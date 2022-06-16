/*
* Projeto Transmissor Wireless
*     Tractian Challenge
*                
* by Victor Hugo Martins Torres 
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/



/* ---------------------------- LIBRARY IMPORTATION ------------------------- */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<string.h>

/* ----------------------- GLOBAL VARIABLES DECLARATION ------------------------ */
#define STR_MAX_LEN 32 // max message length for nrf24l01 transmitter
const char EndMessageSymbol[] = "#$#"; // End Message Symbol
RF24 radio(7, 8); // CE pin AND  CSN pin
const byte address[6] = "00001"; // channel address

/* 500kB message to be sent */
/*Random file character generator : https://onlinefiletools.com/generate-random-text-file  */
const String message = "assaasaasasasasasasaasasaassaasassasaasassaassaasassaassaassasassa";

/* ------------------------------- METHODS DECLARATION ------------------------ */
void sendMessage(String msg);

/* ------------------------------------ MAIN CODE --------------------------- */
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  sendMessage(message);
  delay(1000);
}

/*Due to data size limit of 32 bytes per message from the hardware specification. 
  This function will split the main message into small packages of 32 bytes and send them to Receiver*/
void sendMessage(String msg){
  for (unsigned i = 0; i < msg.length(); i += STR_MAX_LEN) {
    String subString = msg.substring(i, i + STR_MAX_LEN);
    char text[STR_MAX_LEN];
    subString.toCharArray(text, STR_MAX_LEN);
    
    radio.write(&text, sizeof(text));
    delay(10);
  }
  radio.write(&EndMessageSymbol, sizeof(EndMessageSymbol)); //to finish the communication, we send the end message symbol
}

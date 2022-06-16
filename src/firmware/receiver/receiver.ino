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
const byte address[6] = "00001"; // channel address
const char EndMessageSymbol[3] = "#$#"; // End Message Symbol
RF24 radio(7, 8); // CE pin AND  CSN pin

/* ------------------------------- METHODS DECLARATION ------------------------ */
String readTxMessage();
bool finishedTransmission(String msg);

/* ------------------------------------ MAIN CODE --------------------------- */
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  String message;
  if (radio.available()) {
    Serial.println("STARTING READING MESSAGE...");
    message = readTxMessage();
  }
}

/* We need to get each piece of message sent (with size of 32 bytes) 
   and concatenate it to understand the full message */
String readTxMessage(){
  String message = "";
  char text[STR_MAX_LEN] = "";
  do{
    strcpy(text, "");
    radio.read(&text, sizeof(text));
    if(!finishedTransmission(EndMessageSymbol, text)){
      message.concat(String(text));
    }
  }while(finishedTransmission(EndMessageSymbol, text));
  
  Serial.println("MESSAGE RECEIVED...");
  Serial.println(message);
  Serial.println("#################### FINISHED TRANSMISSION ####################");
  return message;
}

/* Detect if the transmission was finished through the end message symbol*/
bool finishedTransmission(char *ems, char *msg){
  bool isFinished = false;
  int cmp;
  
  char str1[STR_MAX_LEN];
  char str2[STR_MAX_LEN];

  strcpy(str1, ems);
  strcpy(str2, msg);

  cmp = strcmp(str1, str2);
  
  if(cmp == 0){
    isFinished = true;
  }
  return isFinished;
}

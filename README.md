# Projeto Transmissor Wireless

### Sobre o projeto

O projeto em questão foi desenvolvido  com intuito de resolver um desafio proposto em um processo seletivo. A proposta é comunicar dois dispositivos utilizando tecnologia sem fio ou "wireless".
 
Considerando todos os aspectos  do desenvolvimento de uma solução tecnológica, o projeto foi dividido em etapas como definição de requisitos, desenvolvimento de hardware, software e produto final. Todas essas fases, embora pareçam seguir uma ordem em cadeia, foram desenvolvidas de forma iterativa e isso resultou em uma solução que atende todos requisitos solicitados. 

### Sumário
- [Definição de Requisitos](https://github.com/Victor-MT/projeto-transmissor-wireless#defini%C3%A7%C3%A3o-de-requisitos)
- [Arquitetura](https://github.com/Victor-MT/projeto-transmissor-wireless#arquitetura)
- [Hardware](https://github.com/Victor-MT/projeto-transmissor-wireless#hardware)
- [Firmware](https://github.com/Victor-MT/projeto-transmissor-wireless#firmware)
- [Produto Final](https://github.com/Victor-MT/projeto-transmissor-wireless#produto-final)
- [Conclusão](https://github.com/Victor-MT/projeto-transmissor-wireless#conclus%C3%A3o)
- [Referências](https://github.com/Victor-MT/projeto-transmissor-wireless#refer%C3%AAncias)


## |Definição de Requisitos
Os requisitos definidos pelo cliente, nesse caso, o documento de especificação do projeto, foram: 
- Comunicar dois dispositivos, usando uma arquitetura integralmente sem fio em um range de 100 metros em espaço aberto. 
- Enviar um arquivo de 500kB 
- Componentes utilizados de fácil acesso ( disponíveis no mercado)
- Interface simples de operar 
- Pelo menos um dispositivo utilizando bateria
- Pensar na case do dispositivos (produto final) 

#### Ferramentas utilizadas :
Arduino IDE, KiCad software

## |Arquitetura
Para essa primeira versão que tem como fim uma prova de conceito (POC), a arquitetura escolhida para esse projeto foi, basicamente, um microcontrolador conectado a um transmissor e um microcontrolador conectado a um receptor com a possibilidade de enviar as informações recebidas para outro dispositivo via serial. Essa arquitetura corresponde ao tipo de comunicação simplex com um transmissor e um receptor.

#### Arquitetura proposta

![Arquitetura](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/arquitetura.png)


## |Hardware
Baseado na premissa da disponibilidade de mercado, foi selecionado como microcontrolador o arduino nano (chip ATMega328P) e o transmissor nRF24L01 por sua alta disponibilidade e preços relativamente baixos. Segundo o próprio [datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1243924/ETC1/NRF24L01.html) do nRF24L01, ele possui um alcance de 100m em espaços abertos, sendo assim, atende ao principal requisito do projeto. Além disso, o transceptor em questão posssui mais 1 canal para se comunicar o que permite comunicações full-duplex. 

#### Arduino | NRF24 spec
![spec](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/spec.png)

Com esses dois dispositivos escolhidos foi possível desenvolver o esquemático do sistema e a consequentemente a placa pcb.

#### Esquemático
![Eschm](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/circuit_esquematico.png)

Para o desenvolvimento da placa PCB foi utilizado o software KiCad.

#### PCB
![pcb](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/PCB_circuit.png)

[Formato da placa já desenvolvido para encaixar na case do protótipo.](https://github.com/Victor-MT/projeto-transmissor-wireless#produto-final)

#### PCB 3D
![pcb](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/pcb_3D.png)

Coloquei os nomes dos dispositivos na placa 3D pois o KiCad não possui o modelo 3D dos componentes em questão, apenas as medidadas de referência. 

No caso acima para facilitar a configuração da placa e também deixar o protótipo aberto a futuras intervenções, foi utilizado a placa arduino nano e o módulo nRF24L01, porém durante o processo de confecção do produto real ambos podem ser substituídos por apenas o chip de cada módulo com apenas um circuito de proteção e assim diminuir ainda mais o custo do projeto.

A bateria do sistema foi escolhida baseada no consumo do mesmo que foi calculado em 31.3 mA. A bateria sugerida seria uma de 9V 250mAh ([bateria](https://www.amazon.com.br/Bateria-Recarreg%C3%A1vel-Blister-Elgin-Baterias/dp/B0754DF568/ref=asc_df_B0754DF568/?tag=googleshopp00-20&linkCode=df0&hvadid=379726667452&hvpos=&hvnetw=g&hvrand=8347384447641540275&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9100812&hvtargid=pla-809701102940&psc=1) e [conector](https://produto.mercadolivre.com.br/MLB-2114848124-clip-para-bateria-9v-capa-de-proteco-arduino-esp-nodemcu-_JM#position=2&search_layout=grid&type=item&tracking_id=4435f918-5bed-4264-9335-1ed655bfa6df)) e com isso a autonomia do projeto seria de aproximadamente 8 horas. 

## |Firmware
Para o desenvolvimento do firmware, por se tratar de dois dispositivos muito utilizados para prototipagem possuem diversas bibliotecas disponíveis, escolhemos utilizar a RF24, desenvolvida por [TMRh20](https://github.com/tmrh20/RF24/) que pode ser encontrada diretamente pelo gerenciador de bibliotecas na IDE do Arduino. 

No desenvolvimento  do firmware o principal desafio foi conseguir transportar um arquivo tão grande quanto 500kB já que a limitação do nRF24L01 é de 32 bytes por mensagem. Para solucionar o problema, o algoritmo desenvolvido divide a mensagem original em pequenos pedaços de 32 bytes de tamanho e depois o firmware do receptor remonta a mensagem. 

[Código do transmissor](https://github.com/Victor-MT/projeto-transmissor-wireless/tree/master/src/firmware/transmistter)
[Código do Receptor](https://github.com/Victor-MT/projeto-transmissor-wireless/tree/master/src/firmware/receiver)
## |Produto Final
Após a confecção da placa, foi desenvolvida uma case para proteger o sistema e tornar o produto mais apresentável para o cliente final poder manusear e acoplar onde for necessário. O formato octogonal foi escolhido por sua facilidade de encaixe em diversas posições e baixa complexidade de confecção, além de ser um formato agradável visualmente. 

#### Case
![case](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/case_img.png)

## |Conclusão
Após todas essas etapas, podemos concluir que todos requisitos foram cumpridos resultando em um produto de fácil confecção, acessível no mercado e de simples operação. Segue abaixo o custo relativo ao projeto, sem considerar o custo para produção da PCB nem fabricação da case que deperiam do fornecedor já que seriam personalizadas.

#### Custo do projeto
![case](https://github.com/Victor-MT/projeto-transmissor-wireless/blob/master/img/Custo%20do%20Produto.png)
[Planilha de custos](https://github.com/Victor-MT/projeto-transmissor-wireless/tree/master/src/product)

### Melhorias

Este projeto teve o instituto de prototipar um sistema de comunicação wireless em uma semana, sendo assim, é evidente que ficam pendentes diversas melhorias que poderiam ser implementadas. Deixarei aqui algumas sugestões.

#### Upgrades Futuros: 
- Indicador LED alertando por código de cor se a mensagem foi enviada e/ou recebida;
- Mudança de protocolo para full-duplex;
- Melhoria do firmware para feedback de resposta sobre a integridade da mensagem enviada pelo transmissor;
- Interface desktop para ler e exibir informações do receptor;
## |Referências

 - [Understanding Wireless Range Calculations](https://www.electronicdesign.com/technologies/communications/article/21796484/understanding-wireless-range-calculations)
 - [About nRF24L01](https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/)
 - [Library Documentation](https://nrf24.github.io/RF24/)
 - [nRF24L01 datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1243924/ETC1/NRF24L01.html)
 - [Modos de transmissão](https://www.canalti.com.br/redes-de-computadores/modos-de-transmissao-de-dados-simplex-half-duplex-full-duplex/)

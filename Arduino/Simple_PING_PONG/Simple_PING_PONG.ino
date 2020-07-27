#include <SPI.h>  
#include "SX1272.h"

#define ETSI_EUROPE_REGULATION
#define PABOOST
#define MY_FREQUENCY 868.1
#define BAND868
#define MAX_DBM 14

#define LORAMODE  1
#define node_addr 8

#define PRINTLN                   Serial.println("")
#define PRINT_CSTSTR(fmt,param)   Serial.print(F(param))
#define PRINT_STR(fmt,param)      Serial.print(param)
#define PRINT_VALUE(fmt,param)    Serial.print(param)
#define FLUSHOUTPUT               Serial.flush();

#define DEFAULT_DEST_ADDR 1

uint8_t message[100];

int loraMode=LORAMODE;

void setup()
{
  int e;
  Serial.begin(38400);  
  pinMode(13, OUTPUT);
  // Print a start message
  PRINT_CSTSTR("%s","Simple LoRa ping-pong with the gateway\n");  

  // Power ON the module
  sx1272.ON();
  
  // Set transmission mode and print the result
  e = sx1272.setMode(loraMode);
  PRINT_CSTSTR("%s","Setting Mode: state ");
  PRINT_VALUE("%d", e);
  PRINTLN;

  // enable carrier sense
  sx1272._enableCarrierSense=true;
    
  // Select frequency channel
  e = sx1272.setChannel(MY_FREQUENCY*1000000.0*RH_LORA_FCONVERT);
  PRINT_CSTSTR("%s","Setting Channel: state ");
  PRINT_VALUE("%d", e);
  PRINTLN;
  // Select amplifier line; PABOOST or RFO
  sx1272._needPABOOST=true;
  e = sx1272.setPowerDBM((uint8_t)MAX_DBM); 
  PRINT_CSTSTR("%s","Setting Power: state ");
  PRINT_VALUE("%d", e);
  PRINTLN;
  
  // Set the node address and print the result
  e = sx1272.setNodeAddress(node_addr);
  PRINT_CSTSTR("%s","Setting node addr: state ");
  PRINT_VALUE("%d", e);
  PRINTLN;
  
  // Print a success message
  PRINT_CSTSTR("%s","SX1272 successfully configured\n");

  delay(500);
}


void loop(void)
{
  uint8_t r_size;
  int e;

  sx1272.CarrierSense();

  sx1272.setPacketType(PKT_TYPE_DATA);

  while (1) {
      r_size=sprintf((char*)message, "T");
      PRINT_CSTSTR("%s","Sending Ping");  
      PRINTLN;
            
      e = sx1272.sendPacketTimeoutACK(DEFAULT_DEST_ADDR, message, r_size);

      // this is the no-ack version
      //e = sx1272.sendPacketTimeout(DEFAULT_DEST_ADDR, message, r_size);
            
      PRINT_CSTSTR("%s","Packet sent, state ");
      PRINT_VALUE("%d", e);
      PRINTLN;
      
      if (e==3){
        digitalWrite(13, LOW);
          PRINT_CSTSTR("%s","No Pong from gw!");
          }
      if (e==0) {
        digitalWrite(13, HIGH);
          PRINT_CSTSTR("%s","Pong received from gateway!");
          PRINTLN;        
          sprintf((char*)message,"SNR at gw=%d   ", sx1272._rcv_snr_in_ack);
          PRINT_STR("%s", (char*)message); 
          PRINTLN;
          sx1272.getSNR();
          sx1272.getRSSIpacket();
          sprintf((char*)message,"From gw=%d,%d", sx1272._SNR, sx1272._RSSIpacket);
          PRINT_STR("%s", (char*)message);
          PRINTLN;               
      }      

      PRINTLN;
      
      delay(10000);    
  }          
}

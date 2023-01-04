// AR RoboTics
//https://youtube.com/@ARRoboTics
#include <EEPROM.h>
#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3); // RX, TX  bluetooth communication

#define Relay1 4 //light pin
#define Relay2 5 // lamp pin
#define Relay3 6 // socket pin
#define Relay4 7 // fan pin

char bt_data; // variable to receive data from the serial port
int load1, load2, load3, load4, power;

void setup(){
Serial.begin(9600);
BT_Serial.begin(9600); 

pinMode(Relay1, OUTPUT); digitalWrite(Relay1, 1); 
pinMode(Relay2, OUTPUT); digitalWrite(Relay2, 1); 
pinMode(Relay3, OUTPUT); digitalWrite(Relay3, 1); 
pinMode(Relay4, OUTPUT); digitalWrite(Relay4, 1); 
  
load1 = EEPROM.read(1);
load2 = EEPROM.read(2);
load3 = EEPROM.read(3);
load4 = EEPROM.read(4);

power = EEPROM.read(5);
delay(500); 
}

void loop() {
if(BT_Serial.available()>0){bt_data = BT_Serial.read();}

if(bt_data == 'A'){load1=0;EEPROM.write(1, load1);}
if(bt_data == 'a'){load1=1;EEPROM.write(1, load1);}

if(bt_data == 'B'){load2=0;EEPROM.write(2, load2);}
if(bt_data == 'b'){load2=1;EEPROM.write(2, load2);}

if(bt_data == 'C'){load3=0;EEPROM.write(3, load3);}
if(bt_data == 'c'){load3=1;EEPROM.write(3, load3);}

if(bt_data == 'D'){load4=0;EEPROM.write(4, load4);}
if(bt_data == 'd'){load4=1;EEPROM.write(4, load4);}

if(bt_data == 'E'){power=0;EEPROM.write(5, power);}
if(bt_data == 'e'){power=1;EEPROM.write(5, power);}

bt_data = '0';
  
if(power==1){  
digitalWrite(Relay1, 1); 
digitalWrite(Relay2, 1); 
digitalWrite(Relay3, 1); 
digitalWrite(Relay4, 1); 
}else{
digitalWrite(Relay1, load1); 
digitalWrite(Relay2, load2); 
digitalWrite(Relay3, load3); 
digitalWrite(Relay4, load4);
}

 BT_Serial.print(power); //send data to MIT App
 BT_Serial.print(";");
 BT_Serial.print(load1); //send data to MIT App 
 BT_Serial.print(";");
 BT_Serial.print(load2); //send data to MIT App 
 BT_Serial.print(";");
 BT_Serial.print(load3); //send data to MIT App 
 BT_Serial.print(";");
 BT_Serial.print(load4); //send data to MIT App 
 BT_Serial.println(";");
  
delay(500);  
}

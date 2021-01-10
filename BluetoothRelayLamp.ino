/*********
  James Steven Dulangon
  Bluetooth-controlled Lamp using HC-05, 5V Relay and Arduino Nano
*********/
#define relayOut 2 // pin D2 connencted to In1 of the relay module

void setup() {
 Serial.begin(9600);
 pinMode(relayOut, OUTPUT);
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1': digitalWrite(relayOut,LOW); break; // the relay coil energizes when In1 of the relay board is LOW
        case '0': digitalWrite(relayOut,HIGH); break; 
        default : break;
      }
   }
   delay(50);
}

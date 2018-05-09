#include <SoftwareSerial.h> 
 
SoftwareSerial ModBluetooth(2, 3); // RX | TX 
 
void setup()  
{ 
    pinMode(13, OUTPUT); 
    digitalWrite(13, LOW);  
     
    ModBluetooth.begin(9600); 
    Serial.begin(9600);  
    ModBluetooth.println("MODULO CONECTADO");  
    ModBluetooth.print("#");  
} 
 
void loop()  
{  
    if (ModBluetooth.available())  
    { 
        char VarChar; 
         
        VarChar = ModBluetooth.read(); 
         
        if(VarChar == '1') 
        { 
        digitalWrite(13, HIGH); 
        delay(100); 
        ModBluetooth.print("LED ENCENDIDO"); 
        Serial.print("LED ENCENDIDO"); 
        ModBluetooth.print("#"); 
        } 
        if(VarChar == '0') 
        { 
        digitalWrite(13, LOW); 
        delay(100); 
        ModBluetooth.print("LED APAGADO#"); 
        Serial.print("LED APAGADO#"); 
        } 
    } 
} 
 

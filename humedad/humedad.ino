const int pinSenHum = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSenHum, INPUT);
}

void loop() {
  int humedad = digitalRead(pinSenHum);
  // Mensaje a puerto serie
  if ( humedad == HIGH) {
    Serial.println("Encendido");
  }
  //espera medio segundo para continuar con el proceso.
  delay(500); 
}

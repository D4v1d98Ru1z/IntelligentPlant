const int pinSenHum = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSenHum, INPUT);
}

void loop() {
  int humedad = digitalRead(sensorPin);
  // Mensaje a puerto serie
  if ( humedad == HIGH) {
    Serial.println(humedad);
  }
  //espera un segundo para continuar con el proceso.
  delay(1000); 
}

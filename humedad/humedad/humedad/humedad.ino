const int pinSenHum = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSenHum, INPUT);
}

void loop() {
  int humedad = digitalRead(pinSenHum);
  Serial.println(humedad);
  // Mensaje a puerto serie
  /*if ( humedad == HIGH) {
    Serial.println("Se encuentra bastante humedo.");
  }
  else {
    Serial.println("la humedad esta bajando");
  }*/
  //espera medio segundo para continuar con el proceso.
  delay(500); 
}

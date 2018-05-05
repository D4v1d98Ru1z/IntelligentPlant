const int pinTrig = 7;
const int pinEcho = 6;
//velocidad del sonido en cm/s
const float VelSonido = 34000.0;
// # de muestras
const int NumLecturas = 100;
// Distancia cuando este  lleno a los 100ml y vacío de acuerdo a las medidas del recipiente 
const float dLleno = 2.15; 
const float dVacio = 11.41;
// Array para almacenar lecturas 
float lecturas[NumLecturas]; 
int lecturaActual = 0;
float total = 0;
float mediaMedidas = 0;
 


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

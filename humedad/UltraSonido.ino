const int pinTrig = 7;
const int pinEcho = 6;

//velocidad del sonido en cm/s
const float VelSonido = 34000.0;
// # de muestras
const int NumLecturas = 100;
// Distancia cuando este  lleno a los 100ml y vacío de acuerdo a las medidas del recipiente 
const float distancia100 = 2.15; 
const float dVacio = 11.41;
// Array para almacenar lecturas 
float lecturas[NumLecturas]; 
int lecturaActual = 0;
float total = 0;
float mediaMedidas = 0;
bool primeraMedia = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  //inicializa el array mediante el for se hace el recorrido dentro de él.
  for(int i = 0; i < NumLecturas; i++) {
    lecturas[i] = 0;
  }

}

void loop() {
  //Elimina la ultima medida.
  total = total - lecturas[lecturaActual];

  iniciarTrigger();

  // La función pulseIn obtiene el tiempo que tarda en cambiar entre estados, en este caso a HIGH
  unsigned long tiempo = pulseIn(PinEcho, HIGH);
  //la distancia se obtiene en cm, el tiempo esta en milisegundos, asi que se multiplica para pasarse a segundos.
  float distancia = tiempo * 0.000001 * VelSonido / 2.0;
  //se almacena la distancia en el array, se añade la lectura total y se avanza a la siguiente posicion del array.
  lecturas[lecturaActual] = distancia;
  total = total + lecturas[lecturaActual];
  lecturaActual += 1;

  // se comprueba si llego al final del array
  if(lecturaActual >= NumLecturas) {
    primeraMedia = true;
    lecturaActual = 0;
  }
  
  mediaMedidas = total /NumLecturas;

  //solo muestra si se ha calculado por lo menos una media
  if(primeraMedia) {
    float dLleno = dVacio - mediaMedidas;
    float cantidadLq = dLleno * 100 / distancia100;

    Serial.print(mediaMedidas);
    Serial.printn(" cm");
    Serial.print(cantidadLq);
    Serial.println(" ml");
  }
  delay(500);
} 

//metodo Trigger para comenzar a medir 
void iniciarTrigger(){
  //se pone el pin en estado bajo y se espera 2ms
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);

  digitalWrite(pinTrig, LOW);
}


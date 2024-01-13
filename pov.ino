
int sensorPin = 2;
unsigned int seconds,i,n,d = 0;
unsigned int c = 0;
float dl;
unsigned long timecurr,timeold,previousTime = 0;
uint16_t timer_count_A=0; 
byte letra,t,temp,data = 0;
int altura=96;
int val;
// Lista de opciones
int opciones[] = {0, 4, 8, 12};

// Calcular la longitud de la lista de opciones
int cantidadOpciones = sizeof(opciones) / sizeof(opciones[0]);

// Generar un índice aleatorio dentro del rango de opciones
int indiceAleatorio = random(cantidadOpciones);

// Elegir una opción al azar de la lista
int limite = opciones[indiceAleatorio];


void setup() 
{




  
  DDRD = 0xFA;
  DDRB = 0xFF;
  DDRC = 0x3F;
  PORTD = 0x05;
  PORTB = 0x00;      
  PORTC = 0x00;  

   UBRR0 = 832;   // baud rate 1200bps
   UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); 
   UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);  

  attachInterrupt(0, us_time, RISING);    
}

void loop() 
{
   altura=altura-altura/2;
  //Serial.begin(4800);
    val = digitalRead(sensorPin);  
    while (val == LOW)
  {
    update_time();   
    val = digitalRead(sensorPin);
  }

  
  
  while(n < 192)
  {
   
  int puntos=1;

  c=80;
Display(puntos, altura, limite);
    
    
    
        delayMicroseconds(dl);
        Clear();
        delayMicroseconds(dl * 3);
        n++;
       PORTC &= 1111110;
        
      
 

  }



    val = digitalRead(sensorPin);  
    
    while (val == HIGH)
    {
    update_time();  
    val = digitalRead(sensorPin); 
    }

   if(altura==3){
    altura=96;
    // Calcular la longitud de la lista de opciones
 cantidadOpciones = sizeof(opciones) / sizeof(opciones[0]);

// Generar un índice aleatorio dentro del rango de opciones
 indiceAleatorio = random(cantidadOpciones);

// Elegir una opción al azar de la lista
 limite = opciones[indiceAleatorio];
    }     
}

  void Display(int puntos, int altura, int limite)
{
  
  for(int i=0; i<puntos+1;i++){


    
    if(n==c+i+limite){
    
  temp =  altura;
  
      
   if(n==c+i){
    temp++;
    }
     if(n==c+i+4){
    temp++;
    }
     if(n==c+i+8){
    temp++;
    }
     if(n==c+i+12){
    temp++;
    }
  
         PORTC = temp;
    }
    

  }
 
} 

  

void Clear()
  {
    for (int i = 3; i <= 20; i++)
    {
    digitalWrite(i,LOW);
    }    
  }

void update_time()  
{
 

 
}

   void us_time()
{    
  n = 0;
  letra=0;
  timecurr = micros()-timeold;
  timeold = micros(); 
  dl = timecurr/1000 ; 
 
} 

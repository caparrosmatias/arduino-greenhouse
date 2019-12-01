//******DECLARACION DE ENTRADAS Y SALIDAS******

int ledrojo=13; //led azul, temperatura baja 
int ledazul=12; //led rojo para, temperatura alta 
int ledverde=11;//led verde, temperatura ideal 
int riego=10;//relevador para control de riego
int calefactor=9; //relevador para control de calefactor 
int ventilador=8; //relevador para control de ventiladores 
float TC; //temperatura promedio 
float TC1;

int tempPin1=0; //entrada del sensor de temperatura


//******DECLARACION DE VARIABLES DE PROGRAMA*******

unsigned long despertador ((pow(2,20))-1); //2^20 para reiniciar el programa
unsigned long msActual = (millis()&despertador); //Suma binaria para msActual
unsigned long msPrevioR = msActual;
unsigned long msPrevioT = msActual;
unsigned long restanteR = msActual - restanteR;
unsigned long restanteT = msActual - restanteT;


void setup(){
  Serial.begin(9600); //Se inicia la conexion serial con PC
    //Serial.print(despertador);
    
    //*****DECLARACION DE LAS SALIDAS
    pinMode(ledazul,OUTPUT); 
    pinMode(ledrojo,OUTPUT);
    pinMode(ledverde,OUTPUT); 
    pinMode(riego,OUTPUT);
    pinMode(calefactor,OUTPUT);
    pinMode(ventilador,OUTPUT);

}

void loop(){
  
  //*******PROCESAMIENTO DE SEÑALES
  //CONVERSIÓN Y LECTURA DE TEMPERATURA
  TC1=analogRead(tempPin1); 
  TC= (5* TC1 * 100)/1024;
  
  //******CONDICIONALES DEL RELOJ
  
  unsigned long msActual = (millis()&despertador); //Suma binaria para msActual
  
  if (msActual<msPrevioR) {
    msPrevioR = (msActual - restanteR);
    msPrevioT = (msActual - restanteT);
    
  }
  
  if ((msActual - msPrevioT) > 240000){
    msPrevioT = msActual;
    Serial.println(TC);
    if (TC < 25) {
      //apagar ventilador, encender calefactor
      digitalWrite(calefactor, HIGH);
      digitalWrite(ventilador, LOW);
      digitalWrite(ledrojo, HIGH);
      digitalWrite(ledazul, LOW);
      digitalWrite(ledverde, LOW);
    }
    else {
      if (TC > 28){
        //apagar calefactor, encender ventildor
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, HIGH);
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledazul, HIGH);
      digitalWrite(ledverde, LOW);
      }
      else {
      digitalWrite(calefactor, LOW);
      digitalWrite(ventilador, LOW);
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledazul, LOW);
      digitalWrite(ledverde, HIGH);
      }
    }
    }
    
    if ((msActual-msPrevioR)> 100000) {
      msPrevioR = msActual;
      Serial.println("*****RIEGO*****");
      digitalWrite(riego, HIGH);
      delay(1000);
      digitalWrite(riego, LOW);
      //prendo la bomba
    }
    













  
 /* 
  
  Serial.println(despertador);
  delay(1000);
  Serial.println(msActual);
  delay(1000); */
  

  }
  
 
  

    
  
  
 
  
  
  
  
  
  



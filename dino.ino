#include <Servo.h> //Incluimos la librería del servo
int ldr = A0;     //Declaráramos una variable para el pin A0
int valorldr;    //Declaráramos una variable para el calor del LDR 
int porcentaje; //Declaráramos una variable para el porsentaje
Servo serv;

void setup() {
  Serial.begin (9600); //Iniciamos monitor Serial
  serv.attach(9); //Seleccionamos el pin a utilizar Servomotor
  serv.write(90); //Se muve 90° el Servomotor
  delay (1000); // Retraso de 1 Sg
}
void loop() {
  
  valorldr = analogRead(ldr); // La variable "valorldr"  es igual ala escritura analogica del pin A0
  porcentaje = map(valorldr, 0, 1023, 0, 100); //Mapeamos para que nuestros valores sean de 0 a 100

  Serial.print("Analogico: "); //Imprimimos en la terminal 
  Serial.println(valorldr);    //El valor del ldr ente 0 y 1023
//  Serial.print("porcentaje "); //Imprimimos en la terminal 
//  Serial.println(porcentaje);  //El valor del ldr ente 0 y 100
  
  if (710> valorldr) { //Si el valor del LDR es mayor a 710.
    serv.write(60); //Se muve 60° el Servomotor.
  }
  else { // Si no
    serv.write(90); //Se muve 90° el Servomotor.
  }
  delay(5);
}

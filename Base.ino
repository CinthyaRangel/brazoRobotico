// Incluímos la librería para poder controlar el servo
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo base;
int movimientoBase = 100;
int input;
 
void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  base.attach(9);

  // Inicializamos las base cerradas
  base.write(90);
}
 
void loop() {
  while (Serial.available() > 0) { // SI HAY UN MENSAJE DISPONIBLE
    input = Serial.read();

    if(input == '1') { // MOVER BASE A LA IZQUIERDA
      if(movimientoBase >= 0)
        movimientoBase -= 10;
    } else if(input == '0') { // MOVER BASE A LA DERECHA
      if(movimientoBase <= 180)
        movimientoBase += 10;
    }

    base.write(movimientoBase);
    Serial.println(Serial.read());
    //delay(700);
  }
}


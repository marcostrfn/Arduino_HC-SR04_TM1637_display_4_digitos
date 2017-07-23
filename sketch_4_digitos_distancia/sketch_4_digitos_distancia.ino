/*
  Medir distancia (en mm) com modulo HC-SR04
  y mostrar resultado en display de 4 digitos (tm1637).

  Arduino nano.

  Display 4 digitos
  ------------------
	GND - GND
	VCC - VCC
	DIO - PIN 5
	CLK - PINT 3

  HC-SR04
  ------------------
	GND - GND
	VCC - VCC
	TRIGGER - PIN 9
	ECHO - PIN 8

*/


#include "SevenSegmentTM1637.h"

/* TM1637 */
const byte PIN_CLK = 3;   // CLK pin (cualquier pin digital)
const byte PIN_DIO = 5;   // DIO pin (cualquier pin digital)
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);

/* sensor de distancia */

int ECHO = 8;
int TRIGGER = 9;

#define TRIGGER 9
#define ECHO 8

#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 10
#define MEASURE_DELAY 250

void setup() {
  Serial.begin(9600);         // Iniciamos conexion serie a 9600 baudios

  // display numerico
  display.begin();            // iniciamos display
  display.setBacklight(100);  // brillo a 100%
  display.print("INIT");      // mostramos INIT en el display
  delay(1000);                // esperamos...


  // sensor de distancia
  pinMode(TRIGGER, OUTPUT); // activación del pin 9 como salida: para el pulso
  pinMode(ECHO, INPUT); 	// activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/

  // Reseteamos el trigger y esperamos...
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(500);

};


void loop() {

  delay(MEASURE_DELAY);
  long distance = measure();
  Serial.println(distance);
  // si la distancia es menor a 500 mm
  // la mostramos en el display
  // si no, mostramos ----
  if (distance < 500) {
    char buf[4];
    sprintf(buf, "%04lu", distance);
    display.print(buf);
  } else {
    display.print("----");
  }

};

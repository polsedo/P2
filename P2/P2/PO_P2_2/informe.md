# PRACTICA 2 : INTERRUPCIONES
## Parte B: Interrupción por timer

### CÓDIGO:

```cpp
#include <Arduino.h>
volatile int interruptCounter;
int totalInterruptCounter;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
void IRAM_ATTR onTimer() {
portENTER_CRITICAL_ISR(&timerMux);
interruptCounter++;
portEXIT_CRITICAL_ISR(&timerMux);
}
void setup() {
Serial.begin(115200);
timer = timerBegin(0, 80, true);
timerAttachInterrupt(timer, &onTimer, true);
timerAlarmWrite(timer, 1000000, true);
timerAlarmEnable(timer);
}
void loop() {
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    totalInterruptCounter++;
    Serial.print("An interrupt as occurred. Total number: ");
    Serial.println(totalInterruptCounter);
  }
}

```

### FUNCIONAMIENTO:
En este caso en vez de usa el pin cero provocamos una interrupcion cada cierto tiempo, en concreto cada segundo i cada vexz que se interrumpa el programa escrivimos por el serial ' an interruption ha ocurred, total number of interruptions:' i el numero de interrupciones hasta el momento 



```cpp
void loop() {
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    totalInterruptCounter++;
    Serial.print("An interrupt as occurred. Total number: ");
    Serial.println(totalInterruptCounter);
  }
}
```
Al ejecutar por pantalla, muestra que hay interrupciones i las va sumando.
![alt text](captura.JPG)
#include <IRLibSendBase.h>
#include <IRLib_P02_Sony.h>
#include <IRLibCombo.h>


#define LED1_PIN 10
#define LED2_PIN 11
#define IR_SEND_PWM_PIN 9

#define BTN1_PIN 4
#define BTN2_PIN 5


byte ir_signals[2] = {0x70, 0x80};

IRsend IRSender;

void setup() {

  pinMode(LED1_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED2_PIN, LOW);

  pinMode(BTN1_PIN, INPUT);
  pinMode(BTN2_PIN, INPUT);
}

void loop() {

  if (digitalRead(BTN1_PIN) == HIGH) {
    digitalWrite(LED1_PIN, 1);
    IRSender.send(SONY, ir_signals[0], 8);
  } else {
    digitalWrite(LED1_PIN, 0);
  }

  if (digitalRead(BTN2_PIN) == HIGH) {
    digitalWrite(LED2_PIN, 1);
    IRSender.send(SONY, ir_signals[1], 8);
  } else {
    digitalWrite(LED2_PIN, 0);
  }

  delay(50);

}


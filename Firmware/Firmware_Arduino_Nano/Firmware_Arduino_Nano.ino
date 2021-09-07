//Arduino NANO CODE
//Joystick library is https://github.com/MHeironimus/ArduinoJoystickLibrary
//Arduino Nano Clone Driver: https://sparks.gogo.co.nz/ch340.html

#define MAX_POT_VALUE 1023 //max potentiometer value (only needed if you flip one of the axis)

#define POT_PIN_Y A6 
#define FLIP_Y false //if you wired the potentiometer wrong you can flip it (true or false)

#define POT_PIN_X A4
#define FLIP_X false //if you wired the potentiometer wrong you can flip it (true or false)

//Y Value
#define TOP_GEAR_ROW 415 //top row of gears max value (Y value < TOP_GEAR_ROW)
#define BOTTOM_GEAR_ROW 475 //bottom row of gears min value (Y value > BOTTOM_GEAR_ROW)


//X Value
#define FIRST_ROW_MAX 385 // 1 and 2 gears row max value (X value < FIRST_ROW_MAX)

#define SECOND_ROW_MIN 405 // 3 and 4 gears row min value (X value > SECOND_ROW_MIN)
#define SECOND_ROW_MAX 450 // 3 and 4 gears row max value (X value < SECOND_ROW_MAX)

#define THIRD_ROW_MIN 465 // 5 and 6 gears row min value (X value > THIRD_ROW_MIN)
#define THIRD_ROW_MAX 485 // 5 and 6 gears row max value (X value < THIRD_ROW_MAX)

#define FOURTH_ROW_MIN 500 // 7 and R/8 gears row max value (X value > FOURTH_ROW_MIN)



#include <Joystick.h>
Joystick_ Joystick;

int currentButton = 8;

int nutralCount = 0;

int potValueY;
int potValueX;


void setup() {
  Serial.begin(115200);
  Joystick.begin();
  Joystick.press(8);
}


void loop() {
  potValueY = analogRead(POT_PIN_Y);
  if (FLIP_Y) {
    potValueY = MAX_POT_VALUE - potValueY;
  }
  potValueX = analogRead(POT_PIN_X);
  if (FLIP_X) {
    potValueX = MAX_POT_VALUE - potValueX;
  }
  Serial.print(potValueY);
  Serial.print(" ");
  Serial.print(potValueX);
  Serial.print(" ");
  Serial.println(currentButton);

  if (Joystick.isConnected()) {
    if (potValueY < TOP_GEAR_ROW && potValueX < FIRST_ROW_MAX) {
      if (currentButton != 0) {
        Joystick.release(currentButton);
        Joystick.press(0);
        currentButton = 0;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX < FIRST_ROW_MAX) {
      if (currentButton != 1) {
        Joystick.release(currentButton);
        Joystick.press(1);
        currentButton = 1;
        nutralCount = 0;
      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > SECOND_ROW_MIN && potValueX < SECOND_ROW_MAX) {
      if (currentButton != 2) {
        Joystick.release(currentButton);
        Joystick.press(2);
        currentButton = 2;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > SECOND_ROW_MIN && potValueX < SECOND_ROW_MAX) {
      if (currentButton != 3) {
        Joystick.release(currentButton);
        Joystick.press(3);
        currentButton = 3;
        nutralCount = 0;

      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > THIRD_ROW_MIN && potValueX < THIRD_ROW_MAX) {
      if (currentButton != 4) {
        Joystick.release(currentButton);
        Joystick.press(4);
        currentButton = 4;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > THIRD_ROW_MIN && potValueX < THIRD_ROW_MAX) {
      if (currentButton != 5) {
        Joystick.release(currentButton);
        Joystick.press(5);
        currentButton = 5;
        nutralCount = 0;
      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > FOURTH_ROW_MIN) {
      if (currentButton != 6) {
        Joystick.release(currentButton);
        Joystick.press(6);
        currentButton = 6;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > FOURTH_ROW_MIN) {
      if (currentButton != 7) {
        Joystick.release(currentButton);
        Joystick.press(7);
        currentButton = 7;
        nutralCount = 0;
      }
    }
    else {
      nutralCount = nutralCount + 1;
      if (pressed == true && currentButton != 8 && nutralCount > 5) {
        Joystick.release(currentButton);
        Joystick.press(8);
        currentButton = 8;
      }
    }
  }
  delay(100);
}

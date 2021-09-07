//ESP32 CODE
//Gamepad library is https://github.com/lemmingDev/ESP32-BLE-Gamepad
//ESP32 Driver: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

#define MAX_POT_VALUE 4095 //max potentiometer value (only needed if you flip one of the axis)

#define POT_PIN_Y 35 
#define FLIP_Y false //if you wired the potentiometer wrong you can flip it (true or false)

#define POT_PIN_X 33
#define FLIP_X false //if you wired the potentiometer wrong you can flip it (true or false)

//Y Value
#define TOP_GEAR_ROW 1650 //top row of gears max value (Y value < TOP_GEAR_ROW)
#define BOTTOM_GEAR_ROW 1900 //bottom row of gears min value (Y value > BOTTOM_GEAR_ROW)


//X Value
#define FIRST_ROW_MAX 1550 // 1 and 2 gears row max value (X value < FIRST_ROW_MAX)

#define SECOND_ROW_MIN 1625 // 3 and 4 gears row min value (X value > SECOND_ROW_MIN)
#define SECOND_ROW_MAX 1800 // 3 and 4 gears row max value (X value < SECOND_ROW_MAX)

#define THIRD_ROW_MIN 1850 // 5 and 6 gears row min value (X value > THIRD_ROW_MIN)
#define THIRD_ROW_MAX 1950 // 5 and 6 gears row max value (X value < THIRD_ROW_MAX)

#define FOURTH_ROW_MIN 2000 // 7 and R/8 gears row max value (X value > FOURTH_ROW_MIN)



#include <BleGamepad.h>
BleGamepad bleGamepad("Sim Stick Shift", "Ely Oshri", -1);

bool pressed = true;
int currentButton = 9;

int nutralCount = 0;

int potValueY;
int potValueX;


void setup() {
  Serial.begin(115200);
  bleGamepad.begin();
  bleGamepad.press(BUTTON_9);
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

  if (bleGamepad.isConnected()) {
    if (potValueY < TOP_GEAR_ROW && potValueX < FIRST_ROW_MAX) {
      if (pressed == true && currentButton != 1) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_1);
        pressed = true;
        currentButton = 1;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX < FIRST_ROW_MAX) {
      if (pressed == true && currentButton != 2) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_2);
        pressed = true;
        currentButton = 2;
        nutralCount = 0;
      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > SECOND_ROW_MIN && potValueX < SECOND_ROW_MAX) {
      if (pressed == true && currentButton != 3) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_3);
        pressed = true;
        currentButton = 3;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > SECOND_ROW_MIN && potValueX < SECOND_ROW_MAX) {
      if (pressed == true && currentButton != 4) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_4);
        pressed = true;
        currentButton = 4;
        nutralCount = 0;

      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > THIRD_ROW_MIN && potValueX < THIRD_ROW_MAX) {
      if (pressed == true && currentButton != 5) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_5);
        pressed = true;
        currentButton = 5;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > THIRD_ROW_MIN && potValueX < THIRD_ROW_MAX) {
      if (pressed == true && currentButton != 6) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_6);
        pressed = true;
        currentButton = 6;
        nutralCount = 0;
      }
    }
    else if (potValueY < TOP_GEAR_ROW && potValueX > FOURTH_ROW_MIN) {
      if (pressed == true && currentButton != 7) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_7);
        pressed = true;
        currentButton = 7;
        nutralCount = 0;
      }
    }
    else if (potValueY > BOTTOM_GEAR_ROW && potValueX > FOURTH_ROW_MIN) {
      if (pressed == true && currentButton != 8) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_8);
        pressed = true;
        currentButton = 8;
        nutralCount = 0;
      }
    }
    else {
      nutralCount = nutralCount + 1;
      if (pressed == true && currentButton != 9 && nutralCount > 5) {
        bleGamepad.release(currentButton);
        bleGamepad.press(BUTTON_9);
        pressed = true;
        currentButton = 9;
      }
    }
  }
  delay(100);
}

#include <Wire.h>
// 使用可變電阻控制 Servo 的旋轉角度
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

// 引用 Servo Library
#include <Servo.h> 

// 建立一個 Servo 物件 
Servo myservo; 
 
void setup() {
  myservo.attach(9);
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output
}

void loop() {
  delay(1500);

}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
    int c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  myservo.write(c);                  // 設定 Servo 旋轉角度

  delay(15);                           // 等待 Servo 旋轉指定的位置


}


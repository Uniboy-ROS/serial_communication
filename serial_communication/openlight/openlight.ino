int brightness1 ;                   //亮度
int fadeAmount1 = 25;               //亮度增幅值
int brightness2 ;
int fadeAmount2 = 25;

String str;

void setup() {
  pinMode(10, OUTPUT);  //green
  pinMode(11, OUTPUT);  //blue
  Serial.begin(115200);
}

void loop() {
  analogWrite(10, brightness1);
  analogWrite(11, brightness2);
  if (Serial.available()) {
    // 讀取傳入的字串直到"\n"結尾
    str = Serial.readStringUntil('\n');

    if (str == "GLED_UP") {                                     // 若字串值是 "LED_ON" 開燈
      brightness1 = brightness1 + fadeAmount1;                  //增加亮度
      if (brightness1 > 255) {                                  //設保護值，當亮度大於255時，就直接等於255，以避免亮度值爆表造成LED有不正常閃光
        brightness1 = 255;
      }
      //Serial.println(brightness1);                            //序列埠印出亮度值
      //digitalWrite(10, HIGH);     // 開燈
      Serial.println("GreenLED brightness is ");
      Serial.println(brightness1);
    }
    else if (str == "GLED_DOWN") {
      brightness1 = brightness1 - fadeAmount1;
      if (brightness1 < 0) {                                    //設保護值，當亮度小於0時，就直接等於0，以避免亮度值爆表造成LED有不正常閃光
        brightness1 = 0;
      }
      //digitalWrite(10, LOW);
      Serial.println("GreenLED brightness is ");
      Serial.println(brightness1);
    }
    else if (str == "GLED_ON") {                                // 若字串值是 "LED_ON" 開燈
      brightness1 = 255;                                        // 開燈
      Serial.println("GreenLED is ON");                       // 回應訊息給電腦
    }
    else if (str == "GLED_OFF") {
      brightness1 = 0;
      Serial.println("GreenLED is OFF");
    }


    else if (str == "BLED_UP") {
      brightness2 = brightness2 + fadeAmount2;

      if (brightness2 > 255) {
        brightness2 = 255;
      }
      //digitalWrite(11, HIGH);
      Serial.println("BlueLED brightness is ");
      Serial.println(brightness2);
    }
    else if (str == "BLED_DOWN") {
      brightness2 = brightness2 - fadeAmount2;
      if (brightness2 < 0) {
        brightness2 = 0;
      }
      //digitalWrite(11, LOW);
      Serial.println("BlueLED brightness is ");
      Serial.println(brightness2);
    }
    else if (str == "BLED_ON") {                                // 若字串值是 "LED_ON" 開燈
      brightness2 = 255;                                         // 開燈
      Serial.println("BlueLED is ON");                       // 回應訊息給電腦
    }
    else if (str == "BLED_OFF") {
      brightness2 = 0;
      Serial.println("BlueLED is OFF");
    }

    else if (str == "flicker") {

      digitalWrite(10, HIGH);                               // 點亮LED
      digitalWrite(11, HIGH);
      delay(300);                                          // 延時1000ms(即1秒)
      digitalWrite(10, LOW);                                // 熄滅LED
      digitalWrite(11, LOW);
      delay(300);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(300);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      delay(300);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      delay(300);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);

      Serial.println("flash");
    }
  }
}

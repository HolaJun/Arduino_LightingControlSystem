
// 컴퓨터공학과 20153219 임정훈

// [Error] 'Serial3' was not declared in this scope 발생시 
//   -> 아두이노가 잘 연결되있는지 확인. 포트가 제대로 설정되어있는지 확인.

#include <Time.h>
#include <TimeLib.h>
#include <TimeAlarms.h>
#include <SHT1x.h>
#include <LiquidCrystal.h>

#define dataPin 22
#define clockPin 23
SHT1x sht1x(dataPin, clockPin);

LiquidCrystal lcd(40, 54, 41, 42, 43, 44, 45);

const int ledPin1 = 24; // IO모듈 첫번째 LED 핀번호
const int ledPin2 = 25; // IO모듈 두번째 LED 핀번호
const int buttonPin1 = 28; // IO모듈 첫번쨰 버튼 핀번호
const int buttonPin2 = 29; // IO모듈 두번째 버튼 핀번호
const int ultrasonicPin = 39; // 초음파센서 핀번호
const int relayPin = 2; // 릴레이모듈 핀번호
const int buzzer = 11; // 부저 핀번호
int onoff = 1;

// 초음파센서 관련 변수
int dummcnt;
long distance;
long tempture;
unsigned long duration;


void setup() {
  Serial.begin(9600);
  Serial.println("HelloWorld! Serial Start");
  Serial3.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(ultrasonicPin, LOW);
  tempture = 25;
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  setTime(16, 00, 00, 14, 06, 2018);
  lcd.begin(8, 2);
  lcd.clear();
  
  // LCD 첫번째 줄 출력
  lcd.setCursor(0,0);
  lcd.print(year());
  lcd.print("-");
  lcd.print(month());
  lcd.print("-");
  lcd.print(day());  
}

void loop() {
  // LCD 두번째 줄 출력
  float temp_c;
  temp_c = sht1x.readTemperatureC();
  lcd.setCursor(0,1);
  lcd.print(temp_c);
  lcd.print("C");

  // 첫번째 버튼을 눌렀다면
  if(digitalRead(buttonPin1) == HIGH) {
    digitalWrite(ledPin1, HIGH);
  } else { 
    digitalWrite(ledPin1, LOW);
    digitalWrite(relayPin, LOW);
  }
  // 두번째 버튼을 눌렀다면
  if(digitalRead(buttonPin2) == HIGH) {
    digitalWrite(ledPin2, HIGH);
  } else { 
    digitalWrite(ledPin2, LOW);
    digitalWrite(relayPin, HIGH);
  }
  
  // 초음파센서 시작   
  pinMode(ultrasonicPin, OUTPUT);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);
  pinMode(ultrasonicPin, INPUT);
  duration = pulseIn(ultrasonicPin, HIGH);

  distance = (331.5 + 0.607 * tempture) * (duration * 0.001 / 2) / 10 ;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("cm");

  // 초음파 거리가 15cm 미만이라면, 릴레이모듈 실행(스위치 ON/OFF)
  if (distance  < 15) {
    delay(600);
    onoff = switching_Relay(onoff);
  }

  // 블루투스 모듈 설정
  if (Serial.available()) {
    Serial3.write(Serial.read());
  }
  if (Serial3.available()) {
    char data = Serial3.read();

    if (data == '1') {
      Serial.println("블루투스 lighton");
      digitalWrite(relayPin, LOW);
    }
    else if (data == '0') {
      Serial.println("블루투스 lightoff");
      digitalWrite(relayPin, HIGH);
    }
  }  
  delay(500);
}

// 스위치 ONOFF 함수
int switching_Relay(int onoff) {
  if (onoff == 1) {
    digitalWrite(relayPin, HIGH);
    return 0;
  }
  else if (onoff == 0) {
    digitalWrite(relayPin, LOW);
    return 1;
  }
}


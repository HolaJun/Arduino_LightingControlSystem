# 아두이노, 원격전등제어, 성공적.

> #### **아두이노 우노, 안드로이드 블루투스 앱을 이용해 집 안의 전등을 ON/OFF 제어합니다**



## 제작 계기

![아두이노](https://i.imgur.com/x5S57R5.png)

- 오래된 자취방 덕분에 전등 스위치가 현관문에 위치되어 있다.

- 불을 끄러 가기 너무 귀찮다 

  → 원격으로 전등을 제어할 수는 없을까?

<br>

## 개발 환경

- OS: Windows 10 64 bit
- Tool: ARDUINO 1.8.7
- Moudule: Bluetooth HC-06, LCD, Temp&Humi Sensor, Button, Ultrasonic, Relay 
- Library: SHT1x, Time-master, TimeAlarms-master

<br>

## 기능 시연

### 1. 블루투스 앱을 통한 전등제어

![](https://media.giphy.com/media/7T2Y1K0INxUelUYFLT/giphy.gif)

<br>

### 2. 버튼을 이용한 전등제어

![](https://media.giphy.com/media/9VcCi8uIiitnkZlKEF/giphy.gif)

<br>

### 3. 초음파 센서를 이용한 전등제어

![](https://media.giphy.com/media/dn11cRVTPNRJYPZddo/giphy.gif)

<br>

## 보완해야할 점

- 앱이 많이 허접함
  - 전반적인 UI 개선
  - 블루투스가 아닌 와이파이 모듈 사용으로 집 밖에서도 원격 가능
  - 알람기능 추가
- 전구가 아닌 실제 전등에 연결후 전원 제어
  - 집의 모든 전등 연결

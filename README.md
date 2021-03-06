![header](https://capsule-render.vercel.app/api?type=Cylinder&color=auto&height=200&section=header&text=Elevator%20&fontSize=100)

# 프로젝트 제목

Atmega128을 활용 LCD, 홀센서, 서보모터를 응용한 엘리베이터 제작

## 제작 목표

Atmega128을 사용하여 DC모터를 조작, 홀센서를 사용하여 층 구분하며 스위치를 누르면 작동하고 해당 층에 도착할 시 서보모터가 승강기 문을 열어주고 일정 시간 후 닫히도록 제작.

### 유의점

1층 또는 4층으로 이동하는 승강기가 앞 선 층의 스위치 입력이 있을 경우 먼저 정지 할 수 있도록 제작이 되어야함.

### 사용 부품

```
FND
홀센서
LCD
스위치
저항
DC모터
서보모터
Atmega128
전선
알루미늄 프로파일
아크릴 판
아크릴 테이프 등
```

## 제작 과정

9조 - 부품 수배 및 설계, LCD 코딩

2조 - DC, 서보모터 코딩

```
1~2 주차 - 부품 및 재료 조달, 기판 납땜

3주차 - 외형 제작, 프레임 제작

4주차 - 코딩 및 완성품 제작
```

## 문제점

부품 수급 차질

```
W135 홀센서 작동 오류 – A04E 홀센서 구매
```

LCD 표기 오류
```
LCD 출력시 글자가 깨지고 엘리베이터 정지시간이 지연
```

코딩 오류
```
미처 발견하지 못한 헤더파일 오류와 자잘한 충돌 및 오류가 발생
```

## 시연 영상

```
https://youtu.be/ScPlI7iRta8
```

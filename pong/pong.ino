// #include <DMD2.h>
// #include "SystemFont5x7.h"
// // #include <TimerOne.h>

// SoftDMD dmd(1, 1, 7, 6, 5, 3, 4, 2);
// int x = 15, y = 7, speedX = 1, speedY = 1, aux1, aux2, aux3, aux4, ScoreA, ScoreB;

// void setup() {
//     pinMode(9, OUTPUT);
//     dmd.setBrightness(255);
//     dmd.selectFont(SystemFont5x7);
//     dmd.begin();
//     dmd.drawString(1, 0, F("PING ")); 
//     dmd.drawString(2, 8, F(" PONG")); 
//     delay(2000);
//     displayScore();
//     startGame();
// }

// void loop() {
//     drawBall();
//     drawPlayerA();
//     drawPlayerB();
//     moveBall();
//     delay(100);
// }

// void drawBall() {
//     analogWrite(9, 0);
//     dmd.setPixel(aux1, aux2, GRAPHICS_OFF);
//     dmd.setPixel(x, y, GRAPHICS_ON);
//     aux1 = x;
//     aux2 = y;
// }

// void drawPlayerA() {
//     int analogA = map(analogRead(A0), 0, 1023, -3, 15);
//     dmd.drawLine(1, aux3, 1, aux3 + 3, GRAPHICS_OFF);
//     dmd.drawLine(1, analogA, 1, analogA + 3, GRAPHICS_ON);
//     aux3 = analogA;
//     if (x == 1 && y >= aux3 && y <= aux3 + 3) {
//         analogWrite(9, 30);
//         speedX = -speedX;
//     }
// }

// void drawPlayerB() {
//     int analogB = map(analogRead(A1), 0, 1023, -3, 15);
//     dmd.drawLine(30, aux4, 30, aux4 + 3, GRAPHICS_OFF);
//     dmd.drawLine(30, analogB, 30, analogB + 3, GRAPHICS_ON);
//     aux4 = analogB;
//     if (x == 30 && y >= aux4 && y <= aux4 + 3) {
//         analogWrite(9, 30);
//         speedX = -speedX;
//     }
// }

// void moveBall() {
//     if (x > 31) { 
//         ScoreA++;
//         if (ScoreA > 99) ScoreA = 0;  
//         displayScore();
//         speedX = -speedX;
//         startGame();
//     } else if (x < 0) {
//         ScoreB++;
//         if (ScoreB > 99) ScoreB = 0;  
//         displayScore();
//         speedX = -speedX;
//         startGame();
//     }
//     if (y > 15) {
//         speedY = -speedY;
//         analogWrite(9, 30);
//     } else if (y < 0) {
//         speedY = -speedY;
//         analogWrite(9, 30);
//     }
//     x = x + speedX;
//     y = y + speedY; 
// }

// void displayScore() {
//     dmd.clearScreen();  
//     dmd.drawString(2, 0, "A: " + String(ScoreA)); 
//     dmd.drawString(2, 8, "B: " + String(ScoreB)); 
//     delay(2000);  
//     dmd.clearScreen();  
// }

// void startGame() {
//     dmd.clearScreen();
//     x = 15, y = 7;
//     dmd.drawString(2, 4, F("READY!"));
//     delay(2000);
//     dmd.clearScreen();  
// }

/*
//JUEGO PONG CON ARDUINO UNO Y MATRIZ LED 16X32 P10
//MAS INFORMACION LA ENCUENTRAS EN MI BLOG:
//dinoelectro.blogspot.com
//
//PENDIENTE:
//   MARCADOR DE PUNTAJE
//   MODO DE DOS JUGADORES
//
//CONEXIONES:
//  ARDUINO________________DMD
//  PIN9___________________OE
//  PIN6___________________A
//  PIN7___________________B
//  PIN13__________________SLK
//  PIN8___________________SCLK
//  PIN11__________________SPI
//  CANAL A0_______________Pot 10K
//  PIN5___________________Zumbador
*/
#include <SPI.h>

#include <DMD.h>

#include <TimerOne.h>

#include "SystemFont5x7.h"

#include "Arial_black_16.h"


#define ROW 1

#define COLUMN 1

#define FONT Arial_Black_16


DMD led_module(ROW, COLUMN);


void scan_module()

{

  led_module.scanDisplayBySPI();

}


void setup()

{

  Timer1.initialize(2000);

  Timer1.attachInterrupt(scan_module);

  led_module.clearScreen( true );

}

void loop()

{

    led_module.selectFont(FONT);

    led_module.drawMarquee("Welcome to Circuit Digest",25, (32 * ROW), 0);

    long start = millis();

    long timming = start;

    boolean flag = false;

    while (!flag)

    {

      if ((timming + 20) < millis()) 

      {

        flag = led_module.stepMarquee(-1, 0);

        timming = millis();

      }

    }

  }


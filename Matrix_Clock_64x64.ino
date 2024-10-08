// Required libraries: RTC for clock, Wire for I2C, RGBMatrix for LED matrix
#include <RTClib.h>
#include<Wire.h>
#include <DFRobot_RGBMatrix.h> 

// Initialization of RTC and LED matrix
RTC_DS1307 RTC;
#define OE   	9
#define LAT 	10
#define CLK 	11
#define A   	A0
#define B   	A1
#define C   	A2
#define D   	A3
#define E   	A4
#define WIDTH 64
#define _HIGH	64

DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, _HIGH);

const uint16_t BLACK = matrix.Color333(0, 0, 0); // Black background color

// Display coordinates and dimensions
const int XMIN = 30;
const int YMIN = 0;
const int XHOUR = 0;
const int YHOUR = 0;
const int UNIT_HEIGHT = 16;
const int UNIT_WIDTH = 40;

int minutePrecedente = -1; 
int hourPrecedente = -1; 
int prochaineHeureAffichee = -1;
int prochaineMinuteAffichee = -1;
int minutesRestantesPrecedentes = -1; 

// Clears a specific section of the screen
void screen_clear_unit(int x, int y,int width, int height)
{
  matrix.fillRect(x, y, width, height, matrix.Color333(0, 0, 0));
}

// Displays the time of the next period if it has changed
void afficherHeureProchainePeriode(int heure, int minute) 
{
    int heuresDebut[] = {8, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int minutesDebut[] = {0, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10};
    int nombrePeriodes = sizeof(heuresDebut) / sizeof(heuresDebut[0]);

    int prochaineHeure = 8;
    int prochaineMinute = 0;
    
    // Search for the next period
    for (int i = 0; i < nombrePeriodes; ++i) {
        if (heure < heuresDebut[i] || (heure == heuresDebut[i] && minute < minutesDebut[i])) {
            prochaineHeure = heuresDebut[i];
            prochaineMinute = minutesDebut[i];
            break;
        }
    }
    
        if (prochaineHeure != prochaineHeureAffichee || prochaineMinute != prochaineMinuteAffichee) {
        screen_clear_unit(0, 26, 64, UNIT_HEIGHT); 
        matrix.setTextSize(2);
        matrix.setCursor(0, 26);
        
        if (prochaineHeure < 10) {
        matrix.setTextColor(matrix.Color333(0, 0, 0));
        matrix.print("0");
        }

        matrix.setTextColor(matrix.Color333(7, 7, 7));
        matrix.print(prochaineHeure);
        matrix.print(":");
        if (prochaineMinute < 10) 
        matrix.print("0");
        matrix.print(prochaineMinute);

        prochaineHeureAffichee = prochaineHeure;
        prochaineMinuteAffichee = prochaineMinute;
        }
}

// Search for the next period
void afficherTempsRestant() 
{
    DateTime now = RTC.now();  
    int minuteActuelle = now.minute();
    int heureActuelle = now.hour();
    int minutesRestantes = (prochaineHeureAffichee * 60 + prochaineMinuteAffichee) - (heureActuelle * 60 + minuteActuelle);

    if (minutesRestantes < 0) {
        if (minutesRestantesPrecedentes >= 0) {
            screen_clear_unit(1, 49, 64, UNIT_HEIGHT);  
        }
        matrix.setCursor(1, 49);  
        matrix.setTextSize(2);     
        matrix.setTextColor(matrix.Color888(255, 20, 147)); 
        matrix.print("FINI!");
        minutesRestantesPrecedentes = minutesRestantes;
        return;
    }

    if (minutesRestantes != minutesRestantesPrecedentes) {
        screen_clear_unit(1, 49, 64, UNIT_HEIGHT);  
        matrix.setCursor(1, 49);  
        matrix.setTextSize(2);     
          if (minutesRestantes < 10) {
              matrix.setTextColor(matrix.Color333(0, 0, 0)); 
              matrix.print("0");
          }
        matrix.setTextColor(matrix.Color333(7, 7, 7)); 
        matrix.print(minutesRestantes);
        matrix.print("min");
        minutesRestantesPrecedentes = minutesRestantes;
    }
    if (minutesRestantes <= 5) {
        screen_clear_unit(1, 49, 64, UNIT_HEIGHT);  
        matrix.setCursor(1, 49);  
        matrix.setTextSize(2);  
    
        if (minutesRestantes < 10) {
            matrix.setTextColor(matrix.Color333(0, 0, 0));
            matrix.print("0");
        }
        matrix.setTextColor(matrix.Color333(255, 0, 0));
        matrix.print(minutesRestantes);
        matrix.print("min");
        minutesRestantesPrecedentes = minutesRestantes;
        delay(850);
      }
}

void setup() {
  matrix.begin();
  Wire.begin();
  RTC.begin(); 
  if (! RTC.isrunning())
  {
    matrix.setCursor(0, 0);  
    matrix.setTextSize(1);    
    matrix.setTextColor(matrix.Color333(7,7,7));
    matrix.print("RTC is NOT running!");
    // Adjust the time here only if the RTC is not yet started
    //RTC.adjust(DateTime(2024, 9, 12, 10, 25, 20));
    delay(1000);
  }
  // force time adjustment only once to fix the time
  //RTC.adjust(DateTime(2024, 10, 2, 8, 50, 00));
}

void loop() {
 DateTime now = RTC.now();
  int hour = now.hour();
  int minute = now.minute();
 
  // Display time
  matrix.setCursor(0, 1); 
  matrix.setTextSize(2); 

  if(now.hour() == hourPrecedente) {
      if (now.hour() < 10) {
          matrix.setTextColor(matrix.Color333(0, 0, 0)); 
          matrix.print("0");
      }
      matrix.setTextColor(matrix.Color333(7, 7, 7)); 
      matrix.print(now.hour(), DEC);
    } else {
        screen_clear_unit(XHOUR, YHOUR, UNIT_WIDTH, UNIT_HEIGHT);
          if (now.hour() < 10) {
              matrix.setTextColor(matrix.Color333(0, 0, 0)); 
              matrix.print("0");
          }
        matrix.setTextColor(matrix.Color333(7, 7, 7)); 
        matrix.print(now.hour(), DEC);
        hourPrecedente = hour;
    }
      matrix.print(':');
      if(now.minute() == minutePrecedente){
      }  else{
      screen_clear_unit(XMIN,YMIN,UNIT_WIDTH,UNIT_HEIGHT);
        if (now.minute() < 10){ 
          matrix.print("0");
        }
      matrix.print(now.minute(), DEC);
        minutePrecedente = minute;
  }

  // Display of indications and countdown
  matrix.setCursor(1, 17);
  matrix.setTextColor(matrix.Color888(30, 144, 255));
  matrix.setTextSize(1);
  matrix.print("->periode");

  afficherHeureProchainePeriode(hour, minute);
  
  matrix.setCursor(1, 41);
  matrix.setTextColor(matrix.Color888(154, 205, 50));
  matrix.setTextSize(1);
  matrix.print("Il reste");

  afficherTempsRestant();
  
  delay(100);
}
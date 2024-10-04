# ENGLISH - Clock with LED 64x64 matrix panel

## General Informations
This project shows a LED matrix panel with 64x64 full RGB pixels driven by a ATMega-2560 Arduino. I added a Real Time Clock TinyRTC_DS1307 to show the time.

This display was created to help teachers in my department quickly know how much time is left until the start of the next class when they are in the technicians office.
So I had fun programming an RTC with a matrix of RGB LEDs to display 3 things:
1. The current time
2. The time that the next period starts
3. The number of minutes remaining until the start of the next period.

At the school, the schedule for the classes are made of periods of 50 minutes each with a 5 minutes breaks between them so I had to put the time of the start of each period in the code.
The time is displayed in 24 hour format so if you want to display the time in AM/PM format you will need to change the way it is displayed to make it fit.
8:00, 8:55, 9:50, 10:45, 11:40, 12:35, 13:30, 14:25, 15:20, 16:15, 17:10 and then the last period finishes at 18:00
For the last 5 minutes before a period start, the remaining time flases in red.
Instead of showing the remaining time or empty remaining time when the start of the last period begins (at 17h10), I added ''FINI'' to indicate the end of the day.

## Libraries
- For 64x64 LED matrix : DFRobot_RGBMatrix   [https://github.com/DFRobot/DFRobot_RGBMatrix.git]
- For the DS1037 RTC : RTClib   [https://github.com/adafruit/RTClib]

## Materials
- 64x64 RGB LED Matrix Panel Full Color 192x192 mm 3mm Pitch 4096 LEDs Adjustable Brightness Brand: iiunius     [https://www.amazon.ca/dp/B0BYJHMFSQ?ref=ppx_yo2ov_dt_b_fed_asin_title]
- Robojax DS1307 AT24C32 Real Time Clock RTC I2c Module for Arduino    [https://www.amazon.ca/dp/B07GGM7GL4?ref=ppx_yo2ov_dt_b_fed_asin_title]
- Arduino Mega 2560 Rev3      [https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?srsltid=AfmBOorYKxeyBhkbbV5RMA4XHm1_XfgZI-iuLKvp3k0p0sYNPKFb4Qjt]
- 3D printer Prusa MK3S+


## Arduino connections

### Matrix connection
| Wire number | Color | Matrix Pin | Mega Pin |
| :---: | ------ | ------ | ----- |
| 1  | Brown  | R1  | D24  |
| 2  | Red  | G1  | D25  |
| 3  | Orange  | B1  | D26  |
| 4  | Yellow  | N  | GND  |
| 5  | Green  | R2  | D27  |
| 6  | Blue  | G2  | D28  |
| 7  | Violet  | B2  | D29  |
| 8  | Grey  | LE  | A4  |
| 9  | White  | LA  | A0  |
| 10  | Black  | LB  | A1  |
| 11  | Brown  | LC  | A2  |
| 12  | Red  | LD  | A3  |
| 13  | Orange  | CLK  | D11  |
| 14  | Yellow  | LAT  | CD10  |
| 15  | Green  | OE  | CD9  |
| 16  | Blue  | GND  | GND  |

### RTC connection
| RTC Pin | Mega Pin |
|  ------ | ----- |
| SDA  | SDA/C20  |
| SCL  | SCL/C21  |
| 5V  | 5V  |
| GND  | GND  |


# FRANÇAIS - Horloge avec une matrice LED 64x64

## Informations Générales
Ce projet montre une matrice LED avec 64x64 pixels RVB complets geré par un Arduino ATMega-2560. J'ai ajouté une horloge temps réel TinyRTC_DS1307 pour afficher l'heure.

Cet afichage a été crée pour aider les enseignants de mon département à savoir rapidement il reste combien de temps avant le début du prochain cours lorsqu'ils sont dans le bureau des techniciens.
Je me suis donc amusée à programmer un RTC avec une matrice de LED RGB pouor afficher 3 choses:
1. L'heure actuelle
2. L'heure que la prochaine période commence
3. Le nombre de minutes restantes avant le début de la prochaine période.

A l'école, l'horaire des cours est composé de périodes de 50 minutes chacune avec 5 minutes de pause entre elles donc j'ai dû mettre l'heure de début de chaque période dans le code.
L'heure est affichée au format 24 heures. Si vous souhaitez afficher l'heure au format AM/PM, vous devrez modifier la façon dont elle est affichée pour avoir de la place.
8h00, 8h55, 9h50, 10h45, 11h40, 12h35, 13h30, 14h25, 15h20, 16h15, 17h10 puis la dernière période se termine à 18h00
Pendant les 5 dernières minutes avant le début d'une période, le temps restant clignote en rouge.
Au lieu d'afficher le temps restant ou de le temps restant vide lorsque le début de la dernière période commence (à 17h10), j'ai ajouté ''FINI'' pour indiquer que la fin de la journée.

## Librairies utilisées
- Pour la matrice DEL 64x64 : DFRobot_RGBMatrix   [https://github.com/DFRobot/DFRobot_RGBMatrix.git]
- Pour le RTC DS1037 : RTClib   [https://github.com/adafruit/RTClib]

## Matériels utilisés
- 64x64 RGB LED Matrix Panel Full Color 192x192 mm 3mm Pitch 4096 LEDs Adjustable Brightness Brand: iiunius     [https://www.amazon.ca/dp/B0BYJHMFSQ?ref=ppx_yo2ov_dt_b_fed_asin_title]
- Robojax DS1307 AT24C32 Real Time Clock RTC I2c Module for Arduino    [https://www.amazon.ca/dp/B07GGM7GL4?ref=ppx_yo2ov_dt_b_fed_asin_title]
- Arduino Mega 2560 Rev3      [https://store-usa.arduino.cc/products/arduino-mega-2560-rev3?srsltid=AfmBOorYKxeyBhkbbV5RMA4XHm1_XfgZI-iuLKvp3k0p0sYNPKFb4Qjt]
- 3D printer Prusa MK3S+

## Connections du matériel sur le Arduino

### Connection de la matrice
| Numéro de fil | Couleur | Pin sur Matrix | Pin sur Mega |
| :---: | ------ | ------ | ----- |
| 1  | Brun  | R1  | D24  |
| 2  | Rouge  | G1  | D25  |
| 3  | Orange  | B1  | D26  |
| 4  | Jaune  | N  | GND  |
| 5  | Vert  | R2  | D27  |
| 6  | Bleu  | G2  | D28  |
| 7  | Violet  | B2  | D29  |
| 8  | Gris  | LE  | A4  |
| 9  | Blanc  | LA  | A0  |
| 10  | Noir  | LB  | A1  |
| 11  | Brun  | LC  | A2  |
| 12  | Rouge  | LD  | A3  |
| 13  | Orange  | CLK  | D11  |
| 14  | Jaune  | LAT  | CD10  |
| 15  | Vert  | OE  | CD9  |
| 16  | Bleu  | GND  | GND  |

### connection du RTC
| Pin sur RTC | Pin sur Mega |
|  ------ | ----- |
| SDA  | SDA/C20  |
| SCL  | SCL/C21  |
| 5V  | 5V  |
| GND  | GND  |

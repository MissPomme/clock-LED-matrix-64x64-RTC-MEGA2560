# Horloge avec une matrice LED 64x64
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

# Clock with LED 64x64 matrix panel
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

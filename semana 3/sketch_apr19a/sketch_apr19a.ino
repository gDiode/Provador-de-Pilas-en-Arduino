/*probador de pilas
Conectamos una pila entre A0 (entrada analógica 0) y GND. En el LCD nos mostrara su nivel de carga perfecto, bueno, regular, malo. 
*/

//habilitamos la librería para el manejo del LCD

#include <LiquidCrystal.h>
//pines a usar del LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() 
{
lcd.begin (16,2);         //columnas 16 filas 2
lcd.print("ARDUINO");
delay(1000);
lcd.clear();
}
void loop()
{
lcd.clear();
lcd.setCursor(0,0);           //cursor en la posición 0 de la lcd
lcd.print("Probador pilas");
lcd.setCursor(0,1);
lcd.print(analogRead(0)*5.00/1024);     //conversión de binario a voltaje
lcd.print("V=>");
lcd.setCursor(8,1);
if ((analogRead(0)*5.00/1023.00) >1.40)
{
 lcd.print("Perfecto");
}
else if ((analogRead(0)*5.00/1023.00)>1.20 && (analogRead(0)*5.00/1023.00) <1.40)
{
lcd.print("Bueno");
}
else if ((analogRead(0)*5.00/1023.00)<1.20 && (analogRead(0)*5.00/1023.00) >0.30)
{
lcd.print("Regular");
}
else if ((analogRead(0)*5.00/1023.00) <0.3)
{
lcd.print("Malo");
}
else
{
lcd.print(" ");
}
delay(250);
}

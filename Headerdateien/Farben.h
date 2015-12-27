/*
============================================================================
Autor : Patrick Sch�nfeld
Klasse : FI12
Dateiname : color.h
Datum : 17.03.09
Beschreibung: Ver�ndert die Farbe der Console
Version : 1.0
�nderung : -
Programmschnittstelle: color (int color)
Das Programm gibt den Wert 0 oder 1 zur�ck.
Es werden keine Argumente erwartet.
============================================================================
*/
#if !defined (COLOR_H)
#define COLOR_H
#include <windows.h>
void color(int color);

#endif
/*
============================================================================
Funktion color(die Farbe)
Ver�ndert die Farbe in der Console, m�gliche Parameter:
Schriften: 0=normal; 1=Rot; 2=Gr�n; 3=Gelb; 4=Dunkel Blau; 5=Pink; 6=hell Blau; 7=schwarze Schrift + Grau HintiErgrund
Hintergr�nde+Schrift: 8=wei�er Hintergrund Graue Schrift;9=wei�er Hintergrund Rote Schrift;
10=gr�ne Schrift, wei�er Hintergrund
11=schei�e;12=wei�er Hintergrund, blaue Schrift;13=pinke Schrift,wei�er Hintergrund
14=wei�er Hintergrund,hell blaube Schrift;15=alles wei�;16=wei�e Schrift
============================================================================
*/
void color(int color)
{
  switch (color)
  {
  case 0:
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
    break;
  case 1:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                         FOREGROUND_INTENSITY | FOREGROUND_RED);
    break;
  case 2:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                      FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    break;
  case 3:  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                      FOREGROUND_INTENSITY | FOREGROUND_RED |
                      FOREGROUND_GREEN);
    break;
  case 4:  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                      FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    break;
  case 5: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                     FOREGROUND_INTENSITY | FOREGROUND_RED |
                     FOREGROUND_BLUE);
    break;
  case 6:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                    FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                    FOREGROUND_BLUE);
    break;
  case 7:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                  BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
    break;
  case 8:  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                  BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                  BACKGROUND_RED | BACKGROUND_GREEN |
                  BACKGROUND_BLUE);
    break;
  case 9: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                  BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                  BACKGROUND_RED | BACKGROUND_GREEN |
                  BACKGROUND_BLUE |
      FOREGROUND_RED);
    break;
  case 10:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                 BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                 BACKGROUND_RED | BACKGROUND_GREEN |
                 BACKGROUND_BLUE | FOREGROUND_GREEN);
    break;
  case 11:  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                 BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                 BACKGROUND_RED | BACKGROUND_GREEN |
                 BACKGROUND_BLUE | FOREGROUND_RED |
                 FOREGROUND_GREEN);
    break;
  case 12:  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                 BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                 BACKGROUND_RED | BACKGROUND_GREEN |
                 BACKGROUND_BLUE | FOREGROUND_BLUE);
    break;
  case 13: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                 BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                 BACKGROUND_RED | BACKGROUND_GREEN |
                 BACKGROUND_BLUE | FOREGROUND_RED |
                 FOREGROUND_BLUE);
    break;
  case 14: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                 BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                 BACKGROUND_RED | BACKGROUND_GREEN |
                 BACKGROUND_BLUE | FOREGROUND_GREEN |
                 FOREGROUND_BLUE);
    break;
  case 15: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                BACKGROUND_RED | BACKGROUND_GREEN |
                BACKGROUND_BLUE | FOREGROUND_RED |
                FOREGROUND_GREEN | FOREGROUND_BLUE);
    break;
   case 16: 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_INTENSITY | FOREGROUND_RED |
                FOREGROUND_GREEN | FOREGROUND_BLUE);
    break;
  default :    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                FOREGROUND_RED |
                FOREGROUND_GREEN | FOREGROUND_BLUE);
    break;
  }
}

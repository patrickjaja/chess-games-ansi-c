/*
============================================================================
Autor : Patrick Sch�nfeld
Klasse : FI12
Dateiname : Main.c
Datum : 17.03.09
Beschreibung: Erstellt die Men�s und bietet die Login und Registrations M�glichkeit
Version : 1.0
�nderung : -
Programmschnittstelle: int main(void)
Das Programm gibt den Wert 0 oder 1 zur�ck.
Es werden keine Argumente erwartet.
============================================================================
*/

/*
============================================================================
Pr�prozessoranweisungen
============================================================================
*/

#include "Funktionen.h"
#include "Farben.h"


/*
============================================================================
Funktion main()
@return OK
============================================================================
*/
int main (void)
{
	HWND hwnd = FindWindow("ConsoleWindowClass",NULL);
	MoveWindow(hwnd,0,0,900,700,TRUE);

	HauptMenu();

	return OK;
}
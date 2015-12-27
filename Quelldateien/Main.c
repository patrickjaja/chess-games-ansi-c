/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : Main.c
Datum : 17.03.09
Beschreibung: Erstellt die Menüs und bietet die Login und Registrations Möglichkeit
Version : 1.0
Änderung : -
Programmschnittstelle: int main(void)
Das Programm gibt den Wert 0 oder 1 zurück.
Es werden keine Argumente erwartet.
============================================================================
*/

/*
============================================================================
Präprozessoranweisungen
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
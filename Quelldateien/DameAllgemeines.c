/*
   ============================================================================
   Programmname: DameAllgemeines.c
   Autor       : Andreas Danek, Daniel Janﬂen
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Funktionen
   ============================================================================
*/

/*
============================================================================
Pr‰prozessoranweisungen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion DameiErbeutenBelegen()

   @aufruf: DameSpielen()
   @beschreibung: belegt das Array mit den default-Wert -5, denn dieser
				  Wert wird im Programm nicht benutzt
   @return OK: Das Array wurde erfolgreich belegt
   ========================================================================
*/
int DameiErbeutenBelegen()
{
	int iZaehler1;
	int iZaehler2;

	for (iZaehler1 = 0; iZaehler1 < 48; iZaehler1++)
	{
		for (iZaehler2 = 0; iZaehler2 < 2; iZaehler2++)
		{
			iErbeuten[iZaehler1][iZaehler2] = -5; 
		}
	}
	return OK;
}
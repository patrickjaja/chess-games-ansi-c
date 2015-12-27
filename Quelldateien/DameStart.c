/*
   ============================================================================
   Programmname: DameStart.c
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
   Funktion Dame()
   @Beschreibung: Main-Funktion welche das Spielfeld kreiert und das Spiel
				  steuert, sowie am Ende den Gewinner ausgibt
   @return OK: Spiel wurde erfolgreich beendet
   ========================================================================
*/
int Dame(void)
{
 int iEnde = 0, iErgebnis;
 iSpieler = -1;

 ErstelleSpielFeld(8,8);
 DameSetzeStartPosition();
 while (iEnde == 0)
 {
	iEnde = DameSpielen();
 }

 iErgebnis = SpielErgebnis(iEnde, iSpieler);
 return iErgebnis;
}
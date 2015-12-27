/*
   ============================================================================
   Programmname: VierGewinntStart.c
   Autor       : Milan Niezgodka, Pascal Neuhausen
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Funktionen
   ============================================================================
*/

/*
============================================================================
Präprozessoranweisungen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion VierGewinnt()
   @Aufruf: Spielmenu()
   @return iErgebnis: das Spiel ist fertig
   ========================================================================
*/
int VierGewinnt(void)
{
 int iEnde = 0, iErgebnis;
 iSpieler = -1;

 ErstelleSpielFeld(6,7);
 while (iEnde == 0)
 {
	iSpieler *= -1;
	Spieler();
	iEnde = VierGewinntSpielen();
 }

 iErgebnis = SpielErgebnis(iEnde, iSpieler);
 return iErgebnis;
}
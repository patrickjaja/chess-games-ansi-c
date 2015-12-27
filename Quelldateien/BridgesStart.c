/*
   ============================================================================
   Programmname: BridgesStart.c
   Autor       : David Frerich
   Datum       : 19.03.2009
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
   Funktion Bridges()

   @Aufruf: -
   @return Spieler
   ========================================================================
*/
int Bridges(void)
{
 int iEnde = 0, iErgebnis;
 iSpieler = -1;

 ErstelleSpielFeld(17,17);
 BridgesSetzeSpielFeld();
 while (iEnde == 0)
 {
	iSpieler *= -1;
	Spieler(iSpieler);
	iEnde = BridgesSpielen();
 }
 iErgebnis = SpielErgebnis(iEnde, iSpieler);
 return iErgebnis;
}
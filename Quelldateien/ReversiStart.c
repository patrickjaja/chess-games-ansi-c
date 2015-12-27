/*
   ============================================================================
   Programmname: ReversiStart.c
   Autor       : Jakob Bohr, Gilles Meyer, Andreas Danek, Daniel Janßen
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
   Funktion Reversi()

   @return OK: das Spiel ist fertig
   ========================================================================
*/
int Reversi(void)
{
 int iEnde = 0;
 int iGewinner, iErgebnis;
 iSpieler = -1;

  /*
  * Spielvorbereitung
  */
 ErstelleSpielFeld(8,8);
 ReversiSetzeStartPositionen();
 ZeichneFeld(8,8);
  /*
  * Spieldurchführung
  */
 while (iEnde == 0)
 {
	iSpieler*=-1;
	Spieler();
	iEnde = ReversiSpielen(0);
	ZeichneFeld(8,8);
 }
 if(iEnde == 2)
 {
	/*iGewinner = iSpieler * -1;*/
	iGewinner = 0;
 }
 else
 {
	iGewinner = ReversiZaehleSteine();
 }
 iErgebnis = SpielErgebnis(1, iGewinner);

 return iErgebnis;
}
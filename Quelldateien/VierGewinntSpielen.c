/*
   ============================================================================
   Programmname: VierGewinntSpielen.c
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
   Funktion VierGewinntSpielen()

   @aufruf: VierGewinntStart()
   @beschreibung: steuert das spiel
   @return iRueckgabe: Integer-Variable, welche angibt ob das Spiel zu Ende
					   ist (1 oder 2) oder nicht (0)
   ========================================================================
*/
int VierGewinntSpielen()
{
	int iEnde = 0;
	int iRueckgabe = 0;

	iRueckgabe = VierGewinntSteinSetzen();
	return iRueckgabe;
}

/*
   ========================================================================
   Funktion VierGewinntSteinSetzen()

   @aufruf: VierGewinntSpielen()
   @beschreibung: setzt die Steine und ruft Gewinnüberprüfungen bzw. Spiel-
				  endeüberprüfungen auf
   @return ENDE: Spieler hat aufgegeben, der Gegner hat gewonnen
   @return NOTOK: Spieler hat gewonnen, es liegen 4 in Reihe
   @return iRueckgabe: Spielfeld ist voll (2) oder das Spiel geht ganz
					   normal weiter (0)
   ========================================================================
*/
int VierGewinntSteinSetzen()
{
	int ixKoordinate;
	int iyKoordinate;
	int iRueckgabe = 0;

	if(PositionEingeben(&ixKoordinate, &iyKoordinate, 6, 7, 0) == NOTOK)
	{
		/*iSpieler *= -1;*/
		iSpieler = 0;
		return ENDE;
	}

	cSpielFeld[ixKoordinate][iyKoordinate] = cSpielsteine[0];
	ZeichneFeld(6,7);
	iRueckgabe = VierGewinntUeberpruefeVierInReihe(ixKoordinate, iyKoordinate);
	if (iRueckgabe > 0)
	{
		return NOTOK;
	}
	iRueckgabe = VierGewinntUeberpruefeSpielfeldVoll();
	return iRueckgabe;
}


/*
   ============================================================================
   Programmname: BridgesSpielen.c
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
   Funktion BridgesSpielen()

   @beschreibung: steuert das spiel
   @return iRueckgabe: Integer-Variable, welche angibt ob das Spiel zu Ende
					   ist (1 oder 2) oder nicht (0)
   ========================================================================
*/
int BridgesSpielen()
{
	int iXKoordinate = 0, iYKoordinate = 0;
	int iRueckgabe = 0;

	if(PositionEingeben(&iXKoordinate, &iYKoordinate, 17, 17, 0) == NOTOK)
	{
		/*iSpieler *= -1;*/
		iSpieler = 0;
		return ENDE;
	}

	cSpielFeld[iXKoordinate][iYKoordinate] = cSpielsteine[0];
	ZeichneFeld(17,17);
	iRueckgabe = BridgesUeberpruefe();

	return iRueckgabe;
}

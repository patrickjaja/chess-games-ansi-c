/*
   ============================================================================
   Programmname: BridgesUeberpruefen.c
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
   Funktion BridgesUeberpruefe()

   @beschreibung: Überprüfen ob ein Spieler gewonnen hat
   @return iSieg: Integer-Variable die Zurückgibt ob ein Spieler gewonnen
				  hat (=1) oder nicht (=0)
   ========================================================================
*/
int BridgesUeberpruefe()
{
	if(BridgesUeberpruefeSpielerSieg(ROT, 1) == ENDE)
	{
		return ENDE;
	}
	if(BridgesUeberpruefeSpielerSieg(BLAU, 2) == ENDE)
	{
		return ENDE;
	}
	return OK;
}


/*
   ========================================================================
   Funktion BridgesUeberpruefeSpielerSieg()

   @beschreibung:	Überprüfen ob ein Spieler gewonnen hat
   @param cFarbe:	Übergabe der Spielsteinfarbe
   @param iVonBis:	1 (Von Links nach Rechts) oder 2 (Von Oben nach Unten)
   @return:			Integer-Variable die Zurückgibt ob ein Spieler gewonnen
					hat (=1) oder nicht (=0)
   ========================================================================
*/
int BridgesUeberpruefeSpielerSieg(char cFarbe, int iVonBis)
{
	int iXKoordinate, iYKoordinate;
	int iBelegteFelder[17][17], iAktionen;

	for(iXKoordinate = 0; iXKoordinate < 17; iXKoordinate++)
	{
		for(iYKoordinate = 0; iYKoordinate < 17; iYKoordinate++)
		{
			if(cSpielFeld[iXKoordinate][iYKoordinate] == cFarbe && ((iXKoordinate == 0 && iVonBis == 1) || (iYKoordinate == 0 && iVonBis == 2)) )
			{
				iBelegteFelder[iXKoordinate][iYKoordinate] = 2;
			}
			else if(cSpielFeld[iXKoordinate][iYKoordinate] == cFarbe)
			{
				iBelegteFelder[iXKoordinate][iYKoordinate] = 1;
			}
			else
			{
				iBelegteFelder[iXKoordinate][iYKoordinate] = 0;
			}
		}
	}

	do
	{
		iAktionen = 0;
		for(iXKoordinate = 0; iXKoordinate < 17; iXKoordinate++)
		{
			for(iYKoordinate = 0; iYKoordinate < 17; iYKoordinate++)
			{
				if(iBelegteFelder[iXKoordinate][iYKoordinate] == 1
				&&( iXKoordinate-1 >= 0 && iBelegteFelder[iXKoordinate-1][iYKoordinate] == 2
					|| iXKoordinate+1 < 17 && iBelegteFelder[iXKoordinate+1][iYKoordinate] == 2
					|| iYKoordinate-1 >= 0 && iBelegteFelder[iXKoordinate][iYKoordinate-1] == 2
					|| iYKoordinate+1 < 17 && iBelegteFelder[iXKoordinate][iYKoordinate+1] == 2))
				{
					iAktionen++;
					iBelegteFelder[iXKoordinate][iYKoordinate] = 2;
				}
			}
		}
	} while(iAktionen != 0);

	if(iVonBis == 1)
	{
		for(iYKoordinate = 0; iYKoordinate < 17; iYKoordinate++)
		{
			if(iBelegteFelder[16][iYKoordinate] == 2)
			{
				return ENDE;
			}
		}
	}
	else if(iVonBis == 2)
	{
		for(iXKoordinate = 0; iXKoordinate < 17; iXKoordinate++)
		{
			if(iBelegteFelder[iXKoordinate][16] == 2)
			{
				return ENDE;
			}
		}
	}
	return OK;
}
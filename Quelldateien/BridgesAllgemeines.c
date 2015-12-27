/*
   ============================================================================
   Programmname: BridgesAllgemeines.c
   Autor       : David Frerich
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
   Funktion BridgesSetzeSpielFeld()

   @beschreibung: setzt die startsteine für Bridges
   @return OK: Zielfeld ist erstellt
   ========================================================================
*/
int BridgesSetzeSpielFeld()
{
	int iXZaehler, iYZaehler;

	for(iXZaehler = 0; iXZaehler < 17; iXZaehler++)
	{
		for(iYZaehler = 0; iYZaehler < 17; iYZaehler++)
		{
			if(cSpielFeld[iXZaehler][iYZaehler] == SCHWARZ)
			{
				if(iXZaehler%2 == 0)
				{
					cSpielFeld[iXZaehler][iYZaehler] = ROT;
				}
				else
				{
					cSpielFeld[iXZaehler][iYZaehler] = BLAU;
				}
			}
		}
	}
	
	ZeichneFeld(17, 17);

	return OK;
}

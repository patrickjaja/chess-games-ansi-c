/*
   ============================================================================
   Programmname: DameVorbereitung.c
   Autor       : Andreas Danek, Daniel Janßen
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
   Funktion DameSetzeStartPosition()

   @aufruf: main()
   @beschreibung: belegt das Spielfeld mit Figuren in der vorgegebenen
				  Startposition
   @return OK: gibt OK zurück wenn alles erfolgreich war
   ========================================================================
*/
int DameSetzeStartPosition()
{
	int iBreite;
	int iHoehe;
	int i2Zeile = 1;

	/* 
	 * weiße Steine 
	 */
	for (iHoehe = 0; iHoehe < 3; iHoehe++)
	{
		if (i2Zeile == -1)
		{
			for (iBreite = 0; iBreite < 8; iBreite+=2)
			{
				cSpielFeld[iBreite][iHoehe] = BLAU;
			}
		}
		else
		{
			for (iBreite = 1; iBreite < 8; iBreite+=2)
			{
				cSpielFeld[iBreite][iHoehe] = BLAU;
			}
		}
		i2Zeile = i2Zeile*-1;
	}
	/*
	 *schwarze Steine
	 */
	for (iHoehe = 5; iHoehe < 8; iHoehe++)
	{
		if (i2Zeile == -1)
		{
			for (iBreite = 0; iBreite < 8; iBreite+=2)
			{
				cSpielFeld[iBreite][iHoehe] = ROT;
			}
		}
		else
		{
			for (iBreite = 1; iBreite < 8; iBreite+=2)
			{
				cSpielFeld[iBreite][iHoehe] = ROT;
			}
		}
		i2Zeile = i2Zeile*-1;
	}
	ZeichneFeld(8,8);
	return OK;
}
/*
   ============================================================================
   Programmname: DameHilfsfunktionenSpringen.c
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
   Funktion DameSchlageStein()

   @aufruf: DameSpringen()
   @beschreibung: führt das Schlagen des Steines durch (für einen Stein und 
				  eine Dame)
   @param ixZiel: gewählte x-Zielkoordinate
   @param iyZiel: gewählte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gewählten Steines
   @param iyKoordinate: Die y-Koordinate des gewählten Steines
   @return OK: der Stein wurde bewegt und der Gegner geschlagen
   ========================================================================
*/
int DameSchlageStein(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate)
{
	int iSchon_Getauscht = 0;
	
	/*
	 * DameTausch prüft nur in der normalen Zugrichtung, aber da eine Dame 
	 * auch gegen die Zugrichtung schlagen kann findet der 2. Teil nochmal 
	 * statt
	 */
	iSchon_Getauscht = DameTausch(ixZiel, iyZiel, ixKoordinate, iyKoordinate);
	if (iSchon_Getauscht == 1)
	{
		if (iyZiel == iyKoordinate - iSpieler*2)
		{
			if (ixZiel < ixKoordinate)
			{
				cSpielFeld[ixKoordinate - 1][iyKoordinate - iSpieler] = SCHWARZ;
			}
			else
			{
				cSpielFeld[ixKoordinate + 1][iyKoordinate - iSpieler] = SCHWARZ;
			}


			if (iyZiel == 0 || iyZiel == 7)
			{
				cSpielFeld[ixZiel][iyZiel] = cSpielsteine [2];
			}
			else
			{
				cSpielFeld[ixZiel][iyZiel] = cSpielFeld[ixKoordinate][iyKoordinate];
				iSteinStehtIn[0][0] = ixZiel;
				iSteinStehtIn[0][1] = iyZiel;
			}
			cSpielFeld[ixKoordinate][iyKoordinate] = SCHWARZ;
		}
	}
	return OK;
}

/*
   ========================================================================
   Funktion DameTausch()

   @aufruf: DameSchlageStein()
   @beschreibung: führt das Schlagen des Steines durch (für einen Stein und 
				  eine Dame nach vorne)
   @param ixZiel: gewählte x-Zielkoordinate
   @param iyZiel: gewählte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gewählten Steines
   @param iyKoordinate: Die y-Koordinate des gewählten Steines
   @return OK: der Stein wurde bewegt und der Gegner geschlagen
   @return NOTOK: das Schlagen konnte nicht durchgeführt werden
   ========================================================================
*/
int DameTausch(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate)
{
	if (iyZiel == iyKoordinate + iSpieler*2)
	{
		if (ixZiel < ixKoordinate)
		{
			cSpielFeld[ixKoordinate - 1][iyKoordinate + iSpieler] = SCHWARZ;
		}
		else
		{
			cSpielFeld[ixKoordinate + 1][iyKoordinate + iSpieler] = SCHWARZ;
		}

		if (iyZiel == 0 || iyZiel == 7)
		{
			cSpielFeld[ixZiel][iyZiel] = cSpielsteine [2];
		}
		else
		{
			cSpielFeld[ixZiel][iyZiel] = cSpielFeld[ixKoordinate][iyKoordinate];
			iSteinStehtIn[0][0] = ixZiel;
			iSteinStehtIn[0][1] = iyZiel;
		}
		cSpielFeld[ixKoordinate][iyKoordinate] = SCHWARZ;
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DamePruefeSteinIniErbeuten()

   @aufruf: DameSpringen(int iErsterSprung)
   @beschreibung: überprüft ob der gewählte Stein erbeuten kann
   @param ixKoordinate: Die x-Koordinate des gewählten Steines
   @param iyKoordinate: Die y-Koordinate des gewählten Steines
   @return OK: der gewählte Stein kann erbeuten
   @return NOTOK: der gewählte Stein kann nicht erbeuten
   ========================================================================
*/
int DamePruefeSteinIniErbeuten(int ixKoordinate,int iyKoordinate)
{
	int iBreite;
	int iHoehe;

	for (iHoehe = 0; iHoehe < 48; iHoehe++)
	{
		for (iBreite = 0; iBreite < 2; iBreite++)
		{
			if (iErbeuten[iBreite][0] == ixKoordinate && iErbeuten[iBreite][1] == iyKoordinate)
			{
				return OK;
			}
		}
	}
	ZeichneFeld(8, 8);
	color(1);
	printf("\nFehler: W\204hlen Sie einen korrekten Stein aus\n");
	color(0);
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameGueltigerSprung()

   @aufruf: DameSpringen(int iErsterSprung)
   @beschreibung: überprüft die gewählten Zielkoordinaten auf Richtigkeit 
				  (Diagonal nach vorne ein fremder Stein/Dame sthehend und 
				  das Feld dahinter leer)
   @param ixZiel: gewählte x-Zielkoordinate
   @param iyZiel: gewählte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gewählten Steines
   @param iyKoordinate: Die y-Koordinate des gewählten Steines
   @return OK: der gewünschte Sprung kann durchgeführt werden
   @return NOTOK: der gewünschte Sprung kann nicht durchgeführt werden
   ========================================================================
*/
int DameGueltigerSprung(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate)
{
	if ((cSpielFeld[ixKoordinate - iSpieler][iyKoordinate + iSpieler] == cSpielsteine[3] &&
	 cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate - iSpieler][iyKoordinate + iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate + iSpieler] == cSpielsteine[3] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate + iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ))
	{
		return OK;
	}
	ZeichneFeld(8, 8);
	color(1);
	printf("\nFehler: Geben Sie ein korrektes Ziel ein\n");
	color(0);
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameGueltigerSprungDame()

   @aufruf: DameSpringen(int iErsterSprung)
   @beschreibung: überprüft die gewählten Zielkoordinaten auf Richtigkeit 
				  (Diagonal ein fremder Stein/Dame sthehend und das Feld 
				  dahinter leer)
   @param ixZiel: gewählte x-Zielkoordinate
   @param iyZiel: gewählte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gewählten Steines
   @param iyKoordinate: Die y-Koordinate des gewählten Steines
   @return OK: der gewünschte Sprung kann durchgeführt werden
   @return NOTOK: der gewünschte Sprung kann nicht durchgeführt werden
   ========================================================================
*/
int DameGueltigerSprungDame(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate)
{
	if ((cSpielFeld[ixKoordinate - iSpieler][iyKoordinate + iSpieler] == cSpielsteine[3] &&
	 cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate - iSpieler][iyKoordinate + iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate + iSpieler] == cSpielsteine[3] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate + iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate - iSpieler][iyKoordinate - iSpieler] == cSpielsteine[3] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate - iSpieler][iyKoordinate - iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate - iSpieler] == cSpielsteine[3] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ)
	 || (cSpielFeld[ixKoordinate + iSpieler][iyKoordinate - iSpieler] == cSpielsteine[1] &&
	  cSpielFeld[ixZiel][iyZiel] == SCHWARZ))
	{
		return OK;
	}
	ZeichneFeld(8, 8);
	color(1);
	printf("\nFehler: Geben Sie ein korrektes Ziel ein\n");
	color(0);
	return NOTOK;
}
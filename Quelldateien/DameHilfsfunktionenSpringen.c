/*
   ============================================================================
   Programmname: DameHilfsfunktionenSpringen.c
   Autor       : Andreas Danek, Daniel Jan�en
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Funktionen
   ============================================================================
*/

/*
============================================================================
Pr�prozessoranweisungen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion DameSchlageStein()

   @aufruf: DameSpringen()
   @beschreibung: f�hrt das Schlagen des Steines durch (f�r einen Stein und 
				  eine Dame)
   @param ixZiel: gew�hlte x-Zielkoordinate
   @param iyZiel: gew�hlte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der Stein wurde bewegt und der Gegner geschlagen
   ========================================================================
*/
int DameSchlageStein(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate)
{
	int iSchon_Getauscht = 0;
	
	/*
	 * DameTausch pr�ft nur in der normalen Zugrichtung, aber da eine Dame 
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
   @beschreibung: f�hrt das Schlagen des Steines durch (f�r einen Stein und 
				  eine Dame nach vorne)
   @param ixZiel: gew�hlte x-Zielkoordinate
   @param iyZiel: gew�hlte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der Stein wurde bewegt und der Gegner geschlagen
   @return NOTOK: das Schlagen konnte nicht durchgef�hrt werden
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
   @beschreibung: �berpr�ft ob der gew�hlte Stein erbeuten kann
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der gew�hlte Stein kann erbeuten
   @return NOTOK: der gew�hlte Stein kann nicht erbeuten
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
   @beschreibung: �berpr�ft die gew�hlten Zielkoordinaten auf Richtigkeit 
				  (Diagonal nach vorne ein fremder Stein/Dame sthehend und 
				  das Feld dahinter leer)
   @param ixZiel: gew�hlte x-Zielkoordinate
   @param iyZiel: gew�hlte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der gew�nschte Sprung kann durchgef�hrt werden
   @return NOTOK: der gew�nschte Sprung kann nicht durchgef�hrt werden
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
   @beschreibung: �berpr�ft die gew�hlten Zielkoordinaten auf Richtigkeit 
				  (Diagonal ein fremder Stein/Dame sthehend und das Feld 
				  dahinter leer)
   @param ixZiel: gew�hlte x-Zielkoordinate
   @param iyZiel: gew�hlte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der gew�nschte Sprung kann durchgef�hrt werden
   @return NOTOK: der gew�nschte Sprung kann nicht durchgef�hrt werden
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
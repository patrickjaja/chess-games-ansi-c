/*
   ============================================================================
   Programmname: DameHilfsfunktionenSteinSetzen.c
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
   Funktion DameAusgewaehlterSteinVorhanden()

   @aufruf: DameSteinSetzen()
   @beschreibung: �berpr�ft, ob es den ausgew�hlten Stein auf dem Spielfeld 
				  gibt
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der gew�hlte Stein ist vorhanden
   @return NOTOK: der gew�hlte Stein ist nicht vorhanden
   ========================================================================
*/
int DameAusgewaehlterSteinVorhanden(int ixKoordinate,int iyKoordinate)
{
	if ((cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[0]) ||
	 (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[2]))
	{
		return OK;
	}
	ZeichneFeld(8, 8);
	color(1);
	printf("\nFehler: W\204hlen Sie einen vorhandenen Stein aus\n");
	color(0);
	return NOTOK;
}


/*
   ========================================================================
   Funktion DameBewegeStein()

   @aufruf: DameSteinSetzen()
   @beschreibung: bewege stein von koordinaten nach ziel
   @param ixZiel: gew�hlte x-Zielkoordinate
   @param iyZiel: gew�hlte y-Zielkoordinate
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return OK: der Stein wurde bewegt
   ========================================================================
*/
int DameBewegeStein(int ixKoordinate,int iyKoordinate,int ixZiel,int iyZiel)
{
	if (iyZiel > 0 && iyZiel < 7)
	{
		cSpielFeld[ixZiel][iyZiel] = cSpielFeld[ixKoordinate][iyKoordinate];
	}
	else
	{
		cSpielFeld[ixZiel][iyZiel] = cSpielsteine[2];
	}
	cSpielFeld[ixKoordinate][iyKoordinate] = SCHWARZ;
	
	return OK;
}
/*
   ========================================================================
   Funktion DameKannSteinBewegtWerden(int ixKoordinate,int iyKoordinate, 
								  int iRueckgabe)
   @aufruf: DameSteinSetzen()
   @beschreibung: �berpr�ft ob der ausgew�hlte Stein �berhaupt bewegt 
				  werden kann
   @param ixKoordinate: Die x-Koordinate des gew�hlten Steines
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @param iRueckgabe: Rueckgabewert, welcher ver�ndert wird
   @return iRueckgabe: gibt an ob der Stein bewegt werden kann (0) oder
					   nicht (1)
   ========================================================================
*/

int DameKannSteinBewegtWerden(int ixKoordinate,int iyKoordinate, int iRueckgabe)
	{
			if (ixKoordinate == 0)
			{
				iRueckgabe = ZielfeldLeer(ixKoordinate+1,iyKoordinate+iSpieler);
				if (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[2])
				{
					iRueckgabe *= ZielfeldLeer(ixKoordinate+1,iyKoordinate-iSpieler); 
				}
				return iRueckgabe;
			}
			if (ixKoordinate == 7)
			{
				iRueckgabe = ZielfeldLeer(ixKoordinate-1,iyKoordinate+iSpieler);
				if (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[2])
				{
					iRueckgabe *= ZielfeldLeer(ixKoordinate-1,iyKoordinate-iSpieler); 
				}
				return iRueckgabe;
			}
			if (7 > ixKoordinate > 0)
			{
				iRueckgabe = ZielfeldLeer(ixKoordinate+1,iyKoordinate+iSpieler);
				iRueckgabe *= ZielfeldLeer(ixKoordinate-1,iyKoordinate+iSpieler);  
				if (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[2])
				{
					iRueckgabe *= ZielfeldLeer(ixKoordinate+1,iyKoordinate-iSpieler);
					iRueckgabe *= ZielfeldLeer(ixKoordinate-1,iyKoordinate-iSpieler);
				}
				return iRueckgabe;
			}
			ZeichneFeld(8, 8);
			color(1);
			printf("\nFehler: W\204hlen Sie einen bewegbaren Stein aus\n");
			color(0);
			return NOTOK;
	}

/*
   ========================================================================
   int DameBelegeIyzielStein(int iyKoordinate)
   @aufruf: DameSteinSetzen()
   @beschreibung: Belegt die iyZiel Koordinate f�r einen Stein
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return iyZiel: y-Zielkoordinate, nach wo gesetzt werden soll
   ========================================================================
*/
int DameBelegeZielStein(int *ixZielReturn, int *iyZielReturn, int ixKoordinate, int iyKoordinate)
{
	int ixZiel, iyZiel;
	ZeichneFeld(8,8);
	do
	{
		printf("\nWohin soll der Stein bewegt werden?\n");
		PositionEingeben(&ixZiel, &iyZiel, 8, 8, 0);
		if ((iyZiel != iyKoordinate+iSpieler) || ((ixZiel != ixKoordinate+1) && (ixZiel != ixKoordinate-1)))
		{
			ZeichneFeld(8,8);
			printf("\nW\204hlen Sie eine korrekte Zielposition aus\n");
		}
	}while (((ixZiel != ixKoordinate+1) && (ixZiel != ixKoordinate-1)) || (iyZiel != iyKoordinate+iSpieler));

	*ixZielReturn = ixZiel;
	*iyZielReturn = iyZiel;
	return OK;
}
/*
   ========================================================================
   int DameBelegeIyzielDame(int iyKoordinate)
   @aufruf: DameSteinSetzen()
   @beschreibung: Belegt die iyZiel Koordinate f�r eine Dame
   @param iyKoordinate: Die y-Koordinate des gew�hlten Steines
   @return iyZiel: y-Zielkoordinate, nach wo gesetzt werden soll
   ========================================================================
*/
int DameBelegeZielDame(int *ixZielReturn, int *iyZielReturn, int ixKoordinate, int iyKoordinate)
{
	int ixZiel, iyZiel;
	ZeichneFeld(8,8);
	do
	{
		PositionEingeben(&ixZiel, &iyZiel, 8, 8, 0);
		if (((iyZiel != iyKoordinate+iSpieler) && (iyZiel != iyKoordinate-iSpieler)) ||
		 ((ixZiel != ixKoordinate+1) && (ixZiel != ixKoordinate-1)))
		{
			ZeichneFeld(8,8);
			printf("\nW\204hlen Sie eine korrekte Zielposition aus\n");
		}
	}while (((ixZiel != ixKoordinate+1) && (ixZiel != ixKoordinate-1)) ||
	 ((iyZiel != iyKoordinate+iSpieler) && (iyZiel != iyKoordinate-iSpieler)));
	
	*ixZielReturn = ixZiel;
	*iyZielReturn = iyZiel;
	return OK;
}
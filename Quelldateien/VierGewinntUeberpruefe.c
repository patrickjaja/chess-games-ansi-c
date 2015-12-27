/*
   ============================================================================
   Programmname: VierGewinntUeberpruefe.c
   Autor       : Milan Niezgodka, Pascal Neuhausen
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
   Funktion VierGewinntUeberpruefeVierInReihe()

   @aufruf: VierGewinntSteinSetzen()
   @beschreibung: Oberfunktion, welche Unterfunktionen aufruft, die �ber-
				  pr�fen ob ein Spieler gewonnen hat
   @param ixKoordinate: x-Koordinate des grade gesetzten Steines
   @param iyKoordinate: y-Koordinate des grade gesetzten Steines
   @return iSieg: Integer-Variable die Zur�ckgibt ob ein Spieler gewonnen
				  hat (>0) oder nicht (=0)
   ========================================================================
*/
int VierGewinntUeberpruefeVierInReihe(int ixKoordinate, int iyKoordinate)
{
	int iSieg;

	iSieg = VierGewinntPruefeWaagerecht(ixKoordinate, iyKoordinate);
	iSieg += VierGewinntPruefeSenkrecht(ixKoordinate, iyKoordinate);
	iSieg += VierGewinntPruefeDiagonalLinksUntenRechtsOben(ixKoordinate, iyKoordinate);
	iSieg += VierGewinntPruefeDiagonalLinksObenRechtsUnten(ixKoordinate, iyKoordinate);
	return iSieg;
}

/*
   ========================================================================
   Funktion VierGewinntPruefeWaagerecht()

   @aufruf: UeberpruefeVierInReihe()
   @beschreibung: �berpr�ft ob waagerecht eine Gewinnsituation vorliegt
   @param ixKoordinate: x-Koordinate des grade gesetzten Steines
   @param iyKoordinate: y-Koordinate des grade gesetzten Steines
   @return ENDE: Gewinnbedingung erf�llt
   @return OK: Gewinnbedingung nicht erf�llt
   ========================================================================
*/
int VierGewinntPruefeWaagerecht(int ixKoordinate, int iyKoordinate)
{
	int x = 1;
	int iZaehler = 0;

	while ((cSpielFeld[ixKoordinate-x][iyKoordinate] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	x = 1;
	while ((cSpielFeld[ixKoordinate+x][iyKoordinate] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	if (iZaehler >= 3)
	{
		return ENDE;
	}
	return OK;
}

/*
   ========================================================================
   Funktion VierGewinntPruefeSenkrecht()

   @aufruf: UeberpruefeVierInReihe()
   @beschreibung: �berpr�ft ob senkrecht eine Gewinnsituation vorliegt
   @param ixKoordinate: x-Koordinate des grade gesetzten Steines
   @param iyKoordinate: y-Koordinate des grade gesetzten Steines
   @return ENDE: Gewinnbedingung erf�llt
   @return OK: Gewinnbedingung nicht erf�llt
   ========================================================================
*/
int VierGewinntPruefeSenkrecht(int ixKoordinate, int iyKoordinate)
{
	int x = 1;
	int iZaehler = 0;

	while ((cSpielFeld[ixKoordinate][iyKoordinate-x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	x = 1;
	while ((cSpielFeld[ixKoordinate][iyKoordinate+x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	if (iZaehler >= 3)
	{
		return ENDE;
	}
	return OK;
}

/*
   ========================================================================
   Funktion VierGewinntPruefeDiagonalLinksUntenRechtsOben()

   @aufruf: UeberpruefeVierInReihe()
   @beschreibung: �berpr�ft ob diagonal eine Gewinnsituation vorliegt
   @param ixKoordinate: x-Koordinate des grade gesetzten Steines
   @param iyKoordinate: y-Koordinate des grade gesetzten Steines
   @return ENDE: Gewinnbedingung erf�llt
   @return OK: Gewinnbedingung nicht erf�llt 
   ========================================================================
*/
int VierGewinntPruefeDiagonalLinksUntenRechtsOben(int ixKoordinate, int iyKoordinate)
{
	int x = 1;
	int iZaehler = 0;

	while ((cSpielFeld[ixKoordinate-x][iyKoordinate+x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	x = 1;
	while ((cSpielFeld[ixKoordinate+x][iyKoordinate-x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	if (iZaehler >= 3)
	{
		return ENDE;
	}
	return OK;
}

/*
   ========================================================================
   Funktion VierGewinntPruefeDiagonalLinksObenRechtsUnten()

   @aufruf: VierGewinntUeberpruefeVierInReihe()
   @beschreibung: �berpr�ft ob in der anderne Diagonalen eine 
				  Gewinnsituation vorliegt
   @param ixKoordinate: x-Koordinate des grade gesetzten Steines
   @param iyKoordinate: y-Koordinate des grade gesetzten Steines
   @return ENDE: Gewinnbedingung erf�llt
   @return OK: Gewinnbedingung nicht erf�llt 
   ========================================================================
*/
int VierGewinntPruefeDiagonalLinksObenRechtsUnten(int ixKoordinate, int iyKoordinate)
{
	int x = 1;
	int iZaehler = 0;

	while ((cSpielFeld[ixKoordinate-x][iyKoordinate-x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	x = 1;
	while ((cSpielFeld[ixKoordinate+x][iyKoordinate+x] == cSpielsteine[0])
		&& (iZaehler != 3))
	{
		x++;
		iZaehler++;
	}
	if (iZaehler >= 3)
	{
		return ENDE;
	}
	return OK;
}

/*
   ========================================================================
   Funktion VierGewinntUeberpruefeSpielfeldVoll()

   @aufruf: VierGewinntSteinSetzen()
   @beschreibung: �berpr�ft ob es auf dem Spielfeld noch mindestens einen
				  freien Platz zum legen gibt
   @return OK: es gibt noch mindestens einen freien Platz
   @return UNENTSCHIEDEN: Das gesamte Spielfeld ist voll und dadurch gibt
						  es keinen Sieger
   ========================================================================
*/
int VierGewinntUeberpruefeSpielfeldVoll()
{
	int iHoehe;
	int iBreite;

 for (iHoehe = 0; iHoehe < 8; iHoehe++)
 {
	for (iBreite = 0; iBreite < 7; iBreite++)
	{
		if ((cSpielFeld[iBreite][iHoehe] == SCHWARZ)
		 || (cSpielFeld[iBreite][iHoehe] == WEISS))
		{
			return OK;
		}
	}
 }
 return UNENTSCHIEDEN;
}
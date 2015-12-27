/*
   ============================================================================
   Programmname: ReversiSpielen.c
   Autor       : Jakob Bohr, Gilles Meyer, Andreas Danek, Daniel Janﬂen
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Funktionen
   ============================================================================
*/

/*
============================================================================
Pr‰prozessoranweisungen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion ReversiSpielen()

   @aufruf: main(), ReversiSpielen()
   @beschreibung: steuert das spiel
   @param iKeinzugmoeglich: Integer-Variable, die angibt ob das der erste
							Aufruf diese Funktion ist (bei Aufruf aus main())
							oder ob es sich um einen Rekursionsaufruf handelt
   @return iRueckgabe: Integer-Variable, welche angibt ob das Spiel zu Ende
					   ist (1 oder 2) oder nicht (0)
   ========================================================================
*/
int ReversiSpielen(int iKeinzugmoeglich)
{
	int iEnde = 0;
	int iRueckgabe = 0;

	/*
	 * ‹berpr¸fung ob der aktuelle Spieler noch einen Zug machen kann
	 * ansonsten ob der nicht aktuelle Spieler noch einen Zug machen
	 * kann
	 */
	iRueckgabe = ReversiUeberpruefeZugMoeglich();
	if (iRueckgabe == 1)
	{
		printf("\nKein Zug mˆglich. N‰chster Spieler am Zug");
		iKeinzugmoeglich += 1;
		if (iKeinzugmoeglich > 1)
		{
			printf("\nKein Spieler kann mehr ziehen!!");
			return ENDE;
		}
		iSpieler *= 1;
		ReversiSpielen(1);
	}
	/*
	 * Der else-Fall behandelt erst den eigentlichen Spielzug
	 */
	else
	{
		iRueckgabe = ReversiPruefeObSteinGesetztWerdenKann();
	}
	return iRueckgabe;
}

/*
   ========================================================================
   Funktion ReversiZaehleSteine()

   @aufruf: main()
   @beschreibung: z‰hlt die Anzahl der Spielsteine in der jeweiligen Farbe
				  (schwarz/weiﬂ)
   @return 1: Spieler 1 hat mehr Steine und somit gewonnen
   @return -1: Spieler -1 hat mehr Steine und somit gewonnen
   @return 2: Beide Spieler haben gleichviele Steine und es gibt ein 
			  Unentschieden
   ========================================================================
*/
int ReversiZaehleSteine()
{
	int iBreite;
	int iHoehe;
	int iPunkte1 = 0;
	int iPunkte2 = 0;

	/*
	 * Z‰hlen der Spielsteine
	 */
	for (iBreite = 0; iBreite < 8; iBreite++)
	{
		for (iHoehe = 0; iHoehe < 8; iHoehe++)
		{
			if (cSpielFeld[iBreite][iHoehe] == BLAU)
			{
				iPunkte1 += 1;
			}
			if (cSpielFeld[iBreite][iHoehe] == ROT)
			{
				iPunkte2 += 1;
			}
		}
	}

	/*
	 * Spieler 1 hat gewonnen
	 */
	if (iPunkte1 > iPunkte2)
	{
		return 1;	
	}

	/*
	 * Spieler -1 hat gewonnen
	 */
	if (iPunkte1 < iPunkte2)
	{
		return -1;
	}

	/*
	 * Sonst gibt es ein Unentschieden
	 */
	return 2;
}

/*
   ========================================================================
   Funktion ReversiSteinSetzen()

   @aufruf:  ReversiPruefeObSteinGesetztWerdenKann()
   @beschreibung: setzt einen eigenen Stein auf die entsprechende Stelle
   @param ixKoordinate: Die x-Koordinate des zu ¸berpr¸fenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu ¸berpr¸fenden Spielsteines
   @return OK: der Stein wurde erfolgreich gesetzt 
   ========================================================================
*/
int ReversiSteinSetzen(int ixKoordinate, int iyKoordinate)
{
	cSpielFeld[ixKoordinate][iyKoordinate] = cSpielsteine[0];
	return OK;
}

/*
   ========================================================================
   Funktion SteineDrehen()

   @aufruf: ReversiPruefeObSteinGesetztWerdenKann()
   @beschreibung: dreht Steine nach dem setzen um
   @param ixKoordinate: Die x-Koordinate des zu ¸berpr¸fenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu ¸berpr¸fenden Spielsteines
   @return OK: Die Drehung(en) war(en) erfolgreich
   ========================================================================
*/
int ReversiSteineDrehen(int ixKoordinate, int iyKoordinate)
{
	int iRueckgabe = 1;
	
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachLinks(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachLinks(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachRechts(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachRechts(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachOben(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachOben(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachUnten(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachUnten(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben(ixKoordinate, iyKoordinate, 1);
	}
	iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten(ixKoordinate, iyKoordinate, 0);
	if (iRueckgabe == 0)
	{
		ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten(ixKoordinate, iyKoordinate, 1);
	}
	return OK;
}
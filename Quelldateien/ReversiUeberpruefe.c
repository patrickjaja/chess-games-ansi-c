/*
   ============================================================================
   Programmname: ReversiUeberpruefe.c
   Autor       : Jakob Bohr, Gilles Meyer, Andreas Danek, Daniel Janßen
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
   Funktion ReversiUeberpruefeSpielfeldVoll()

   @aufruf: ReversiPruefeObSteinGesetztWerdenKann()
   @beschreibung: Überprüft ob es auf dem Spielfeld noch mindestens einen
				  freien Platz zum legen gibt
   @return OK: es gibt noch mindestens einen freien Platz
   @return ENDE: Das gesamte Spielfeld ist voll
   ========================================================================
*/
int ReversiUeberpruefeSpielfeldVoll()
{
	int iHoehe;
	int iBreite;

 for (iHoehe = 0; iHoehe < 8; iHoehe++)
 {
	for (iBreite = 0; iBreite < 8; iBreite++)
	{
		if ((cSpielFeld[iBreite][iHoehe] == SCHWARZ)
		 || (cSpielFeld[iBreite][iHoehe] == WEISS))
		{
			return OK;
		}
	}
 }
 return ENDE;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeZugMoeglich()

   @aufruf: ReversiSpielen()
   @beschreibung: Überprüft ob noch ein Zug moeglich ist
   @return OK: ein Zug ist möglich
   @return NOTOK: kein Zug ist möglich
   ========================================================================
*/
int ReversiUeberpruefeZugMoeglich()
{
	int iHoehe;
	int iBreite;
	int iRueckgabe = 1;

	for (iHoehe = 0; iHoehe < 8; iHoehe++)
	{
		for (iBreite = 0; iBreite < 8; iBreite++)
		{
			iRueckgabe = ZielfeldLeer(iBreite,iHoehe);
			if (iRueckgabe == 0)
			{
				iRueckgabe = ReversiUeberpruefeGueltigeStelle(iBreite,iHoehe);
				if (iRueckgabe == 0)
				{
					return OK;
				}
			}
		}
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiPruefeObSteinGesetztWerdenKann()

   @aufruf: ReversiSpielen()
   @beschreibung: Liest die gewünschten Koordinaten zum setzen ein, 
				  und ruft Funktionen zum setzen und Drehen auf
   @return ENDE: Spieler hat aufgegeben, Spiel ist zu Ende
   @return iRueckgabe: Integer-Variable die anzeigt ob das Spielfeld voll ist
   ========================================================================
*/
int ReversiPruefeObSteinGesetztWerdenKann()
{
	int ixKoordinate;
	int iyKoordinate;
	int iRueckgabe = 0;
	int iKoordinatenRichtig=0;

	do{

		if(PositionEingeben(&ixKoordinate, &iyKoordinate, 8, 8, 0) == NOTOK)
		{
			return AUFGABE;
		}

		/*
		 * Überprüfungen ob der Stein dahin gesetzt werden kann
		 */
		iKoordinatenRichtig = ZielfeldLeer(ixKoordinate, iyKoordinate);
		iKoordinatenRichtig += ReversiUeberpruefeGueltigeStelle(ixKoordinate, iyKoordinate);
		if(iKoordinatenRichtig > 0)
		{
			ZeichneFeld(8, 8);
			color(1);
			printf("\nFehler: Waehlen Sie ein gueltiges Zielfeld\n");
			color(0);
		}
	}while (iKoordinatenRichtig > 0);

	/*
	* Setzen des Steines und Drehen der fremden
	*/
	ReversiSteinSetzen(ixKoordinate, iyKoordinate);
	ReversiSteineDrehen(ixKoordinate, iyKoordinate);

	iRueckgabe = ReversiUeberpruefeSpielfeldVoll();
	return iRueckgabe;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeGueltigeStelle(int ixKoordinate, int iyKoordinate)

   @aufruf: ReversiPruefeObSteinGesetztWerdenKann()
   @beschreibung: Diese Funktion überprüft ob der Stein dorthin gesetzt
				  werden kann, indem sie überprüft, ob Steine umgedreht 
				  werden können
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @return iRueckgabe: zeigt an ob es mindestens eine gültige Stelle gibt
					   (bei 0). Ansonsten wird 1 zurückgegeben
   ========================================================================
*/
int ReversiUeberpruefeGueltigeStelle(int ixKoordinate, int iyKoordinate)
{
	int iRueckgabe = 1;

	if (cSpielFeld[ixKoordinate-1][iyKoordinate] == cSpielsteine[1])
	{
		iRueckgabe = ReversiUeberpruefeReiheAufEigenenSteinNachLinks(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate+1][iyKoordinate] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachRechts(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate][iyKoordinate-1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachOben(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate][iyKoordinate+1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachUnten(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate-1][iyKoordinate-1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate-1][iyKoordinate+1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate+1][iyKoordinate-1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben(ixKoordinate, iyKoordinate, 0);
	}
	if (cSpielFeld[ixKoordinate+1][iyKoordinate+1] == cSpielsteine[1])
	{
		iRueckgabe *= ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten(ixKoordinate, iyKoordinate, 0);
	}
	return iRueckgabe;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachLinks()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach links möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachLinks(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate-x][iyKoordinate] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate-x][iyKoordinate] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate-x][iyKoordinate] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachRechts()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach rechts möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachRechts(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate+x][iyKoordinate] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate+x][iyKoordinate] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate+x][iyKoordinate] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachOben()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach oben möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachOben(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate][iyKoordinate-x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate][iyKoordinate-x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate][iyKoordinate-x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachUnten()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach unten möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate][iyKoordinate+x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate][iyKoordinate+x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate][iyKoordinate+x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach links oben möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate-x][iyKoordinate-x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate-x][iyKoordinate-x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate-x][iyKoordinate-x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach links unten möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate-x][iyKoordinate+x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate-x][iyKoordinate+x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate-x][iyKoordinate+x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach rechts oben möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate+x][iyKoordinate-x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate+x][iyKoordinate-x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate+x][iyKoordinate-x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}

/*
   ========================================================================
   Funktion ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten()

   @aufruf: ReversiUeberpruefeGueltigeStelle(),ReversiSteineDrehen()
   @beschreibung: überprüft ob ein Drehen nach rechts unten möglich ist und dreht
				  die entsprechenden Steine um
   @param ixKoordinate: Die x-Koordinate des zu überprüfenden Spielsteines
   @param iyKoordinate: Die y-Koordinate des zu überprüfenden Spielsteines
   @param iDrehe_um: gibt an ob nur überprüft wird (0) oder ob auch ggf. 
					 umgedreht werden soll (1)
   @return OK: es kann gedreht werden
   @return NOTOK: es kann nicht gedreht werden
   ========================================================================
*/
int ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um)
{
	int x = 1;

	while (cSpielFeld[ixKoordinate+x][iyKoordinate+x] == cSpielsteine[1])
		{
			if (iDrehe_um == 1)
			{
				cSpielFeld[ixKoordinate+x][iyKoordinate+x] = cSpielsteine[0];
			}
			x++;
		}
		if (cSpielFeld[ixKoordinate+x][iyKoordinate+x] == cSpielsteine[0])
		{
			return OK;
		}
	return NOTOK;
}
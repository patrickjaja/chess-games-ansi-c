/*
   ============================================================================
   Programmname: SpieleAllgemeines.c
   Autor       : David Frerich, Andreas Danek, Daniel Janßen
   Datum       : 17.03.2009
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
   Funktion Spieler()

   @beschreibung: belegt das Array mit den ASCII-Zeichen in folgender
				  Reihenfolge: eigener Stein, fremder Stein, 
				  eigener Stein 2, fremder Stein 2
   ========================================================================
*/
int Spieler()
{
	if (iSpieler == 1)
	{
		cSpielsteine[0] = BLAU;
		cSpielsteine[1] = ROT;
		cSpielsteine[2] = HBLAU;
		cSpielsteine[3] = PINK;
	}
	else
	{
		cSpielsteine[0] = ROT;
		cSpielsteine[1] = BLAU;
		cSpielsteine[2] = PINK;
		cSpielsteine[3] = HBLAU;
	}
	return OK;
}

/*
   ========================================================================
   Funktion ZielfeldLeer()

   @beschreibung: überprüft, ob das gewünschte Feld zum Steine legen
				  leer ist
   @param ixZiel: x-Koordinate des gewünschten Zielfeldes
   @param iyZiel: y-Koordinate des gewünschten Zielfeldes
   @return OK: Zielfeld ist leer
   @return NOTOK: Zielfeld ist schon besetzt
   ========================================================================
*/
int ZielfeldLeer(int iXZiel,int iYZiel)
{
	if (cSpielFeld[iXZiel][iYZiel] == SCHWARZ || cSpielFeld[iXZiel][iYZiel] == WEISS)
	{
		return OK;
	}
	return NOTOK;
}


/*
   ========================================================================
   Funktion PositionEingeben

   @beschreibung: liest die position ein und gibt die Koordinaten zurück
   @param iXKoordinate: x-Koordinate des gewünschten Zielfeldes
   @param iYKoordinate: y-Koordinate des gewünschten Zielfeldes
   @param iBreite: Breite des Feldes
   @param iHoehe: Hoehe des Feldes
   @param iNurSteine: 0 = Felder, 1 = Steine
   @return OK: Eingabe
   @return NOTOK: Beenden
   ========================================================================
*/
int PositionEingeben(int *iXKoordReturn, int *iYKoordReturn, int iBreite, int iHoehe, int iNurSteine)
{
	char cPosition[5];
	int iXKoordinate = -1, iYKoordinate = -1;
	int iRueckgabe = 0;
	int iSpielerIDAmZug;

	/* Solange das Feld / der Spielstein gültig ist */
	do{
		printf("\n");
		/* Aktiver Spieler spielt mit blauen Steinen */
		if(cSpielsteine[0] == BLAU)
		{
			color(12);
		}
		/* Aktiver Spieler spielt mit roten Steinen */
		else
		{
			color(9);
		}
		if(iSpieler == -1)
		{
			iSpielerIDAmZug = iSpielerID2;
		}
		else
		{
			iSpielerIDAmZug = iSpielerID;
		}
		printf("%s am Zug", cArrayUser[iSpielerIDAmZug][2]);
		color(0);

		printf("\n");
		
		/* Solange bis gültige Koordinaten eingegeben wurden oder 0 (fürs Beenden) */
		do{
			color(1);
			/*Aufgabe entfernt, statt dessen Abbruch! //printf("\n(Aufgabe mit 0)");*/
			printf("\n(Abbruch des Spiels mit 0)");
			color(0);

			printf("\nGeben Sie eine Position (Buchstabe+Zahl) ein: ");
			fflush(stdin);

			/* String einlesen, max 3 Zeichen + Stringende */
			scanf("%s", &cPosition);

			/* Erstes Zeichen ist ein Kleinbuchstabe */
			if(cPosition[0] >= 65 && cPosition[0] <= 90)
			{
				iXKoordinate = cPosition[0] - 65;
			}
			/* Erstes Zeichen ist ein Großbuchstabe */
			else if(cPosition[0] >= 97 && cPosition[0] <= 122)
			{
				iXKoordinate = cPosition[0] - 97;
			}
			/* Zweites Zeichen ist eine Zahl */
			if(cPosition[1] >= 48 && cPosition[1] <= 57)
			{
				iYKoordinate = cPosition[1] - 49;
			}
			/* Drittes Zeichen ist eine Zahl */
			if(cPosition[2] >= 48 && cPosition[2] <= 57)
			{
				iYKoordinate = ((iYKoordinate + 1) * 10) + (cPosition[2] - 48)-1;
			}
			/* Viertes Zeichen ist eine Zahl */
			if(cPosition[3] >= 48 && cPosition[3] <= 57)
			{
				iYKoordinate = ((iYKoordinate + 1) * 10) + (cPosition[3] - 48)-1;
			}
			/* Die Koordinaten sind ungültig oder 0 für Abbruch */
			if(cPosition[0] != '0' && ((0 > iXKoordinate || iXKoordinate > iBreite) 
				|| (0 > iYKoordinate || iYKoordinate > iHoehe)))
			{
				ZeichneFeld(iBreite, iHoehe);
				color(1);
				printf("\nFehler: Geben Sie eine g\201ltige Position ein\n");
						if(cSpielsteine[0] == BLAU)
						{
							color(12);
						}
						/* Aktiver Spieler spielt mit roten Steinen */
						else
						{
							color(9);
						}
						if(iSpieler == -1)
						{
							iSpielerIDAmZug = iSpielerID2;
						}
						else
						{
							iSpielerIDAmZug = iSpielerID;
						}
						printf("\n%s am Zug\n", cArrayUser[iSpielerIDAmZug][2]);
						color(0);
				color(0);
			}
		}while (cPosition[0] != '0' && ((0 > iXKoordinate || iXKoordinate > iBreite) 
			|| (0 > iYKoordinate || iYKoordinate > iHoehe)));

		/* Kein Abbruch */
		if(cPosition[0] != '0')
		{
			/* Überprüfung ob es sich um ein Leeres Feld handelt (Schwarz oder Weiß) */
			iRueckgabe = ZielfeldLeer(iXKoordinate, iYKoordinate);

			/* Fehler: Typ ist Felder und Feld ist nicht leer */
			if(iRueckgabe == NOTOK && iNurSteine == 0)
			{
				ZeichneFeld(iBreite, iHoehe);
				color(1);
				printf("\nFehler: W\204hlen Sie ein freies Feld\n");
				color(0);
			}
			/* Fehler: Typ ist Spielsteine und Feld ist leer */
			else if(iRueckgabe == OK && iNurSteine == 1)
			{
				ZeichneFeld(iBreite, iHoehe);
				color(1);
				printf("\nFehler: W\204hlen Sie einen Spielstein\n");
				color(0);
			}
		}
	}while (((iRueckgabe == NOTOK && iNurSteine == 0) 
		|| (iRueckgabe == OK && iNurSteine == 1)) && cPosition[0] != '0');

	/* Bei Abbruch: Schreiben von 0 in entsprechende Koordinaten Adresse */
	if(cPosition[0] == '0')
	{
		*iXKoordReturn = 0;
		*iYKoordReturn = 0;
		return NOTOK;
	}
	/* Bei gültigen Koordinaten, Schreiben dieser in entsprechende Adresse */
	else
	{
		*iXKoordReturn = iXKoordinate;
		*iYKoordReturn = iYKoordinate;
		return OK;
	}
}

/*
   ========================================================================
   Funktion SpielErgebnis

   @beschreibung: gibt das spielergebnis aus
   @param iErgebnis: 1 (entschieden) oder (unentschieden)
   @param iGewinner: -1, 1 oder 0 (Abbruch)
   @return OK: -1, 0 oder 1
   ========================================================================
*/
int SpielErgebnis(int iEnde, int iGewinner)
{
	int iSpielerIDGewinner;

	if(iGewinner == -1)
	{
		iSpielerIDGewinner = iSpielerID2;
	}
	else if(iGewinner == 1)
	{
		iSpielerIDGewinner = iSpielerID;
	}
	/* Bei Abbruch ist der Gewinner = 0 */
	else if(iGewinner == 0)
	{
		iEnde = 3;
	}
	else
	{
		/* Kein gültiger Gewinner => Unentschieden */
		iEnde = 2;
	}

	/* Entschiedenes Ende */
	if (iEnde == 1)
	{
		color(2);
		printf("\nHerzlichen Glueckwunsch %s. Sie haben gewonnen!!\n", cArrayUser[iSpielerIDGewinner][2]);
		color(0);
		system("pause");
		return iGewinner;
	}
	/* Abgebrochenes Spiel */
	else if(iEnde == 3)
	{
		color(1);
		printf("\nSpiel abgebrochen!!\n");
		color(0);
		system("pause");
		return 10;
	}
	else
	{
		color(3);
		printf("\nUnentschieden!!\n");
		color(0);
		system("pause");
		return 0;
	}
}
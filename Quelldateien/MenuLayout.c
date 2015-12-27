/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : MenuLayout.c
Datum : 17.03.09
Version : 1.0
Thema : Projektarbeit
Beschreibung: Erstellt einen Headerbereich und einen farbigen Balken um
              Content und User Eingaben deutlich zu trennen.
Programmschnittstelle: Funktionen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion InfoKopfzeile(char cLoginName1[L_NAME], char cLoginName2[L_NAME], 
						  char cPunkte1[L_PUNKT], char cPunkte2[L_PUNKT])
   @Aufruf: InfoKopfzeile()
   @Beschreibung: Parameter1 > S_NAME macht eine Ausgabe, 
				   Parameter2 > S_NAME macht zweite Ausgabe
   @Hinweis: Der Parameter Punkte war schon eine Erweiterung die wir eventuell 
			 noch einbauen wollen
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
void InfoKopfzeile(char cLoginName1[L_NAME], char cLoginName2[L_NAME], char cPunkte1[L_PUNKT], char cPunkte2[L_PUNKT])
{
		char akt_datum[30];
		int anz_Namen = 0;
		int iLNAME1 = 0;
		int iLNAME2 = 0;
		time_t sec;
		time(&sec);
		strcpy (akt_datum, ctime(&sec));
		akt_datum[24] = '\0';
		color(0);
		printf ("Datum und Uhrzeit (GMT): %s", akt_datum);
		printf ("\nEine Produktion von \"HHBK Tendo Research Centers\" \n");
    	
		iLNAME1 = (int)strlen(cLoginName1);
		iLNAME2 = (int)strlen(cLoginName2);
		if (iLNAME1 > S_NAME)
		{
			anz_Namen = anz_Namen + 1;
		}

		if (iLNAME2 > S_NAME)
		{
			anz_Namen = anz_Namen + 1;
		}

		if (anz_Namen >= 2)
		{
			printf("1. Spieler: %s\n", cLoginName1);
			printf("2. Spieler: %s\n", cLoginName2);
		}
		else
		{
			if (anz_Namen >= 1)
			{
				printf("1. Spieler: %s\n", cLoginName1);
			}
			else
			{
				printf ("");
			}
		}
		color(16);
}

/*
   ========================================================================
   Funktion FarbigerBalken(int farbe)
   @Aufruf: FarbigerBalken(farbe)
   @Beschreibung: erstellt einen Balken um den Sicht- und 
				  Eingabebereich für den Anwender klar abzutrennen
   ========================================================================
*/
void FarbigerBalken (int farbe)
{
 color(farbe);
 printf ("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line, line);
 color(16);
}
/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : MenuDateiInOut.c
Datum : 17.03.09
Version : 1.0
Thema : Projektarbeit
Beschreibung: Funktionen zum Auslesen der Datei, füllen des Arrays
              und schreibt Informationen zurück
Programmschnittstelle: Funktionen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion LeseZerlegeDatei()
   @Aufruf: LeseZerlegeDatei()
   @Beschreibung: füllt das Array cArrayUser + muss vor SchreibeDatei aufgerufen werden
   @return EXIT_SUCCESS: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int LeseZerlegeDatei(void)
{
  FILE *datei;
  char cAktZeile[L_ZEILE];
  char cAusgeleseneZeile[L_ZEILE];
  int i = 0;
  int cTokennr = 0;
  int iZaehler = 0;
  cSeparator[0] = ';';
  datei = fopen(pfad, "r");
  /* Existiert die Datei? */
  if (datei != NULL)
    {
	   iNrLetzteZeile = 0;
	   /* Lese alle Zeilen */
	   while ( fgets ( cAktZeile, L_ZEILE, datei ))
	   {
		   strcpy(cArrayUser[iZaehler][0], cAktZeile);
		   iZaehler++;
		   iNrLetzteZeile++;
	   }
	    /* Zerlege solange wie Zeilen vorhanden */
        for (i=0; i< iZaehler; i++)
		{
			strcpy(cAusgeleseneZeile,cArrayUser[i][0]);
			/* Hole erstes Token und schreibe in cToken bis ; */
			cToken=strtok(cAusgeleseneZeile, ";");
			cTokennr = 0;
			while( cToken != NULL )
			{
			  strcpy(cArrayUser[i][cTokennr+1], cToken);
			  cTokennr++;
			  /* setze das Token ; auf NULL*/
			  cToken = strtok(NULL, ";");
			}
		}
    }
    else
    {
		color(1);
		printf("Datei nicht iGefunden.\nPfad: %s\n", pfad);
		color(0);
		return EXIT_FAILURE; 
	}
  fclose (datei);
  return EXIT_SUCCESS;
}

/*
   ========================================================================
   Funktion SchreibeDatei()
   @Aufruf: SchreibeDatei()
   @Beschreibung: Hängt in der Datei eine Zeile mit Login Infos an
   @return EXIT_SUCCESS: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int SchreibeDatei(void)
{
   FILE *datei;
   time_t datum;
   int iZaehler = 0;
   int iNeueID;
   char cAlteID[20];
   int iAnzahlLogins = 0;
   char cAktuellesDatum[30];
   time(&datum);
   strcpy(cAktuellesDatum, ctime(&datum));
   /* entfernt das /n am Ende des Datums */
   cAktuellesDatum[24] = '\0'; 
   strcpy(cSeparator, cSeparator);
   strcpy(cAlteID, cArrayUser[iNrLetzteZeile-1][1]);
   Verschluesseln(cLoginPasswort1,CRYPT_KEY);
   iNeueID = atoi(cAlteID) + 1;
   printf("\nRegistration abgeschlossen\n");
   printf("Hallo ");
   color(3);
   printf("%s", cLoginName1);
   color(16);
   printf(",\n");
   if (strlen(cLoginPasswort1) < P_SICHER)
   {
	   printf("Dein gew\204hltes Passwort wurde als");
	   color(3);
	   printf(" unsicher");
	   color(16);
	   printf(" eingestuft!");
   }
   if (strlen(cLoginPasswort1) > P_SICHER)
   {
	   printf("Dein gew\204hltes Passwort wurde als");
	   color(2);
	   printf(" sehr sicher");
	   color(16);
	   printf(" eingestuft!");
   }
   /* öffne Datei und füge Zeile hinzu */
   if (datei = fopen(pfad, "a+"))
   {
      fprintf(datei,"%i%s%s%s%s%s%s%s%i%s\n", iNeueID, ";", cLoginName1, ";", cLoginPasswort1, ";", cAktuellesDatum, ";", iAnzahlLogins, ";" );
   }
   else
   {
	  color(1);
      fprintf(stderr,"\nFehler beim Öffnen der Datei %s!\n",pfad);
	  color(16);
      return EXIT_FAILURE;
   }
   fclose (datei);
  return EXIT_SUCCESS;
}
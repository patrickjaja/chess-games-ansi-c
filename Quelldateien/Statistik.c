/*
   ========================================================================
   Autor       : Gilles Meyer, Jakob Bohr
   Firma       : Tendo Research Center
   Dateiname   : statistik.c
   Datum       : 18.03.2008
   Beschreibung: -
   Version     : 1.0
   ========================================================================
*/

/*
   ========================================================================
   Include Dateien
   ========================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion StatistikAendern()

   @aufruf: StatistikNewStats()
   @beschreibung: Statistik Des Spielers abändern.
   @param iSpieler:   1 = Spieler 1
                      2 = Spieler 2
   @param iSpiel:     1 = 4 Gewinnt
                      2 = Reversi
                      3 = Checkers
                      4 = Bridges
   @param iResultate: 1 = Siege
                      2 = Unentschieden
                      3 = Niederlagen
   ========================================================================
*/
int StatistikAendern(int iSpieler, int iSpiel, int iResultate)
{
    char cAendern[30];
    int iId = 0;
    int iRealId = 0;
    int iErgebnis;
    
    /* Abfrage für welchen Spieler die Werte abgeändert werden sollen */
    if (iSpieler == 1)
    {
        iId = iSpielerID;
    }
    else
    {
        iId = iSpielerID2;
    }
    
    /* Zeile in der Statistik.txt zuordnen */
    iRealId = (iId-1) *4;

    /* Spiele Abfrage (Zwischen 1-4) */
    if(iSpiel > 0 && iSpiel < 5)
    {
		iSpiel--;

        /* Abfrage ob Wert zwischen 1-3 liegt */
        if( iResultate > 0 && iResultate < 4)
        {
            /* Wert um 1 erhöhen */
            strcpy(cAendern, cStatistikTokens[iRealId+iSpiel][iResultate]);
            iErgebnis = atoi(cAendern) +1;
            itoa(iErgebnis,&cAendern,10);
            strcpy(cStatistikTokens[iRealId+iSpiel][iResultate],cAendern);
        }
        else
        {
            printf("Fehler");
        }
    }
    else
    {
        printf("Fehler");
    }
	return OK;
}

/*
   ========================================================================
   Funktion StatistikAuswahlMenu()

   @aufruf: Spielmenu()
   @beschreibung: Menu für Auswahl zwischen Eigener Statistik-Anzeige oder alle Statistiken anzeigen
   ========================================================================
*/
int StatistikAuswahlMenu(void)
{	
	int iEingabe = -1;
	
	while(iEingabe < 0 || iEingabe > 3)
	{
		system("cls");
		/* Kopfzeile */
		if (strcmp(cArrayUser[iSpielerID2][2],"NAME"))
		{
			
			InfoKopfzeile(cArrayUser[iSpielerID][2], cArrayUser[iSpielerID2][2], cArrayUser[iSpielerID][5], cArrayUser[iSpielerID2][5]);
		}
		else
		{
			InfoKopfzeile(cArrayUser[iSpielerID][2], "a", cArrayUser[iSpielerID2][5], "");
		}
		
		printf("Welche Statistik anzeigen?\n1.Alle Statistiken\n2.Statistik der angemeldeten Spieler\n0.Zurueck zum Hauptmenu\n");

		scanf("%i",&iEingabe);
	}

	switch(iEingabe)
	{

		case 1: system("cls");
				StatistikAlle();
				break;

		case 2: system("cls");
				StatistikSelbst();
				break;

		case 0: system("cls");
				break;
	}

	return OK;

}

/*
   ========================================================================
   Funktion StatistikNewStats()

   @aufruf: Spielmenu()
   @beschreibung: Setzt Gewinnen,Unentschieden bzw. 
                  Veloren um 1 hoch. Setzt außerdem den Elo-Wert und 
                  schreibt die Werte in die Statistik.txt
   @param iZahl:  Nummer des Spielers der gewonnen hat
                  (-1: Spieler2; 1:Spieler1; 0:Unentschieden; 10: Spielabbruch)
                   
   @param iSpiel: Nummer des gespielten Spiels: 
                  (1: Checkers; 2:Reversi; 3: 4 Gewinnt; 4: Bridges)
   ========================================================================
*/
int StatistikNewStats(int iZahl, int iSpiel)
{
	if(iZahl == -1)
	{
		/* Spieler 2 gewinnt und Spieler 1 verliert */
		StatistikAendern(1,iSpiel,3);
		StatistikAendern(2,iSpiel,1);
	}
	if(iZahl == 0)
	{
		/* Unentschieden */
		StatistikAendern(1,iSpiel,2);
		StatistikAendern(2,iSpiel,2);
	}
	if(iZahl == 1)
	{
		/* Spieler 1 gewinnt und Spieler 2 verliert */
		StatistikAendern(1,iSpiel,1);
		StatistikAendern(2,iSpiel,3);
	}
	if(iZahl != 10)
	{
		spielerBewertung(iSpiel,iZahl);
		StatistikSchreiben();
	}
	return OK;
}

/*
   ========================================================================
   Funktion StatistikAenderElo()

   @aufruf: spielerBewertung()
   @beschreibung: Ändert die Elo-Zahl für das gespielte Spiel für den gewünschten Spieler im Statistik Array
   @param iSpielerNr: Nummer des Spielers für den der Wert im Array geändert werden soll
                  (1: Spieler1; 2: Spieler2)
                   
   @param iSpielId: Nummer des Spiels (1: Checkers; 2:Reversi; 3: 4 Gewinnt; 4: Bridges)
                  
   @param dWert: Der neue Wert der Elo-Zahl
   ========================================================================
*/


int StatistikAenderElo(int iSpielerNr, int iSpielId, double dWert)
{
    int iRealId;

    if(iSpielerNr == 1)
    {
        iRealId = (iSpielerID-1) * 4;
    }
    else
    {
        iRealId = (iSpielerID2-1) * 4;
    }
    
    itoa(dWert,cStatistikTokens[iRealId+(iSpielId-1)][4],10);

	return OK;
}

/*
   ========================================================================
   Funktion StatistikLeseWert()

   @aufruf: spielerBewertung()
   @beschreibung: Liest einen Wert für die Statistik für einen User aus
                  
   @param iSpielerNr: Nummer des Spielers für den der Wert im Array geändert werden soll
                  (1: Spieler1; 2: Spieler2)
                   
   @param iSpielId: Nummer des Spiels (1: Checkers; 2:Reversi; 3: 4 Gewinnt; 4: Bridges)
                  
   @param dWert: Der Wert der ausgelesen werden soll (Siege, Niederlagen, Unentschieden & Elo-Zahl) 
   ========================================================================
*/


double StatistikLeseWert(int iSpielerNr, int iSpielId, int iWert)
{
    int iRealId;

    if(iSpielerNr == 1)
    {
        iRealId = (iSpielerID-1) * 4;
    }
    else
    {
        iRealId = (iSpielerID2-1) * 4;
    }
    
    return atof(cStatistikTokens[iRealId+(iSpielId-1)][iWert]);

}


/*
   ========================================================================
   Funktion StatistikAenderElo()

   @aufruf: RegistrierungPasswortEingabe()
   @beschreibung: Neuen Spieler hinzufügen
                  Es werden für alle 4 Spiele die Werte initialisiert
   ========================================================================
*/
int StatistikNeu(void)
{
    char cSeparator[2] = ";";
	FILE *datei;
    int iZaehler = 0;
    int i = 0;

    datei = fopen("Statistik.txt","a");

    if(datei != NULL)
    {
        for(i=0; i < 4; i++)
        {
            fprintf(datei,"0;0;0;0;\n");
        }

        fclose(datei);
    }

	return OK;
}


/*
   ========================================================================
   Funktion StatistikLaden()

   @aufruf: Spielmenu()
   @beschreibung: Die Statistik Datei wird ausgelesen und jede Zeile in ein Array geschrieben.
                  In dem 2. Array stehen die einzelnen Informationen.
                  Beispiel:
                  cStatistikTokens[1][1]    <-- entspricht Zeile 1: Siege
   ========================================================================
*/
int StatistikLaden(void)
{
    int cTokennr = 0;
    int iZaehler = 0;
    int i = 0;
    char *cToken;
    char cAktZeile[L_ZEILE];
    char cAusgeleseneZeile[L_ZEILE];
    char cSeparator[2] = ";";
	FILE *datei;
    int iTest = 0;

  /* Datei öffnen und Zeile für Zeile einlesen */
	datei = fopen("Statistik.txt", "r");

    if (datei != NULL)
    {
	   iStatistikLetzteZeile = 0;

       while ( fgets ( cAktZeile, L_ZEILE, datei ))
       {
	       strcpy(cStatistikTokens[iZaehler][0], cAktZeile);

           iZaehler++;

	       iStatistikLetzteZeile++;
	       
       }

      /* Zeile zerlegen und Werte in ein Array schreiben */
	   for (i=0; i< iZaehler; i++)
	   {
            strcpy(cAusgeleseneZeile,cStatistikTokens[i][0]);

		    cToken=strtok(cAusgeleseneZeile, cSeparator);

		    cTokennr = 0;

		    while( cToken != NULL )
	        {
		      strcpy(cStatistikTokens[i][cTokennr+1], cToken);

		      cTokennr++;

		      cToken = strtok(NULL, cSeparator);

		    }
	   }

       return 0;
    }
    else
    {
	 
	    printf("Datei nicht Gefunden.\nPfad: %s\n", "Statistik.txt");
	 
	    return 0; 
    }

    fclose (datei);

    return 0;
}


/*
   ========================================================================
   Funktion StatistikSchreiben()

   @aufruf: Spielmenu()
   @beschreibung: Das Statistik Array wird neu in die Datei geschrieben.
                  Hier bei wird die Datei neu geschrieben.
   ========================================================================
*/
int StatistikSchreiben(void)
{
    char cSeparator[2] = ";";
	FILE *datei;
    int iZaehler = 0;
    int i = 0;

    datei = fopen("Statistik.txt","w");

    if(datei != NULL)
    {
        for(i=0; i < iStatistikLetzteZeile; i++)
        {
            fprintf(datei,"%s;%s;%s;%s;\n",cStatistikTokens[i][1],
				cStatistikTokens[i][2],cStatistikTokens[i][3],cStatistikTokens[i][4]);
        }
    }

	return OK;
}


/*
   ========================================================================
   Funktion StatistikSelbst()

   @aufruf: StatistikAuswahlMenu()
   @beschreibung: Ausgabe der Statistik für die angemeldeten Spieler
   ========================================================================
*/
int StatistikSelbst(void)
{
    int iRealeId;
    int i;
    int iTest = 0;

    /* Spieler 1*/
    if(iSpielerID > 0)
    {
        iRealeId = iSpielerID - 1;

        if(iRealeId != 0)
        {
            iRealeId = iRealeId * 4;
        }
        

        printf("=========================================\n");
		printf("%s:\n========================================= \n",cArrayUser[iSpielerID][2]);

        for(i= 0; i < 4; i++)
        {  printf("----------------------------------------\n");
           switch(i)
           {

           case 0:
               printf("Checkers:");
               break;

           case 1:
               printf("Reversi:");
               break;

           case 2:
               printf("4 Gewinnt:");
               break;

           case 3:
               printf("Bridges:");
               break;

           }

            printf("\t |\t");
			color(2);
			printf("Siege: %s ",cStatistikTokens[iRealeId+i][1]);
			color(16);
			printf("\n\t\t |\t");
			color(3);
			printf("Unentschieden: %s ",cStatistikTokens[iRealeId+i][2]);
			color(16);
			printf("\n\t\t |\t");
			color(1);
			printf("Niederlagen: %s ",cStatistikTokens[iRealeId+i][3]);
			color(16);
			printf("\n\t\t |\t");
			color(6);
			printf("Elo-Zahl: %s\n",cStatistikTokens[iRealeId+i][4]);
			color(16);

              iTest++;

              if(iTest == 4) 
              {
				printf("=========================================\n");
                printf("\n");

                iTest = 0;
              }
              
        }
    }


    /* Spieler 2*/
    if(iSpielerID2 > 0)
    {
        printf("=========================================\n");
		printf("%s:\n========================================= \n",cArrayUser[iSpielerID2][2]);

        iRealeId = iSpielerID2 - 1;

        if(iRealeId != 0)
        {
            iRealeId = iRealeId * 4;
        }

        for(i= 0; i < 4; i++)
        {  printf("----------------------------------------\n");
           switch(i)
           {

           case 0:
               printf("Checkers:");
               break;

           case 1:
               printf("Reversi:");
               break;

           case 2:
               printf("4 Gewinnt:");
               break;

           case 3:
               printf("Bridges:");
               break;

           }
              
		    printf("\t |\t");
			color(2);
			printf("Siege: %s ",cStatistikTokens[iRealeId+i][1]);
			color(16);
			printf("\n\t\t |\t");
			color(3);
			printf("Unentschieden: %s ",cStatistikTokens[iRealeId+i][2]);
			color(16);
			printf("\n\t\t |\t");
			color(1);
			printf("Niederlagen: %s ",cStatistikTokens[iRealeId+i][3]);
			color(16);
			printf("\n\t\t |\t");
			color(6);
			printf("Elo-Zahl: %s\n",cStatistikTokens[iRealeId+i][4]);
			color(16);
		  
              iTest++;

              if(iTest == 4) 
              {
			    printf("=========================================\n");
                printf("\n");

                iTest = 0;
              }
        }
    }  
	return OK;
}

/*
   ========================================================================
   Funktion StatistikLoginPerson()

   @aufruf: StatistikAuswahlMenu()
   @beschreibung: Ausgabe der Statistik nach dem Login für den angemledeten Spieler
   ========================================================================
*/
int StatistikLoginPerson(int iRealId)
{
    int iRealeId;
    int i;
    int iTest = 0;

    
        iRealeId = iRealId - 1;

        if(iRealeId != 0)
        {
            iRealeId = iRealeId * 4;
        }
        
		printf("\n");
        printf("=========================================\n");
		printf("%s:\n========================================= \n",cArrayUser[iRealId][2]);

        for(i= 0; i < 4; i++)
        {  printf("----------------------------------------\n");
           switch(i)
           {

           case 0:
               printf("Checkers:");
               break;

           case 1:
               printf("Reversi:");
               break;

           case 2:
               printf("4 Gewinnt:");
               break;

           case 3:
               printf("Bridges:");
               break;

           }

            printf("\t |\t");
			color(2);
			printf("Siege: %s ",cStatistikTokens[iRealeId+i][1]);
			color(16);
			printf("\n\t\t |\t");
			color(3);
			printf("Unentschieden: %s ",cStatistikTokens[iRealeId+i][2]);
			color(16);
			printf("\n\t\t |\t");
			color(1);
			printf("Niederlagen: %s ",cStatistikTokens[iRealeId+i][3]);
			color(16);
			printf("\n\t\t |\t");
			color(6);
			printf("Elo-Zahl: %s\n",cStatistikTokens[iRealeId+i][4]);
			color(16);

              iTest++;

              if(iTest == 4) 
              {
				printf("=========================================\n");
                printf("\n");

                iTest = 0;
              }
              
        }
    getchar();
	return OK;
}


/*
   ========================================================================
   Funktion StatistikAlle()

   @aufruf: StatistikAuswahlMenu()
   @beschreibung: Ausgabe der Statistik für alle Spieler
   ========================================================================
*/
int StatistikAlle(void)
{
    int i;
    int iTest = 0;
    int iUserId = 1;
    
    printf("=========================================\n");
	printf("%s:\n========================================= \n",cArrayUser[iUserId][2]);


    for(i=0; i < iStatistikLetzteZeile; i++)
    {  
        
       if(iTest == 4)
       { 
		   iUserId++;
		   printf("=========================================\n");
                printf("\n");

           printf("=========================================\n");
		   printf("%s:\n========================================= \n",cArrayUser[iUserId][2]);

           iTest = 0;
       }
	   printf("----------------------------------------\n");

       iTest++;

       switch(iTest)
       {

       case 1:
           printf("4 Gewinnt:");
           break;

       case 2:
           printf("Reversi:");
           break;

       case 3:
           printf("Checkers:");
           break;

       case 4:
           printf("Bridges:");
           break;

       }

        printf("\t |\t");
		color(2);
		printf("Siege: %s ",cStatistikTokens[i][1]);
		color(16);
		printf("\n\t\t |\t");
		color(3);
		printf("Unentschieden: %s ",cStatistikTokens[i][2]);
		color(16);
		printf("\n\t\t |\t");
		color(1);
		printf("Niederlagen: %s ",cStatistikTokens[i][3]);
		color(16);
		printf("\n\t\t |\t");
		color(6);
		printf("Elo-Zahl: %s\n",cStatistikTokens[i][4]);
		color(16);
		  
       
    } 

	return OK;

}
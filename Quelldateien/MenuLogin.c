/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : MenuLogin.c
Datum : 17.03.09
Version : 1.0
Thema : Projektarbeit
Beschreibung: Vergleicht die Eingabe der Login Daten mit den Daten aus der
			  Datei
Programmschnittstelle: Funktionen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion LoginEingabeName1()
   @Aufruf: LoginEingabeName1()
   @Beschreibung: Eingabe im Login wird mit dem Inhalt der Textdatei 
				  verglichen. Dem entsprechend wird gehandelt.
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int LoginEingabeName1(void)
{
	char cLoginName[L_NAME] = "leer";
	int iRegistrieren = 0;
	int iGefunden = 0;
	/* Solange bis iGefunden 1 wird */
	while (iGefunden != 1)
	{
	LeseZerlegeDatei();
	system ("cls");
	printf ("LOGIN-Bereich\n");
	printf ("Bitte Namen eingeben");
	color(1);
	printf (" (0 zum Abbrechen): ");
	color(16);
	scanf("%s",&cLoginName);
	fflush(stdin);
	strcpy(cLoginName, cLoginName);
	/* Wenn der Login abgebrochen wird dann... */
	if (strcmp(cLoginName, "0") == 0)
	{
	 color(1);
	 printf ("\nLogin abgebrochen...\n\n");
	 color(16);
	 Sleep(1000);
	 return EXIT_FAILURE;
	}
	 /* Solange bis Spielername gefunden */
	 for (iSpielerID = 1;iSpielerID <= iNrLetzteZeile;iSpielerID++)
	 {
		if (strcmp(cArrayUser[iSpielerID][2], cLoginName) == 0)
		{
	     color(2);
		 printf ("\1 Name OK \1");
		 color(16);
		 iGefunden = 1;
		 LoginPasswort1(iSpielerID);
		 iSpielerID = iNrLetzteZeile;
		}
		else
		{
			/* Wenn an der letzten Zeile angekommen dann... */
			if (iSpielerID == iNrLetzteZeile)
			{
			color(1);
			printf ("Unbekannter Loginname, zum Registrieren 1 dr\201cken: ");
			color(16);
			scanf ("%i", &iRegistrieren);
			fflush(stdin);
			/* Registrieren ja? */
			if (iRegistrieren == 1)
			{
			 RegistrierungNameEingabe();
			}
			}
		}
	 }
	Sleep(1500);
	}
	return EXIT_FAILURE;
}

/*
   ========================================================================
   Funktion LoginPasswort1(int iSpielerID)
   @Aufruf: LoginPasswort1(iSpielerID)
   @Beschreibung: Passwort wird überprüft, übergeben wird die Zeile in der,
				  der Benutzer vom Login gefunden wurde.
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int LoginPasswort1(int iSpielerID)
{
	char cLoginPasswort[L_PASS] = "";
	int iPasswortOK = 0;
	int iPasswortCount = 0;
	/* Solange bis das Passwort richtig eingegeben wurde */
	while (iPasswortOK != 1)
	{
	printf ("\nBitte Passwort eingeben");
	color(1);
	printf (" (0 zum Abbrechen): ");
	color(16);
	strcpy(cLoginPasswort, GetPasswort(cLoginPasswort));
	/* Abbrechen? */
	if (strcmp(cLoginPasswort, "0") == 0)
	{
	 color(1);
	 printf ("\nLogin abgebrochen...\n\n");
	 color(16);
	 Sleep(1000);
	 return EXIT_FAILURE;
	}
	fflush(stdin);
	/* Passwort für die Textdatei verschlüsseln, da für jeden einlesebar */
	Verschluesseln(cLoginPasswort,CRYPT_KEY);	
		/* Wenn das Passwort in der selben Zeile der Datei wie der Name steht */
		if (strcmp(cArrayUser[iSpielerID][3], cLoginPasswort) == 0)
		{
		 color(2);
		 printf ("\1 Passwort OK \1\n");
		 color(16);
		 Spielmenu (iSpielerID, 0);
		 iPasswortOK = 1;
		 return iSpielerID;
		}
		else
		{
		 color(1);
		 printf ("Falsches Passwort.");
		 strcpy(cLoginPasswort,"");
		 iPasswortCount++;
		 /* Wenn mehr als 3 Versuche in der Passwort Eingabe dann Programm Ende */
		 if(iPasswortCount>2)
		 {
			 printf ("\nSie haben 3 mal ein falsches Passwort eingegeben.\nDas Programm wird nun beendet.");
			 Sleep(CDclose*1000);
			 exit(0);
		 }
		 color(16);
		}
	}
	return EXIT_FAILURE;
}

/*
   ========================================================================
   Funktion LoginEingabeName2()
   @Aufruf: LoginEingabeName2()
   @Beschreibung: Eingabe im Login wird mit dem Inhalt der Textdatei 
				  verglichen. Dem entsprechend wird gehandelt.
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int LoginEingabeName2(void)
{
	char cLoginName[L_NAME] = "leer";
	int iGefunden = 0;
	LeseZerlegeDatei();
	while (iGefunden != 1)
	{
	system ("cls");
	printf ("Mitspieler anmelden.\n");
	printf ("LOGIN BEREICH.\n");
	printf ("Bitte Namen eingeben");
	color(1);
	printf (" (0 zum Abbrechen): ");
	color(16);
	scanf("%s",&cLoginName);
	fflush(stdin);
	strcpy(cLoginName, cLoginName);
	if (strcmp(cLoginName, "0") == 0)
	{
	 color(1);
	 printf ("\nLogin abgebrochen...\n\n");
	 color(16);
	 Sleep(1000);
	 Spielmenu (iSpielerID, 0);
	 //return EXIT_FAILURE;
	}
	 for (iSpielerID2 = 1;iSpielerID2 <= iNrLetzteZeile;iSpielerID2++)
	 {
		if (strcmp(cArrayUser[iSpielerID2][2], cLoginName) == 0)
		{
			/* Wenn die erste gespeicherte Zeile wie die Eingabe ist dann */
			if (strcmp(cArrayUser[iSpielerID][2], cLoginName) == 0)
			{
			 color(1);
			 printf ("Dieser Spieler ist bereits angemeldet.\n");
			 iSpielerID2 = iNrLetzteZeile;
			 color(16);
			}
			else
			{
			 color(2);
			 printf ("\1 Name OK \1");
			 color(16);
			 iGefunden = 1;
			 LoginPasswort2(iSpielerID2);
			 iSpielerID2 = iNrLetzteZeile;
			}
		}
		else
		{
			/* Wenn am Ende der Datei angekommen dann... */
			if (iSpielerID2 == iNrLetzteZeile)
			{
			color(1);
			printf ("Unbekannter Loginname.");
			color(16);
			}
		}
		
	 }
	Sleep(1500);
	}
	return EXIT_FAILURE;
}

/*
   ========================================================================
   Funktion LoginPasswort2(int iSpielerID2)
   @Aufruf: LoginPasswort2(iSpielerID2)
   @Beschreibung: Passwort wird überprüft, übergeben wird die Zeile in der,
				  der Benutzer vom Login gefunden wurde.
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int LoginPasswort2(int iSpielerID2)
{
	char cLoginPasswort[L_PASS] = "leer";
	int iPasswortOK = 0;
	int iPasswortCount2 = 0;
	while (iPasswortOK != 1)
	{
	printf ("\nBitte Passwort eingeben ");
	color(1);
	printf (" (0 zum Abbrechen): ");
	color(16);
	strcpy(cLoginPasswort, GetPasswort(cLoginPasswort));
	if (strcmp(cLoginPasswort, "0") == 0)
	{
	 color(1);
	 printf ("\nLogin abgebrochen...\n\n");
	 color(16);
	 Spielmenu (iSpielerID, 0);
	 Sleep(1000);
	 //return EXIT_FAILURE;
	}
	fflush(stdin);
	Verschluesseln(cLoginPasswort,CRYPT_KEY);	
		if (strcmp(cArrayUser[iSpielerID2][3], cLoginPasswort) == 0)
		{
		 color(2);
		 printf ("\1 Passwort OK \1\n");
		 color(16);
		 Spielmenu (iSpielerID, iSpielerID2);
		 iPasswortOK = 1;
		 return iSpielerID2;
		}
		else
		{
		 color(1);
		 printf ("Falsches Passwort.");
		 iPasswortCount2++;
		 if(iPasswortCount2>2)
		 {
			 printf ("\nSie haben 3 mal ein falsches Passwort eingegeben.\nDas Programm wird nun beendet.");
			 Sleep(CDclose*1000);
			 exit(0);
		 }
		 color(16);
		}
	}

	return EXIT_FAILURE;
}

/*
   ========================================================================
   Funktion ArrayAusgeben()
   @Aufruf: ArrayAusgeben()
   @Beschreibung: Funktion zum Ausgeben der Textdatei geteilt durch Sepparator
   ========================================================================
*/
void ArrayAusgeben(void)
{
	int iZaehler;
	int iMaxToken;
	for(iZaehler=0; iZaehler<iNrLetzteZeile;iZaehler++) {
		printf("\nZeile: %s\n", cArrayUser[iZaehler][0]);
		printf("\n\n=======Zeile %i=========", iZaehler+1);
		for(iMaxToken=1; iMaxToken<6; iMaxToken++) {
			printf("%i und %i", iZaehler, iNrLetzteZeile);
			printf ("\n%s: %s", cArrayUser[0][iMaxToken], cArrayUser[iZaehler][iMaxToken]);
		}
		
	}
	printf("\n\n");
	printf("ENDE ArrayAusgeben");
}


/*
============================================================================
	Funktion *GetPasswort(cPasswort)
	ersetzt das Eingabe Zeichen durch einen Platzhalter *,
	wenn der define Placeholder entfernt wird, entfällt die Bewegung des Coursors
	wärend der Eingabe
	Quelle: http://www.pronix.de/comment/site-958/open-1395/site-1.html
============================================================================
*/
char *GetPasswort(char *cPasswort)
{
	char ch,*cPasswortp=cPasswort;
	int i,y;
	i = 0;
	while( i < L_PASS )
	{
		ch = getch();
		switch(ch)
		{	
			/*wenn Backspace*/
			case 8 : 
			{
				if(i != 0)
				{
					printf("\b \b");
					*cPasswortp-- = "";
					i--;
				}
			}break;
			/* wenn enter */
			case 13:
			{
				i = L_PASS;
			}break;
			default:
			{
				*cPasswortp++=ch;
				printf("*");
				i++;
			}
		}
	}
	
	printf("\n");
	*cPasswortp='\0';
	return(cPasswort);
}


/*
   ========================================================================
   Funktion Verschluesseln()
   @Aufruf: Verschluesseln()
   @Beschreibung: Verschlüsselt das Passwort
   ========================================================================
*/
void Verschluesseln(char str[], int key)
{
    unsigned int i;
	/* Solange bis alle Zeichen des Strings verschlüsselt wurden */
    for(i=0;i<strlen(str);++i)
    {
		  /* 1 Zeichen - define */
          str[i] = str[i] - key;
    }
}
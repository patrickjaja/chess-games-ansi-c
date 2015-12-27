/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : MenuRegistration.c
Datum : 17.03.09
Version : 1.0
Thema : Projektarbeit
Beschreibung: Abfragen Benutzername/Passwort und dann in Datei schreiben
Programmschnittstelle: Funktionen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion RegistrierungNameEingabe()

   @Aufruf: RegistrierungNameEingabe()
   @Beschreibung: Füllt das Array durch Aufruft der Funktion LeseZerlegeDatei().
			      Dann wird die Eingabe mit den gelesenen bestehenden Daten verglichen.
				  Jetzt wird überprüft ob die Eingabe der vordefinierten
				  Mindestlänge und Maximallänge entspricht und danach die
				  Registration des Passwortes aufgerufen.
   @return ENDE: -
   ========================================================================
*/
void RegistrierungNameEingabe(void)
{
	int iSpielerID = 1;
	int pos = 0;
	LeseZerlegeDatei();
	printf ("Bitte Namen eingeben (Max %i Zeichen): ", L_NAME);
	scanf("%s",&cLoginName1);
	strcpy(cLoginName1, cLoginName1);
	fflush(stdin);
	/* Eingabe ist in TextDatei vorhanden? */
	for (iSpielerID = 1;iSpielerID <= iNrLetzteZeile;iSpielerID++)
	 {  
		 /* wenn Name bereits vorhanden dann erneute Eingabe */
		if (strcmp(cArrayUser[iSpielerID][2], cLoginName1) == 0) 
		{
		 color(1);
		 printf ("Fehler: Name bereits vorhanden.\n");
	     color(16);
		 RegistrierungNameEingabe();
		 iSpielerID = iNrLetzteZeile;
		}
		else
		{
			/* Wenn am Ende der Datei angekommen dann weiter zur
			   Passwort Eingabe */
			if (iSpielerID == iNrLetzteZeile)
			{
			 /* Eingabe kleiner als Maxlänge */
			 if (strlen(cLoginName1) <= L_NAME)
			  {
				/* Eingabe größer als Minimallänge */
				if (strlen(cLoginName1) >= S_NAME)
				{
					pos = 0;
					pos = strchr(cLoginName1, ';') - &cLoginName1;
					if (pos <= 0)
					{
					  RegistrierungPasswortEingabe();
					}
					else
					{
						color(1);
						printf("Im Namen darf kein ';' vorhanden sein.\n");
						color(16);
						RegistrierungNameEingabe();
					}
				}
				else
				{
				  color(1);
				  printf("Fehler: Der Name muss mindestens aus %i Zeichen bestehen!\n", S_NAME);
				  color(16);
				}
			  }
			  else
			  {	
				color(1);
				printf("Fehler: Der Name darf maximal aus %i Zeichen bestehen!\n", L_NAME);
				color(16);
				RegistrierungNameEingabe();
			  }
			}
		  }
	   }
}

/*
   ========================================================================
   Funktion RegistrierungPasswortEingabe()
   @Aufruf: RegistrierungPasswortEingabe()
   @Beschreibung: Es wird das Passwort abgefragt und danach zusammen mit
				  dem LoginNamen in eine Datei geschrieben. Die Eingabe
				  wird auf Mindestlänge und Maximallänge überprüft
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int RegistrierungPasswortEingabe(void)
{
	char cPasswort[L_PASS];
	printf ("Bitte Passwort eingeben (Max %i Zeichen):", L_PASS);
	/* Einlesen des Passwortes durch die Funktion GetPasswort,
	   als Parameter wird jedes einzelne Zeichen der Eingabe übergeben*/
	strcpy(cLoginPasswort1, GetPasswort(cPasswort));
	fflush(stdin);
	/* Eingabe kleiner als Maxlänge */
	if (strlen(cLoginPasswort1) <= L_PASS)
	{
		/* Eingabe kleiner als Minimallänge */
		if (strlen(cLoginPasswort1) >= S_PASS)
		{

			/* Füllt die Datei */
			SchreibeDatei();
			/* Füllt die Datei der Statistik mit default Informationen */
			StatistikNeu();
			
		}
		else
		{
			color(1);
			printf("Fehler: Das Passwort muss mindestens aus %i Zeichen bestehen!\n", S_PASS);
			color(16);
			RegistrierungPasswortEingabe();
	    }
	    
	}
	else
	{	
		color(1);
		printf("Fehler: Das Passwort darf maximal aus %i Zeichen bestehen!\n", L_PASS);
		color(16);
		RegistrierungPasswortEingabe();
	}
	return EXIT_FAILURE;
}

/*
   ========================================================================
   Funktion RegistrierungNameEingabe2()

   @Aufruf: RegistrierungNameEingabe()
   @Beschreibung: Füllt das Array durch Aufruft der Funktion LeseZerlegeDatei().
			      Dann wird die Eingabe mit den gelesenen bestehenden Daten verglichen.
				  Jetzt wird überprüft ob die Eingabe der vordefinierten
				  Mindestlänge und Maximallänge entspricht und danach die
				  Registration des Passwortes aufgerufen.
   @return ENDE: -
   ========================================================================
*/
void RegistrierungNameEingabe2(void)
{
	int iSpielerID = 1;
	int pos = 0;
	LeseZerlegeDatei();
	printf ("Bitte Namen eingeben (Max %i Zeichen): ", L_NAME);
	scanf("%s",&cLoginName1);
	strcpy(cLoginName1, cLoginName1);
	fflush(stdin);
	/* Eingabe ist in TextDatei vorhanden? */
	for (iSpielerID = 1;iSpielerID <= iNrLetzteZeile;iSpielerID++)
	 {  
		 /* wenn Name bereits vorhanden dann erneute Eingabe */
		if (strcmp(cArrayUser[iSpielerID][2], cLoginName1) == 0) 
		{
		 color(1);
		 printf ("Fehler: Name bereits vorhanden.\n");
	     color(16);
		 RegistrierungNameEingabe2();
		 iSpielerID = iNrLetzteZeile;
		}
		else
		{
			/* Wenn am Ende der Datei angekommen dann weiter zur
			   Passwort Eingabe */
			if (iSpielerID == iNrLetzteZeile)
			{
			 /* Eingabe kleiner als Maxlänge */
			 if (strlen(cLoginName1) <= L_NAME)
			  {
				/* Eingabe größer als Minimallänge */
				if (strlen(cLoginName1) >= S_NAME)
				{
					pos = 0;
					pos = strchr(cLoginName1, ';') - &cLoginName1;
					if (pos <= 0)
					{
					  RegistrierungPasswortEingabe2();
					}
					else
					{
						color(1);
						printf("Im Namen darf kein ';' vorhanden sein.\n");
						color(16);
						RegistrierungNameEingabe2();
					}
				}
				else
				{
				  color(1);
				  printf("Fehler: Der Name muss mindestens aus %i Zeichen bestehen!\n", S_NAME);
				  color(16);
				}
			  }
			  else
			  {	
				color(1);
				printf("Fehler: Der Name darf maximal aus %i Zeichen bestehen!\n", L_NAME);
				color(16);
				RegistrierungNameEingabe2();
			  }
			}
		  }
	   }
}

/*
   ========================================================================
   Funktion RegistrierungPasswortEingabe2()
   @Aufruf: RegistrierungPasswortEingabe2()
   @Beschreibung: Es wird das Passwort abgefragt und danach zusammen mit
				  dem LoginNamen in eine Datei geschrieben. Die Eingabe
				  wird auf Mindestlänge und Maximallänge überprüft
   @return EXIT_FAILURE: wird bei komplettem durchlauf der Funktion
						 zurück gegeben
   ========================================================================
*/
int RegistrierungPasswortEingabe2(void)
{
	char cPasswort[L_PASS];
	printf ("Bitte Passwort eingeben (Max %i Zeichen):", L_PASS);
	/* Einlesen des Passwortes durch die Funktion GetPasswort,
	   als Parameter wird jedes einzelne Zeichen der Eingabe übergeben*/
	strcpy(cLoginPasswort1, GetPasswort(cPasswort));
	fflush(stdin);
	/* Eingabe kleiner als Maxlänge */
	if (strlen(cLoginPasswort1) <= L_PASS)
	{
		/* Eingabe kleiner als Minimallänge */
		if (strlen(cLoginPasswort1) >= S_PASS)
		{

			/* Füllt die Datei */
			SchreibeDatei();
			/* Füllt die Datei der Statistik mit default Informationen */
			StatistikNeu();
			printf("\n");
			system("pause");
			Spielmenu (iSpielerID, 0);
			
		}
		else
		{
			color(1);
			printf("Fehler: Das Passwort muss mindestens aus %i Zeichen bestehen!\n", S_PASS);
			color(16);
			RegistrierungPasswortEingabe2();
	    }
	    
	}
	else
	{	
		color(1);
		printf("Fehler: Das Passwort darf maximal aus %i Zeichen bestehen!\n", L_PASS);
		color(16);
		RegistrierungPasswortEingabe2();
	}
	return EXIT_FAILURE;
}
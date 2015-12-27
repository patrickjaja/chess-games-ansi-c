/*
============================================================================
Autor : Patrick Schönfeld
Klasse : FI12
Dateiname : MenuStart.c
Datum : 17.03.09
Version : 1.0
============================================================================
*/

#include "Funktionen.h"

/*
============================================================================
Funktion Spielmenu
@beschreibung Gibt das Spielemenü aus
============================================================================
*/
int Spielmenu(int iSpieler1, int iSpieler2)
{
	int iEingabe;
	int iZweiSpieler = 0;

	StatistikLaden();
	do
	{
		system("cls");
		if (iSpieler2 != 0)
		{
			iZweiSpieler = 1;
			InfoKopfzeile(cArrayUser[iSpieler1][2], cArrayUser[iSpieler2][2], cArrayUser[iSpieler1][5], cArrayUser[iSpieler2][5]);
		}
		else
		{
			InfoKopfzeile(cArrayUser[iSpieler1][2], "a", cArrayUser[iSpieler1][5], "");
		}
		printf("\nSpielmen\201\n");

		if (iZweiSpieler == 1)
		{
			printf("1. Checkers \n2. Reversi \n3. 4-Gewinnt \n4. Bridges\n5. Statistik\n6. Spieler 1 ausloggen\n7. Spieler 2 ausloggen\n8. Online Hilfe\n9. zur\201ck ins Hauptmen\201 (alle ausloggen)\n0. Programm Beenden\n");
			FarbigerBalken(4);
			printf("Hallo %s und %s, ihr befindet euch im Spielmen\201.\nBitte w\204hle eine Option: ", cArrayUser[iSpieler1][2], cArrayUser[iSpieler2][2]);
			scanf("%i", &iEingabe);	
			fflush (stdin);

			switch(iEingabe)
			{
			 case 1:
				StatistikNewStats(Dame(),1);
 				break;
			 case 2:
				StatistikNewStats(Reversi(),2);		  
				break;
			 case 3:
				StatistikNewStats(VierGewinnt(),3);
 				break;
			 case 4:
				StatistikNewStats(Bridges(),4);
				break;
			 case 5:
				 StatistikAuswahlMenu();
				 system("pause");
				break;
			 case 6:
				 iSpieler1 = iSpieler2;
				 iSpieler2 = 0;
				 iSpielerID = iSpieler1;
				 iZweiSpieler = 0;
				 break;
			 case 7:
			    iSpieler2 = 0;
				iZweiSpieler = 0;
				break;
			 case 8:
				system("online.htm");
				break;
			 case 9:
				HauptMenu();
				break;
			 case 0:
				color(2);
				printf("\n\nHoffentlich bis bald!");
				color(0);
				printf("\n\n\nDieses Fenster schlie\341t sich in %i Sekunden automatisch.\n", CDclose);
				Sleep(CDclose*1000);
				exit(0);
				break;
			}
		}
		else
		{
			printf("1. Checkers \n2. Reversi \n3. 4-Gewinnt \n4. Bridges\n5. Statistik\n6. Mitspieler anmelden\n7. Online Hilfe\n8. zur\201ck ins Hauptmen\201 (ausloggen)\n9. Mitspieler Registrieren\n0. Programm Beenden\n");
	 		FarbigerBalken(4);
			printf("Hallo %s, du befindest dich im Spielmen\201.\nBitte w\204hle eine Option: ", cArrayUser[iSpieler1][2]);
			scanf("%i", &iEingabe);	
			fflush (stdin);

			switch(iEingabe)
			{
			 case 1:
			 case 2:
			 case 3:
			 case 4:
				color(1);
				printf("\nFehler: Dieses Spiel ist nur mit zwei Spielern m\224glich\n");
				color(16);
				system("pause");
				break;
			 case 5:
				 StatistikAuswahlMenu();
				 system("pause");
				break;
			 case 6:
				LoginEingabeName2();
				return EXIT_SUCCESS;
			 case 7:
				system("online.htm");
				break;
			 case 8:
				HauptMenu();
				break;
			 case 9:
				RegistrierungNameEingabe2();
			 case 0:
				color(2);
				printf("\n\nHoffentlich bis bald!");
				color(0);
				printf("\n\n\nDieses Fenster schlie\341t sich in %i Sekunden automatisch.\n", CDclose);
				Sleep(CDclose*1000);
				exit(0);
				break;
			}
		}
	}while (iEingabe != 0);

	return EXIT_SUCCESS;
}

/*
============================================================================
Funktion HauptMenu()
@beschreibung Gibt das Hauptmenü aus
============================================================================
*/
void HauptMenu(void)
{
	char cEingabe[2];
	int iEingabe = 0;
	cEingabe[0] = '0';
	do
	{
		system ("cls");
		InfoKopfzeile("", "", "", "");
		printf ("\n Schachbrettspiele Hauptmen\201 \n\n");
		printf ("1. Login\n");
		printf ("2. Registrieren\n");
		printf ("3. Online Hilfe\n");
		printf ("4. Info\n");
		printf ("6. Weg hier!\n\n");
		FarbigerBalken (1);
		printf ("Bitte eine dieser Optionen w\204hlen \30:");
		scanf ("%s", &cEingabe);
	    fflush (stdin);
		iEingabe = atoi(cEingabe);
		switch(iEingabe)
		{
		 case 1:
			LoginEingabeName1();
			system("pause");
		  break;
		 case 2:
			RegistrierungNameEingabe(); //Name eingeben, Passwort eingeben, in Datei schreiben
			Sleep(2000);
		  break;
		 case 3:
			 system("online.htm");
		  break;
		 case 4:
			 color(2);
			 printf("Release 1.0, Gruppe 3.\n\nMitarbeiter:\n Gilles Meyer\n David Frerich\n Milan Niezgodka\n Pascal Neuhausen\n Andreas Danek\n Daniel Jan\341en\n Patrick Sch\224nfeld\n Jakob Bohr\n Linda von Groote");
			 color(16);
			 Sleep(6000);
		  break;
		 case 5:
			 color(1);
			 printf("Falsche Eingabe.");
			 Sleep(1000);
			 HauptMenu();
			 color(16);
		 case 6:
			color(2);
			printf("\n\nHoffentlich bis bald!");
			color(0);
			printf("\n\n\nDieses Fenster schlie\341t sich in %i Sekunden automatisch.\n", CDclose);
			Sleep(CDclose*1000);
			exit(0);
		  break;
		   default :    
			 HauptMenu();
			break;
		}     
    }while (iEingabe != 0);
}

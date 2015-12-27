/*
   ============================================================================
   Programmname: DameSpielen.c
   Autor       : Andreas Danek, Daniel Janßen
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
   Funktion DameSpielen()

   @aufruf: main()
   @beschreibung: Steuert das spiel
   @return iEnde: gibt zurück ob das Spiel zu Ende ist. Bei 1 ist das Spiel
				  zu Ende
   @return ENDE: wird bei Aufgabe des Spielers zurückgegeben
   ========================================================================
*/
int DameSpielen()
{
	int iZug_beendet = 1;
	int iEnde = 0;
	int iErsterSprung = 1;
	
	Spieler();
	DameiErbeutenBelegen();
	DameErbeuten();
	if (iErbeuten[0][0] != -5)
	{
		color(3);
		printf("\nHinweis: Sie m\201ssen einen Stein Erbeuten\n\n");
		color(0);
		iEnde = DameSpringen(iErsterSprung);
		if (iEnde==1)
		{
			return ENDE;
		}
		ZeichneFeld(8,8);
		do{
			iErsterSprung+=1;
			iZug_beendet = DameKannGesprungenerSteinNochEinmalSpringen();
			if (iZug_beendet == 0)
			{
				iEnde = DameSpringen(iErsterSprung);
				if (iEnde==1)
				{
					return ENDE;
				}
				ZeichneFeld(8,8);
			}
		}while (iZug_beendet != 1);
	}
	if (iErsterSprung == 1)
	{
		iEnde = DameSteinSetzen();
		if (iEnde==1)
		{
			return ENDE;
		}
		ZeichneFeld(8,8);
	}

	iSpieler *= -1;
	Spieler();
	return iEnde = DameUeberpruefeSpielende(iEnde);
}

/*
   ========================================================================
   Funktion DameSteinSetzen()

   @aufruf: DameSpielen()
   @beschreibung: Liest die Koordinaten zum Steinsetzen ein, überprüft
				  ob der gewünschte Zug möglich ist und ruft anschließend
				  die Methode zum Bewegen des Steines auf
   @return OK: alles wurde erfolgreich ausgeführt
   @return ENDE: Spieler hat aufgegeben
   ========================================================================
*/
int DameSteinSetzen()
{
	int iRueckgabe = 0;
	int ixKoordinate = 0;
	int iyKoordinate = 0;
	int ixZiel = 0;
	int iyZiel = 0;

	do{
		printf("\nWelcher Stein soll bewegt werden?\n");
		if(PositionEingeben(&ixKoordinate, &iyKoordinate, 8, 8, 1) == NOTOK)
		{
			/*iSpieler *= -1;*/
			iSpieler = 0;
			return ENDE;
		}

		iRueckgabe = DameAusgewaehlterSteinVorhanden(ixKoordinate,iyKoordinate);

		if (iRueckgabe == 0)
		{
			iRueckgabe = DameKannSteinBewegtWerden(ixKoordinate,iyKoordinate, iRueckgabe);		  
		}
	}while (iRueckgabe == 1);

	iRueckgabe = 0;
	do{
		if (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[0])
		{
			if(DameBelegeZielStein(&ixZiel, &iyZiel, ixKoordinate, iyKoordinate) == ENDE)
			{
				/*iSpieler *= -1;*/
				iSpieler = 0;
				return ENDE;
			}
		}
		else
		{
			if(DameBelegeZielDame(&ixZiel, &iyZiel, ixKoordinate, iyKoordinate) == ENDE)
			{
				/*iSpieler *= -1;*/
				iSpieler = 0;
				return ENDE;
			}
		}
		iRueckgabe = ZielfeldLeer(ixZiel,iyZiel);
	}while (iRueckgabe != 0);

	DameBewegeStein(ixKoordinate,iyKoordinate,ixZiel,iyZiel);
	return OK;
}


/*
   ========================================================================
   Funktion DameSpringen()

   @aufruf: DameSpielen()
   @beschreibung: Liest die Koordinaten zum Springen ein, überprüft
				  ob der gewünschte Zug möglich ist und ruft anschließend
				  die Methode zum Springen des Steines auf
   @param iErster-Sprung: Integer-Variable welche angibt ob es sich um den
						  ersten Sprung des Spielers in diesem Spielzug
						  handelt
   @return OK: alles wurde erfolgreich ausgeführt
   @return ENDE: Spieler hat aufgegeben
   ========================================================================
*/
int DameSpringen(int iErsterSprung)
{
	int ixKoordinate;
	int iyKoordinate;
	int ixZiel;
	int iyZiel;
	int iInArray;
	int iGueltigersprung = 1;
	
	if (iErsterSprung == 1)
	{
		do{
			printf("Welcher Stein soll bewegt werden?\n");
			if(PositionEingeben(&ixKoordinate, &iyKoordinate, 8, 8, 1) == NOTOK)
			{
				return ENDE;
			}

			iInArray = DamePruefeSteinIniErbeuten(ixKoordinate,iyKoordinate);
		}while (iInArray != 0);
	}
	else
	{
		ixKoordinate = iSteinStehtIn[0][0];
		iyKoordinate = iSteinStehtIn[0][1];
	}

	do{
		ZeichneFeld(8,8);
		printf("\nWohin soll der Stein bewegt werden?\n");
		if(PositionEingeben(&ixZiel, &iyZiel, 8, 8, 0) == NOTOK)
		{
			return ENDE;
		}

		if (cSpielFeld[ixKoordinate][iyKoordinate] == cSpielsteine[0])
		{
			if ((ixKoordinate+iSpieler*2==ixZiel && iyKoordinate+iSpieler*2==iyZiel)
			 || (ixKoordinate-iSpieler*2==ixZiel && iyKoordinate+iSpieler*2==iyZiel))
			{
				iGueltigersprung = DameGueltigerSprung(ixZiel,iyZiel,ixKoordinate,iyKoordinate);
			}
		}
		else
		{
			if ((ixKoordinate+iSpieler*2==ixZiel && iyKoordinate+iSpieler*2==iyZiel)
			 || (ixKoordinate-iSpieler*2==ixZiel && iyKoordinate+iSpieler*2==iyZiel)
			 || (ixKoordinate+iSpieler*2==ixZiel && iyKoordinate-iSpieler*2==iyZiel)
			 || (ixKoordinate-iSpieler*2==ixZiel && iyKoordinate-iSpieler*2==iyZiel))
			{
				iGueltigersprung = DameGueltigerSprungDame(ixZiel,iyZiel,ixKoordinate,iyKoordinate);
			}
		}
	}while (iGueltigersprung != 0);

	DameSchlageStein(ixZiel,iyZiel,ixKoordinate,iyKoordinate);

	return OK;
}


/*
   ========================================================================
   Funktion DameKannGesprungenerSteinNochEinmalSpringen()

   @aufruf: DameSpielen()
   @beschreibung: Überprüfung ob der gerade gesprungene Stein noch einmal
				  springen kann
   @return iSprung_moeglich: Integer-Variable, welche angibt ob ein 
							 erneuter Sprung nochmal möglich ist (bei 0)
   ========================================================================
*/

int DameKannGesprungenerSteinNochEinmalSpringen()
{
	int iSprung_moeglich = 1;

	if (cSpielFeld[iSteinStehtIn[0][0]][iSteinStehtIn[0][1]] == cSpielsteine[0])
	{
		return iSprung_moeglich = DameUeberpruefeSpielstein(iSteinStehtIn[0][0],iSteinStehtIn[0][1]);
	}
	else
	{
		return iSprung_moeglich = DameUeberpruefeDame(iSteinStehtIn[0][0],iSteinStehtIn[0][1]);
	}
}


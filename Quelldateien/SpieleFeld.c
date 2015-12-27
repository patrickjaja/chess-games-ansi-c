/*
   ============================================================================
   Programmname: SpieleFeld.c
   Autor       : David Frerich, Andreas Danek, Daniel Janßen, Gilles Meyer
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
   Funktion ErstelleSpielFeld()

   @beschreibung: erzeugt ein spielfeld
   @param iBreite: die breite des spielfeldes (maximal 17)
   @param iHoehe: die höhe des spielfeldes (maximal 17)
   @return OK
   ========================================================================
*/
int ErstelleSpielFeld(int iBreite, int iHoehe)
{
 	int iFeldHoehe, iFeldBreite;
	color(0);
	
	if(iBreite > 0 && iHoehe > 0 && iBreite <= 17 && iHoehe <= 17)
	{
		for(iFeldHoehe = 0; iFeldHoehe < iHoehe; iFeldHoehe++)
		{
			for(iFeldBreite = 0; iFeldBreite < iBreite ; iFeldBreite++)
			{
				if((iFeldHoehe+iFeldBreite)%2 == 0)
				{
					cSpielFeld[iFeldBreite][iFeldHoehe] = WEISS;
				}
				else
				{
					cSpielFeld[iFeldBreite][iFeldHoehe] = SCHWARZ;
				}
			}
		}
		ZeichneFeld(iBreite, iHoehe);
		return 0;
	}
	else
	{
		printf("Fehler");
	}
	return OK;
}

/*
   ========================================================================
   Funktion ZeichneFeld()

   @beschreibung: gibt das spielfeld in der konsole aus
   @param iBreite: die breite des spielfeldes (maximal 17)
   @param iHoehe: die höhe des spielfeldes (maximal 17)
   @return OK
   ========================================================================
*/
int ZeichneFeld(int iBreite, int iHoehe)
{
	int iFeldBreit, iFeldHoch;
	int iFeldHoehe, iFeldBreite;
	int iMaxFeldBreit, iMaxFeldHoch, iMax;
	int iBeschriftungDrin[18][18];

	/* Array für Beschriftungsabfrage auf 0 setzen */
	for(iFeldHoehe = 0; iFeldHoehe < iHoehe; iFeldHoehe++)
	{
		for(iFeldBreite = 0; iFeldBreite < iBreite; iFeldBreite++)
		{
			iBeschriftungDrin[iFeldBreite][iFeldHoehe] = 0;
		}
	}

	if(iBreite > iHoehe)
	{
		iMax = iBreite;
	}
	else
	{
		iMax = iHoehe;
	}

	/* Feldgröße der einzelnen Felder relativ zur Breite/Hoehe der Felder */
	iMaxFeldHoch = (int)ceil(40/iMax);
	iMaxFeldBreit = (int)ceil(60/iMax);

	system("cls");
	for(iFeldHoehe = -1; iFeldHoehe < iHoehe; iFeldHoehe++)
	{
		for(iFeldHoch = 0; iFeldHoch < iMaxFeldHoch; iFeldHoch++)
		{
			for(iFeldBreite = -1; iFeldBreite < iBreite; iFeldBreite++)
			{
				for(iFeldBreit = 0; iFeldBreit < iMaxFeldBreit; iFeldBreit++)
				{
					/* Leere Felder des Randes (mit Schwarz füllen) */
					if((iFeldBreite < 0 && iFeldHoehe < 0) || (iFeldBreite < 0 || iFeldHoehe < 0) && (iBeschriftungDrin[(iFeldBreite+1)][(iFeldHoehe+1)] == 1))
					{
						printf("%c", SCHWARZ);
					}
					/* Linker Rand (Beschriftung Zahlen) */
					else if(iFeldBreite < 0)
					{
						/* Zweite Stelle der Zahl */
						if(iBeschriftungDrin[(iFeldBreite+1)][(iFeldHoehe+1)] == 2)
						{
							printf("%c", (iFeldHoehe + 1 - (iFeldHoehe + 1)/10*10 + 48));
							iBeschriftungDrin[(iFeldBreite+1)][(iFeldHoehe+1)] = 1;
						}
						/* Erste Stelle der Zahl */
						else
						{
							printf("%c", ((iFeldHoehe + 1)/10 + 48));
							iBeschriftungDrin[(iFeldBreite+1)][(iFeldHoehe+1)] = 2;
						}
					}
					/* Oberer Rand (Beschriftung Buchstaben) */
					else if(iFeldHoehe < 0)
					{
						printf("%c", iFeldBreite + 65);
						iBeschriftungDrin[(iFeldBreite+1)][(iFeldHoehe+1)] = 1;
					}
					/* Normales Spielfeld */
					else
					{
						/* Felder einfärben */
						switch(cSpielFeld[iFeldBreite][iFeldHoehe])
						{
							case HBLAU:
								color(6);
								printf("%c", ROT);
								break;
							case PINK:
								color(5);
								printf("%c", ROT);
								break;
							case ROT:
								color(1);
								printf("%c", ROT);
								break;
							case BLAU:
								color(4);
								printf("%c", BLAU);
								break;
							case SCHWARZ:
								color(7);
								printf("%c", SCHWARZ);
								break;
							default:
								color(0);
								printf("%c", WEISS);
								break;
						}
						color(0);
					}
				}
			}
			printf("\n");
		}
	}
	return OK;
}

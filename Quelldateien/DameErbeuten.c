/*
   ============================================================================
   Programmname: DameErbeuten.c
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
   Funktion DameErbeuten()

   @aufruf: DameSpielen()
   @beschreibung: durchläuft das Spielfeld, guckt wo eigene Steine stehen,
				  und speichert diese Position wenn gesprungen werden kann
   @return OK: gibt OK zurück, wenn alles ausgeführt wurde
   ========================================================================
*/

int DameErbeuten()
{
	int iArrayZaehler = 0;
	int iRueckgabe = 0;
	int iBreite;
	int iHoehe;

	for (iHoehe = 0; iHoehe < 8; iHoehe++)
	{
		for (iBreite = 0; iBreite < 8; iBreite++)
		{
			if(cSpielFeld[iBreite][iHoehe] == cSpielsteine[2] ||
				 cSpielFeld[iBreite][iHoehe] == cSpielsteine [0])
			{
				
				/*
				 * Überprüfung für einen normalen Stein
				 */ 
				if (cSpielFeld[iBreite][iHoehe] == cSpielsteine[0])
				{
					iRueckgabe = DameUeberpruefeSpielstein(iBreite,iHoehe);
					if (iRueckgabe == 0)
					{
						iArrayZaehler=DameiErbeutenBelegenWert(iBreite,iHoehe,iArrayZaehler);
					}
				}

				/*
				 * sonst für die Dame
				 */ 
				else
				{
					iRueckgabe = DameUeberpruefeDame(iBreite,iHoehe);
					if (iRueckgabe == 0)
					{
						iArrayZaehler=DameiErbeutenBelegenWert(iBreite,iHoehe,iArrayZaehler);
					}
				}
			}
		}
	}
	return OK;
}

/*
   ========================================================================
   Funktion DameiErbeutenBelegenWert(int iBreite, int iHoehe, int iArrayZaehler)

   @aufruf: DameErbeuten()
   @beschreibung: belegt iErbeuten mit dem aktuellen Wert des Steines
   @param iBreite: die x-Koordinate des aktuellen Steines/Dame
   @param iHoehe: die y-Koordinate des aktuellen Steines/Dame
   @param iArrayZaehler: die nächste, leere Position im Array
   @return iArrayZaehler: die nächste leere Stelle im Array
   ========================================================================
*/
int DameiErbeutenBelegenWert(int iBreite, int iHoehe, int iArrayZaehler)
{
	iErbeuten[iArrayZaehler][0] = iBreite;
	iErbeuten[iArrayZaehler][1] = iHoehe;
	iArrayZaehler++;
	return iArrayZaehler;
}

/*
   ========================================================================
   Funktion DameUeberpruefeSpielstein()

   @aufruf: DameErbeuten()
   @beschreibung: Überprüft, ob der Stein erbeuten kann
   @param iBreite: die x-Koordinate des aktuellen Steines
   @param iHoehe: die y-Koordinate des aktuellen Steines
   @return OK: Stein kann erbeuten
   @return NOTOK: Stein kann nicht erbeuten
   ========================================================================
*/
int DameUeberpruefeSpielstein(int iBreite, int iHoehe)
{
	/*
	 * Stein steht in der Mitte, kann in alle Richtungen erbeuten
	 */ 
	if (iBreite>1 && iBreite<6)
	{
		if ((cSpielFeld[iBreite-iSpieler][iHoehe+iSpieler] ==
		 cSpielsteine[3] && cSpielFeld[iBreite-iSpieler*2][iHoehe+iSpieler*2] == SCHWARZ) 
		 || (cSpielFeld[iBreite-iSpieler][iHoehe+iSpieler] ==
		  cSpielsteine[1] && cSpielFeld[iBreite-iSpieler*2][iHoehe+iSpieler*2] == SCHWARZ)
		 || (cSpielFeld[iBreite+iSpieler][iHoehe+iSpieler] ==
		  cSpielsteine[3] && cSpielFeld[iBreite+iSpieler*2][iHoehe+iSpieler*2] == SCHWARZ) 
		 || (cSpielFeld[iBreite+iSpieler][iHoehe+iSpieler] ==
		  cSpielsteine[1] && cSpielFeld[iBreite+iSpieler*2][iHoehe+iSpieler*2] == SCHWARZ))
		{
			return OK;
		}
	}

	/*
	 * Stein steht am linken Rand, kann nur nach rechts erbeuten
	 */ 
	else if (iBreite == 1 || iBreite == 0)
	{
		if ((cSpielFeld[iBreite+1][iHoehe+iSpieler] == cSpielsteine[3] &&
		 cSpielFeld[iBreite+2][iHoehe+iSpieler*2] == SCHWARZ)
		 || (cSpielFeld[iBreite+1][iHoehe+iSpieler] == cSpielsteine[1] &&
		  cSpielFeld[iBreite+2][iHoehe+iSpieler*2] == SCHWARZ))
		{
			return OK;
		}
	}

	/*
	 * Stein steht am rechten Rand, kann nur nach links erbeuten
	 */ 
	else
	{
		if (iBreite == 7 || iBreite == 6)
		{
			if ((cSpielFeld[iBreite-1][iHoehe+iSpieler] == cSpielsteine[3] &&
			 cSpielFeld[iBreite-2][iHoehe+iSpieler*2] == SCHWARZ)
			 || (cSpielFeld[iBreite-1][iHoehe+iSpieler] == cSpielsteine[1] &&
			  cSpielFeld[iBreite-2][iHoehe+iSpieler*2] == SCHWARZ))
			{
			return OK;
			}
		}
	}
	return NOTOK;
}


/*
   ========================================================================
   Funktion DameUeberpruefeDame()

   @aufruf: DameErbeuten()
   @beschreibung: Überprüft, wo die Dame am Spielfeld steht
   @param iBreite: die x-Koordinate des aktuellen Steines
   @param iHoehe: die y-Koordinate des aktuellen Steines
   @return Mitte:				Dame befindet sich mitten auf dem Spielfeld,  
								kann in jede Richtung erbeuten
   @return ObereLinkereEcke:	Dame befindet sich oben links auf dem 
								Spielfeld, kann nur nach unten rechts 
								erbeuten 
   @return ObereMitte:			Dame befindet sich oben in der Mitte auf  
								dem Spielfeld, kann nur nach unten 
								erbeuten
   @return ObereRechteEcke:		Dame befindet sich oben rechts auf dem 
								Spielfeld, kann nur nach unten links 
								erbeuten 
   @return LinkeMitte:			Dame befindet sich links in der Mitte auf  
								dem Spielfeld, kann nur nach rechts erbeuten 
   @return RechteMitte:			Dame befindet sich rechts in der Mitte auf  
								dem Spielfeld, kann nur nach links erbeuten 
   @return UntereLinkereEcke:	Dame befindet sich unten links auf dem 
								Spielfeld, kann nur nach oben rechts 
								erbeuten 
   @return UntereMitte:			Dame befindet sich unten in der Mitte auf  
								dem Spielfeld, kann nur nach oben 
								erbeuten
   @return UntereRechteEcke:	Dame befindet sich unten rechts auf dem 
								Spielfeld, kann nur nach oben links 
								erbeuten 
   @return NOTOK: Dame ist nicht auf dem Spielfeld
   ========================================================================
*/
int DameUeberpruefeDame(int iBreite,int iHoehe)
{		
	if (iBreite>1 && iBreite<6 && iHoehe>1 && iHoehe<6)
	{
		return DameMitte(iBreite, iHoehe);
	}
	else if ((iBreite == 1 || iBreite == 0) && (iHoehe == 0 || iHoehe == 1))
	{
		return DameObereLinkeEcke(iBreite, iHoehe);
	}
	else if ((iBreite > 1 || iBreite < 6) && (iHoehe == 0 || iHoehe == 1))
	{
		return DameObereMitte(iBreite, iHoehe);
	}
	else if ((iBreite == 6 || iBreite == 7) && (iHoehe == 0 || iHoehe == 1))
	{
		return DameObereRechteEcke(iBreite, iHoehe);
	}
	else if ((iBreite == 0 || iBreite == 1) && (iHoehe > 1 || iHoehe < 6))
	{
		return DameLinkeMitte(iBreite, iHoehe);
	}
	else if ((iBreite == 6 || iBreite == 7) && (iHoehe > 1 || iHoehe < 6))
	{
		return DameRechteMitte(iBreite, iHoehe);
	}
	else if ((iBreite == 0 || iBreite == 1) && (iHoehe == 6 || iHoehe == 7))
	{
		return DameUntereLinkeEcke(iBreite, iHoehe);
	}
	else if ((iBreite > 1 || iBreite < 6) && (iHoehe == 6 || iHoehe == 7))
	{
		return DameUntereMitte(iBreite, iHoehe);
	}
	else if ((iBreite == 6 || iBreite == 7) && (iHoehe == 6 || iHoehe == 7))
	{
		return DameUntereRechteEcke(iBreite, iHoehe);
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameObereLinkeEcke(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von oben links erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameObereLinkeEcke(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameObereMitte(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von oben mitte erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameObereMitte(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameObereRechteEcke(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von oben rechts erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameObereRechteEcke(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameLinkeMitte(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von links in der Mitte erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameLinkeMitte(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameMitte(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von der Mitte erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameMitte(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ) 
	 || (cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ) 
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameRechteMitte(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von rechts in der Mitte erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameRechteMitte(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe+1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe+2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameUntereLinkeEcke(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von unten links erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameUntereLinkeEcke(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameUntereMitte(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von unten mitte erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameUntereMitte(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite+1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite+2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameUntereRechteEcke(int iBreite,int iHoehe)

   @aufruf: DameUeberpruefeDame()
   @beschreibung: Überprüft, ob die Dame von unten rechts erbeuten kann
   @param iBreite: die x-Koordinate der aktuellen Dame
   @param iHoehe: die y-Koordinate der aktuellen Dame
   @return OK: Die Dame kann erbeuten
   @return NOTOK: Die Dame kann nicht erbeuten
   ========================================================================
*/
int DameUntereRechteEcke(int iBreite,int iHoehe)
{
	if ((cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[1] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ)
	 || (cSpielFeld[iBreite-1][iHoehe-1] == cSpielsteine[3] && cSpielFeld[iBreite-2][iHoehe-2] == SCHWARZ))
	{
		return OK;
	}
	return NOTOK;
}
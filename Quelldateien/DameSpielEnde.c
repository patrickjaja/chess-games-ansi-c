/*
   ============================================================================
   Programmname: DameSpielEnde.c
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
   Funktion DameUeberpruefeSpielende()

   @aufruf: DameSpielen()
   @beschreibung: ruft Funktionen zum Prüfen des Spielendes auf
   @param iEnde: Integer, welcher zur Überprüfung des Spielendes benötigt
				 wird
   @return iEnde: gibt 1 zurück wenn das Spiel zu Ende ist, ansonsten 0
   ========================================================================
*/

int DameUeberpruefeSpielende(int iEnde)
{
	iEnde = DameSteinVorhanden();
	if (iEnde == 0)
	{
		iEnde += DameZugMoeglich();
	}
	return iEnde;
}
/*
   ========================================================================
   Funktion DameSteinVorhanden()

   @aufruf: DameUeberpruefeSpielende()
   @beschreibung: Überprüft, ob noch mindestens ein Stein des aktuellen 
				  Spielers vorhanden ist.		  
   @return OK: gibt OK zurück, falls mindestens ein Stein vorhanden ist
   @return NOTOK: gibt NOTOK zurück, falls kein Stein vorhanden ist
   ========================================================================
*/
int DameSteinVorhanden()
{
	int iBreite;
	int iHoehe;

	for (iHoehe = 0; iHoehe < 8; iHoehe++)
	{
		for (iBreite = 0; iBreite < 8; iBreite++)
		{
			if	((cSpielFeld[iBreite][iHoehe] == cSpielsteine[0]) ||
			 (cSpielFeld[iBreite][iHoehe] == cSpielsteine[2]))
			{
				return OK;
			}
		}
	}
	return NOTOK;
}

/*
   ========================================================================
   Funktion DameZugMoeglich()

   @aufruf: DameUeberpruefeSpielende()
   @beschreibung: überprüft, ob ein eigener Stein oder eine eigene Dame
				  gezogen oder gesprungen werden kann
   @return OK: gibt OK zurück ,falls mit mindestens einem Stein ein Zug 
			   möglich ist
   @return NOTOK, falls kein Zug möglich ist, wird NOTOK zurückgegeben
   ========================================================================
*/
int DameZugMoeglich()
{
	int iBreite;
	int iHoehe;
	int iRueckgabe = 0;

	for (iHoehe = 0; iHoehe < 8; iHoehe++)
	{
		for (iBreite = 0; iBreite < 8; iBreite++)
		{
			if (cSpielFeld[iBreite][iHoehe] == cSpielsteine[0])
			{
				iRueckgabe = DameUeberpruefeSpielstein(iBreite,iHoehe);              
				iRueckgabe *= ZielfeldLeer(iBreite-iSpieler,iHoehe+iSpieler);    
				iRueckgabe *= ZielfeldLeer(iBreite+iSpieler,iHoehe+iSpieler);    
				if (iRueckgabe == 0)
				{
					return OK;
				}
			}
			else
			{	if (cSpielFeld[iBreite][iHoehe] == cSpielsteine[2])
				{
					iRueckgabe = DameUeberpruefeDame(iBreite,iHoehe);              
					iRueckgabe *= ZielfeldLeer(iBreite-iSpieler,iHoehe+iSpieler);    
					iRueckgabe *= ZielfeldLeer(iBreite+iSpieler,iHoehe+iSpieler);    
					iRueckgabe *= ZielfeldLeer(iBreite-iSpieler,iHoehe-iSpieler);    
					iRueckgabe *= ZielfeldLeer(iBreite+iSpieler,iHoehe-iSpieler); 
					if (iRueckgabe == 0)
					{
						return OK;
					}
				}
			}
		}
	}
	return NOTOK;
}



/*
   ============================================================================
   Programmname: DameSpielEnde.c
   Autor       : Andreas Danek, Daniel Jan�en
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Funktionen
   ============================================================================
*/

/*
============================================================================
Pr�prozessoranweisungen
============================================================================
*/

#include "Funktionen.h"

/*
   ========================================================================
   Funktion DameUeberpruefeSpielende()

   @aufruf: DameSpielen()
   @beschreibung: ruft Funktionen zum Pr�fen des Spielendes auf
   @param iEnde: Integer, welcher zur �berpr�fung des Spielendes ben�tigt
				 wird
   @return iEnde: gibt 1 zur�ck wenn das Spiel zu Ende ist, ansonsten 0
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
   @beschreibung: �berpr�ft, ob noch mindestens ein Stein des aktuellen 
				  Spielers vorhanden ist.		  
   @return OK: gibt OK zur�ck, falls mindestens ein Stein vorhanden ist
   @return NOTOK: gibt NOTOK zur�ck, falls kein Stein vorhanden ist
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
   @beschreibung: �berpr�ft, ob ein eigener Stein oder eine eigene Dame
				  gezogen oder gesprungen werden kann
   @return OK: gibt OK zur�ck ,falls mit mindestens einem Stein ein Zug 
			   m�glich ist
   @return NOTOK, falls kein Zug m�glich ist, wird NOTOK zur�ckgegeben
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



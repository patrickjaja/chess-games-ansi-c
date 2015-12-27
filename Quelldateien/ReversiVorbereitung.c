/*
   ============================================================================
   Programmname: ReversiVorbereitung.c
   Autor       : Jakob Bohr, Gilles Meyer, Andreas Danek, Daniel Janßen
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
   Funktion ReversiSetzeStartPosition()

   @aufruf: main()
   @beschreibung: belegt das Spielfeld mit Figuren in der vorgegebenen
				  Startposition
   @return OK: gibt OK zurück wenn alles erfolgreich war
   ========================================================================
*/
int ReversiSetzeStartPositionen()
{
	cSpielFeld[3][3] = BLAU;
	cSpielFeld[4][3] = ROT;
	cSpielFeld[3][4] = ROT;
	cSpielFeld[4][4] = BLAU;

	return OK;
}
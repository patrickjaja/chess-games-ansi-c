/* 
Autor : Linda von Groote
Klasse : FI12
Dateiname : SpielerBewertung.c
Datum : 16. März 2009
*/

#include "Funktionen.h"


void spielerBewertung( int iSpielTyp, int iGewonnen)
/* Ruft die Berechnung der neuen Elo-Zahlen für den jeweiligen Gewinner des Spiels auf.
1. iSpielTyp : Typ des gespielten Spiels (z. B. Vier gewinnt)
2. iGewonnen : Gewinner des Spiels (z. B Spieler 2)
*/
{
   double dElo1;	   /* Alte Elo-Zahl für Spieler1 */
   double dElo2;       /* Alte Elo-Zahl für Spieler2 */
   double dBNeu1=0;    /* Neue Elo-Zahl für Spieler1 */
   double dBNeu2=0;    /* Neue Elo-Zahl für Spieler2 */
   double dPunkte=0;   /* erreichte Punkte pro Spiel */

   /* Alte Elo-Zahlen aus Statistik-Datei auslesen */
   dElo1 = StatistikLeseWert(1, iSpielTyp, 4);	
   dElo2 = StatistikLeseWert(2, iSpielTyp, 4);

   switch(iGewonnen){

	   /* Spieler1 gewinnt */
       case 1: 

           dBNeu1 = eloBerechnungSp1(dElo1, dElo2, 1.0);
           dBNeu2 = eloBerechnungSp2(dElo2, dElo1, 0.0);
			
		   if(dBNeu1 < 0)
		   {
			   dBNeu1 = 0;
		   }
		   if(dBNeu2 < 0)
		   {
			   dBNeu2 = 0;
		   }

           /* neue Werte im User array speichern: */
           StatistikAenderElo(1,iSpielTyp,dBNeu1);
           StatistikAenderElo(2,iSpielTyp,dBNeu2);

           break;

       /* Spiel unentschieden */
       case 0:   
			
           dBNeu1 = eloBerechnungSp1(dElo1, dElo2, 0.5);
           dBNeu2 = eloBerechnungSp2(dElo2, dElo1, 0.5);
			
		   if(dBNeu1 < 0)
		   {
			   dBNeu1 = 0;
		   }
		   if(dBNeu2 < 0)
		   {
			   dBNeu2 = 0;
		   }

           /* neue Werte im User array speichern: */
		   StatistikAenderElo(1,iSpielTyp,dBNeu1);
           StatistikAenderElo(2,iSpielTyp,dBNeu2);

           break;

       /* Spieler2 gewinnt */
       case -1:

           dBNeu1 = eloBerechnungSp1(dElo1, dElo2, 0.0);
           dBNeu2 = eloBerechnungSp2(dElo2, dElo1, 1.0);
			
		   if(dBNeu1 < 0)
		   {
			   dBNeu1 = 0;
		   }
		   if(dBNeu2 < 0)
		   {
			   dBNeu2 = 0;
		   }

           /* neue Werte im User array speichern: */
		
           StatistikAenderElo(1,iSpielTyp,dBNeu1);
           StatistikAenderElo(2,iSpielTyp,dBNeu2);

           break;        
    }
        
}

double eloBerechnungSp1(double dElo1, double dElo2, double dPunkte)
/* Berechnet die neuen Elo-Zahlen und schreibt sie in die Statistik-Datei.
1. dElo1 : Alte Elo-Zahl von Spieler1
2. dElo2 : Alte Elo-Zahl von Spieler2
3. dPunkte : erreichte Punkte für das aktuelle Spiel
*/
{
   double dBDelta=0;        /* Differenz der Elo-Zahlen beider Spieler */
   double dErgErwartet=0;   /* erwarteter Elo-Wert */
   double dBNeu1=0;         /* neue errechneter Elo-Wert */
   double dTest=0;
        
   /* Bewertungsdifferenz */ 
   dBDelta = dElo1 - dElo2;

   /* Erwartungswert */ 
   if(dBDelta <0){

      dErgErwartet =   pow(0.5, (-dBDelta/201));  

    }
   else{

      dErgErwartet  = 1-(pow(0.5, dBDelta/201)); 

       }

   dTest=dBDelta/201;

   /* Berechnung der neuen Bewertung */
   dBNeu1 = dElo1 + (50*(dPunkte - dErgErwartet));

   return dBNeu1;

}

double eloBerechnungSp2(double dElo2, double dElo1, double dPunkte){

   double dBDelta=0;                    /* Differenz der Elo-Zahlen beider Spieler */
   double dErgErwartet=0;               /* erwarteter Elo-Wert */
   double dBNeu2=0;                     /* neue errechneter Elo-Wert */
        
 
   /* Bewertungsdifferenz */ 
   dBDelta = dElo2 - dElo1;

   /* Erwartungswert */ 
   if(dBDelta <0){
      dErgErwartet =   pow(0.5, (-dBDelta/201));        
    }
    else{
       dErgErwartet  = 1-(pow(0.5, dBDelta/201));        
    }

   /* Berechnung der neuen Bewertung */
   dBNeu2 = dElo2 + 50*(dPunkte - dErgErwartet);

   return dBNeu2;

}
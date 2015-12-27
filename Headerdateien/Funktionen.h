/*
   ============================================================================
   Programmname: Funktionen.h
   Autor       : David Frerich, Andreas Danek, Daniel Janßen, Gilles Meyer
   Datum       : 18.03.2009
   Thema       : Projektarbeit
   Version     : 1.0
   Programmschnittstelle: Header
   ============================================================================
*/

#if !defined (FUNKTIONEN_H)
#define FUNKTIONEN_H

#define _CRT_SECURE_NO_DEPRECATE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define OK				0 
#define ENDE			1
#define NOTOK			1
#define UNENTSCHIEDEN	2
#define AUFGABE			2
#define SCHWARZ			'\xFF'
#define WEISS			'\xDB'
#define ROT				'\xB1'
#define BLAU			'\xB2'
#define HBLAU			'\xB3'
#define PINK			'\xB4'

/* 
   ============================================================================
   Konfiguration Login, Registrierung und Menüs 
   ============================================================================
 */
#define LRM_H
#define L_ZEILE 80   /* Zeichen Zeile */
#define ANZAHL 100 /* Max Zeilen */
#define pfad "users.txt" /* Pfad zur Datei */
#define L_NAME 20 /* Max Zeichen Name */
#define L_PASS 15  /* Max Zeichen Passworts */
#define S_PASS 1 /* Min Zeichen Pass */
#define S_NAME 3 /* Min Zeichen Name */
#define line '\xB1'  /* Trennbalken unterhalb des Menüs */
#define CDclose 3   /* Cooldown bis entgültiger Close */
#define CRYPT_KEY 8 /* Wird mit dieser Zahl verschlüsselt, möglich wäre auch HEX */
#define L_PUNKT 10 /* maximal angezeigte Ziffern */
#define P_SICHER 5 /* Anzahl Zeichen für ein sicheres Passwort */

/*
   ========================================================================
   Globale Variablen
   ========================================================================
*/
char cSpielsteine[4];
char cSpielFeld[17][17];
int iSpieler;
int iErbeuten[48][2];
int iSteinStehtIn[1][2];

int iNrLetzteZeile; /* enthält die letzte Zeile der Textdatei */
char cArrayUser[ANZAHL][L_ZEILE][100];
char cSeparator[2];
int iSpielerID;
int iSpielerID2;
char *cToken;
char cLoginName1[L_NAME];
char cLoginName2[L_NAME];
char cLoginPasswort1[L_PASS];
char cLoginPasswort2[L_PASS];

int iStatistikLetzteZeile;
char cStatistikTokens[ANZAHL][L_ZEILE][100];
char cArrayUser[ANZAHL][L_ZEILE][100];

/* 
   ============================================================================
   Funktionsprototypen
   ============================================================================ 
*/

int ErstelleSpielFeld(int x, int y);
int ZeichneFeld(int x, int y);
int ZielfeldLeer(int ixZiel,int iyZiel);
int Spieler();
int PositionEingeben(int *iXKoordReturn, int *iYKoordReturn, int iBreite, int iHoehe, int iNurSteine);
int SpielErgebnis(int iEnde, int iGewinner);

int Bridges();
int BridgesSetzeSpielFeld();
int BridgesSpielen();
int BridgesUeberpruefe();
int BridgesUeberpruefeSpielerSieg(char cFarbe, int iVonBis);

int Reversi();
int ReversiSpielen(int iKeinzugmoeglich);
int ReversiPruefeObSteinGesetztWerdenKann();
int ReversiSteinSetzen(int ixKoordinate, int iyKoordinate);
int ReversiUeberpruefeSpielfeldVoll();
int ReversiUeberpruefeZugMoeglich();
int ReversiZaehleSteine();
int ReversiSetzeStartPositionen();
int ReversiUeberpruefeGueltigeStelle(int ixKoordinate, int iyKoordinate);
int ReversiSteineDrehen(int ixKoordinate, int iyKoordinate);
int ReversiUeberpruefeReiheAufEigenenSteinNachLinks(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachRechts(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachOben(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachLinksOben(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachLinksUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachRechtsOben(int ixKoordinate, int iyKoordinate, int iDrehe_um);
int ReversiUeberpruefeReiheAufEigenenSteinNachRechtsUnten(int ixKoordinate, int iyKoordinate, int iDrehe_um);

int VierGewinnt(void);
int VierGewinntSpielen();
int VierGewinntSteinSetzen();
int VierGewinntUeberpruefeVierInReihe(int ixKoordinate, int iyKoordinate);
int VierGewinntPruefeWaagerecht(int ixKoordinate, int iyKoordinate);
int VierGewinntPruefeSenkrecht(int ixKoordinate, int iyKoordinate);
int VierGewinntPruefeDiagonalLinksUntenRechtsOben(int ixKoordinate, int iyKoordinate);
int VierGewinntPruefeDiagonalLinksObenRechtsUnten(int ixKoordinate, int iyKoordinate);
int VierGewinntUeberpruefeSpielfeldVoll();

int Dame(void);
int DameUeberpruefeSpielende(int iEnde);
int DameSteinVorhanden();
int DameZugMoeglich();
int DameSpielen();
int DameSteinSetzen();
int DameSpringen(int iErsterSprung);
int DameKannSteinBewegtWerden(int ixKoordinate,int iyKoordinate, int iRueckgabe);
int DameAusgewaehlterSteinVorhanden(int ixKoordinate,int iyKoordinate);
int DameBewegeStein(int ixKoordinate,int iyKoordinate,int ixZiel,int iyZiel);
int DameBelegeZielStein(int *ixZielReturn, int *iyZielReturn, int ixKoordinate, int iyKoordinate);
int DameBelegeZielDame(int *ixZielReturn, int *iyZielReturn, int ixKoordinate, int iyKoordinate);
int DameGueltigerSprung(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate);
int DameGueltigerSprungDame(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate);
int DameKannGesprungenerSteinNochEinmalSpringen();
int DameSchlageStein(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate);
int DameTausch(int ixZiel,int iyZiel,int ixKoordinate,int iyKoordinate);
int DameSetzeStartPosition();
int DameiErbeutenBelegen();
int DameErbeuten();
int DameUeberpruefeSpielstein(int iBreite,int iHoehe);
int DameUeberpruefeDame(int iBreite,int iHoehe);
int DameUntereRechteEcke(int iBreite,int iHoehe);
int DameUntereMitte(int iBreite,int iHoehe);
int DameUntereLinkeEcke(int iBreite,int iHoehe);
int DameRechteMitte(int iBreite,int iHoehe);
int DameMitte(int iBreite,int iHoehe);
int DameLinkeMitte(int iBreite,int iHoehe);
int DameObereRechteEcke(int iBreite,int iHoehe);
int DameObereMitte(int iBreite,int iHoehe);
int DameObereLinkeEcke(int iBreite,int iHoehe);
int DamePruefeSteinIniErbeuten(int ixKoordinate,int iyKoordinate);
int DameiErbeutenBelegenWert(int iBreite, int iHoehe, int iArrayZaehler);


void RegistrierungNameEingabe(void);
void ArrayAusgeben(void);
void Verschluesseln(char string[],int key);
void FarbigerBalken (int farbe);
void InfoKopfzeile(char cLoginName1[L_NAME], char cLoginName2[L_NAME], char cPunkte1[L_PUNKT], char cPunkte2[L_PUNKT]);
void HauptMenu (void);
void RegistrierungNameEingabe2(void);
int RegistrierungPasswortEingabe2(void);
int LoginEingabeName2(void); /* Login iSpieler2 (Mitspieler) */
int LoginPasswort2(int iSpielerID);
int LoginEingabeName1(void); /* Login iSpieler1 */
int LoginPasswort1(int iSpielerID);
int RegistrierungPasswortEingabe(void);
int LeseZerlegeDatei(void); /* füllt das cArrayUser Array */
int SchreibeDatei(void);
int Spielmenu(int iSpieler1, int iSpieler2);
char *GetPasswort(char *cPasswort); /* ersetzt die Eingabe durch einen Platzhalter */

int StatistikLaden(void);
int StatistikSelbst(void);
int StatistikAlle(void);
int StatistikSchreiben(void);
int StatistikNeu(void);
int StatistikAendern(int iSpieler,int iSpiel, int iResultate);
int StatistikAenderElo(int iSpieler, int iSpiel, double dWert);
double StatistikLeseWert(iSpielerNr, iSpielId, iWert);
int StatistikNewStats(int iZahl, int iSpiel);
int StatistikAuswahlMenu(void);

void spielerBewertung( int iSpielTyp, int iGewonnen);
double eloBerechnungSp1(double dElo1, double dElo2, double dPunkte);
double eloBerechnungSp2(double dElo2, double dElo1, double dPunkte);

void color(int color);
#endif
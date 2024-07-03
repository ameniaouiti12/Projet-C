#ifndef GESTIONRDV_H_INCLUDED
#define GESTIONRDV_H_INCLUDED
#include <gtk/gtk.h>
typedef struct {
 int jj;
 int mm;
 int yy;

}DateD;
typedef struct {
  char  id[50] ;
  char Cin[50];
  char etab[50];
  DateD dateRdv;
  char nom[50] ;
  char type[50];
  char genre[50];
  char question[50];
}Donneur;
typedef struct{
    int id;
    char nom[50];
    char adresse[50];
    int capacite;
    char region[50];
    int telephone;
}etsN;

void afficherDonneur(GtkWidget *liste, char *filename);
void rechercherDonneur(GtkWidget *liste, char *filename,char *id[50]);
void listeRdvTreeView(GtkWidget *liste,char *filename,char *etab,int jj,int mm, int yy);
void viderDonneur(GtkWidget *liste);
int ajouterDonneur(char *, Donneur );
int modifierDonneur( char *, char *, Donneur );
int supprimerDonneur(char *, char* );
Donneur chercherDonneur(char *, char *);
int listeRDV(char *,char *,int , int ,int,Donneur *);
int nbEts(char *);
float moyRDV_ETS(char * , char * , int , int , int );
#endif // GESTIONRDV_H_INCLUDED

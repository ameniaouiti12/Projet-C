#ifndef GESTIONDONS_H_INCLUDED
#define GESTIONDONS_H_INCLUDED
#include <gtk/gtk.h>
typedef struct{
int jj;
int mm;
int yy;

}Dategh;
typedef struct {
char id[50];
char cinDonneur[50];
char typeSang[50];
int quantite;
Dategh date;

char tattou[50];
char fumeur[50];
char alcool[50];


}Dons;
void afficherDons(GtkWidget *liste, char *filename);
void viderDons(GtkWidget *liste);
void rechercherDons(GtkWidget *liste, char *filename,char *id);
int ajouterDons(char *filename, Dons d );
int modifierDons( char *filename, char *id, Dons nouv );
int supprimerDons(char *filename,char *id);
Dons rechercheDons(char *filename,char *id);
int quantite_type(char *filename, char *type);
char* sang_rare(char *filename);

#endif // GESTIONDONS_H_INCLUDED

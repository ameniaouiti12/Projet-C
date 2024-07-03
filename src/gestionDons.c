#include "gestionDons.h"
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

enum{EID,
     ECIN,
     ETYPE,
     EQAUNTITE,
     EDATEJJ,
     EDATEMM,
     EDATEYY,
     ETATOU,
     EFUMEUR,
     EALCOL,
     COLUMNS
      };

void rechercherDons(GtkWidget *liste, char *filename,char *id){

GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Dons d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin donneur", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   
           renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQAUNTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question1", renderer, "text", ETATOU, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question2", renderer, "text", EFUMEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question3", renderer, "text", EALCOL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);




       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {
         if(strcmp(d.id,id)==0){
         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  ECIN, d.cinDonneur,ETYPE,d.typeSang,EQAUNTITE,quantite, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,ETATOU,d.tattou,EFUMEUR,d.fumeur,EALCOL,d.alcool,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }









}

void afficherDons(GtkWidget *liste, char *filename){

GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Dons d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin donneur", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   
           renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQAUNTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question1", renderer, "text", ETATOU, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question2", renderer, "text", EFUMEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question3", renderer, "text", EALCOL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     


              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {

         sprintf(jj,"%d",d.date.jj);
         sprintf(mm,"%d",d.date.mm);
         sprintf(yy,"%d",d.date.yy);
          sprintf(quantite,"%d",d.quantite);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, d.id,  ECIN, d.cinDonneur,ETYPE,d.typeSang,EQAUNTITE,quantite, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,ETATOU,d.tattou,EFUMEUR,d.fumeur,EALCOL,d.alcool,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }










}

void viderDons(GtkWidget *liste){


GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50],quantite[50];
    store = NULL;
   Dons d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

       

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin donneur", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type sang", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

   
           renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("quantité", renderer, "text", EQAUNTITE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EDATEJJ, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EDATEMM, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Année", renderer, "text", EDATEYY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
          renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question1", renderer, "text", ETATOU, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question2", renderer, "text", EFUMEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       

         renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("question3", renderer, "text", EALCOL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



       

        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);









}
int ajouterDons(char *filename, Dons d ){

     FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.tattou,d.fumeur,d.alcool);
        fclose(f);
        return 1;
    }
    else return 0;





}

int modifierDons( char *filename, char *id, Dons nouv ){

     int tr=0;
    Dons d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {
            if(strcmp(d.id,id)==0)
            {
                fprintf(f2,"%s %s %s %d %d %d %d %s %s %s\n",nouv.id,nouv.cinDonneur,nouv.typeSang,nouv.quantite,nouv.date.jj,nouv.date.mm,nouv.date.yy,nouv.tattou,nouv.fumeur,nouv.alcool);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.tattou,d.fumeur,d.alcool);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;





}


int supprimerDons(char *filename,char *id){

    int tr=0;
    Dons d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {
            if(strcmp(d.id,id)==0)
            {

                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,d.quantite,d.date.jj,d.date.mm,d.date.yy,d.tattou,d.fumeur,d.alcool);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;









}


Dons rechercheDons(char *filename,char *id){

Dons d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {
            if(strcmp(d.id,id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(d.id,"-1");
    return d;




}

int quantite_type(char *filename, char *type){

    Dons d;
   int quantiteTotale=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %d %d %d %d %s %s %s\n",d.id,d.cinDonneur,d.typeSang,&d.quantite,&d.date.jj,&d.date.mm,&d.date.yy,d.tattou,d.fumeur,d.alcool)!=EOF)
        {


            if (strcmp(d.typeSang, type) == 0)
            {
               quantiteTotale+=d.quantite;
            }




        }

    }
    fclose(f);

     return quantiteTotale;






}




char* sang_rare(char *filename){

char typesSangConnus[][5] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};

    int minQuantite = 1000;
    char sangRare[5] = "";

         for(int i =0; i<8;i++){

            int quantite = quantite_type(filename,typesSangConnus[i]);
             if ( quantite < minQuantite && quantite!=0){
            minQuantite = quantite;
            strcpy(sangRare, typesSangConnus[i]);
            }








}
  char *resultat = (char *)malloc((strlen(sangRare) + 1) * sizeof(char));

   strcpy(resultat,sangRare);
return resultat;








    }



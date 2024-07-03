#include "ficheDonneur.h"
#include<stdio.h>
#include<string.h>


enum{EID,
     ECIN,
     EETAB,
     EDATEJJ,
     EDATEMM,
     EDATEYY,
     ENOM,
     ETYPE,
     EGENRE,
     EQUESTION,
     COLUMNS
      };

void listeRdvTreeView(GtkWidget *liste,char *filename,char *etab,int jj,int mm, int yy){

          GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj1[50],mm1[50],yy1[50];
    store = NULL;
   
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	 
	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
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
        column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

      
      
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
 renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("question", renderer, "text", EQUESTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	 renderer = gtk_cell_renderer_text_new();
        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);


     

              Donneur d;
              f = fopen(filename, "r");

    if (f == NULL)
    {
        return;
    }
    else
    {
       
        while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.etab,etab)==0 && d.dateRdv.jj== jj  && d.dateRdv.mm == mm && d.dateRdv.yy == yy){
         sprintf(jj1,"%d",d.dateRdv.jj);
         sprintf(mm1,"%d",d.dateRdv.mm);
         sprintf(yy1,"%d",d.dateRdv.yy);
        
        





            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,   &iter,ENOM,d.nom, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EGENRE,d.genre, EID, d.id, ECIN, d.Cin, EETAB, d.etab,ETYPE,d.type,EQUESTION,d.question,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }





}
void rechercherDonneur(GtkWidget *liste, char *filename,char *id[50]){
GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   Donneur d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        
	 renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
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
        column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

      
      
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
 renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("question", renderer, "text", EQUESTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	 renderer = gtk_cell_renderer_text_new();


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
       
        while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.id,id)==0){
         sprintf(jj,"%d",d.dateRdv.jj);
         sprintf(mm,"%d",d.dateRdv.mm);
         sprintf(yy,"%d",d.dateRdv.yy);
     
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,  &iter,ENOM,d.nom, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EGENRE,d.genre, EID, d.id, ECIN, d.Cin, EETAB, d.etab,ETYPE,d.type,EQUESTION,d.question,-1);}
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }

}
void viderDonneur(GtkWidget *liste){

   
     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   Donneur d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
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
        column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

      
      
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
 renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("question", renderer, "text", EQUESTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	 renderer = gtk_cell_renderer_text_new();



        // La liste contient 7 colonnes de type chaine de caractères
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

}
void afficherDonneur(GtkWidget *liste, char *filename){


     GtkCellRenderer *renderer; // afficheur de cellule (Cellule contient un texte, image, case à cocher)
      GtkTreeViewColumn *column; // visualisation des colonnes
       GtkTreeIter iter;          /**/
       GtkListStore *store;       // création du modèle de type liste

  char jj[50],mm[50],yy[50];
    store = NULL;
   Donneur d;
    FILE *f;
    store = gtk_tree_view_get_model(liste);
    if (store == NULL)
    {
	  renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
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
        column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text", EGENRE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	
        renderer=gtk_cell_renderer_text_new();                                                               // cellule contenant du texte
        column = gtk_tree_view_column_new_with_attributes("Id ", renderer, "text", EID, NULL); // création d'une colonne avec du texte
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);                                             // associer la colonne à l'afficheur (GtkTreeView)

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("etablissement", renderer, "text", EETAB, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

      
      
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        
 renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("question", renderer, "text", EQUESTION, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	 renderer = gtk_cell_renderer_text_new();


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
       
        while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {

         sprintf(jj,"%d",d.dateRdv.jj);
         sprintf(mm,"%d",d.dateRdv.mm);
         sprintf(yy,"%d",d.dateRdv.yy);
      

            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store,  &iter,ENOM,d.nom, EDATEJJ, jj, EDATEMM, mm, EDATEYY, yy,EGENRE,d.genre, EID, d.id, ECIN, d.Cin, EETAB, d.etab,ETYPE,d.type,EQUESTION,d.question,-1);
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }


}
int ajouterDonneur(char *filename, Donneur d)
{

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question);
        fclose(f);
        return 1;
    }
    else return 0;


}


int modifierDonneur( char *filename, char *id, Donneur nouv)
{

    int tr=0;
    Donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.id, id)==0)
            {
                fprintf(f2,"%s %d %d %d %s %s %s %s %s %s\n",nouv.nom,&nouv.dateRdv.jj,&nouv.dateRdv.mm,&nouv.dateRdv.yy,nouv.genre,nouv.id,d.Cin,nouv.etab,nouv.type,nouv.question);
                tr=1;
            }
            else
                fprintf(f2,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}


int supprimerDonneur(char *filename, char *id)
{


    int tr=0;
    Donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.id, id)==0)
                tr=1;
            else
                fprintf(f2,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;


}

Donneur chercherDonneur(char *filename, char *id )
{

    Donneur d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.id, id)==0)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(d.id,"-1");
    return d;


}


int listeRDV(char *filename,char *etab,int jj, int mm,int yy,Donneur *resultat)
{

    Donneur d;

    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if(strcmp(d.etab, etab) == 0  && d.dateRdv.jj == jj && d.dateRdv.mm == mm && d.dateRdv.yy == yy)
            {
                resultat[i] = d;
                i++;
            }
        }
    }
    fclose(f);
    return i;


}


int nbEts(char *filename)
{
    etsN e;

    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%d %s %s %d %s %d\n",&e.id,e.nom,e.adresse,&e.capacite,e.region,&e.telephone)!=EOF)
        {


            i++;

        }
    }
    fclose(f);
    return i;

}



float moyRDV_ETS(char *filename1 , char *filename , int jj , int mm, int yy ){

      Donneur d;
    float moyenne = 0;
    int i = 0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %d %d %d %s %s %s %s %s %s\n",d.nom,&d.dateRdv.jj,&d.dateRdv.mm,&d.dateRdv.yy,d.genre,d.id,d.Cin,d.etab,d.type,d.question)!=EOF)
        {
            if( d.dateRdv.jj == jj && d.dateRdv.mm == mm && d.dateRdv.yy == yy)
            {

                i++;
            }
        }
    }
    fclose(f);
      int nb = nbEts(filename1);

     if (i > 0){
        moyenne = (float)i / (float)nb;
        return (float)moyenne;
      }

       return moyenne;

}

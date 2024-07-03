#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "ficheDonneur.h"
#include "gestionDons.h"
#include "gestionEts.h"
int g ;
int g1;
char filename1[50] = "ameni.txt";
void
on_Ameni_Ajouter_Utilisateur_clicked   (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_ajout_Utilisateur,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    espace_ajout_Utilisateur = lookup_widget(button,"espace_ajout_Utilisateur");
      espace_ajout_Utilisateur = create_espace_ajout_Utilisateur();
     gtk_widget_show(espace_ajout_Utilisateur);
}


void
on_Ameni_Modifier_Utilisateur_clicked  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_modif_Utilisateur,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    espace_modif_Utilisateur = lookup_widget(button,"espace_modif_Utilisateur");
      espace_modif_Utilisateur = create_espace_modif_Utilisateur();
     gtk_widget_show(espace_modif_Utilisateur);
}


void
on_Ameni_Supprimer_Utilisateur_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_supprimer_Utilisateur,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    espace_supprimer_Utilisateur = lookup_widget(button,"espace_supprimer_Utilisateur");
      espace_supprimer_Utilisateur = create_espace_supprimer_Utilisateur();
     gtk_widget_show(espace_supprimer_Utilisateur);
}


void
on_Ameni_Afficher_Utilisateur_clicked  (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Afficher_Utilisateur,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
     espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
     gtk_widget_show(espace_Afficher_Utilisateur);
}

void
on_UstatistiqueWidget_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Statistique_Utilisateur,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    espace_Statistique_Utilisateur = lookup_widget(button,"espace_Statistique_Utilisateur");
     espace_Statistique_Utilisateur = create_espace_Statistique_Utilisateur();
     gtk_widget_show(espace_Statistique_Utilisateur);
}

void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=1;} 
}


void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=2;}
}


void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	 GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UmdpEntryAjout");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpAjout");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}

void
on_UajoutButton_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*espace_ajout_Utilisateur,*label,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
   int b = 1;
   utilisateur u;
   espace_ajout_Utilisateur = lookup_widget(button,"espace_ajout_Utilisateur");
           espace_ajout_Utilisateur = create_espace_ajout_Utilisateur();
  cin = lookup_widget(button,"UcinEntryAjout");
  nom =lookup_widget(button,"UnomEntryAjout");
  prenom = lookup_widget(button,"UprenomEntryAjout");
  jj = lookup_widget(button,"UjjSpinAjout");
  mm = lookup_widget(button,"UmmSpinAjout");
  yy = lookup_widget(button,"UyySpinAjout");
  region = lookup_widget(button,"UregionComboAjout");
  num = lookup_widget(button,"UnumEntryAjout");
  role = lookup_widget(button,"UroleComboAjout");
  login = lookup_widget(button,"UloginEntryAjout");
  mdp = lookup_widget(button,"UmdpEntryAjout");
  label = lookup_widget(button,"UcontroleSaisiAjout");    

  strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
  u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
  u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));

    if(g == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  ajouterUtilisateur("ameni.txt",u);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
          		 gtk_widget_destroy(espace_ajout_Utilisateur);
              espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
            espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
             gtk_widget_show(espace_Afficher_Utilisateur);
                 w1=lookup_widget(button,"espace_Afficher_Utilisateur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "ameni.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }

   
}

void
on_Retour_Ajout_Admin_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
     GtkWidget *espace_ajout_Utilisateur,*espace_admin;
     espace_ajout_Utilisateur= lookup_widget(button,"espace_ajout_Utilisateur");
   gtk_widget_destroy(espace_ajout_Utilisateur);
    espace_admin = lookup_widget(button,"espace_admin");
     espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}


void
on_UbuttonRechercherIDModifier_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*espace_modif_Utilisateur,*label,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
   int b = 1;
   utilisateur u;
   char cin1[50];
  espace_modif_Utilisateur = lookup_widget(button,"espace_modif_Utilisateur");
           espace_modif_Utilisateur = create_espace_modif_Utilisateur();
  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");

  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier");   
  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 



     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }

         if(b == 1){

     u =  chercherUtilisateurByCin("ameni.txt", cin1);
       if(strcmp(u.Cin,"-1")==0){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(cin),"");
               break;}

          }else{
                 
                 
              gtk_entry_set_text(GTK_ENTRY(cin),u.Cin);
                  gtk_entry_set_text(GTK_ENTRY(nom),u.nom);
                  gtk_entry_set_text(GTK_ENTRY(prenom),u.prenom);
                  gtk_entry_set_text(GTK_ENTRY(num),u.num);
                  gtk_entry_set_text(GTK_ENTRY(login),u.login);
                  gtk_entry_set_text(GTK_ENTRY(mdp),u.mpd);
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre Cin   ❌️");

       }
      

}


void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=1;} 

}


void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{g1=2;}

}


void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	GtkWidget *pass,*buttoncheck;
       pass = lookup_widget(togglebutton, "UafficherMdpModifier");
     buttoncheck = lookup_widget(togglebutton,"UafficherMdpModifier");
   
    if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(buttoncheck))){
       gtk_entry_set_visibility(pass,TRUE);
   }else{
       gtk_entry_set_visibility(pass,FALSE);
   }
}


void
on_Retour_Modif_Admin_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *espace_modif_Utilisateur,*espace_admin;
     espace_modif_Utilisateur= lookup_widget(button,"espace_modif_Utilisateur");
   gtk_widget_destroy(espace_modif_Utilisateur);
    espace_admin = lookup_widget(button,"espace_admin");
     espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}


void
on_UModifierButton_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *cin,*nom,*prenom,*jj,*mm,*yy,*region,*num,*role,*login,*mdp,*espace_modif_Utilisateur,*label,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
   int b = 1;
   utilisateur u;
   espace_modif_Utilisateur = lookup_widget(button,"espace_modif_Utilisateur");
           espace_modif_Utilisateur = create_espace_modif_Utilisateur();
  cin = lookup_widget(button,"UcinEntryModifier");
  nom =lookup_widget(button,"UnomEntryModifier");
  prenom = lookup_widget(button,"UprenomEntryModifier");
  jj = lookup_widget(button,"UjjSpinModifier");
  mm = lookup_widget(button,"UmmSpinModifier");
  yy = lookup_widget(button,"UyySpinModifier");
  region = lookup_widget(button,"UregionComboModifier");
  num = lookup_widget(button,"UnumEntryModifier");
  role = lookup_widget(button,"UroleComboModifier");
  login = lookup_widget(button,"UloginEntryModifier");
  mdp = lookup_widget(button,"UmdpEntryModifier");
  label = lookup_widget(button,"UcontroleSaisiModifier"); 
 
strcpy(u.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
  u.dateNaissance.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        u.dateNaissance.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        u.dateNaissance.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
  strcpy(u.Region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
  strcpy(u.num,gtk_entry_get_text(GTK_ENTRY(num)));
   strcpy(u.Role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
   strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
   strcpy(u.mpd,gtk_entry_get_text(GTK_ENTRY(mdp)));  

 if(g == 1){
     strcpy(u.genre,"Homme");
  }else{
       strcpy(u.genre,"Femme");

    }

     if(strcmp(u.Cin,"")==0 ){
      
           b=0;
             }
       if(strcmp(u.nom,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.prenom,"")==0 ){
      
           b=0;
             }
      if(strcmp(u.Region,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.num,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.Role,"")==0 ){
      
           b=0;
             }
        if(strcmp(u.login,"")==0 ){
      
           b=0;
             }
          if(strcmp(u.mpd,"")==0 ){
      
           b=0;
             }
          
                 if(b == 1){
       int t =  modifierUtilisateur("ameni.txt",u.Cin,u);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifier Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(prenom),"");
                  gtk_entry_set_text(GTK_ENTRY(num),"");
                  gtk_entry_set_text(GTK_ENTRY(login),"");
                  gtk_entry_set_text(GTK_ENTRY(mdp),"");
                  
          		 gtk_widget_destroy(espace_modif_Utilisateur);
              espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
             espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
             gtk_widget_show(espace_Afficher_Utilisateur);
                 w1=lookup_widget(button,"espace_Afficher_Utilisateur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview, "ameni.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed modifier  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     } 

}


void
on_UsupprimerButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	  GtkWidget *cin,*espace_supprimer_Utilisateur,*label,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
      int b = 1;
    char cin1[50];
   espace_supprimer_Utilisateur = lookup_widget(button,"espace_supprimer_Utilisateur");
           espace_supprimer_Utilisateur = create_espace_supprimer_Utilisateur();
  cin = lookup_widget(button,"UidEntrySupprimer");
 
  label = lookup_widget(button,"UcontroleSaisiSupprimer");    

  strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
 
  

     if(strcmp(cin1,"")==0 ){
      
           b=0;
             }
      
          
                 if(b == 1){
       int t =  supprimerUtilisateur("ameni.txt",cin1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimer  Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  
                  
          		 gtk_widget_destroy(espace_supprimer_Utilisateur);
              espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
             espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
             gtk_widget_show(espace_Afficher_Utilisateur);
                 w1=lookup_widget(button,"espace_Afficher_Utilisateur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview,"ameni.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
}


void
on_UannulerSupprimerButton_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *espace_supprimer_Utilisateur,*espace_admin;
     espace_supprimer_Utilisateur= lookup_widget(button,"espace_supprimer_Utilisateur");
   gtk_widget_destroy(espace_supprimer_Utilisateur);
     espace_admin = lookup_widget(button,"espace_admin");
     espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}


void
on_FDstatistiqueButton_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *labelHomme,*labelFemme,*espace_Statistique_Utilisateur;
       char homme[50],femme[50];
     espace_Statistique_Utilisateur = lookup_widget(button,"espace_Statistique_Utilisateur");
     espace_Statistique_Utilisateur = create_espace_Statistique_Utilisateur();
       labelHomme  = lookup_widget(button,"UpourcentageHommeLabelStatistique");
        labelFemme = lookup_widget(button,"UpourcentageFemmeLabelStatistique");
       float nbH ,nbF;
     afficherPourcentageParSexe("ameni.txt",&nbH,&nbF);
    sprintf(homme,"%.2f",nbH);
    sprintf(femme,"%.2f",nbF);

     gtk_label_set_text(GTK_LABEL(labelHomme),homme);
     gtk_label_set_text(GTK_LABEL(labelFemme),femme);
}


void
on_Retour_Stat_Admin_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *espace_Statistique_Utilisateur,*espace_admin;
     espace_Statistique_Utilisateur= lookup_widget(button,"espace_Statistique_Utilisateur");
   gtk_widget_destroy(espace_Statistique_Utilisateur);
    espace_admin = lookup_widget(button,"espace_admin");
     espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}


void
on_UsearchButton_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *cin,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
       int b = 1;
    char cin1[50];
    espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
     espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
    cin = lookup_widget(button,"UsearchEntry");
     strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
      if(strcmp(cin1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"espace_Afficher_Utilisateur");
      espace_Afficher_Utilisateur=create_espace_Afficher_Utilisateur();
       gtk_widget_show(espace_Afficher_Utilisateur);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByCin(treeview, "ameni.txt",cin1);
}
}


void
on_Uactualiser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Afficher_Utilisateur,*w1,*treeview;
      w1=lookup_widget(button,"espace_Afficher_Utilisateur");
      espace_Afficher_Utilisateur=create_espace_Afficher_Utilisateur();
       gtk_widget_show(espace_Afficher_Utilisateur);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateur(treeview,"ameni.txt");
}





void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	

}




void
on_Ubutton_AfficherByRole_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *role,*pInfo,*espace_Afficher_Utilisateur,*w1,*treeview;
       int b = 1;
    char role1[50];
    espace_Afficher_Utilisateur = lookup_widget(button,"espace_Afficher_Utilisateur");
     espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur();
    role = lookup_widget(button,"Ucombobox_filtre");
     strcpy(role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
      if(strcmp(role1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"espace_Afficher_Utilisateur");
      espace_Afficher_Utilisateur=create_espace_Afficher_Utilisateur();
       gtk_widget_show(espace_Afficher_Utilisateur);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_Utilisateur,"treeviewU");
       viderUtilisateur(treeview);
       afficherUtilisateurByRole(treeview,"ameni.txt",role1);
}	
}


void
on_Retour_Affiche_admin_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *espace_Afficher_Utilisateur,*espace_admin;
     espace_Afficher_Utilisateur= lookup_widget(button,"espace_Afficher_Utilisateur");
   gtk_widget_destroy(espace_Afficher_Utilisateur);
     espace_admin = lookup_widget(button,"espace_admin");
     espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}

void
on_Retour_admin_espace_pr_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*espace_admin;
     espace_admin= lookup_widget(button,"espace_admin");
   gtk_widget_destroy(espace_admin);
    Acceuil_App = lookup_widget(button,"Acceuil_App");
      Acceuil_App = create_Acceuil_App();
     gtk_widget_show(Acceuil_App);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////::::
void
on_Espace_m__decin_ghada_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*espace_medecin;
     Acceuil_App= lookup_widget(button,"Acceuil_App");
   gtk_widget_destroy(Acceuil_App);
    espace_medecin = lookup_widget(button,"espace_medecin");
     espace_medecin = create_espace_medecin();
     gtk_widget_show(espace_medecin);
}


void
on_Espace_Infirmier_nour_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*espace_infirmier;
     Acceuil_App= lookup_widget(button,"Acceuil_App");
   gtk_widget_destroy(Acceuil_App);
    espace_infirmier = lookup_widget(button,"espace_infirmier");
    espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_Espace_Administrateur_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*espace_admin;
     Acceuil_App= lookup_widget(button,"Acceuil_App");
   gtk_widget_destroy(Acceuil_App);
    espace_admin = lookup_widget(button,"espace_admin");
      espace_admin = create_espace_admin();
     gtk_widget_show(espace_admin);
}


void
on_Espace_RDV_Asma_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

}


void
on_Espace_ETS_oussema_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*Espace_ets_oussema;
     Acceuil_App= lookup_widget(button,"Acceuil_App");
   gtk_widget_destroy(Acceuil_App);
   Espace_ets_oussema = lookup_widget(button,"Espace_ets_oussema");
    Espace_ets_oussema = create_Espace_ets_oussema();
     gtk_widget_show(Espace_ets_oussema);
}

////////////////////////////////////////////////////////////////////////////nour///////////////////////////////////////////////////////////////////////////////////////////////////
int genre1 = 1;
int question1 = 1;
int genre2 = 1;
int question2 = 1;
char filename2[50] = "nour.txt";
void
on_ajouter_espace_nour_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_ajouter_donneur,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
    espace_ajouter_donneur = lookup_widget(button,"espace_ajouter_donneur");
     espace_ajouter_donneur = create_espace_ajouter_donneur();
     gtk_widget_show(espace_ajouter_donneur);
}


void
on_Modifier_espace_nour_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_modifier_donneur,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
   Espace_modifier_donneur = lookup_widget(button,"Espace_modifier_donneur");
    Espace_modifier_donneur = create_Espace_modifier_donneur();
     gtk_widget_show(Espace_modifier_donneur);
}


void
on_supprimer_espace_nour_clicked       (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_Supp_Donneur,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
   Espace_Supp_Donneur = lookup_widget(button,"Espace_Supp_Donneur");
   Espace_Supp_Donneur = create_Espace_Supp_Donneur();
     gtk_widget_show(Espace_Supp_Donneur);
}


void
on_statistique_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_stat_donneur,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
  Espace_stat_donneur = lookup_widget(button,"Espace_stat_donneur");
  Espace_stat_donneur = create_Espace_stat_donneur();
     gtk_widget_show(Espace_stat_donneur);
}


void
on_Afficher_espace_nour_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Afficher_donneur,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
  espace_Afficher_donneur = lookup_widget(button,"espace_Afficher_donneur");
  espace_Afficher_donneur = create_espace_Afficher_donneur();
     gtk_widget_show(espace_Afficher_donneur);
}

void
on_FDHommeAjout_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{genre1=1;} 
}
void
on_FDFemmeAjout_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{genre1=2;} 
}

void
on_FDouiQuestion_Ajout_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	//if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
 //{question1=1;} 
}


void
on_FDnonQuestion_Ajout_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	// if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
 //{question1=2;} 
}


void
on_FDajoutButton_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*nom,*type,*espace_ajouter_donneur,*label,*pInfo,*espace_Afficher_donneur,*w1,*treeview;

         int b = 1;
         Donneur d;
         espace_ajouter_donneur = lookup_widget(button,"espace_ajouter_donneur");
         espace_ajouter_donneur = create_espace_ajouter_donneur();
	 nom = lookup_widget(button,"entryNomdonAjout");
        jj =  lookup_widget(button,"FDjjSpinAjout");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDyySpinAjout");
        id = lookup_widget(button,"FDidEntryAjout"); 
        cin = lookup_widget(button,"FDcinEntryAjout");
         etab= lookup_widget(button,"FDetabComboAjout");
	
        type =  lookup_widget(button,"FDtypeComboAjout");
        label = lookup_widget(button,"FDcontroleSaisiAjout");
	 strcpy(d.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	d.dateRdv.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
  	d.dateRdv.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
  	d.dateRdv.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
        strcpy(d.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
        strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
	
        strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
        if(genre1 == 1){
          strcpy(d.genre,"Homme");
         }else{
         strcpy(d.genre,"Femme");
         }
          if(question1 == 1){
          strcpy(d.question,"oui");
         }else {
         strcpy(d.question,"non");
         }
            if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.Cin,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }

             if(strcmp(d.nom,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.type,"")==0 ){
      
           b=0;
             }




                 if(b == 1){
       int t =  ajouterDonneur("nour.txt",d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  
          		 gtk_widget_destroy(espace_ajouter_donneur);
              espace_Afficher_donneur = lookup_widget(button,"espace_Afficher_donneur");
            espace_Afficher_donneur = create_espace_Afficher_donneur();
             gtk_widget_show(espace_Afficher_donneur);
                 w1=lookup_widget(button,"espace_Afficher_donneur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_donneur,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, "noue.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }


}
void
on_Retour_Ajout_Espace_Nour_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_ajouter_donneur,*espace_infirmier;
     espace_ajouter_donneur = lookup_widget(button,"espace_ajouter_donneur");
   gtk_widget_destroy(espace_ajouter_donneur);
  espace_infirmier = lookup_widget(button,"espace_infirmier");
  espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_FDHommeModifier_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{genre2=1;} 
}


void
on_FDFemmeModifier_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{genre2=2;} 
}


void
on_FDouiQuestionModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_FDnonQuestionModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_Retour_Modifier_espace_nour_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_modifier_donneur,*espace_infirmier;
     Espace_modifier_donneur= lookup_widget(button,"Espace_modifier_donneur");
   gtk_widget_destroy(Espace_modifier_donneur);
  espace_infirmier = lookup_widget(button,"espace_infirmier");
  espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_FDmodifierButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*nom,*type,*Espace_modifier_donneur,*label,*pInfo,*espace_Afficher_donneur,*w1,*treeview;

         int b = 1;
         Donneur d;
          Espace_modifier_donneur = lookup_widget(button,"Espace_modifier_donneur");
          Espace_modifier_donneur = create_Espace_modifier_donneur();
        id = lookup_widget(button,"FDidEntryModifier"); 
        cin = lookup_widget(button,"FDcinEntryModifier");
         etab= lookup_widget(button,"FDetabComboModifier");
        jj =  lookup_widget(button,"FDjjSpinModifier");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDmmSpinModifier");
        nom = lookup_widget(button,"Nom_prenomMOd_donneur");
        type =  lookup_widget(button,"FDtypeComboModifier");
        label = lookup_widget(button,"FDcontroleSaisiModifier");
        strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
        strcpy(d.Cin,gtk_entry_get_text(GTK_ENTRY(cin)));
        strcpy(d.etab,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        d.dateRdv.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.dateRdv.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.dateRdv.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
        strcpy(d.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
        strcpy(d.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
        if(genre2 == 1){
          strcpy(d.genre,"Homme");
         }else{
         strcpy(d.genre,"Femme");
         }
          if(question2 == 1){
          strcpy(d.question,"oui");
         }else{
         strcpy(d.question,"non");
         }
            if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.Cin,"")==0 ){
      
           b=0;
             }
              if(strcmp(d.etab,"")==0 ){
      
           b=0;
             }

             if(strcmp(d.nom,"")==0 ){
      
           b=0;
             }
             if(strcmp(d.type,"")==0 ){
      
           b=0;
             }




                 if(b == 1){
       int t =  modifierDonneur("nour.txt",d.id,d);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Modifier Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(cin),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  
          		 gtk_widget_destroy(Espace_modifier_donneur);
             espace_Afficher_donneur = lookup_widget(button,"espace_Afficher_donneur");
             espace_Afficher_donneur = create_espace_Afficher_donneur();
             gtk_widget_show(espace_Afficher_donneur);
                 w1=lookup_widget(button,"espace_Afficher_donneur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_donneur,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview, "nour.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
}
  
void
on_FDsearchModifierButton_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
	  GtkWidget *id ,*cin,*etab,*jj,*mm,*yy,*nom,*type,*Espace_modifier_donneur,*label,*pInfo,*espace_Afficher_donneur,*w1,*treeview;
int b = 1;
  char id1[50];
          Espace_modifier_donneur = lookup_widget(button,"Espace_modifier_donneur");
           Espace_modifier_donneur = create_Espace_modifier_donneur();
        id = lookup_widget(button,"FDidEntryModifier"); 
        cin = lookup_widget(button,"FDcinEntryModifier");
         etab= lookup_widget(button,"FDetabComboModifier");
        jj =  lookup_widget(button,"FDjjSpinModifier");
        mm =  lookup_widget(button,"FDmmSpinAjout");
        yy =   lookup_widget(button,"FDmmSpinModifier");
        nom = lookup_widget(button,"Nom_prenomMOd_donneur");
        type =  lookup_widget(button,"FDtypeComboModifier");
        label = lookup_widget(button,"FDcontroleSaisiModifier");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
      
     
            if(strcmp(id1,"")==0 ){
      
           b=0;
             }
             if(b == 1){
                Donneur p =  chercherDonneur("nour.txt", id1);
       if(strcmp(p.id,"-1")==0){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(id),"");
               break;}

          }else{
                 
                 
               gtk_entry_set_text(GTK_ENTRY(id),p.id);
                  gtk_entry_set_text(GTK_ENTRY(cin),p.Cin);
                  gtk_entry_set_text(GTK_ENTRY(nom),p.nom);
               //  gtk_combo_box_append_text (GTK_COMBO_BOX (type), _(p.type));
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre id ❌️");

       }
}

void
on_Retour_supp_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_Supp_Donneur,*espace_infirmier;
     Espace_Supp_Donneur = lookup_widget(button,"Espace_Supp_Donneur");
   gtk_widget_destroy(Espace_Supp_Donneur);
  espace_infirmier = lookup_widget(button,"espace_infirmier");
  espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_FDsupprimerButton_clicked           (GtkWidget      *button,
                                        gpointer         user_data)
{
	 GtkWidget *id ,*Espace_Supp_Donneur,*label,*pInfo,*w1,*treeview,*espace_Afficher_donneur;
    
           int b = 1;
         char id1[50];
         Espace_Supp_Donneur  = lookup_widget(button,"Espace_Supp_Donneur");
         Espace_Supp_Donneur = create_Espace_Supp_Donneur();
        id = lookup_widget(button,"FDidEntrySupprimer"); 
        label = lookup_widget(button,"FDcontroleSaisiSupprimer");
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
           b=0;
             }

                 if(b == 1){
       int t =  supprimerDonneur(filename2,id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Supprimer Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
                  
          		 gtk_widget_destroy(Espace_Supp_Donneur);
               break;
          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
        
}


void
on_FDsearchButton_clicked              (GtkWidget      *button,
                                        gpointer         user_data)
{
	GtkWidget *pInfo , *espace_Afficher_donneur,*treeview,*w1,*id;
	    int b = 1;
         char id1[50];
        espace_Afficher_donneur  = lookup_widget(button,"espace_Afficher_donneur");
          espace_Afficher_donneur = create_espace_Afficher_donneur();
        id = lookup_widget(button,"FDsearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"espace_Afficher_donneur");
      espace_Afficher_donneur=create_espace_Afficher_donneur();
       gtk_widget_show(espace_Afficher_donneur);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_donneur,"treeviewFD");
       viderDonneur(treeview);
       rechercherDonneur(treeview,filename2,id1);

           }
}


void
on_Retour_Afficher_espace_nour_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Afficher_donneur,*espace_infirmier;
     espace_Afficher_donneur = lookup_widget(button,"espace_Afficher_donneur");
   gtk_widget_destroy(espace_Afficher_donneur);
  espace_infirmier = lookup_widget(button,"espace_infirmier");
  espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_FDactualiser_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Afficher_donneur,*w1,*treeview;
      w1=lookup_widget(button,"espace_Afficher_donneur");
      espace_Afficher_donneur=create_espace_Afficher_donneur();
       gtk_widget_show(espace_Afficher_donneur);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_Afficher_donneur,"treeviewFD");
       viderDonneur(treeview);
       afficherDonneur(treeview,filename2);
}


void
on_FDtreeviewStatistique_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

void
on_FDrdvMoyenneButtonStatistique_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *label,*jj,*mm,*yy,*Espace_stat_donneur ;
    Espace_stat_donneur = lookup_widget(button,"Espace_stat_donneur");
           Espace_stat_donneur = create_Espace_stat_donneur();
  label = lookup_widget(button,"FDrdvMoyenneLabelStatistique");
   jj =  lookup_widget(button,"jj1");
        mm =  lookup_widget(button,"mm1");
        yy =   lookup_widget(button,"yy1");
    int jj1,mm1,yy1;
     char moyenne1[50];
      jj1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        mm1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
       yy1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
   float moyenne =     moyRDV_ETS("ets.txt",filename2, jj1, mm1 ,yy1 );
        sprintf(moyenne1,"%f",moyenne);
     gtk_label_set_text(GTK_LABEL(label),moyenne1);
}


void
on_Retour_stat_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espace_stat_donneur,*espace_infirmier;
     Espace_stat_donneur = lookup_widget(button,"Espace_stat_donneur");
   gtk_widget_destroy(Espace_stat_donneur);
  espace_infirmier = lookup_widget(button,"espace_infirmier");
  espace_infirmier = create_espace_infirmier();
     gtk_widget_show(espace_infirmier);
}


void
on_FDstatistiqueButton_don_clicked     (GtkWidget      *button,
                                        gpointer         user_data)
{
	  GtkWidget *id ,*etab,*jj,*mm,*yy,*espace_Afficher_donneur,*Espace_stat_donneur,*label,*pInfo,*w1,*treeview;
     int b =1;
       char etab1[50];
int jj1,mm1,yy1;
         etab= lookup_widget(button,"FDetabComboStatistique");
        jj =  lookup_widget(button,"FDjjSpinStatistique");
        mm =  lookup_widget(button,"FDmmSpinStatistique");
        yy =   lookup_widget(button,"FDyySpinStatistique");
        
        label = lookup_widget(button,"FDcontroleSaisiStatistique");
         Espace_stat_donneur = lookup_widget(button,"Espace_stat_donneur");
           Espace_stat_donneur = create_Espace_stat_donneur();
           strcpy(etab1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etab)));
        jj1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        mm1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
       yy1 = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
    if(jj1>0 &&  jj1<32){

        b =0;

      }
          if(mm1>0 &&  mm1<13){

        b =0;

      }
            if(yy1>1950 &&  yy1<2025){

        b =0;

      } 


      if(strcmp(etab1,"")==0){
         b =0;
      }

    if(b =1){

          Espace_stat_donneur = lookup_widget(button,"Espace_stat_donneur");
            Espace_stat_donneur = create_Espace_stat_donneur();
             gtk_widget_show(Espace_stat_donneur);
                 w1=lookup_widget(button,"Espace_stat_donneur");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(Espace_stat_donneur,"FDtreeviewStatistique");
      viderDonneur(treeview);
       listeRdvTreeView(treeview, filename2,etab1,jj1,mm1,yy1);
    }else{

        gtk_label_set_text(GTK_LABEL(label),"verifier vos donner");
      }
}


void
on_Retour_infirmier_espace_pr_clicked  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_App,*espace_infirmier;
     espace_infirmier= lookup_widget(button,"espace_infirmier");
   gtk_widget_destroy(espace_infirmier);
    Acceuil_App = lookup_widget(button,"Acceuil_App");
      Acceuil_App = create_Acceuil_App();
     gtk_widget_show(Acceuil_App);
}



//////////////////////////////////////////////////////////ghada/////////////////////////////////////////////////////////////////////////////


int tatou1;
int alcool1;
int fumeur1;
int tatou2;
int alcool2;
int fumeur2;
char filename3[]="gestionDons.txt";
void
on_Ajouter_espace_ajouterghada_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_medecin,*espace_Ajouter_don_ghada;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
  espace_Ajouter_don_ghada = lookup_widget(button,"espace_Ajouter_don_ghada");
   espace_Ajouter_don_ghada = create_espace_Ajouter_don_ghada();
     gtk_widget_show(espace_Ajouter_don_ghada);
}


void
on_mod_space_modghada_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *espace_medecin,*espace_modif_dons;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
   espace_modif_dons= lookup_widget(button,"espace_modif_dons");
    espace_modif_dons = create_espace_modif_dons();
     gtk_widget_show(espace_modif_dons);
}


void
on_supp_espace_suppghada_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_medecin,*Espace_supp_Dons;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
   Espace_supp_Dons= lookup_widget(button,"Espace_supp_Dons");
    Espace_supp_Dons = create_Espace_supp_Dons();
     gtk_widget_show(Espace_supp_Dons);
}


void
on_stat_ghada_stat_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_medecin,*espace_stat_dons;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
   espace_stat_dons= lookup_widget(button,"espace_stat_dons");
    espace_stat_dons = create_espace_stat_dons();
     gtk_widget_show(espace_stat_dons);
}


void
on_afficher_ghada_afficher_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_medecin,*espace_ghada_affiche;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
   espace_ghada_affiche= lookup_widget(button,"espace_ghada_affiche");
    espace_ghada_affiche = create_espace_ghada_affiche();
     gtk_widget_show(espace_ghada_affiche);
}


void
on_Retour_ajout_espaceGhada_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_Ajouter_don_ghada,*espace_medecin;
     espace_Ajouter_don_ghada= lookup_widget(button,"espace_Ajouter_don_ghada");
   gtk_widget_destroy(espace_Ajouter_don_ghada);
    espace_medecin = lookup_widget(button,"espace_medecin");
      espace_medecin= create_espace_medecin();
     gtk_widget_show(espace_medecin);
}


void
on_GDonsajoutButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id ,*cin,*type,*quantite,*jj,*mm,*yy,*espace_Ajouter_don_ghada,*label,*pInfo,*espace_ghada_affiche,*w1,*treeview;
     int b = 1;
     Dons d;
    espace_Ajouter_don_ghada = lookup_widget(button,"espace_Ajouter_don_ghada");
          espace_Ajouter_don_ghada = create_espace_Ajouter_don_ghada();
      id = lookup_widget(button,"GDonsIdEntryAjout");
     cin = lookup_widget(button,"GDonscinEntryAjout");
     type = lookup_widget(button,"GDonsTypeComboAjout");
     quantite = lookup_widget(button,"GDonsQuantiteSpinAjout");
     jj = lookup_widget(button,"GDonsjjSpinAjout");
     mm = lookup_widget(button,"GDonsmmSpinAjout");
     yy = lookup_widget(button,"GDonsyySpinAjout");
     label = lookup_widget(button,"GDonscontroleSaisiAjout");
     strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
     strcpy(d.cinDonneur,gtk_entry_get_text(GTK_ENTRY(cin)));
     strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
      d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         if(tatou1 == 1){
           strcpy(d.tattou,"oui");

          }else{

           strcpy(d.tattou,"non");
          }
            if(fumeur1 == 1){
           strcpy(d.fumeur,"oui");

          }else{

           strcpy(d.fumeur,"non");
          }
           if(alcool1 == 1){
           strcpy(d.alcool,"oui");

          }else{

           strcpy(d.alcool,"non");
          }

         if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
           if(strcmp(d.cinDonneur,"")==0 ){
      
           b=0;
             }
            if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

           if(b == 1){
       int t =  ajouterDons(filename3,d);
       if(t == 1){
         gtk_label_set_text(GTK_LABEL(label)," ajout avec succee ");
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                      gtk_entry_set_text(GTK_ENTRY(cin),"");
                 
                  
          		 
             espace_ghada_affiche = lookup_widget(button,"espace_ghada_affiche");
             espace_ghada_affiche = create_espace_ghada_affiche();
             gtk_widget_show(espace_ghada_affiche);
              
                 w1=lookup_widget(button,"espace_ghada_affiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_ghada_affiche,"treeviewGDons");
       viderDons(treeview);
       afficherDons(treeview,filename3);
        gtk_widget_destroy(espace_Ajouter_don_ghada);
          
       }else{

          gtk_label_set_text(GTK_LABEL(label),"echec ajout  ❌️   ");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos données  ❌️");
     }


}


void
on_GDonsFumeurNonAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	 if (gtk_toggle_button_get_active(togglebutton))
 {fumeur1=2;}
}


void
on_GDonsAlcoolNonAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
 {alcool1=2;}
}


void
on_GDonsTatouageOuiModifier_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{tatou2=1;}
}


void
on_GDonsTatouagenonModifier_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{tatou2=2;} 
}


void
on_GDonsFumeurOuiModifie_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	
	if (gtk_toggle_button_get_active(togglebutton))
 {fumeur2=1;}
}


void
on_GDonsFumeurNonModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
 {fumeur2=2;}
}


void
on_Retour_modif_space_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *espace_modif_dons,*espace_medecin;
     espace_modif_dons= lookup_widget(button,"espace_modif_dons");
   gtk_widget_destroy(espace_modif_dons);
    espace_medecin = lookup_widget(button,"espace_medecin");
      espace_medecin= create_espace_medecin();
     gtk_widget_show(espace_medecin);
}


void
on_GDonsModifierButton_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *id ,*cin,*type,*quantite,*jj,*mm,*yy,*espace_modif_dons,*label,*pInfo,*espace_ghada_affiche,*w1,*treeview;
     int b = 1;
     Dons d;
     espace_modif_dons = lookup_widget(button,"espace_modif_dons");
         espace_modif_dons = create_espace_modif_dons();
     id = lookup_widget(button,"GDonsIdEntryModifier");
     cin = lookup_widget(button,"GDonscinEntryModifier");
     type = lookup_widget(button,"GDonsTypeComboModifier");
     quantite = lookup_widget(button,"GDonsQuantiteSpinModifier");
     jj = lookup_widget(button,"GDonsjjSpinModifier");
     mm = lookup_widget(button,"GDonsmmSpinModifier");
     yy = lookup_widget(button,"GDonsyySpinModifier");
     label = lookup_widget(button,"GDonscontroleSaisiModifier");
     strcpy(d.id,gtk_entry_get_text(GTK_ENTRY(id)));
     strcpy(d.cinDonneur,gtk_entry_get_text(GTK_ENTRY(cin)));
     strcpy(d.typeSang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
      d.date.jj = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jj));
        d.date.mm = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mm));
        d.date.yy = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(yy));
         d.quantite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite));
         if(tatou2 == 1){
           strcpy(d.tattou,"oui");

          }else{

           strcpy(d.tattou,"non");
          }
            if(fumeur2 == 1){
           strcpy(d.fumeur,"oui");

          }else{

           strcpy(d.fumeur,"non");
          }
           if(alcool2 == 1){
           strcpy(d.alcool,"oui");

          }else{

           strcpy(d.alcool,"non");
          }

         if(strcmp(d.id,"")==0 ){
      
           b=0;
             }
           if(strcmp(d.cinDonneur,"")==0 ){
      
           b=0;
             }
            if(strcmp(d.typeSang,"")==0 ){
      
           b=0;
             }

           if(b == 1){
       int t =  modifierDons(filename3,d.id,d);
       if(t == 1){
                  gtk_label_set_text(GTK_LABEL(label),"modifier avec succe  ");
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                      gtk_entry_set_text(GTK_ENTRY(cin),"");
                 
                  
          		 
             espace_ghada_affiche = lookup_widget(button,"espace_ghada_affiche");
             espace_ghada_affiche = create_espace_ghada_affiche();
             gtk_widget_show(espace_ghada_affiche);
              
                 w1=lookup_widget(button,"espace_ghada_affiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_ghada_affiche,"treeviewGDons");
       viderDons(treeview);
       afficherDons(treeview,filename3);
           gtk_widget_destroy(espace_modif_dons);
          
       }else{

          gtk_label_set_text(GTK_LABEL(label),"echec modification  ");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos données   ");
     }
}


void
on_GDonssupprimerButton_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *id ,*Espace_supp_Dons,*label,*pInfo,*espace_ghada_affiche,*w1,*treeview;
     int b = 1;
      char id1[50];
     Espace_supp_Dons = lookup_widget(button,"Espace_supp_Dons");
           Espace_supp_Dons = create_Espace_supp_Dons();
      id = lookup_widget(button,"GDonsidEntrySupprimer");
   
     label = lookup_widget(button,"GDonscontroleSaisiSupprimer");
     strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
  

         if(strcmp(id1,"")==0 ){
      
           b=0;
             }
        

           if(b == 1){
       int t =  supprimerDons(filename3,id1);
       if(t == 1){
         gtk_label_set_text(GTK_LABEL(label)," suppression avec succe  ");
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                     
                 
                  
          		 
             espace_ghada_affiche = lookup_widget(button,"espace_ghada_affiche");
             espace_ghada_affiche = create_espace_ghada_affiche();
             gtk_widget_show(espace_ghada_affiche);
              
                 w1=lookup_widget(button,"espace_ghada_affiche");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_ghada_affiche,"treeviewGDons");
       viderDons(treeview);
       afficherDons(treeview,filename3);
           gtk_widget_destroy(Espace_supp_Dons);
               


          
       }else{

          gtk_label_set_text(GTK_LABEL(label),"echec suppression  ");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ");
     }
}


void
on_treeviewGDons_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_GDonssearchButton_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *id ,*espace_ghada_affiche,*pInfo,*w1,*treeview;
    
           int b = 1;
         char id1[50];
         espace_ghada_affiche  = lookup_widget(button,"espace_ghada_affiche");
           espace_ghada_affiche = create_espace_ghada_affiche();
        id = lookup_widget(button,"GDonssearchEntry"); 
        
        strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
          if(strcmp(id1,"")==0 ){
      
            pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
             }else{
                w1=lookup_widget(button,"espace_ghada_affiche");
      espace_ghada_affiche=create_espace_ghada_affiche();
       gtk_widget_show(espace_ghada_affiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_ghada_affiche,"treeviewGDons");
       viderDons(treeview);
       rechercherDons(treeview,filename3,id1);

           }
}


void
on_Retour_affiche_espace_ghada_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_ghada_affiche,*espace_medecin;
   espace_ghada_affiche= lookup_widget(button,"espace_ghada_affiche");
   gtk_widget_destroy(espace_ghada_affiche);
    espace_medecin = lookup_widget(button,"espace_medecin");
      espace_medecin= create_espace_medecin();
     gtk_widget_show(espace_medecin);
}


void
on_GDonsactualiser_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_ghada_affiche,*w1,*treeview;
      w1=lookup_widget(button,"espace_ghada_affiche");
      espace_ghada_affiche=create_espace_ghada_affiche();
       gtk_widget_show(espace_ghada_affiche);
       gtk_widget_hide(w1);
       treeview=lookup_widget(espace_ghada_affiche,"treeviewGDons");
       viderDons(treeview);
       afficherDons(treeview,filename3);
}


void
on_GDonsstatistiqueQuantiteButton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget  *type,*label1,*espace_stat_dons;
      espace_stat_dons = lookup_widget(button,"espace_stat_dons");
           espace_stat_dons = create_espace_stat_dons();
    int b=1;
char type1[50];
   type = lookup_widget(button,"GDonsTypeComboStatistique"); 
   label1 = lookup_widget(button,"GDonsQuantiteLabelStatistique");
   
    strcpy(type1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
        if(strcmp(type1,"")==0 ){
      
           b=0;
             }
         if (b == 1){
       int quantite = quantite_type(filename3,type1);
       char var[50];
    sprintf(var,"%d",quantite);

         gtk_label_set_text(GTK_LABEL(label1),var);


         }else{


           gtk_label_set_text(GTK_LABEL(label1),"verifier vos donnée ");

        }
}


void
on__GDonsstatistiqueSangButton_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *label;
   label = lookup_widget(button,"GDonsSangLabelStatistique");
    gtk_label_set_text(GTK_LABEL(label),sang_rare(filename3));
}


void
on_Retour_stat_espace_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *espace_stat_dons,*espace_medecin;
    espace_stat_dons= lookup_widget(button,"espace_stat_dons");
   gtk_widget_destroy(espace_stat_dons);
    espace_medecin = lookup_widget(button,"espace_medecin");
      espace_medecin= create_espace_medecin();
     gtk_widget_show(espace_medecin);
}





void
on_Retour_medecin_Espace_pr_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_App,*espace_medecin;
     espace_medecin= lookup_widget(button,"espace_medecin");
   gtk_widget_destroy(espace_medecin);
    Acceuil_App = lookup_widget(button,"Acceuil_App");
      Acceuil_App = create_Acceuil_App();
     gtk_widget_show(Acceuil_App);
}


void
on_Retour_supp_espace_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *Espace_supp_Dons,*espace_medecin;
   Espace_supp_Dons= lookup_widget(button,"Espace_supp_Dons");
   gtk_widget_destroy(Espace_supp_Dons);
    espace_medecin = lookup_widget(button,"espace_medecin");
      espace_medecin= create_espace_medecin();
     gtk_widget_show(espace_medecin);
}

/////////////////////////////////////////////////////////////////////////////////////////////////oussema//////////////////////////////////////////////////////////////////
void
on_Ajouter_espace_ajouterEts_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Ajouter_ETS,*Espace_ets_oussema;
    Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   gtk_widget_destroy(Espace_ets_oussema);
   NL_Ajouter_ETS= lookup_widget(button,"NL_Ajouter_ETS");
    NL_Ajouter_ETS = create_NL_Ajouter_ETS();
     gtk_widget_show(NL_Ajouter_ETS);
}


void
on_Modifier_espace_mod_ets_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Modifier_ETS,*Espace_ets_oussema;
    Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   gtk_widget_destroy(Espace_ets_oussema);
   NL_Modifier_ETS= lookup_widget(button,"NL_Modifier_ETS");
   NL_Modifier_ETS = create_NL_Modifier_ETS();
     gtk_widget_show(NL_Modifier_ETS);
}


void
on_Afficher_espace_afficher_ets_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Afficher_ETS,*Espace_ets_oussema;
    Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   gtk_widget_destroy(Espace_ets_oussema);
   NL_Afficher_ETS= lookup_widget(button,"NL_Afficher_ETS");
   NL_Afficher_ETS = create_NL_Afficher_ETS();
     gtk_widget_show(NL_Afficher_ETS);
}


void
on_supp_espace_supp_ets_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Supprimer_ETS,*Espace_ets_oussema;
    Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   gtk_widget_destroy(Espace_ets_oussema);
   NL_Supprimer_ETS= lookup_widget(button,"NL_Supprimer_ETS");
   NL_Supprimer_ETS = create_NL_Supprimer_ETS();
     gtk_widget_show(NL_Supprimer_ETS);
}

void
on_Retour_espace_oussema_home_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
 	GtkWidget *Acceuil_App,*Espace_ets_oussema;
    Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   gtk_widget_destroy(Espace_ets_oussema);
   Acceuil_App= lookup_widget(button,"Acceuil_App");
   Acceuil_App = create_Acceuil_App();
     gtk_widget_show(Acceuil_App);
}
void
on_Retour_ETS_espace_oussema_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Ajouter_ETS,*Espace_ets_oussema;
    NL_Ajouter_ETS= lookup_widget(button,"NL_Ajouter_ETS");
   gtk_widget_destroy(NL_Ajouter_ETS);
   Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   Espace_ets_oussema = create_Espace_ets_oussema();
     gtk_widget_show(Espace_ets_oussema);

}


void
on_NL_buttonAjouterETS_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Ajouter_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
    char varid[50],varcapacite[50],vartelephone[50];
    ets e;
    int b = 1;
    NL_Ajouter_ETS = lookup_widget(button,"NL_Ajouter_ETS");
     NL_Ajouter_ETS = create_NL_Ajouter_ETS();
    id = lookup_widget(button,"NL_entryId");
    nom =  lookup_widget(button,"NL_entrynom");
    adresse =  lookup_widget(button,"NL_entryemail");
    capacite =  lookup_widget(button,"spinbutton21");
    region = lookup_widget(button,"NL_ComboBoxRegionAjout");
    telephone = lookup_widget(button,"NL_entrytelephone");
    label = lookup_widget(button,"NL_Ajout_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid);
    strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(nom)));
    e.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
     strcpy(e.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
    strcpy(vartelephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
    e.telephone = atoi(vartelephone);
    if( e.id == 0 ){
       
       b=0;
     }
     if(strcmp(e.nom,"")==0 ){
      
       b=0;
     }
      if(strcmp(e.adresse,"")==0 ){
      
       b=0;
     }
      if(e.capacite==0 ){
      
       b=0;
     }
    if(strcmp(e.region,"")==0 ){
      
       b=0;
     }
    
      if( e.telephone == 0 ){
       
       b=0;
     }
     
     if(b == 1){
       int t =  ajouterEts("oussema.txt",e);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ajout Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(adresse),"");
                  gtk_entry_set_text(GTK_ENTRY(telephone),"");
          		 gtk_widget_destroy(NL_Ajouter_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "oussema.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
     
     
}


void
on_Retour_modif_ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *NL_Modifier_ETS,*Espace_ets_oussema;
    NL_Modifier_ETS= lookup_widget(button,"NL_Modifier_ETS");
   gtk_widget_destroy(NL_Modifier_ETS);
   Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   Espace_ets_oussema = create_Espace_ets_oussema();
     gtk_widget_show(Espace_ets_oussema);
}


void
on_buttonValiderModification_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	  GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Modifier_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
    char varid[50],varcapacite[50],vartelephone[50];
    ets e;
    int b = 1;
    NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
     NL_Modifier_ETS = create_NL_Modifier_ETS();
    id = lookup_widget(button,"NL_entryID");
    nom =  lookup_widget(button,"NL_modentryNom");
    adresse =  lookup_widget(button,"NL_entrymodemail");
    capacite =  lookup_widget(button,"spinbuttonmodcapacite");
    region = lookup_widget(button,"NL_ComboBoxRegionModifier");
    telephone = lookup_widget(button,"NL_entrymodtelephone");
    label = lookup_widget(button,"NL_Modifier_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid);
    strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
    e.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capacite));
     strcpy(e.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
    strcpy(vartelephone,gtk_entry_get_text(GTK_ENTRY(telephone)));
    e.telephone = vartelephone;
    if( e.id == 0 ){
       
       b=0;
     }
     if(strcmp(e.nom,"")==0 ){
      
       b=0;
     }
      if(strcmp(e.adresse,"")==0 ){
      
       b=0;
     }
      if(e.capacite==0 ){
      
       b=0;
     }
    if(strcmp(e.region,"")==0 ){
      
       b=0;
     }
    
      if( e.telephone == 0 ){
       
       b=0;
     }
     
     if(b == 1){
       int t =  modifierEts("nermine.txt", e.id,e);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modifier Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                  gtk_entry_set_text(GTK_ENTRY(nom),"");
                  gtk_entry_set_text(GTK_ENTRY(adresse),"");
                  gtk_entry_set_text(GTK_ENTRY(telephone),"");
			 gtk_widget_destroy(NL_Modifier_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "oussema.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
}


void
on_NL_treeviewETS_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_NL_Button_tree_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *NL_Afficher_ETS,*w1,*treeview;
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherTrier(treeview, "oussema.txt");
}



void
on_NL_button_AfficherByRole_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *region,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
       int b = 1;
    char region1[50];
    NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
     NL_Afficher_ETS = create_NL_Afficher_ETS();
    region = lookup_widget(button,"NL_combobox_filtre");
     strcpy(region1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
      if(strcmp(region1,"")==0 ){
      
       pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"case est vide  ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 
               break;}
     }else{

         
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEtsByRegion(treeview, "oussema.txt",region1);

   }
}


void
on_Retour_affiche_Ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Afficher_ETS,*Espace_ets_oussema;
   NL_Afficher_ETS= lookup_widget(button,"NL_Afficher_ETS");
   gtk_widget_destroy(NL_Afficher_ETS);
   Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   Espace_ets_oussema = create_Espace_ets_oussema();
     gtk_widget_show(Espace_ets_oussema);
}


void
on_actualisertrieETS_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	
}


void
on_buttonValiderSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *id,*NL_Supprimer_ETS,*label,*pInfo,*NL_Afficher_ETS,*w1,*treeview;
 char varid[50];
  int b =1;
   int id1;
  NL_Supprimer_ETS = lookup_widget(button,"NL_Supprimer_ETS");
     NL_Supprimer_ETS = create_NL_Supprimer_ETS();
    id = lookup_widget(button,"NL_entryIdSupprimer");
   label = lookup_widget(button,"NL_Supprimer_Controle_saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    id1 = atoi(varid);
     if( id1 == 0 ){
       
       b=0;
     }
     if(b == 1){
       int t =  supprimerEts("oussema.txt", id1);
       if(t == 1){
          pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"supprimer Avec succée ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                  gtk_entry_set_text(GTK_ENTRY(id),"");
                 
			 gtk_widget_destroy(NL_Supprimer_ETS);
              NL_Afficher_ETS = lookup_widget(button,"NL_Afficher_ETS");
             NL_Afficher_ETS = create_NL_Afficher_ETS();
             gtk_widget_show(NL_Afficher_ETS);
                 w1=lookup_widget(button,"NL_Afficher_ETS");
     
       
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
       afficherEts(treeview, "oussema.txt");
               break;


          }
       }else{

          gtk_label_set_text(GTK_LABEL(label),"failed ajout  ❌️");
       }

      }else if (b == 0){

      gtk_label_set_text(GTK_LABEL(label),"verifier vos donné   ❌️");
     }
    
}


void
on_Retour_supp_ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Supprimer_ETS,*Espace_ets_oussema;
   NL_Supprimer_ETS= lookup_widget(button,"NL_Supprimer_ETS");
   gtk_widget_destroy(NL_Supprimer_ETS);
   Espace_ets_oussema= lookup_widget(button,"Espace_ets_oussema");
   Espace_ets_oussema = create_Espace_ets_oussema();
     gtk_widget_show(Espace_ets_oussema);
}





void
on_buttonRechercherIDModifier_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	 GtkWidget *id,*nom,*adresse,*capacite,*region,*telephone,*NL_Modifier_ETS,*label,*pInfo; 
       int b =1;
char varid[50],varcapacite[50],vartelephone[50];
    ets e;

     NL_Modifier_ETS = lookup_widget(button,"NL_Modifier_ETS");
     NL_Modifier_ETS = create_NL_Modifier_ETS();
    id = lookup_widget(button,"NL_entryID");
    nom =  lookup_widget(button,"NL_modentryNom");
    adresse =  lookup_widget(button,"NL_entrymodemail");
    capacite =  lookup_widget(button,"spinbuttonmodcapacite");
    region = lookup_widget(button,"NL_Modifier_Combo_2");
    telephone = lookup_widget(button,"NL_entrymodtelephone");
    label = lookup_widget(button,"NL_Modifier_Controle_Saisi");
    strcpy(varid,gtk_entry_get_text(GTK_ENTRY(id)));
    e.id = atoi(varid); 
    if( e.id == 0 ){
       
       b=0;
     }

    if(b == 1){

     ets p =  chercherEts("oussema.txt", e.id);
       if(p.id == -1){

pInfo = gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ets n'est pas trouver ✔️");
      switch(gtk_dialog_run(GTK_DIALOG(pInfo))){
               case GTK_RESPONSE_OK:
               gtk_widget_destroy(pInfo);
                 gtk_entry_set_text(GTK_ENTRY(id),"");
               break;}

          }else{
                 sprintf(varid,"%d",p.id);
                 sprintf(vartelephone,"%d",p.telephone);
                 
               gtk_entry_set_text(GTK_ENTRY(id),varid);
                  gtk_entry_set_text(GTK_ENTRY(nom),p.nom);
                  gtk_entry_set_text(GTK_ENTRY(adresse),p.adresse);
                  gtk_entry_set_text(GTK_ENTRY(telephone),vartelephone);
                 
                 // gtk_combo_box_set_active_iter(region, p.region);
          }



     }else if (b == 0){

         gtk_label_set_text(GTK_LABEL(label),"verifier votre id   ❌️");

       }
    
}


void
on_actualisertrie_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *NL_Afficher_ETS,*w1,*treeview;
      w1=lookup_widget(button,"NL_Afficher_ETS");
      NL_Afficher_ETS=create_NL_Afficher_ETS();
       gtk_widget_show(NL_Afficher_ETS);
       gtk_widget_hide(w1);
       treeview=lookup_widget(NL_Afficher_ETS,"NL_treeviewETS");
       vider_Ets(treeview);
        afficherEts(treeview, "oussema.txt");
}


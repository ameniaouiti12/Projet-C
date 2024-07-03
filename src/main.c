/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *espace_admin;
  GtkWidget *espace_ajout_Utilisateur;
  GtkWidget *espace_modif_Utilisateur;
  GtkWidget *espace_supprimer_Utilisateur;
  GtkWidget *espace_Statistique_Utilisateur;
  GtkWidget *espace_Afficher_Utilisateur;
  GtkWidget *Acceuil_App;
  GtkWidget *espace_infirmier;
  GtkWidget *espace_ajouter_donneur;
  GtkWidget *Espace_modifier_donneur;
  GtkWidget *Espace_Supp_Donneur;
  GtkWidget *espace_Afficher_donneur;
  GtkWidget *Espace_stat_donneur;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  Acceuil_App = create_Acceuil_App ();
  gtk_widget_show (Acceuil_App);
  /*espace_admin = create_espace_admin ();
  gtk_widget_show (espace_admin);
  espace_ajout_Utilisateur = create_espace_ajout_Utilisateur ();
  gtk_widget_show (espace_ajout_Utilisateur);
  espace_modif_Utilisateur = create_espace_modif_Utilisateur ();
  gtk_widget_show (espace_modif_Utilisateur);

  espace_supprimer_Utilisateur = create_espace_supprimer_Utilisateur ();
  gtk_widget_show (espace_supprimer_Utilisateur);
  espace_Statistique_Utilisateur = create_espace_Statistique_Utilisateur ();
  gtk_widget_show (espace_Statistique_Utilisateur);
  espace_Afficher_Utilisateur = create_espace_Afficher_Utilisateur ();
  gtk_widget_show (espace_Afficher_Utilisateur);

  */
  gtk_main ();
  return 0;
}


#include <gtk/gtk.h>


void
on_Ameni_Ajouter_Utilisateur_clicked   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ameni_Modifier_Utilisateur_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ameni_Supprimer_Utilisateur_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ameni_Afficher_Utilisateur_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UgenreHommeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeAjout_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UafficherMdpAjout_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Retour_Ajout_Admin_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UbuttonRechercherIDModifier_clicked (GtkWidget      *button,
                                        gpointer         user_data);

void
on_UgenreHommeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UgenreFemmeModifier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_UafficherMdpModifier_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Retour_Modif_Admin_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UModifierButton_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UsupprimerButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UannulerSupprimerButton_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDstatistiqueButton_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_Stat_Admin_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UsearchButton_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Uactualiser_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_UstatistiqueWidget_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeviewU_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_UajoutButton_clicked                (GtkWidget       *button,
                                        gpointer         user_data);


void
on_Ubutton_AfficherByRole_clicked      (GtkWidget        *button,
                                        gpointer         user_data);

void
on_Retour_Affiche_admin_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Espace_m__decin_ghada_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Espace_Infirmier_nour_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Espace_Administrateur_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Espace_RDV_Asma_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Espace_ETS_oussema_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajouter_espace_nour_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modifier_espace_nour_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_espace_nour_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_statistique_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Afficher_espace_nour_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDHommeAjout_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiQuestion_Ajout_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDnonQuestion_Ajout_clicked         (GtkWidget      *button,
                                        gpointer         user_data);

void
on_FDajoutButton_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDsearchModifierButton_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDHommeModifier_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDFemmeModifier_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDouiQuestionModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FDnonQuestionModifier_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Retour_Modifier_espace_nour_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDmodifierButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_supp_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDsupprimerButton_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDsearchButton_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_Afficher_espace_nour_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDactualiser_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDtreeviewStatistique_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_FDrdvMoyenneButtonStatistique_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_stat_espace_nour_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDstatistiqueButton_don_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_Ajout_Espace_Nour_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_Ajout_Espace_Nour_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_FDFemmeAjout_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Ajouter_espace_ajouterghada_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_mod_space_modghada_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supp_espace_suppghada_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_stat_ghada_stat_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_afficher_ghada_afficher_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_ajout_espaceGhada_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonsajoutButton_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonsFumeurNonAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDonsAlcoolNonAjout_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDonsTatouageOuiModifier_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDonsTatouagenonModifier_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDonsFumeurOuiModifie_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_GDonsFumeurNonModifier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Retour_modif_space_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonsModifierButton_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonssupprimerButton_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeviewGDons_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_GDonssearchButton_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_affiche_espace_ghada_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonsactualiser_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDonsstatistiqueQuantiteButton_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on__GDonsstatistiqueSangButton_clicked (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_stat_espace_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_admin_espace_pr_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_infirmier_espace_pr_clicked  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_medecin_Espace_pr_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Retour_supp_espace_ghada_clicked    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Ajouter_espace_ajouterEts_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modifier_espace_mod_ets_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Afficher_espace_afficher_ets_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_supp_espace_supp_ets_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_ETS_espace_oussema_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_buttonAjouterETS_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_modif_ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonValiderModification_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_treeviewETS_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_NL_Button_tree_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_NL_button_AfficherByRole_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_affiche_Ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualisertrieETS_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonValiderSuppression_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_supp_ets_espace_oussema_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retour_espace_oussema_home_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonRechercherIDModifier_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualisertrie_clicked              (GtkButton       *button,
                                        gpointer         user_data);

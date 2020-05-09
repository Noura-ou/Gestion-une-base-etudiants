#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
    void supprimeclasse(void);
	void moyenneclasse(void);
    void creation(void);
    void lecture(void);
    void affiche_notes(void);
    void ajout(void);
    void recherche(char k[13]);
    void modif(int);
    void suppr(void);
    int c,d;
    char k[13];
    int quitter=0;
int main()
{
    void recherche(char k[13])
 {
     FILE *F;
     struct Etudiant Etud;
     int trouve=0;
     long pos;
     F=fopen("Etudiant.dat","rb+");
     if(F==NULL)
     {
         printf("Ouverture impossible du fichier de donees!!");
         getch();
     }
     else
     {
         while(trouve==0 && !feof(F))
         {
             pos=ftell(F);
             fread(&Etud,sizeof(Etud),1,F);
             if (strcmpi(Etud.nom,k)==0)
			   {
			   trouve=1;
		       }
         }
         if(trouve==1 )
         {
            printf("Donnees actuelles de l'etudiant:\n\tnumero:%d  \n\tNom: %s \n\tPrenom:%s  \n\tnote d'exam: %.2f\n\tnote de projet: %.2f\n",Etud.numero,Etud.nom,Etud.prenom,Etud.noteexam,Etud.noteprojet);
            printf("\n\nPresser une touche pour continuer!");
            getch();
            fclose(F);
		}
		else{
			printf("l'etudiant n'existe pas!!");
			printf("\n\nPresser une touche pour continuer!");
            getch();
            fclose(F);
		}
		}
}

// fonction modifier les informations d'un etudiant //
 void modif(int d)
 {
     FILE *F;
     struct Etudiant Etud;
     int trouve=0;
     long pos;
     char rep;
     F=fopen("Etudiant.dat","rb+");
     if(F==NULL)
     {
         printf("Ouverture impossible du fichier de donees!!");
         getch();
     }
     else
     {
         while(trouve==0 && !feof(F))
         {
             pos=ftell(F);
             fread(&Etud,sizeof(Etud),1,F);
             if(Etud.numero==d)
			   {
			   trouve=1;
		       }
         }
         if(trouve==1 )
         {
             printf("Donnees actuelles de l'etudiant:\n\tnumero:%d  \n\tNom: %s \n\tPrenom:%s  \n\tnote d'exam: %.2f\n\tnote de projet: %.2f\n",Etud.numero,Etud.nom,Etud.prenom,Etud.noteexam,Etud.noteprojet);
             printf("Modifier le numero? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\tnumero: ");
                 scanf("%d",&Etud.numero);
             }
             printf("Modifier le nom? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\tNom: ");
                 fflush(stdin);
                 gets(Etud.nom);
             }
             printf("Modifier le prenom? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\tPrenom: ");
                 fflush(stdin);
                 gets(Etud.prenom);
             }
             printf("Modifier la note de l'exam? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\tNote exam: ");
                 scanf("%f",&Etud.noteexam);
             }
             printf("Modifier la note de projet? (O/N): ");
             fflush(stdin);
             rep=getchar();
             if(rep=='o' || rep=='O')
             {
                 printf("\tnote projet: ");
                 scanf("%f",&Etud.noteprojet);
             }
             fseek(F,pos,SEEK_SET);
             fwrite(&Etud,sizeof(Etud),1,F);
             fclose(F);
         }
         else
		 {
		   printf("Etudiant non trouver!!!");
		   printf("\n\nPresser une touche pour continuer!");
           getch();
           fclose(F);
	     }
     }
 }

// fonction qui supprime un etudiant //
void suppr(void)
{
    FILE *F,*Ftemp;
    struct Etudiant Etud;
    char nomEt[41], prenomEt[41];
    int i=0;
    F=fopen("Etudiant.dat","rb");
    Ftemp=fopen("temp.dat","wb+");
    if(F==NULL)
    {
        printf("Ouverture du fichier de donnees impossible!!");
        getch();
    }
    else if(Ftemp==NULL)
    {
        printf("Creation du fichier temporaire impossible!!");
        getch();
    }
    else
    { int c=0;
        printf("Nom de l'etudiant: ");
        fflush(stdin);
        gets(nomEt);
        while(fread(&Etud,sizeof(Etud),1,F))
		{
		   if(strcmpi(Etud.nom,nomEt) )
		        fwrite(&Etud,sizeof(Etud),1,Ftemp);
		     else
		     c+=1;
	    }
	    if (c==0)
	    {
	    	printf("l'etudiant n'existe pas !!!");
		}
		else
		{
			printf("votre etudiant est bien supprime !!");
		}
	    fclose(F);
        fclose(Ftemp);
        remove("Etudiant.dat");
        rename("temp.dat","Etudiant.dat");
		}
        printf("\n\nPresser une touche pour continuer!");
        getch();

}
void affiche_notes(void){
	int compt=0;
    struct Etudiant Etud ;
    FILE *F;
     F=fopen("Etudiant.dat","rt");
	  if(F==NULL)
            printf("le fichier n'a pas encore ete cree!!");
      else
        {
            if(fread(&Etud,sizeof(Etud),1,F)<1)
       	       printf("le fichier contient %d eleve(s)\n",compt);
            else
            printf("\t numero \t note d'exam \t note du projet");
               while(feof(F)==0)
                     {
                        if(Etud.numero!=-1)
                           {
                              printf("\n\t  %d  \t          %.2f      \t    %.2f   ",Etud.numero,Etud.noteexam,Etud.noteprojet);

                              compt++;
                           }
                        if(fread(&Etud,sizeof(Etud),1,F)<1)
       	                   printf("\nle fichier contient %d eleve(s)\n",compt);
                     }
        }
      fclose(F);
      getch();
}
// fonction qui calcule la moyenne de la classe //
void moyenneclasse(void)
{
	float l=0;
	int c=0;
	float moyclass;
	FILE * F;
	struct Etudiant Etud;
	F=fopen("Etudiant.dat","rb+");
	do
	{
	   if(!fread(&Etud,sizeof(Etud),1,F))
	   {
	   	l+=((Etud.noteexam)+(Etud.noteprojet))/2;
	   	c++;
	   }
	}while(!feof(F));
	moyclass=l/c;
	printf("la moyenne de classe est %.2f",moyclass);
	printf("\n\nPresser une touche pour continuer!");
    getch();
    fclose(F);
}

// fonction qui supprime la classe //
void supprimeclasse(void)
{
	FILE *F;
    struct Etudiant Etud;
   if(remove("Etudiant.dat")==-1){
    	printf("erreeur!!");
   }
   else {remove("Etudiant.dat");
   printf("votre classe est bien supprimer *_*");
   }


    printf("\n\nPresser une touche pour continuer!");
    getch();

}



void change_label (GtkWidget *widget, gpointer data)

{
 /* Recuperation du tableau de pointeur */
 GPtrArray *array = (GPtrArray *)data;
 /* Modification du texte de pLabel par le texte de pEntry */
 gtk_label_set_label(array->pdata[0],
gtk_entry_get_text(array->pdata[1]));
}

struct Etudiant
{
    int numero;
    char nom[41];
    char prenom[41];
    float noteexam;
    float noteprojet;
}


 /* Déclaration des pointeurs pour les Widgets */
GtkWidget *pWindow;
GtkWidget *pLabel;
GtkWidget *pButton1;
GtkWidget *pButton2;
GtkWidget *pButton3;
GtkWidget *pButton4;
GtkWidget *pButton5;
GtkWidget *pButton6;
GtkWidget *pButton7;
GtkWidget *pButton8;


 GtkWidget *pVBox;
 GtkWidget *pEntry;
 /* Déclaration du tableau de pointeur */
 GPtrArray *args;

 /* Initialisation de GTK+*/
 gtk_init(&argc, &argv);

 /* Création de la fenêtre */
 pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 /* Définition de la position au centre */
 gtk_window_set_position(GTK_WINDOW(pWindow),
GTK_WIN_POS_CENTER);
 /* Définition de la taille de la fenetre 320x100 */
 gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 100);


 /* Création de la GtkBox verticale */
 pVBox = gtk_vbox_new(TRUE, 0);
 /* Création du label */
 pLabel=gtk_label_new("Bienvenue !");
 /* Création du bouton */
pButton1 = gtk_button_new_with_label("ajouter eleve");
pButton2 = gtk_button_new_with_label("supprimer eleve");
pButton3 = gtk_button_new_with_label(" affichereleve");
pButton4 = gtk_button_new_with_label("note eleve");
pButton5 = gtk_button_new_with_label("moyenne eleve");
pButton6 = gtk_button_new_with_label("moyenne classe");
pButton7 = gtk_button_new_with_label("quitter");
pButton8 = gtk_button_new_with_label("supprimer classe");


 /* Création du textbox */
 pEntry = gtk_entry_new();
 /* Création du tableau de pointeur*/
 args = g_ptr_array_new();

 /* Remplissage du tableau de pointeurs de pLabel et pEntry
*/
 g_ptr_array_add(args, pLabel);
 g_ptr_array_add(args, pEntry);

 /* Connexion du signal "destroy" de la fenetre */
 g_signal_connect(G_OBJECT(pWindow), "destroy",
G_CALLBACK(gtk_main_quit), NULL);
 /* Connexion du signal "clicked" du bouton */
g_signal_connect(G_OBJECT(pButton1), "clicked",G_CALLBACK(ajout), args);
;
g_signal_connect(G_OBJECT(pButton2), "clicked",G_CALLBACK(change_label), args);
;g_signal_connect(G_OBJECT(pButton3), "clicked",G_CALLBACK(change_label), args);
;
g_signal_connect(G_OBJECT(pButton4), "clicked",G_CALLBACK(change_label), args);
;g_signal_connect(G_OBJECT(pButton5), "clicked",G_CALLBACK(change_label), args);
;
g_signal_connect(G_OBJECT(pButton6), "clicked",G_CALLBACK(change_label), args);
;g_signal_connect(G_OBJECT(pButton7), "clicked",G_CALLBACK(change_label), args);
;
g_signal_connect(G_OBJECT(pButton8), "clicked",G_CALLBACK(change_label), args);
;


 /* Injection du Label et Button dans la VBox*/
gtk_box_pack_start(GTK_BOX(pVBox), pLabel, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton1, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton2, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton3, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton4, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton5, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton6, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton7, TRUE, FALSE, 0);
gtk_box_pack_start(GTK_BOX(pVBox), pButton8, TRUE, FALSE, 0);




 gtk_box_pack_start(GTK_BOX(pVBox), pEntry, TRUE, FALSE, 0);
 /* Ajout de la GtkVBox dans la fenêtre */
 gtk_container_add(GTK_CONTAINER(pWindow), pVBox);
 /* Affichage et démarrage de la boucle even.*/
 gtk_widget_show_all(pWindow);
 gtk_main();
/* Fin ! */
 return EXIT_SUCCESS;
}






        do
    {
        system("color 75");
        system("cls");
        printf("      -------------****Menu****-------------\n\n      1- Creer une nouvelle liste d'etudiants.\n      2- Afficher la liste d'etudiants.\n      3- Ajouter un nouvel etudiant.\n      4- la moyenne de la classe .\n      5- Afficher les donnees d'un etudiant.\n      6- Modifier un etudiant.\n      7- Supprimer un etudiant.\n      8- supprimer la classe .\n      9- afficher les notes.\n      10- Quitter.\n\n");
        scanf("%d",&c);
        Restart:
            switch(c)
            {
            case 1:
               system("cls");
                creation();
                break;
            case 2:
                system("cls");
                lecture();
                break;
            case 3:
                system("cls");
                ajout();
                break;
            case 4:
            	system("cls");
            	moyenneclasse();
            	break;
            case 5:
                system("cls");
                printf("Entrer le nom de l'etudiant recherche: ");
                fflush(stdin);
                scanf("%s",k);
                recherche(k);
                break;
            case 6:
               system("cls");
                printf("Entrer le numero de l'etudiant dont vous voulez modifier les donnees: ");
                scanf("%d",&d);
                modif(d);
                break;
            case 7:
                system("cls");
                suppr();
                break;
            case 8:
			     system("cls");
				 supprimeclasse();
				 break;
            case 10:
            	quitter=1;
                break;
            case 9:
            	system("cls");
            	affiche_notes();
            	break;
            default:
                printf("Vous avez entrer une valeur inexistante dans le menu. Veuillez reessayer: ");
                scanf("%d",&c);
                goto Restart;
            }
    }while(quitter==0);
    return 0;
}


void creation(void)
{
    FILE *F;
    struct Etudiant Etud;
    char rep;
    F=fopen("Etudiant.dat","wb+");
    if(F==NULL)
    {
        printf("Creation de la liste impossible!!");
        getch();
        exit(-1);
    }
    else{
    	printf("votre classe a ete bien creer *_*");
	}
    fclose(F);
    printf("\n\nPresser une touche pour continuer!");
    getch();
}
//la definition de la fonction d'affichage
 void lecture(void)
 {
    int compt=0;
    struct Etudiant Etud ;
    FILE *F;
     F=fopen("Etudiant.dat","rt");
	  if(F==NULL)
            printf("le fichier n'a pas encore ete cree!!");
      else
        {
            if(fread(&Etud,sizeof(Etud),1,F)<1)
       	       printf("le fichier contient %d eleve(s)\n",compt);
            else
            printf("    nom     \t  prenom    \t numero \t note d'exam \t note du projet");
               while(feof(F)==0)
                     {
                        if(Etud.numero!=-1)
                           {
                              printf("\n  %s \t  %s  \t  %d  \t          %.2f      \t    %.2f   ",Etud.nom,Etud.prenom,Etud.numero,Etud.noteexam,Etud.noteprojet);

                              compt++;
                           }
                        if(fread(&Etud,sizeof(Etud),1,F)<1)
       	                   printf("\nle fichier contient %d eleve(s)\n",compt);
                     }
        }
      fclose(F);
      getch();
}

void ajout(void)
 {
 	int num;
     FILE *F;
     struct Etudiant Etud;
     F=fopen("Etudiant.dat","ab+");
     if(F==NULL)
     {
         printf("Ouverture impossible du fichier de donnees!!");
         getch();
     }
     else
     {
     	printf("\n\tdonnez le numero: ");
        scanf("%d",&num);
         int comp=0;
         do
         {
         	comp=0;
         	rewind(F);
         while(!feof(F)) {
          fread(&Etud,sizeof(Etud),1,F);
           if(Etud.numero==num){
	           comp+=1;
              }
          }
          if(comp==0)
          {
          	Etud.numero=num;
		  }
		  else
		  {
		  		printf("ce numero existe!!  \ndonnez un autre numero!:");
            scanf("%d",&num);
		  }
          }while(comp!=0);
        printf("\tdonnez le Nom: ");
        fflush(stdin);
        gets(Etud.nom);
        printf("\tdonnez le Prenom: ");
        fflush(stdin);
        gets(Etud.prenom);
        printf("\tla note de l'exam: ");
        scanf("%f",&Etud.noteexam);
        while(Etud.noteexam<0 || Etud.noteexam>20){
        printf("Entrez une note comprise entre (0 et 20)! :");
      	scanf("%f",&Etud.noteexam);
		}
        printf("\tla note du projet ");
        scanf("%f",&Etud.noteprojet);
        while(Etud.noteprojet<0 || Etud.noteprojet>20){
        printf("Entrez une note comprise entre (0 et 20)! :");
        scanf("%f",&Etud.noteprojet);
	}
        fflush(stdin);
        fwrite(&Etud,sizeof(Etud),1,F);
        fclose(F);

 }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
/*************************** STRUCTURES **************************************/
//informations du produit
struct data_article
{
       int code_article;
       char designation[15];
       int code_famille;
       int prix_achat;
       int code_fournisseur;
       long quant_stock;
}; typedef struct data_article DATA_ARTICLE;

//structure des noeuds de l'ABR produit
struct abr_article
{
       DATA_ARTICLE da;
       struct abr_article* gauche;
       struct abr_article* droite;
}; typedef struct abr_article ABR_ARTICLE;

//informations du fournisseur
struct data_fournisseur
{
       int code_fournisseur;
       char raison_sociale[15];
}; typedef struct data_fournisseur DATA_FOURNISSEUR;

//structure des noeuds de l'ABR du fournisseurs
struct abr_fournisseur
{
       DATA_FOURNISSEUR dfo;
       struct abr_fournisseur *gauche;
       struct abr_fournisseur *droite;
}; typedef struct abr_fournisseur ABR_FOURNISSEUR;

//informations de la famille
struct data_famille
{
    int code_famille;
    char designation[15];
}; typedef struct data_famille DATA_FAMILLE;

//structure des noeuds de l'ABR du famille
struct abr_famille
{
       DATA_FAMILLE dfa;
       struct abr_famille *gauche;
       struct abr_famille *droite;
}; typedef struct abr_famille ABR_FAMILLE;

//informations du procede
struct data_procede
{
       int code;
       int qt;
}; typedef struct data_procede DATA_PROCEDE;

//structure des noeuds de l'ABR du procede
struct arbre_procede
{
       DATA_PROCEDE dp;
       struct arbre_procede *frere;
       struct arbre_procede *fils;
};typedef struct arbre_procede ARBRE_PROCEDE;

//information du production
struct data_production
{
       int code;
       int qt;
       int prix;
}; typedef struct data_production DATA_PRODUCTION;

//structure des noeuds de la liste production
struct liste_production
{
       DATA_PRODUCTION dl;
       struct liste_production *suivant;
};typedef struct liste_production LISTE_PRODUCTION;

//structure noeud de la liste code
struct liste_code
{
    int code;
    int nb;
    struct liste_code *suivant;
};typedef struct liste_code LISTE_CODE;

//structure noeud de la liste code
struct liste_produit
{
    int code;
    int qt;
    struct liste_produit *suivant;
};typedef struct liste_produit LISTE_PRODUIT;

//structure noeud de la liste pointeur
struct liste_pointer
{
    ARBRE_PROCEDE *pointer;
    struct liste_pointer *suivant;

};typedef struct liste_pointer LISTE_POINTER;

/*****************************************************************************/
/*************************** PROTOTYPES **************************************/

/**************************** Quetion 0 **************************************/
void chargement_arbre(ABR_ARTICLE **article,ABR_FOURNISSEUR **fournisseur,ABR_FAMILLE **famille,ARBRE_PROCEDE **procede);
char choix_option();
void panel_option(ABR_ARTICLE *article,ABR_FAMILLE *famille,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *procede,int choix_g);

ABR_ARTICLE* chargement_abr_article();
void insere_noeud_article(ABR_ARTICLE** article,DATA_ARTICLE data);
void affichage_abr_article(ABR_ARTICLE* article);
void affichage_data_article(DATA_ARTICLE data );

ABR_FOURNISSEUR* chargement_abr_fournisseur();
void insere_noeud_fournisseur(ABR_FOURNISSEUR** fournisseur, DATA_FOURNISSEUR data);
void affichage_abr_fournisseur(ABR_FOURNISSEUR* fournisseur);
void affichage_data_fournisseur(DATA_FOURNISSEUR data);

ABR_FAMILLE* chargement_abr_famille();
void insere_noeud_famille(ABR_FAMILLE** famille, DATA_FAMILLE data);
void affichage_abr_famille(ABR_FAMILLE* famille);
void affichage_data_famille(DATA_FAMILLE data);

ARBRE_PROCEDE* chargement_arbre_procede();
void insere_noeud_procede(ARBRE_PROCEDE** procede,int code_pere,int code_fils,int qt);
ARBRE_PROCEDE *cherche_noeud(ARBRE_PROCEDE *procede, int code);
void duplique_arbre(ARBRE_PROCEDE **dest, ARBRE_PROCEDE *src);
void reorganise(ARBRE_PROCEDE **racine, int code);
void free_arbre(ARBRE_PROCEDE *racine);
void affichage_arbre_procede(ARBRE_PROCEDE* procede);
void affichage_fils(ARBRE_PROCEDE* premier_fils);

/*****************************************************************************/
/**************************** Quetion 1 **************************************/

int choix_mode();

void mode_code(ABR_ARTICLE* article,ARBRE_PROCEDE* procede);
int charger_code_produit();
void chercher_nom_produit(ABR_ARTICLE* article,int code_produit,char** s);
int famille_prix_cpse(ABR_ARTICLE* article,int code_cpse,int *prix);
void affichage_cpsant_produit(ARBRE_PROCEDE* procede,ABR_ARTICLE* article,int code_cpse);
void chargement_liste_production(ARBRE_PROCEDE *racine,LISTE_PRODUCTION **production,int *multip);
LISTE_PRODUCTION* cherche_liste_production(LISTE_PRODUCTION *production,int code);
void chargement_prix_production(ABR_ARTICLE *article,LISTE_PRODUCTION **production);
int cherche_prix_article(ABR_ARTICLE *article,int code);
void affichage_liste_production(ABR_ARTICLE *article,LISTE_PRODUCTION *production);
void affichage_cout_matiere(LISTE_PRODUCTION *production);

void mode_nom(ABR_ARTICLE* article,ARBRE_PROCEDE* procede);
void charger_nom_produit(char nom_produit[]);
int convert_nom_code(ABR_ARTICLE* article,char nom_produit[]);

/*****************************************************************************/
/**************************** Quetion 2 **************************************/

void affichage_designation_cout(ABR_ARTICLE *article,ARBRE_PROCEDE *procede);
void chargement_liste_code(ABR_ARTICLE *article,LISTE_CODE **l_c);
void affichage_produit_fini(ARBRE_PROCEDE *procede,ABR_ARTICLE *article,int code);

/*****************************************************************************/
/**************************** Quetion 3 **************************************/

void affichage_liste_MP(ABR_ARTICLE *article,ARBRE_PROCEDE *procede);
void chargement_liste_MP(ABR_ARTICLE *article,ARBRE_PROCEDE *procede,LISTE_CODE **l_c);

/*****************************************************************************/
/**************************** Quetion 4 **************************************/
void affichage_nbarticle_parfournisseur(ABR_ARTICLE *article,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *procede);
void initialisation_liste(ABR_FOURNISSEUR *fournisseur,LISTE_CODE **liste);
void chercher_code_fournisseur(ABR_ARTICLE *article,int code,int *code_fournisseur);
void ajout_liste_nb(LISTE_CODE *l_cnb,int code);
int ajout_liste_exist(LISTE_CODE *l_exist,int code);
void affichage_liste(ABR_FOURNISSEUR *fournisseur,LISTE_CODE *l_cnb);
void remplissage_liste_parniveau(ABR_ARTICLE *article,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *niveau,LISTE_CODE *l_cnb,LISTE_CODE *l_exist);
void save_pointer(ARBRE_PROCEDE* procede,LISTE_POINTER **l_p);
int verifie_matiere_premiere(ABR_ARTICLE *article,int *code);
void affichage_nom_fournisseur(ABR_FOURNISSEUR *fournisseur,int code);

/*****************************************************************************/
/**************************** Quetion 5 **************************************/
void programme_production();
LISTE_PRODUIT *chargement_liste_produit();
void insere_liste_prod(LISTE_PRODUIT **l_prod,int code,int qt);
void chargement_liste_composant(ARBRE_PROCEDE* procede,LISTE_PRODUCTION **composant,int code_cpse);
LISTE_PRODUCTION *intialisation_code(LISTE_PRODUCTION *composant);
void insere_en_fin(LISTE_PRODUCTION **q_s,int code);
LISTE_PRODUCTION *cherche_dernier(LISTE_PRODUCTION *q_s);
void chargement_liste_qt_dispo(ABR_ARTICLE *article,LISTE_PRODUCTION *q_s);
int cherche_qt(ABR_ARTICLE *article,int code);
void affichage_liste_qt(ABR_ARTICLE *article,LISTE_PRODUCTION *composant,LISTE_PRODUCTION *quant_stock,int qt);



/*****************************************************************************/
/********************************* MAIN **************************************/
int main()
{
    ABR_ARTICLE* article;
    ABR_FOURNISSEUR* fournisseur;
    ABR_FAMILLE* famille;
    ARBRE_PROCEDE* procede;

	char choix_g;

	chargement_arbre(&article,&fournisseur,&famille,&procede);//Quetion 0.
	do
    {
        choix_g=choix_option();//Quetion 0.
        panel_option(article,famille,fournisseur,procede,choix_g);

    }while(choix_g != '6');
    exit(EXIT_SUCCESS);
	system("pause");
	return 0;
}
/*****************************************************************************/
/**************************** FONCTIONS **************************************/


/**************************** Quetion 0 **************************************/
void chargement_arbre(ABR_ARTICLE **article,ABR_FOURNISSEUR **fournisseur,ABR_FAMILLE **famille,ARBRE_PROCEDE **procede)//chargement des fichier article,fournisseur,procede et famille dans des arbres.
{
    printf("#########################################################################################\n");
    printf("                 Bienvenue dans le gestionnaire de stock\n");
    printf("#########################################################################################\n\n");

	printf("Ce programme permet de fournir quelques fonctions de getion sur un stock donnee...\n");
    printf("Appuiez sur  la touche ENTRE pour commencer\n\n");

    int c;
	while((c=getchar())!='\n')
	{
	    printf("Veuillez appuier sur ENTRE\n");
         printf("ATTENTION SI VOUS VOULEZ QUITTER LE PROGRAMME TAPPEZ x\n");

	}

    *article = chargement_abr_article();//chargement specifique pour l'arbre article.
    printf("Chargement arbre ARTICLE...en cours..");
    _sleep(1000);//juste pour le decor.
    printf("[OK]\n\n");
    printf("CodeA  Designation      CodeF  Prix   CodeF  Quant\n\n");
    affichage_abr_article(*article);//affichage de l'arbre article.
    printf("#########################################################################################\n");

    *fournisseur = chargement_abr_fournisseur();//chargement specifique pour l'arbre fournisseur.
    printf("Chargement arbre FOURNISSEUR...en cours..");
    _sleep(1000);//juste pour le decor.
    printf("[OK]\n");
    printf("CodeF  RaisonSocial\n\n");
    affichage_abr_fournisseur(*fournisseur);//affichage de l'arbre fournisseur.
    printf("#########################################################################################\n");

    *famille = chargement_abr_famille();//chargement specifique pour l'arbre famille.
    printf("Chargement arbre FAMILLE...en cours..");
    _sleep(1000);//juste pour le decor.
    printf("[OK]\n");
    printf("CodeF  Designation\n\n");
    affichage_abr_famille(*famille);//affichage de l'arbre famille.
    printf("#########################################################################################\n");

    *procede=chargement_arbre_procede();//chargement specifique pour l'arbre procede.
    printf("Chargement arbre PROCEDE...en cours..");
    _sleep(1000);//juste pour le decor.
    printf("[OK]\n");
    printf("CodeCpse  Quant  CodeCpsant  Quant\n\n");
    affichage_arbre_procede(*procede);//affichage de l'arbre procede.
    printf("\n\n");
    printf("#########################################################################################\n");
}

/********************* chargement de l arbre des articles ********************/

ABR_ARTICLE* chargement_abr_article()
{
  ABR_ARTICLE* article;
  char S[100];
  memset(S,'\0', 100);
  FILE* fp;
  DATA_ARTICLE data ;

  if( !(fp = fopen("article.txt","r")))
    return( NULL);
  for ( article = NULL; fgets(S,100,fp);)
     {
     sscanf(S,"%5d%15s%5d%10d%5d%5ld",
               &data.code_article, data.designation, &data.code_famille,
               &data.prix_achat, &data.code_fournisseur, &data.quant_stock);
     insere_noeud_article(&article,data);
     }

  fclose(fp);
  return(article);
}

void insere_noeud_article(ABR_ARTICLE** article,DATA_ARTICLE data)//a chaque appel il y aura une creation d'un noeud dans l'arbre article et linsertion de la partie data.
{
     if(*article)
     {
         if((*article)->da.code_article >= data.code_article)
           insere_noeud_article(&(*article)->gauche,data);
         else
           insere_noeud_article(&(*article)->droite,data);
     }
     else
     {
          (*article) = (ABR_ARTICLE*) malloc ( sizeof (ABR_ARTICLE));
          (*article)->da= data;
          (*article)->gauche=(*article)->droite=NULL;
     }
}

void affichage_abr_article(ABR_ARTICLE* article)//parcour l'arbre article.
{
     if(article)
     {
                affichage_data_article(article->da);
                affichage_abr_article(article->gauche);
                affichage_abr_article(article->droite);
     }
}

void affichage_data_article(DATA_ARTICLE da)//affiche les donnée de chaque noeud.
{
     printf("%5.5d  ",da.code_article);
     printf("%-15.15s  ", da.designation);
     printf("%5.5d  ", da.code_famille);
     printf("%-5.5d  ", da.prix_achat);
     printf("%-5.5d  ", da.code_fournisseur);
     printf("%-5.5ld\n", da.quant_stock);

}

/******************** chargement de l arbre des fournisseurs ******************/

ABR_FOURNISSEUR* chargement_abr_fournisseur()
 {
  ABR_FOURNISSEUR* fournisseur;
  char S[100];
  memset(S, '\0', 100);
  FILE* fp;
  DATA_FOURNISSEUR data;

  if( !(fp = fopen("Fournisseur.txt","r")))
  {
      printf("erreur\n");
      return( NULL);
  }
  for ( fournisseur = NULL; fgets(S,100,fp);)
     {
     sscanf(S,"%5d",&data.code_fournisseur);
     strncpy(data.raison_sociale,S+5,sizeof data.raison_sociale);
     data.raison_sociale[sizeof data.raison_sociale]='\0';
     insere_noeud_fournisseur(&fournisseur,data);
     }

  fclose(fp);
  return(fournisseur);
}

void insere_noeud_fournisseur(ABR_FOURNISSEUR** fournisseur, DATA_FOURNISSEUR data)//a chaque appel il y aura une creation d'un noeud dans l'arbre fournisseur et l'insertion de la partie data.
{
     if(*fournisseur)
     {
                     if ((*fournisseur)->dfo.code_fournisseur >= data.code_fournisseur)
                     {
                     insere_noeud_fournisseur(&(*fournisseur)->gauche,data);
                     }
                     else
                     {
                     insere_noeud_fournisseur(&(*fournisseur)->droite,data);
                     }
     }
     else
     {
                   (*fournisseur)= (ABR_FOURNISSEUR*) malloc(sizeof (ABR_FOURNISSEUR));
                   (*fournisseur)->dfo = data;
                   (*fournisseur)->droite = (*fournisseur)->gauche = NULL;
     }
}

void affichage_abr_fournisseur(ABR_FOURNISSEUR* fournisseur)//parcour l'arbre fournisseur.
{
     if(fournisseur)
     {
                    affichage_data_fournisseur(fournisseur->dfo);
                    affichage_abr_fournisseur(fournisseur->gauche);
                    affichage_abr_fournisseur(fournisseur->droite);
     }
}

void affichage_data_fournisseur(DATA_FOURNISSEUR data)//affiche les donnée de chaque noeud.
{
     printf("%-5.5d  ", data.code_fournisseur);
     printf("%s\n",data.raison_sociale);
}

/********************* chargement de l arbre des familles *********************/

ABR_FAMILLE* chargement_abr_famille()
 {
  ABR_FAMILLE* famille;
  char S[100];
  memset(S, '\0', 100);
  FILE* fp;
  DATA_FAMILLE data;

  if( !(fp = fopen("Famille.txt","r")))
  {
      printf("erreur\n");
      return( NULL);
  }
  for ( famille = NULL; fgets(S,100,fp);)
     {
     sscanf(S,"%5d",&data.code_famille);
     strncpy(data.designation,S+5,sizeof (data.designation));
     data.designation[sizeof data.designation-1]='\0';
     insere_noeud_famille(&famille,data);
     }

  fclose(fp);
  return(famille);
}

void insere_noeud_famille(ABR_FAMILLE** famille, DATA_FAMILLE data)//a chaque appel il y aura une creation d'un noeud dans l'arbre famille et l'insertion de la partie data.
{
     if(*famille)
     {
                     if ((*famille)->dfa.code_famille >= data.code_famille)
                     {
                     insere_noeud_famille(&(*famille)->gauche,data);
                     }
                     else
                     {
                     insere_noeud_famille(&(*famille)->droite,data);
                     }
     }
     else
     {
                   (*famille)= (ABR_FAMILLE*) malloc(sizeof (ABR_FAMILLE));
                   (*famille)->dfa = data;
                   (*famille)->droite = (*famille)->gauche = NULL;
     }
}

void affichage_abr_famille(ABR_FAMILLE* famille)//parcour l'arbre famille.
{
     if(famille)
     {
                    affichage_data_famille(famille->dfa);
                    affichage_abr_famille(famille->gauche);
                    affichage_abr_famille(famille->droite);
     }
}

void affichage_data_famille(DATA_FAMILLE data)//affiche les donnée de chaque noeud.
{
     printf("%-5.5d  ", data.code_famille);
     printf("%s\n",data.designation);
}

/******************* chargement de l arbre des procede ************************/

ARBRE_PROCEDE* chargement_arbre_procede()
 {
  ARBRE_PROCEDE* procede;
  char S[100];
  memset(S, '\0', 100);
  FILE* fp;
  int code_pere,code_fils,qt;
  DATA_PROCEDE dp;

  if( !(fp = fopen("Procede.txt","r")))
  {
      printf("erreur\n");
      return( NULL);
  }
  for ( procede = NULL; fgets(S,100,fp);)
     {
     sscanf(S,"%5d",&code_pere);
     sscanf(S+5,"%5d",&code_fils);
     sscanf(S+10,"%5d",&qt);
     insere_noeud_procede(&procede,code_pere,code_fils,qt);
     }

  fclose(fp);
  return(procede);
}

void insere_noeud_procede(ARBRE_PROCEDE** procede,int code_pere,int code_fils,int qt)//creation des noeud de l'arbre procede avec organisation pour garantir une hiarchie correcte.
{
	ARBRE_PROCEDE *fils, *p_pere, *p_compose, *pere;
	fils = (ARBRE_PROCEDE *) malloc(sizeof(ARBRE_PROCEDE));
	fils->dp.code = code_fils;
	fils->dp.qt=qt;
	fils->fils = fils->frere = NULL;
	if(p_compose = cherche_noeud(*procede, code_fils))//chercher si le compose existe deja.
		duplique_arbre(&fils->fils, p_compose->fils);//s'il existe on duplique le sous arbre.
		reorganise(procede, code_fils);//et on le reinjecte dans la nouvelle position.
	if(p_pere = cherche_noeud(*procede,code_pere))//on cherche si le pere existe ou pas!!!Si oui on injecte le composant comme fils.Sinon il sera consideré comme nouvelle racine.
        {
		fils->frere = p_pere->fils;
		p_pere->fils = fils;
	    }
	else {
		pere = (ARBRE_PROCEDE *) malloc(sizeof(ARBRE_PROCEDE));
		pere->dp.code = code_pere;
		pere->dp.qt = 1;
		pere->frere = *procede;
		pere->fils = fils;
		*procede = pere;
	}
}

ARBRE_PROCEDE *cherche_noeud(ARBRE_PROCEDE *procede, int code)//cette fonction permet de chercher dans l'arbre procede selon un code donné.
{
      ARBRE_PROCEDE *p = NULL;
      if(procede)
      {
                 if(procede->dp.code== code)
                 {
                                                      p=procede;
                 }
                 else
                 {
                     p = cherche_noeud(procede->frere,code);
                     if (p==NULL)
                     p = cherche_noeud(procede->fils,code);
                 }
      }
      return(p);
}

void duplique_arbre(ARBRE_PROCEDE **dest, ARBRE_PROCEDE *src)//copier un arbre source vers un arbre destination.
{
    ARBRE_PROCEDE* p;
	if(src)
    {

		 p = (ARBRE_PROCEDE*) malloc(sizeof(ARBRE_PROCEDE));
		 p->dp = src->dp;
		 p->frere = p->fils = NULL;
		 (*dest)=p;

             duplique_arbre(&((*dest)->fils), src->fils);
             duplique_arbre(&((*dest)->frere), src->frere);

	}
}

void reorganise(ARBRE_PROCEDE **racine, int code)//permet de deplacer des branches de l'arbre pour eviter les redondances.
{
	ARBRE_PROCEDE *p;
	if(*racine) {
		if(code == (*racine)->dp.code) {
			p = *racine;
			*racine = (*racine)->frere;
			free_arbre(p->fils); // libérer l'arbre fils
			free(p); // puis le noeud courant
		}
		else
			reorganise(&(*racine)->frere, code);
	}
}

void free_arbre(ARBRE_PROCEDE *racine)
{
	if(racine) {
		free_arbre(racine->fils);
		free_arbre(racine->frere);
		free(racine);
	}
}

void affichage_arbre_procede(ARBRE_PROCEDE* procede)
{
     if(procede)
     {
               printf("%-5.5d     %-5.5ld\n",procede->dp.code,procede->dp.qt);
               if(procede->fils)
               {

                                affichage_fils(procede->fils);
               }

               affichage_arbre_procede(procede->frere);
    }
}

void affichage_fils(ARBRE_PROCEDE* premier_fils)
{
     if(premier_fils)
     {
                     printf("\t\t %-5.5d       %-5.5ld\n",premier_fils->dp.code,premier_fils->dp.qt);
                     affichage_fils(premier_fils->frere);
                     affichage_fils(premier_fils->fils);
     }
}

/********************* chargement des choix d'options *************************/

char choix_option()
{
    char choix_g;

    printf("Veuillez choisir une option parmit la liste :\n\n");
	printf("1-Afficher pour un produit les articles qui le composes,les quantites et le cout matiere.\n");
	printf("2-Afficher la designation et le cout matiere des produit fini.\n");
	printf("3-Afficher les articles qui n'intervient dans aucune composition de produit fini ou semmi fini.\n");
	printf("4-Afficher ,pour chaque fournisseur, le nombre d'article dont il fournit au moins l'un des matieres premieres\n");
	printf("5-Verifier la faisabilite d'un programme de production et afficher les besoins et les manques en matiere premieres\n");
	printf("6-EXIT \n\n");
	do
    {

        choix_g=getchar();
        fflush(stdin);
        if(choix_g!='1' && choix_g!= '2' && choix_g!='3' && choix_g!='4' && choix_g!='5' && choix_g!='6')
        {
            printf("CHOIX ERRONE\n");
	        printf("Ressayez a nouveau\n\n");
        }
    }
    while(choix_g < '1' || choix_g > '6');

    return choix_g;

}

void panel_option(ABR_ARTICLE *article,ABR_FAMILLE *famille,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *procede,int choix_g)
{
    int choix;
    switch(choix_g)
	{
	   case '1' :
	                printf("\n\n");
                	choix=choix_mode();
					if (choix==1)
					  mode_code(article,procede);//Quetion 1.
					else
					  mode_nom(article,procede);//Quetion 1.
                    printf("#########################################################################################\n");
					break;
	   case '2' :
	                printf("\n\n");
                    affichage_designation_cout(article,procede);//Quetion 2.
                    printf("#########################################################################################\n");
	                break;
	   case '3' :
	                printf("\n\n");
                    affichage_liste_MP(article,procede);//Quetion 3.
                    printf("#########################################################################################\n");
	                break;
	   case '4' :
                    printf("\n\n");
	                affichage_nbarticle_parfournisseur(article,fournisseur,procede);//Quetion 4.
	                //affichage_abr_article(article);
	                //affichage_abr_fournisseur(fournisseur);
	                //affichage_arbre_procede(procede);
	                break;
	   case '5' :
	                printf("\n\n");
                    programme_production(article,procede);//Quetion 5.
                    printf("#########################################################################################\n");
	                break;
	}
}

/*****************************************************************************/
/**************************** Quetion 1 **************************************/

int choix_mode()
{
     int mode;
     do
     {
                      printf("#########################################################################################\n");
                      printf("                    Veuillez choisir la valeur a introduir                    \n");
                      printf("                      1 :code produit     2 :Nom produit                      \n");
                      printf("                                        ");
                      fflush(stdin);
                      scanf("%d",&mode);
                      printf("#########################################################################################\n");
     }
     while(mode!=1 && mode!=2);
     return(mode);
}

void mode_code(ABR_ARTICLE* article,ARBRE_PROCEDE* procede)
{
     int code_produit;
     int prix_produit;
     int code_famille;
     char* s;


     code_produit=charger_code_produit();//lire le code fournit par l'utilisateur sur l'ecran.
     chercher_nom_produit(article,code_produit,&s);//cherche le nom du produit par code.
     printf("Le produit demande est : %s\n",s);
     code_famille = famille_prix_cpse(article,code_produit,&prix_produit);//donne code famille et le prix du produit.
     if(code_famille!=3)
     {
          affichage_cpsant_produit(procede,article,code_produit);
     }
     else if(code_famille==3)
     {
          printf("Ce produit est une matiere premiere\n");
     }

     printf("Le prix du produit est : %d\n",prix_produit);
     printf("#########################################################################################\n");


}

int charger_code_produit()
{
     int code;
     do
     {
                      printf("#########################################################################################\n");
                      printf("                      Veuillez donner le code du produit                      \n");
                      printf("                                        ");
                      fflush(stdin);
                      scanf("%d",&code);
                      printf("#########################################################################################\n");
     }
     while(code>99999 && code<0);
     return(code);
}

void chercher_nom_produit(ABR_ARTICLE* article,int code_produit,char** s)
{
      if(article)
      {
                 if(article->da.code_article==code_produit)
                 {
                   *s= article->da.designation;
                 }
                 else
                 {
                     chercher_nom_produit(article->droite,code_produit,s);
                     chercher_nom_produit(article->gauche,code_produit,s);
                 }
      }

}

int famille_prix_cpse(ABR_ARTICLE* article,int code_cpse,int *prix)
{
      int k=0;
      if(article)
      {
                 if((article->da).code_article == code_cpse)
                 {
                                                       *prix = (article->da).prix_achat;
                                                       k= (article->da).code_famille;
                 }
                 else
                 {
                     k = famille_prix_cpse(article->droite,code_cpse,prix);
                     if (k==0)
                     k = famille_prix_cpse(article->gauche,code_cpse,prix);
                 }
      }
      return(k);
}

void affichage_cpsant_produit(ARBRE_PROCEDE* procede,ABR_ARTICLE* article,int code_cpse)
{
     if(procede)
     {

              if((procede->dp).code==code_cpse)
                {
                                               int multip = 1;
                                               LISTE_PRODUCTION *production = NULL;
                                               chargement_liste_production(procede->fils,&production,&multip);
                                               chargement_prix_production(article,&production);
                                               printf("Ce produit est compose de :\n");
                                               affichage_liste_production(article,production);
                                               affichage_cout_matiere(production);
                }
                else
                {
                    affichage_cpsant_produit(procede->fils,article,code_cpse);
                    affichage_cpsant_produit(procede->frere,article,code_cpse);
                }
     }
}

void chargement_liste_production(ARBRE_PROCEDE *racine,LISTE_PRODUCTION **production,int *multip)
{

     if (racine)
     {
                 int m = *multip;
                if (racine->fils == NULL)
                {
                                 LISTE_PRODUCTION *p1=NULL;
                                 p1=cherche_liste_production(*production,(racine->dp).code);
                                 if(p1)
                                 {
                                                         (p1->dl).qt=((p1->dl).qt)+(*multip)*((racine->dp).qt);

                                 }
                                 else
                                 {
                                     LISTE_PRODUCTION *p2;
                                     p2 = (LISTE_PRODUCTION*) malloc(sizeof(LISTE_PRODUCTION));
                                     (p2->dl).code = (racine->dp).code;
                                     (p2->dl).qt= ((racine->dp).qt)*(*multip);
                                     p2->suivant=(*production);
                                     (*production)=p2;
                                 }
               }
               else
                {
                   *multip=(*multip)*((racine->dp).qt);
                   chargement_liste_production(racine->fils,production,multip);
                }
                chargement_liste_production(racine->frere,production,&m);
     }
}

LISTE_PRODUCTION* cherche_liste_production(LISTE_PRODUCTION *production,int code)
{
	if(production)
	{
                  if(production->dl.code==code)
                    return(production);
                  return(cherche_liste_production(production->suivant,code));
    }
    return(NULL);
}

void chargement_prix_production(ABR_ARTICLE *article,LISTE_PRODUCTION **production)
{
     if(*production)
     {
                    LISTE_PRODUCTION *p;
                    int prix = cherche_prix_article(article,(*production)->dl.code);
                    (*production)->dl.prix=(prix) * ((*production)->dl.qt);
                    p = (*production)->suivant;
                    chargement_prix_production(article,&p);
     }
}

int cherche_prix_article(ABR_ARTICLE *article,int code)
{
    int p;
    if(article)
    {

	if((article->da.code_article)==code)
		return article->da.prix_achat;
	if(p = cherche_prix_article(article->droite,code))
		return p;
	return cherche_prix_article(article->gauche, code);
    }
}

void affichage_liste_production(ABR_ARTICLE *article,LISTE_PRODUCTION *production)
{
     char *s;
     if(production)
     {
     chercher_nom_produit(article,production->dl.code,&s);
     printf("%-15.15s Son code est : %-5.5d Sa quantite est : %-5.5d Son prix est : %-5.5d\n",s,production->dl.code,production->dl.qt,production->dl.prix);
     affichage_liste_production(article,production->suivant);
     }
}

void affichage_cout_matiere(LISTE_PRODUCTION *production)
{
     int total;
     for(total=0;production;production=production->suivant)
        total = total + production->dl.prix;
     printf("Le cout matiere total est : %d\n",total);
}

void mode_nom(ABR_ARTICLE* article,ARBRE_PROCEDE* procede)
{
     char nom_produit[15];
     memset(nom_produit, '\0', 15);
     char* s;
     int prix;
     int code_produit;
     int prix_produit;

     charger_nom_produit(nom_produit);
     code_produit=convert_nom_code(article,nom_produit);


      prix_produit = cherche_prix_article(article,code_produit);
      printf("Le produit demande est : %s  Son code est : %d\n",nom_produit,code_produit);
      affichage_cpsant_produit(procede,article,code_produit);
      printf("Le prix du produit est : %d\n",prix_produit);
      printf("#########################################################################################\n");

}

void charger_nom_produit(char nom_produit[])
{
    int i;
                   printf("#########################################################################################\n");
                   printf("                      Veuillez donner le nom du produit                      \n");
                   scanf("%15s*[^\n]\n", nom_produit);
                   printf("#########################################################################################\n");
                   for(i=0;i<15;i++)
                      nom_produit[i]=toupper(nom_produit[i]);
}

int convert_nom_code(ABR_ARTICLE* article,char nom_produit[])
{
    int k=0;
    if(article)
    {
               if(strncmp(nom_produit,article->da.designation,15)==0)
               {
                   return(article->da.code_article);

               }
               else
               {
                   k=convert_nom_code(article->droite,nom_produit);
                   if (k ==0)
                   k=convert_nom_code(article->gauche,nom_produit);
               }
    }
    return(k);
}

/*****************************************************************************/
/**************************** Quetion 2 **************************************/

void affichage_designation_cout(ABR_ARTICLE *article,ARBRE_PROCEDE *procede)
{
     LISTE_CODE *l_c = NULL;
     chargement_liste_code(article,&l_c);
     for(;l_c;l_c=l_c->suivant)
        {
            affichage_produit_fini(procede,article,l_c->code);
        }

}

void chargement_liste_code(ABR_ARTICLE *article,LISTE_CODE **l_c)
{
    if(article)
    {
        if(article->da.code_famille==1)
        {
                                     LISTE_CODE *p;
                                     p = (LISTE_CODE*) malloc(sizeof(LISTE_CODE));
                                     p->code=article->da.code_article;
                                     p->suivant=(*l_c);
                                     (*l_c)=p;
        }
        else
        {
            chargement_liste_code(article->droite,l_c);
            chargement_liste_code(article->gauche,l_c);
        }
    }
}

void affichage_produit_fini(ARBRE_PROCEDE *procede,ABR_ARTICLE *article,int code)
{
    if(procede)
     {

              if((procede->dp).code==code)
                {
                                               int multip = 1;
                                               char *s;
                                               LISTE_PRODUCTION *production = NULL;
                                               chercher_nom_produit(article,code,&s);
                                               printf("%s\n",s);
                                               chargement_liste_production(procede->fils,&production,&multip);
                                               chargement_prix_production(article,&production);
                                               affichage_cout_matiere(production);
                }
                else
                {
                    affichage_produit_fini(procede->fils,article,code);
                    affichage_produit_fini(procede->frere,article,code);
                }
     }
}

/*****************************************************************************/
/**************************** Quetion 3 **************************************/

void affichage_liste_MP(ABR_ARTICLE *article,ARBRE_PROCEDE *procede)
{
    LISTE_CODE *l_c = NULL;
    chargement_liste_MP(article,procede,&l_c);
    printf("Les matiere premiere qui n'intervient dans aucune composition sont :\n\n");
    for(;l_c;l_c=l_c->suivant)
       {
           char *s;
           chercher_nom_produit(article,l_c->code,&s);
           printf("%-15.15s\n",s);
       }

}

void chargement_liste_MP(ABR_ARTICLE *article,ARBRE_PROCEDE *procede,LISTE_CODE **l_c)
{
    if(article)
    {
        if(article->da.code_famille == 3)
        {
            ARBRE_PROCEDE *p=NULL;
            p = cherche_noeud(procede,article->da.code_article);
            if(!p)
            {
                                     LISTE_CODE *l;
                                     l = (LISTE_CODE*) malloc(sizeof(LISTE_CODE));
                                     l->code=article->da.code_article;
                                     l->suivant=(*l_c);
                                     (*l_c)=l;
            }
        }

            chargement_liste_MP(article->droite,procede,l_c);
            chargement_liste_MP(article->gauche,procede,l_c);

    }
}

/*****************************************************************************/
/**************************** Quetion 4 **************************************/

void affichage_nbarticle_parfournisseur(ABR_ARTICLE *article,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *procede)
{
    LISTE_CODE *l_cnb =NULL;
    LISTE_POINTER *l_p = NULL;

    initialisation_liste(fournisseur,&l_cnb);
    save_pointer(procede,&l_p);
    for(;l_p;l_p=l_p->suivant)
    {
        LISTE_CODE *l_exist =NULL;
        initialisation_liste(fournisseur,&l_exist);
        remplissage_liste_parniveau(article,fournisseur,l_p,l_cnb,l_exist);
    }
    affichage_liste(fournisseur,l_cnb);
    printf("#########################################################################################\n\n");
}


void save_pointer(ARBRE_PROCEDE *procede,LISTE_POINTER **l_p)
{
    if(procede)
    {
        if(procede->fils)
        {
            LISTE_POINTER *p;
            p = (LISTE_POINTER*) malloc(sizeof(LISTE_POINTER));
            p = procede->fils;
            p->suivant = (*l_p);
            (*l_p) = p;
        }
        save_pointer(procede->fils,l_p);
        save_pointer(procede->frere,l_p);

    }

}


void initialisation_liste(ABR_FOURNISSEUR *fournisseur,LISTE_CODE **liste)
{

    if(fournisseur)
    {

        LISTE_CODE *p;
        p = (LISTE_CODE*) malloc(sizeof(LISTE_CODE));
        p->code = fournisseur->dfo.code_fournisseur;
        p->nb=0;
        p->suivant=(*liste);
        (*liste)=p;

        initialisation_liste(fournisseur->droite,liste);
        initialisation_liste(fournisseur->gauche,liste);
    }
}

void remplissage_liste_parniveau(ABR_ARTICLE *article,ABR_FOURNISSEUR *fournisseur,ARBRE_PROCEDE *niveau,LISTE_CODE *l_cnb,LISTE_CODE *l_exist)
{
    int code_fournisseur;
    int code_article;
    int exist;

    if(niveau)
    {
        code_article = niveau->dp.code;
        verifie_matiere_premiere(article,&code_article);
        if(code_article !=0 )
        {

            chercher_code_fournisseur(article,niveau->dp.code,&code_fournisseur);
            exist = ajout_liste_exist(l_exist,code_fournisseur);
            if(exist==0)
                 {
                      ajout_liste_nb(l_cnb,code_fournisseur);
                 }
        }
        remplissage_liste_parniveau(article,fournisseur,niveau->frere,l_cnb,l_exist);
    }
}

int verifie_matiere_premiere(ABR_ARTICLE *article,int *code)
{
    if(article)
    {
        if(article->da.code_article==(*code))
        {
            if(article->da.code_famille != 3)
            {
               (*code)=0;
            }
        }
        else
        {
            verifie_matiere_premiere(article->droite,code);
            verifie_matiere_premiere(article->gauche,code);
        }
    }
}

void ajout_liste_nb(LISTE_CODE *l_cnb,int code)
{
    if(l_cnb)
    {
        if(l_cnb->code==code)
            {
                l_cnb->nb=(l_cnb->nb) + 1;
            }
        else
          {
              ajout_liste_nb(l_cnb->suivant,code);
          }
    }
}

int ajout_liste_exist(LISTE_CODE *l_exist,int code)
{
    if(l_exist)
    {
        if(l_exist->code==code)
        {
            if(l_exist->nb==0)
            {
                l_exist->nb= 1;
                return (0);
            }
            else
                return(1);
        }
        else
            ajout_liste_exist(l_exist->suivant,code);

    }
}

void chercher_code_fournisseur(ABR_ARTICLE *article,int code,int *code_fournisseur)
{

    if(article)
    {
        if(article->da.code_article==code)
        {
            *code_fournisseur=article->da.code_fournisseur;
        }
        else
        {
            chercher_code_fournisseur(article->droite,code,code_fournisseur);
            chercher_code_fournisseur(article->gauche,code,code_fournisseur);
        }
    }
}

void affichage_nom_fournisseur(ABR_FOURNISSEUR *fournisseur,int code)
{
    if(fournisseur)
    {
        if(fournisseur->dfo.code_fournisseur==code)
            printf("%-15.15s",fournisseur->dfo.raison_sociale);
        else
        {
            affichage_nom_fournisseur(fournisseur->droite,code);
            affichage_nom_fournisseur(fournisseur->gauche,code);
        }
    }
}

void affichage_liste(ABR_FOURNISSEUR *fournisseur,LISTE_CODE *l_cnb)
{
    if(l_cnb)
    {

        affichage_nom_fournisseur(fournisseur,l_cnb->code);
        printf("  %-5.5d  %d\n",l_cnb->code,l_cnb->nb);
        affichage_liste(fournisseur,l_cnb->suivant);
    }
}

/*****************************************************************************/
/**************************** Quetion 5 **************************************/

void programme_production(ABR_ARTICLE *article,ARBRE_PROCEDE *procede)
{
    LISTE_PRODUIT *production;
    LISTE_PRODUCTION *composant;
    LISTE_PRODUCTION *quant_stock;
    char *s;

    production = chargement_liste_produit();

    for(;production;production=production->suivant)
    {
        chercher_nom_produit(article,production->code,&s);
        printf("%-15.15s\n",s);
        printf("                Code    Quant/unite  Quant_neces  Quant_stock  Quant_manq\n");
        chargement_liste_composant(procede,&composant,production->code);
        quant_stock = intialisation_code(composant);
        chargement_liste_qt_dispo(article,quant_stock);
        affichage_liste_qt(article,composant,quant_stock,production->qt);
        printf("\n");
    }
}


LISTE_PRODUIT *chargement_liste_produit()
{
    LISTE_PRODUCTION *l_prod;
    char s[100];
    memset(s, '\0', 100);
    FILE* fp;
    int code;
    int qt;

    if( !(fp = fopen("progprod.txt","r")))
    {
      printf("erreur\n");
      return( NULL);
    }
    for ( l_prod = NULL; fgets(s,100,fp);)
     {
         sscanf(s,"%5d%5d",&code,&qt);
         insere_liste_prod(&l_prod,code,qt);
     }

     fclose(fp);
     return(l_prod);
}

void insere_liste_prod(LISTE_PRODUIT **l_prod,int code,int qt)
{
        LISTE_PRODUIT *p;
        p = (LISTE_PRODUIT*) malloc(sizeof(LISTE_PRODUIT));
        p->code = code;
        p->qt=qt;
        p->suivant=(*l_prod);
        (*l_prod)=p;

}

void chargement_liste_composant(ARBRE_PROCEDE* procede,LISTE_PRODUCTION **composant,int code_cpse)
{
     if(procede)
     {
         if(procede->dp.code == code_cpse)
                {

                                               int multip = 1;
                                               LISTE_PRODUIT *l_comp = NULL;
                                               chargement_liste_production(procede->fils,&l_comp,&multip);
                                               (*composant)=l_comp;
                }
        else
                {
                    chargement_liste_composant(procede->fils,composant,code_cpse);
                    chargement_liste_composant(procede->frere,composant,code_cpse);
                }

     }

}

LISTE_PRODUCTION *intialisation_code(LISTE_PRODUCTION *composant)
{
    LISTE_PRODUCTION *q_s = NULL;
    for(;composant;composant=composant->suivant)
    {
        insere_en_fin(&q_s,composant->dl.code);
    }
    return(q_s);

}

void insere_en_fin(LISTE_PRODUCTION **q_s,int code)
{
    LISTE_PRODUCTION *p;
    LISTE_PRODUCTION *dernier;
    p = (LISTE_PRODUCTION*) malloc(sizeof(LISTE_PRODUCTION));
    p->dl.code = code;
    p->dl.qt=0;
    p->dl.prix=0;
    p->suivant=NULL;
    if(dernier = cherche_dernier(*q_s))
        {dernier->suivant = p;}
    else
    {
        *q_s = p;
    }

}

LISTE_PRODUCTION *cherche_dernier(LISTE_PRODUCTION *q_s)
{
    if(q_s)
    {

        for(;q_s->suivant;q_s=q_s->suivant)
           ;

    }

    return(q_s);
}

void chargement_liste_qt_dispo(ABR_ARTICLE *article,LISTE_PRODUCTION *q_s)
{
    int qt;
        for(;q_s;q_s=q_s->suivant)
        {
        q_s->dl.qt = cherche_qt(article,q_s->dl.code);
        }
}

int cherche_qt(ABR_ARTICLE *article,int code)
{
    int k=0;
    if(article)
    {
        if(article->da.code_article==code)
            {
                k=article->da.quant_stock;
            }
        else
        {
            k = cherche_qt(article->droite,code);
            if(k==0)
                k = cherche_qt(article->gauche,code);
        }
    }
    return(k);
}

void affichage_liste_qt(ABR_ARTICLE *article,LISTE_PRODUCTION *composant,LISTE_PRODUCTION *quant_stock,int qt)
{

    for(;composant && quant_stock;(composant=composant->suivant) && (quant_stock=quant_stock->suivant))
        {
        int total = (composant->dl.qt)*qt;
        int defaut = (quant_stock->dl.qt)-total;
        char *s;

        chercher_nom_produit(article,composant->dl.code,&s);
        printf("%-15.15s",s);
        if(defaut>=0)
          printf("| %-5.5d | %-10.10d | %-10.10d | %-10.10d | xxxxxxxxxx |\n",composant->dl.code,composant->dl.qt,total,quant_stock->dl.qt);
        else
            printf("| %-5.5d | %-10.10d | %-10.10d | %-10.10d | %-10.10d |\n",composant->dl.code,composant->dl.qt,total,quant_stock->dl.qt,abs(defaut));
        }
}

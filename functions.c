/**
* recharche Adherent by id.
*
* int id.
*
* @return int .
*/
int SearchAdherent(int id)
{
   int i;
 
   FILE* fichier;
   fichier = fopen("Adherent.txt","r");

   do
	{
		fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
		fflush(stdin);

		if( adh[i].adh_index == id )
		{
		   	fclose(fichier);
		   	return 1;
		}
    } while(!feof(fichier));

    fclose(fichier);

	return -1;
}

/**
* recharche Livres by id.
*
* int id.
*
* @return int .
*/
int SearchLivres(int id)
{
   int j;
 
   FILE* file;
   file = fopen("Livres.txt","r");
 
   do
	{
		fscanf(file,"%d\t%s\t%s\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
		fflush(stdin);
	
		if( liv[j].livre_index == id )
		{
		   	fclose(file);
		   	return 1;
		}
    }while(!feof(file));

    fclose(file);

	return -1;
}

/**
* Ajoute_Adherents qui Ajouter un ahderent dans un fichier Adherent.txt.
*
* @return void.
*/
void AjouterAdherents()
{
	int i,n,ID=0;

	FILE* fichier;

	printf("Inserez le nombre des Adherents : \n");
	scanf("%d",&n);
	fichier = fopen("Adherent.txt","r");

	if(fichier != NULL)
	{
		do
		{
			fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
			ID = adh[i].adh_index;
		}while(!feof(fichier));
		
		 fichier = fopen("Adherent.txt","a");
		 for(i=0; i<n; i++)
	     {
	       ID++;
		   adh[i].adh_index = ID;
		   adh[i].adh_NbEmprunts=0;
		   printf("Nom : ");
    	   scanf("%s",&adh[i].adh_Nom); 
	       printf("\n");
	       fprintf(fichier,"%d\t%s\t%d\t\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
	      }
	     fclose(fichier);

	} else {

		 fichier = fopen("Adherent.txt","a");
		 for(i=0; i<n; i++)
	     {
		   adh[i].adh_index = i+1;
		   adh[i].adh_NbEmprunts=0;
		   printf("Nom : ");
    	   scanf("%s",&adh[i].adh_Nom); 
	       printf("\n");
	       fprintf(fichier,"%d\t\t%s\t\t%d\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
	      }

	     fclose(fichier);
	}
	
}

/**
* afficher les Adherents dans un fichier.
*
* @return void.
*/
void AfficherAdherents()
{
	int i;
	
	FILE* fichier;
	fichier = fopen("Adherent.txt","r");

	printf("**************************La Liste des Adherents*****************************\n");
	printf("\t\tIndex \t Nom \t Nb_Emprunts \n");

	if( fichier != NULL )
	{
	    do
	    {
		  fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
		  printf("\t\t%d",adh[i].adh_index);
		  printf("\t%s",adh[i].adh_Nom);
		  printf("\t  %d\t\n",adh[i].adh_NbEmprunts);
	    } while(!feof(fichier));
    
    } else {
    	printf("Il n'y a pas des Adherents ! \n");
	}

	fclose(fichier);;
}

/**
* modifier un Adherent.
*
* @return void.
*/
void ModifierAdherents()
{
	int i,ID;
	char c = 'n';

	FILE *fichier,*fichiertemp;

	AfficherAdherents();

	printf("Entrer le Index du Adherent : ");
	scanf("%d",&ID);
	fflush(stdin);

	if( SearchAdherent(ID) == 1 )
	{
	   printf("Voulez vous modifier ? (O/N)");
	   scanf(" %c",&c);
	   fflush(stdin);
	   printf("%c",c);
	  
	   if( c=='o' || c=='O' )
	   {
	   	fichier = fopen("Adherent.txt","r");
	   	fichiertemp = fopen("tempAdherent.txt","a");
	   	do
	   	{
	   		fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
	   		if( adh[i].adh_index == ID )
	   		{
	   			adh[i].adh_index=ID;
	   			printf("Entrer le nouveau Nom : ");
	   			scanf("%s",&adh[i].adh_Nom);
	   			printf("Entrer le nouveau Nb_Emprunts : ");
	   			scanf("%d",&adh[i].adh_NbEmprunts);
			   }
			  fprintf(fichiertemp,"%d\t%s\t%d\t\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
		   }while(!feof(fichier));
		        fclose(fichiertemp);
	            fclose(fichier);
	            remove("Adherent.txt");
	            rename("tempAdherent.txt","Adherent.txt");
	     }
	} else {
	    printf("\n Ce numero n'exite pas   ! ! ! !! ");
    }
}

/**
* Supprimer un adherent dans un tableau d'enregistrement.
*
* @return void.
*/
void SupprimerAdherents()
{
	char c;
	int ID,i;

	AfficherAdherents();

	printf("Entrer le numero du adherent a supprimer : ");
	scanf("%d",&ID);
	fflush(stdin);
    
    if( SearchAdherent(ID) == 1 )
    {
	   printf("Voulez vous supprimer ? (O/N)");
	   scanf(" %c",&c);
	   fflush(stdin);
	   if(c=='o' || c=='O')
	   {
         	FILE* fichier,*fichiertemp;	
        	fichier=fopen("Adherent.txt","r");
        	fichiertemp=fopen("tempAdherent.txt","a");
 	        do
 	         {
 	           fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
 		       if(adh[i].adh_index != ID)
 		       {
 			      fprintf(fichiertemp,"%d\t%s\t%d\t\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
		       }
	          }while(!feof(fichier));
	            fclose(fichiertemp);
	            fclose(fichier);
	            remove("Adherent.txt");
	            rename("tempAdherent.txt","Adherent.txt");
	            printf("La Suppression avec sucss !!!\n");
       }
   }

}

/**
* Gestion qui traiter les livres dans une bibliotheque.
*
* @return void.
*/
void AjouterLivres()
{
	int j,m,IDL=0;

	FILE* file;

	printf("Inserez le nombre du Livres : ");
	scanf("%d",&m);
	file = fopen("Livres.txt","r");

	if(file != NULL)
	{
		do
		{
			fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
			IDL = liv[j].livre_index;
		}while(!feof(file));
		
		 file = fopen("Livres.txt","a");
		 for(j=0; j<m; j++)
	     {
	     	IDL++;
		    liv[j].livre_index = IDL;
		    liv[j].liv_Emprunteur=0;
		    printf("Titre de livre: ");
        	scanf("%s",&liv[j].liv_Titre);
	        fflush(stdin);
	        printf("Auteur : ");
	        scanf("%s",&liv[j].liv_Auteur);
	        printf("\n");
	        fprintf(file,"%d\t%s\t%s\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
	      }
	     fclose(file);
	} else {
		 file = fopen("Livres.txt","a");
		 for(j=0; j<m; j++)
	     {
		    liv[j].livre_index = j+1;
		    liv[j].liv_Emprunteur=0;
		    printf("Titre de livre: ");
        	scanf("%s",&liv[j].liv_Titre);
	        fflush(stdin);
	        printf("Auteur : ");
	        scanf("%s",&liv[j].liv_Auteur);
	        printf("\n");
	        fprintf(file,"%d\t%s\t%s\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
	      }
	     fclose(file);
	}
	
}

/**
* afficher les livres.
*
* @return void.
*/
void AfficherLivres()
{
	int j;

	FILE* file;
	file = fopen("Livres.txt","r");

	printf("***********************************La Liste des Livres*******************************\n");
	printf("\t\tIndex \t\tTitre \t\tAuteur \t\tliv_Emprunteurs\n");

	if(file != NULL)
	{
      do
	  {
		fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
		printf("\t\t%d",liv[j].livre_index);
		printf("\t\t%s",liv[j].liv_Titre);
		printf("\t\t%s",liv[j].liv_Auteur);
		printf("\t\t  %d\t\n",liv[j].liv_Emprunteur);
	  }while(!feof(file));
    } else {
    	printf("Il n y a pas des livres ! \n");
	}
	fclose(file);
}

/**
* modifier un livre avec l'index de livre.
*
* @return void.
*/
void ModifierLivres()
{
	int j,IDL;
	char c = 'n';
	
	FILE *file,*filetemp;

	AfficherLivres();

	printf("Entrer le Index du Livre : ");
	scanf("%d",&IDL);
	fflush(stdin);

	if( SearchLivres(IDL) == 1 )
	{
	   printf("Voulez vous modifier ? (O/N)");
	   scanf(" %c",&c);
	   fflush(stdin);
	   printf("%c",c);
	   if( c=='o' || c=='O' )
	   {
	   	file = fopen("Livres.txt","r");
	   	filetemp = fopen("tempLivres.txt","a");
	   	do
	   	{
	   		fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
	   		if(liv[j].livre_index == IDL)
	   		{
	   			liv[j].livre_index = IDL;
	   			printf("Entrer le nouveau Titre : ");
	   			scanf("%s",&liv[j].liv_Titre);
	   			printf("Entrer le nouveau Auteur : ");
	   			scanf("%s",&liv[j].liv_Auteur);
	   			printf("Entrer le nouveau Nb_Emprunteur : ");
	   			scanf("%d",&liv[j].liv_Emprunteur);

			   }
			  fprintf(filetemp,"%d\t%s\t%s\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
		   }while(!feof(file));
		        fclose(filetemp);
	            fclose(file);
	            remove("Livres.txt");
	            rename("tempLivres.txt","Livres.txt");
	     }
	} else {
	    printf("\n Ce numero n'exite pas   ! ! ! !! ");
    }
}

/**
* supprimer un livre d'aprés l'index de livre.
*
* @return void.
*/
void SupprimerLivres()
{
	char c;
	int IDL,j;

	AfficherLivres();
	
	printf("Entrer le numero du Livre a supprimer : ");
	scanf("%d",&IDL);
	fflush(stdin);
   
   if( SearchLivres(IDL) == 1 )
   {
	   printf("Voulez vous supprimer ? (O/N)");
	   scanf(" %c",&c);
	   fflush(stdin);

	   if( c=='o' || c=='O' )
	   {
         	FILE* file,*filetemp;
            file = fopen("Livres.txt","r");
        	filetemp = fopen("tempLivres.txt","a");
 	        do
 	         {
 	           fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
 		       if(liv[j].livre_index != IDL)
 		       {
 			      fprintf(filetemp,"%d\t%s\t%s\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
		       }
	          }while(!feof(file));
	            fclose(filetemp);
	            fclose(file);
	            remove("Livres.txt");
	            rename("tempLivres.txt","Livres.txt");
	            printf("La Suppression avec sucss !!!\n");
       }
   }

}

/**
* emprunter qui permet de emprunter un livre.
*
* @return void.
*/
void EmprunterLivres()
{
        int id,i,j,k;

	    FILE* file,*filetemp;
        file = fopen("Livres.txt","r");
  
        printf("Emprunter un livre : ");
	    printf(" \n\n");
        printf("***********************************La Liste des Livres*******************************\n");
	    printf("\t\tIndex \t\tTitre \t\tAuteur \t\tliv_Emprunteurs\n");
  
      do
	  {
		fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
	    if(liv[j].liv_Emprunteur >= 0)
		{
         	printf("\t\t%d",liv[j].livre_index);
		    printf("\t\t%s",liv[j].liv_Titre);
		    printf("\t\t%s",liv[j].liv_Auteur);
		    printf("\t\t  %d\t\n",liv[j].liv_Emprunteur);
        }
	 }while(!feof(file));
	        fclose(file);
	        printf("\nID Livre : \n");
			scanf("%d",&id);
			AfficherAdherents();
            printf("\nID Emprunter : \n");
			scanf("%d",&k);

            file = fopen("Livres.txt","r");
	   	    filetemp = fopen("tempLivres.txt","a");
			do
            {
            	fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
            	if(liv[j].livre_index == id)
            	{
            		liv[j].liv_Emprunteur=liv[j].liv_Emprunteur+1;
				}
				fprintf(filetemp,"%d\t%s\t%s\t\t\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
			}while(!feof(file));
	   		    fclose(filetemp);
	            fclose(file);
	            remove("Livres.txt");
	            rename("tempLivres.txt","Livres.txt");
	            FILE* fichier,*fichiertemp;
	            fichier = fopen("Adherent.txt","r");
        	    fichiertemp = fopen("tempAdherent.txt","a");
        	    do
 	            {
 	              fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
 		         if(adh[i].adh_index == k)
 		         {
 			          adh[i].adh_NbEmprunts=adh[i].adh_NbEmprunts+1;
		          }
		          fprintf(fichiertemp,"%d\t%s\t%d\t\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
	            }while(!feof(fichier));
	
	             fclose(fichiertemp);
	             fclose(fichier);
	             remove("Adherent.txt");
	             rename("tempAdherent.txt","Adherent.txt");
}

/**
* Afficher les livres empruntes.
*
* @return void.
*/
void AfficherLivresEmp()
{
	int j;

	FILE* file;
	file = fopen("Livres.txt","r");

	printf("***********************************La Liste des Livres Empruntes*******************************\n");
	printf("\t\tIndex \t\tTitre \t\tAuteur \t\tliv_Emprunteurs\n");

	if(file != NULL)
	{
	do
	  {
		fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
	    if(liv[j].liv_Emprunteur != 0)
		{
         	printf("\t\t%d",liv[j].livre_index);
		    printf("\t\t%s",liv[j].liv_Titre);
		    printf("\t\t%s",liv[j].liv_Auteur);
		    printf("\t\t  %d\t\n",liv[j].liv_Emprunteur);
        }
	 }while(!feof(file));
     } else {
     	printf("Il n y 'a pas des livres emprunters ! \n");
	 }
	 fclose(file);
}

/**
* rendre un livre.
*
* @return void.
*/
void RendreLivres()
{
	   int id,i,j,k;

	   FILE* file,*filetemp;
	   file = fopen("Livres.txt","r");

       printf("***********************************       La Liste des Livres     *******************************\n");
	   printf("\t\tIndex \t\tTitre \t\tAuteur \t\tliv_Emprunteurs\n");

	   do
	   {
		fscanf(file,"%d\t%s\t%s\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
	    if(liv[j].liv_Emprunteur != 0)
		{
         	printf("\t\t%d",liv[j].livre_index);
		    printf("\t\t%s",liv[j].liv_Titre);
		    printf("\t\t%s",liv[j].liv_Auteur);
		    printf("\t\t  %d\t\n",liv[j].liv_Emprunteur);
        }
	   }while(!feof(file));
	        fclose(file);
            printf("\nID Livre : \n");
			scanf("%d",&id);
			AfficherAdherents();
            printf("\nID Emprunteurs : \n");
			scanf("%d",&k);
            file = fopen("Livres.txt","r");
	   	    filetemp = fopen("tempLivres.txt","a");
			do
            {
            	fscanf(file,"%d\t%s\t%s\t\t\t\t%d\n",&liv[j].livre_index,&liv[j].liv_Titre,&liv[j].liv_Auteur,&liv[j].liv_Emprunteur);
            	if(liv[j].livre_index == id)
            	{
            		liv[j].liv_Emprunteur=liv[j].liv_Emprunteur-1;
				}
				fprintf(filetemp,"%d\t%s\t%s\t\t%d\n",liv[j].livre_index,liv[j].liv_Titre,liv[j].liv_Auteur,liv[j].liv_Emprunteur);
			}while(!feof(file));
			    fclose(filetemp);
	            fclose(file);
	            remove("Livres.txt");
	            rename("tempLivres.txt","Livres.txt");
	            FILE* fichier,*fichiertemp;
	            fichier = fopen("Adherent.txt","r");
        	    fichiertemp = fopen("tempAdherent.txt","a");
        	    do
 	            {
 	              fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
 		         if(adh[i].adh_index == k)
 		         {
 			          adh[i].adh_NbEmprunts=adh[i].adh_NbEmprunts-1;
		          }
		          fprintf(fichiertemp,"%d\t%s\t%d\t\n",adh[i].adh_index,adh[i].adh_Nom,adh[i].adh_NbEmprunts);
	            }while(!feof(fichier));

	             fclose(fichiertemp);
	             fclose(fichier);
	             remove("Adherent.txt");
	             rename("tempAdherent.txt","Adherent.txt");
}

/**
* Afficher la liste des emprunteurs de livres.
*
* @return void.
*/
void AfficherListeEmprunteurs()
{
	int i;

	FILE* fichier = NULL;
	fichier = fopen("Adherent.txt","r");

    printf("*********************************** La Liste des Emprunteurs de Livres *******************************\n");
	printf("\t\tIndex \t Nom \t Nb_Emprunts \n");

	if(fichier != NULL) {
	do
	  {
		fscanf(fichier,"%d\t%s\t%d\t\n",&adh[i].adh_index,&adh[i].adh_Nom,&adh[i].adh_NbEmprunts);
	    if(adh[i].adh_NbEmprunts != 0) {
	    printf("\t\t%d",adh[i].adh_index);
		printf("\t%s",adh[i].adh_Nom);
		printf("\t  %d\t\n",adh[i].adh_NbEmprunts);
	    }
	 }while(!feof(fichier));
	 
     } else {
	 printf("IL n'y a pas des Emprunteurs ! \n");
	 }

	 fclose(fichier);	 
}

/**
* color.
*
* int t,f.
*
*/
void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
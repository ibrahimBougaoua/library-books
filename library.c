#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/**
* .......................
*/
#define CMAX 50
#define TAILLEMAX 1000

/**
* .......................
*/
#include "structs.c"
#include "functions.c"

/**
* Badani Yahia
* Bougaoua ibrahim
*/
void main() 
{
	
	  int ch;
	  char C;

	  SetConsoleTitle("Gestion Livre");

	/*
	  Menu Principale contient tout les choix que vous traiter
	*/
	do
	{
	  system("cls");
	  color(11, 0);
	  printf("\n\t\t  ____________________________________________________________________________  ");
	  printf("\n\t\t||                          Gestion Livre                                     ||");
	  printf("\n\t\t||                         Gestion Adherent                                   ||");
	  printf("\n\t\t  ---------------------------------------------------------------------------");
	  color(9, 0);
	  printf("\n\t\t  ____________________________________________________________________________");
	  printf("\n\t\t||                ||-1-Ajouter un Adherent.                                   ||");
	  printf("\n\t\t||    Gestion     ||-2-Modifier un Adherent.                                  ||");
	  printf("\n\t\t||   Adherents    ||-3-Supprimer un Adherent.                                 ||");
	  printf("\n\t\t||                ||-4-Afficher la liste des Adherents.                       ||");
      printf("\n\t\t  ----------------------------------------------------------------------------");
	  color(14, 0);
	  printf("\n\t\t  ____________________________________________________________________________");
	  printf("\n\t\t||                ||-5-Ajouter un Livre.                                      ||");
	  printf("\n\t\t||   Gestion      ||-6-Modifier un Livre.                                     ||");
	  printf("\n\t\t||   Livres       ||-7-Supprimer un Livre.                                    ||");
	  printf("\n\t\t||                ||-8-Afficher la liste des Livres.                          ||");
	  printf("\n\t\t  ----------------------------------------------------------------------------");
	  color(2, 0);
	  printf("\n\t\t  ___________________________________________________________________________");
	  printf("\n\t\t||   Gestion      ||-9-Emprunter un Livre.                                    ||");
	  printf("\n\t\t||     Des        ||-10-Afficher la liste des livres empruntes.               ||");
	  printf("\n\t\t||   Emprunts     ||-11-Rendre un livre.                                      ||");
	  printf("\n\t\t||                ||-12-Afficher la liste des emprunteurs de livres.          ||");
	  printf("\n\t\t  ----------------------------------------------------------------------------");
	  color(13, 0);
	  printf("\n\t\t  ______________________________________________________________________________");
	  printf("\n\t\t||                     Produced By  @BB Team                                  ||");
	  printf("\n\t\t  ______________________________________________________________________________");
	  color(12, 0);
	  printf("\n\t\t  ----------------------------------------------------------------------------\n");
	  color(15, 0);
       do
	   {
	      printf("\nEntrer Ton Choix : ");
	      fflush(stdout);
	      scanf("%d",&ch);
        
        }while( ch<1 || ch>12 );
     
	     switch(ch)
         {
        	case 1:
     		      color(9, 0);
		          AjouterAdherents();
     		      break;
     	    case 2:   
		          color(9, 0);
     	          ModifierAdherents();
                  break;
            case 3:   
		          color(9, 0);
     		      SupprimerAdherents();
     		      break;
     	    case 4:   
		          color(9, 0);
     		      AfficherAdherents();
     		      break;
     		case 5:
		          color(14, 0);
     		      AjouterLivres();
     		      break;
     	    case 6:
		          color(14, 0);
     		      ModifierLivres();
				  break;
        	case 7:
		          color(14, 0);
		          SupprimerLivres();
				  break;
     	    case 8:
		          color(14, 0);
     		      AfficherLivres();
				  break;
			case 9:
     		      color(13, 0);
     		      EmprunterLivres();
    		      break;
    	    case 10:
     		      color(13, 0);
     		      AfficherLivresEmp();
     		      break;
     		case 11:
     		      color(13, 0);
     		      RendreLivres();
				  break;
			case 12:
			      color(13, 0);
				  AfficherListeEmprunteurs();
				  break;
		    case 13:
			      color(11, 0);
				  break;
				  system("pause");	  
	      }
	        color(11, 0);
	        printf("Voulez Vous Continuez ? (O/N)");
	        scanf(" %c",&C);

        } while( C=='o' || C=='O' );
        
        printf("\n\t\t##############################################################################");
	  	printf("\n\t\t#                              THANKS                                        #");
	  	printf("\n\t\t##############################################################################");
	  	printf("\n\t\t##############################################################################");
	  	printf("\n\t\t#                       FOR USING THIS PROGRAMME                             #");
	  	printf("\n\t\t##############################################################################");
	  	SYSTEMTIME t;
        GetSystemTime(&t);
        printf("\n\t\t******************************************************************************");
        printf("\n\t\t*\t\tDate\t\t*\t\t*\tHeure\t\t     *");
        printf("\n\t\t******************************************************************************");
        printf("\n\t\t*\t\t%d-%d-%d\t*\t\t*\t%d:%d:%d\t     *",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);
        printf("\n\t\t******************************************************************************");
	
}
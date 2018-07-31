/**
* Enregistrement des Adherents.
*/
struct SAdherent
{
	int  adh_index;
	char adh_Nom[CMAX];
	int  adh_NbEmprunts;
};

struct SAdherent adh[TAILLEMAX];

/**
* Enregistrement des Livres.
*/
struct SLivre
{
	int  livre_index;
	char liv_Titre[CMAX];
	char liv_Auteur[CMAX];
	int  liv_Emprunteur;
};

struct SLivre liv[TAILLEMAX];
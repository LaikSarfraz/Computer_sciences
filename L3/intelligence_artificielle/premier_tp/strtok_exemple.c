/********************************************************/
/*							*/
/* 		Utilisation de STRTOK	                */
/* Permet de compter le nombre de mot de la phrase      */
/* Permet d'extraire les différents mots                */
/* selon le caractere "space"                           */
/* NOTA : Aucun controle dans le prog !                 */
/*							*/
/*  Créateur : Trinta                                   */
/*  Date de création : 04/06/2003                       */
/*                                                      */
/*  Version : 1.0.0                                     */
/*  Date de modification : 04/06/2003                   */
/*  FREEWARE                                            */
/*                                                      */
/********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ( )
{
  char	*pointeur;
  char	*separateur = { " " };     // Le séparateur
  char 	*buffer;
  char    *Chaine_Entrante="bonjour je m'appelle Trinita";
  int     nb_mot=1;
	
  buffer = strdup ( Chaine_Entrante );

  // premier appel,
  pointeur = strtok( buffer, separateur  );
  printf ("Mot de la phrase numero : %d %s\n",nb_mot, pointeur);
	    
  while( pointeur != NULL ) 
    {
      // Cherche les autres separateur
      pointeur = strtok( NULL, separateur  );
      if ( pointeur != NULL )
	{
	  nb_mot++; // increment du nombre de mot	
	  printf ("Mot de la phrase numero : %d %s\n",nb_mot, pointeur);
	}
    }
    
  getchar (); // pause en mode console
    
  return 0 ;
}

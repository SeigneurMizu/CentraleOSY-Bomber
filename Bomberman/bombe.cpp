#include "Bombe.h"

using namespace std;



Bombe::Bombe()   
{
	// cr�er un pointeur vers la bombe dans le tableau qui recense les instances de bombe.

}

Bombe::~Bombe() 
{
	// afficher l'image de l'explosion ? -> non, affich� par explose()

}


void Bombe::decrementTimer()
{
	m_timer -= 1;  // nb: qd le timer est � 0, un if ds la boucle de temps le detecte et fait exploser la bombe
}


/* // code � rajouter dans le main.cpp � chaque fin de "boucle de temps"
for () // pour toutes les bombes sur la carte: trouver un moyen de pouvoir les parcourir: probablement avec un tableau dynamique statique dont les cases enregistrent un pointeur vers chaque instance. Creuser aussi http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
{
	if (m_timer == 0)
	{
		explose();   //// ATTENTION: rajouter l'objet avant la m�thode...d�pend de la d�claration de la boucle for (parcours des bombes pos�es sur la carte)
		~Bombe();   // pour d�truire l'instance de la bombe
	}
}

*/


void Bombe::explose();    // pour d�truire les blocs detruisables et appeler afficheExplosion
{

}


void Bombe::afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
{

}

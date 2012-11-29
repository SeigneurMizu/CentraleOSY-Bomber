#include "Bombe.h"
#include <set>
#include <algorithm> // indispensable pour le for_each
using namespace std;



void Bombe::boucleTestTimerPourExplosion() // fonciton � rajouter dans le main.cpp � chaque fin de "boucle de temps"
{
	for_each (instances.begin(), instances.end(), testTimerPourExplosion);  // pour toutes les bombes sur la carte: trouver un moyen de pouvoir les parcourir: probablement avec un tableau dynamique statique dont les cases enregistrent un pointeur vers chaque instance. Creuser aussi http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class
} 


void Bombe::testTimerPourExplosion(Bombe* b)
	{
		if (b->m_timer == 0)
		{
			b->enleverAffichageExplosion();  
			b->~Bombe();  
		}
		else if (b->m_timer > 0 && b->m_timer < 5 )  // c'est ici qu'est r�gl�e la dur�e de l'explosion !
		{
			b->affichageExplosion(); 
			b->m_timer -= 1 ; 
		}
		else 
		{
			b->m_timer -= 1 ;  
		}
	}




Bombe::Bombe()   
{
	instances.insert(this);   // cr�er un pointeur vers la bombe dans le tableau qui recense les instances de bombe.
}

Bombe::~Bombe() 
{
	instances.erase(instances.find(this));  // on enleve le pointeur vers la bombe dans le tableau d'instances
}





void Bombe::explose()    // pour d�truire les blocs detruisables et appeler afficheExplosion
{

}


void Bombe::afficheExplosion()  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion, dans la limite de la port�e de la bombe
{

}

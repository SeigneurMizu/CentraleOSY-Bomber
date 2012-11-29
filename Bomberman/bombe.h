#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>
#include <set>



class Bombe
{
	static std::set<Bombe const *> instances;  // on cr�e un set nomm� "instances", pour l'instant vide, et qui contiendra des pointeurs vers les bombes, et qui va r�f�rencer les instances de Bombe, ce qui permettra de compter les bombes sur la carte et de les atteindre.
                                               // 
											   // http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class

	static void boucleTestTimerPourExplosion();  // fonciton � rajouter dans le main.cpp � chaque fin de "boucle de temps". Elle applique la fonction testTimerPourExplosion() � toutes les instances de bombes
	static void testTimerPourExplosion(Bombe* b);        // 

public: 
    Bombe();
    ~Bombe();
    void decrementTimer();   // 
    void explose();    // pour d�truire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	


private:
    int m_timer;   // compte � rebours entre moment ou elle est pos�e et explosion
    int m_portee;  // nombre de blocs d�truits dans chaque direction lors de l'explosion
	bool m_isExploding;  // correspond � l'etat ou les images de l'explosion sont affich�es
	bool m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};

std::set<Bombe> Bombe::instances;  // pour etre conforme a http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class . j'imagine que c'est une sorte d'initialisation.

#endif
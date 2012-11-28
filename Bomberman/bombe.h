#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>

class Bombe
{
	static std::set<Bombe const *> instances;  // http://stackoverflow.com/questions/3208958/how-to-keep-a-list-of-instances-of-a-class

public: 
    Bombe() : { instances.insert(this); };
    ~Bombe(){ instances.delete(this); };
    void decrementTimer();   // 
    void explose();    // pour d�truire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void decrementTimer(); // pour d�cr�menter le timer � chaque boucle de temps
	


private:
    int m_timer;   // compte � rebours entre moment ou elle est pos�e et explosion
    int m_portee;  // nombre de blocs d�truits dans chaque direction lors de l'explosion
	bool m_isExploding;  // correspond � l'etat ou les images de l'explosion sont affich�es
	bool m_isExploded;   // correspond a l'etat ou on a arrete d'afficher les images d'explosion
};

#endif
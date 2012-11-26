#ifndef DEF_BOMBE
#define DEF_BOMBE

#include <string>

class Bombe
{
    public:
    Bombe();
    ~Bombe();
    void decrementTimer();   // 
    void explose();    // pour d�truire les blocs detruisables et appeler afficheExplosion
	void afficheExplosion();  // pour remplacer temporairement les blocs autour de la bombe par l'image d'explosion
	void decrementTimer(); // pour d�cr�menter le timer � chaque boucle de temps
	


    private:

    int m_timer;   // compte � rebours entre moment ou elle est pos�e et explosion
    int m_portee;  // nombre de blocs d�truits dans chaque direction lors de l'explosion
};

#endif
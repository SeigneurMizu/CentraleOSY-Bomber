#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <map>

// using namespace std; ATTENTION : PAS de namespace std dans les .h (cf site du zero)

typedef std::pair <int,int> coord;

class Objet
{
    public:
		Objet();
		Objet(coord xy);
		~Objet();
        coord   getCoord();
        int     getx();
        int     gety();
        void    setCoord(int x, int y);
        bool    estPassable();

    protected:  // pour que les attributs soient accessibles depuis les classes filles (n�cessaire pour le deposeBombe() de Personnage)
        coord   m_coordonnees;
        bool    m_passable;
};



#endif // OBJET_H_INCLUDED

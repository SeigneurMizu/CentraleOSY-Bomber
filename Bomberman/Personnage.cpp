#include "Personnage.h"

using namespace std;

CImg<unsigned char> pictoJoueur(Joueur.png);
CImg<unsigned char> pictoEnnemi(Ennemi.png);



void	Personnage::decrementeCompteurDeBombe(Personnage* p)
{
	p->m_compteurDeBombe-=1;
}


Personnage::Personnage(int typePerso) : Objet() // constructeur du personnage
{
	if (m_typePerso = 1)
	{
		m_picto(pictoJoueur); // personnage du joueur
	}
	else
	{
		m_picto(pictoEnnemi);
	}
	m_vie(m_maxVie);
	m_maxVie(100);
	//m_vitesse (??) => On met des niveau de vitesse genre 1,2,3 pour chaque personnage ?
	m_tailleSacBombe(100); //valeur � discuter
	m_typePerso(typePerso);
	m_scopeDestruction[0] = 1; // zone de destruction lat�rale horizontale des bombes pose�s par le personnage (ici : 1 case de chaque c�t� de la bombe)
	m_scopeDestruction[1] = 1; // zone de destruction lat�rale verticale des bombes pose�s par le personnage
    m_vitesseDeplacement = 1;
}


void Personnage::modifVie(signed int deltaVie) // pr�voit les bonus de type potions ou autre
{
	if (m_vie + deltaVie <= 0)
	{
		m_vie = 0;
		m_estVivant = false;
	}
	else if (m_vie + deltaVie >= m_maxVie)
	{
		m_vie = m_maxVie;
	}
	else
	{
		m_vie += deltaVie;
	}
}

void Personnage::powerUpSacBombe(int deltaSac)
{
	m_tailleSacBombe += deltaSac;
}

void Personnage::powerUpVitessDeplacement(int deltaVit)
{
    m_vitesseDeplacement += deltaVit;
    if (m_vitesseDeplacement <= 0)
    {
        m_vitesseDeplacement = 1;
    }
    else if (m_vitesseDeplacement >= VITESSEMAX)
    {
        m_vitesseDeplacement = VITESSEMAX;
    }
}

bool Personnage::estVivant()
{
	if (m_vie > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Personnage::afficheLastAction()
{
	return m_lastAction;
}

void Personnage::updateLastAction(time_t time)
{
	m_lastAction = time;
}


void Personnage::deposeBombe()
{
	if (m_compteurDeBombe<m_tailleSacBombe)
	{
		Bombe(m_coordonnees, m_scopeDestruction, this);   //on appelle le constructeur de la classe Bombe avec les coordonn�es du personnage.
		m_compteurDeBombe +=1;
	}
}


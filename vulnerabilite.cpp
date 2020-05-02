#include <iostream>
#include "header.h"

//SS Graphe Connexe() Utilsation de allego djiskra pour trouve les composant Connexxe
// Si sommet non explore Distance = 999
// Ainsi on parcours a chaque fois un somme non explore

void Graphe::GrapheConnexe()
{

    std::vector<int> distance;
    std::vector<int> couleur((int)m_sommets.size(),0);
    std::vector<std::vector<int>> CC;

    int NonSommet=0;
    int k=0;
    bool check=true ;

    while(check!=false)
    {
        std::cout<<"Composant Connexe : ";
        check=false;
        distance=AlegoDjiskra(NonSommet);

        for(int i=0; i<distance.size(); i++)
        {

            if(distance[i]==999 && couleur[i]==0)
            {
                NonSommet=i;
                check=true;
            }
            else if(couleur[i]==0)
            {

                std::cout<<"  "<<m_sommets[i]->getNom();
                couleur[i]=1;

            }

        }
        k++;
    }

    if(k==1)
        std::cout<<"\n Le Graphe est Connexe \n";
    else
        std::cout<<"\n Le Graphe n'est pas Connexe \n";


}

// SS De suppression d'une arrets

Graphe* Graphe::Sup_aretes()
{
  //Calculer des indices avant suppression graphe

    calcul_indice_degres();
    calcul_indice_proximite();
    calcul_vecteur_propre();
 ///   calcul_indice_proximite();

//On declare des tableaux qui vont nous servir de buffer
    std::vector<int> t_indice;
    std::map<const Sommet*,int> succes;
    std::map<const Sommet*,int> temp;
    std::map<const Sommet*,int> temp2;

    std::string depart,arrive;


    std::cout<<"Arrets : \n";

    for(int i =0 ; i<m_arrets.size() ; i++)  // On affiche les arrets
        {

for(auto s : m_sommets) // On associer les arrets a des nom
    {

     if(m_arrets[i].first==s->getNum())
        depart=s->getNom();

     if(m_arrets[i].second==s->getNum())
        arrive=s->getNom();

    }
    std::cout<<"Indice : "<<i<<" : "<<depart<<" - "<<arrive<<std::endl;

     }

    int indice=0;

    std::cout<<"\n99 / Pour Quitter la saisie \n ";
    std::cout<<"Saisir l'indice des aretes a supprimer \n";
    while(indice!=99)
    {
        std::cout<<"Indice : ";

        std::cin>>indice;
        t_indice.push_back(indice);

    }


    t_indice.pop_back(); // On Supprimer le 99



    for(auto s : m_sommets) // On parcours les sommets
    {

        temp.clear();
        // On cherche quelle sommmet est conserner par l'arrets
        for(int z=0; z < t_indice.size(); z++)
        {
            if(s->getNum()== m_arrets[t_indice[z]].first )
            {
                for( auto succ : s->getSuccesseurs() )
                {
                    if (succ.first->getNum() != m_arrets[t_indice[z]].second)
                        temp[succ.first]=succ.second;  // On utiliser un nouveau tableau pour remmplace les succeurs des sommets
                }

                s->setsucc(temp);
            }

            temp2.clear();
            if(s->getNum()== m_arrets[t_indice[z]].second )
            {
                for( auto succ : s->getSuccesseurs() )
                {
                    if (succ.first->getNum() != m_arrets[t_indice[z]].first)
                        temp2[succ.first]=succ.second;
                }

                s->setsucc(temp2);
            }


        }

    }


m_taille=m_taille-t_indice.size(); // Suite a la suppresion d'une arrets la taille est reduite



for(int k =0; k<t_indice.size();k++) // De meme pour l'arrets
            m_arrets.erase(m_arrets.begin()+t_indice[k]);







}

// SS De comparaison des indices

void Graphe::ComparaisonIndice()
{
    std::cout<<"\n \nComparaison entre les deux graphes \n";
    int i=0;
    float temp,temp2;

    std::vector<float> vecteur_propre;
    std::vector<float> indice_proximite;
    std::vector<float> indice_intermedaire;
    std::vector<float> indice_degresN;
    std::vector<float> indice_degresNN;


    for(auto k : m_sommets)
    {

        vecteur_propre.push_back(k->getIndice(2));
        indice_proximite.push_back(k->getIndice(3));
        indice_degresNN.push_back(k->getIndice(0));
        indice_degresN.push_back(k->getIndice(1));
        indice_intermedaire.push_back(k->getIndice(4));


    }

    calcul_indice_degres();
    calcul_indice_proximite();
    calcul_vecteur_propre();
  //  centraliteintermediarite();

    for(auto s : m_sommets)
    {
        std::cout<<"\nSommet   "<<s->getNom()<<std::endl;

        std::cout<<"Indice degres normalise :     ";
        std::cout<<indice_degresN[i]<<" - "<<s->getIndice(1)<<" = "<<indice_degresN[i]-s->getIndice(1)<<std::endl;
        std::cout<<"Indice degres non normalise : ";
        std::cout<<indice_degresNN[i]<<" - "<<s->getIndice(0)<<" = "<<indice_degresN[i]-s->getIndice(0)<<std::endl;
        std::cout<<"Indice vecteur :              ";
        std::cout<<vecteur_propre[i]<<" - "<<s->getIndice(2)<<" = "<<vecteur_propre[i]-s->getIndice(2)<<std::endl;
        std::cout<<"Indice proximite :            ";
        std::cout<<indice_proximite[i]<<" - "<<s->getIndice(3)<<" = "<<indice_proximite[i]-s->getIndice(3)<<std::endl;
        std::cout<<"Indice intermediare :         ";
        std::cout<<indice_intermedaire[i]<<" - "<<s->getIndice(4)<<" = "<<indice_intermedaire[i]-s->getIndice(4)<<std::endl;

        std::cout<<"\n";
        i++;
    }


}

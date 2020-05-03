#include "header.h"


//////////////////////////////////////////////// Indice de degre

void Sommet::indice_degre(float ordre)
{
    int nbrsucc=0;

    for( auto s : m_successeurs)
        nbrsucc++;

    m_indice.degre_non_normamise=nbrsucc;
    m_indice.degre_nomralise=(nbrsucc/ordre);

}

void Graphe::calcul_indice_degres()
{
    for(auto s : m_sommets)
        s->indice_degre(m_sommets.size()-1); //On envoie l'ordre du graphe -1

}

void Sommet::affi_degre_sommmet() const
{
    std::cout<<" sommet : "<<m_nom<< std::endl;
    std::cout<<"indice de degre normalisee : "<<m_indice.degre_nomralise<<" , \n"<<"indice de degre nonnormalisee : "<<m_indice.degre_non_normamise<<" .";

}

//inisialisation de la fonction de trie pour notre fil de priorité
auto cmp = [](std::pair<const Sommet*,double> p1, std::pair<const
              Sommet*,double> p2)
{
    return p2.second<p1.second;
};




std::vector<std::pair<int,int>> Graphe::Dijkstra(int num_s0)const
{
    int NbNodes=m_sommets.size();
    std::vector<std::pair<int,int>> Distances;//pour chaque sommets on mets une distance infinie( std::numeric_limits<int>::max()) correspond a la valeur mas que peut contenir un int en C++
    ;//la distance entre le sommets de départs et lui-meme est 0
    int Parents [NbNodes][NbNodes];//pour chaque sommets on definie son parents a -1 qui corspondt a aucun parents
    std::pair<int,int> innitialise;
    innitialise.first=std::numeric_limits<int>::max();
    innitialise.second=0;
    for (int i = 0; i < NbNodes; i++)
    {
        for (int j = 0; j < NbNodes; j++)
        {
            Parents[i][j] = -1;
            Distances.push_back(innitialise);

        }
    }
    Distances[num_s0].first = 0;
/// déclaration de la file de priorité
    std::priority_queue<std::pair<const Sommet*,double>,
        std::vector<std::pair<const Sommet*,double>>,decltype(cmp)> file(cmp);

    file.push({m_sommets[num_s0],0});//on mets dans le liste le sommet de commencement

    while(!file.empty())
    {
        int v = file.top().first->getNum();//on récupaire le succeur avec la plus grande priorité, on le marque(supression)
        int w = file.top().second;
        file.pop();

        if (w <= Distances[v].first) // si la distance entre le succeur et sont prédécesseur est infèrieur ou égale avec la distance total
        {
            std::map<const Sommet*,int> m_successeurs; //on récupaire le vecteur contenant les succeurs
            m_successeurs=m_sommets[v]->getSuccesseurs();
            for (auto s : m_successeurs)//on parcours le vecteur des succeurs
            {
                int v2 = s.first->getNum();
                int w2 = s.second;

                if (Distances[v].first + w2 < Distances[v2].first)//si la somme de la distance entre le parcours et le prédécésseur est infèrieur a la distance du sommet où l'on arrive
                {
                    Distances[v2].first = Distances[v].first + w2;//on remplace cette distance
                    Parents[v2][0] = v;//on change le predessesseur
                    for (int i=1; i<NbNodes; ++i)
                    {
                        Parents[v2][i] = -1;//on change le predessesseur
                    }
                    file.push({m_sommets[v2],Distances[v2].first});//on push le sommet et la ditance dans notre file
                }
                //ici on récupaire égalment les chemins égaux au plus court chemin
                else if (Distances[v].first + w2 == Distances[v2].first)
                {
                    int dep=0;
                    while(Parents[v2][dep] != -1)
                    {
                        ++dep;
                    }
                    Parents[v2][dep] = v;
                }
            }
        }
    }
//dans cette partie on remplie une matrice avec la taille des plus cours chemin et une autre avec leur nombre
//on remplie la matrice d'adjacence du graph orienté oubtenu grace a l'algorithme de Dijkstra
    int chemin_t[NbNodes] ;
    float matrice[NbNodes][NbNodes];
    for (int i = 0; i < NbNodes; i++)
    {
        for (int j = 0; j < NbNodes; j++)
        {
            matrice[i][j] = 0;
            chemin_t[i]=0;
        }
    }
    for (int i = 0; i < NbNodes; i++)
    {
        int j=0;
        while (Parents[i][j] != -1)
        {
            matrice[i][Parents[i][j]]=1;
            ++j;
        }
    }
    float ca[NbNodes][NbNodes],cb[NbNodes][NbNodes],tot;
    //transfert de notre matrice dans une matrice de calcul
    for(int i=0; i<NbNodes; i++)
    {
        for(int j=0; j<NbNodes; j++)
        {
            ca[i][j]=matrice[i][j];

        }

    }

    for (int i = 0; i < NbNodes-1; ++i)
    {
        for(int g =0; g<NbNodes; ++g)
        {
            chemin_t[g]=chemin_t[g]+ca[g][num_s0];
        }

        for(int k=0; k<NbNodes; ++k)
        {
            //transfert de notre matrice de calcul dans une matrice second matrice
            for(int j=0; j<NbNodes; ++j)
            {
                cb[k][j]=ca[k][j];

            }

        }


        for(int k=0; k<NbNodes; ++k)
        {

            for(int j=0; j<NbNodes; ++j)
            {
                tot=0;
                for(int z=0; z<NbNodes; ++z)
                {
                    //on calcule la puissance de la matrice
                    tot=tot+(cb[k][z]*matrice[z][j]);
                }
//on récupaire le résultat
                ca[k][j]=tot;

            }


        }


    }


    for (int j = 0; j < NbNodes; j++)
    {
        if(j !=num_s0 )
        {
            Distances[j].second=chemin_t[j];
        }
    }
//on return au programme appelent la liste des plus court chemin du sommet demander
    return Distances;
}
void Sommet::indice_centralite(float ordre,float indicenn)
{
    float normalisation=0;

    normalisation=(ordre*ordre-3*ordre+2)/2;


    m_indice.intermediaire_non_normamise=indicenn;

    m_indice.intermediaire_nomralise=(indicenn/normalisation);

}
void Sommet::affi_centralite_sommmet() const
{
    std::cout<<" sommet : "<<m_nom<< std::endl;
    std::cout<<"Indice de centralite normalise : "<<m_indice.intermediaire_nomralise<<"\nIndice de centralite non normalise : "<<m_indice.intermediaire_non_normamise<< std::endl;

}
void Graphe::affi_indice_centralite() const
{
    for (auto s : m_sommets)
    {
        s->affi_centralite_sommmet();
        std::cout<<std::endl;
    }
}

void Graphe::centraliteintermediarite()
{
// ce programme regoupe dans 2 matrice la distance des plus cours chemin et leurs nombre pour pouvoir calculer l'indice de centralité intermédiaire
    int taille=m_sommets.size();

    float matricedist[taille][taille];
    float matricenbchemin[taille][taille];
    float indice_nn=0;
    std::vector<float> tempindice;
    std::map<const Sommet*,int> suceur;
    int nbtotal=0;
    //on inisialise les matrice
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            matricedist[i][j] = 0;
        }
    }

    std::vector<std::pair<int,int>> Distances;
    for(int i=0; i<taille; ++i)
    {
        Distances=Dijkstra(i);
        for(int j=0; j<taille; ++j)
        {
            matricedist[i][j]=Distances[j].first;
            matricenbchemin[i][j]=Distances[j].second;
        }
    }

//on calcul l'indice avec les matrice obtenue grace a l'algorithme de Dijkstra
    for (int i = 0; i < taille; ++i)
    {
        for(int j=0; j<taille; ++j)
        {
            for(int k=0; k<taille; ++k)
            {
                if(i !=j && i!=k)
                {
                    if(matricedist[j][i]+matricedist[i][k]==matricedist[j][k])
                    {
                        float tempik=matricenbchemin[i][k]-1;
                        float temp=(matricenbchemin[j][i]+tempik)/matricenbchemin[j][k];
                        indice_nn=indice_nn+temp;
                    }
                }
            }
        }
        tempindice.push_back(indice_nn);
        indice_nn=0;
    }
    //ici on stock dans nos sommets le résultat obtenu
    for(int i=0; i<taille; ++i)
    {
        m_sommets[i]->indice_centralite(taille,tempindice[i]);
    }

}




void Graphe::affi_indice_Tdegre() const
{
    for (auto s : m_sommets)
    {
        s->affi_degre_sommmet();
        std::cout<<std::endl;
    }
}


//////////////////////////////////////////////////////////////////// Indice Vecteur propre

// SS de calcul du vecteur propre
void Graphe::calcul_vecteur_propre()
{


    float S_indice=0;
    float S_total=0;
    float lamda=0;
    float lamdatemp=0;
    std::vector<float> stock((int)m_sommets.size(),0);

    int k=0;

    calcul_indice_degres(); // On calcul le degres d'indice.
    do
    {

        lamdatemp=lamda;

        k=0;
        S_total=0;

        for (auto s : m_sommets) // ON parcours les sommets et somme l'indice de degres
        {
            S_indice=0;
            for(auto succ : s->getSuccesseurs())
            {
                S_indice+=succ.first->getIndice(2);

            }
            stock[k]=S_indice;

            S_total+=pow(S_indice,2);
            k++;

        }

        lamda=sqrt(S_total); // On calcul lamda

        int i=0;

        for(auto s : m_sommets)
        {

            s->setIndice_vecteur(stock[i]/lamda);
            i++;

        }


    }
    while(lamda != lamdatemp); // Tant que lamda varie pas trop

}


void Sommet::affi_indice_vecteur() const
{
    std::cout<<"Sommet : "<<m_nom<< std::endl;
    std::cout<<"Indice  : "<<m_indice.vecteur<<"\n" ;

}

void Graphe::affi_indice_Tvecteur() const
{
    for (auto s : m_sommets)
    {
        s->affi_indice_vecteur();
        std::cout<<std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////



std::vector<int> Graphe::AlegoDjiskra(int num_D) // Alego de Djiskra
{

    //tableau pour le marquage ;
    std::vector<int> marquage((int)m_sommets.size(),0);
    //tableau des distances
    std::vector<int> distance((int)m_sommets.size(),999);
    //tableau des preds
    std::vector<int> preds((int)m_sommets.size(),-1);



    bool M = false; //booleen pour savoir si tout les sommets sont marquees
    int temp=999; // Utiliser pour determiner le min
    int index=0;
    float total=0;

    distance[num_D]=0; //Initialisation de la distance du Sommet 0 a 0
    const Sommet* k;



    for(auto z : m_sommets) //On met a jour les distances des adjacents
    {
        if(z->getNum()==num_D)
        {
            for(auto succ : z->getSuccesseurs())
            {
                distance[succ.first->getNum()]=succ.second;
            }
            marquage[num_D]=1; // On  marque le sommet s0

        }

    }


    do
    {
        M=false;

        for(int i=0 ; i<distance.size(); i++) // On cherche le sommets avec la plus petite distance
        {
            if(marquage[i]==0 && i!=num_D)
            {

                if(distance[i]<=temp)
                {
                    temp=distance[i];
                    index=i;

                }

                M=true;

            }

        }

        for(auto s : m_sommets)
            if(s->getNum()==index) //On recherche le pointeur Sommet¨* le plus proche de s0
                k=s;

        if(M==true)
            distance[index]=temp;

        marquage[index]=1;



        for(auto X : k->getSuccesseurs())
        {

            if(marquage[X.first->getNum()]==0)
            {

                if(distance[k->getNum()]+X.second<distance[X.first->getNum()]) //Si le chemin est plus court on le met a jour
                {
                    distance[X.first->getNum()]=distance[k->getNum()]+X.second;
                    // std::cout<<k->getNum()<<"-->"<<X.first->getNum()<<std::endl;
                    //  preds[k->getNum()]=X.first->getNum();

                }

            }


        }

        temp=999;



    }
    while(M==true); // tant que tout les sommets ne sont pas marque

    int i=0;


    return distance;

}

//SS Calcul indice proximite

void Graphe::calcul_indice_proximite()
{
    float temp;
    std::vector<int> preds;

    for(auto s : m_sommets)
    {
        temp=0;
        preds=AlegoDjiskra(s->getNum()); // On appel Djiskra pour chaque sommet
        for(auto k : preds)

            for(int i=0 ; i<preds.size(); i++)
            {
                temp+=preds[i]; // ON sommet l'ensemvle des distance
                //  std::cout<<"\n temp "<<temp<<"preds "<<preds[i];
            }


        s->setIndice_proximite((m_taille-1)/temp,1); // On normalise
        s->setIndice_proximite(temp,2);

    }

}


void Sommet::affi_indice_proximite() const
{
    std::cout<<"Sommet : "<<m_nom<< std::endl;
    std::cout<<"Indice normalisee  : "<<m_indice.proximite_normalise<<"\n" ;
    std::cout<<"Indice non  normalisee  : "<<m_indice.proximite_non_normalise<<"\n" ;

}

void Graphe::affi_indice_Tproximite() const
{
    for (auto s : m_sommets)
    {
        s->affi_indice_proximite();
        std::cout<<std::endl;
    }
}

// SS fonction de visualisation d'indice

void Graphe::Visualisation_indice(int indice)
{

    std::vector<float> valeurindice;
    float tempmax=0;

    switch (indice)
    {

    case 1 :  ///Pour chaque indice on push l'indice dans valeur indice suivant le choix du client

        for(auto k : m_sommets)
        {
            valeurindice.push_back(k->getIndice(1));
            if(tempmax<k->getIndice(1))
                tempmax=k->getIndice(1);

        }

        break;

    case 2 : /// Indice vecteur propre

        for(auto k : m_sommets)
        {
            valeurindice.push_back(k->getIndice(2));
            if(tempmax<k->getIndice(2))
                tempmax=k->getIndice(2);

        }

        break;


    case 3 : /// Indice vecteur proximite

        for(auto k : m_sommets)
        {
            valeurindice.push_back(k->getIndice(3));
            if(tempmax<k->getIndice(3))
                tempmax=k->getIndice(3);

        }

        break;

    case 4 : /// Indice intermediare

        for(auto k : m_sommets)
        {
            valeurindice.push_back(k->getIndice(4));
            if(tempmax<k->getIndice(4))
                tempmax=k->getIndice(4);

        }

        break;

    }

    std::sort(valeurindice.begin(),valeurindice.end());

    for(auto k : m_sommets)
        for(int i=0 ; i<valeurindice.size(); i++)
            if(valeurindice[i]==k->getIndice(indice))
                if(k->getColor()==0)
                    k->setColor((k->getIndice(indice)*255)/tempmax); /// A voir




}



#include "header.h"

void Sommet::Dessiner(BITMAP* bmp)
{
    const char *nom = m_nom.c_str();


   circlefill(bmp,m_x,m_y,6,makecol(m_couleur,0,0)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));

    if(m_ligne==2)
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,20,0));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(255,20,0));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(255,20,0));

        }
         circlefill(bmp,m_x,m_y,3,makecol(255,20,0));
    }
    else if(m_ligne==2)
    {

        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(60,145,220));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(60,145,220));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(60,145,220));

        }
         circlefill(bmp,m_x,m_y,3,makecol(60,145,220));

    }
    else if(m_ligne==2)
    {



        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,150,0));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(220,150,0));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(220,150,0));

        }
         circlefill(bmp,m_x,m_y,3,makecol(220,150,0));
    }
    else if(m_ligne==2)
    {

 textprintf_ex(bmp,font,m_x+30,m_y,makecol(0,0,0),-1,nom);
        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(0,150,65));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(0,150,65));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(0,150,65));
        }
         circlefill(bmp,m_x,m_y,3,makecol(0,150,65));

    }
    else if(m_ligne==28)
    {

         textprintf_ex(bmp,font,m_x+30,m_y,makecol(0,0,0),-1,nom);
        for (auto s : m_successeurs) ///Dessin des Arcs
        {

            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,90,180));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(220,90,180));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(220,90,180));

        }
          circlefill(bmp,m_x,m_y,3,makecol(220,90,180));

    }
    else
    {
/*
        circlefill(bmp,m_x,m_y,5,makecol(0,0,0));
        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,0,0));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(255,0,0));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(255,0,0));


        }

        */
    }


}

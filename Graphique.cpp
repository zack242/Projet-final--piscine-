#include "header.h"

void Sommet::Dessiner(BITMAP* bmp)
{
    const char *nom = m_nom.c_str();


    if(m_ligne==24)
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,20,0));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(255,20,0));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(255,20,0));

        }

    }
    else if(m_ligne==25)
    {

        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(60,145,220));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(60,145,220));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(60,145,220));

        }
// textprintf_ex(bmp,font,m_x,m_y,makecol(0,0,0),-1,nom);

    }
    else if(m_ligne==26)
    {

 //textprintf_ex(bmp,font,m_x,m_y,makecol(0,0,0),-1,nom);

        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,150,0));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(220,150,0));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(220,150,0));

        }

    }
    else if(m_ligne==27)
    {

 //textprintf_ex(bmp,font,m_x+30,m_y,makecol(0,0,0),-1,nom);
        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(0,150,65));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(0,150,65));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(0,150,65));
        }


    }
    else if(m_ligne==28)
    {

   // textprintf_ex(bmp,font,m_x+30,m_y,makecol(0,0,0),-1,nom);
        for (auto s : m_successeurs) ///Dessin des Arcs
        {

            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,90,180));
            line(bmp,m_x-1,m_y-1,s.first->getX()-1,s.first->getY()-1,makecol(220,90,180));
            line(bmp,m_x+1,m_y+1,s.first->getX()+1,s.first->getY()+1,makecol(220,90,180));

        }


    }
    else
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,0,0));


        }


    }



}


void Sommet::DessinSommet(BITMAP* bmp)
{

  const char *nom = m_nom.c_str();


if((m_num==22 || m_num==60 ||  m_num==23  ||  m_num==81 || m_num==62 || m_num==0 || m_num==44  || m_num==45
   || m_num==6 || m_num==11 ||  m_num==155  ||  m_num==74 || m_num==164 || m_num==192 || m_num==194  || m_num==36 || m_num==50
  ||  m_num==90 ||  m_num==91  || m_num==164  || m_num == 113  ||
   m_num == 165 ||  m_num == 221 || m_num ==212 ||  m_num==231 ||  m_num==220 ||  m_num==111 ) && ( m_ligne!=0) )
{
    textprintf_ex(bmp,font,m_x+10,m_y-10,makecol(0,0,0),-1,nom);

      circlefill(bmp,m_x,m_y,8,makecol(255,255,255)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));
      circlefill(bmp,m_x,m_y,6,makecol(m_couleur,0,0)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));

}else
{

 circlefill(bmp,m_x,m_y,4,makecol(m_couleur,0,0)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));

}
if(m_ligne==0)
    {
 textprintf_ex(bmp,font,m_x+10,m_y-10,makecol(0,0,0),-1,nom);

      circlefill(bmp,m_x,m_y,8,makecol(255,255,255)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));
      circlefill(bmp,m_x,m_y,6,makecol(m_couleur,0,0)); ///Cercle pour la visu des indicescirclefill(bmp,m_x,m_y,0,makecol(0,0,0));

}

}



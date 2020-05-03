#include "header.h"

void Sommet::Dessiner(BITMAP* bmp , Svgfile& svgfile)
{
    const char *nom = m_nom.c_str();


    if(m_ligne==24)
    {

        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,20,0));

            svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(255,20,0));

        }

    }
    else if(m_ligne==25)
    {

        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(60,145,220));

            svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(60,140,220));

        }


    }
    else if(m_ligne==26)
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
        line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,150,0));

         svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(220,150,0));

        }

    }
    else if(m_ligne==27)
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(0,150,65));

            svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(0,150,65));
        }


    }
    else if(m_ligne==28)
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {

            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(220,90,180));

            svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(220,90,180));

        }


    }
    else
    {


        for (auto s : m_successeurs) ///Dessin des Arcs
        {
            line(bmp,m_x,m_y,s.first->getX(),s.first->getY(),makecol(255,0,0));

            svgfile.addLine(m_x,m_y,s.first->getX(),s.first->getY(),svgfile.makeRGB(255,0,0));


        }


    }



}


void Sommet::DessinSommet(BITMAP* bmp,Svgfile& svgfile)
{

  const char *nom = m_nom.c_str();


if((m_num==22 || m_num==60 ||  m_num==23  ||  m_num==81 || m_num==62 || m_num==0 || m_num==44  || m_num==45
   || m_num==6 || m_num==11 ||  m_num==155  ||  m_num==74 || m_num==164 || m_num==192 || m_num==194  || m_num==36 || m_num==50
  ||  m_num==90 ||  m_num==91  || m_num==164  || m_num == 113  ||
   m_num == 165 ||  m_num == 221 || m_num ==212 ||  m_num==231 ||  m_num==220 ||  m_num==111 ) && ( m_ligne!=0) )
{
    textprintf_ex(bmp,font,m_x+10,m_y-10,makecol(0,0,0),-1,nom);

    svgfile.addText(m_x+10,m_y-10,nom,svgfile.makeRGB(0,0,0));

      circlefill(bmp,m_x,m_y,8,makecol(255,255,255));
      circlefill(bmp,m_x,m_y,6,makecol(m_couleur,0,0));

      svgfile.addDisk(m_x,m_y,8,svgfile.makeRGB(255,255,255));
      svgfile.addDisk(m_x,m_y,6,svgfile.makeRGB(m_couleur,0,0));

}else
{

 circlefill(bmp,m_x,m_y,4,makecol(m_couleur,0,0));

 svgfile.addDisk(m_x,m_y,4,svgfile.makeRGB(m_couleur,0,0));


}
if(m_ligne==0)
    {
      textprintf_ex(bmp,font,m_x+10,m_y-10,makecol(0,0,0),-1,nom);

      svgfile.addText(m_x+10,m_y-10,nom,svgfile.makeRGB(0,0,0));

      circlefill(bmp,m_x,m_y,8,makecol(255,255,255));
      circlefill(bmp,m_x,m_y,6,makecol(m_couleur,0,0));

      svgfile.addDisk(m_x,m_y,8,svgfile.makeRGB(255,255,255));
      svgfile.addDisk(m_x,m_y,6,svgfile.makeRGB(m_couleur,0,0));


}

}



#include "geometric-drawer/GeometricDrawer.h"

GeometricDrawer::GeometricDrawer(SDL_Window *window, SDL_Renderer *renderer) : m_window(window), m_renderer(renderer)
{
}

GeometricDrawer::~GeometricDrawer()
{
}

void GeometricDrawer::init()
{
    // TODO: Init
}

void GeometricDrawer::add(Figure *figure)
{
    m_figureList.push_back(figure);
}

void GeometricDrawer::draw()
{
    // for (Figure *f : m_figureList)
    // {
    //     // TODO: Render figures
    // }
}

void GeometricDrawer::destroy()
{
    for (size_t i = 0; i < m_figureList.size(); i++)
    {
        delete m_figureList[i];
    }
    m_figureList.clear();
}
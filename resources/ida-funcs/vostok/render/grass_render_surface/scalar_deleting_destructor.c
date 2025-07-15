vostok::render::grass_render_surface *__thiscall vostok::render::grass_render_surface::`scalar deleting destructor'(
        vostok::render::grass_render_surface *this,
        char a2)
{
  vostok::render::grass_render_surface::~grass_render_surface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

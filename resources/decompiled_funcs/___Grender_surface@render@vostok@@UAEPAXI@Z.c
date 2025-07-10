vostok::render::user_render_surface_editable *__thiscall vostok::render::render_surface::`scalar deleting destructor'(
        vostok::render::user_render_surface_editable *this,
        char a2)
{
  vostok::render::render_surface::~render_surface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

vostok::render::static_render_surface *__thiscall vostok::render::static_render_surface::`vector deleting destructor'(
        vostok::render::static_render_surface *this,
        char a2)
{
  this->__vftable = (vostok::render::static_render_surface_vtbl *)&vostok::render::static_render_surface::`vftable';
  vostok::render::render_surface::~render_surface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

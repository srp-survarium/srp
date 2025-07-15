vostok::render::static_render_model *__thiscall vostok::render::grass_render_model::`vector deleting destructor'(
        vostok::render::static_render_model *this,
        char a2)
{
  vostok::render::render_model::~render_model(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

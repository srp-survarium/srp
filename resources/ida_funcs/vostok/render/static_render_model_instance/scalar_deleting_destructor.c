vostok::render::static_render_model_instance *__thiscall vostok::render::static_render_model_instance::`scalar deleting destructor'(
        vostok::render::static_render_model_instance *this,
        char a2)
{
  vostok::render::static_render_model_instance::~static_render_model_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

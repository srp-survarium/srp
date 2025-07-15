vostok::render::skeleton_render_model_instance *__thiscall vostok::render::skeleton_render_model_instance::`scalar deleting destructor'(
        vostok::render::skeleton_render_model_instance *this,
        char a2)
{
  vostok::render::skeleton_render_model_instance::~skeleton_render_model_instance(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

vostok::render::user_render_model_instance *__thiscall vostok::render::user_render_model_instance::`scalar deleting destructor'(
        vostok::render::user_render_model_instance *this,
        char a2)
{
  vostok::render::render_model_instance_impl *v3; // ecx

  vostok::render::render_surface_instance::~render_surface_instance(
    (vostok::render::render_surface_instance *)this,
    &this->m_surface_instance.m_override_diffuse_texture);
  vostok::render::render_model_instance_impl::~render_model_instance_impl(v3, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

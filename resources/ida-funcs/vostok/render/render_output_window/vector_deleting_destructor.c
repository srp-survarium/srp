vostok::render::render_output_window *__thiscall vostok::render::render_output_window::`vector deleting destructor'(
        vostok::render::render_output_window *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::render::res_render_output,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_output; // eax
  vostok::render::res_render_output *m_object; // ecx

  p_m_output = &this->m_output;
  m_object = this->m_output.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        p_m_output->m_object);
  }
  `vector destructor iterator'(
    (char *)&this->m_targets,
    0xA0u,
    73,
    (void (__thiscall *)(void *))vostok::render::render_target_instance::~render_target_instance);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

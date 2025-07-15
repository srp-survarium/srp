vostok::configs::binary_config *__thiscall vostok::engine::engine_world::get_sound_world(
        vostok::engine::engine_world *this)
{
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *p_m_shader_mask_config; // edi

  p_m_shader_mask_config = &this->m_shader_mask_config;
  if ( !this->m_shader_mask_config.m_object )
  {
    do
      vostok::threading::yield(1u, (vostok::tasks *)this);
    while ( !p_m_shader_mask_config->m_object );
  }
  return p_m_shader_mask_config->m_object;
}

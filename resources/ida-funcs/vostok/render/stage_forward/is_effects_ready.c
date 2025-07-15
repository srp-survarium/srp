bool __thiscall vostok::render::stage_forward::is_effects_ready(vostok::render::stage_forward *this)
{
  unsigned int v1; // edx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *m_gbuffer_depth_effect; // eax

  v1 = 0;
  m_gbuffer_depth_effect = this->m_gbuffer_depth_effect;
  do
  {
    if ( v1 != 12 && !m_gbuffer_depth_effect->m_object )
      return 0;
    ++v1;
    ++m_gbuffer_depth_effect;
  }
  while ( v1 < 0xF );
  return this->m_opaque_geometry_mask_effect.m_object && this->m_debug_tracer_effect.m_object;
}

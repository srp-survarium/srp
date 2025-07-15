vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::set_cull_mode@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        D3D11_CULL_MODE mode@<edi>)
{
  bool v2; // zf

  if ( !this->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v2 = this->m_state_descriptor.m_rasterizer_desc.CullMode == mode;
      this->m_state_descriptor.m_rasterizer_desc.CullMode = mode;
      this->m_state_descriptor.m_rasterizer_desc_updated |= !v2;
    }
  }
  return this;
}

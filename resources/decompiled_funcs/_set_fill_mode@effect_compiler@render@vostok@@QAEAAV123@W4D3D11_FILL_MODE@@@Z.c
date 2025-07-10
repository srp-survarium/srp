vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::set_fill_mode@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        D3D11_FILL_MODE fill_mode@<edi>)
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
      v2 = this->m_state_descriptor.m_rasterizer_desc.FillMode == fill_mode;
      this->m_state_descriptor.m_rasterizer_desc.FillMode = fill_mode;
      this->m_state_descriptor.m_rasterizer_desc_updated |= !v2;
    }
  }
  return this;
}

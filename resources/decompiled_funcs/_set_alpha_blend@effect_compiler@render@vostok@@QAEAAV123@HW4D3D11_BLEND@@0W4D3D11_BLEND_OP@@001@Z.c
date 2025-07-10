vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_alpha_blend@<eax>(
        D3D11_BLEND dest_blend@<edi>,
        vostok::render::effect_compiler *this,
        int blend_enable,
        D3D11_BLEND src_blend,
        D3D11_BLEND_OP blend_op,
        D3D11_BLEND src_alpha_blend,
        D3D11_BLEND_OP dest_alpha_blend,
        D3D11_BLEND_OP blend_alpha_op)
{
  D3D11_BLEND v9; // [esp+0h] [ebp-Ch]

  if ( !this->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
      vostok::render::state_descriptor::set_alpha_blend(
        dest_blend,
        blend_op,
        src_alpha_blend,
        dest_alpha_blend,
        &this->m_state_descriptor,
        blend_enable,
        src_blend,
        v9);
  }
  return this;
}

vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_stencil@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        D3D11_STENCIL_OP zfail@<edi>,
        int enable,
        unsigned int ref,
        unsigned __int8 read_mask,
        unsigned __int8 write_mask,
        D3D11_COMPARISON_FUNC func,
        D3D11_STENCIL_OP fail,
        D3D11_STENCIL_OP pass)
{
  if ( !this->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      this->m_state_descriptor.m_depth_stencil_desc.StencilEnable = enable;
      this->m_state_descriptor.m_depth_stencil_desc.StencilWriteMask = write_mask;
      this->m_state_descriptor.m_depth_stencil_desc.StencilReadMask = read_mask;
      this->m_state_descriptor.m_stencil_ref = ref;
      this->m_state_descriptor.m_depth_stencil_desc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
      this->m_state_descriptor.m_depth_stencil_desc.FrontFace.StencilDepthFailOp = zfail;
      this->m_state_descriptor.m_depth_stencil_desc.FrontFace.StencilPassOp = fail;
      this->m_state_descriptor.m_depth_stencil_desc.FrontFace.StencilFunc = func;
      this->m_state_descriptor.m_depth_stencil_desc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
      this->m_state_descriptor.m_depth_stencil_desc.BackFace.StencilDepthFailOp = zfail;
      this->m_state_descriptor.m_depth_stencil_desc.BackFace.StencilPassOp = fail;
      this->m_state_descriptor.m_depth_stencil_desc.BackFace.StencilFunc = func;
      this->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  return this;
}

void __thiscall vostok::render::scr_quad_effect::compile(
        vostok::render::scr_quad_effect *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  D3D11_BLEND_OP v10; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v11; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v12; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v13; // [esp+0h] [ebp-20h]
  vostok::render::shader_include_getter include_getter; // [esp+10h] [ebp-10h] BYREF
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  v16 = 4;
  include_getter.__vftable = 0;
  v15 = 0;
  v17 = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&stru_965DD0.configuration[1],
    0,
    &stru_965DD0,
    &include_getter);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v10);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    v11,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
  vostok::render::effect_compiler::begin_technique(v6);
  v16 = 4;
  include_getter.__vftable = 0;
  v15 = 0;
  v17 = 0;
  vostok::render::effect_compiler::begin_pass(
    v7,
    (const char *)compiler,
    (const char *)&stru_965DD0.configuration[1],
    0,
    &stru_965DE0,
    &include_getter);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v12);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    v13,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::end_pass(v8);
  vostok::render::effect_compiler::end_technique(v9);
}

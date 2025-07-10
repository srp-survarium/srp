void __thiscall vostok::render::effect_resolve_particles::compile(
        vostok::render::effect_resolve_particles *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  D3D11_BLEND_OP v6; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v7; // [esp+0h] [ebp-20h]
  bool v8; // [esp+0h] [ebp-20h]
  vostok::render::shader_include_getter include_getter; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  v11 = 4;
  include_getter.__vftable = 0;
  v10 = 0;
  v12 = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&gs_name,
    0,
    (const vostok::render::shader_configuration *)"resolve_particles",
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_fill_mode(compiler, D3D11_FILL_SOLID);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v6);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v7);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_particle_result",
    "$user$particle_result",
    0,
    v8,
    0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
}

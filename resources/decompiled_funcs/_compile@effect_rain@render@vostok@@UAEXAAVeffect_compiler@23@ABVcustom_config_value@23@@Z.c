void __thiscall vostok::render::effect_rain::compile(
        vostok::render::effect_rain *this,
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
  bool v11; // [esp+0h] [ebp-20h]
  bool v12; // [esp+0h] [ebp-20h]
  bool v13; // [esp+0h] [ebp-20h]
  bool v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-20h]
  bool v16; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v17; // [esp+0h] [ebp-20h]
  bool v18; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_960F2C,
    0,
    (vostok::render::shader_configuration *)&stru_960F2C,
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v10);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_scroll_rain", "engine/scroll_rain_0", 0, v11);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v12);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_rain_shadow_map",
    &stru_963F84.m_name.m_string.m_buffer[92],
    0,
    v13);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_frame_color", "$user$generic1", 0, v14);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[136],
    "$user$blur3",
    0,
    v15);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    v16);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v6, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v7,
    compiler,
    (char *)&stru_967744,
    0,
    (vostok::render::shader_configuration *)&stru_967744,
    &include_getter);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v17);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_rain", "$user$rain_result", 0, v18);
  vostok::render::effect_compiler::end_pass(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v9, (int)compiler);
}

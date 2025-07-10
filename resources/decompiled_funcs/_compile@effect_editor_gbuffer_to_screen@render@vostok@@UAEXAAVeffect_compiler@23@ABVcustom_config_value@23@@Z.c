void __thiscall vostok::render::effect_editor_gbuffer_to_screen::compile(
        vostok::render::effect_editor_gbuffer_to_screen *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  D3D11_BLEND_OP v6; // [esp+0h] [ebp-20h]
  bool v7; // [esp+0h] [ebp-20h]
  bool v8; // [esp+0h] [ebp-20h]
  bool v9; // [esp+0h] [ebp-20h]
  bool v10; // [esp+0h] [ebp-20h]
  bool v11; // [esp+0h] [ebp-20h]
  bool v12; // [esp+0h] [ebp-20h]
  bool v13; // [esp+0h] [ebp-20h]
  bool v14; // [esp+0h] [ebp-20h]
  bool v15; // [esp+0h] [ebp-20h]
  bool v16; // [esp+0h] [ebp-20h]
  bool v17; // [esp+0h] [ebp-20h]
  bool v18; // [esp+0h] [ebp-20h]
  bool v19; // [esp+0h] [ebp-20h]
  bool v20; // [esp+0h] [ebp-20h]
  bool v21; // [esp+0h] [ebp-20h]
  bool v22; // [esp+0h] [ebp-20h]
  bool v23; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&gs_name,
    0,
    (vostok::render::shader_configuration *)&stru_96609C,
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
    D3D11_BLEND_ZERO,
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v6);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v7);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v8);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v9);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_emissive", "$user$emmisive", 0, v10);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc_3d.Usage,
    "$user$ssao_accumulator_full_x",
    0,
    v11);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_accumulator_dif", "$user$accum_diffuse", 0, v12);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_accumulator_spec",
    "$user$accum_specular",
    0,
    v13);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9656C8,
    "$user$generic0",
    0,
    v14);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9656C8.m_rescale_min,
    "$user$generic1",
    0,
    v15);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_distortion", "$user$distortion", 0, v16);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[208],
    "$user$frame_luminance",
    0,
    v17);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_frame_luminance_histogram",
    "$user$frame_luminance_histogram",
    0,
    v18);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v19);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_decals_normal", "$user$decals_normal", 0, v20);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_indirect_specular",
    "$user$indirect_lighting_specular",
    0,
    v21);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_lpv_accumulation",
    "$user$lpv_accumulation",
    0,
    v22);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_sun_translucensy_help_data",
    "$user$sun_translucensy_help_data",
    0,
    v23);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
}

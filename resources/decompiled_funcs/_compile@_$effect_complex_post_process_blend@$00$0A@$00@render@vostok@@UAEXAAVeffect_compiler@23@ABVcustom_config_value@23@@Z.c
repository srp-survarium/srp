void __thiscall vostok::render::effect_complex_post_process_blend<1,0,1>::compile(
        vostok::render::effect_complex_post_process_blend<1,0,1> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  bool v6; // [esp+0h] [ebp-20h]
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
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0x1000000;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x100400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    &stru_9656C8.m_name.m_string.m_buffer[100],
    0,
    (const vostok::render::shader_configuration *)&stru_9656C8.m_name.m_string.m_buffer[72],
    (vostok::render::shader_include_getter *)&configuration);
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
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[112],
    "$user$blur0",
    0,
    v6,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[136],
    "$user$blur2",
    0,
    v7,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[172],
    "$user$blur3",
    0,
    v8,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_frame_color", "$user$generic0", 0, v9, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v10, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[208],
    "$user$frame_luminance",
    0,
    v11,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[228],
    "$user$light_scattering_mask",
    0,
    v12,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    &stru_9656C8.m_name.m_string.m_buffer[252],
    "$user$light_scattering_result",
    0,
    v13,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_sphere_falloff",
    (const char *)&stru_9656C8.m_desc_valid,
    0,
    v14,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_bokeh_image", "fx/bokeh_image", 0, v15, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_lighting_buffer", "$user$accum_diffuse", 0, v16, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_lens_flares", "$user$lens_flares", 0, v17, 0xFFFFFFFF);
  if ( (*((_BYTE *)&configuration.0 + 9) & 0x10) != 0 )
    vostok::render::effect_compiler::set_texture(compiler, "t_grain_noise", "engine/noise_64x64", 0, v18, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    "t_hiz_depth",
    "$user$hiz_occlusion_depth_mips",
    0,
    v18,
    0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
}

void __thiscall vostok::render::effect_atmospheric_scattering::compile(
        vostok::render::effect_atmospheric_scattering *this,
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
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  bool v31; // [esp+0h] [ebp-20h]
  bool v32; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v33; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v34; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v35; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v36; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v37; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v38; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v39; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v41; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v42; // [esp+0h] [ebp-20h]
  bool v43; // [esp+0h] [ebp-20h]
  bool v44; // [esp+0h] [ebp-20h]
  bool v45; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v46; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v47; // [esp+0h] [ebp-20h]
  bool v48; // [esp+0h] [ebp-20h]
  bool v49; // [esp+0h] [ebp-20h]
  bool v50; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v51; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    (char *)&stru_9675C4,
    0,
    (vostok::render::shader_configuration *)&stru_9675C4,
    &include_getter);
  vostok::render::effect_compiler::end_pass(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v5, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v6, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    (char *)&stru_960F6C,
    0,
    (vostok::render::shader_configuration *)&stru_960F6C,
    &include_getter);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[220],
    "$user$mie_scattering",
    0,
    v31);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[240],
    "$user$rayleigh_scattering",
    0,
    v32);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v33);
  vostok::render::effect_compiler::end_pass(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v8, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v10,
    compiler,
    "atmosphere_clouds",
    0,
    (vostok::render::shader_configuration *)&stru_9675E0,
    &include_getter);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_SRC_ALPHA,
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v34);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v35);
  vostok::render::effect_compiler::end_pass(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v12, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v14,
    compiler,
    "atmosphere_clouds",
    0,
    (vostok::render::shader_configuration *)&stru_967614,
    &include_getter);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_SRC_COLOR,
    compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v36);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v37);
  vostok::render::effect_compiler::end_pass(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v16, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    (char *)&stru_967630,
    0,
    (vostok::render::shader_configuration *)&stru_967630,
    &include_getter);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_DEST_ALPHA,
    compiler,
    1,
    D3D11_BLEND_INV_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v38);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::end_pass(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v19, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v20, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v21,
    compiler,
    (char *)&stru_967630,
    0,
    (vostok::render::shader_configuration *)&stru_967630,
    &include_getter);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_INV_DEST_ALPHA,
    compiler,
    1,
    D3D11_BLEND_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v40);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v41);
  vostok::render::effect_compiler::end_pass(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v23, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v24, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v25,
    compiler,
    "atmospheric_scattering_on_geometry",
    0,
    (vostok::render::shader_configuration *)&stru_967644,
    &include_getter);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v42);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[220],
    "$user$mie_scattering",
    0,
    v43);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[240],
    "$user$rayleigh_scattering",
    0,
    v44);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v45);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_SRC_COLOR,
    compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    v46);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::end_pass(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v27, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v28, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    "atmospheric_scattering_on_geometry",
    0,
    (vostok::render::shader_configuration *)&stru_967690,
    &include_getter);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v47);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[220],
    "$user$mie_scattering",
    0,
    v48);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    &texture.m_name.m_string.m_buffer[240],
    "$user$rayleigh_scattering",
    0,
    v49);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v50);
  vostok::render::effect_compiler::set_alpha_blend(
    D3D11_BLEND_ONE,
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    v51);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
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
  vostok::render::effect_compiler::end_pass(
    v29,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v30, (int)compiler);
}

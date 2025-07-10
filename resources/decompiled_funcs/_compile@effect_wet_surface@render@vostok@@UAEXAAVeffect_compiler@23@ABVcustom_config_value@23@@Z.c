void __thiscall vostok::render::effect_wet_surface::compile(
        vostok::render::effect_wet_surface *this,
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
  bool v21; // [esp+0h] [ebp-20h]
  bool v22; // [esp+0h] [ebp-20h]
  bool v23; // [esp+0h] [ebp-20h]
  bool v24; // [esp+0h] [ebp-20h]
  bool v25; // [esp+0h] [ebp-20h]
  bool v26; // [esp+0h] [ebp-20h]
  bool v27; // [esp+0h] [ebp-20h]
  bool v28; // [esp+0h] [ebp-20h]
  bool v29; // [esp+0h] [ebp-20h]
  bool v30; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v31; // [esp+0h] [ebp-20h]
  bool v32; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v33; // [esp+0h] [ebp-20h]
  bool v34; // [esp+0h] [ebp-20h]
  bool v35; // [esp+0h] [ebp-20h]
  bool v36; // [esp+0h] [ebp-20h]
  bool v37; // [esp+0h] [ebp-20h]
  bool v38; // [esp+0h] [ebp-20h]
  bool v39; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v40; // [esp+0h] [ebp-20h]
  bool v41; // [esp+0h] [ebp-20h]
  bool v42; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v43; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v44; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    compiler,
    "wet_sufrace",
    0,
    (vostok::render::shader_configuration *)&stru_966BF8,
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v21);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal_copy", 0, v22);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v23);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_rain_shadow_map",
    &stru_963F84.m_name.m_string.m_buffer[92],
    0,
    v24);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_water_flowing_normals",
    "engine/water_flowing_nmap",
    0,
    v25);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_water_flowing_specular",
    "engine/water_flowing_spec",
    0,
    v26);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_puddle_rings",
    "engine/rain_puddle_rings",
    0,
    v27);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_rain_stream", "engine/rain_stream", 0, v28);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_rain_puddle", "engine/rain_puddle", 0, v29);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_rain_puddle_mask",
    "engine/rain_puddle_mask",
    0,
    v30);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v31);
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
    "wet_sufrace",
    0,
    (vostok::render::shader_configuration *)&stru_966D40,
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_unpacked_normal", "$user$generic1", 0, v32);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v33);
  vostok::render::effect_compiler::end_pass(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v9, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v10, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&include_getter,
    compiler,
    "wet_sufrace",
    0,
    (vostok::render::shader_configuration *)&stru_966D70,
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v34);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v35);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v36);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_rain_shadow_map",
    &stru_963F84.m_name.m_string.m_buffer[92],
    0,
    v37);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_accum_diffuse", "$user$accum_diffuse", 0, v38);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_accum_specular", "$user$accum_specular", 0, v39);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v40);
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
    "wet_sufrace",
    0,
    (vostok::render::shader_configuration *)&stru_966DB0,
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_accum_diffuse", "$user$generic0", 0, v41);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_accum_specular", "$user$generic1", 0, v42);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v43);
  vostok::render::effect_compiler::end_pass(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v16, (int)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_pass(
    v18,
    compiler,
    "wet_sufrace",
    0,
    (vostok::render::shader_configuration *)&stru_966DC8,
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    D3D11_STENCIL_OP_KEEP,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    v44);
  vostok::render::effect_compiler::end_pass(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v20, (int)compiler);
}

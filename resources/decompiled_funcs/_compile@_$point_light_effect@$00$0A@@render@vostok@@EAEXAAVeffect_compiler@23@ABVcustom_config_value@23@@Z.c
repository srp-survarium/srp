void __thiscall vostok::render::point_light_effect<1,0>::compile(
        vostok::render::point_light_effect<1,0> *this,
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
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  D3D11_BLEND_OP v37; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v38; // [esp+0h] [ebp-20h]
  bool v39; // [esp+0h] [ebp-20h]
  bool v40; // [esp+0h] [ebp-20h]
  bool v41; // [esp+0h] [ebp-20h]
  bool v42; // [esp+0h] [ebp-20h]
  bool v43; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v44; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v45; // [esp+0h] [ebp-20h]
  bool v46; // [esp+0h] [ebp-20h]
  bool v47; // [esp+0h] [ebp-20h]
  bool v48; // [esp+0h] [ebp-20h]
  bool v49; // [esp+0h] [ebp-20h]
  bool v50; // [esp+0h] [ebp-20h]
  bool v51; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v52; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v53; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v54; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v55; // [esp+0h] [ebp-20h]
  bool v56; // [esp+0h] [ebp-20h]
  bool v57; // [esp+0h] [ebp-20h]
  bool v58; // [esp+0h] [ebp-20h]
  bool v59; // [esp+0h] [ebp-20h]
  bool v60; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v61; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v62; // [esp+0h] [ebp-20h]
  bool v63; // [esp+0h] [ebp-20h]
  bool v64; // [esp+0h] [ebp-20h]
  bool v65; // [esp+0h] [ebp-20h]
  bool v66; // [esp+0h] [ebp-20h]
  bool v67; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v68; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v69; // [esp+0h] [ebp-20h]
  bool v70; // [esp+0h] [ebp-20h]
  bool v71; // [esp+0h] [ebp-20h]
  bool v72; // [esp+0h] [ebp-20h]
  bool v73; // [esp+0h] [ebp-20h]
  bool v74; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v75; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v76; // [esp+0h] [ebp-20h]
  bool v77; // [esp+0h] [ebp-20h]
  bool v78; // [esp+0h] [ebp-20h]
  bool v79; // [esp+0h] [ebp-20h]
  bool v80; // [esp+0h] [ebp-20h]
  bool v81; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v82; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v83; // [esp+0h] [ebp-20h]
  bool v84; // [esp+0h] [ebp-20h]
  bool v85; // [esp+0h] [ebp-20h]
  bool v86; // [esp+0h] [ebp-20h]
  bool v87; // [esp+0h] [ebp-20h]
  bool v88; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration configuration; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0x4000;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&stru_9642F8.m_desc.Height,
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_desc_3d.MiscFlags,
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v37);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v38,
    D3D11_STENCIL_OP_INVERT);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_BACK);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v39, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v40, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v41,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v42, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v43, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
  vostok::render::effect_compiler::begin_technique(v6);
  vostok::render::effect_compiler::begin_pass(
    v7,
    (const char *)compiler,
    (const char *)&stru_9642F8.m_desc.Height,
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_desc_3d.MiscFlags,
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v44,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v45);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v46, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v47, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v48,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_emissive", "$user$emmisive", 0, v49, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v50, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v51, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v8);
  vostok::render::effect_compiler::end_technique(v9);
  vostok::render::effect_compiler::begin_technique(v10);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&configuration,
    (const char *)compiler,
    (const char *)&stru_9642F8.m_desc.Height,
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_desc_3d.MiscFlags,
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v52,
    D3D11_STENCIL_OP_INVERT);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::color_write_enable(v11, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v12);
  vostok::render::effect_compiler::end_technique(v13);
  vostok::render::effect_compiler::begin_technique(v14);
  vostok::render::effect_compiler::begin_pass(
    v15,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[8],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[8],
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v53,
    D3D11_STENCIL_OP_INVERT);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::color_write_enable(v16, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v17);
  vostok::render::effect_compiler::end_technique(v18);
  vostok::render::effect_compiler::begin_technique(v19);
  vostok::render::effect_compiler::begin_pass(
    v20,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[8],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[8],
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v54);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v55,
    D3D11_STENCIL_OP_INVERT);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_BACK);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v56, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v57, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v58,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v59, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v60, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v21);
  vostok::render::effect_compiler::end_technique(v22);
  vostok::render::effect_compiler::begin_technique(v23);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&configuration,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[8],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[8],
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0xFFu,
    0x40u,
    0xFFu,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    v61,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v62);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v63, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v64, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v65,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v66, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v67, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v24);
  vostok::render::effect_compiler::end_technique(v25);
  vostok::render::effect_compiler::begin_technique(v26);
  vostok::render::effect_compiler::begin_pass(
    v27,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[8],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[8],
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v68,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v69);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v70, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v71, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v72,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v73, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v74, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v28);
  vostok::render::effect_compiler::end_technique(v29);
  vostok::render::effect_compiler::begin_technique(v30);
  vostok::render::effect_compiler::begin_pass(
    v31,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[24],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[24],
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
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v75,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v76);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v77, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v78, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v79,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v80, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v81, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v32);
  vostok::render::effect_compiler::end_technique(v33);
  vostok::render::effect_compiler::begin_technique(v34);
  vostok::render::effect_compiler::begin_pass(
    (vostok::render::effect_compiler *)&configuration,
    (const char *)compiler,
    &stru_9649F4.m_name.m_string.m_buffer[24],
    0,
    (const vostok::render::shader_configuration *)&stru_9649F4.m_name.m_string.m_buffer[24],
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
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v82,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v83);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_FRONT);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v84, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_normal", "$user$normal", 0, v85, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(
    compiler,
    (const char *)&stru_9642F8.m_desc.ArraySize,
    "$user$albedo",
    0,
    v86,
    0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_diffuse", "$user$decals_diffuse", 0, v87, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_texture(compiler, "t_decals_normal", "$user$decals_normal", 0, v88, 0xFFFFFFFF);
  vostok::render::effect_compiler::end_pass(v35);
  vostok::render::effect_compiler::end_technique(v36);
}

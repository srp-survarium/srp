void __thiscall vostok::render::effect_system_ui::compile(
        vostok::render::effect_system_ui *this,
        vostok::render::effect_compiler *c,
        const vostok::render::custom_config_value *config)
{
  char *data; // edi
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  D3D11_STENCIL_OP v7; // ecx
  vostok::render::effect_compiler *v8; // esi
  vostok::render::effect_compiler *v9; // eax
  vostok::render::effect_compiler *v10; // eax
  vostok::render::effect_compiler *v11; // eax
  vostok::render::effect_compiler *v12; // eax
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::res_pass *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::custom_config_value *v16; // ecx
  char *v17; // edi
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // eax
  vostok::render::effect_compiler *v20; // ecx
  D3D11_STENCIL_OP v21; // ecx
  vostok::render::effect_compiler *v22; // esi
  vostok::render::effect_compiler *v23; // eax
  vostok::render::effect_compiler *v24; // eax
  vostok::render::effect_compiler *v25; // eax
  vostok::render::effect_compiler *v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::res_pass *v28; // eax
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // eax
  vostok::render::effect_compiler *v31; // ecx
  D3D11_STENCIL_OP v32; // ecx
  vostok::render::effect_compiler *v33; // esi
  vostok::render::effect_compiler *v34; // eax
  vostok::render::effect_compiler *v35; // eax
  vostok::render::effect_compiler *v36; // eax
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::res_pass *v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // eax
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // esi
  vostok::render::effect_compiler *v44; // eax
  vostok::render::effect_compiler *v45; // eax
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::res_pass *v47; // eax
  vostok::render::effect_compiler *v48; // ecx
  D3D11_BLEND_OP v49; // [esp-10h] [ebp-30h]
  D3D11_BLEND_OP v50; // [esp-10h] [ebp-30h]
  bool v51; // [esp+0h] [ebp-20h]
  bool v52; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v53; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v54; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  data = (char *)vostok::render::custom_config_value::operator[](
                   (vostok::render::custom_config_value *)this,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"ui_texture0")->data;
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v5 = vostok::render::effect_compiler::begin_technique(v4, (int)c);
  v8 = vostok::render::effect_compiler::begin_pass(
         v6,
         v5,
         (char *)&stru_966240.configuration[1],
         0,
         (vostok::render::shader_configuration *)&stru_966240,
         &include_getter);
  if ( !v8->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v8->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      v8->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      v8->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v8->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v49 = v7;
  v9 = vostok::render::effect_compiler::set_stencil(
         v8,
         D3D11_STENCIL_OP_KEEP,
         0,
         0x20u,
         0,
         0xFFu,
         D3D11_COMPARISON_ALWAYS,
         D3D11_STENCIL_OP_REPLACE,
         v7);
  v10 = vostok::render::effect_compiler::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          v9,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          v49);
  v11 = vostok::render::effect_compiler::set_cull_mode(v10, D3D11_CULL_NONE);
  v12 = vostok::render::effect_compiler::set_texture(
          0xFFFFFFFF,
          v11,
          &stru_963F84.m_name.m_string.m_buffer[116],
          data,
          0,
          v51);
  v14 = vostok::render::effect_compiler::end_pass(
          v13,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v12);
  vostok::render::effect_compiler::end_technique(v15, (int)v14);
  v17 = (char *)vostok::render::custom_config_value::operator[](
                  v16,
                  (int)config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"ui_texture1")->data;
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v19 = vostok::render::effect_compiler::begin_technique(v18, (int)c);
  v22 = vostok::render::effect_compiler::begin_pass(
          v20,
          v19,
          (char *)&stru_966240.configuration[1],
          0,
          (vostok::render::shader_configuration *)&stru_961088,
          &include_getter);
  if ( !v22->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v22->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      v22->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      v22->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v22->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v50 = v21;
  v23 = vostok::render::effect_compiler::set_stencil(
          v22,
          D3D11_STENCIL_OP_KEEP,
          0,
          0x20u,
          0,
          0xFFu,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          v21);
  v24 = vostok::render::effect_compiler::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          v23,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          v50);
  v25 = vostok::render::effect_compiler::set_cull_mode(v24, D3D11_CULL_NONE);
  v26 = vostok::render::effect_compiler::set_texture(
          0xFFFFFFFF,
          v25,
          &stru_963F84.m_name.m_string.m_buffer[116],
          v17,
          0,
          v52);
  v28 = vostok::render::effect_compiler::end_pass(
          v27,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v26);
  vostok::render::effect_compiler::end_technique(v29, (int)v28);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v30 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)&include_getter, (int)c);
  v33 = vostok::render::effect_compiler::begin_pass(
          v31,
          v30,
          (char *)&stru_966240.configuration[1],
          0,
          (vostok::render::shader_configuration *)&stru_96625C,
          &include_getter);
  if ( !v33->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v33->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      v33->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      v33->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v33->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v34 = vostok::render::effect_compiler::set_stencil(
          v33,
          D3D11_STENCIL_OP_KEEP,
          0,
          0x20u,
          0,
          0xFFu,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          v32);
  v35 = vostok::render::effect_compiler::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          v34,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          v53);
  v36 = vostok::render::effect_compiler::set_cull_mode(v35, D3D11_CULL_NONE);
  v38 = vostok::render::effect_compiler::end_pass(
          v37,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v36);
  vostok::render::effect_compiler::end_technique(v39, (int)v38);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v41 = vostok::render::effect_compiler::begin_technique(v40, (int)c);
  v43 = vostok::render::effect_compiler::begin_pass(
          v42,
          v41,
          (char *)&stru_966240.configuration[1],
          0,
          (vostok::render::shader_configuration *)&stru_96625C,
          &include_getter);
  if ( !v43->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v43->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
      v43->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      v43->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v43->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v44 = vostok::render::effect_compiler::set_stencil(
          v43,
          D3D11_STENCIL_OP_KEEP,
          0,
          0x20u,
          0,
          0xFFu,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          v54);
  v45 = vostok::render::effect_compiler::set_cull_mode(v44, D3D11_CULL_NONE);
  v47 = vostok::render::effect_compiler::end_pass(
          v46,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v45);
  vostok::render::effect_compiler::end_technique(v48, (int)v47);
}

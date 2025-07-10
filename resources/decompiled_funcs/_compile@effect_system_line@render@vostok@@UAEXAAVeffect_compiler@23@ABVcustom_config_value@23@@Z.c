void __thiscall vostok::render::effect_system_line::compile(
        vostok::render::effect_system_line *this,
        vostok::render::effect_compiler *c,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // eax
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // esi
  vostok::render::effect_compiler *v6; // eax
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::res_pass *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // eax
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // esi
  vostok::render::effect_compiler *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::res_pass *v16; // eax
  vostok::render::effect_compiler *v17; // ecx
  D3D11_STENCIL_OP v18; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v19; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v3 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)c);
  v5 = vostok::render::effect_compiler::begin_pass(
         v4,
         v3,
         (char *)&stru_966224,
         0,
         (vostok::render::shader_configuration *)&stru_966224,
         &include_getter);
  if ( !v5->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v5->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      v5->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
      v5->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v5->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v6 = vostok::render::effect_compiler::set_stencil(
         v5,
         D3D11_STENCIL_OP_KEEP,
         1,
         0x20u,
         0,
         0xFFu,
         D3D11_COMPARISON_ALWAYS,
         D3D11_STENCIL_OP_REPLACE,
         v18);
  v8 = vostok::render::effect_compiler::end_pass(
         v7,
         (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v6);
  vostok::render::effect_compiler::end_technique(v9, (int)v8);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v11 = vostok::render::effect_compiler::begin_technique(v10, (int)c);
  v13 = vostok::render::effect_compiler::begin_pass(
          v12,
          v11,
          (char *)&stru_966224.configuration[1] + 4,
          0,
          (vostok::render::shader_configuration *)&stru_966224,
          &include_getter);
  if ( !v13->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v13->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      v13->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
      v13->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_ALWAYS;
      v13->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v14 = vostok::render::effect_compiler::set_stencil(
          v13,
          D3D11_STENCIL_OP_KEEP,
          1,
          0x20u,
          0,
          0xFFu,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          v19);
  v16 = vostok::render::effect_compiler::end_pass(
          v15,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v14);
  vostok::render::effect_compiler::end_technique(v17, (int)v16);
}

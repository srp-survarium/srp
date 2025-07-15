void __thiscall vostok::render::effect_system_colored::compile(
        vostok::render::effect_system_colored *this,
        vostok::render::effect_compiler *c,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // eax
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // eax
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::res_pass *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // eax
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // esi
  vostok::render::res_pass *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // eax
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // eax
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // eax
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::res_pass *v23; // eax
  vostok::render::effect_compiler *v24; // ecx
  __int32 v25; // ecx
  vostok::render::effect_compiler *v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // eax
  vostok::render::effect_compiler *v29; // eax
  vostok::render::effect_compiler *v30; // eax
  vostok::render::effect_compiler *v31; // eax
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::res_pass *v33; // eax
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // eax
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // eax
  vostok::render::effect_compiler *v39; // eax
  vostok::render::effect_compiler *v40; // eax
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::res_pass *v42; // eax
  vostok::render::effect_compiler *v43; // ecx
  D3D11_BLEND_OP v44; // [esp-20h] [ebp-40h]
  bool v45; // [esp-10h] [ebp-30h]
  D3D11_BLEND_OP v46; // [esp+0h] [ebp-20h]
  bool v47; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v48; // [esp+0h] [ebp-20h]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-10h] BYREF

  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v3 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)c);
  v5 = vostok::render::effect_compiler::begin_pass(
         v4,
         v3,
         (char *)&stru_9555EC,
         0,
         (vostok::render::shader_configuration *)&stru_9555EC,
         &include_getter);
  v6 = vostok::render::effect_compiler::set_alpha_blend(
         D3D11_BLEND_INV_SRC_ALPHA,
         v5,
         1,
         D3D11_BLEND_SRC_ALPHA,
         D3D11_BLEND_OP_ADD,
         D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,
         v46);
  v8 = vostok::render::effect_compiler::end_pass(
         v7,
         (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v6);
  vostok::render::effect_compiler::end_technique(v9, (int)v8);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v10 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)&include_getter, (int)c);
  v13 = vostok::render::effect_compiler::begin_pass(
          v11,
          v10,
          (char *)&stru_9661C8.configuration[1] + 4,
          0,
          (vostok::render::shader_configuration *)&stru_9661C8,
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
  v14 = vostok::render::effect_compiler::end_pass(
          v12,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v13);
  vostok::render::effect_compiler::end_technique(v15, (int)v14);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v17 = vostok::render::effect_compiler::begin_technique(v16, (int)c);
  v19 = vostok::render::effect_compiler::begin_pass(
          v18,
          v17,
          (char *)&stru_9555EC,
          0,
          (vostok::render::shader_configuration *)&stru_9555EC,
          &include_getter);
  v21 = vostok::render::effect_compiler::color_write_enable(v20, (int)v19, (D3D11_COLOR_WRITE_ENABLE)0);
  v23 = vostok::render::effect_compiler::end_pass(
          v22,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v21);
  vostok::render::effect_compiler::end_technique(v24, (int)v23);
  v45 = v25;
  v44 = v25;
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v26 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)&include_getter, (int)c);
  v28 = vostok::render::effect_compiler::begin_pass(
          v27,
          v26,
          (char *)&stru_9661E0,
          0,
          (vostok::render::shader_configuration *)&stru_9661E0,
          &include_getter);
  v29 = vostok::render::effect_compiler::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          v28,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          v44);
  v30 = vostok::render::effect_compiler::set_texture(0xFFFFFFFF, v29, "t_position", "$user$position", 0, v45);
  v31 = vostok::render::effect_compiler::set_texture(
          0xFFFFFFFF,
          v30,
          "t_random_rotates",
          (char *)&stru_9661E0.configuration[1] + 4,
          0,
          v47);
  v33 = vostok::render::effect_compiler::end_pass(
          v32,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v31);
  vostok::render::effect_compiler::end_technique(v34, (int)v33);
  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v36 = vostok::render::effect_compiler::begin_technique(v35, (int)c);
  v38 = vostok::render::effect_compiler::begin_pass(
          v37,
          v36,
          (char *)&stru_9555EC,
          0,
          (vostok::render::shader_configuration *)&stru_966214,
          &include_getter);
  v39 = vostok::render::effect_compiler::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          v38,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ZERO,
          D3D11_BLEND_OP_ADD,
          v48);
  v40 = vostok::render::effect_compiler::set_fill_mode(v39, D3D11_FILL_WIREFRAME);
  v42 = vostok::render::effect_compiler::end_pass(
          v41,
          (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v40);
  vostok::render::effect_compiler::end_technique(v43, (int)v42);
}

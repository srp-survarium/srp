void __thiscall vostok::render::effect_system_colored::compile(
        vostok::render::effect_system_colored *this,
        vostok::render::effect_compiler *c,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // eax
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // eax
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // eax
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // eax
  vostok::render::effect_compiler *v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // eax
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // eax
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // eax
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // eax
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // eax
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // eax
  vostok::render::effect_compiler *v30; // eax
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // eax
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // eax
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // eax
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // eax
  vostok::render::effect_compiler *v42; // eax
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // eax
  vostok::command_line::key *v45; // ecx
  vostok::render::effect_compiler *v46; // eax
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // eax
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::effect_compiler *v50; // [esp-4Ch] [ebp-88h]
  vostok::render::shader_configuration v51; // [esp-40h] [ebp-7Ch]
  vostok::render::effect_compiler *v53; // [esp-1Ch] [ebp-58h]
  char *v54; // [esp-14h] [ebp-50h]
  vostok::render::shader_configuration v55; // [esp-10h] [ebp-4Ch]
  vostok::render::shader_configuration v56; // [esp-10h] [ebp-4Ch]
  vostok::render::effect_compiler *v57; // [esp-Ch] [ebp-48h]
  vostok::render::shader_configuration v58; // [esp+0h] [ebp-3Ch]
  vostok::render::shader_configuration v59; // [esp+4h] [ebp-38h]
  D3D11_BLEND_OP v60; // [esp+1Ch] [ebp-20h]
  D3D11_COMPARISON_FUNC v61; // [esp+1Ch] [ebp-20h]
  D3D11_BLEND_OP v62; // [esp+1Ch] [ebp-20h]

  *(_DWORD *)&v55.0 = "color";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 0x80000;
  v4 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)c);
  v5 = vostok::render::effect_compiler::begin_pass((vostok::render::effect_compiler *)this, (int)v4, "color", 0, v55, 0);
  v7 = vostok::render::effect_compiler::set_alpha_blend(
         v6,
         (int)v5,
         1,
         D3D11_BLEND_SRC_ALPHA,
         D3D11_BLEND_INV_SRC_ALPHA,
         D3D11_BLEND_OP_ADD,
         D3D11_BLEND_ONE,
         D3D11_BLEND_ZERO,
         v60);
  v9 = vostok::render::effect_compiler::end_pass(v8, (int)v7);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v9);
  *(_DWORD *)&v58.0 = "color_doted";
  *(unsigned __int64 *)((char *)v58.configuration + 4) = 0;
  v57 = v11;
  HIDWORD(v58.configuration[1]) = 0x80000;
  v12 = vostok::render::effect_compiler::begin_technique(v11, (int)c);
  v13 = vostok::render::effect_compiler::begin_pass(v57, (int)v12, "color_top", 0, v58, 0);
  v15 = vostok::render::effect_compiler::set_depth(v14, (int)v13, 1, 1, v61);
  v17 = vostok::render::effect_compiler::end_pass(v16, (int)v15);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v17);
  *(_DWORD *)&v59.0 = "color";
  *(unsigned __int64 *)((char *)v59.configuration + 4) = 0;
  HIDWORD(v59.configuration[1]) = 0x80000;
  v20 = vostok::render::effect_compiler::begin_technique(v19, (int)c);
  v22 = vostok::render::effect_compiler::begin_pass(v21, (int)v20, "color", 0, v59, 0);
  v24 = vostok::render::effect_compiler::color_write_enable(v23, (int)v22, (D3D11_COLOR_WRITE_ENABLE)0);
  v26 = vostok::render::effect_compiler::end_pass(v25, (int)v24);
  vostok::render::effect_compiler::end_technique(
    v27,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v26);
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 0x80000;
  *(_DWORD *)&v51.0 = "color_cover";
  v50 = v28;
  v29 = vostok::render::effect_compiler::begin_technique(v28, (int)c);
  v30 = vostok::render::effect_compiler::begin_pass(v50, (int)v29, "color_cover", 0, v51, 0);
  v32 = vostok::render::effect_compiler::set_alpha_blend(
          v31,
          (int)v30,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_ZERO,
          (D3D11_BLEND_OP)"t_position");
  v34 = vostok::render::effect_compiler::set_texture(
          v33,
          (const char *)v32,
          v54,
          "$user$position",
          0,
          0xFFFFFFFF,
          0,
          1.0);
  v36 = vostok::render::effect_compiler::set_texture(
          v35,
          (const char *)v34,
          "t_random_rotates",
          "engine/ssao_rotate",
          0,
          0xFFFFFFFF,
          0,
          1.0);
  v38 = vostok::render::effect_compiler::end_pass(v37, (int)v36);
  vostok::render::effect_compiler::end_technique(
    v39,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v38);
  *(_DWORD *)&v56.0 = "color_wireframe";
  *(unsigned __int64 *)((char *)v56.configuration + 4) = 0;
  HIDWORD(v56.configuration[1]) = 0x80000;
  v53 = v40;
  v41 = vostok::render::effect_compiler::begin_technique(v40, (int)c);
  v42 = vostok::render::effect_compiler::begin_pass(v53, (int)v41, "color", 0, v56, 0);
  v44 = vostok::render::effect_compiler::set_alpha_blend(
          v43,
          (int)v42,
          1,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_ZERO,
          v62);
  v46 = vostok::render::effect_compiler::set_fill_mode(
          v44,
          (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
          v45);
  v48 = vostok::render::effect_compiler::end_pass(v47, (int)v46);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v48);
}

void __thiscall vostok::render::effect_system_ui::compile(
        vostok::render::effect_system_ui *this,
        vostok::render::effect_compiler *c,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // eax
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // eax
  vostok::render::effect_compiler *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // eax
  vostok::command_line::key *v11; // ecx
  vostok::render::effect_compiler *v12; // eax
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // eax
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // eax
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // eax
  vostok::render::effect_compiler *v20; // eax
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // eax
  vostok::render::effect_compiler *v23; // eax
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // eax
  vostok::command_line::key *v26; // ecx
  vostok::render::effect_compiler *v27; // eax
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // eax
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // eax
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // eax
  vostok::render::effect_compiler *v35; // eax
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // eax
  vostok::render::effect_compiler *v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // eax
  vostok::command_line::key *v41; // ecx
  vostok::render::effect_compiler *v42; // eax
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // eax
  vostok::render::effect_compiler *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::effect_compiler *v47; // eax
  vostok::render::effect_compiler *v48; // eax
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::effect_compiler *v50; // eax
  vostok::render::effect_compiler *v51; // eax
  vostok::command_line::key *v52; // ecx
  vostok::render::effect_compiler *v53; // eax
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // eax
  vostok::render::effect_compiler *v56; // ecx
  vostok::render::effect_compiler *v58; // [esp-74h] [ebp-98h]
  vostok::render::shader_configuration v59; // [esp-68h] [ebp-8Ch]
  vostok::render::shader_configuration v60; // [esp-68h] [ebp-8Ch]
  vostok::render::effect_compiler *v61; // [esp-5Ch] [ebp-80h]
  vostok::render::shader_configuration v62; // [esp-50h] [ebp-74h]
  vostok::render::effect_compiler *v64; // [esp-4Ch] [ebp-70h]
  D3D11_COMPARISON_FUNC v65; // [esp-4Ch] [ebp-70h]
  vostok::render::effect_compiler *v66; // [esp-4Ch] [ebp-70h]
  vostok::render::effect_compiler *v67; // [esp-44h] [ebp-68h]
  vostok::render::shader_configuration v68; // [esp-38h] [ebp-5Ch]
  D3D11_COMPARISON_FUNC v69; // [esp-34h] [ebp-58h]
  vostok::render::effect_compiler *v70; // [esp-34h] [ebp-58h]
  int v71; // [esp-2Ch] [ebp-50h]
  int v72; // [esp-2Ch] [ebp-50h]
  D3D11_COMPARISON_FUNC v73; // [esp-1Ch] [ebp-40h]
  vostok::render::effect_compiler *v74; // [esp-1Ch] [ebp-40h]
  char *v75; // [esp-14h] [ebp-38h]
  char *v76; // [esp-14h] [ebp-38h]
  int v77; // [esp-14h] [ebp-38h]
  D3D11_BLEND_OP v78; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v79; // [esp+4h] [ebp-20h]

  *(_DWORD *)&v59.0 = "ui_font";
  *(unsigned __int64 *)((char *)v59.configuration + 4) = 0;
  HIDWORD(v59.configuration[1]) = 0x80000;
  v4 = vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)c);
  v5 = vostok::render::effect_compiler::begin_pass(
         (vostok::render::effect_compiler *)this,
         (int)v4,
         "stub_notransform_t",
         0,
         v59,
         0);
  v7 = vostok::render::effect_compiler::set_depth(v6, (int)v5, 0, 0, (D3D11_COMPARISON_FUNC)this);
  v8 = vostok::render::effect_compiler::set_stencil(
         v64,
         (int)v7,
         0,
         0x20u,
         0,
         255,
         D3D11_COMPARISON_ALWAYS,
         D3D11_STENCIL_OP_REPLACE,
         D3D11_STENCIL_OP_KEEP,
         D3D11_STENCIL_OP_KEEP);
  v10 = vostok::render::effect_compiler::set_alpha_blend(
          v9,
          (int)v8,
          v71,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_ZERO,
          (D3D11_BLEND_OP)"t_base");
  v12 = vostok::render::effect_compiler::set_cull_mode(
          v10,
          (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
          v11);
  v14 = vostok::render::effect_compiler::set_texture(
          v13,
          (const char *)v12,
          v75,
          "ui/ui_font_arial_21_1024",
          0,
          0xFFFFFFFF,
          0,
          1.0);
  v16 = vostok::render::effect_compiler::end_pass(v15, (int)v14);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v16);
  v65 = (D3D11_COMPARISON_FUNC)v18;
  *(_DWORD *)&v60.0 = "ui";
  *(unsigned __int64 *)((char *)v60.configuration + 4) = 0;
  v58 = v18;
  HIDWORD(v60.configuration[1]) = 0x80000;
  v19 = vostok::render::effect_compiler::begin_technique(v18, (int)c);
  v20 = vostok::render::effect_compiler::begin_pass(v58, (int)v19, "stub_notransform_t", 0, v60, 0);
  v22 = vostok::render::effect_compiler::set_depth(v21, (int)v20, 0, 0, v65);
  v23 = vostok::render::effect_compiler::set_stencil(
          v66,
          (int)v22,
          0,
          0x20u,
          0,
          255,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          D3D11_STENCIL_OP_KEEP,
          D3D11_STENCIL_OP_KEEP);
  v25 = vostok::render::effect_compiler::set_alpha_blend(
          v24,
          (int)v23,
          v72,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_ZERO,
          (D3D11_BLEND_OP)"t_base");
  v27 = vostok::render::effect_compiler::set_cull_mode(
          v25,
          (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
          v26);
  v29 = vostok::render::effect_compiler::set_texture(v28, (const char *)v27, v76, "ui/ui_skull", 0, 0xFFFFFFFF, 0, 1.0);
  v31 = vostok::render::effect_compiler::end_pass(v30, (int)v29);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v31);
  v69 = (D3D11_COMPARISON_FUNC)v33;
  *(_DWORD *)&v62.0 = "ui_fill";
  *(unsigned __int64 *)((char *)v62.configuration + 4) = 0;
  HIDWORD(v62.configuration[1]) = 0x80000;
  v61 = v33;
  v34 = vostok::render::effect_compiler::begin_technique(v33, (int)c);
  v35 = vostok::render::effect_compiler::begin_pass(v61, (int)v34, "stub_notransform_t", 0, v62, 0);
  v37 = vostok::render::effect_compiler::set_depth(v36, (int)v35, 0, 0, v69);
  v38 = vostok::render::effect_compiler::set_stencil(
          v70,
          (int)v37,
          0,
          0x20u,
          0,
          255,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          D3D11_STENCIL_OP_KEEP,
          D3D11_STENCIL_OP_KEEP);
  v40 = vostok::render::effect_compiler::set_alpha_blend(
          v39,
          (int)v38,
          v77,
          D3D11_BLEND_SRC_ALPHA,
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_ZERO,
          v78);
  v42 = vostok::render::effect_compiler::set_cull_mode(
          v40,
          (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
          v41);
  v44 = vostok::render::effect_compiler::end_pass(v43, (int)v42);
  vostok::render::effect_compiler::end_technique(
    v45,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v44);
  v73 = (D3D11_COMPARISON_FUNC)v46;
  *(_DWORD *)&v68.0 = "ui_fill";
  *(unsigned __int64 *)((char *)v68.configuration + 4) = 0;
  v67 = v46;
  HIDWORD(v68.configuration[1]) = 0x80000;
  v47 = vostok::render::effect_compiler::begin_technique(v46, (int)c);
  v48 = vostok::render::effect_compiler::begin_pass(v67, (int)v47, "stub_notransform_t", 0, v68, 0);
  v50 = vostok::render::effect_compiler::set_depth(v49, (int)v48, 0, 0, v73);
  v51 = vostok::render::effect_compiler::set_stencil(
          v74,
          (int)v50,
          0,
          0x20u,
          0,
          255,
          D3D11_COMPARISON_ALWAYS,
          D3D11_STENCIL_OP_REPLACE,
          D3D11_STENCIL_OP_KEEP,
          v79);
  v53 = vostok::render::effect_compiler::set_cull_mode(
          v51,
          (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
          v52);
  v55 = vostok::render::effect_compiler::end_pass(v54, (int)v53);
  vostok::render::effect_compiler::end_technique(
    v56,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v55);
}

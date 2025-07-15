void __thiscall vostok::render::effect_blur<3>::compile(
        vostok::render::effect_blur<3> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524291;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524291;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<5>::compile(
        vostok::render::effect_blur<5> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524293;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524293;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<7>::compile(
        vostok::render::effect_blur<7> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524295;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524295;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<9>::compile(
        vostok::render::effect_blur<9> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524297;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524297;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<17>::compile(
        vostok::render::effect_blur<17> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524305;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524305;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<21>::compile(
        vostok::render::effect_blur<21> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524309;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524309;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<25>::compile(
        vostok::render::effect_blur<25> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524313;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524313;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_blur<13>::compile(
        vostok::render::effect_blur<13> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::command_line::key *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::command_line::key *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::command_line::key *v30; // ecx
  vostok::command_line::key *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::command_line::key *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::command_line::key *v45; // ecx
  vostok::command_line::key *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::shader_configuration v50; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v51; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v52; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v53; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v56; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v57; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v58; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v60; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v61; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v63; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v64; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+0h] [ebp-20h]
  D3D11_BLEND_OP v66; // [esp+0h] [ebp-20h]
  __int64 v67; // [esp+18h] [ebp-8h]

  v67 = 524301;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v50.0 = "blur_horizontally";
  *(unsigned __int64 *)((char *)v50.configuration + 4) = 0;
  HIDWORD(v50.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur", 0, v50, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v56);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v57);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v51.0 = "blur_vertically";
  *(unsigned __int64 *)((char *)v51.configuration + 4) = 0;
  HIDWORD(v51.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "blur", 0, v51, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v58);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v14);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v15);
  vostok::render::effect_compiler::set_alpha_blend(
    v16,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v52.0 = "blur_accumulate";
  *(unsigned __int64 *)((char *)v52.configuration + 4) = 0;
  HIDWORD(v52.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "blur", 0, v52, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v60);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v23);
  vostok::render::effect_compiler::set_alpha_blend(
    v24,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v61);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v27, (int)compiler);
  *(_DWORD *)&v53.0 = "blur_downsample";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v28, (int)compiler, "blur", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v29, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v30);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v31);
  vostok::render::effect_compiler::end_pass(v32, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v33,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v34, (int)compiler);
  *(_DWORD *)&v54.0 = "blur_add_first";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v35, (int)compiler, "blur", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v63);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v37);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v38);
  vostok::render::effect_compiler::set_alpha_blend(
    v39,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v64);
  vostok::render::effect_compiler::end_pass(v40, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v41,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v42, (int)compiler);
  *(_DWORD *)&v55.0 = "blur_add";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 524301;
  vostok::render::effect_compiler::begin_pass(v43, (int)compiler, "blur", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v45);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v46);
  vostok::render::effect_compiler::set_alpha_blend(
    v47,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v66);
  vostok::render::effect_compiler::end_pass(v48, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v49,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

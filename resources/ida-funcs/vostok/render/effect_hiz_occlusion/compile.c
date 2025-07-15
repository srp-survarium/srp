void __thiscall vostok::render::effect_hiz_occlusion::compile(
        vostok::render::effect_hiz_occlusion *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::command_line::key *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::command_line::key *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::command_line::key *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::command_line::key *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::command_line::key *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
  vostok::command_line::key *v44; // ecx
  vostok::render::effect_compiler *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::command_line::key *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::render::shader_configuration v53; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v56; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v57; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v58; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v59; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v60; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v61; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v62; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v63; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v64; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v65; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v66; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v67; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v68; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v69; // [esp+4h] [ebp-20h]
  __int64 v70; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v53.0 = "hiz_debug_color";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "dumb", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 1, v61);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&v54.0 = "hiz_debug_color";
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  HIDWORD(v54.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "dumb", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v11, (int)compiler, 0, 0, v62);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v12);
  vostok::render::effect_compiler::set_alpha_blend(
    v13,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v63);
  vostok::render::effect_compiler::end_pass(v14, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v16, (int)compiler);
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 0x80000;
  *(_DWORD *)&v55.0 = "hiz_copy_scene_depth";
  vostok::render::effect_compiler::begin_pass(v17, (int)compiler, "hiz_copy_scene_depth", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 0, 0, v64);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v19);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v23, (int)compiler);
  *(unsigned __int64 *)((char *)v56.configuration + 4) = 0;
  HIDWORD(v56.configuration[1]) = 0x80000;
  *(_DWORD *)&v56.0 = "hiz_depth";
  vostok::render::effect_compiler::begin_pass(v24, (int)compiler, "hiz_depth", 0, v56, 0);
  vostok::render::effect_compiler::set_depth(v25, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v26);
  vostok::render::effect_compiler::end_pass(v27, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v28,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v29, (int)compiler);
  *(unsigned __int64 *)((char *)v57.configuration + 4) = 0;
  HIDWORD(v57.configuration[1]) = 0x80000;
  *(_DWORD *)&v57.0 = "hiz_downsample_depth";
  vostok::render::effect_compiler::begin_pass(v30, (int)compiler, "hiz_downsample_depth", 0, v57, 0);
  vostok::render::effect_compiler::set_depth(v31, (int)compiler, 0, 0, v66);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v32);
  vostok::render::effect_compiler::end_pass(v33, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v34,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v35, (int)compiler);
  *(unsigned __int64 *)((char *)v58.configuration + 4) = 0;
  HIDWORD(v58.configuration[1]) = 0x80000;
  *(_DWORD *)&v58.0 = "hiz_merge_mip";
  vostok::render::effect_compiler::begin_pass(v36, (int)compiler, "hiz_merge_mip", 0, v58, 0);
  vostok::render::effect_compiler::set_depth(v37, (int)compiler, 0, 0, v67);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v38);
  vostok::render::effect_compiler::end_pass(v39, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v40,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v41, (int)compiler);
  *(unsigned __int64 *)((char *)v59.configuration + 4) = 0;
  HIDWORD(v59.configuration[1]) = 0x80000;
  *(_DWORD *)&v59.0 = "hiz_fill_culling_results_buffer";
  vostok::render::effect_compiler::begin_pass(v42, (int)compiler, "hiz_fill_culling_results_buffer", 0, v59, 0);
  vostok::render::effect_compiler::set_depth(v43, (int)compiler, 0, 0, v68);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v44);
  vostok::render::effect_compiler::end_pass(v45, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v46,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v47, (int)compiler);
  *(_DWORD *)&v60.0 = "hiz_copy_to_lockable_rt";
  v70 = 0x80000;
  *(unsigned __int64 *)((char *)v60.configuration + 4) = 0;
  HIDWORD(v60.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v48, (int)compiler, "hiz_copy_scene_depth", 0, v60, 0);
  vostok::render::effect_compiler::set_depth(v49, (int)compiler, 0, 0, v69);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v50);
  vostok::render::effect_compiler::end_pass(v51, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v52,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

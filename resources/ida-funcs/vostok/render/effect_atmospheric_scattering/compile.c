void __thiscall vostok::render::effect_atmospheric_scattering<1>::compile(
        vostok::render::effect_atmospheric_scattering<1> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
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
  vostok::render::effect_compiler *v26; // ecx
  vostok::command_line::key *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::command_line::key *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::command_line::key *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::render::effect_compiler *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::effect_compiler *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::render::effect_compiler *v53; // ecx
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // ecx
  vostok::command_line::key *v56; // ecx
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::effect_compiler *v58; // ecx
  vostok::render::effect_compiler *v59; // ecx
  vostok::render::effect_compiler *v60; // ecx
  vostok::render::effect_compiler *v61; // ecx
  vostok::render::effect_compiler *v62; // ecx
  vostok::render::effect_compiler *v63; // ecx
  vostok::render::effect_compiler *v64; // ecx
  vostok::render::effect_compiler *v65; // ecx
  vostok::render::effect_compiler *v66; // ecx
  vostok::command_line::key *v67; // ecx
  vostok::render::effect_compiler *v68; // ecx
  vostok::render::effect_compiler *v69; // ecx
  vostok::render::effect_compiler *v70; // ecx
  vostok::render::effect_compiler *v71; // ecx
  vostok::render::effect_compiler *v72; // ecx
  vostok::render::effect_compiler *v73; // ecx
  vostok::render::effect_compiler *v74; // ecx
  vostok::render::effect_compiler *v75; // ecx
  vostok::command_line::key *v76; // ecx
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::shader_configuration v80; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v81; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v82; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v83; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v84; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v85; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v86; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v87; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v88; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v89; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v90; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v91; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v92; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v93; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v94; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v95; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v96; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v97; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v98; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v99; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v100; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v101; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v102; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v103; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v104; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v105; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v106; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v107; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v108; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v109; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v110; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v111; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v112; // [esp+4h] [ebp-20h]
  __int64 v113; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v80.configuration + 4) = 0;
  HIDWORD(v80.configuration[1]) = 0x80000;
  *(_DWORD *)&v80.0 = "make_mie_rayleigh_texture";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "make_mie_rayleigh_texture", 0, v80, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v89);
  vostok::render::effect_compiler::end_pass(v6, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  *(unsigned __int64 *)((char *)v81.configuration + 4) = 0;
  HIDWORD(v81.configuration[1]) = 0x80000;
  *(_DWORD *)&v81.0 = "atmosphere";
  vostok::render::effect_compiler::begin_pass(v9, (int)compiler, "atmosphere", 0, v81, 0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v12);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v90);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v91);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(unsigned __int64 *)((char *)v82.configuration + 4) = 0x800000;
  HIDWORD(v82.configuration[1]) = 0x80000;
  *(_DWORD *)&v82.0 = "atmosphere_clouds";
  vostok::render::effect_compiler::begin_pass(v18, (int)compiler, "atmosphere_clouds", 0, v82, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v19);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v92);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v93);
  vostok::render::effect_compiler::set_stencil(
    v22,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v94);
  vostok::render::effect_compiler::end_pass(v23, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v24,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v25, (int)compiler);
  *(unsigned __int64 *)((char *)v83.configuration + 4) = 8912896;
  HIDWORD(v83.configuration[1]) = 0x80000;
  *(_DWORD *)&v83.0 = "atmosphere_clouds";
  vostok::render::effect_compiler::begin_pass(v26, (int)compiler, "atmosphere_clouds", 0, v83, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v27);
  vostok::render::effect_compiler::set_depth(v28, (int)compiler, 0, 0, v95);
  vostok::render::effect_compiler::set_alpha_blend(
    v29,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v96);
  vostok::render::effect_compiler::set_stencil(
    v30,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v97);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v33, (int)compiler);
  *(unsigned __int64 *)((char *)v84.configuration + 4) = 0;
  HIDWORD(v84.configuration[1]) = 0x80000;
  *(_DWORD *)&v84.0 = "atmosphere_sun_moon";
  vostok::render::effect_compiler::begin_pass(v34, (int)compiler, "atmosphere_sun_moon", 0, v84, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v35);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v98);
  vostok::render::effect_compiler::set_alpha_blend(
    v37,
    (int)compiler,
    1,
    D3D11_BLEND_INV_DEST_ALPHA,
    D3D11_BLEND_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v99);
  vostok::render::effect_compiler::set_stencil(
    v38,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v100);
  vostok::render::effect_compiler::end_pass(v39, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v40,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v41, (int)compiler);
  *(unsigned __int64 *)((char *)v85.configuration + 4) = 0;
  HIDWORD(v85.configuration[1]) = 0x80000;
  *(_DWORD *)&v85.0 = "atmosphere_sun_moon";
  vostok::render::effect_compiler::begin_pass(v42, (int)compiler, "atmosphere_sun_moon", 0, v85, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v43);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v101);
  vostok::render::effect_compiler::set_alpha_blend(
    v45,
    (int)compiler,
    1,
    D3D11_BLEND_DEST_ALPHA,
    D3D11_BLEND_INV_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v102);
  vostok::render::effect_compiler::set_stencil(
    v46,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v103);
  vostok::render::effect_compiler::end_pass(v47, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v48,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v49, (int)compiler);
  *(_DWORD *)&v86.0 = "atmospheric_scattering_on_geometry_mul";
  *(unsigned __int64 *)((char *)v86.configuration + 4) = 0;
  HIDWORD(v86.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v50, (int)compiler, "atmospheric_scattering_on_geometry", 0, v86, 0);
  vostok::render::effect_compiler::set_stencil(
    v51,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v104);
  vostok::render::effect_compiler::set_texture(
    v52,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v53,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v54,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v55,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v105);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v56);
  vostok::render::effect_compiler::set_depth(v57, (int)compiler, 0, 0, v106);
  vostok::render::effect_compiler::end_pass(v58, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v59,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v60, (int)compiler);
  *(_DWORD *)&v87.0 = "atmospheric_scattering_on_geometry_add";
  *(unsigned __int64 *)((char *)v87.configuration + 4) = 0;
  HIDWORD(v87.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v61, (int)compiler, "atmospheric_scattering_on_geometry", 0, v87, 0);
  vostok::render::effect_compiler::set_stencil(
    v62,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v107);
  vostok::render::effect_compiler::set_texture(
    v63,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v64,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v65,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v66,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v108);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v67);
  vostok::render::effect_compiler::set_depth(v68, (int)compiler, 0, 0, v109);
  vostok::render::effect_compiler::end_pass(v69, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v70,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v71, (int)compiler);
  *(_DWORD *)&v88.0 = "atmospheric_scattering_on_geometry_temporary";
  v113 = 0x80000;
  *(unsigned __int64 *)((char *)v88.configuration + 4) = 0;
  HIDWORD(v88.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v72, (int)compiler, "atmospheric_scattering_on_geometry", 0, v88, 0);
  vostok::render::effect_compiler::set_stencil(
    v73,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v110);
  vostok::render::effect_compiler::set_texture(
    v74,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v75,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v111);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v76);
  vostok::render::effect_compiler::set_depth(v77, (int)compiler, 0, 0, v112);
  vostok::render::effect_compiler::end_pass(v78, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v79,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_atmospheric_scattering<0>::compile(
        vostok::render::effect_atmospheric_scattering<0> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
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
  vostok::render::effect_compiler *v26; // ecx
  vostok::command_line::key *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::effect_compiler *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::command_line::key *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::command_line::key *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::render::effect_compiler *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::render::effect_compiler *v47; // ecx
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_compiler *v49; // ecx
  vostok::render::effect_compiler *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::render::effect_compiler *v53; // ecx
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // ecx
  vostok::command_line::key *v56; // ecx
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::effect_compiler *v58; // ecx
  vostok::render::effect_compiler *v59; // ecx
  vostok::render::effect_compiler *v60; // ecx
  vostok::render::effect_compiler *v61; // ecx
  vostok::render::effect_compiler *v62; // ecx
  vostok::render::effect_compiler *v63; // ecx
  vostok::render::effect_compiler *v64; // ecx
  vostok::render::effect_compiler *v65; // ecx
  vostok::render::effect_compiler *v66; // ecx
  vostok::command_line::key *v67; // ecx
  vostok::render::effect_compiler *v68; // ecx
  vostok::render::effect_compiler *v69; // ecx
  vostok::render::effect_compiler *v70; // ecx
  vostok::render::effect_compiler *v71; // ecx
  vostok::render::effect_compiler *v72; // ecx
  vostok::render::effect_compiler *v73; // ecx
  vostok::render::effect_compiler *v74; // ecx
  vostok::render::effect_compiler *v75; // ecx
  vostok::command_line::key *v76; // ecx
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::shader_configuration v80; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v81; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v82; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v83; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v84; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v85; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v86; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v87; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v88; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v89; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v90; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v91; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v92; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v93; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v94; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v95; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v96; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v97; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v98; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v99; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v100; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v101; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v102; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v103; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v104; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v105; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v106; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v107; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v108; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v109; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v110; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v111; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v112; // [esp+4h] [ebp-20h]
  __int64 v113; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v80.configuration + 4) = 0;
  HIDWORD(v80.configuration[1]) = 0x80000;
  *(_DWORD *)&v80.0 = "make_mie_rayleigh_texture";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "make_mie_rayleigh_texture", 0, v80, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v89);
  vostok::render::effect_compiler::end_pass(v6, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  *(unsigned __int64 *)((char *)v81.configuration + 4) = 0;
  HIDWORD(v81.configuration[1]) = 0x80000;
  *(_DWORD *)&v81.0 = "atmosphere";
  vostok::render::effect_compiler::begin_pass(v9, (int)compiler, "atmosphere", 0, v81, 0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v12);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v90);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v91);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(unsigned __int64 *)((char *)v82.configuration + 4) = 0;
  HIDWORD(v82.configuration[1]) = 0x80000;
  *(_DWORD *)&v82.0 = "atmosphere_clouds";
  vostok::render::effect_compiler::begin_pass(v18, (int)compiler, "atmosphere_clouds", 0, v82, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v19);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v92);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v93);
  vostok::render::effect_compiler::set_stencil(
    v22,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v94);
  vostok::render::effect_compiler::end_pass(v23, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v24,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v25, (int)compiler);
  *(unsigned __int64 *)((char *)v83.configuration + 4) = 0x80000;
  HIDWORD(v83.configuration[1]) = 0x80000;
  *(_DWORD *)&v83.0 = "atmosphere_clouds";
  vostok::render::effect_compiler::begin_pass(v26, (int)compiler, "atmosphere_clouds", 0, v83, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v27);
  vostok::render::effect_compiler::set_depth(v28, (int)compiler, 0, 0, v95);
  vostok::render::effect_compiler::set_alpha_blend(
    v29,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v96);
  vostok::render::effect_compiler::set_stencil(
    v30,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v97);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v33, (int)compiler);
  *(unsigned __int64 *)((char *)v84.configuration + 4) = 0;
  HIDWORD(v84.configuration[1]) = 0x80000;
  *(_DWORD *)&v84.0 = "atmosphere_sun_moon";
  vostok::render::effect_compiler::begin_pass(v34, (int)compiler, "atmosphere_sun_moon", 0, v84, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v35);
  vostok::render::effect_compiler::set_depth(v36, (int)compiler, 0, 0, v98);
  vostok::render::effect_compiler::set_alpha_blend(
    v37,
    (int)compiler,
    1,
    D3D11_BLEND_INV_DEST_ALPHA,
    D3D11_BLEND_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v99);
  vostok::render::effect_compiler::set_stencil(
    v38,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v100);
  vostok::render::effect_compiler::end_pass(v39, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v40,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v41, (int)compiler);
  *(unsigned __int64 *)((char *)v85.configuration + 4) = 0;
  HIDWORD(v85.configuration[1]) = 0x80000;
  *(_DWORD *)&v85.0 = "atmosphere_sun_moon";
  vostok::render::effect_compiler::begin_pass(v42, (int)compiler, "atmosphere_sun_moon", 0, v85, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v43);
  vostok::render::effect_compiler::set_depth(v44, (int)compiler, 0, 0, v101);
  vostok::render::effect_compiler::set_alpha_blend(
    v45,
    (int)compiler,
    1,
    D3D11_BLEND_DEST_ALPHA,
    D3D11_BLEND_INV_DEST_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v102);
  vostok::render::effect_compiler::set_stencil(
    v46,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v103);
  vostok::render::effect_compiler::end_pass(v47, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v48,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v49, (int)compiler);
  *(_DWORD *)&v86.0 = "atmospheric_scattering_on_geometry_mul";
  *(unsigned __int64 *)((char *)v86.configuration + 4) = 0;
  HIDWORD(v86.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v50, (int)compiler, "atmospheric_scattering_on_geometry", 0, v86, 0);
  vostok::render::effect_compiler::set_stencil(
    v51,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v104);
  vostok::render::effect_compiler::set_texture(
    v52,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v53,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v54,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v55,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v105);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v56);
  vostok::render::effect_compiler::set_depth(v57, (int)compiler, 0, 0, v106);
  vostok::render::effect_compiler::end_pass(v58, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v59,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v60, (int)compiler);
  *(_DWORD *)&v87.0 = "atmospheric_scattering_on_geometry_add";
  *(unsigned __int64 *)((char *)v87.configuration + 4) = 0;
  HIDWORD(v87.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v61, (int)compiler, "atmospheric_scattering_on_geometry", 0, v87, 0);
  vostok::render::effect_compiler::set_stencil(
    v62,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v107);
  vostok::render::effect_compiler::set_texture(
    v63,
    (const char *)compiler,
    "t_mie_scattering",
    "$user$mie_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v64,
    (const char *)compiler,
    "t_rayleigh_scattering",
    "$user$rayleigh_scattering",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v65,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v66,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v108);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v67);
  vostok::render::effect_compiler::set_depth(v68, (int)compiler, 0, 0, v109);
  vostok::render::effect_compiler::end_pass(v69, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v70,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v71, (int)compiler);
  *(_DWORD *)&v88.0 = "atmospheric_scattering_on_geometry_temporary";
  v113 = 0x80000;
  *(unsigned __int64 *)((char *)v88.configuration + 4) = 0;
  HIDWORD(v88.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v72, (int)compiler, "atmospheric_scattering_on_geometry", 0, v88, 0);
  vostok::render::effect_compiler::set_stencil(
    v73,
    (int)compiler,
    1,
    0,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v110);
  vostok::render::effect_compiler::set_texture(
    v74,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v75,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v111);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v76);
  vostok::render::effect_compiler::set_depth(v77, (int)compiler, 0, 0, v112);
  vostok::render::effect_compiler::end_pass(v78, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v79,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

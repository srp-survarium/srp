void __thiscall vostok::render::point_light_effect<1,0>::compile(
        vostok::render::point_light_effect<1,0> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
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
  vostok::command_line::key *v22; // ecx
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
  vostok::command_line::key *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
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
  vostok::render::effect_compiler *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::command_line::key *v53; // ecx
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // ecx
  vostok::render::effect_compiler *v56; // ecx
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
  vostok::render::effect_compiler *v76; // ecx
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::effect_compiler *v80; // ecx
  vostok::command_line::key *v81; // ecx
  vostok::render::effect_compiler *v82; // ecx
  vostok::render::effect_compiler *v83; // ecx
  vostok::render::effect_compiler *v84; // ecx
  vostok::render::effect_compiler *v85; // ecx
  vostok::render::effect_compiler *v86; // ecx
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::effect_compiler *v88; // ecx
  vostok::render::effect_compiler *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::render::effect_compiler *v91; // ecx
  vostok::render::effect_compiler *v92; // ecx
  vostok::render::effect_compiler *v93; // ecx
  vostok::render::effect_compiler *v94; // ecx
  vostok::command_line::key *v95; // ecx
  vostok::render::effect_compiler *v96; // ecx
  vostok::render::effect_compiler *v97; // ecx
  vostok::render::effect_compiler *v98; // ecx
  vostok::render::effect_compiler *v99; // ecx
  vostok::render::effect_compiler *v100; // ecx
  vostok::render::effect_compiler *v101; // ecx
  vostok::render::effect_compiler *v102; // ecx
  vostok::render::effect_compiler *v103; // ecx
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_compiler *v105; // ecx
  vostok::render::effect_compiler *v106; // ecx
  vostok::render::effect_compiler *v107; // ecx
  vostok::render::effect_compiler *v108; // ecx
  vostok::command_line::key *v109; // ecx
  vostok::render::effect_compiler *v110; // ecx
  vostok::render::effect_compiler *v111; // ecx
  vostok::render::effect_compiler *v112; // ecx
  vostok::render::effect_compiler *v113; // ecx
  vostok::render::effect_compiler *v114; // ecx
  vostok::render::effect_compiler *v115; // ecx
  vostok::render::effect_compiler *v116; // ecx
  vostok::render::effect_compiler *v117; // ecx
  vostok::render::shader_configuration v118; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v119; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v120; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v121; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v122; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v123; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v124; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v125; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v126; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v127; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v128; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v129; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v130; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v131; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v132; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v133; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v134; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v135; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v136; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v137; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v138; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v139; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v140; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v141; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v142; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v143; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v144; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v145; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v146; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v147; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v148; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v149; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v150; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v151; // [esp+4h] [ebp-20h]
  __int64 v152; // [esp+1Ch] [ebp-8h]

  v152 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v118.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v118.configuration + 4) = 0x400000000LL;
  HIDWORD(v118.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v118, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v127);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v128);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v129);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(_DWORD *)&v119.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v119.configuration + 4) = 0x400000000LL;
  HIDWORD(v119.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v18, (int)compiler, "light", 0, v119, 0);
  vostok::render::effect_compiler::set_depth(v19, (int)compiler, 0, 0, v130);
  vostok::render::effect_compiler::set_stencil(
    v20,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v131);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v132);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v22);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v30, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v31,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v32, (int)compiler);
  *(_DWORD *)&v120.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v120.configuration + 4) = 0x400000000LL;
  HIDWORD(v120.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v33, (int)compiler, "light", 0, v120, 0);
  vostok::render::effect_compiler::set_depth(v34, (int)compiler, 1, 0, v133);
  vostok::render::effect_compiler::set_stencil(
    v35,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v134);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v36);
  vostok::render::effect_compiler::color_write_enable(v37, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v38, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v39,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v40, (int)compiler);
  *(unsigned __int64 *)((char *)v121.configuration + 4) = 0x400000000LL;
  HIDWORD(v121.configuration[1]) = 0x80000;
  *(_DWORD *)&v121.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v41, (int)compiler, "instance_test", 0, v121, 0);
  vostok::render::effect_compiler::set_depth(v42, (int)compiler, 1, 0, v135);
  vostok::render::effect_compiler::set_stencil(
    v43,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v136);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v44);
  vostok::render::effect_compiler::color_write_enable(v45, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v46, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v47,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v48, (int)compiler);
  *(unsigned __int64 *)((char *)v122.configuration + 4) = 0x400000000LL;
  HIDWORD(v122.configuration[1]) = 0x80000;
  *(_DWORD *)&v122.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v49, (int)compiler, "instance_test", 0, v122, 0);
  vostok::render::effect_compiler::set_depth(v50, (int)compiler, 1, 0, v137);
  vostok::render::effect_compiler::set_alpha_blend(
    v51,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v138);
  vostok::render::effect_compiler::set_stencil(
    v52,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v139);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v53);
  vostok::render::effect_compiler::set_texture(
    v54,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v55,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v56,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v57,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v58,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v59,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v60, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v61,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v62, (int)compiler);
  *(unsigned __int64 *)((char *)v123.configuration + 4) = 0x400000000LL;
  HIDWORD(v123.configuration[1]) = 0x80000;
  *(_DWORD *)&v123.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v63, (int)compiler, "instance_test", 0, v123, 0);
  vostok::render::effect_compiler::set_depth(v64, (int)compiler, 0, 0, v140);
  vostok::render::effect_compiler::set_stencil(
    v65,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v141);
  vostok::render::effect_compiler::set_alpha_blend(
    v66,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v142);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v67);
  vostok::render::effect_compiler::set_texture(
    v68,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v69,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v70,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v71,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v72,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v73,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v74, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v75,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v76, (int)compiler);
  *(unsigned __int64 *)((char *)v124.configuration + 4) = 0x400000000LL;
  HIDWORD(v124.configuration[1]) = 0x80000;
  *(_DWORD *)&v124.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v77, (int)compiler, "instance_test", 0, v124, 0);
  vostok::render::effect_compiler::set_depth(v78, (int)compiler, 0, 0, v143);
  vostok::render::effect_compiler::set_stencil(
    v79,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v144);
  vostok::render::effect_compiler::set_alpha_blend(
    v80,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v145);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v81);
  vostok::render::effect_compiler::set_texture(
    v82,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v83,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v84,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v85,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v86,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v87,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v88, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v89,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v90, (int)compiler);
  *(unsigned __int64 *)((char *)v125.configuration + 4) = 0x400000000LL;
  HIDWORD(v125.configuration[1]) = 0x80000;
  *(_DWORD *)&v125.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v91, (int)compiler, "instance_test2", 0, v125, 0);
  vostok::render::effect_compiler::set_depth(v92, (int)compiler, 0, 0, v146);
  vostok::render::effect_compiler::set_stencil(
    v93,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v147);
  vostok::render::effect_compiler::set_alpha_blend(
    v94,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v148);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v95);
  vostok::render::effect_compiler::set_texture(
    v96,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v97,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v98,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v99,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v100,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v101,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v102, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v103,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v104, (int)compiler);
  *(unsigned __int64 *)((char *)v126.configuration + 4) = 0x400000000LL;
  HIDWORD(v126.configuration[1]) = 0x80000;
  *(_DWORD *)&v126.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v105, (int)compiler, "instance_test2", 0, v126, 0);
  vostok::render::effect_compiler::set_depth(v106, (int)compiler, 1, 0, v149);
  vostok::render::effect_compiler::set_stencil(
    v107,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v150);
  vostok::render::effect_compiler::set_alpha_blend(
    v108,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v151);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v109);
  vostok::render::effect_compiler::set_texture(
    v110,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v111,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v112,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v113,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v114,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v115,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v116, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v117,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::point_light_effect<0,1>::compile(
        vostok::render::point_light_effect<0,1> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
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
  vostok::command_line::key *v22; // ecx
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
  vostok::command_line::key *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
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
  vostok::render::effect_compiler *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::command_line::key *v53; // ecx
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // ecx
  vostok::render::effect_compiler *v56; // ecx
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
  vostok::render::effect_compiler *v76; // ecx
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::effect_compiler *v80; // ecx
  vostok::command_line::key *v81; // ecx
  vostok::render::effect_compiler *v82; // ecx
  vostok::render::effect_compiler *v83; // ecx
  vostok::render::effect_compiler *v84; // ecx
  vostok::render::effect_compiler *v85; // ecx
  vostok::render::effect_compiler *v86; // ecx
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::effect_compiler *v88; // ecx
  vostok::render::effect_compiler *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::render::effect_compiler *v91; // ecx
  vostok::render::effect_compiler *v92; // ecx
  vostok::render::effect_compiler *v93; // ecx
  vostok::render::effect_compiler *v94; // ecx
  vostok::command_line::key *v95; // ecx
  vostok::render::effect_compiler *v96; // ecx
  vostok::render::effect_compiler *v97; // ecx
  vostok::render::effect_compiler *v98; // ecx
  vostok::render::effect_compiler *v99; // ecx
  vostok::render::effect_compiler *v100; // ecx
  vostok::render::effect_compiler *v101; // ecx
  vostok::render::effect_compiler *v102; // ecx
  vostok::render::effect_compiler *v103; // ecx
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_compiler *v105; // ecx
  vostok::render::effect_compiler *v106; // ecx
  vostok::render::effect_compiler *v107; // ecx
  vostok::render::effect_compiler *v108; // ecx
  vostok::command_line::key *v109; // ecx
  vostok::render::effect_compiler *v110; // ecx
  vostok::render::effect_compiler *v111; // ecx
  vostok::render::effect_compiler *v112; // ecx
  vostok::render::effect_compiler *v113; // ecx
  vostok::render::effect_compiler *v114; // ecx
  vostok::render::effect_compiler *v115; // ecx
  vostok::render::effect_compiler *v116; // ecx
  vostok::render::effect_compiler *v117; // ecx
  vostok::render::shader_configuration v118; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v119; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v120; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v121; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v122; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v123; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v124; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v125; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v126; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v127; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v128; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v129; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v130; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v131; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v132; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v133; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v134; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v135; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v136; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v137; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v138; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v139; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v140; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v141; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v142; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v143; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v144; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v145; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v146; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v147; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v148; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v149; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v150; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v151; // [esp+4h] [ebp-20h]
  __int64 v152; // [esp+1Ch] [ebp-8h]

  v152 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v118.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v118.configuration + 4) = 0;
  HIDWORD(v118.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v118, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v127);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v128);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v129);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(_DWORD *)&v119.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v119.configuration + 4) = 0;
  HIDWORD(v119.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v18, (int)compiler, "light", 0, v119, 0);
  vostok::render::effect_compiler::set_depth(v19, (int)compiler, 0, 0, v130);
  vostok::render::effect_compiler::set_stencil(
    v20,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v131);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    1,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_SRC_COLOR,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v132);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v22);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v30, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v31,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v32, (int)compiler);
  *(_DWORD *)&v120.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v120.configuration + 4) = 0;
  HIDWORD(v120.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v33, (int)compiler, "light", 0, v120, 0);
  vostok::render::effect_compiler::set_depth(v34, (int)compiler, 1, 0, v133);
  vostok::render::effect_compiler::set_stencil(
    v35,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v134);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v36);
  vostok::render::effect_compiler::color_write_enable(v37, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v38, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v39,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v40, (int)compiler);
  *(unsigned __int64 *)((char *)v121.configuration + 4) = 0;
  HIDWORD(v121.configuration[1]) = 0x80000;
  *(_DWORD *)&v121.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v41, (int)compiler, "instance_test", 0, v121, 0);
  vostok::render::effect_compiler::set_depth(v42, (int)compiler, 1, 0, v135);
  vostok::render::effect_compiler::set_stencil(
    v43,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v136);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v44);
  vostok::render::effect_compiler::color_write_enable(v45, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v46, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v47,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v48, (int)compiler);
  *(unsigned __int64 *)((char *)v122.configuration + 4) = 0;
  HIDWORD(v122.configuration[1]) = 0x80000;
  *(_DWORD *)&v122.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v49, (int)compiler, "instance_test", 0, v122, 0);
  vostok::render::effect_compiler::set_depth(v50, (int)compiler, 1, 0, v137);
  vostok::render::effect_compiler::set_alpha_blend(
    v51,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v138);
  vostok::render::effect_compiler::set_stencil(
    v52,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v139);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v53);
  vostok::render::effect_compiler::set_texture(
    v54,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v55,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v56,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v57,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v58,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v59,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v60, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v61,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v62, (int)compiler);
  *(unsigned __int64 *)((char *)v123.configuration + 4) = 0;
  HIDWORD(v123.configuration[1]) = 0x80000;
  *(_DWORD *)&v123.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v63, (int)compiler, "instance_test", 0, v123, 0);
  vostok::render::effect_compiler::set_depth(v64, (int)compiler, 0, 0, v140);
  vostok::render::effect_compiler::set_stencil(
    v65,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v141);
  vostok::render::effect_compiler::set_alpha_blend(
    v66,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v142);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v67);
  vostok::render::effect_compiler::set_texture(
    v68,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v69,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v70,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v71,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v72,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v73,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v74, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v75,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v76, (int)compiler);
  *(unsigned __int64 *)((char *)v124.configuration + 4) = 0;
  HIDWORD(v124.configuration[1]) = 0x80000;
  *(_DWORD *)&v124.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v77, (int)compiler, "instance_test", 0, v124, 0);
  vostok::render::effect_compiler::set_depth(v78, (int)compiler, 0, 0, v143);
  vostok::render::effect_compiler::set_stencil(
    v79,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v144);
  vostok::render::effect_compiler::set_alpha_blend(
    v80,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v145);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v81);
  vostok::render::effect_compiler::set_texture(
    v82,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v83,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v84,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v85,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v86,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v87,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v88, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v89,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v90, (int)compiler);
  *(unsigned __int64 *)((char *)v125.configuration + 4) = 0;
  HIDWORD(v125.configuration[1]) = 0x80000;
  *(_DWORD *)&v125.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v91, (int)compiler, "instance_test2", 0, v125, 0);
  vostok::render::effect_compiler::set_depth(v92, (int)compiler, 0, 0, v146);
  vostok::render::effect_compiler::set_stencil(
    v93,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v147);
  vostok::render::effect_compiler::set_alpha_blend(
    v94,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v148);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v95);
  vostok::render::effect_compiler::set_texture(
    v96,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v97,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v98,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v99,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v100,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v101,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v102, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v103,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v104, (int)compiler);
  *(unsigned __int64 *)((char *)v126.configuration + 4) = 0;
  HIDWORD(v126.configuration[1]) = 0x80000;
  *(_DWORD *)&v126.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v105, (int)compiler, "instance_test2", 0, v126, 0);
  vostok::render::effect_compiler::set_depth(v106, (int)compiler, 1, 0, v149);
  vostok::render::effect_compiler::set_stencil(
    v107,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v150);
  vostok::render::effect_compiler::set_alpha_blend(
    v108,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v151);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v109);
  vostok::render::effect_compiler::set_texture(
    v110,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v111,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v112,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v113,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v114,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v115,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v116, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v117,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::point_light_effect<0,0>::compile(
        vostok::render::point_light_effect<0,0> *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
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
  vostok::command_line::key *v22; // ecx
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
  vostok::command_line::key *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
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
  vostok::render::effect_compiler *v50; // ecx
  vostok::render::effect_compiler *v51; // ecx
  vostok::render::effect_compiler *v52; // ecx
  vostok::command_line::key *v53; // ecx
  vostok::render::effect_compiler *v54; // ecx
  vostok::render::effect_compiler *v55; // ecx
  vostok::render::effect_compiler *v56; // ecx
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
  vostok::render::effect_compiler *v76; // ecx
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::effect_compiler *v80; // ecx
  vostok::command_line::key *v81; // ecx
  vostok::render::effect_compiler *v82; // ecx
  vostok::render::effect_compiler *v83; // ecx
  vostok::render::effect_compiler *v84; // ecx
  vostok::render::effect_compiler *v85; // ecx
  vostok::render::effect_compiler *v86; // ecx
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::effect_compiler *v88; // ecx
  vostok::render::effect_compiler *v89; // ecx
  vostok::render::effect_compiler *v90; // ecx
  vostok::render::effect_compiler *v91; // ecx
  vostok::render::effect_compiler *v92; // ecx
  vostok::render::effect_compiler *v93; // ecx
  vostok::render::effect_compiler *v94; // ecx
  vostok::command_line::key *v95; // ecx
  vostok::render::effect_compiler *v96; // ecx
  vostok::render::effect_compiler *v97; // ecx
  vostok::render::effect_compiler *v98; // ecx
  vostok::render::effect_compiler *v99; // ecx
  vostok::render::effect_compiler *v100; // ecx
  vostok::render::effect_compiler *v101; // ecx
  vostok::render::effect_compiler *v102; // ecx
  vostok::render::effect_compiler *v103; // ecx
  vostok::render::effect_compiler *v104; // ecx
  vostok::render::effect_compiler *v105; // ecx
  vostok::render::effect_compiler *v106; // ecx
  vostok::render::effect_compiler *v107; // ecx
  vostok::render::effect_compiler *v108; // ecx
  vostok::command_line::key *v109; // ecx
  vostok::render::effect_compiler *v110; // ecx
  vostok::render::effect_compiler *v111; // ecx
  vostok::render::effect_compiler *v112; // ecx
  vostok::render::effect_compiler *v113; // ecx
  vostok::render::effect_compiler *v114; // ecx
  vostok::render::effect_compiler *v115; // ecx
  vostok::render::effect_compiler *v116; // ecx
  vostok::render::effect_compiler *v117; // ecx
  vostok::render::shader_configuration v118; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v119; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v120; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v121; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v122; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v123; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v124; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v125; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v126; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v127; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v128; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v129; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v130; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v131; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v132; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v133; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v134; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v135; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v136; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v137; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v138; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v139; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v140; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v141; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v142; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v143; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v144; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v145; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v146; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v147; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v148; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v149; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v150; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v151; // [esp+4h] [ebp-20h]
  __int64 v152; // [esp+1Ch] [ebp-8h]

  v152 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v118.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v118.configuration + 4) = 0;
  HIDWORD(v118.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "light", 0, v118, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v127);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v128);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v129);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v17, (int)compiler);
  *(_DWORD *)&v119.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v119.configuration + 4) = 0;
  HIDWORD(v119.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v18, (int)compiler, "light", 0, v119, 0);
  vostok::render::effect_compiler::set_depth(v19, (int)compiler, 0, 0, v130);
  vostok::render::effect_compiler::set_stencil(
    v20,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v131);
  vostok::render::effect_compiler::set_alpha_blend(
    v21,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v132);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v22);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v26,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_emissive",
    "$user$emmisive",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v28,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v30, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v31,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v32, (int)compiler);
  *(_DWORD *)&v120.0 = "point_light_accumulator";
  *(unsigned __int64 *)((char *)v120.configuration + 4) = 0;
  HIDWORD(v120.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v33, (int)compiler, "light", 0, v120, 0);
  vostok::render::effect_compiler::set_depth(v34, (int)compiler, 1, 0, v133);
  vostok::render::effect_compiler::set_stencil(
    v35,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v134);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v36);
  vostok::render::effect_compiler::color_write_enable(v37, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v38, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v39,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v40, (int)compiler);
  *(unsigned __int64 *)((char *)v121.configuration + 4) = 0;
  HIDWORD(v121.configuration[1]) = 0x80000;
  *(_DWORD *)&v121.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v41, (int)compiler, "instance_test", 0, v121, 0);
  vostok::render::effect_compiler::set_depth(v42, (int)compiler, 1, 0, v135);
  vostok::render::effect_compiler::set_stencil(
    v43,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_INVERT,
    v136);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v44);
  vostok::render::effect_compiler::color_write_enable(v45, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v46, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v47,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v48, (int)compiler);
  *(unsigned __int64 *)((char *)v122.configuration + 4) = 0;
  HIDWORD(v122.configuration[1]) = 0x80000;
  *(_DWORD *)&v122.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v49, (int)compiler, "instance_test", 0, v122, 0);
  vostok::render::effect_compiler::set_depth(v50, (int)compiler, 1, 0, v137);
  vostok::render::effect_compiler::set_alpha_blend(
    v51,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v138);
  vostok::render::effect_compiler::set_stencil(
    v52,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_INVERT,
    v139);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v53);
  vostok::render::effect_compiler::set_texture(
    v54,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v55,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v56,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v57,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v58,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v59,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v60, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v61,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v62, (int)compiler);
  *(unsigned __int64 *)((char *)v123.configuration + 4) = 0;
  HIDWORD(v123.configuration[1]) = 0x80000;
  *(_DWORD *)&v123.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v63, (int)compiler, "instance_test", 0, v123, 0);
  vostok::render::effect_compiler::set_depth(v64, (int)compiler, 0, 0, v140);
  vostok::render::effect_compiler::set_stencil(
    v65,
    (int)compiler,
    1,
    0xFFu,
    0x40u,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_INVERT,
    D3D11_STENCIL_OP_KEEP,
    v141);
  vostok::render::effect_compiler::set_alpha_blend(
    v66,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v142);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v67);
  vostok::render::effect_compiler::set_texture(
    v68,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v69,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v70,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v71,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v72,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v73,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v74, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v75,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v76, (int)compiler);
  *(unsigned __int64 *)((char *)v124.configuration + 4) = 0;
  HIDWORD(v124.configuration[1]) = 0x80000;
  *(_DWORD *)&v124.0 = "instance_test";
  vostok::render::effect_compiler::begin_pass(v77, (int)compiler, "instance_test", 0, v124, 0);
  vostok::render::effect_compiler::set_depth(v78, (int)compiler, 0, 0, v143);
  vostok::render::effect_compiler::set_stencil(
    v79,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v144);
  vostok::render::effect_compiler::set_alpha_blend(
    v80,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v145);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v81);
  vostok::render::effect_compiler::set_texture(
    v82,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v83,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v84,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v85,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v86,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v87,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v88, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v89,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v90, (int)compiler);
  *(unsigned __int64 *)((char *)v125.configuration + 4) = 0;
  HIDWORD(v125.configuration[1]) = 0x80000;
  *(_DWORD *)&v125.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v91, (int)compiler, "instance_test2", 0, v125, 0);
  vostok::render::effect_compiler::set_depth(v92, (int)compiler, 0, 0, v146);
  vostok::render::effect_compiler::set_stencil(
    v93,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v147);
  vostok::render::effect_compiler::set_alpha_blend(
    v94,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v148);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v95);
  vostok::render::effect_compiler::set_texture(
    v96,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v97,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v98,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v99,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v100,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v101,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v102, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v103,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v104, (int)compiler);
  *(unsigned __int64 *)((char *)v126.configuration + 4) = 0;
  HIDWORD(v126.configuration[1]) = 0x80000;
  *(_DWORD *)&v126.0 = "instance_test2";
  vostok::render::effect_compiler::begin_pass(v105, (int)compiler, "instance_test2", 0, v126, 0);
  vostok::render::effect_compiler::set_depth(v106, (int)compiler, 1, 0, v149);
  vostok::render::effect_compiler::set_stencil(
    v107,
    (int)compiler,
    1,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v150);
  vostok::render::effect_compiler::set_alpha_blend(
    v108,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v151);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v109);
  vostok::render::effect_compiler::set_texture(
    v110,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v111,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v112,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v113,
    (const char *)compiler,
    "t_diffuse",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v114,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v115,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v116, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v117,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

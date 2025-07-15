void __thiscall vostok::render::effect_resolve_particles::compile(
        vostok::render::effect_resolve_particles *this,
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
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::render::effect_compiler *v41; // ecx
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_compiler *v43; // ecx
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
  vostok::render::effect_compiler *v56; // ecx
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::effect_compiler *v58; // ecx
  vostok::render::shader_configuration v59; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v60; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v61; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v62; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v63; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v64; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v65; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v66; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v67; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v68; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v69; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v70; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v71; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v72; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v73; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v74; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v75; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v76; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v77; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v78; // [esp+4h] [ebp-20h]
  __int64 v79; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v59.0 = "resolve_particles";
  *(unsigned __int64 *)((char *)v59.configuration + 4) = 0;
  HIDWORD(v59.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "eye_adaptation", 0, v59, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v65);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0x77u,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v66);
  vostok::render::effect_compiler::set_alpha_blend(
    v7,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v67);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_particle_lighting_depth",
    "$user$particle_lighting_depth",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(_DWORD *)&v60.0 = "resolve_particles_mask2";
  *(unsigned __int64 *)((char *)v60.configuration + 4) = 0;
  HIDWORD(v60.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "eye_adaptation", 0, v60, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v68);
  vostok::render::effect_compiler::set_stencil(
    v16,
    (int)compiler,
    1,
    0x77u,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v69);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(v18, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_particle_lighting_depth",
    "$user$particle_lighting_depth",
    0,
    0xFFFFFFFF,
    0,
    1.0);
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
  *(_DWORD *)&v61.0 = "resolve_particles_mask";
  *(unsigned __int64 *)((char *)v61.configuration + 4) = 0;
  HIDWORD(v61.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v24, (int)compiler, "eye_adaptation", 0, v61, 0);
  vostok::render::effect_compiler::set_depth(v25, (int)compiler, 0, 0, v70);
  vostok::render::effect_compiler::set_stencil(
    v26,
    (int)compiler,
    1,
    0x77u,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v71);
  vostok::render::effect_compiler::set_texture(
    v27,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(v28, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_particle_lighting_depth",
    "$user$particle_lighting_depth",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v30,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v33, (int)compiler);
  *(_DWORD *)&v62.0 = "resolve_particles_4x_to_2x";
  *(unsigned __int64 *)((char *)v62.configuration + 4) = 0;
  HIDWORD(v62.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v34, (int)compiler, "eye_adaptation", 0, v62, 0);
  vostok::render::effect_compiler::set_depth(v35, (int)compiler, 0, 0, v72);
  vostok::render::effect_compiler::set_texture(
    v36,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v37,
    (const char *)compiler,
    "t_hires_depth",
    "$user$frame_depth_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v38,
    (const char *)compiler,
    "t_coarse_depth",
    "$user$particle_lighting_depth",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v39, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v40,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v41, (int)compiler);
  *(_DWORD *)&v63.0 = "resolve_particles3";
  *(unsigned __int64 *)((char *)v63.configuration + 4) = 0;
  HIDWORD(v63.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v42, (int)compiler, "eye_adaptation", 0, v63, 0);
  vostok::render::effect_compiler::set_depth(v43, (int)compiler, 0, 0, v73);
  vostok::render::effect_compiler::set_stencil(
    v44,
    (int)compiler,
    1,
    0x77u,
    0xFFu,
    255,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v74);
  vostok::render::effect_compiler::set_alpha_blend(
    v45,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v75);
  vostok::render::effect_compiler::set_texture(
    v46,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v47,
    (const char *)compiler,
    "t_particle_lighting_depth",
    "$user$particle_lighting_depth",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v48,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v49, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v50,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v51, (int)compiler);
  *(_DWORD *)&v64.0 = "resolve_particles_copy";
  v79 = 0x80000;
  *(unsigned __int64 *)((char *)v64.configuration + 4) = 0;
  HIDWORD(v64.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v52, (int)compiler, "eye_adaptation", 0, v64, 0);
  vostok::render::effect_compiler::set_depth(v53, (int)compiler, 0, 0, v76);
  vostok::render::effect_compiler::set_stencil(
    v54,
    (int)compiler,
    1,
    0x77u,
    0xFFu,
    255,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v77);
  vostok::render::effect_compiler::set_alpha_blend(
    v55,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v78);
  vostok::render::effect_compiler::set_texture(
    v56,
    (const char *)compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v57, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v58,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

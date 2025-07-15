void __thiscall vostok::render::effect_ssao_filter4x4::compile(
        vostok::render::effect_ssao_filter4x4 *this,
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
  vostok::render::shader_configuration v53; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v54; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v55; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v56; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v57; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v58; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v59; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v60; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v61; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v62; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v63; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v64; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v65; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v66; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v67; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v68; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v69; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v70; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v71; // [esp+4h] [ebp-20h]
  __int64 v72; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v53.0 = "ssao_filter4x4";
  *(unsigned __int64 *)((char *)v53.configuration + 4) = 0;
  HIDWORD(v53.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process_fxaa", 0, v53, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v58);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v59);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v9,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v60);
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v12, (int)compiler);
  *(unsigned __int64 *)((char *)v54.configuration + 4) = 0;
  *(_DWORD *)&v54.0 = "ssao_filter4x4_1";
  HIDWORD(v54.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v13, (int)compiler, "post_process_fxaa", 0, v54, 0);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 1, 0, v61);
  vostok::render::effect_compiler::set_alpha_blend(
    v15,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v62);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v17,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v63);
  vostok::render::effect_compiler::end_pass(v18, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v19,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v20, (int)compiler);
  *(_DWORD *)&v55.0 = "temporal_mask";
  *(unsigned __int64 *)((char *)v55.configuration + 4) = 0;
  HIDWORD(v55.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v21, (int)compiler, "post_process_fxaa", 0, v55, 0);
  vostok::render::effect_compiler::set_depth(v22, (int)compiler, 1, 0, v64);
  vostok::render::effect_compiler::set_alpha_blend(
    v23,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v65);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_ssao_prev_z",
    "$user$ssao_prev_accumulator_z",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v26,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v27, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v28,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v29, (int)compiler);
  *(_DWORD *)&v56.0 = "ssao_filter_upsample";
  *(unsigned __int64 *)((char *)v56.configuration + 4) = 0;
  HIDWORD(v56.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v30, (int)compiler, "post_process_fxaa", 0, v56, 0);
  vostok::render::effect_compiler::set_depth(v31, (int)compiler, 1, 0, v66);
  vostok::render::effect_compiler::set_alpha_blend(
    v32,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v67);
  vostok::render::effect_compiler::set_texture(
    v33,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v34,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v35,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v68);
  vostok::render::effect_compiler::color_write_enable(
    v36,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v37, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v38,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v39, (int)compiler);
  v72 = 0x80000;
  *(_DWORD *)&v57.0 = "ssao_filter_upsample_temporal";
  *(unsigned __int64 *)((char *)v57.configuration + 4) = 0;
  HIDWORD(v57.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v40, (int)compiler, "post_process_fxaa", 0, v57, 0);
  vostok::render::effect_compiler::set_depth(v41, (int)compiler, 1, 0, v69);
  vostok::render::effect_compiler::set_alpha_blend(
    v42,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v70);
  vostok::render::effect_compiler::set_texture(
    v43,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v44,
    (const char *)compiler,
    "t_ssao_accumulator",
    "$user$ssao_accumulator",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v45,
    (const char *)compiler,
    "t_ssao_prev_result",
    "$user$ssao_prev_accumulator_full_x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v46,
    (const char *)compiler,
    "t_ssao_prev_z",
    "$user$ssao_prev_accumulator_z",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v47,
    (const char *)compiler,
    "t_ssao_temporal_mask",
    "$user$ssao_temporal_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v48,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v71);
  vostok::render::effect_compiler::color_write_enable(
    v49,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::color_write_enable(v50, (int)compiler, 1u, D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v51, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v52,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

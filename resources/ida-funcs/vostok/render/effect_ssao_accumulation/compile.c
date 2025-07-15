void __thiscall vostok::render::effect_ssao_accumulation::compile(
        vostok::render::effect_ssao_accumulation *this,
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
  vostok::render::shader_configuration v30; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v31; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v32; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v33; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v34; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v35; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v36; // [esp+4h] [ebp-20h]
  __int64 v37; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v30.0 = "ssao_accumulation";
  *(unsigned __int64 *)((char *)v30.configuration + 4) = 0;
  HIDWORD(v30.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process0", 0, v30, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v32);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v33);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_random_rotates",
    "engine/ssao_rotate",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_frame_depth_downsampled",
    "$user$frame_depth_downsampled",
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
    "t_normal_and_depth",
    "$user$gbuffer_position_normal_downsampled_x2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v13,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v14, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v15,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v16, (int)compiler);
  *(_DWORD *)&v31.0 = "ssao_accumulation_hq";
  v37 = 0x80000;
  *(unsigned __int64 *)((char *)v31.configuration + 4) = 0;
  HIDWORD(v31.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v17, (int)compiler, "post_process0", 0, v31, 0);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 0, 0, v34);
  vostok::render::effect_compiler::set_alpha_blend(
    v19,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v35);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_random_rotates",
    "engine/ssao_rotate",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_frame_depth_downsampled",
    "$user$frame_depth_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v24,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v25,
    (const char *)compiler,
    "t_normal_and_depth",
    "$user$gbuffer_position_normal_downsampled_x2",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_stencil(
    v26,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v36);
  vostok::render::effect_compiler::color_write_enable(
    v27,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v28, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v29,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

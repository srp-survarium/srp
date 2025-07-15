void __thiscall vostok::render::effect_channel_blur::compile(
        vostok::render::effect_channel_blur *this,
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
  vostok::render::shader_configuration v18; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v19; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v20; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v21; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v22; // [esp+4h] [ebp-20h]
  __int64 v23; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v18.0 = "channel_blur";
  *(unsigned __int64 *)((char *)v18.configuration + 4) = 0;
  HIDWORD(v18.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "motion_blur", 0, v18, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v20);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_bloom_4x",
    "$user$bloom_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_bloom_16x",
    "$user$bloom_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::set_alpha_blend(
    v9,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v21);
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v12, (int)compiler);
  *(_DWORD *)&v19.0 = "channel_blur_desaturate";
  v23 = 0x80000;
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v13, (int)compiler, "motion_blur", 0, v19, 0);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 0, 0, v22);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_frame_color",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

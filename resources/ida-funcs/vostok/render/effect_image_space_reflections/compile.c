void __thiscall vostok::render::effect_image_space_reflections::compile(
        vostok::render::effect_image_space_reflections *this,
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
  vostok::render::shader_configuration v13; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v14; // [esp+4h] [ebp-18h]
  D3D11_BLEND_OP v15; // [esp+4h] [ebp-18h]
  __int64 v16; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  v16 = 0x80000;
  HIDWORD(v13.configuration[1]) = 0x80000;
  *(_DWORD *)&v13.0 = "image_space_reflections";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "image_space_reflections", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_final_frame_donwsampled",
    "$user$final_frame_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v10,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v15);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

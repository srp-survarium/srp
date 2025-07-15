void __thiscall vostok::render::effect_gather_bloom::compile(
        vostok::render::effect_gather_bloom *this,
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
  vostok::render::shader_configuration v17; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v18; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v19; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v20; // [esp+4h] [ebp-20h]
  __int64 v21; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v17.0 = "gather_bloom";
  *(unsigned __int64 *)((char *)v17.configuration + 4) = 0;
  HIDWORD(v17.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "gather_bloom", 0, v17, 0);
  vostok::render::effect_compiler::set_texture(
    v5,
    (const char *)compiler,
    "t_frame_color",
    "$user$bright_pixels_2x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v6, (int)compiler, 0, 0, v19);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&v18.0 = "bloom_combine";
  v21 = 0x80000;
  *(unsigned __int64 *)((char *)v18.configuration + 4) = 0;
  HIDWORD(v18.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "gather_bloom", 0, v18, 0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_bloom0",
    "$user$bloom_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_bloom1",
    "$user$bloom_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_bloom2",
    "$user$bloom_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 0, 0, v20);
  vostok::render::effect_compiler::end_pass(v15, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v16,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

void __thiscall vostok::render::effect_lens_flares::compile(
        vostok::render::effect_lens_flares *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-20h]
  D3D11_STENCIL_OP v13; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v14; // [esp+4h] [ebp-20h]
  __int64 v15; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  v15 = 0x80000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "lens_flares";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "lens_flares", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v13);
  vostok::render::effect_compiler::set_alpha_blend(
    v7,
    (int)compiler,
    0,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v14);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_blurred_frame_bloom_only_color",
    "$user$bloom_combine",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

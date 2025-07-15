void __thiscall vostok::render::effect_simple_fog::compile(
        vostok::render::effect_simple_fog *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *__formal)
{
  vostok::render::effect_compiler *v3; // ecx
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  D3D11_BLEND_OP v6; // [esp+0h] [ebp-20h]
  bool v7; // [esp+0h] [ebp-20h]
  D3D11_STENCIL_OP v8; // [esp+0h] [ebp-20h]
  vostok::render::shader_include_getter include_getter; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this);
  v11 = 4;
  include_getter.__vftable = 0;
  v10 = 0;
  v12 = 0;
  vostok::render::effect_compiler::begin_pass(
    v3,
    (const char *)compiler,
    (const char *)&stru_965264.configuration[1] + 4,
    0,
    &stru_965264,
    &include_getter);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::set_alpha_blend(
    compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_ZERO,
    v6);
  vostok::render::effect_compiler::set_texture(compiler, "t_position", "$user$position", 0, v7, 0xFFFFFFFF);
  vostok::render::effect_compiler::set_stencil(
    compiler,
    1,
    0x80u,
    0xFFu,
    0xFFu,
    D3D11_COMPARISON_LESS,
    D3D11_STENCIL_OP_KEEP,
    v8,
    D3D11_STENCIL_OP_KEEP);
  vostok::render::effect_compiler::end_pass(v4);
  vostok::render::effect_compiler::end_technique(v5);
}

void __thiscall vostok::render::effect_editor_apply_wireframe::compile(
        vostok::render::effect_editor_apply_wireframe *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  D3D11_BLEND_OP v13; // [esp+4h] [ebp-18h]
  __int64 v14; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v11.0 = "editor_apply_wireframe";
  v14 = 0x80000;
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  HIDWORD(v11.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "eye_adaptation", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_alpha_blend(
    v6,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v13);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_wireframe_buffer",
    "$user$generic0",
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
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

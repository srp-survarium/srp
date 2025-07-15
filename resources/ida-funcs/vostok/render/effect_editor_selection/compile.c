void __thiscall vostok::render::effect_editor_selection::compile(
        vostok::render::effect_editor_selection *this,
        vostok::render::effect_compiler *compiler,
        vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_material_base *v8; // ecx
  vostok::render::shader_configuration *v9; // [esp+0h] [ebp-18h]
  D3D11_COMPARISON_FUNC v10; // [esp+0h] [ebp-18h]
  D3D11_BLEND_OP v11; // [esp+0h] [ebp-18h]
  const vostok::configs::binary_config_value *v12; // [esp+4h] [ebp-14h]
  char pixel_shader_name[4]; // [esp+8h] [ebp-10h] BYREF
  int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]

  v15 = 0x80000;
  *(_DWORD *)pixel_shader_name = 0;
  v14 = 0;
  v16 = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_selection",
    (char *)compiler,
    pixel_shader_name,
    config,
    v9,
    v12);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 0, v10);
  vostok::render::effect_compiler::set_alpha_blend(
    v5,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v11);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v7);
  vostok::render::effect_material_base::compile_end(v8, compiler);
}

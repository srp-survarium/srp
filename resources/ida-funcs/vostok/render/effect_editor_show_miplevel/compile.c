void __thiscall vostok::render::effect_editor_show_miplevel::compile(
        vostok::render::effect_editor_show_miplevel *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_material_base *v7; // ecx
  vostok::render::shader_configuration *v8; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v9; // [esp+4h] [ebp-20h]
  const vostok::configs::binary_config_value *v10; // [esp+8h] [ebp-1Ch]
  _DWORD v11[4]; // [esp+14h] [ebp-10h] BYREF

  v11[2] = 0x80000;
  v11[0] = 0;
  v11[1] = 0;
  v11[3] = 0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_texture_mip_level",
    compiler,
    (const char *)v11,
    config,
    v8,
    v10);
  vostok::render::effect_compiler::set_depth(v4, (int)compiler, 1, 1, v9);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v5);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_albedo_color",
    "$user$albedo",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v7, compiler);
}

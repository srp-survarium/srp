void __thiscall vostok::render::effect_add_border_padding::compile(
        vostok::render::effect_add_border_padding *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::shader_configuration v9; // [esp-14h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v10; // [esp+0h] [ebp-18h]
  __int64 v11; // [esp+10h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v9.configuration + 4) = 0;
  v11 = 0x80000;
  HIDWORD(v9.configuration[1]) = 0x80000;
  *(_DWORD *)&v9.0 = "bake_decal_border_padding";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "bake_decal_border_padding", 0, v9, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v10);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

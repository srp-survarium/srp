void __thiscall vostok::render::effect_copy_shadow_map::compile(
        vostok::render::effect_copy_shadow_map *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *a4)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::shader_configuration v10; // [esp-14h] [ebp-30h]
  D3D11_COMPARISON_FUNC v11; // [esp+0h] [ebp-1Ch]
  __int64 v12; // [esp+14h] [ebp-8h]

  v12 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v10.configuration + 4) = 0;
  HIDWORD(v10.configuration[1]) = 0x80000;
  *(_DWORD *)&v10.0 = "copy_shadow_map";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "copy_shadow_map", 0, v10, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 1, v11);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::color_write_enable(v7, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v8, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

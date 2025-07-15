void __thiscall vostok::render::effect_downsample_skin_irradiance_texture::compile(
        vostok::render::effect_downsample_skin_irradiance_texture *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
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
  *(_DWORD *)&v9.0 = "downsample_irradiance_texture";
  v11 = 0x80000;
  *(unsigned __int64 *)((char *)v9.configuration + 4) = 0;
  HIDWORD(v9.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur_irradiance_texture", 0, v9, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v10);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v6);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

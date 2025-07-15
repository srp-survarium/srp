void __thiscall vostok::render::effect_fix_irradiance_texture::compile(
        vostok::render::effect_fix_irradiance_texture *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::shader_configuration v10; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v11; // [esp+4h] [ebp-20h]
  __int64 v12; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v10.0 = "fix_irradiance_texture";
  v12 = 0x80000;
  *(unsigned __int64 *)((char *)v10.configuration + 4) = 0;
  HIDWORD(v10.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "blur_irradiance_texture", 0, v10, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v11);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v6);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_skin_scattering_temp",
    "$user$skin_scattering_temp",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v8, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v9,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

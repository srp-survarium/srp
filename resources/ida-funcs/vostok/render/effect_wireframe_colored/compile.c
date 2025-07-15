void __thiscall vostok::render::effect_wireframe_colored::compile(
        vostok::render::effect_wireframe_colored *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // eax
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // eax
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // eax
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::shader_configuration v12; // [esp-14h] [ebp-2Ch]

  *(_DWORD *)&v12.0 = "color_fixed";
  *(unsigned __int64 *)((char *)v12.configuration + 4) = 0;
  HIDWORD(v12.configuration[1]) = 0x80000;
  v4 = vostok::render::effect_compiler::begin_technique(0, (int)compiler);
  v6 = vostok::render::effect_compiler::begin_pass(v5, (int)v4, (char *)&stru_803D84, 0, v12, 0);
  v8 = vostok::render::effect_compiler::set_fill_mode(
         v6,
         (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
         v7);
  v10 = vostok::render::effect_compiler::end_pass(v9, (int)v8);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v10);
}

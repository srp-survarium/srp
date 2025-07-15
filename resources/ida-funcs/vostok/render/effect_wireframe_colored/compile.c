void __thiscall vostok::render::effect_wireframe_colored::compile(
        vostok::render::effect_wireframe_colored *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::effect_compiler *v3; // eax
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // eax
  vostok::render::effect_compiler *v6; // eax
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::res_pass *v8; // eax
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::shader_configuration include_getter; // [esp+8h] [ebp-10h] BYREF

  *(_DWORD *)&include_getter.0 = 0;
  *(unsigned __int64 *)((char *)include_getter.configuration + 4) = 0x400000000LL;
  HIDWORD(include_getter.configuration[1]) = 0;
  v3 = vostok::render::effect_compiler::begin_technique(
         (vostok::render::effect_compiler *)&include_getter,
         (int)compiler);
  v5 = vostok::render::effect_compiler::begin_pass(
         v4,
         v3,
         (char *)&stru_95AAC4,
         0,
         (vostok::render::shader_configuration *)&stru_96625C.configuration[1],
         &include_getter);
  v6 = vostok::render::effect_compiler::set_fill_mode(v5, D3D11_FILL_WIREFRAME);
  v8 = vostok::render::effect_compiler::end_pass(
         v7,
         (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v6);
  vostok::render::effect_compiler::end_technique(v9, (int)v8);
}

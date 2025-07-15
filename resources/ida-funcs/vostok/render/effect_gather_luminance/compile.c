void __thiscall vostok::render::effect_gather_luminance::compile(
        vostok::render::effect_gather_luminance *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::shader_configuration v18; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v19; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v20; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v21; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v22; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v23; // [esp+0h] [ebp-20h]
  __int64 v24; // [esp+18h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v18.0 = "gather_log_luminance";
  *(unsigned __int64 *)((char *)v18.configuration + 4) = 0;
  HIDWORD(v18.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "gather_luminance", 0, v18, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v21);
  vostok::render::effect_compiler::end_pass(v6, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  *(_DWORD *)&v19.0 = "gather_luminance";
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v9, (int)compiler, "gather_luminance", 0, v19, 0);
  vostok::render::effect_compiler::set_depth(v10, (int)compiler, 0, 0, v22);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(_DWORD *)&v20.0 = "gather_exp_luminance";
  v24 = 0x80000;
  *(unsigned __int64 *)((char *)v20.configuration + 4) = 0;
  HIDWORD(v20.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "gather_luminance", 0, v20, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v23);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

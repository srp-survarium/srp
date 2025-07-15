void __thiscall vostok::render::effect_shadow_map::compile(
        vostok::render::effect_shadow_map *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_constant_storage *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_constant_storage *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::command_line::key *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::shader_configuration v19; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v20; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v21; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v22; // [esp+0h] [ebp-20h]
  float v23; // [esp+Ch] [ebp-14h] BYREF
  unsigned __int64 v24; // [esp+10h] [ebp-10h]
  __int64 v25; // [esp+18h] [ebp-8h]

  v25 = 0x80000;
  v24 = 0;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v19.0 = "depth_accumulate";
  *(unsigned __int64 *)((char *)v19.configuration + 4) = 0;
  HIDWORD(v19.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, (char *)&stru_812A60, 0, v19, 0);
  v23 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<float>(v5, &v23, compiler, "wind_scale");
  vostok::render::effect_compiler::set_depth(v6, (int)compiler, 1, 1, v21);
  vostok::render::effect_compiler::color_write_enable(v7, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v8);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v20.0 = "depth_accumulate_batched";
  *(unsigned __int64 *)((char *)v20.configuration + 4) = v24;
  HIDWORD(v20.configuration[1]) = v25;
  vostok::render::effect_compiler::begin_pass(
    v12,
    (int)compiler,
    (char *)&stru_812A9C,
    0,
    v20,
    (vostok::render::shader_include_getter *)HIDWORD(v25));
  v23 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<float>(v13, &v23, compiler, "wind_scale");
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 1, 1, v22);
  vostok::render::effect_compiler::color_write_enable(v15, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v16);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

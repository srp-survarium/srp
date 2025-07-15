void __thiscall vostok::render::effect_debug_modify_gbuffer::compile(
        vostok::render::effect_debug_modify_gbuffer *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_constant_storage *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::command_line::key *v15; // ecx
  vostok::command_line::key *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_constant_storage *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::command_line::key *v24; // ecx
  vostok::command_line::key *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_constant_storage *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::shader_configuration v30; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v31; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v32; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v33; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v34; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v35; // [esp+0h] [ebp-20h]
  vostok::math::float4 source; // [esp+10h] [ebp-10h] BYREF

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v30.0 = "debug_modify_gbuffer";
  *(unsigned __int64 *)((char *)v30.configuration + 4) = 0;
  HIDWORD(v30.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "debug_modify_gbuffer", 0, v30, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v33);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::color_write_enable(v8, (int)compiler, 0, D3D11_COLOR_WRITE_ENABLE_RED);
  memset(&source, 0, sizeof(source));
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&source, v9, compiler, "write_color");
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v12, (int)compiler);
  *(_DWORD *)&v31.0 = "debug_modify_gbuffer";
  *(_QWORD *)&source.x = 0;
  *(_QWORD *)&source.elements[2] = 0x80000;
  *(unsigned __int64 *)((char *)v31.configuration + 4) = 0;
  HIDWORD(v31.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v13, (int)compiler, "debug_modify_gbuffer", 0, v31, 0);
  vostok::render::effect_compiler::set_depth(v14, (int)compiler, 0, 0, v34);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v15);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v16);
  vostok::render::effect_compiler::color_write_enable(v17, (int)compiler, 0, D3D11_COLOR_WRITE_ENABLE_ALPHA);
  memset(&source, 0, sizeof(source));
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&source, v18, compiler, "write_color");
  vostok::render::effect_compiler::end_pass(v19, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v21, (int)compiler);
  *(_DWORD *)&v32.0 = "debug_modify_gbuffer";
  *(_QWORD *)&source.x = 0;
  *(_QWORD *)&source.elements[2] = 0x80000;
  *(unsigned __int64 *)((char *)v32.configuration + 4) = 0;
  HIDWORD(v32.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v22, (int)compiler, "debug_modify_gbuffer", 0, v32, 0);
  vostok::render::effect_compiler::set_depth(v23, (int)compiler, 0, 0, v35);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v24);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v25);
  vostok::render::effect_compiler::color_write_enable(v26, (int)compiler, 0, D3D11_COLOR_WRITE_ENABLE_ALPHA);
  source.x = s_bm_current_air_resistance;
  source.y = s_bm_current_air_resistance;
  source.z = s_bm_current_air_resistance;
  source.w = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&source, v27, compiler, "write_color");
  vostok::render::effect_compiler::end_pass(v28, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v29,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

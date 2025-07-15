void __thiscall vostok::render::effect_block_compression::compile(
        vostok::render::effect_block_compression *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
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
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::shader_configuration v28; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v29; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v30; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v31; // [esp-14h] [ebp-34h]
  vostok::render::shader_configuration v32; // [esp-14h] [ebp-34h]
  D3D11_COMPARISON_FUNC v33; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v34; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v35; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v36; // [esp+0h] [ebp-20h]
  D3D11_COMPARISON_FUNC v37; // [esp+0h] [ebp-20h]
  __int64 v38; // [esp+18h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v28.0 = "block_compression_bc1";
  *(unsigned __int64 *)((char *)v28.configuration + 4) = 0;
  HIDWORD(v28.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "block_compression", 0, v28, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v33);
  vostok::render::effect_compiler::end_pass(v6, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  *(_DWORD *)&v29.0 = "block_compression_bc3";
  *(unsigned __int64 *)((char *)v29.configuration + 4) = 0;
  HIDWORD(v29.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v9, (int)compiler, "block_compression", 0, v29, 0);
  vostok::render::effect_compiler::set_depth(v10, (int)compiler, 0, 0, v34);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(_DWORD *)&v30.0 = "block_compression_bc3nm";
  *(unsigned __int64 *)((char *)v30.configuration + 4) = 0;
  HIDWORD(v30.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "block_compression", 0, v30, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v35);
  vostok::render::effect_compiler::end_pass(v16, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v17,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v18, (int)compiler);
  *(_DWORD *)&v31.0 = "block_compression_box_filter";
  *(unsigned __int64 *)((char *)v31.configuration + 4) = 0;
  HIDWORD(v31.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v19, (int)compiler, "block_compression", 0, v31, 0);
  vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, v36);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v23, (int)compiler);
  *(_DWORD *)&v32.0 = "block_compression_kaiser_filter";
  v38 = 0x80000;
  *(unsigned __int64 *)((char *)v32.configuration + 4) = 0;
  HIDWORD(v32.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v24, (int)compiler, "block_compression", 0, v32, 0);
  vostok::render::effect_compiler::set_depth(v25, (int)compiler, 0, 0, v37);
  vostok::render::effect_compiler::end_pass(v26, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v27,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

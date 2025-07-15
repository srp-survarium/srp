void __thiscall vostok::render::effect_gather_luminance_histogram::compile(
        vostok::render::effect_gather_luminance_histogram *this,
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
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::shader_configuration v25; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v26; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v27; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v28; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v29; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v30; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v31; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v32; // [esp+4h] [ebp-20h]
  __int64 v33; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v25.0 = "gather_luminance_in_range";
  *(unsigned __int64 *)((char *)v25.configuration + 4) = 0;
  HIDWORD(v25.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "gather_luminance", 0, v25, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v29);
  vostok::render::effect_compiler::end_pass(v6, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v7,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v8, (int)compiler);
  *(_DWORD *)&v26.0 = "gather_luminance_count";
  *(unsigned __int64 *)((char *)v26.configuration + 4) = 0;
  HIDWORD(v26.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v9, (int)compiler, "gather_luminance", 0, v26, 0);
  vostok::render::effect_compiler::set_depth(v10, (int)compiler, 0, 0, v30);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v13, (int)compiler);
  *(_DWORD *)&v27.0 = "gather_luminance_histogram";
  *(unsigned __int64 *)((char *)v27.configuration + 4) = 0;
  HIDWORD(v27.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v14, (int)compiler, "gather_luminance2", 0, v27, 0);
  vostok::render::effect_compiler::set_depth(v15, (int)compiler, 0, 0, v31);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_frame_luminance",
    "$user$frame_luminance",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v28.0 = "gather_luminance_histogram_downsample_scene_color";
  v33 = 0x80000;
  *(unsigned __int64 *)((char *)v28.configuration + 4) = 0;
  HIDWORD(v28.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "gather_luminance2", 0, v28, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v32);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v23, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v24,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

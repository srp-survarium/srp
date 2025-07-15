void __thiscall vostok::render::effect_post_process_mlaa::compile(
        vostok::render::effect_post_process_mlaa *this,
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
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v24; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v25; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v26; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v27; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  __int64 v29; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v23.0 = "mlaa_color_edge_detection";
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0;
  HIDWORD(v23.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process_mlaa", 0, v23, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v26);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&v24.0 = "mlaa_blending_weight_calculation";
  *(unsigned __int64 *)((char *)v24.configuration + 4) = 0;
  HIDWORD(v24.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "post_process_mlaa", 0, v24, 0);
  vostok::render::effect_compiler::set_depth(v11, (int)compiler, 0, 0, v27);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_edges",
    "$user$mlaa_edges",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v13, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v15, (int)compiler);
  v29 = 0x80000;
  *(_DWORD *)&v25.0 = "mlaa_neighborhood_blending";
  *(unsigned __int64 *)((char *)v25.configuration + 4) = 0;
  HIDWORD(v25.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v16, (int)compiler, "post_process_mlaa", 0, v25, 0);
  vostok::render::effect_compiler::set_depth(v17, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_edges",
    "$user$mlaa_edges",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_blend",
    "$user$mlaa_blended_weights",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v21, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v22,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

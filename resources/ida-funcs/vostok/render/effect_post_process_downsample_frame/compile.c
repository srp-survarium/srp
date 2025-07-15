void __thiscall vostok::render::effect_post_process_downsample_frame::compile(
        vostok::render::effect_post_process_downsample_frame *this,
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
  vostok::render::shader_configuration v21; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v22; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v23; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v24; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v25; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v26; // [esp+4h] [ebp-20h]
  __int64 v27; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v21.0 = "post_process_downsample_frame";
  *(unsigned __int64 *)((char *)v21.configuration + 4) = 0;
  HIDWORD(v21.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process_downsample_frame", 0, v21, 0);
  vostok::render::effect_compiler::set_texture(
    v5,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v6, (int)compiler, 0, 0, v24);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&v22.0 = "post_process_downsample_frame_blur";
  *(unsigned __int64 *)((char *)v22.configuration + 4) = 0;
  HIDWORD(v22.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "post_process_downsample_frame", 0, v22, 0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_frame_color",
    "$user$final_frame_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v12, (int)compiler, 0, 0, v25);
  vostok::render::effect_compiler::end_pass(v13, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v15, (int)compiler);
  v27 = 0x80000;
  *(_DWORD *)&v23.0 = "post_process_downsample_frame_blur";
  *(unsigned __int64 *)((char *)v23.configuration + 4) = 0;
  HIDWORD(v23.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v16, (int)compiler, "post_process_downsample_frame", 0, v23, 0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_frame_color",
    "$user$final_frame_downsampled_temp",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 0, 0, v26);
  vostok::render::effect_compiler::end_pass(v19, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

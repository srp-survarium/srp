void __thiscall vostok::render::effect_complex_post_process_blend<1,1>::compile(
        vostok::render::effect_complex_post_process_blend<1,1> *this,
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
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::shader_configuration v27; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  __int64 v29; // [esp+1Ch] [ebp-8h]

  v29 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v27.0 = "complex_post_process_blend";
  *(unsigned __int64 *)((char *)v27.configuration + 4) = 0x300000000000LL;
  HIDWORD(v27.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "copy_image", 0, v27, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_bright_pixels_2x",
    "$user$bright_pixels_2x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_bloom_4x",
    "$user$bloom_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_bloom_8x",
    "$user$bloom_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_bloom_16x",
    "$user$bloom_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_bloom_temp_4x",
    "$user$bloom_temp_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_bloom_temp_8x",
    "$user$bloom_temp_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_bloom_temp_16x",
    "$user$bloom_temp_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_bloom_combine",
    "$user$bloom_combine",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_frame_luminance",
    "$user$frame_luminance",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_light_scattering_mask",
    "$user$light_scattering_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_light_scattering_result",
    "$user$light_scattering_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_sphere_falloff",
    "fx/sphere_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_bokeh_image",
    "fx/bokeh_image",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_lighting_buffer",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_lens_flares",
    "$user$lens_flares",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_hiz_depth",
    "$user$hiz_occlusion_depth_mips",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v24,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_complex_post_process_blend<1,0>::compile(
        vostok::render::effect_complex_post_process_blend<1,0> *this,
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
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::shader_configuration v27; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  __int64 v29; // [esp+1Ch] [ebp-8h]

  v29 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v27.0 = "complex_post_process_blend";
  *(unsigned __int64 *)((char *)v27.configuration + 4) = 0x100000000000LL;
  HIDWORD(v27.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "copy_image", 0, v27, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_bright_pixels_2x",
    "$user$bright_pixels_2x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_bloom_4x",
    "$user$bloom_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_bloom_8x",
    "$user$bloom_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_bloom_16x",
    "$user$bloom_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_bloom_temp_4x",
    "$user$bloom_temp_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_bloom_temp_8x",
    "$user$bloom_temp_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_bloom_temp_16x",
    "$user$bloom_temp_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_bloom_combine",
    "$user$bloom_combine",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_frame_luminance",
    "$user$frame_luminance",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_light_scattering_mask",
    "$user$light_scattering_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_light_scattering_result",
    "$user$light_scattering_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_sphere_falloff",
    "fx/sphere_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_bokeh_image",
    "fx/bokeh_image",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_lighting_buffer",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_lens_flares",
    "$user$lens_flares",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_hiz_depth",
    "$user$hiz_occlusion_depth_mips",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v24,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_complex_post_process_blend<0,0>::compile(
        vostok::render::effect_complex_post_process_blend<0,0> *this,
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
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::shader_configuration v27; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v28; // [esp+4h] [ebp-20h]
  __int64 v29; // [esp+1Ch] [ebp-8h]

  v29 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v27.0 = "complex_post_process_blend";
  *(unsigned __int64 *)((char *)v27.configuration + 4) = 0;
  HIDWORD(v27.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "copy_image", 0, v27, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v28);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_bright_pixels_2x",
    "$user$bright_pixels_2x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_bloom_4x",
    "$user$bloom_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_bloom_8x",
    "$user$bloom_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_bloom_16x",
    "$user$bloom_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_bloom_temp_4x",
    "$user$bloom_temp_4x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_bloom_temp_8x",
    "$user$bloom_temp_8x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_bloom_temp_16x",
    "$user$bloom_temp_16x",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_bloom_combine",
    "$user$bloom_combine",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_frame_luminance",
    "$user$frame_luminance",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v17,
    (const char *)compiler,
    "t_light_scattering_mask",
    "$user$light_scattering_mask",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_light_scattering_result",
    "$user$light_scattering_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v19,
    (const char *)compiler,
    "t_sphere_falloff",
    "fx/sphere_falloff",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_bokeh_image",
    "fx/bokeh_image",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v21,
    (const char *)compiler,
    "t_lighting_buffer",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_lens_flares",
    "$user$lens_flares",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v23,
    (const char *)compiler,
    "t_hiz_depth",
    "$user$hiz_occlusion_depth_mips",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::color_write_enable(
    v24,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v25, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v26,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

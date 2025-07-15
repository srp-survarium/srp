void __thiscall vostok::render::effect_aberration_and_sharpen<1,1,1>::compile(
        vostok::render::effect_aberration_and_sharpen<1,1,1> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 537395200;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 8912896;
  HIDWORD(v11.configuration[1]) = 537395200;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<1,1,0>::compile(
        vostok::render::effect_aberration_and_sharpen<1,1,0> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 8912896;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<1,0,1>::compile(
        vostok::render::effect_aberration_and_sharpen<1,0,1> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 537395200;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0x80000;
  HIDWORD(v11.configuration[1]) = 537395200;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<1,0,0>::compile(
        vostok::render::effect_aberration_and_sharpen<1,0,0> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0x80000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<0,1,1>::compile(
        vostok::render::effect_aberration_and_sharpen<0,1,1> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 537395200;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0x800000;
  HIDWORD(v11.configuration[1]) = 537395200;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<0,1,0>::compile(
        vostok::render::effect_aberration_and_sharpen<0,1,0> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0x800000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<0,0,1>::compile(
        vostok::render::effect_aberration_and_sharpen<0,0,1> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 537395200;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  HIDWORD(v11.configuration[1]) = 537395200;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}


void __thiscall vostok::render::effect_aberration_and_sharpen<0,0,0>::compile(
        vostok::render::effect_aberration_and_sharpen<0,0,0> *this,
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
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-2Ch]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-18h]
  __int64 v13; // [esp+14h] [ebp-8h]

  v13 = 0x80000;
  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "aberration";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "aberration", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_frame_color_downsampled",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v13 & 0x20000000) != 0 )
    vostok::render::effect_compiler::set_texture(
      v8,
      (const char *)compiler,
      "t_grain_noise",
      "engine/noise_64x64",
      0,
      0xFFFFFFFF,
      0,
      1.0);
  vostok::render::effect_compiler::color_write_enable(
    v8,
    (int)compiler,
    0,
    D3D11_COLOR_WRITE_ENABLE_BLUE|D3D11_COLOR_WRITE_ENABLE_GREEN|D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

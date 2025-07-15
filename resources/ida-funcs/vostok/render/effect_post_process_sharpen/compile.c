void __thiscall vostok::render::effect_post_process_sharpen::compile(
        vostok::render::effect_post_process_sharpen *this,
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
  vostok::render::shader_configuration v15; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v16; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v17; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v18; // [esp+4h] [ebp-20h]
  __int64 v19; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v15.0 = "post_process_pre_sharpen";
  *(unsigned __int64 *)((char *)v15.configuration + 4) = 0;
  HIDWORD(v15.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process_sharpen", 0, v15, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v17);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic0",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v7, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v8,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v9, (int)compiler);
  *(_DWORD *)&v16.0 = "post_process_post_sharpen";
  v19 = 0x80000;
  *(unsigned __int64 *)((char *)v16.configuration + 4) = 0;
  HIDWORD(v16.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "post_process_sharpen", 0, v16, 0);
  vostok::render::effect_compiler::set_depth(v11, (int)compiler, 0, 0, v18);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_frame_color",
    "$user$generic1",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v13, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v14,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

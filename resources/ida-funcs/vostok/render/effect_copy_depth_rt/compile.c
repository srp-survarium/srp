void __thiscall vostok::render::effect_copy_depth_rt::compile(
        vostok::render::effect_copy_depth_rt *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::shader_configuration v13; // [esp-14h] [ebp-30h]
  D3D11_COMPARISON_FUNC v14; // [esp+0h] [ebp-1Ch]
  D3D11_BLEND_OP v15; // [esp+0h] [ebp-1Ch]
  D3D11_STENCIL_OP v16; // [esp+0h] [ebp-1Ch]
  __int64 v17; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v13.0 = "copy_depth_rt";
  v17 = 0x80000;
  *(unsigned __int64 *)((char *)v13.configuration + 4) = 0;
  HIDWORD(v13.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "post_process0", 0, v13, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v14);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v7);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v15);
  vostok::render::effect_compiler::set_stencil(
    v9,
    (int)compiler,
    1,
    0,
    0xFFu,
    0,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v16);
  vostok::render::effect_compiler::color_write_enable(v10, (int)compiler, 0, D3D11_COLOR_WRITE_ENABLE_RED);
  vostok::render::effect_compiler::end_pass(v11, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v12,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

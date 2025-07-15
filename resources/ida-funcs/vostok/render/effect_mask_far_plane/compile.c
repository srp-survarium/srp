void __thiscall vostok::render::effect_mask_far_plane::compile(
        vostok::render::effect_mask_far_plane *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::shader_configuration v11; // [esp-14h] [ebp-30h]
  D3D11_COMPARISON_FUNC v12; // [esp+0h] [ebp-1Ch]
  D3D11_STENCIL_OP v13; // [esp+0h] [ebp-1Ch]
  __int64 v14; // [esp+14h] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  v14 = 0x80000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "mask_far_plane";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "mask_far_plane", 0, v11, 0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v5);
  vostok::render::effect_compiler::set_depth(v6, (int)compiler, 1, 0, v12);
  vostok::render::effect_compiler::set_stencil(
    v7,
    (int)compiler,
    1,
    0,
    0xFFu,
    240,
    D3D11_COMPARISON_NOT_EQUAL,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v13);
  vostok::render::effect_compiler::color_write_enable(v8, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

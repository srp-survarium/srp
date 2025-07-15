void __thiscall vostok::render::effect_grass_trample::compile(
        vostok::render::effect_grass_trample *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::shader_configuration v11; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v12; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v13; // [esp+4h] [ebp-20h]
  __int64 v14; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v11.configuration + 4) = 0;
  v14 = 0x80000;
  HIDWORD(v11.configuration[1]) = 0x80000;
  *(_DWORD *)&v11.0 = "grass_trample";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "grass_trample", 0, v11, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v12);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v6);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_trample_template",
    "engine/grass_trample_template",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v8,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v13);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

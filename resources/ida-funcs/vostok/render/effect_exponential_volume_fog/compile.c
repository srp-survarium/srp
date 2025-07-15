void __thiscall vostok::render::effect_exponential_volume_fog::compile(
        vostok::render::effect_exponential_volume_fog *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::command_line::key *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::shader_configuration v12; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v13; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v14; // [esp+4h] [ebp-20h]
  __int64 v15; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(unsigned __int64 *)((char *)v12.configuration + 4) = 0;
  v15 = 0x80000;
  HIDWORD(v12.configuration[1]) = 0x80000;
  *(_DWORD *)&v12.0 = "volume_fog";
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "volume_fog", 0, v12, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 0, v13);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v6);
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
    "t_fog_noise",
    "engine/volume_fog_noise",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v9,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v14);
  vostok::render::effect_compiler::end_pass(v10, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v11,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

void __thiscall vostok::render::effect_particle_selection::compile(
        vostok::render::effect_particle_selection *this,
        vostok::render::effect_compiler *compiler,
        vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::enum_vertex_input_type v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::command_line::key *v9; // ecx
  vostok::render::effect_material_base *v10; // ecx
  vostok::render::shader_configuration *v11; // [esp+0h] [ebp-28h]
  D3D11_COMPARISON_FUNC v12; // [esp+0h] [ebp-28h]
  D3D11_BLEND_OP v13; // [esp+0h] [ebp-28h]
  const vostok::configs::binary_config_value *v14; // [esp+4h] [ebp-24h]
  unsigned int i; // [esp+8h] [ebp-20h]
  vostok::render::enum_vertex_input_type type[3]; // [esp+Ch] [ebp-1Ch]
  char pixel_shader_name[4]; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch]
  int v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]

  type[0] = particle_vertex_input_type;
  type[1] = particle_subuv_vertex_input_type;
  type[2] = particle_beamtrail_vertex_input_type;
  for ( i = 0; i < 3; ++i )
  {
    v4 = type[i];
    v19 = 0x80000;
    *(_DWORD *)pixel_shader_name = 0;
    v18 = 0;
    v20 = 0;
    BYTE2(v18) = vostok::render::vertex_input_type_to_index(v4) & 0x3F;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v5,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "particle_selected",
      (char *)compiler,
      pixel_shader_name,
      config,
      v11,
      v14);
    vostok::render::effect_compiler::set_depth(v6, (int)compiler, 1, 0, v12);
    vostok::render::effect_compiler::set_cull_mode(
      compiler,
      (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
      v7);
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
    vostok::render::effect_compiler::set_fill_mode(
      compiler,
      (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
      v9);
    vostok::render::effect_material_base::compile_end(v10, compiler);
  }
}

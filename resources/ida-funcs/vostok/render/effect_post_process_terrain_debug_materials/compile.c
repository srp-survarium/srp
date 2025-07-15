void __thiscall vostok::render::effect_post_process_terrain_debug_materials::compile(
        vostok::render::effect_post_process_terrain_debug_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::command_line::key *v7; // ecx
  vostok::command_line::key *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  char **v15; // eax
  vostok::render::effect_compiler *v16; // ecx
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  _DWORD *pointer; // esi
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  vostok::render::effect_constant_storage *v22; // ecx
  float v23; // xmm0_4
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4
  vostok::configs::binary_config_value *v27; // eax
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  vostok::configs::binary_config_value *v30; // eax
  const vostok::configs::binary_config_value *v31; // eax
  vostok::render::effect_constant_storage *v32; // ecx
  float v33; // xmm0_4
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::render::effect_compiler *v36; // ecx
  vostok::render::shader_configuration v37; // [esp-10h] [ebp-4Ch]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-38h]
  D3D11_STENCIL_OP v39; // [esp+4h] [ebp-38h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-38h]
  float v41; // [esp+14h] [ebp-28h]
  float v42; // [esp+18h] [ebp-24h]
  vostok::math::float4 v43; // [esp+1Ch] [ebp-20h] BYREF
  __int64 v44; // [esp+2Ch] [ebp-10h]
  unsigned int v45; // [esp+34h] [ebp-8h]
  int v46; // [esp+38h] [ebp-4h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v37.0 = "terrain_debug";
  *(_QWORD *)&v43.x = 0;
  *(_QWORD *)&v43.elements[2] = 0x80000;
  *(unsigned __int64 *)((char *)v37.configuration + 4) = 0;
  HIDWORD(v37.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "copy_image", 0, v37, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_stencil(
    v6,
    (int)compiler,
    1,
    0x80u,
    0x80u,
    0,
    D3D11_COMPARISON_EQUAL,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    v39);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v7);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v8);
  vostok::render::effect_compiler::set_texture(
    v9,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v10,
    (const char *)compiler,
    "t_normal",
    "$user$normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_parameters",
    "$user$surface_parameters",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v12,
    (const char *)compiler,
    "t_decals_diffuse",
    "$user$decals_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v13,
    (const char *)compiler,
    "t_decals_normal",
    "$user$decals_normal",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  v14 = vostok::configs::binary_config_value::operator[](config, "texture_gradient");
  v15 = (char **)vostok::configs::binary_config_value::operator[](v14, "value");
  vostok::render::effect_compiler::set_texture(v16, (const char *)compiler, "t_gradient", *v15, 0, 0xFFFFFFFF, 0, 1.0);
  v17 = vostok::configs::binary_config_value::operator[](config, "constant_deepening_color");
  v18 = vostok::configs::binary_config_value::operator[](v17, "value");
  pointer = v18->data.pointer;
  LODWORD(v44) = *(_DWORD *)v18->data.pointer;
  HIDWORD(v44) = *++pointer;
  v45 = *++pointer;
  v46 = pointer[1];
  v20 = vostok::configs::binary_config_value::operator[](config, "constant_deepening_range");
  v21 = vostok::configs::binary_config_value::operator[](v20, "value");
  if ( v21->type == 2 )
    v23 = *(float *)&v21->data.pointer;
  else
    v23 = (float)(int)v21->data.pointer;
  *(_QWORD *)&v43.x = v44;
  *(_QWORD *)&v43.elements[2] = __PAIR64__(LODWORD(v23), v45);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v43, v22, compiler, "deepening_color_and_range");
  v24 = vostok::configs::binary_config_value::operator[](config, "constant_deepening_power");
  v25 = vostok::configs::binary_config_value::operator[](v24, "value");
  if ( v25->type == 2 )
    v26 = *(float *)&v25->data.pointer;
  else
    v26 = (float)(int)v25->data.pointer;
  v42 = v26;
  v27 = vostok::configs::binary_config_value::operator[](config, "constant_deepening_scale");
  v28 = vostok::configs::binary_config_value::operator[](v27, "value");
  if ( v28->type == 2 )
    v29 = *(float *)&v28->data.pointer;
  else
    v29 = (float)(int)v28->data.pointer;
  v41 = v29;
  v30 = vostok::configs::binary_config_value::operator[](config, "constant_deepening_clip_dist");
  v31 = vostok::configs::binary_config_value::operator[](v30, "value");
  if ( v31->type == 2 )
    v33 = *(float *)&v31->data.pointer;
  else
    v33 = (float)(int)v31->data.pointer;
  *(_QWORD *)&v43.x = __PAIR64__(LODWORD(v41), LODWORD(v33));
  *(_QWORD *)&v43.elements[2] = LODWORD(v42);
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v43, v32, compiler, "deepening_parameters");
  vostok::render::effect_compiler::set_alpha_blend(
    v34,
    (int)compiler,
    0,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::end_pass(v35, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v36,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}

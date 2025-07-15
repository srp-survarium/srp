void __thiscall vostok::render::depth_accumulate_material_effect::compile(
        vostok::render::depth_accumulate_material_effect *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  unsigned int vertex_input_type; // ecx
  int v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // eax
  bool v8; // al
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  char **v13; // eax
  vostok::render::effect_compiler *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  const vostok::configs::binary_config_value *v16; // eax
  float pointer; // xmm0_4
  float *v18; // eax
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::command_line::key *v25; // ecx
  vostok::render::effect_material_base *v26; // ecx
  vostok::configs::binary_config_value *v27; // ecx
  bool v28; // al
  vostok::configs::binary_config_value *v29; // eax
  char **v30; // eax
  vostok::render::effect_compiler *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  vostok::configs::binary_config_value *v35; // ecx
  vostok::configs::binary_config_value *v36; // eax
  const vostok::configs::binary_config_value *v37; // eax
  float v38; // xmm0_4
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_compiler *v40; // ecx
  vostok::command_line::key *v41; // ecx
  vostok::render::effect_material_base *v42; // ecx
  vostok::render::shader_configuration *v43; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v44; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v45; // [esp+4h] [ebp-38h]
  const vostok::configs::binary_config_value *v46; // [esp+8h] [ebp-34h]
  bool v47; // [esp+13h] [ebp-29h]
  bool v48; // [esp+13h] [ebp-29h]
  unsigned int i; // [esp+14h] [ebp-28h]
  float v50; // [esp+18h] [ebp-24h] BYREF
  unsigned int num_last_mips_used; // [esp+1Ch] [ebp-20h]
  unsigned int streaming_priority; // [esp+20h] [ebp-1Ch]
  float v53; // [esp+24h] [ebp-18h] BYREF
  float v54; // [esp+28h] [ebp-14h] BYREF
  char pixel_shader_name[4]; // [esp+2Ch] [ebp-10h] BYREF
  int v56; // [esp+30h] [ebp-Ch]
  int v57; // [esp+34h] [ebp-8h]
  int v58; // [esp+38h] [ebp-4h]

  vertex_input_type = parameters->vertex_input_type;
  if ( parameters->vertex_input_type < 0xF )
    v5 = 1 << vertex_input_type;
  else
    v5 = -1;
  LOBYTE(num_last_mips_used) = v5 != 2048;
  v57 = 0x80000;
  *(_DWORD *)pixel_shader_name = 0;
  v56 = 0;
  v58 = 0;
  streaming_priority = v5 == 2048 ? -1 : 5;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)vertex_input_type,
         (int)config,
         (unsigned int)"use_alpha_test") )
  {
    v7 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v8 = vostok::configs::binary_config_value::operator[](v7, "value")->data.pointer != 0;
  }
  else
  {
    v8 = 0;
  }
  pixel_shader_name[2] = 16 * v8;
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)config, (unsigned int)"wind_motion") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "wind_motion");
    HIBYTE(v56) ^= (HIBYTE(v56)
                  ^ (4 * LOBYTE(vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer)))
                 & 0x1C;
  }
  v50 = FLOAT_0_25;
  for ( i = 0; i < 2; ++i )
  {
    HIBYTE(v57) ^= (HIBYTE(v57) ^ (16 * (i == 1))) & 0x10;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      v9,
      (vostok::render::effect_material_base *)&stru_812A60,
      "depth_accumulate",
      (char *)compiler,
      pixel_shader_name,
      config,
      v43,
      v46);
    v47 = (pixel_shader_name[2] & 0x10) != 0;
    if ( (pixel_shader_name[2] & 0x10) != 0 )
    {
      v12 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
      v13 = (char **)vostok::configs::binary_config_value::operator[](v12, "value");
      vostok::render::effect_compiler::set_texture(
        v14,
        (const char *)compiler,
        "t_base",
        *v13,
        num_last_mips_used,
        streaming_priority,
        0,
        1.0);
    }
    if ( (v56 & 0x1C000000) != 0
      && vostok::configs::binary_config_value::value_exists(v11, (int)config, (unsigned int)"wind_scale") )
    {
      v15 = vostok::configs::binary_config_value::operator[](config, "wind_scale");
      v16 = vostok::configs::binary_config_value::operator[](v15, "value");
      if ( v16->type == 2 )
        pointer = *(float *)&v16->data.pointer;
      else
        pointer = (float)(int)v16->data.pointer;
      v53 = pointer;
      v18 = &v53;
    }
    else
    {
      v54 = s_bm_current_air_resistance;
      v18 = &v54;
    }
    vostok::render::effect_compiler::set_constant<float>(
      (vostok::render::effect_constant_storage *)v11,
      v18,
      compiler,
      "wind_scale");
    if ( v47 && vostok::configs::binary_config_value::value_exists(v19, (int)config, (unsigned int)"alpha_ref") )
    {
      v20 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
      v21 = vostok::configs::binary_config_value::operator[](v20, "value");
      if ( v21->type == 2 )
        v22 = *(float *)&v21->data.pointer;
      else
        v22 = (float)(int)v21->data.pointer;
      v50 = v22;
    }
    vostok::render::effect_compiler::set_constant<float>(
      (vostok::render::effect_constant_storage *)v19,
      &v50,
      compiler,
      "alpha_ref_parameter");
    vostok::render::effect_compiler::set_depth(v23, (int)compiler, 1, 1, v44);
    vostok::render::effect_compiler::color_write_enable(v24, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
    vostok::render::effect_compiler::set_cull_mode(
      compiler,
      (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
      v25);
    vostok::render::effect_material_base::compile_end(v26, compiler);
  }
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v9,
    (vostok::render::effect_material_base *)&stru_812A9C,
    "depth_accumulate_batched",
    (char *)compiler,
    pixel_shader_name,
    config,
    v43,
    v46);
  v28 = (pixel_shader_name[2] & 0x10) != 0;
  v48 = v28;
  if ( (pixel_shader_name[2] & 0x10) != 0 )
  {
    v29 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v30 = (char **)vostok::configs::binary_config_value::operator[](v29, "value");
    vostok::render::effect_compiler::set_texture(
      v31,
      (const char *)compiler,
      "t_base",
      *v30,
      num_last_mips_used,
      streaming_priority,
      0,
      1.0);
    v28 = v48;
  }
  if ( v28 && vostok::configs::binary_config_value::value_exists(v27, (int)config, (unsigned int)"alpha_ref") )
  {
    v32 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    v33 = vostok::configs::binary_config_value::operator[](v32, "value");
    if ( v33->type == 2 )
      v34 = *(float *)&v33->data.pointer;
    else
      v34 = (float)(int)v33->data.pointer;
    v50 = v34;
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v27,
    &v50,
    compiler,
    "alpha_ref_parameter");
  if ( (v56 & 0x1C000000) != 0
    && vostok::configs::binary_config_value::value_exists(v35, (int)config, (unsigned int)"wind_scale") )
  {
    v36 = vostok::configs::binary_config_value::operator[](config, "wind_scale");
    v37 = vostok::configs::binary_config_value::operator[](v36, "value");
    if ( v37->type == 2 )
      v38 = *(float *)&v37->data.pointer;
    else
      v38 = (float)(int)v37->data.pointer;
  }
  else
  {
    v38 = s_bm_current_air_resistance;
  }
  v54 = v38;
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v35,
    &v54,
    compiler,
    "wind_scale");
  vostok::render::effect_compiler::set_depth(v39, (int)compiler, 1, 1, v45);
  vostok::render::effect_compiler::color_write_enable(v40, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v41);
  vostok::render::effect_material_base::compile_end(v42, compiler);
}

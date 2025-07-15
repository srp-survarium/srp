void __thiscall vostok::render::effect_distortion_stage_default_materials::compile(
        vostok::render::effect_distortion_stage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  float **v5; // eax
  float *v6; // esi
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // eax
  char v10; // al
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  bool v13; // al
  vostok::render::effect_compiler *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  char **v16; // eax
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::configs::binary_config_value *v19; // ecx
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  vostok::configs::binary_config_value *v26; // eax
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4
  vostok::configs::binary_config_value *v29; // eax
  const vostok::configs::binary_config_value *v30; // eax
  vostok::render::effect_constant_storage *v31; // ecx
  float v32; // xmm0_4
  vostok::render::effect_constant_storage *v33; // ecx
  vostok::configs::binary_config_value *v34; // eax
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  vostok::render::effect_compiler *v37; // ecx
  vostok::render::effect_compiler *v38; // ecx
  vostok::render::effect_material_base *v39; // ecx
  vostok::render::shader_configuration *v40; // [esp+4h] [ebp-48h]
  D3D11_STENCIL_OP v41; // [esp+4h] [ebp-48h]
  D3D11_COMPARISON_FUNC v42; // [esp+4h] [ebp-48h]
  D3D11_BLEND_OP v43; // [esp+4h] [ebp-48h]
  const vostok::configs::binary_config_value *v44; // [esp+8h] [ebp-44h]
  float v45; // [esp+10h] [ebp-3Ch]
  __int64 v46; // [esp+14h] [ebp-38h]
  float v47; // [esp+1Ch] [ebp-30h] BYREF
  vostok::math::float3 v48; // [esp+20h] [ebp-2Ch] BYREF
  int v49; // [esp+2Ch] [ebp-20h] BYREF
  int v50; // [esp+30h] [ebp-1Ch]
  int v51; // [esp+34h] [ebp-18h]
  int v52; // [esp+38h] [ebp-14h]
  vostok::math::float4 v53; // [esp+3Ch] [ebp-10h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](config, "distortion_scale");
  v5 = (float **)vostok::configs::binary_config_value::operator[](v4, "value");
  v6 = *v5;
  v48.x = **v5;
  *(_QWORD *)&v48.elements[1] = *(_QWORD *)(v6 + 1);
  v51 = 0x80000;
  v49 = 0;
  v50 = 0;
  v52 = 0;
  if ( vostok::configs::binary_config_value::value_exists(
         v7,
         (int)config,
         (unsigned int)"use_angle_depended_attenuation") )
  {
    v9 = vostok::configs::binary_config_value::operator[](config, "use_angle_depended_attenuation");
    v10 = vostok::configs::binary_config_value::operator[](v9, "value")->data.pointer != 0;
  }
  else
  {
    v10 = 0;
  }
  BYTE2(v49) = v10 << 7;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)config, (unsigned int)"use_sequence") )
  {
    v12 = vostok::configs::binary_config_value::operator[](config, "use_sequence");
    v13 = vostok::configs::binary_config_value::operator[](v12, "value")->data.pointer != 0;
  }
  else
  {
    v13 = 0;
  }
  LOBYTE(v50) = (v50 ^ (32 * v13)) & 0x20 ^ v50;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v11,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "distortion_base",
    compiler,
    (const char *)&v49,
    config,
    v40,
    v44);
  vostok::render::effect_compiler::set_stencil(
    v14,
    (int)compiler,
    0,
    0x80u,
    0xFFu,
    255,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_REPLACE,
    D3D11_STENCIL_OP_KEEP,
    v41);
  v15 = vostok::configs::binary_config_value::operator[](config, "texture_distortion");
  v16 = (char **)vostok::configs::binary_config_value::operator[](v15, "value");
  vostok::render::effect_compiler::set_texture(v17, (const char *)compiler, "t_base", *v16, 0, 0xFFFFFFFF, 0, 1.0);
  v47 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_texture(
    v18,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( (v50 & 0x20) != 0 )
  {
    v20 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_play_speed");
    v21 = vostok::configs::binary_config_value::operator[](v20, "value");
    if ( v21->type == 2 )
      pointer = *(float *)&v21->data.pointer;
    else
      pointer = (float)(int)v21->data.pointer;
    *((float *)&v46 + 1) = pointer;
    v23 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_start_frame_index");
    v24 = vostok::configs::binary_config_value::operator[](v23, "value");
    if ( v24->type == 2 )
      v25 = *(float *)&v24->data.pointer;
    else
      v25 = (float)(int)v24->data.pointer;
    *(float *)&v46 = v25;
    v26 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_height");
    v27 = vostok::configs::binary_config_value::operator[](v26, "value");
    if ( v27->type == 2 )
      v28 = *(float *)&v27->data.pointer;
    else
      v28 = (float)(int)v27->data.pointer;
    v45 = v28;
    v29 = vostok::configs::binary_config_value::operator[](config, "constant_sequence_array_width");
    v30 = vostok::configs::binary_config_value::operator[](v29, "value");
    if ( v30->type == 2 )
      v32 = *(float *)&v30->data.pointer;
    else
      v32 = (float)(int)v30->data.pointer;
    *(_QWORD *)&v53.x = __PAIR64__(LODWORD(v45), LODWORD(v32));
    *(_QWORD *)&v53.elements[2] = v46;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v53, v31, compiler, "sequence_parameters");
  }
  if ( vostok::configs::binary_config_value::value_exists(v19, (int)config, (unsigned int)"attenuation_power") )
  {
    v34 = vostok::configs::binary_config_value::operator[](config, "attenuation_power");
    v35 = vostok::configs::binary_config_value::operator[](v34, "value");
    if ( v35->type == 2 )
      v36 = *(float *)&v35->data.pointer;
    else
      v36 = (float)(int)v35->data.pointer;
    v47 = v36;
  }
  if ( (v49 & 0x800000) != 0 )
    vostok::render::effect_compiler::set_constant<float>(v33, &v47, compiler, "attenuation_power");
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v48, v33, compiler, "distortion_scale");
  vostok::render::effect_compiler::set_depth(v37, (int)compiler, 1, 0, v42);
  vostok::render::effect_compiler::set_alpha_blend(
    v38,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v43);
  vostok::render::effect_material_base::compile_end(v39, compiler);
}

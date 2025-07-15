void __thiscall vostok::render::effect_distortion_stage_panner_materials::compile(
        vostok::render::effect_distortion_stage_panner_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  float **v5; // eax
  float *v6; // esi
  vostok::configs::binary_config_value *v7; // eax
  float **v8; // eax
  float *v9; // esi
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  char v13; // al
  vostok::render::effect_compiler *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  char **v16; // eax
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_constant_storage *v18; // ecx
  vostok::render::effect_constant_storage *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::configs::binary_config_value *v21; // ecx
  vostok::render::effect_constant_storage *v22; // ecx
  vostok::configs::binary_config_value *v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  float pointer; // xmm0_4
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_material_base *v27; // ecx
  vostok::render::shader_configuration *v28; // [esp+4h] [ebp-38h]
  D3D11_STENCIL_OP v29; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v30; // [esp+4h] [ebp-38h]
  D3D11_BLEND_OP v31; // [esp+4h] [ebp-38h]
  const vostok::configs::binary_config_value *v32; // [esp+8h] [ebp-34h]
  float v33; // [esp+10h] [ebp-2Ch] BYREF
  vostok::math::float3 v34; // [esp+14h] [ebp-28h] BYREF
  vostok::math::float3 v35; // [esp+20h] [ebp-1Ch] BYREF
  _DWORD v36[4]; // [esp+2Ch] [ebp-10h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](config, "distortion_scale");
  v5 = (float **)vostok::configs::binary_config_value::operator[](v4, "value");
  v6 = *v5;
  v34.x = **v5;
  *(_QWORD *)&v34.elements[1] = *(_QWORD *)(v6 + 1);
  v7 = vostok::configs::binary_config_value::operator[](config, "panner");
  v8 = (float **)vostok::configs::binary_config_value::operator[](v7, "value");
  v9 = *v8;
  v35.x = **v8;
  *(_QWORD *)&v35.elements[1] = *(_QWORD *)(v9 + 1);
  v36[2] = 0x80000;
  v36[0] = 0;
  v36[1] = 0;
  v36[3] = 0;
  if ( vostok::configs::binary_config_value::value_exists(
         v10,
         (int)config,
         (unsigned int)"use_angle_depended_attenuation") )
  {
    v12 = vostok::configs::binary_config_value::operator[](config, "use_angle_depended_attenuation");
    v13 = vostok::configs::binary_config_value::operator[](v12, "value")->data.pointer != 0;
  }
  else
  {
    v13 = 0;
  }
  BYTE2(v36[0]) = v13 << 7;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v11,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    (const char *)&stru_812504,
    compiler,
    (const char *)v36,
    config,
    v28,
    v32);
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
    v29);
  v15 = vostok::configs::binary_config_value::operator[](config, "texture_distortion");
  v16 = (char **)vostok::configs::binary_config_value::operator[](v15, "value");
  vostok::render::effect_compiler::set_texture(v17, (const char *)compiler, "t_base", *v16, 0, 0xFFFFFFFF, 0, 1.0);
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v34, v18, compiler, "distortion_scale");
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v35, v19, compiler, "move_direction");
  v33 = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_texture(
    v20,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)config, (unsigned int)"attenuation_power") )
  {
    v23 = vostok::configs::binary_config_value::operator[](config, "attenuation_power");
    v24 = vostok::configs::binary_config_value::operator[](v23, "value");
    if ( v24->type == 2 )
      pointer = *(float *)&v24->data.pointer;
    else
      pointer = (float)(int)v24->data.pointer;
    v33 = pointer;
  }
  if ( (v36[0] & 0x800000) != 0 )
    vostok::render::effect_compiler::set_constant<float>(v22, &v33, compiler, "attenuation_power");
  vostok::render::effect_compiler::set_depth((vostok::render::effect_compiler *)v22, (int)compiler, 1, 0, v30);
  vostok::render::effect_compiler::set_alpha_blend(
    v26,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v31);
  vostok::render::effect_material_base::compile_end(v27, compiler);
}

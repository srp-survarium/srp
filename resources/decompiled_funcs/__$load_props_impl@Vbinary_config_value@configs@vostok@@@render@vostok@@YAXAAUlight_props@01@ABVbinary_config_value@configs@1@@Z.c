void __cdecl vostok::render::load_props_impl<vostok::configs::binary_config_value>(
        vostok::render::light_props *props,
        vostok::configs::binary_config_value *t)
{
  const vostok::configs::binary_config_value *v2; // eax
  __int64 v3; // xmm0_8
  float v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  unsigned int v11; // eax
  float *v12; // esi
  const vostok::math::float3 *v13; // edi
  const vostok::math::float4x4 *v14; // eax
  const vostok::math::float4x4 *v15; // eax
  vostok::math::float4x4 *p_dst; // esi
  const void *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  float x; // xmm0_4
  float *v20; // eax
  float v21; // ecx
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  const vostok::configs::binary_config_value *v26; // eax
  float v27; // xmm0_4
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  const vostok::configs::binary_config_value *v30; // eax
  float v31; // xmm0_4
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  bool v34; // al
  bool v35; // al
  bool v36; // al
  bool v37; // al
  bool v38; // al
  const vostok::configs::binary_config_value *v39; // eax
  float v40; // xmm0_4
  vostok::configs::binary_config_value a; // [esp-Ch] [ebp-13Ch] BYREF
  vostok::math::float3 clr; // [esp+1Ch] [ebp-114h]
  const vostok::math::float3 **v43; // [esp+28h] [ebp-108h]
  vostok::math::float4x4 dst; // [esp+2Ch] [ebp-104h] BYREF
  vostok::math::float4x4 v45; // [esp+6Ch] [ebp-C4h] BYREF
  vostok::math::float4x4 left; // [esp+ACh] [ebp-84h] BYREF
  vostok::math::float4x4 result; // [esp+ECh] [ebp-44h] BYREF

  v2 = vostok::configs::binary_config_value::operator[](t, (const char *)&stru_9555EC);
  v3 = *(_QWORD *)v2->data.pointer;
  v4 = *((float *)v2->data.pointer + 2);
  *(_QWORD *)&clr.x = v3;
  clr.z = v4;
  if ( vostok::configs::binary_config_value::value_exists(t, (const char *)&stru_9555EC.configuration[1]) )
    props->does_cast_shadows = vostok::configs::binary_config_value::operator[](
                                 t,
                                 (const char *)&stru_9555EC.configuration[1])->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "sun_shadow_map_size") )
    props->sun_shadow_map_size = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                 t,
                                                 "sun_shadow_map_size")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(t, "shadow_map_size_index") )
    props->shadow_map_size_index = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                   t,
                                                   "shadow_map_size_index")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(t, "num_sun_cascades") )
    props->num_sun_cascades = (unsigned int)vostok::configs::binary_config_value::operator[](t, "num_sun_cascades")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_x") )
    props->shadow_distribution_sides[0] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_x")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_neg_x") )
    props->shadow_distribution_sides[1] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_x")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_y") )
    props->shadow_distribution_sides[2] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_y")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_neg_y") )
    props->shadow_distribution_sides[3] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_y")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_z") )
    props->shadow_distribution_sides[4] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_z")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "is_cast_shadow_neg_z") )
    props->shadow_distribution_sides[5] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_z")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(t, "z_bias") )
  {
    v5 = vostok::configs::binary_config_value::operator[](t, "z_bias");
    if ( v5->type == 2 )
      pointer = *(float *)&v5->data.pointer;
    else
      pointer = (float)(int)v5->data.pointer;
    props->local_light_z_bias = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "shadow_transparency") )
  {
    v7 = vostok::configs::binary_config_value::operator[](t, "shadow_transparency");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    props->shadow_transparency = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(t, "lighting_model") )
    props->lighting_model = (int)vostok::configs::binary_config_value::operator[](t, "lighting_model")->data.pointer;
  else
    props->lighting_model = 1;
  v9 = vostok::configs::binary_config_value::operator[](t, "range");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  *(float *)&a.type = 1.0;
  props->range = v10;
  v11 = vostok::math::color_rgba(clr.z, (vostok::math *)LODWORD(clr.x), clr.y, *(float *)&a.type);
  *(_DWORD *)&a.type = "scale";
  props->color = v11;
  if ( vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type)
    && vostok::configs::binary_config_value::value_exists(t, "rotation")
    && vostok::configs::binary_config_value::value_exists(t, "position") )
  {
    v12 = (float *)vostok::configs::binary_config_value::operator[](t, "scale")->data.pointer;
    v13 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "rotation")->data.pointer;
    v43 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](t, "position");
    memset((unsigned __int8 *)&dst, 0, sizeof(dst));
    dst.i.x = *v12;
    dst.j.y = v12[1];
    dst.k.z = v12[2];
    LODWORD(dst.c.w) = clear_value;
    v14 = vostok::math::create_rotation(&result, v13);
    vostok::math::mul4x3(&left, &dst, v14);
    v15 = vostok::math::create_translation(&v45, *v43);
    vostok::math::mul4x3(&dst, &left, v15);
    p_dst = &dst;
  }
  else
  {
    p_dst = vostok::math::float4x4::identity(&v45);
  }
  qmemcpy(props, p_dst, 0x40u);
  v17 = vostok::configs::binary_config_value::operator[](t, "light_type")->data.pointer;
  *(_DWORD *)&a.type = &stru_955728;
  props->type = (vostok::render::light_type)v17;
  if ( vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type) )
  {
    v18 = vostok::configs::binary_config_value::operator[](t, (const char *)&stru_955728);
    if ( v18->type == 2 )
      x = *(float *)&v18->data.pointer;
    else
      x = (float)(int)v18->data.pointer;
  }
  else
  {
    v20 = (float *)vostok::configs::binary_config_value::operator[](t, "attenuation")->data.pointer;
    v21 = v20[2];
    *(_QWORD *)&clr.x = *(_QWORD *)v20;
    x = clr.x;
    clr.z = v21;
  }
  *(_DWORD *)&a.type = "intensity";
  props->attenuation_power = x;
  v22 = vostok::configs::binary_config_value::operator[](t, *(const char **)&a.type);
  if ( v22->type == 2 )
    v23 = *(float *)&v22->data.pointer;
  else
    v23 = (float)(int)v22->data.pointer;
  *(_DWORD *)&a.type = "spot_umbra_angle";
  props->intensity = v23;
  v24 = vostok::configs::binary_config_value::operator[](t, *(const char **)&a.type);
  if ( v24->type == 2 )
    v25 = *(float *)&v24->data.pointer;
  else
    v25 = (float)(int)v24->data.pointer;
  *(_DWORD *)&a.type = "spot_penumbra_angle";
  props->spot_umbra_angle = v25;
  v26 = vostok::configs::binary_config_value::operator[](t, *(const char **)&a.type);
  if ( v26->type == 2 )
    v27 = *(float *)&v26->data.pointer;
  else
    v27 = (float)(int)v26->data.pointer;
  *(_DWORD *)&a.type = "spot_falloff";
  props->spot_penumbra_angle = v27;
  v28 = vostok::configs::binary_config_value::operator[](t, *(const char **)&a.type);
  if ( v28->type == 2 )
    v29 = *(float *)&v28->data.pointer;
  else
    v29 = (float)(int)v28->data.pointer;
  *(_DWORD *)&a.type = "diffuse_influence_factor";
  props->spot_falloff = v29;
  if ( vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type) )
  {
    v30 = vostok::configs::binary_config_value::operator[](t, "diffuse_influence_factor");
    if ( v30->type == 2 )
      v31 = *(float *)&v30->data.pointer;
    else
      v31 = (float)(int)v30->data.pointer;
  }
  else
  {
    v31 = *(float *)&clear_value;
  }
  *(_DWORD *)&a.type = "specular_influence_factor";
  props->diffuse_influence_factor = v31;
  if ( vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type) )
  {
    v32 = vostok::configs::binary_config_value::operator[](t, "specular_influence_factor");
    if ( v32->type == 2 )
      v33 = *(float *)&v32->data.pointer;
    else
      v33 = (float)(int)v32->data.pointer;
  }
  else
  {
    v33 = *(float *)&clear_value;
  }
  *(_DWORD *)&a.type = "is_shadower";
  props->specular_influence_factor = v33;
  v34 = vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type)
     && vostok::configs::binary_config_value::operator[](t, "is_shadower")->data.pointer != 0;
  *(_DWORD *)&a.type = "use_with_lpv";
  props->shadower = v34;
  v35 = vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type)
     && vostok::configs::binary_config_value::operator[](t, "use_with_lpv")->data.pointer != 0;
  *(_DWORD *)&a.type = "enabled";
  props->use_with_lpv = v35;
  v36 = !vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type)
     || vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  *(_DWORD *)&a.type = "static_shadows";
  props->enabled = v36;
  v37 = vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type)
     && vostok::configs::binary_config_value::operator[](t, "static_shadows")->data.pointer != 0;
  *(_DWORD *)&a.type = "is_light_animated";
  props->static_shadows = v37;
  if ( vostok::configs::binary_config_value::value_exists(t, *(const char **)&a.type) )
  {
    v38 = vostok::configs::binary_config_value::operator[](t, "is_light_animated")->data.pointer != 0;
    props->is_light_animated = v38;
    if ( v38 )
    {
      a = *vostok::configs::binary_config_value::operator[](t, "color_curve");
      vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
        (vostok::math::curve_line_color *)&a,
        a);
      v39 = vostok::configs::binary_config_value::operator[](t, "light_animation_length");
      if ( v39->type == 2 )
        v40 = *(float *)&v39->data.pointer;
      else
        v40 = (float)(int)v39->data.pointer;
      props->light_animation_length = v40;
    }
  }
  else
  {
    props->is_light_animated = 0;
  }
}

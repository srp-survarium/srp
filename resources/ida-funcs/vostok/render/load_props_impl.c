void __cdecl vostok::render::load_props_impl<vostok::configs::binary_config_value>(
        vostok::memory::base_allocator *allocator,
        vostok::render::light_props *props,
        const vostok::configs::binary_config_value *t)
{
  vostok::math ***v4; // eax
  vostok::math **v5; // esi
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // ecx
  vostok::configs::binary_config_value *v17; // ecx
  const vostok::configs::binary_config_value *v18; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v20; // ecx
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  vostok::configs::binary_config_value *v25; // ecx
  vostok::math::float4x4 *v26; // ecx
  vostok::math::float4x4 *v27; // eax
  vostok::math::float4x4 *v28; // eax
  vostok::math::float4x4 *v29; // esi
  vostok::configs::binary_config_value *v30; // esi
  vostok::configs::binary_config_value *v31; // ecx
  const vostok::configs::binary_config_value *v32; // eax
  float v33; // xmm0_4
  vostok::math ***v34; // eax
  vostok::math **v35; // esi
  const vostok::configs::binary_config_value *v36; // eax
  float v37; // xmm0_4
  const vostok::configs::binary_config_value *v38; // eax
  float v39; // xmm0_4
  const vostok::configs::binary_config_value *v40; // eax
  float v41; // xmm0_4
  const vostok::configs::binary_config_value *v42; // eax
  vostok::configs::binary_config_value *v43; // ecx
  float v44; // xmm0_4
  vostok::configs::binary_config_value *v45; // ecx
  const vostok::configs::binary_config_value *v46; // eax
  float v47; // xmm0_4
  vostok::configs::binary_config_value *v48; // ecx
  const vostok::configs::binary_config_value *v49; // eax
  float v50; // xmm0_4
  vostok::configs::binary_config_value *v51; // ecx
  bool v52; // al
  vostok::configs::binary_config_value *v53; // ecx
  bool v54; // al
  vostok::configs::binary_config_value *v55; // ecx
  bool v56; // al
  vostok::configs::binary_config_value *v57; // ecx
  bool v58; // al
  bool v59; // al
  const vostok::configs::binary_config_value *v60; // eax
  float v61; // xmm0_4
  _BYTE v62[28]; // [esp-10h] [ebp-180h] BYREF
  vostok::math::float4x4 v63; // [esp+18h] [ebp-158h] BYREF
  _BYTE v64[64]; // [esp+58h] [ebp-118h] BYREF
  vostok::math::float4x4 v65; // [esp+98h] [ebp-D8h] BYREF
  vostok::math::float4x4 v66; // [esp+D8h] [ebp-98h] BYREF
  vostok::math::float4x4 v67; // [esp+118h] [ebp-58h] BYREF
  vostok::math *v68; // [esp+158h] [ebp-18h]
  float v69; // [esp+15Ch] [ebp-14h]
  float v70; // [esp+160h] [ebp-10h]
  const vostok::math::float3 *v71; // [esp+164h] [ebp-Ch]
  const vostok::math::float3 **v72; // [esp+168h] [ebp-8h]
  const vostok::math::float3 *config_4; // [esp+17Ch] [ebp+Ch]
  vostok::math::float4x4 *config_4a; // [esp+17Ch] [ebp+Ch]

  v4 = (vostok::math ***)vostok::configs::binary_config_value::operator[](t, "color");
  v5 = *v4;
  v68 = **v4;
  LODWORD(v69) = *++v5;
  v70 = *((float *)v5 + 1);
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)t, (unsigned int)"is_cast_shadow") )
    props->does_cast_shadows = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)t, (unsigned int)"sun_shadow_map_size") )
    props->sun_shadow_map_size = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                 t,
                                                 "sun_shadow_map_size")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v8, (int)t, (unsigned int)"shadow_map_size_index") )
    props->shadow_map_size_index = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                   t,
                                                   "shadow_map_size_index")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)t, (unsigned int)"num_sun_cascades") )
    props->num_sun_cascades = (unsigned int)vostok::configs::binary_config_value::operator[](t, "num_sun_cascades")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v10, (int)t, (unsigned int)"is_cast_shadow_x") )
    props->shadow_distribution_sides[0] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_x")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v11, (int)t, (unsigned int)"is_cast_shadow_neg_x") )
    props->shadow_distribution_sides[1] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_x")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)t, (unsigned int)"is_cast_shadow_y") )
    props->shadow_distribution_sides[2] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_y")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)t, (unsigned int)"is_cast_shadow_neg_y") )
    props->shadow_distribution_sides[3] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_y")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v14, (int)t, (unsigned int)"is_cast_shadow_z") )
    props->shadow_distribution_sides[4] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_z")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)t, (unsigned int)"is_cast_shadow_neg_z") )
    props->shadow_distribution_sides[5] = vostok::configs::binary_config_value::operator[](t, "is_cast_shadow_neg_z")->data.pointer != 0;
  if ( vostok::configs::binary_config_value::value_exists(v16, (int)t, (unsigned int)"z_bias") )
  {
    v18 = vostok::configs::binary_config_value::operator[](t, "z_bias");
    if ( v18->type == 2 )
      pointer = *(float *)&v18->data.pointer;
    else
      pointer = (float)(int)v18->data.pointer;
    props->local_light_z_bias = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v17, (int)t, (unsigned int)"shadow_transparency") )
  {
    v21 = vostok::configs::binary_config_value::operator[](t, "shadow_transparency");
    if ( v21->type == 2 )
      v22 = *(float *)&v21->data.pointer;
    else
      v22 = (float)(int)v21->data.pointer;
    props->shadow_transparency = v22;
  }
  if ( vostok::configs::binary_config_value::value_exists(v20, (int)t, (unsigned int)"lighting_model") )
    props->lighting_model = (int)vostok::configs::binary_config_value::operator[](t, "lighting_model")->data.pointer;
  else
    props->lighting_model = 1;
  v23 = vostok::configs::binary_config_value::operator[](t, "range");
  if ( v23->type == 2 )
    v24 = *(float *)&v23->data.pointer;
  else
    v24 = (float)(int)v23->data.pointer;
  *(float *)&v62[24] = 1.0;
  props->range = v24;
  props->color = vostok::math::color_rgba(v70, v68, v69, *(float *)&v62[24]);
  if ( vostok::configs::binary_config_value::value_exists(v25, (int)t, (unsigned int)"scale")
    && vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v26,
         (int)t,
         (unsigned int)"rotation")
    && vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v26,
         (int)t,
         (unsigned int)"position") )
  {
    v71 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "scale")->data.pointer;
    config_4 = (const vostok::math::float3 *)vostok::configs::binary_config_value::operator[](t, "rotation")->data.pointer;
    v72 = (const vostok::math::float3 **)vostok::configs::binary_config_value::operator[](t, "position");
    config_4a = vostok::math::create_rotation(config_4, (int)"position", (int)v64);
    v27 = vostok::math::create_scale(v71, &v63);
    vostok::math::mul4x3(config_4a, v27, &v67);
    v28 = vostok::math::create_translation(*v72, &v66);
    vostok::math::mul4x3(v28, &v67, &v65);
    v29 = &v65;
  }
  else
  {
    v29 = vostok::math::float4x4::identity(v26, &v66);
  }
  qmemcpy(props, v29, 0x40u);
  v30 = t;
  props->type = (vostok::render::light_type)vostok::configs::binary_config_value::operator[](t, "light_type")->data.pointer;
  if ( vostok::configs::binary_config_value::value_exists(v31, (int)t, (unsigned int)"attenuation_power") )
  {
    v32 = vostok::configs::binary_config_value::operator[](t, "attenuation_power");
    if ( v32->type == 2 )
      v33 = *(float *)&v32->data.pointer;
    else
      v33 = (float)(int)v32->data.pointer;
  }
  else
  {
    v34 = (vostok::math ***)vostok::configs::binary_config_value::operator[](t, "attenuation");
    v35 = *v34;
    v68 = **v34;
    LODWORD(v69) = *++v35;
    v70 = *((float *)v35 + 1);
    v33 = *(float *)&v68;
    v30 = t;
  }
  props->attenuation_power = v33;
  v36 = vostok::configs::binary_config_value::operator[](v30, "intensity");
  if ( v36->type == 2 )
    v37 = *(float *)&v36->data.pointer;
  else
    v37 = (float)(int)v36->data.pointer;
  props->intensity = v37;
  v38 = vostok::configs::binary_config_value::operator[](v30, "spot_umbra_angle");
  if ( v38->type == 2 )
    v39 = *(float *)&v38->data.pointer;
  else
    v39 = (float)(int)v38->data.pointer;
  props->spot_umbra_angle = v39;
  v40 = vostok::configs::binary_config_value::operator[](v30, "spot_penumbra_angle");
  if ( v40->type == 2 )
    v41 = *(float *)&v40->data.pointer;
  else
    v41 = (float)(int)v40->data.pointer;
  props->spot_penumbra_angle = v41;
  v42 = vostok::configs::binary_config_value::operator[](v30, "spot_falloff");
  if ( v42->type == 2 )
    v44 = *(float *)&v42->data.pointer;
  else
    v44 = (float)(int)v42->data.pointer;
  *(_DWORD *)&v62[24] = "diffuse_influence_factor";
  props->spot_falloff = v44;
  if ( vostok::configs::binary_config_value::value_exists(v43, (int)v30, *(unsigned int *)&v62[24]) )
  {
    v46 = vostok::configs::binary_config_value::operator[](v30, "diffuse_influence_factor");
    if ( v46->type == 2 )
      v47 = *(float *)&v46->data.pointer;
    else
      v47 = (float)(int)v46->data.pointer;
  }
  else
  {
    v47 = s_bm_current_air_resistance;
  }
  *(_DWORD *)&v62[24] = "specular_influence_factor";
  props->diffuse_influence_factor = v47;
  if ( vostok::configs::binary_config_value::value_exists(v45, (int)v30, *(unsigned int *)&v62[24]) )
  {
    v49 = vostok::configs::binary_config_value::operator[](v30, "specular_influence_factor");
    if ( v49->type == 2 )
      v50 = *(float *)&v49->data.pointer;
    else
      v50 = (float)(int)v49->data.pointer;
  }
  else
  {
    v50 = s_bm_current_air_resistance;
  }
  *(_DWORD *)&v62[24] = "is_shadower";
  props->specular_influence_factor = v50;
  v52 = vostok::configs::binary_config_value::value_exists(v48, (int)v30, *(unsigned int *)&v62[24])
     && vostok::configs::binary_config_value::operator[](v30, "is_shadower")->data.pointer != 0;
  props->shadower = v52;
  v54 = vostok::configs::binary_config_value::value_exists(v51, (int)v30, (unsigned int)"use_with_lpv")
     && vostok::configs::binary_config_value::operator[](v30, "use_with_lpv")->data.pointer != 0;
  props->use_with_lpv = v54;
  v56 = !vostok::configs::binary_config_value::value_exists(v53, (int)v30, (unsigned int)"enabled")
     || vostok::configs::binary_config_value::operator[](v30, "enabled")->data.pointer != 0;
  props->enabled = v56;
  v58 = vostok::configs::binary_config_value::value_exists(v55, (int)v30, (unsigned int)"static_shadows")
     && vostok::configs::binary_config_value::operator[](v30, "static_shadows")->data.pointer != 0;
  props->static_shadows = v58;
  if ( vostok::configs::binary_config_value::value_exists(v57, (int)v30, (unsigned int)"is_light_animated") )
  {
    v59 = vostok::configs::binary_config_value::operator[](v30, "is_light_animated")->data.pointer != 0;
    props->is_light_animated = v59;
    if ( v59 )
    {
      *(_DWORD *)v62 = allocator;
      qmemcpy(&v62[4], vostok::configs::binary_config_value::operator[](v30, "color_curve"), 0x18u);
      vostok::math::curve_line_color::load<vostok::configs::binary_config_value>(
        0,
        (vostok::memory::base_allocator *)&props->m_color_curve,
        *(vostok::configs::binary_config_value *)v62,
        *(int *)&v62[24]);
      v60 = vostok::configs::binary_config_value::operator[](t, "light_animation_length");
      if ( v60->type == 2 )
        v61 = *(float *)&v60->data.pointer;
      else
        v61 = (float)(int)v60->data.pointer;
      props->light_animation_length = v61;
    }
  }
  else
  {
    props->is_light_animated = 0;
  }
}

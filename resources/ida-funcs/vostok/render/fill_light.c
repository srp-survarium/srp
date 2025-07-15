void __usercall vostok::render::fill_light(
        long double a1@<esi:edi>,
        vostok::render::light *light,
        vostok::render::light_props *props)
{
  vostok::render::light_props *v3; // eax
  long double v4; // rdi
  vostok::math::float4x4 *v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  vostok::math::float3 *v8; // eax
  float v9; // xmm0_4
  unsigned int color; // eax
  double x; // xmm0_8
  double y; // xmm0_8
  double z; // xmm0_8
  vostok::math::curve_line_points<vostok::math::float4_pod,1> *v14; // ecx
  unsigned int *static_shadow_visible_objects_count; // eax
  vostok::render::light *v16; // ecx
  long double v17; // rdi
  vostok::math::float4x4 *v18; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *epsilon; // [esp+Ch] [ebp-154h]
  long double v21; // [esp+10h] [ebp-150h]
  long double v22; // [esp+10h] [ebp-150h]
  long double v23; // [esp+18h] [ebp-148h]
  long double v24; // [esp+18h] [ebp-148h]
  long double v25; // [esp+18h] [ebp-148h]
  char v26; // [esp+23h] [ebp-13Dh]
  vostok::math::float3 v27; // [esp+24h] [ebp-13Ch] BYREF
  int intensity_low; // [esp+30h] [ebp-130h] BYREF
  vostok::math::float3 v29; // [esp+34h] [ebp-12Ch] BYREF
  vostok::math::float4x4 v30; // [esp+40h] [ebp-120h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v31; // [esp+80h] [ebp-E0h] BYREF
  vostok::math::float4x4 v32; // [esp+A0h] [ebp-C0h] BYREF
  vostok::math::float4x4 v33; // [esp+E0h] [ebp-80h] BYREF
  vostok::math::float4x4 v34; // [esp+120h] [ebp-40h] BYREF

  intensity_low = 0;
  if ( light->shadow_z_bias != props->local_light_z_bias
    || !vostok::math::operator==((const vostok::math::float3_pod *)&props->transform.lines[3], &light->position)
    || (v26 = 0, light->static_shadows != props->static_shadows) )
  {
    v26 = 1;
  }
  v3 = props;
  qmemcpy(&v30, props, sizeof(v30));
  if ( props->type == light_type_spot )
  {
    *(_QWORD *)&v29.x = *(_QWORD *)&v30.lines[3].x;
    v29.z = v30.c.z;
    memset(&v27, 0, sizeof(v27));
    memset(&v30.lines[3], 0, 12);
    HIDWORD(v17) = &intensity_low;
    LODWORD(v17) = &v30.c.w;
    v18 = vostok::math::create_rotation_x(v17, (__m128i)0LL, &v34, -1.5707964);
    vostok::math::mul4x3(&v30, v18, &v32);
    v3 = props;
    qmemcpy(&v30, &v32, sizeof(v30));
    *(_QWORD *)&v30.lines[3].x = *(_QWORD *)&v29.x;
    v30.c.z = v29.z;
LABEL_8:
    light->spot_penumbra_angle = v3->spot_penumbra_angle;
    light->spot_umbra_angle = v3->spot_umbra_angle;
    light->spot_falloff = v3->spot_falloff;
    goto LABEL_16;
  }
  if ( props->type != light_type_capsule )
  {
    if ( props->type != light_type_plane_spot )
      goto LABEL_16;
    goto LABEL_8;
  }
  *(_QWORD *)&v29.x = *(_QWORD *)&v30.lines[3].x;
  v29.z = v30.c.z;
  memset(&v27, 0, sizeof(v27));
  memset(&v30.lines[3], 0, 12);
  HIDWORD(v4) = &intensity_low;
  LODWORD(v4) = &v30.c.w;
  v5 = vostok::math::create_rotation_x(v4, (__m128i)0LL, &v33, -1.5707964);
  vostok::math::mul4x3(&v30, v5, &v32);
  qmemcpy(&v30, &v32, sizeof(v30));
  *(_QWORD *)&v30.lines[3].x = *(_QWORD *)&v29.x;
  v30.c.z = v29.z;
  vostok::math::float4x4::get_scale(&props->transform, &v27);
  if ( v27.x != v27.z )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)3),
          v6 = epsilon,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v6,
        &v31);
      intensity_low = 1;
      vostok::logging::append(
        &v31,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lights_db.cpp",
        0xAFu,
        "void __cdecl vostok::render::fill_light(class vostok::render::light &,struct vostok::render::light_props *)",
        "render_pc_dx11",
        warning,
        "invalid capsule passed, x=%f, z=%f",
        v27.x,
        v27.z);
    }
    if ( (intensity_low & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
        (int *)&v31);
  }
  v3 = props;
LABEL_16:
  *(_DWORD *)&light->flags ^= (v3->type ^ *(_DWORD *)&light->flags) & 0xF;
  *(_DWORD *)&light->flags ^= ((unsigned __int8)*(_DWORD *)&light->flags
                             ^ (unsigned __int8)(32 * v3->does_cast_shadows))
                            & 0x20;
  if ( !vostok::math::float3_pod::is_similar(
          &light->position,
          (const vostok::math::float3_pod *)&v30.lines[3],
          0.0000001) )
  {
    light->position.x = v30.c.x;
    *(_QWORD *)&light->position.elements[1] = *(_QWORD *)&v30.lines[3].elements[1];
  }
  v27.x = s_bm_current_air_resistance;
  v27.y = s_bm_current_air_resistance;
  v27.z = s_bm_current_air_resistance;
  v8 = vostok::math::normalize_safe((const vostok::math::float3_pod *)&v30.lines[2], &v27, &v29);
  v9 = s_bm_current_air_resistance;
  light->direction = *v8;
  v27.x = v9;
  v27.y = v9;
  v27.z = v9;
  light->right = *vostok::math::normalize_safe((const vostok::math::float3_pod *)&v30, &v27, &v29);
  light->range = props->range;
  color = props->color;
  intensity_low = LODWORD(props->intensity);
  light->color.x = (float)(unsigned __int8)color;
  light->color.y = (float)BYTE1(color);
  light->color.z = (float)BYTE2(color);
  light->color.x = light->color.x * 0.0039215689;
  light->color.y = light->color.y * 0.0039215689;
  light->color.z = light->color.z * 0.0039215689;
  x = light->color.x;
  __libm_sse2_pow(a1, v23);
  *(float *)&x = x;
  v27.x = *(float *)&x;
  y = light->color.y;
  __libm_sse2_pow(v21, v24);
  *(float *)&y = y;
  v27.y = *(float *)&y;
  z = light->color.z;
  __libm_sse2_pow(v22, v25);
  *(float *)&z = z;
  v27.z = *(float *)&z;
  LODWORD(z) = intensity_low;
  light->color = v27;
  light->intensity = *(float *)&z;
  light->attenuation_power = props->attenuation_power;
  light->lighting_model = props->lighting_model;
  light->scale = *vostok::math::float4x4::get_scale(&v30, &v29);
  light->diffuse_influence_factor = props->diffuse_influence_factor;
  light->use_with_lpv = props->use_with_lpv;
  light->specular_influence_factor = props->specular_influence_factor;
  light->is_shadower = props->shadower;
  light->shadow_z_bias = props->local_light_z_bias;
  light->shadow_map_size = props->shadow_map_size;
  light->m_shadow_map_size_index = props->shadow_map_size_index;
  vostok::render::light::on_render_options_changed(light);
  light->shadow_transparency = props->shadow_transparency;
  light->m_enabled = props->enabled;
  light->m_particle_light = props->particle_light;
  light->static_shadows = props->static_shadows;
  if ( v26 )
  {
    v14 = 0;
    static_shadow_visible_objects_count = light->static_shadow_visible_objects_count;
    do
    {
      *((_BYTE *)v14[11].curve_value_min.elements + (_DWORD)light + 2) = 1;
      *(static_shadow_visible_objects_count - 6) = 0;
      *static_shadow_visible_objects_count = 0;
      v14 = (vostok::math::curve_line_points<vostok::math::float4_pod,1> *)((char *)v14 + 1);
      ++static_shadow_visible_objects_count;
    }
    while ( (unsigned int)v14 < 6 );
  }
  LOBYTE(v14) = props->is_light_animated;
  light->m_is_light_animated = (char)v14;
  light->m_light_animation_length = props->light_animation_length;
  if ( (_BYTE)v14 )
    vostok::math::curve_line_points<vostok::math::float4_pod,1>::copy_from(
      v14,
      &light->m_color_curve,
      &props->m_color_curve);
  *(_DWORD *)light->shadow_distribution_sides = *(_DWORD *)props->shadow_distribution_sides;
  *(_WORD *)&light->shadow_distribution_sides[4] = *(_WORD *)&props->shadow_distribution_sides[4];
  vostok::render::light::try_create_static_shadow_buffers((vostok::render::light *)v14, (int)light, 0);
  vostok::render::light::on_properties_changed(v16, (int)light);
}

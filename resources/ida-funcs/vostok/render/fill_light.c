void __cdecl vostok::render::fill_light(vostok::render::light *light, vostok::render::light_props *props)
{
  vostok::render::light_props *v2; // eax
  float v3; // edi
  vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 *v5; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  float v8; // edx
  unsigned int color; // eax
  float intensity; // xmm1_4
  float v11; // xmm1_4
  double v12; // st7
  bool is_light_animated; // dl
  vostok::render::resource_manager *v14; // ecx
  vostok::render::render_target *render_target; // eax
  vostok::render::render_target *v16; // ecx
  const char *m_object; // eax
  bool v18; // zf
  vostok::render::res_texture *v19; // ecx
  const vostok::render::res_texture *v20; // eax
  vostok::render::res_texture *v21; // esi
  float z; // edi
  vostok::math::float4x4 *rotation_x; // eax
  unsigned int v24; // [esp+308h] [ebp-150h]
  unsigned int v25; // [esp+30Ch] [ebp-14Ch]
  char v26; // [esp+318h] [ebp-140h]
  float v27; // [esp+318h] [ebp-140h]
  vostok::render::res_texture *v28; // [esp+318h] [ebp-140h]
  __int64 v29; // [esp+31Ch] [ebp-13Ch] BYREF
  float v30; // [esp+324h] [ebp-134h]
  vostok::math::float4x4 right; // [esp+328h] [ebp-130h] BYREF
  float v32; // [esp+368h] [ebp-F0h]
  __int64 v33; // [esp+36Ch] [ebp-ECh]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+378h] [ebp-E0h] BYREF
  vostok::math::float4x4 v35; // [esp+398h] [ebp-C0h] BYREF
  _QWORD v36[8]; // [esp+3D8h] [ebp-80h] BYREF
  _QWORD v37[8]; // [esp+418h] [ebp-40h] BYREF

  v2 = props;
  qmemcpy((void *)&right, props, sizeof(right));
  v26 = 0;
  if ( props->type == light_type_spot )
  {
    z = right.c.z;
    v33 = *(_QWORD *)&right.lines[3].x;
    v30 = 0.0;
    v29 = 0;
    memset(&right.lines[3], 0, 12);
    rotation_x = vostok::math::create_rotation_x(v37, COERCE_VOSTOK_MATH_FLOAT4X4_(-1.5707964));
    vostok::math::mul4x3(&v35, rotation_x, &right);
    v2 = props;
    right.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35);
    right.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[1]);
    right.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[2]);
    right.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[3]);
    *(_QWORD *)&right.lines[3].x = v33;
    right.c.z = z;
LABEL_4:
    light->spot_penumbra_angle = v2->spot_penumbra_angle;
    light->spot_umbra_angle = v2->spot_umbra_angle;
    light->spot_falloff = v2->spot_falloff;
    goto LABEL_17;
  }
  if ( props->type != light_type_capsule )
  {
    if ( props->type != light_type_plane_spot )
      goto LABEL_17;
    goto LABEL_4;
  }
  v3 = right.c.z;
  v33 = *(_QWORD *)&right.lines[3].x;
  v30 = 0.0;
  v29 = 0;
  memset(&right.lines[3], 0, 12);
  v4 = vostok::math::create_rotation_x(v36, COERCE_VOSTOK_MATH_FLOAT4X4_(-1.5707964));
  vostok::math::mul4x3(&v35, v4, &right);
  right.i = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35);
  right.lines[1] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[1]);
  right.lines[2] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[2]);
  right.lines[3] = (vostok::math::float4_pod)_mm_load_si128((const __m128i *)&v35.lines[3]);
  right.c.z = v3;
  *(_QWORD *)&right.lines[3].x = v33;
  vostok::math::float4x4::get_scale(v5, (float *)&v29, &props->transform.i.x);
  if ( *(float *)&v29 != v30 )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render_pc_dx11:", warning) )
    {
      v7 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v7 )
      {
        log_callback.functor.obj_ptr = v7;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v26 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\lights_db.cpp",
        0xA8u,
        "void __cdecl vostok::render::fill_light(class vostok::render::light &,struct vostok::render::light_props *)",
        "render_pc_dx11:",
        warning,
        "invalid capsule passed, x=%f, z=%f",
        *(float *)&v29,
        v30);
    }
    if ( (v26 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v6,
        (int *)&log_callback);
  }
  v2 = props;
LABEL_17:
  *(_DWORD *)&light->flags ^= ((unsigned __int8)v2->type ^ (unsigned __int8)*(_DWORD *)&light->flags) & 0xF;
  *(_DWORD *)&light->flags ^= ((unsigned __int8)*(_DWORD *)&light->flags
                             ^ (unsigned __int8)(32 * v2->does_cast_shadows))
                            & 0x20;
  if ( !vostok::math::float3_pod::is_similar(
          &light->position,
          (const vostok::math::float3_pod *)&right.lines[3],
          0.0000001) )
  {
    v8 = right.c.z;
    *(_QWORD *)&light->position.x = *(_QWORD *)&right.lines[3].x;
    light->position.z = v8;
  }
  vostok::render::light::set_orientation(
    (vostok::render::light *)&right.lines[2],
    light,
    (const vostok::math::float3 *)&right);
  light->range = props->range;
  color = props->color;
  intensity = props->intensity;
  light->color.x = (float)(unsigned __int8)color;
  light->color.y = (float)BYTE1(color);
  light->color.z = (float)BYTE2(color);
  light->color.x = light->color.x * 0.0039215689;
  light->color.y = light->color.y * 0.0039215689;
  light->color.z = light->color.z * 0.0039215689;
  light->intensity = intensity;
  light->attenuation_power = props->attenuation_power;
  v11 = (float)((float)(right.k.x * right.k.x) + (float)(right.k.y * right.k.y)) + (float)(right.k.z * right.k.z);
  light->lighting_model = props->lighting_model;
  v32 = sqrtf(v11);
  v27 = sqrtf((float)((float)(right.j.y * right.j.y) + (float)(right.j.z * right.j.z)) + (float)(right.j.x * right.j.x));
  *(float *)&v29 = sqrtf(
                     (float)((float)(right.i.x * right.i.x) + (float)(right.i.z * right.i.z))
                   + (float)(right.i.y * right.i.y));
  *((float *)&v29 + 1) = v27;
  v12 = v32;
  *(_QWORD *)&light->scale.x = v29;
  v30 = v12;
  light->scale.z = v30;
  light->diffuse_influence_factor = props->diffuse_influence_factor;
  light->use_with_lpv = props->use_with_lpv;
  light->specular_influence_factor = props->specular_influence_factor;
  light->is_shadower = props->shadower;
  light->shadow_z_bias = props->local_light_z_bias;
  light->shadow_map_size = props->shadow_map_size;
  light->shadow_map_size_index = props->shadow_map_size_index;
  light->shadow_transparency = props->shadow_transparency;
  light->m_enabled = props->enabled;
  light->static_shadows = props->static_shadows;
  light->need_refresh_static_shadows = 1;
  is_light_animated = props->is_light_animated;
  light->m_is_light_animated = is_light_animated;
  light->m_light_animation_length = props->light_animation_length;
  if ( is_light_animated )
  {
    vostok::math::curve_line_points<vostok::math::float4_pod,1>::operator=(&light->m_color_curve, &props->m_color_curve);
    light->m_color_curve.m_evaluate_type = props->m_color_curve.m_evaluate_type;
  }
  v14 = *(vostok::render::resource_manager **)props->shadow_distribution_sides;
  *(_DWORD *)light->shadow_distribution_sides = v14;
  *(_WORD *)&light->shadow_distribution_sides[4] = *(_WORD *)&props->shadow_distribution_sides[4];
  if ( props->type == light_type_parallel )
    goto LABEL_39;
  if ( props->static_shadows )
  {
    render_target = vostok::render::resource_manager::create_render_target(
                      v14,
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      0,
                      (vostok::render::res_texture *)0x100,
                      (ID3D11Texture2D **)0x100,
                      (const char *)0x35,
                      enum_rt_usage_depth_stencil,
                      0,
                      0,
                      v24,
                      v25);
    v16 = 0;
    if ( render_target )
    {
      ++render_target->m_reference_count;
      v16 = render_target;
    }
    m_object = (const char *)light->m_shadow_depth_stencil.m_object;
    light->m_shadow_depth_stencil.m_object = v16;
    if ( m_object )
    {
      v18 = (*(_DWORD *)m_object)-- == 1;
      if ( v18 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          m_object);
    }
    v19 = light->m_shadow_depth_stencil.m_object->m_texture.m_object;
    v20 = 0;
    v28 = 0;
    if ( v19 )
    {
      ++v19->m_reference_count;
      v28 = v19;
      v20 = v19;
    }
    v14 = 0;
    if ( v20 )
    {
      ++v20->m_reference_count;
      v14 = (vostok::render::resource_manager *)v20;
    }
    v21 = light->m_shadow_depth_stencil_texture.m_object;
    light->m_shadow_depth_stencil_texture.m_object = (vostok::render::res_texture *)v14;
    if ( v21 )
    {
      v18 = v21->m_reference_count-- == 1;
      if ( v18 )
      {
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v14, v21);
        v20 = v28;
      }
    }
    if ( v20 )
    {
      v18 = v20->m_reference_count-- == 1;
      if ( v18 )
        vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v14, v20);
    }
  }
  if ( props->type == light_type_parallel )
  {
LABEL_39:
    light->sun_shadow_map_size = props->sun_shadow_map_size;
    light->num_sun_cascades = props->num_sun_cascades;
  }
  vostok::render::light::on_properties_changed((vostok::render::light *)v14, light);
}

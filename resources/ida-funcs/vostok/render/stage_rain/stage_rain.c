void __usercall vostok::render::stage_rain::stage_rain(
        vostok::render::stage_rain *this@<edi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v4; // ecx
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  vostok::strings::shared::manager *v7; // ecx
  vostok::strings::shared::profile *v8; // eax
  vostok::render::backend *v9; // ecx
  volatile signed __int32 *v10; // esi
  vostok::strings::shared::manager *v11; // ecx
  vostok::strings::shared::profile *v12; // eax
  vostok::render::backend *v13; // ecx
  volatile signed __int32 *v14; // esi
  vostok::strings::shared::manager *v15; // ecx
  vostok::strings::shared::profile *v16; // eax
  vostok::render::backend *v17; // ecx
  volatile signed __int32 *v18; // esi
  vostok::strings::shared::manager *v19; // ecx
  vostok::strings::shared::profile *v20; // eax
  vostok::render::backend *v21; // ecx
  volatile signed __int32 *v22; // esi
  vostok::render::resource_manager *v23; // ecx
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v25; // ecx
  vostok::render::res_texture *m_object; // esi
  int v28; // ecx
  unsigned int v29; // esi
  float *m_rain_rotation_y; // ebp
  int v31; // ecx
  double v32; // st4
  vostok::math::float2 *m_rain_offsets; // eax
  vostok::shared_string name; // [esp+10h] [ebp-Ch] BYREF
  float v35; // [esp+14h] [ebp-8h]
  float v36; // [esp+18h] [ebp-4h]

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_rain_vtbl *)&vostok::render::stage_rain::`vftable';
  p_m_reference_count = 0;
  this->m_t_rain_shadow_map.m_object = 0;
  this->m_rain_effect.m_object = 0;
  this->m_effect_shadow_direct.m_object = 0;
  vostok::render::sphere_geometry::sphere_geometry(
    (vostok::render::sphere_geometry *)in_renderer,
    &this->m_rain_geometry,
    COERCE_FLOAT(24),
    3u);
  this->m_camera_offset_view = 0.0;
  this->m_camera_offset_right = 0.0;
  *(_QWORD *)&this->m_previous_view_position.x = 0;
  this->m_previous_view_position.z = 0.0;
  v5 = vostok::strings::shared::manager::string(v4, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_radius_parameter = vostok::render::backend::register_constant_host(
                               v6,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( p_m_reference_count )
  {
    v7 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v7 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v8 = vostok::strings::shared::manager::string(v7, (const char *)s_manager.m_variable);
  v10 = 0;
  name.m_pointer.m_object = 0;
  if ( v8 )
  {
    v10 = &v8->m_reference_count;
    name.m_pointer.m_object = v8;
    v9 = (vostok::render::backend *)_InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  this->m_rain_speed_parameter = vostok::render::backend::register_constant_host(
                                   v9,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v10 )
  {
    v11 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v10, 0xFFFFFFFF);
    if ( !v11 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v12 = vostok::strings::shared::manager::string(v11, (const char *)s_manager.m_variable);
  v14 = 0;
  name.m_pointer.m_object = 0;
  if ( v12 )
  {
    v14 = &v12->m_reference_count;
    name.m_pointer.m_object = v12;
    v13 = (vostok::render::backend *)_InterlockedExchangeAdd(&v12->m_reference_count, 1u);
  }
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
                                       v13,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v14 )
  {
    v15 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v14, 0xFFFFFFFF);
    if ( !v15 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v16 = vostok::strings::shared::manager::string(v15, (const char *)s_manager.m_variable);
  v18 = 0;
  name.m_pointer.m_object = 0;
  if ( v16 )
  {
    v18 = &v16->m_reference_count;
    name.m_pointer.m_object = v16;
    v17 = (vostok::render::backend *)_InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  this->m_rain_density_parameter = vostok::render::backend::register_constant_host(
                                     v17,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     &name,
                                     rc_float);
  if ( v18 )
  {
    v19 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v18, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v20 = vostok::strings::shared::manager::string(v19, (const char *)s_manager.m_variable);
  v22 = 0;
  name.m_pointer.m_object = 0;
  if ( v20 )
  {
    v22 = &v20->m_reference_count;
    name.m_pointer.m_object = v20;
    v21 = (vostok::render::backend *)_InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  this->m_rain_uv_scales_parameter = vostok::render::backend::register_constant_host(
                                       v21,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v22 && !_InterlockedExchangeAdd(v22, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  v23 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_shadow_map_size = 128;
  texture = vostok::render::resource_manager::create_texture(
              v23,
              &stru_963F84.m_name.m_string.m_buffer[92],
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
  v25 = 0;
  if ( texture )
  {
    ++texture->_M_parent;
    v25 = (vostok::render::res_texture *)texture;
  }
  m_object = this->m_t_rain_shadow_map.m_object;
  this->m_t_rain_shadow_map.m_object = v25;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(v25, m_object);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_rain>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_rain_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_effect_shadow_direct);
  this->m_rain_offsets = vostok::memory::new_array_helper<vostok::math::float2>::call<vostok::memory::doug_lea_allocator>((vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object);
  v28 = 1000;
  v29 = 0;
  m_rain_rotation_y = this->m_rain_rotation_y;
  do
  {
    v31 = 134775813 * v28 + 1;
    name.m_pointer.m_object = (vostok::strings::shared::profile *)((((unsigned int)&loc_FFFFF + 1)
                                                                  * (unsigned __int64)(unsigned int)v31) >> 32);
    v32 = (double)(unsigned int)name.m_pointer.m_object * 0.00000095367432;
    v28 = 134775813 * v31 + 1;
    name.m_pointer.m_object = (vostok::strings::shared::profile *)((((unsigned int)&loc_FFFFF + 1)
                                                                  * (unsigned __int64)(unsigned int)v28) >> 32);
    m_rain_offsets = this->m_rain_offsets;
    ++v29;
    ++m_rain_rotation_y;
    v35 = (double)(unsigned int)name.m_pointer.m_object * 0.00000095367432 * 2.0 - 1.0;
    m_rain_offsets[v29 - 1].x = v35;
    v36 = v32 * 2.0 - 1.0;
    m_rain_offsets[v29 - 1].y = v36;
    *(m_rain_rotation_y - 101) = 0.0;
    *(m_rain_rotation_y - 1) = 0.0;
  }
  while ( v29 < 100 );
}

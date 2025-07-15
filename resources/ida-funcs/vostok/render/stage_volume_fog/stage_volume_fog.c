void __usercall vostok::render::stage_volume_fog::stage_volume_fog(
        vostok::render::stage_volume_fog *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *in_context@<eax>)
{
  vostok::render::sphere_geometry *v3; // ecx
  vostok::strings::shared::profile *v4; // eax
  vostok::render::backend *v5; // ecx
  vostok::strings::shared::manager *v6; // edi
  vostok::strings::shared::profile *v7; // eax
  vostok::render::backend *v8; // ecx
  vostok::strings::shared::manager *v9; // edi
  vostok::strings::shared::profile *v10; // eax
  vostok::render::backend *v11; // ecx
  vostok::strings::shared::manager *v12; // edi
  vostok::strings::shared::profile *v13; // eax
  vostok::render::backend *v14; // ecx
  vostok::strings::shared::manager *v15; // edi
  vostok::strings::shared::profile *v16; // eax
  vostok::render::backend *v17; // ecx
  vostok::strings::shared::manager *v18; // edi
  vostok::strings::shared::profile *v19; // eax
  vostok::render::backend *v20; // ecx
  vostok::strings::shared::manager *v21; // edi
  vostok::strings::shared::profile *v22; // eax
  vostok::render::backend *v23; // ecx
  vostok::strings::shared::manager *v24; // edi
  vostok::strings::shared::profile *v25; // eax
  vostok::render::backend *v26; // ecx
  vostok::strings::shared::manager *v27; // edi
  vostok::strings::shared::profile *v28; // eax
  vostok::render::backend *v29; // ecx
  vostok::strings::shared::manager *v30; // edi
  vostok::strings::shared::profile *v31; // eax
  vostok::render::backend *v32; // ecx
  vostok::strings::shared::manager *v33; // edi
  vostok::strings::shared::profile *v34; // eax
  vostok::render::backend *v35; // ecx
  vostok::strings::shared::manager *v36; // edi
  vostok::strings::shared::profile *v37; // eax
  vostok::render::backend *v38; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::shared_string name; // [esp+10h] [ebp-4h] BYREF

  this->m_context = in_context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_volume_fog_vtbl *)&vostok::render::stage_volume_fog::`vftable';
  vostok::render::fog_box_geometry::fog_box_geometry((vostok::render::fog_box_geometry *)in_renderer);
  vostok::render::sphere_geometry::sphere_geometry(v3, &this->m_fog_sphere_geometry, COERCE_FLOAT(32), 0x20u);
  this->m_exponential_volume_fog_effect.m_object = 0;
  this->m_simple_fog_effect.m_object = 0;
  v4 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v6 = 0;
  name.m_pointer.m_object = 0;
  if ( v4 )
  {
    v6 = (vostok::strings::shared::manager *)v4;
    name.m_pointer.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v5,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)v6, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v6, (vostok::strings::shared::profile *)s_manager.m_variable);
  v7 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v9 = 0;
  name.m_pointer.m_object = 0;
  if ( v7 )
  {
    v9 = (vostok::strings::shared::manager *)v7;
    name.m_pointer.m_object = v7;
    _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  this->m_inverted_world_matrix_parameter = vostok::render::backend::register_constant_host(
                                              v8,
                                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                              &name,
                                              rc_float);
  if ( v9 && !_InterlockedExchangeAdd((volatile signed __int32 *)v9, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v9, (vostok::strings::shared::profile *)s_manager.m_variable);
  v10 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v12 = 0;
  name.m_pointer.m_object = 0;
  if ( v10 )
  {
    v12 = (vostok::strings::shared::manager *)v10;
    name.m_pointer.m_object = v10;
    _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  this->m_eye_pos_os_parameter = vostok::render::backend::register_constant_host(
                                   v11,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v12 && !_InterlockedExchangeAdd((volatile signed __int32 *)v12, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v12, (vostok::strings::shared::profile *)s_manager.m_variable);
  v13 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v15 = 0;
  name.m_pointer.m_object = 0;
  if ( v13 )
  {
    v15 = (vostok::strings::shared::manager *)v13;
    name.m_pointer.m_object = v13;
    _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  this->m_eye_pos_ws_parameter = vostok::render::backend::register_constant_host(
                                   v14,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( v15 && !_InterlockedExchangeAdd((volatile signed __int32 *)v15, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v15, (vostok::strings::shared::profile *)s_manager.m_variable);
  v16 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v18 = 0;
  name.m_pointer.m_object = 0;
  if ( v16 )
  {
    v18 = (vostok::strings::shared::manager *)v16;
    name.m_pointer.m_object = v16;
    _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  this->m_is_inside_volume_parameter = vostok::render::backend::register_constant_host(
                                         v17,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_int);
  if ( v18 && !_InterlockedExchangeAdd((volatile signed __int32 *)v18, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v18, (vostok::strings::shared::profile *)s_manager.m_variable);
  v19 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v21 = 0;
  name.m_pointer.m_object = 0;
  if ( v19 )
  {
    v21 = (vostok::strings::shared::manager *)v19;
    name.m_pointer.m_object = v19;
    _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
  }
  this->m_fog_parameters0 = vostok::render::backend::register_constant_host(
                              v20,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v21 && !_InterlockedExchangeAdd((volatile signed __int32 *)v21, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v21, (vostok::strings::shared::profile *)s_manager.m_variable);
  v22 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v24 = 0;
  name.m_pointer.m_object = 0;
  if ( v22 )
  {
    v24 = (vostok::strings::shared::manager *)v22;
    name.m_pointer.m_object = v22;
    _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
  }
  this->m_fog_parameters1 = vostok::render::backend::register_constant_host(
                              v23,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v24 && !_InterlockedExchangeAdd((volatile signed __int32 *)v24, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v24, (vostok::strings::shared::profile *)s_manager.m_variable);
  v25 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v27 = 0;
  name.m_pointer.m_object = 0;
  if ( v25 )
  {
    v27 = (vostok::strings::shared::manager *)v25;
    name.m_pointer.m_object = v25;
    _InterlockedExchangeAdd(&v25->m_reference_count, 1u);
  }
  this->m_fog_parameters2 = vostok::render::backend::register_constant_host(
                              v26,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v27 && !_InterlockedExchangeAdd((volatile signed __int32 *)v27, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v27, (vostok::strings::shared::profile *)s_manager.m_variable);
  v28 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v30 = 0;
  name.m_pointer.m_object = 0;
  if ( v28 )
  {
    v30 = (vostok::strings::shared::manager *)v28;
    name.m_pointer.m_object = v28;
    _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
  }
  this->m_fog_parameters3 = vostok::render::backend::register_constant_host(
                              v29,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v30 && !_InterlockedExchangeAdd((volatile signed __int32 *)v30, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v30, (vostok::strings::shared::profile *)s_manager.m_variable);
  v31 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v33 = 0;
  name.m_pointer.m_object = 0;
  if ( v31 )
  {
    v33 = (vostok::strings::shared::manager *)v31;
    name.m_pointer.m_object = v31;
    _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v32,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v33 && !_InterlockedExchangeAdd((volatile signed __int32 *)v33, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v33, (vostok::strings::shared::profile *)s_manager.m_variable);
  v34 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v36 = 0;
  name.m_pointer.m_object = 0;
  if ( v34 )
  {
    v36 = (vostok::strings::shared::manager *)v34;
    name.m_pointer.m_object = v34;
    _InterlockedExchangeAdd(&v34->m_reference_count, 1u);
  }
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v35,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v36 && !_InterlockedExchangeAdd((volatile signed __int32 *)v36, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v36, (vostok::strings::shared::profile *)s_manager.m_variable);
  v37 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v37 )
  {
    p_m_reference_count = &v37->m_reference_count;
    name.m_pointer.m_object = v37;
    _InterlockedExchangeAdd(&v37->m_reference_count, 1u);
  }
  this->m_fog_alpha = vostok::render::backend::register_constant_host(
                        v38,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( p_m_reference_count && !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::render::effect_manager::create_effect<vostok::render::effect_exponential_volume_fog>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_exponential_volume_fog_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_simple_fog>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_simple_fog_effect);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 296);
}

void __usercall vostok::render::stage_translucency::stage_translucency(
        vostok::render::stage_translucency *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx
  vostok::strings::shared::manager *v4; // ecx
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v8; // ecx
  vostok::strings::shared::profile *v9; // eax
  vostok::render::backend *v10; // ecx
  volatile signed __int32 *v11; // edi
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::backend *v14; // ecx
  volatile signed __int32 *v15; // edi
  vostok::strings::shared::manager *v16; // ecx
  vostok::strings::shared::profile *v17; // eax
  vostok::render::backend *v18; // ecx
  volatile signed __int32 *v19; // edi
  vostok::strings::shared::manager *v20; // ecx
  vostok::strings::shared::profile *v21; // eax
  vostok::render::backend *v22; // ecx
  volatile signed __int32 *v23; // edi
  vostok::strings::shared::manager *v24; // ecx
  vostok::strings::shared::profile *v25; // eax
  vostok::render::backend *v26; // ecx
  volatile signed __int32 *v27; // edi
  vostok::strings::shared::manager *v28; // ecx
  vostok::strings::shared::profile *v29; // eax
  vostok::render::backend *v30; // ecx
  volatile signed __int32 *v31; // edi
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_translucency_vtbl *)&stru_964DF4.m_name.m_string.m_buffer[64];
  this->m_translucency_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_translucency>(
    m_conflicted_action_to_bind,
    &this->m_translucency_effect);
  v5 = vostok::strings::shared::manager::string(v4, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v6,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( p_m_reference_count )
  {
    v8 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v9 = vostok::strings::shared::manager::string(v8, (const char *)s_manager.m_variable);
  v11 = 0;
  name.m_pointer.m_object = 0;
  if ( v9 )
  {
    v11 = &v9->m_reference_count;
    name.m_pointer.m_object = v9;
    v10 = (vostok::render::backend *)_InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
                        v10,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v11 )
  {
    v12 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v11, 0xFFFFFFFF);
    if ( !v12 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v13 = vostok::strings::shared::manager::string(v12, (const char *)s_manager.m_variable);
  v15 = 0;
  name.m_pointer.m_object = 0;
  if ( v13 )
  {
    v15 = &v13->m_reference_count;
    name.m_pointer.m_object = v13;
    v14 = (vostok::render::backend *)_InterlockedExchangeAdd(&v13->m_reference_count, 1u);
  }
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
                        v14,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v15 )
  {
    v16 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v15, 0xFFFFFFFF);
    if ( !v16 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v17 = vostok::strings::shared::manager::string(v16, (const char *)s_manager.m_variable);
  v19 = 0;
  name.m_pointer.m_object = 0;
  if ( v17 )
  {
    v19 = &v17->m_reference_count;
    name.m_pointer.m_object = v17;
    v18 = (vostok::render::backend *)_InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        v18,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v19 )
  {
    v20 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v19, 0xFFFFFFFF);
    if ( !v20 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v21 = vostok::strings::shared::manager::string(v20, (const char *)s_manager.m_variable);
  v23 = 0;
  name.m_pointer.m_object = 0;
  if ( v21 )
  {
    v23 = &v21->m_reference_count;
    name.m_pointer.m_object = v21;
    v22 = (vostok::render::backend *)_InterlockedExchangeAdd(&v21->m_reference_count, 1u);
  }
  this->m_c_sun_direction = vostok::render::backend::register_constant_host(
                              v22,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v23 )
  {
    v24 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v23, 0xFFFFFFFF);
    if ( !v24 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v25 = vostok::strings::shared::manager::string(v24, (const char *)s_manager.m_variable);
  v27 = 0;
  name.m_pointer.m_object = 0;
  if ( v25 )
  {
    v27 = &v25->m_reference_count;
    name.m_pointer.m_object = v25;
    v26 = (vostok::render::backend *)_InterlockedExchangeAdd(&v25->m_reference_count, 1u);
  }
  this->m_c_sun_color = vostok::render::backend::register_constant_host(
                          v26,
                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                          &name,
                          rc_float);
  if ( v27 )
  {
    v28 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v27, 0xFFFFFFFF);
    if ( !v28 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v29 = vostok::strings::shared::manager::string(v28, (const char *)s_manager.m_variable);
  v31 = 0;
  name.m_pointer.m_object = 0;
  if ( v29 )
  {
    v31 = &v29->m_reference_count;
    name.m_pointer.m_object = v29;
    v30 = (vostok::render::backend *)_InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v30,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( v31 && !_InterlockedExchangeAdd(v31, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  this->m_enabled = 1;
}

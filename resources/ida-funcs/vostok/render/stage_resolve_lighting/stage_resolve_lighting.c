void __usercall vostok::render::stage_resolve_lighting::stage_resolve_lighting(
        vostok::render::stage_resolve_lighting *this@<esi>,
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
  vostok::shared_string name; // [esp+8h] [ebp-4h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_resolve_lighting_vtbl *)&stru_964DF4.m_name.m_string.m_buffer[132];
  this->m_resolve_lighting_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_lighting>(
    m_conflicted_action_to_bind,
    &this->m_resolve_lighting_effect);
  v5 = vostok::strings::shared::manager::string(v4, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_wind_info_parameters = vostok::render::backend::register_constant_host(
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
  this->m_sun_light_parameters = vostok::render::backend::register_constant_host(
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
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
                                       v14,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       &name,
                                       rc_float);
  if ( v15 && !_InterlockedExchangeAdd(v15, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  this->m_enabled = 1;
}

void __usercall vostok::render::stage_pre_rain::stage_pre_rain(
        vostok::render::stage_pre_rain *this@<edi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        unsigned int a4@<ebp>,
        unsigned int a5@<esi>)
{
  vostok::strings::shared::profile *v5; // eax
  vostok::render::backend *v6; // ecx
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *v8; // ecx
  vostok::strings::shared::profile *v9; // eax
  vostok::render::backend *v10; // ecx
  volatile signed __int32 *v11; // esi
  vostok::strings::shared::manager *v12; // ecx
  vostok::strings::shared::profile *v13; // eax
  vostok::render::backend *v14; // ecx
  volatile signed __int32 *v15; // esi
  vostok::strings::shared::manager *v16; // ecx
  vostok::strings::shared::profile *v17; // eax
  vostok::render::backend *v18; // ecx
  volatile signed __int32 *v19; // esi
  vostok::render::resource_manager *v20; // ecx
  vostok::render::render_target *render_target; // eax
  vostok::render::render_target *v22; // ecx
  const char *m_object; // eax
  bool v24; // zf
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v26; // ecx
  vostok::render::res_texture *v27; // esi
  vostok::shared_string name; // [esp+0h] [ebp-4h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_pre_rain_vtbl *)&stru_963F84.m_name.m_string.m_buffer[128];
  this->m_rt_rain_shadow_map.m_object = 0;
  this->m_t_rain_shadow_map.m_object = 0;
  this->m_wet_surface_effect.m_object = 0;
  this->m_effect_shadow_direct.m_object = 0;
  this->m_rain_offset = 0.0;
  this->m_rain_offset_counter = 0.0;
  v5 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)in_renderer,
         (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_view_to_shadow_parameter = vostok::render::backend::register_constant_host(
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
  this->m_eye_ray_corner_parameter = vostok::render::backend::register_constant_host(
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
  this->m_rain_offset_parameter = vostok::render::backend::register_constant_host(
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
  this->m_rain_density_parameter = vostok::render::backend::register_constant_host(
                                     v18,
                                     (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                     &name,
                                     rc_float);
  if ( v19 )
  {
    v20 = (vostok::render::resource_manager *)_InterlockedExchangeAdd(v19, 0xFFFFFFFF);
    if ( !v20 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  this->m_shadow_map_size = 128;
  render_target = vostok::render::resource_manager::create_render_target(
                    v20,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    &stru_963F84.m_name.m_string.m_buffer[92],
                    (vostok::render::res_texture *)this->m_shadow_map_size,
                    (ID3D11Texture2D **)this->m_shadow_map_size,
                    (const char *)0x35,
                    enum_rt_usage_depth_stencil,
                    0,
                    0,
                    a5,
                    a4);
  v22 = 0;
  if ( render_target )
  {
    ++render_target->m_reference_count;
    v22 = render_target;
  }
  m_object = (const char *)this->m_rt_rain_shadow_map.m_object;
  this->m_rt_rain_shadow_map.m_object = v22;
  if ( m_object )
  {
    v24 = (*(_DWORD *)m_object)-- == 1;
    if ( v24 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  texture = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              &stru_963F84.m_name.m_string.m_buffer[92],
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
  v26 = 0;
  if ( texture )
  {
    ++texture->_M_parent;
    v26 = (vostok::render::res_texture *)texture;
  }
  v27 = this->m_t_rain_shadow_map.m_object;
  this->m_t_rain_shadow_map.m_object = v26;
  if ( v27 )
  {
    v24 = v27->m_reference_count-- == 1;
    if ( v24 )
      vostok::render::res_texture::destroy_impl(v26, v27);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_wet_surface>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_wet_surface_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_effect_shadow_direct);
}

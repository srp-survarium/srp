void __usercall vostok::render::stage_ambient_occlusion::stage_ambient_occlusion(
        vostok::render::stage_ambient_occlusion *this@<esi>,
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
  vostok::shared_string name; // [esp+10h] [ebp-4h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_ambient_occlusion_vtbl *)&stru_963F84.m_desc_cache_surface;
  this->m_sh_combine.m_object = 0;
  this->m_sh_ssao_accumulation.m_object = 0;
  this->m_sh_ssao_filter4x4.m_object = 0;
  this->m_sh_ssao_downsample_position_and_normal.m_object = 0;
  this->m_post_process_antialiasing_shader.m_object = 0;
  this->m_post_process_deferred_transparency_shader.m_object = 0;
  this->m_g_combine.m_object = 0;
  this->m_vb.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_accumulation>(
    m_conflicted_action_to_bind,
    &this->m_sh_ssao_accumulation);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_filter4x4>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_ssao_filter4x4);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_downsample_position_and_normal>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_sh_ssao_downsample_position_and_normal);
  v5 = vostok::strings::shared::manager::string(v4, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v5 )
  {
    p_m_reference_count = &v5->m_reference_count;
    name.m_pointer.m_object = v5;
    v6 = (vostok::render::backend *)_InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
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
  this->m_ao_parameters = vostok::render::backend::register_constant_host(
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
  this->m_prev_view_parameter = vostok::render::backend::register_constant_host(
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
  this->m_prev_ssao_valid_parameter = vostok::render::backend::register_constant_host(
                                        v18,
                                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                        &name,
                                        rc_int);
  if ( v19 && !_InterlockedExchangeAdd(v19, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 255)
                 && *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 250);
}

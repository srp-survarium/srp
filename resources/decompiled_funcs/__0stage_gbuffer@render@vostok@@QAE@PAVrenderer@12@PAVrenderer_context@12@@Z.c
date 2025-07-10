void __usercall vostok::render::stage_gbuffer::stage_gbuffer(
        vostok::render::stage_gbuffer *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::strings::shared::profile *v3; // eax
  vostok::render::backend *v4; // ecx
  volatile signed __int32 *p_m_reference_count; // edi
  vostok::strings::shared::manager *v6; // ecx
  vostok::strings::shared::profile *v7; // eax
  vostok::render::backend *v8; // ecx
  volatile signed __int32 *v9; // edi
  vostok::strings::shared::manager *v10; // ecx
  vostok::strings::shared::profile *v11; // eax
  vostok::render::backend *v12; // ecx
  volatile signed __int32 *v13; // edi
  vostok::strings::shared::manager *v14; // ecx
  vostok::strings::shared::profile *v15; // eax
  vostok::render::backend *v16; // ecx
  volatile signed __int32 *v17; // edi
  vostok::strings::shared::manager *v18; // ecx
  vostok::strings::shared::profile *v19; // eax
  vostok::render::backend *v20; // ecx
  volatile signed __int32 *v21; // edi
  vostok::strings::shared::manager *v22; // ecx
  vostok::strings::shared::profile *v23; // eax
  vostok::render::backend *v24; // ecx
  volatile signed __int32 *v25; // edi
  vostok::strings::shared::manager *v26; // ecx
  vostok::strings::shared::profile *v27; // eax
  vostok::render::backend *v28; // ecx
  volatile signed __int32 *v29; // edi
  vostok::strings::shared::manager *v30; // ecx
  vostok::strings::shared::profile *v31; // eax
  vostok::render::backend *v32; // ecx
  volatile signed __int32 *v33; // edi
  vostok::strings::shared::manager *v34; // ecx
  vostok::strings::shared::profile *v35; // eax
  vostok::render::backend *v36; // ecx
  volatile signed __int32 *v37; // edi
  vostok::strings::shared::manager *v38; // ecx
  vostok::strings::shared::profile *v39; // eax
  vostok::render::backend *v40; // ecx
  volatile signed __int32 *v41; // edi
  vostok::strings::shared::manager *v42; // ecx
  vostok::strings::shared::profile *v43; // eax
  vostok::render::backend *v44; // ecx
  volatile signed __int32 *v45; // edi
  vostok::strings::shared::manager *v46; // ecx
  vostok::strings::shared::profile *v47; // eax
  vostok::render::backend *v48; // ecx
  volatile signed __int32 *v49; // edi
  vostok::strings::shared::manager *v50; // ecx
  vostok::strings::shared::profile *v51; // eax
  vostok::render::backend *v52; // ecx
  volatile signed __int32 *v53; // edi
  vostok::strings::shared::manager *v54; // ecx
  vostok::strings::shared::profile *v55; // eax
  vostok::render::backend *v56; // ecx
  volatile signed __int32 *v57; // edi
  vostok::strings::shared::manager *v58; // ecx
  vostok::strings::shared::profile *v59; // eax
  vostok::render::backend *v60; // ecx
  volatile signed __int32 *v61; // edi
  vostok::strings::shared::manager *v62; // ecx
  vostok::strings::shared::profile *v63; // eax
  vostok::render::backend *v64; // ecx
  volatile signed __int32 *v65; // edi
  vostok::strings::shared::manager *v66; // ecx
  vostok::strings::shared::profile *v67; // eax
  vostok::render::backend *v68; // ecx
  volatile signed __int32 *v69; // edi
  vostok::strings::shared::manager *v70; // ecx
  vostok::strings::shared::profile *v71; // eax
  vostok::strings::shared::manager *v72; // ecx
  vostok::strings::shared::profile *v73; // eax
  vostok::strings::shared::manager *v74; // ecx
  vostok::strings::shared::profile *v75; // eax
  vostok::strings::shared::manager *v76; // ecx
  vostok::strings::shared::profile *v77; // eax
  vostok::strings::shared::manager *v78; // ecx
  vostok::strings::shared::profile *v79; // eax
  vostok::render::effect_options_descriptor *v80; // eax
  vostok::shared_string name; // [esp+Ch] [ebp-420h] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+10h] [ebp-41Ch] BYREF
  unsigned __int8 data[1024]; // [esp+28h] [ebp-404h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_gbuffer_vtbl *)&stru_963F84.m_rescale_min.elements[3];
  this->m_state.m_object = 0;
  this->m_copy_depth_rt.m_object = 0;
  this->m_fill_depth_effect.m_object = 0;
  this->m_fill_view_space_depth = 0;
  v3 = vostok::strings::shared::manager::string(
         (vostok::strings::shared::manager *)in_renderer,
         (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  name.m_pointer.m_object = 0;
  if ( v3 )
  {
    p_m_reference_count = &v3->m_reference_count;
    name.m_pointer.m_object = v3;
    v4 = (vostok::render::backend *)_InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  this->m_object_transparency_scale_parameter = vostok::render::backend::register_constant_host(
                                                  v4,
                                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                  &name,
                                                  rc_float);
  if ( p_m_reference_count )
  {
    v6 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v7 = vostok::strings::shared::manager::string(v6, (const char *)s_manager.m_variable);
  v9 = 0;
  name.m_pointer.m_object = 0;
  if ( v7 )
  {
    v9 = &v7->m_reference_count;
    name.m_pointer.m_object = v7;
    v8 = (vostok::render::backend *)_InterlockedExchangeAdd(&v7->m_reference_count, 1u);
  }
  this->m_c_start_corner = vostok::render::backend::register_constant_host(
                             v8,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             &name,
                             rc_float);
  if ( v9 )
  {
    v10 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v9, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v11 = vostok::strings::shared::manager::string(v10, (const char *)s_manager.m_variable);
  v13 = 0;
  name.m_pointer.m_object = 0;
  if ( v11 )
  {
    v13 = &v11->m_reference_count;
    name.m_pointer.m_object = v11;
    v12 = (vostok::render::backend *)_InterlockedExchangeAdd(&v11->m_reference_count, 1u);
  }
  this->m_far_fog_color_and_distance = vostok::render::backend::register_constant_host(
                                         v12,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v13 )
  {
    v14 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v13, 0xFFFFFFFF);
    if ( !v14 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v15 = vostok::strings::shared::manager::string(v14, (const char *)s_manager.m_variable);
  v17 = 0;
  name.m_pointer.m_object = 0;
  if ( v15 )
  {
    v17 = &v15->m_reference_count;
    name.m_pointer.m_object = v15;
    v16 = (vostok::render::backend *)_InterlockedExchangeAdd(&v15->m_reference_count, 1u);
  }
  this->m_c_bound_box_min = vostok::render::backend::register_constant_host(
                              v16,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v17 )
  {
    v18 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v17, 0xFFFFFFFF);
    if ( !v18 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v19 = vostok::strings::shared::manager::string(v18, (const char *)s_manager.m_variable);
  v21 = 0;
  name.m_pointer.m_object = 0;
  if ( v19 )
  {
    v21 = &v19->m_reference_count;
    name.m_pointer.m_object = v19;
    v20 = (vostok::render::backend *)_InterlockedExchangeAdd(&v19->m_reference_count, 1u);
  }
  this->m_c_bound_box_max = vostok::render::backend::register_constant_host(
                              v20,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v21 )
  {
    v22 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v21, 0xFFFFFFFF);
    if ( !v22 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v23 = vostok::strings::shared::manager::string(v22, (const char *)s_manager.m_variable);
  v25 = 0;
  name.m_pointer.m_object = 0;
  if ( v23 )
  {
    v25 = &v23->m_reference_count;
    name.m_pointer.m_object = v23;
    v24 = (vostok::render::backend *)_InterlockedExchangeAdd(&v23->m_reference_count, 1u);
  }
  this->m_c_sun_near_aabb_point = vostok::render::backend::register_constant_host(
                                    v24,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( v25 )
  {
    v26 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v25, 0xFFFFFFFF);
    if ( !v26 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v27 = vostok::strings::shared::manager::string(v26, (const char *)s_manager.m_variable);
  v29 = 0;
  name.m_pointer.m_object = 0;
  if ( v27 )
  {
    v29 = &v27->m_reference_count;
    name.m_pointer.m_object = v27;
    v28 = (vostok::render::backend *)_InterlockedExchangeAdd(&v27->m_reference_count, 1u);
  }
  this->m_near_fog_distance = vostok::render::backend::register_constant_host(
                                v28,
                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                &name,
                                rc_float);
  if ( v29 )
  {
    v30 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v29, 0xFFFFFFFF);
    if ( !v30 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v31 = vostok::strings::shared::manager::string(v30, (const char *)s_manager.m_variable);
  v33 = 0;
  name.m_pointer.m_object = 0;
  if ( v31 )
  {
    v33 = &v31->m_reference_count;
    name.m_pointer.m_object = v31;
    v32 = (vostok::render::backend *)_InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  this->m_fog_alpha = vostok::render::backend::register_constant_host(
                        v32,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v33 )
  {
    v34 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v33, 0xFFFFFFFF);
    if ( !v34 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v35 = vostok::strings::shared::manager::string(v34, (const char *)s_manager.m_variable);
  v37 = 0;
  name.m_pointer.m_object = 0;
  if ( v35 )
  {
    v37 = &v35->m_reference_count;
    name.m_pointer.m_object = v35;
    v36 = (vostok::render::backend *)_InterlockedExchangeAdd(&v35->m_reference_count, 1u);
  }
  this->m_ambient_color = vostok::render::backend::register_constant_host(
                            v36,
                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                            &name,
                            rc_float);
  if ( v37 )
  {
    v38 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v37, 0xFFFFFFFF);
    if ( !v38 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v39 = vostok::strings::shared::manager::string(v38, (const char *)s_manager.m_variable);
  v41 = 0;
  name.m_pointer.m_object = 0;
  if ( v39 )
  {
    v41 = &v39->m_reference_count;
    name.m_pointer.m_object = v39;
    v40 = (vostok::render::backend *)_InterlockedExchangeAdd(&v39->m_reference_count, 1u);
  }
  this->m_c_environment_skylight_upper_color = vostok::render::backend::register_constant_host(
                                                 v40,
                                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                 &name,
                                                 rc_float);
  if ( v41 )
  {
    v42 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v41, 0xFFFFFFFF);
    if ( !v42 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v43 = vostok::strings::shared::manager::string(v42, (const char *)s_manager.m_variable);
  v45 = 0;
  name.m_pointer.m_object = 0;
  if ( v43 )
  {
    v45 = &v43->m_reference_count;
    name.m_pointer.m_object = v43;
    v44 = (vostok::render::backend *)_InterlockedExchangeAdd(&v43->m_reference_count, 1u);
  }
  this->m_c_environment_skylight_lower_color = vostok::render::backend::register_constant_host(
                                                 v44,
                                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                 &name,
                                                 rc_float);
  if ( v45 )
  {
    v46 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v45, 0xFFFFFFFF);
    if ( !v46 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v47 = vostok::strings::shared::manager::string(v46, (const char *)s_manager.m_variable);
  v49 = 0;
  name.m_pointer.m_object = 0;
  if ( v47 )
  {
    v49 = &v47->m_reference_count;
    name.m_pointer.m_object = v47;
    v48 = (vostok::render::backend *)_InterlockedExchangeAdd(&v47->m_reference_count, 1u);
  }
  this->m_c_environment_skylight_parameters = vostok::render::backend::register_constant_host(
                                                v48,
                                                (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                &name,
                                                rc_float);
  if ( v49 )
  {
    v50 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v49, 0xFFFFFFFF);
    if ( !v50 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v51 = vostok::strings::shared::manager::string(v50, (const char *)s_manager.m_variable);
  v53 = 0;
  name.m_pointer.m_object = 0;
  if ( v51 )
  {
    v53 = &v51->m_reference_count;
    name.m_pointer.m_object = v51;
    v52 = (vostok::render::backend *)_InterlockedExchangeAdd(&v51->m_reference_count, 1u);
  }
  this->m_c_gs_test_constant = vostok::render::backend::register_constant_host(
                                 v52,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 &name,
                                 rc_float);
  if ( v53 )
  {
    v54 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v53, 0xFFFFFFFF);
    if ( !v54 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v55 = vostok::strings::shared::manager::string(v54, (const char *)s_manager.m_variable);
  v57 = 0;
  name.m_pointer.m_object = 0;
  if ( v55 )
  {
    v57 = &v55->m_reference_count;
    name.m_pointer.m_object = v55;
    v56 = (vostok::render::backend *)_InterlockedExchangeAdd(&v55->m_reference_count, 1u);
  }
  this->m_c_sun_direction = vostok::render::backend::register_constant_host(
                              v56,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v57 )
  {
    v58 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v57, 0xFFFFFFFF);
    if ( !v58 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v59 = vostok::strings::shared::manager::string(v58, (const char *)s_manager.m_variable);
  v61 = 0;
  name.m_pointer.m_object = 0;
  if ( v59 )
  {
    v61 = &v59->m_reference_count;
    name.m_pointer.m_object = v59;
    v60 = (vostok::render::backend *)_InterlockedExchangeAdd(&v59->m_reference_count, 1u);
  }
  this->m_c_translucency_max_scatter = vostok::render::backend::register_constant_host(
                                         v60,
                                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                         &name,
                                         rc_float);
  if ( v61 )
  {
    v62 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v61, 0xFFFFFFFF);
    if ( !v62 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v63 = vostok::strings::shared::manager::string(v62, (const char *)s_manager.m_variable);
  v65 = 0;
  name.m_pointer.m_object = 0;
  if ( v63 )
  {
    v65 = &v63->m_reference_count;
    name.m_pointer.m_object = v63;
    v64 = (vostok::render::backend *)_InterlockedExchangeAdd(&v63->m_reference_count, 1u);
  }
  this->m_c_sun_color = vostok::render::backend::register_constant_host(
                          v64,
                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                          &name,
                          rc_float);
  if ( v65 )
  {
    v66 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v65, 0xFFFFFFFF);
    if ( !v66 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v67 = vostok::strings::shared::manager::string(v66, (const char *)s_manager.m_variable);
  v69 = 0;
  name.m_pointer.m_object = 0;
  if ( v67 )
  {
    v69 = &v67->m_reference_count;
    name.m_pointer.m_object = v67;
    v68 = (vostok::render::backend *)_InterlockedExchangeAdd(&v67->m_reference_count, 1u);
  }
  this->m_shadow[0] = vostok::render::backend::register_constant_host(
                        v68,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( v69 )
  {
    v70 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v69, 0xFFFFFFFF);
    if ( !v70 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v71 = vostok::strings::shared::manager::string(v70, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v71);
  this->m_shadow[1] = vostok::render::backend::register_constant_host(
                        (vostok::render::backend *)&name,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( name.m_pointer.m_object )
  {
    v72 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v72 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v73 = vostok::strings::shared::manager::string(v72, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v73);
  this->m_shadow[2] = vostok::render::backend::register_constant_host(
                        (vostok::render::backend *)&name,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( name.m_pointer.m_object )
  {
    v74 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v74 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v75 = vostok::strings::shared::manager::string(v74, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v75);
  this->m_shadow[3] = vostok::render::backend::register_constant_host(
                        (vostok::render::backend *)&name,
                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                        &name,
                        rc_float);
  if ( name.m_pointer.m_object )
  {
    v76 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v76 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v77 = vostok::strings::shared::manager::string(v76, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v77);
  this->m_wind_info_parameters = vostok::render::backend::register_constant_host(
                                   (vostok::render::backend *)&name,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   &name,
                                   rc_float);
  if ( name.m_pointer.m_object )
  {
    v78 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(
                                                &name.m_pointer.m_object->m_reference_count,
                                                0xFFFFFFFF);
    if ( !v78 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v79 = vostok::strings::shared::manager::string(v78, (const char *)s_manager.m_variable);
  name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &name.m_pointer,
    v79);
  this->m_smoothness_multiplier = vostok::render::backend::register_constant_host(
                                    (vostok::render::backend *)&name,
                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                    &name,
                                    rc_float);
  if ( name.m_pointer.m_object && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy_depth_rt>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_copy_depth_rt);
  desc.data = &data[24];
  desc.type = 3;
  desc.bytes = 0;
  desc.count = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.memory_size = 1024;
  v80 = vostok::render::effect_options_descriptor::operator[](
          (vostok::render::effect_options_descriptor *)3,
          (int)&desc,
          (const char *)&key);
  vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(
    (vostok::render::effect_options_descriptor *)1,
    v80);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>(
    (vostok::render::effect_options_descriptor *)&this->m_fill_depth_effect,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 242);
}

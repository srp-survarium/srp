void __thiscall vostok::render::stage_light_propagation_volumes::register_light_constans(
        vostok::render::stage_light_propagation_volumes *this,
        vostok::render::stage_light_propagation_volumes *thisa)
{
  vostok::render::stage_light_propagation_volumes *v2; // ebx
  vostok::render::stage_light_propagation_volumes *v3; // eax
  vostok::render::backend *v4; // ecx
  volatile signed __int32 *v5; // esi
  vostok::strings::shared::manager *v6; // ecx
  vostok::render::stage_light_propagation_volumes *v7; // eax
  vostok::render::backend *v8; // ecx
  volatile signed __int32 *v9; // esi
  vostok::strings::shared::manager *v10; // ecx
  vostok::render::stage_light_propagation_volumes *v11; // eax
  vostok::render::backend *v12; // ecx
  volatile signed __int32 *v13; // esi
  vostok::strings::shared::manager *v14; // ecx
  vostok::render::stage_light_propagation_volumes *v15; // eax
  vostok::render::backend *v16; // ecx
  volatile signed __int32 *v17; // esi
  vostok::strings::shared::manager *v18; // ecx
  vostok::render::stage_light_propagation_volumes *v19; // eax
  vostok::render::backend *v20; // ecx
  volatile signed __int32 *v21; // esi
  vostok::strings::shared::manager *v22; // ecx
  vostok::render::stage_light_propagation_volumes *v23; // eax
  vostok::render::backend *v24; // ecx
  volatile signed __int32 *v25; // esi
  vostok::strings::shared::manager *v26; // ecx
  vostok::render::stage_light_propagation_volumes *v27; // eax
  vostok::render::backend *v28; // ecx
  volatile signed __int32 *v29; // esi
  vostok::strings::shared::manager *v30; // ecx
  vostok::render::stage_light_propagation_volumes *v31; // eax
  vostok::render::backend *v32; // ecx
  volatile signed __int32 *v33; // esi
  vostok::strings::shared::manager *v34; // ecx
  vostok::render::stage_light_propagation_volumes *v35; // eax
  vostok::render::backend *v36; // ecx
  volatile signed __int32 *v37; // esi
  vostok::strings::shared::manager *v38; // ecx
  vostok::render::stage_light_propagation_volumes *v39; // eax
  vostok::render::backend *v40; // ecx
  volatile signed __int32 *v41; // esi
  vostok::strings::shared::manager *v42; // ecx
  vostok::render::stage_light_propagation_volumes *v43; // eax
  vostok::render::backend *v44; // ecx
  volatile signed __int32 *v45; // esi
  vostok::strings::shared::manager *v46; // ecx
  vostok::render::stage_light_propagation_volumes *v47; // eax
  vostok::render::backend *v48; // ecx
  volatile signed __int32 *v49; // esi
  vostok::strings::shared::manager *v50; // ecx
  vostok::render::stage_light_propagation_volumes *v51; // eax
  vostok::render::backend *v52; // ecx
  volatile signed __int32 *v53; // esi
  vostok::strings::shared::manager *v54; // ecx
  vostok::render::stage_light_propagation_volumes *v55; // eax
  vostok::render::backend *v56; // ecx
  volatile signed __int32 *v57; // esi
  vostok::strings::shared::manager *v58; // ecx
  vostok::render::stage_light_propagation_volumes *v59; // eax
  vostok::render::backend *v60; // ecx
  volatile signed __int32 *v61; // esi
  vostok::strings::shared::manager *v62; // ecx
  vostok::render::stage_light_propagation_volumes *v63; // eax
  vostok::render::backend *v64; // ecx
  volatile signed __int32 *v65; // esi
  vostok::strings::shared::manager *v66; // ecx
  vostok::render::stage_light_propagation_volumes *v67; // eax
  vostok::render::backend *v68; // ecx
  volatile signed __int32 *v69; // esi
  vostok::strings::shared::manager *v70; // ecx
  vostok::strings::shared::profile *v71; // eax
  vostok::strings::shared::manager *v72; // ecx
  vostok::strings::shared::profile *v73; // eax
  vostok::strings::shared::manager *v74; // ecx
  vostok::strings::shared::profile *v75; // eax

  v2 = thisa;
  v3 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                            (vostok::strings::shared::manager *)this,
                                                            (const char *)s_manager.m_variable);
  v5 = 0;
  thisa = 0;
  if ( v3 )
  {
    v5 = (volatile signed __int32 *)v3;
    thisa = v3;
    v4 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v3, 1u);
  }
  v2->m_c_view_to_light_matrix = vostok::render::backend::register_constant_host(
                                   v4,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&thisa,
                                   rc_float);
  if ( v5 )
  {
    v6 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v5, 0xFFFFFFFF);
    if ( !v6 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v7 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                            v6,
                                                            (const char *)s_manager.m_variable);
  v9 = 0;
  thisa = 0;
  if ( v7 )
  {
    v9 = (volatile signed __int32 *)v7;
    thisa = v7;
    v8 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v7, 1u);
  }
  v2->m_c_light_color = vostok::render::backend::register_constant_host(
                          v8,
                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                          (const vostok::shared_string *)&thisa,
                          rc_float);
  if ( v9 )
  {
    v10 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v9, 0xFFFFFFFF);
    if ( !v10 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v11 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v10,
                                                             (const char *)s_manager.m_variable);
  v13 = 0;
  thisa = 0;
  if ( v11 )
  {
    v13 = (volatile signed __int32 *)v11;
    thisa = v11;
    v12 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v11, 1u);
  }
  v2->m_c_light_intensity = vostok::render::backend::register_constant_host(
                              v12,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              (const vostok::shared_string *)&thisa,
                              rc_float);
  if ( v13 )
  {
    v14 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v13, 0xFFFFFFFF);
    if ( !v14 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v15 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v14,
                                                             (const char *)s_manager.m_variable);
  v17 = 0;
  thisa = 0;
  if ( v15 )
  {
    v17 = (volatile signed __int32 *)v15;
    thisa = v15;
    v16 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v15, 1u);
  }
  v2->m_c_light_position = vostok::render::backend::register_constant_host(
                             v16,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&thisa,
                             rc_float);
  if ( v17 )
  {
    v18 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v17, 0xFFFFFFFF);
    if ( !v18 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v19 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v18,
                                                             (const char *)s_manager.m_variable);
  v21 = 0;
  thisa = 0;
  if ( v19 )
  {
    v21 = (volatile signed __int32 *)v19;
    thisa = v19;
    v20 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v19, 1u);
  }
  v2->m_c_light_direction = vostok::render::backend::register_constant_host(
                              v20,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              (const vostok::shared_string *)&thisa,
                              rc_float);
  if ( v21 )
  {
    v22 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v21, 0xFFFFFFFF);
    if ( !v22 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v23 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v22,
                                                             (const char *)s_manager.m_variable);
  v25 = 0;
  thisa = 0;
  if ( v23 )
  {
    v25 = (volatile signed __int32 *)v23;
    thisa = v23;
    v24 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v23, 1u);
  }
  v2->m_c_light_attenuation_power = vostok::render::backend::register_constant_host(
                                      v24,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      (const vostok::shared_string *)&thisa,
                                      rc_float);
  if ( v25 )
  {
    v26 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v25, 0xFFFFFFFF);
    if ( !v26 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v27 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v26,
                                                             (const char *)s_manager.m_variable);
  v29 = 0;
  thisa = 0;
  if ( v27 )
  {
    v29 = (volatile signed __int32 *)v27;
    thisa = v27;
    v28 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v27, 1u);
  }
  v2->m_c_light_range = vostok::render::backend::register_constant_host(
                          v28,
                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                          (const vostok::shared_string *)&thisa,
                          rc_float);
  if ( v29 )
  {
    v30 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v29, 0xFFFFFFFF);
    if ( !v30 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v31 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v30,
                                                             (const char *)s_manager.m_variable);
  v33 = 0;
  thisa = 0;
  if ( v31 )
  {
    v33 = (volatile signed __int32 *)v31;
    thisa = v31;
    v32 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v31, 1u);
  }
  v2->m_c_lighting_model = vostok::render::backend::register_constant_host(
                             v32,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&thisa,
                             rc_int);
  if ( v33 )
  {
    v34 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v33, 0xFFFFFFFF);
    if ( !v34 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v35 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v34,
                                                             (const char *)s_manager.m_variable);
  v37 = 0;
  thisa = 0;
  if ( v35 )
  {
    v37 = (volatile signed __int32 *)v35;
    thisa = v35;
    v36 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v35, 1u);
  }
  v2->m_c_diffuse_influence_factor = vostok::render::backend::register_constant_host(
                                       v36,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       (const vostok::shared_string *)&thisa,
                                       rc_float);
  if ( v37 )
  {
    v38 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v37, 0xFFFFFFFF);
    if ( !v38 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v39 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v38,
                                                             (const char *)s_manager.m_variable);
  v41 = 0;
  thisa = 0;
  if ( v39 )
  {
    v41 = (volatile signed __int32 *)v39;
    thisa = v39;
    v40 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v39, 1u);
  }
  v2->m_c_specular_influence_factor = vostok::render::backend::register_constant_host(
                                        v40,
                                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                        (const vostok::shared_string *)&thisa,
                                        rc_float);
  if ( v41 )
  {
    v42 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v41, 0xFFFFFFFF);
    if ( !v42 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v43 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v42,
                                                             (const char *)s_manager.m_variable);
  v45 = 0;
  thisa = 0;
  if ( v43 )
  {
    v45 = (volatile signed __int32 *)v43;
    thisa = v43;
    v44 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v43, 1u);
  }
  v2->m_c_light_spot_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                    v44,
                                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                    (const vostok::shared_string *)&thisa,
                                                    rc_float);
  if ( v45 )
  {
    v46 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v45, 0xFFFFFFFF);
    if ( !v46 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v47 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v46,
                                                             (const char *)s_manager.m_variable);
  v49 = 0;
  thisa = 0;
  if ( v47 )
  {
    v49 = (volatile signed __int32 *)v47;
    thisa = v47;
    v48 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v47, 1u);
  }
  v2->m_c_light_spot_umbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                 v48,
                                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                 (const vostok::shared_string *)&thisa,
                                                 rc_float);
  if ( v49 )
  {
    v50 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v49, 0xFFFFFFFF);
    if ( !v50 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v51 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v50,
                                                             (const char *)s_manager.m_variable);
  v53 = 0;
  thisa = 0;
  if ( v51 )
  {
    v53 = (volatile signed __int32 *)v51;
    thisa = v51;
    v52 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v51, 1u);
  }
  v2->m_c_light_spot_inversed_umbra_half_angle_cosine_minus_penumbra_half_angle_cosine = vostok::render::backend::register_constant_host(
                                                                                           v52,
                                                                                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                                                           (const vostok::shared_string *)&thisa,
                                                                                           rc_float);
  if ( v53 )
  {
    v54 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v53, 0xFFFFFFFF);
    if ( !v54 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v55 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v54,
                                                             (const char *)s_manager.m_variable);
  v57 = 0;
  thisa = 0;
  if ( v55 )
  {
    v57 = (volatile signed __int32 *)v55;
    thisa = v55;
    v56 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v55, 1u);
  }
  v2->m_c_light_spot_falloff = vostok::render::backend::register_constant_host(
                                 v56,
                                 (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                 (const vostok::shared_string *)&thisa,
                                 rc_float);
  if ( v57 )
  {
    v58 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v57, 0xFFFFFFFF);
    if ( !v58 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v59 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v58,
                                                             (const char *)s_manager.m_variable);
  v61 = 0;
  thisa = 0;
  if ( v59 )
  {
    v61 = (volatile signed __int32 *)v59;
    thisa = v59;
    v60 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v59, 1u);
  }
  v2->m_c_light_type = vostok::render::backend::register_constant_host(
                         v60,
                         (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                         (const vostok::shared_string *)&thisa,
                         rc_int);
  if ( v61 )
  {
    v62 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v61, 0xFFFFFFFF);
    if ( !v62 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v63 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v62,
                                                             (const char *)s_manager.m_variable);
  v65 = 0;
  thisa = 0;
  if ( v63 )
  {
    v65 = (volatile signed __int32 *)v63;
    thisa = v63;
    v64 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v63, 1u);
  }
  v2->m_c_light_capsule_half_width = vostok::render::backend::register_constant_host(
                                       v64,
                                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                       (const vostok::shared_string *)&thisa,
                                       rc_float);
  if ( v65 )
  {
    v66 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v65, 0xFFFFFFFF);
    if ( !v66 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v67 = (vostok::render::stage_light_propagation_volumes *)vostok::strings::shared::manager::string(
                                                             v66,
                                                             (const char *)s_manager.m_variable);
  v69 = 0;
  thisa = 0;
  if ( v67 )
  {
    v69 = (volatile signed __int32 *)v67;
    thisa = v67;
    v68 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v67, 1u);
  }
  v2->m_c_light_capsule_radius = vostok::render::backend::register_constant_host(
                                   v68,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&thisa,
                                   rc_float);
  if ( v69 )
  {
    v70 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v69, 0xFFFFFFFF);
    if ( !v70 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v71 = vostok::strings::shared::manager::string(v70, (const char *)s_manager.m_variable);
  thisa = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&thisa,
    v71);
  v2->m_c_light_sphere_radius = vostok::render::backend::register_constant_host(
                                  (vostok::render::backend *)&thisa,
                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                  (const vostok::shared_string *)&thisa,
                                  rc_float);
  if ( thisa )
  {
    v72 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd((volatile signed __int32 *)thisa, 0xFFFFFFFF);
    if ( !v72 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v73 = vostok::strings::shared::manager::string(v72, (const char *)s_manager.m_variable);
  thisa = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&thisa,
    v73);
  v2->m_c_light_local_to_world = vostok::render::backend::register_constant_host(
                                   (vostok::render::backend *)&thisa,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&thisa,
                                   rc_float);
  if ( thisa )
  {
    v74 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd((volatile signed __int32 *)thisa, 0xFFFFFFFF);
    if ( !v74 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v75 = vostok::strings::shared::manager::string(v74, (const char *)s_manager.m_variable);
  thisa = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&thisa,
    v75);
  v2->m_c_light_sphere_radius = vostok::render::backend::register_constant_host(
                                  (vostok::render::backend *)&thisa,
                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                  (const vostok::shared_string *)&thisa,
                                  rc_float);
  if ( thisa )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)thisa, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}

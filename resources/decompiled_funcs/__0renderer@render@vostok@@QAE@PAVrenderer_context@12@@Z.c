void __thiscall vostok::render::renderer::renderer(
        vostok::render::renderer *this,
        vostok::render::renderer *renderer_context,
        vostok::render::renderer_context *renderer_contexta)
{
  vostok::render::renderer_context *v3; // ebp
  char *v4; // ebx
  vostok::render::renderer_context *v5; // eax
  survarium::game_action_id *M_start; // eax
  __int64 v7; // xmm1_8
  __int64 v8; // xmm0_8
  vostok::strings::shared::manager *v9; // ecx
  vostok::render::renderer_context *v10; // eax
  vostok::render::backend *v11; // ecx
  volatile signed __int32 *v12; // esi
  vostok::strings::shared::manager *v13; // ecx
  vostok::render::renderer_context *v14; // eax
  vostok::render::backend *v15; // ecx
  volatile signed __int32 *v16; // esi
  vostok::strings::shared::manager *v17; // ecx
  vostok::render::renderer_context *v18; // eax
  vostok::render::backend *v19; // ecx
  volatile signed __int32 *v20; // esi
  vostok::strings::shared::manager *v21; // ecx
  vostok::render::renderer_context *v22; // eax
  vostok::render::backend *v23; // ecx
  volatile signed __int32 *v24; // esi
  _DWORD *i; // eax
  vostok::render::stage_gbuffer *v26; // esi
  int v27; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v28; // eax
  unsigned int v29; // esi
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx
  _BYTE *v31; // eax
  int v32; // ecx
  survarium::game_action_id *v33; // edx
  vostok::render::stage_pre_rain *v34; // edx
  int v35; // eax
  _DWORD *v36; // eax
  vostok::render::stage_ambient_occlusion *v37; // esi
  int v38; // eax
  vostok::render::stage_ambient_lighting *v39; // eax
  int v40; // eax
  vostok::render::stage_shadow_direct *v41; // eax
  int v42; // eax
  vostok::render::stage_sun *v43; // eax
  int v44; // eax
  vostok::render::stage_lights *v45; // eax
  int v46; // eax
  vostok::render::stage_light_propagation_volumes *v47; // eax
  int v48; // eax
  vostok::render::stage_translucency *v49; // esi
  int v50; // eax
  vostok::render::stage_resolve_lighting *v51; // esi
  int v52; // eax
  vostok::render::stage_clouds *v53; // eax
  int v54; // eax
  vostok::render::stage_atmosphere *v55; // esi
  int v56; // eax
  vostok::render::stage_forward *v57; // esi
  int v58; // eax
  vostok::render::stage_atmosphere *v59; // esi
  int v60; // eax
  vostok::render::stage_forward *v61; // esi
  int v62; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v63; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v64; // esi
  vostok::render::effect_manager *v65; // ecx
  vostok::render::stage_rain *v66; // edx
  int v67; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v68; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v69; // esi
  survarium::game_action_id *v70; // edx
  vostok::render::stage_lights *v71; // eax
  int v72; // eax
  vostok::render::stage_volume_fog *v73; // esi
  int v74; // eax
  vostok::render::stage_postprocess *v75; // eax
  int v76; // eax
  vostok::render::stage_visibility *v77; // edx
  int v78; // eax
  vostok::render::stage_debug *v79; // esi
  int v80; // eax
  vostok::render::stage_view_mode *v81; // esi
  int v82; // eax
  vostok::render::stage_screen_image *v83; // edi
  int v84; // eax
  _DWORD *v85; // eax
  _DWORD *v86; // esi
  survarium::game *m_game; // edx
  int x; // eax
  _DWORD *v89; // eax
  _DWORD *v90; // esi
  survarium::game *v91; // ecx
  int v92; // eax
  LARGE_INTEGER v93; // rax
  vostok::render *v94; // [esp+0h] [ebp-64h]
  LARGE_INTEGER PerformanceCount; // [esp+10h] [ebp-54h] BYREF
  __int64 v96; // [esp+18h] [ebp-4Ch]
  vostok::math::float4x4 v97; // [esp+20h] [ebp-44h] BYREF

  v3 = (vostok::render::renderer_context *)renderer_context;
  vostok::timing::timer::timer(&renderer_context->m_timing_timer);
  `vector constructor iterator'(
    &v3->m_family[0].name.m_buffer[12],
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    &v3->m_family[0].name.m_buffer[28],
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    &v3->m_family[0].name.m_buffer[44],
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  v4 = &v3->m_family[1].orig_name.m_buffer[40];
  *(_DWORD *)&v3->m_family[1].orig_name.m_buffer[40] = &v3->m_family[1].orig_name.m_buffer[48];
  *(_DWORD *)&v3->m_family[1].orig_name.m_buffer[44] = &v3->m_family[1].orig_name.m_buffer[48];
  v5 = renderer_contexta;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[4] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[8] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[16] = v5;
  vostok::timing::timer::timer((vostok::timing::timer *)&v3->m_family[2].orig_name.m_buffer[40]);
  vostok::timing::timer::timer((vostok::timing::timer *)&v3->m_family[2].name);
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[28] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[32] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[36] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[40] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[44] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[48] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[52] = 0;
  *(_DWORD *)&v3->m_family[2].name.m_buffer[56] = 0;
  vostok::render::cloud_simulation::cloud_simulation(
    *((_DWORD *)M_start + 27),
    *((_DWORD *)M_start + 28),
    (vostok::render::cloud_simulation *)&v3->m_family[2].target,
    *((_DWORD *)M_start + 27));
  *(_DWORD *)&v3->m_family[3].name.m_buffer[4] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&v3->m_family[3].name.m_buffer[12], 0x2710u);
  *(_DWORD *)&v3->m_family[3].name.m_buffer[40] = 0;
  *(_DWORD *)&v3->m_family[3].name.m_buffer[44] = 0;
  vostok::render::register_samplers(v94);
  *(_QWORD *)&v3->m_family[0].name.m_buffer[60] = 0;
  *(_QWORD *)&v3->m_family[0].texture.m_object = 0;
  *(_QWORD *)&v3->m_family[1].orig_name.m_end = 0;
  *(_QWORD *)v3->m_family[1].orig_name.m_buffer = 0;
  v96 = 0;
  *(_QWORD *)&v3->m_family[1].orig_name.m_buffer[8] = 0;
  PerformanceCount.QuadPart = 0;
  *(_QWORD *)&v3->m_family[1].orig_name.m_buffer[16] = v96;
  v96 = 0;
  *(LARGE_INTEGER *)&v3->m_family[1].orig_name.m_buffer[24] = PerformanceCount;
  v7 = v96;
  PerformanceCount.QuadPart = 0;
  v96 = 0;
  *(_QWORD *)&v3->m_family[3].name.m_buffer[52] = 0;
  v8 = v96;
  *(_QWORD *)&v3->m_family[1].orig_name.m_buffer[32] = v7;
  LOBYTE(v3->m_targets) = 0;
  *(_QWORD *)&v3->m_family[3].name.m_buffer[60] = v8;
  vostok::render::material::initialize_nomaterial_material();
  vostok::render::effect_manager::create_effect<vostok::render::effect_pick_light_luminance>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)&v3->m_family[2].name.m_buffer[44]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_gbuffer_to_screen>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)&v3->m_family[2].name.m_buffer[28]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fill_environment_probe_face>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)&v3->m_family[2].name.m_buffer[32]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_fill_sky_ao_map>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)&v3->m_family[2].name.m_buffer[40]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_grass_trample>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)&v3->m_family[2].name.m_buffer[48]);
  v10 = (vostok::render::renderer_context *)vostok::strings::shared::manager::string(
                                              v9,
                                              (const char *)s_manager.m_variable);
  v12 = 0;
  renderer_context = 0;
  if ( v10 )
  {
    v12 = (volatile signed __int32 *)v10;
    renderer_context = (vostok::render::renderer *)v10;
    v11 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v10, 1u);
  }
  *(_DWORD *)&v3->m_family[2].name.m_buffer[24] = vostok::render::backend::register_constant_host(
                                                    v11,
                                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                    (const vostok::shared_string *)&renderer_context,
                                                    rc_float);
  if ( v12 )
  {
    v13 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v12, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v14 = (vostok::render::renderer_context *)vostok::strings::shared::manager::string(
                                              v13,
                                              (const char *)s_manager.m_variable);
  v16 = 0;
  renderer_context = 0;
  if ( v14 )
  {
    v16 = (volatile signed __int32 *)v14;
    renderer_context = (vostok::render::renderer *)v14;
    v15 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v14, 1u);
  }
  *(_DWORD *)&v3->m_family[2].name.m_buffer[12] = vostok::render::backend::register_constant_host(
                                                    v15,
                                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                    (const vostok::shared_string *)&renderer_context,
                                                    rc_int);
  if ( v16 )
  {
    v17 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v16, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v18 = (vostok::render::renderer_context *)vostok::strings::shared::manager::string(
                                              v17,
                                              (const char *)s_manager.m_variable);
  v20 = 0;
  renderer_context = 0;
  if ( v18 )
  {
    v20 = (volatile signed __int32 *)v18;
    renderer_context = (vostok::render::renderer *)v18;
    v19 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v18, 1u);
  }
  *(_DWORD *)&v3->m_family[2].name.m_buffer[16] = vostok::render::backend::register_constant_host(
                                                    v19,
                                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                    (const vostok::shared_string *)&renderer_context,
                                                    rc_float);
  if ( v20 )
  {
    v21 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v20, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v22 = (vostok::render::renderer_context *)vostok::strings::shared::manager::string(
                                              v21,
                                              (const char *)s_manager.m_variable);
  v24 = 0;
  renderer_context = 0;
  if ( v22 )
  {
    v24 = (volatile signed __int32 *)v22;
    renderer_context = (vostok::render::renderer *)v22;
    v23 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v22, 1u);
  }
  *(_DWORD *)&v3->m_family[2].name.m_buffer[20] = vostok::render::backend::register_constant_host(
                                                    v23,
                                                    (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                                    (const vostok::shared_string *)&renderer_context,
                                                    rc_float);
  if ( v24 && !_InterlockedExchangeAdd(v24, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  qmemcpy(v3->m_family, vostok::math::float4x4::identity(&v97), 0x40u);
  vostok::buffer_vector<vostok::render::stage *>::resize(0, (int *)&v3->m_family[1].orig_name.m_buffer[40]);
  for ( i = *(_DWORD **)v4; i != *(_DWORD **)&v3->m_family[1].orig_name.m_buffer[44]; ++i )
    *i = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[28] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[24] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[20] = 0;
  v26 = (vostok::render::stage_gbuffer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x7Cu);
  if ( v26 )
    vostok::render::stage_gbuffer::stage_gbuffer(
      v26,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v27 = 0;
  **(_DWORD **)v4 = v27;
  v28 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::memory::doug_lea_allocator::malloc_impl((vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object, 0x18u);
  v29 = (unsigned int)v28;
  if ( v28 )
  {
    m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
    v28[1].m_object = *(vostok::render::res_effect **)&v3->m_family[2].orig_name.m_buffer[16];
    v28[2].m_object = (vostok::render::res_effect *)v3;
    LOBYTE(v28[3].m_object) = 1;
    BYTE1(v28[3].m_object) = 1;
    v28->m_object = (vostok::render::res_effect *)&stru_963F84.m_desc.SampleDesc.Quality;
    v28[4].m_object = 0;
    v28[5].m_object = 0;
    vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
      m_conflicted_action_to_bind,
      v28 + 4);
    vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>(
      (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
      (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)(v29 + 20));
    *(_BYTE *)(v29 + 12) = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                           + 245);
  }
  else
  {
    v29 = 0;
  }
  *(_DWORD *)(*(_DWORD *)v4 + 4) = v29;
  v31 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          0x10u);
  if ( v31 )
  {
    v32 = *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[16];
    v33 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
    v31[12] = 1;
    *((_DWORD *)v31 + 1) = v32;
    *((_DWORD *)v31 + 2) = v3;
    v31[13] = 1;
    *(_DWORD *)v31 = &stru_963F84.m_name.m_string.m_end;
    v31[12] = *((_BYTE *)v33 + 246);
  }
  else
  {
    v31 = 0;
  }
  *(_DWORD *)(*(_DWORD *)v4 + 8) = v31;
  v34 = (vostok::render::stage_pre_rain *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x3Cu);
  if ( v34 )
    vostok::render::stage_pre_rain::stage_pre_rain(
      v34,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      (unsigned int)v3,
      v29);
  else
    v35 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 12) = v35;
  v36 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          0x10u);
  if ( v36 )
  {
    v36[1] = *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[16];
    v36[2] = v3;
    *((_BYTE *)v36 + 12) = 1;
    *((_BYTE *)v36 + 13) = 1;
    *v36 = &vostok::render::stage_pre_lighting::`vftable';
  }
  else
  {
    v36 = 0;
  }
  *(_DWORD *)(*(_DWORD *)v4 + 16) = v36;
  v37 = (vostok::render::stage_ambient_occlusion *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                     (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                     0x40u);
  if ( v37 )
    vostok::render::stage_ambient_occlusion::stage_ambient_occlusion(
      v37,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v38 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 20) = v38;
  v39 = (vostok::render::stage_ambient_lighting *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                    0xA4u);
  if ( v39 )
    vostok::render::stage_ambient_lighting::stage_ambient_lighting(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v39);
  else
    v40 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 24) = v40;
  v41 = (vostok::render::stage_shadow_direct *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                 0xABCu);
  if ( v41 )
    vostok::render::stage_shadow_direct::stage_shadow_direct(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v41);
  else
    v42 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 28) = v42;
  v43 = (vostok::render::stage_sun *)vostok::memory::doug_lea_allocator::malloc_impl(
                                       (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                       0x78u);
  if ( v43 )
    vostok::render::stage_sun::stage_sun(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v43,
      (vostok::render::cloud_interp_textures *)&v3->m_family[2].orig_name.m_buffer[4],
      (vostok::render::cloud_simulation *)&v3->m_family[2].target);
  else
    v44 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 32) = v44;
  v45 = (vostok::render::stage_lights *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                          0x9E8u);
  if ( v45 )
    vostok::render::stage_lights::stage_lights(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v45,
      0);
  else
    v46 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 36) = v46;
  v47 = (vostok::render::stage_light_propagation_volumes *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                             0x360u);
  if ( v47 )
    vostok::render::stage_light_propagation_volumes::stage_light_propagation_volumes(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v47);
  else
    v48 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 40) = v48;
  v49 = (vostok::render::stage_translucency *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                0x30u);
  if ( v49 )
    vostok::render::stage_translucency::stage_translucency(
      v49,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v50 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 44) = v50;
  v51 = (vostok::render::stage_resolve_lighting *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                    (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                    0x20u);
  if ( v51 )
    vostok::render::stage_resolve_lighting::stage_resolve_lighting(
      v51,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v52 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 48) = v52;
  v53 = (vostok::render::stage_clouds *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                          0x1B8u);
  if ( v53 )
    vostok::render::stage_clouds::stage_clouds(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v53,
      (vostok::render::cloud_interp_textures *)&v3->m_family[2].orig_name.m_buffer[4],
      (vostok::render::cloud_simulation *)&v3->m_family[2].target);
  else
    v54 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 60) = v54;
  v55 = (vostok::render::stage_atmosphere *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x6Cu);
  if ( v55 )
    vostok::render::stage_atmosphere::stage_atmosphere(
      v55,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      0);
  else
    v56 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 64) = v56;
  v57 = (vostok::render::stage_forward *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x8Cu);
  if ( v57 )
    vostok::render::stage_forward::stage_forward(
      v57,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      forward_base);
  else
    v58 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 68) = v58;
  v59 = (vostok::render::stage_atmosphere *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x6Cu);
  if ( v59 )
    vostok::render::stage_atmosphere::stage_atmosphere(
      v59,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      (vostok::strings::shared::profile *)1);
  else
    v60 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 72) = v60;
  v61 = (vostok::render::stage_forward *)vostok::memory::doug_lea_allocator::malloc_impl(
                                           (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                           0x8Cu);
  if ( v61 )
    vostok::render::stage_forward::stage_forward(
      v61,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      forward_sky);
  else
    v62 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 80) = v62;
  v63 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::memory::doug_lea_allocator::malloc_impl((vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object, 0x14u);
  v64 = v63;
  if ( v63 )
  {
    v65 = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
    v63[1].m_object = *(vostok::render::res_effect **)&v3->m_family[2].orig_name.m_buffer[16];
    v63[2].m_object = (vostok::render::res_effect *)v3;
    LOBYTE(v63[3].m_object) = 1;
    BYTE1(v63[3].m_object) = 1;
    v63->m_object = (vostok::render::res_effect *)&stru_965008.m_sh_res_view;
    v63[4].m_object = 0;
    vostok::render::effect_manager::create_effect<vostok::render::effect_apply_distortion>(v65, v63 + 4);
  }
  else
  {
    v64 = 0;
  }
  *(_DWORD *)(*(_DWORD *)v4 + 76) = v64;
  v66 = (vostok::render::stage_rain *)vostok::memory::doug_lea_allocator::malloc_impl(
                                        (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                        0x38Cu);
  if ( v66 )
    vostok::render::stage_rain::stage_rain(
      v66,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v67 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 84) = v67;
  v68 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::memory::doug_lea_allocator::malloc_impl((vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object, 0x2Cu);
  v69 = v68;
  if ( v68 )
  {
    v70 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
    v68[1].m_object = *(vostok::render::res_effect **)&v3->m_family[2].orig_name.m_buffer[16];
    LOBYTE(v68[3].m_object) = 1;
    v68[2].m_object = (vostok::render::res_effect *)v3;
    BYTE1(v68[3].m_object) = 1;
    v68->m_object = (vostok::render::res_effect *)&vostok::render::stage_particles::`vftable';
    v68[5].m_object = 0;
    v68[6].m_object = 0;
    v68[7].m_object = 0;
    v68[8].m_object = 0;
    v68[9].m_object = 0;
    v68[10].m_object = 0;
    LOBYTE(v68[3].m_object) = *((_BYTE *)v70 + 254);
    vostok::render::effect_manager::create_effect<vostok::render::effect_resolve_particles>(
      (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
      v68 + 7);
  }
  else
  {
    v69 = 0;
  }
  *(_DWORD *)(*(_DWORD *)v4 + 92) = v69;
  v71 = (vostok::render::stage_lights *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                          0x9E8u);
  if ( v71 )
    vostok::render::stage_lights::stage_lights(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v71,
      (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>)1);
  else
    v72 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 88) = v72;
  v73 = (vostok::render::stage_volume_fog *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x60u);
  if ( v73 )
    vostok::render::stage_volume_fog::stage_volume_fog(
      v73,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v74 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 96) = v74;
  v75 = (vostok::render::stage_postprocess *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0x23Cu);
  if ( v75 )
    vostok::render::stage_postprocess::stage_postprocess(
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16],
      v75);
  else
    v76 = 0;
  *(_DWORD *)(*(_DWORD *)v4 + 100) = v76;
  v77 = (vostok::render::stage_visibility *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x28u);
  if ( v77 )
    vostok::render::stage_visibility::stage_visibility(
      v77,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v78 = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[32] = v78;
  v79 = (vostok::render::stage_debug *)vostok::memory::doug_lea_allocator::malloc_impl(
                                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                         0x2Cu);
  if ( v79 )
    vostok::render::stage_debug::stage_debug(
      v79,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v80 = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[28] = v80;
  v81 = (vostok::render::stage_view_mode *)vostok::memory::doug_lea_allocator::malloc_impl(
                                             (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                             0x1A8u);
  if ( v81 )
    vostok::render::stage_view_mode::stage_view_mode(
      v81,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v82 = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[24] = v82;
  v83 = (vostok::render::stage_screen_image *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                0x2Cu);
  if ( v83 )
    vostok::render::stage_screen_image::stage_screen_image(
      v83,
      (vostok::render::renderer *)v3,
      *(vostok::render::renderer_context **)&v3->m_family[2].orig_name.m_buffer[16]);
  else
    v84 = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[20] = v84;
  v85 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          4u);
  v86 = v85;
  if ( v85 )
  {
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *v85 = 0;
    x = m_game->m_game_world.m_mouse_pos.x;
    PerformanceCount.QuadPart = 0;
    (*(void (__stdcall **)(int, LARGE_INTEGER *, _DWORD *))(*(_DWORD *)x + 96))(x, &PerformanceCount, v86);
  }
  else
  {
    v86 = 0;
  }
  *(_DWORD *)&v3->m_family[0].name.m_buffer[8] = v86;
  v89 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          4u);
  v90 = v89;
  if ( v89 )
  {
    v91 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    *v89 = 0;
    v92 = v91->m_game_world.m_mouse_pos.x;
    PerformanceCount.QuadPart = 0;
    (*(void (__stdcall **)(int, LARGE_INTEGER *, _DWORD *))(*(_DWORD *)v92 + 96))(v92, &PerformanceCount, v90);
  }
  else
  {
    v90 = 0;
  }
  *(_DWORD *)&v3->m_family[0].name.m_buffer[4] = v90;
  if ( vostok::timing::g_cpu_supports_time_stamp )
  {
    v93.QuadPart = __rdtsc();
  }
  else
  {
    QueryPerformanceCounter(&PerformanceCount);
    v93 = PerformanceCount;
  }
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[48] = v93.LowPart;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[40] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[44] = 0;
  *(_DWORD *)&v3->m_family[2].orig_name.m_buffer[52] = v93.HighPart;
}

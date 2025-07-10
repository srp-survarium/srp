void __userpurge vostok::render::stage_ambient_lighting::stage_ambient_lighting(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_ambient_lighting *this)
{
  vostok::render::stage_ambient_lighting *v3; // ebx
  char *m_environment_probe_lighting_effect; // esi
  const vostok::math::float4x4 *v5; // xmm0_4
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx
  vostok::strings::shared::manager *v7; // ecx
  vostok::render::stage_ambient_lighting *v8; // eax
  vostok::render::backend *v9; // ecx
  volatile signed __int32 *v10; // edi
  vostok::strings::shared::manager *v11; // ecx
  vostok::render::stage_ambient_lighting *v12; // eax
  vostok::render::backend *v13; // ecx
  volatile signed __int32 *v14; // edi
  vostok::strings::shared::manager *v15; // ecx
  vostok::render::stage_ambient_lighting *v16; // eax
  vostok::render::backend *v17; // ecx
  volatile signed __int32 *v18; // edi
  vostok::strings::shared::manager *v19; // ecx
  vostok::render::stage_ambient_lighting *v20; // eax
  vostok::render::backend *v21; // ecx
  volatile signed __int32 *v22; // edi
  vostok::strings::shared::manager *v23; // ecx
  vostok::render::stage_ambient_lighting *v24; // eax
  vostok::render::backend *v25; // ecx
  volatile signed __int32 *v26; // edi
  vostok::strings::shared::manager *v27; // ecx
  vostok::render::stage_ambient_lighting *v28; // eax
  vostok::render::backend *v29; // ecx
  volatile signed __int32 *v30; // edi
  vostok::strings::shared::manager *v31; // ecx
  vostok::render::stage_ambient_lighting *v32; // eax
  vostok::render::backend *v33; // ecx
  volatile signed __int32 *v34; // edi
  vostok::strings::shared::manager *v35; // ecx
  vostok::render::stage_ambient_lighting *v36; // eax
  vostok::render::backend *v37; // ecx
  volatile signed __int32 *v38; // edi
  vostok::strings::shared::manager *v39; // ecx
  vostok::render::stage_ambient_lighting *v40; // eax
  vostok::render::backend *v41; // ecx
  volatile signed __int32 *v42; // edi
  vostok::strings::shared::manager *v43; // ecx
  vostok::render::stage_ambient_lighting *v44; // eax
  vostok::render::backend *v45; // ecx
  volatile signed __int32 *v46; // edi
  vostok::strings::shared::manager *v47; // ecx
  vostok::render::stage_ambient_lighting *v48; // eax
  vostok::render::backend *v49; // ecx
  volatile signed __int32 *v50; // edi
  vostok::strings::shared::manager *v51; // ecx
  vostok::render::stage_ambient_lighting *v52; // eax
  vostok::render::backend *v53; // ecx
  volatile signed __int32 *v54; // edi
  vostok::strings::shared::manager *v55; // ecx
  vostok::render::stage_ambient_lighting *v56; // eax
  vostok::render::backend *v57; // ecx
  volatile signed __int32 *v58; // edi
  vostok::strings::shared::manager *v59; // ecx
  vostok::render::stage_ambient_lighting *v60; // eax
  vostok::render::backend *v61; // ecx
  volatile signed __int32 *v62; // edi
  vostok::strings::shared::manager *v63; // ecx
  vostok::render::stage_ambient_lighting *v64; // eax
  vostok::render::backend *v65; // ecx
  void *(__thiscall *v66)(void *); // edi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v68; // ecx
  vostok::render::res_state *m_object; // edi
  bool v70; // zf
  vostok::render::untyped_buffer *v71; // eax
  vostok::render::untyped_buffer *v72; // ecx
  vostok::render::res_state *v73; // edi
  vostok::render::untyped_buffer *v74; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v76; // ecx
  vostok::render::res_geometry *v77; // eax
  vostok::render::untyped_buffer *v78; // eax
  vostok::render::res_state *v79; // edi
  void *v80; // esp
  vostok::render::untyped_buffer *v81; // eax
  vostok::render::res_state *v82; // edi
  vostok::render::res_geometry *v83; // eax
  vostok::render::res_geometry *v84; // ecx
  vostok::render::res_geometry *v85; // eax
  unsigned __int8 v86[56]; // [esp-48h] [ebp-74h] BYREF
  char *v87; // [esp-10h] [ebp-3Ch]
  unsigned int v88; // [esp-Ch] [ebp-38h]
  int v89; // [esp-8h] [ebp-34h]
  void *(__thiscall *v90)(void *); // [esp-4h] [ebp-30h]
  D3D11_INPUT_ELEMENT_DESC desc[1]; // [esp+10h] [ebp-1Ch] BYREF

  v3 = this;
  v90 = (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>;
  v89 = 8;
  v88 = 4;
  m_environment_probe_lighting_effect = (char *)this->m_environment_probe_lighting_effect;
  this->m_context = context;
  v3->m_renderer = in_renderer;
  v3->m_enabled = 1;
  v3->m_prev_enabled = 1;
  v3->__vftable = (vostok::render::stage_ambient_lighting_vtbl *)&stru_9642F8.m_name.m_string.m_max_end;
  v87 = m_environment_probe_lighting_effect;
  v3->m_effect_accum_mask.m_object = 0;
  `vector constructor iterator'(v87, v88, v89, v90);
  v5 = clear_value;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  v3->m_skylight_effect.m_object = 0;
  v3->m_sky_ambient_occlusion_effect.m_object = 0;
  v3->m_ambient_volume_effect.m_object = 0;
  v3->m_reflection_mask_effect.m_object = 0;
  v3->m_sh_ssao_downsample_position_and_normal.m_object = 0;
  LODWORD(v3->m_ambient_multiplier) = v5;
  v3->m_use_probes = 1;
  v3->m_sphere_vertex_buffer.m_object = 0;
  v3->m_sphere_index_buffer.m_object = 0;
  v3->m_sphere_geometry.m_object = 0;
  v3->m_box_vertex_buffer.m_object = 0;
  v3->m_box_index_buffer.m_object = 0;
  v3->m_box_geometry.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_light_mask>(
    m_conflicted_action_to_bind,
    &v3->m_effect_accum_mask);
  vostok::render::effect_manager::create_effect<vostok::render::effect_sky_ambient_occlusion>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_sky_ambient_occlusion_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ambient_volume>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_ambient_volume_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_reflection_mask>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_reflection_mask_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,0,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)m_environment_probe_lighting_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,0,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v3->m_environment_probe_lighting_effect[1][0]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,1,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v3->m_environment_probe_lighting_effect[0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,1,0>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v3->m_environment_probe_lighting_effect[1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,0,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_environment_probe_lighting_effect[0][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,0,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_environment_probe_lighting_effect[1][0][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<0,1,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_environment_probe_lighting_effect[0][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_environment_probe_lighting<1,1,1>>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_environment_probe_lighting_effect[1][1][1]);
  vostok::render::effect_manager::create_effect<vostok::render::effect_ssao_downsample_position_and_normal>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_sh_ssao_downsample_position_and_normal);
  vostok::render::effect_manager::create_effect<vostok::render::effect_skylight>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v3->m_skylight_effect);
  v90 = (void *(__thiscall *)(void *))"s_eye_ray_corner";
  v8 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                   v7,
                                                   (const char *)s_manager.m_variable);
  v10 = 0;
  this = 0;
  if ( v8 )
  {
    v10 = (volatile signed __int32 *)v8;
    this = v8;
    v9 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v8, 1u);
  }
  v3->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                             v9,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&this,
                             rc_float);
  if ( v10 )
  {
    v11 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v10, 0xFFFFFFFF);
    if ( !v11 )
    {
      v90 = (void *(__thiscall *)(void *))v10;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"light_range";
  v12 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v11,
                                                    (const char *)s_manager.m_variable);
  v14 = 0;
  this = 0;
  if ( v12 )
  {
    v14 = (volatile signed __int32 *)v12;
    this = v12;
    v13 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v12, 1u);
  }
  v3->m_c_light_range = vostok::render::backend::register_constant_host(
                          v13,
                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                          (const vostok::shared_string *)&this,
                          rc_float);
  if ( v14 )
  {
    v15 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v14, 0xFFFFFFFF);
    if ( !v15 )
    {
      v90 = (void *(__thiscall *)(void *))v14;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"num_mips";
  v16 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v15,
                                                    (const char *)s_manager.m_variable);
  v18 = 0;
  this = 0;
  if ( v16 )
  {
    v18 = (volatile signed __int32 *)v16;
    this = v16;
    v17 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v16, 1u);
  }
  v3->m_c_num_mips = vostok::render::backend::register_constant_host(
                       v17,
                       (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                       (const vostok::shared_string *)&this,
                       rc_int);
  if ( v18 )
  {
    v19 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v18, 0xFFFFFFFF);
    if ( !v19 )
    {
      v90 = (void *(__thiscall *)(void *))v18;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters0";
  v20 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v19,
                                                    (const char *)s_manager.m_variable);
  v22 = 0;
  this = 0;
  if ( v20 )
  {
    v22 = (volatile signed __int32 *)v20;
    this = v20;
    v21 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v20, 1u);
  }
  v3->m_c_skylight_parameters0 = vostok::render::backend::register_constant_host(
                                   v21,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v22 )
  {
    v23 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v22, 0xFFFFFFFF);
    if ( !v23 )
    {
      v90 = (void *(__thiscall *)(void *))v22;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters1";
  v24 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v23,
                                                    (const char *)s_manager.m_variable);
  v26 = 0;
  this = 0;
  if ( v24 )
  {
    v26 = (volatile signed __int32 *)v24;
    this = v24;
    v25 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v24, 1u);
  }
  v3->m_c_skylight_parameters1 = vostok::render::backend::register_constant_host(
                                   v25,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v26 )
  {
    v27 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v26, 0xFFFFFFFF);
    if ( !v27 )
    {
      v90 = (void *(__thiscall *)(void *))v26;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters2";
  v28 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v27,
                                                    (const char *)s_manager.m_variable);
  v30 = 0;
  this = 0;
  if ( v28 )
  {
    v30 = (volatile signed __int32 *)v28;
    this = v28;
    v29 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v28, 1u);
  }
  v3->m_c_skylight_parameters2 = vostok::render::backend::register_constant_host(
                                   v29,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v30 )
  {
    v31 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v30, 0xFFFFFFFF);
    if ( !v31 )
    {
      v90 = (void *(__thiscall *)(void *))v30;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters3";
  v32 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v31,
                                                    (const char *)s_manager.m_variable);
  v34 = 0;
  this = 0;
  if ( v32 )
  {
    v34 = (volatile signed __int32 *)v32;
    this = v32;
    v33 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v32, 1u);
  }
  v3->m_c_skylight_parameters3 = vostok::render::backend::register_constant_host(
                                   v33,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v34 )
  {
    v35 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v34, 0xFFFFFFFF);
    if ( !v35 )
    {
      v90 = (void *(__thiscall *)(void *))v34;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters4";
  v36 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v35,
                                                    (const char *)s_manager.m_variable);
  v38 = 0;
  this = 0;
  if ( v36 )
  {
    v38 = (volatile signed __int32 *)v36;
    this = v36;
    v37 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v36, 1u);
  }
  v3->m_c_skylight_parameters4 = vostok::render::backend::register_constant_host(
                                   v37,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v38 )
  {
    v39 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v38, 0xFFFFFFFF);
    if ( !v39 )
    {
      v90 = (void *(__thiscall *)(void *))v38;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters5";
  v40 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v39,
                                                    (const char *)s_manager.m_variable);
  v42 = 0;
  this = 0;
  if ( v40 )
  {
    v42 = (volatile signed __int32 *)v40;
    this = v40;
    v41 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v40, 1u);
  }
  v3->m_c_skylight_parameters5 = vostok::render::backend::register_constant_host(
                                   v41,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v42 )
  {
    v43 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v42, 0xFFFFFFFF);
    if ( !v43 )
    {
      v90 = (void *(__thiscall *)(void *))v42;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters6";
  v44 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v43,
                                                    (const char *)s_manager.m_variable);
  v46 = 0;
  this = 0;
  if ( v44 )
  {
    v46 = (volatile signed __int32 *)v44;
    this = v44;
    v45 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v44, 1u);
  }
  v3->m_c_skylight_parameters6 = vostok::render::backend::register_constant_host(
                                   v45,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v46 )
  {
    v47 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v46, 0xFFFFFFFF);
    if ( !v47 )
    {
      v90 = (void *(__thiscall *)(void *))v46;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"skylight_parameters7";
  v48 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v47,
                                                    (const char *)s_manager.m_variable);
  v50 = 0;
  this = 0;
  if ( v48 )
  {
    v50 = (volatile signed __int32 *)v48;
    this = v48;
    v49 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v48, 1u);
  }
  v3->m_c_skylight_parameters7 = vostok::render::backend::register_constant_host(
                                   v49,
                                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                   (const vostok::shared_string *)&this,
                                   rc_float);
  if ( v50 )
  {
    v51 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v50, 0xFFFFFFFF);
    if ( !v51 )
    {
      v90 = (void *(__thiscall *)(void *))v50;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"color_parameters";
  v52 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v51,
                                                    (const char *)s_manager.m_variable);
  v54 = 0;
  this = 0;
  if ( v52 )
  {
    v54 = (volatile signed __int32 *)v52;
    this = v52;
    v53 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v52, 1u);
  }
  v3->m_c_color_parameters = vostok::render::backend::register_constant_host(
                               v53,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               (const vostok::shared_string *)&this,
                               rc_float);
  if ( v54 )
  {
    v55 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v54, 0xFFFFFFFF);
    if ( !v55 )
    {
      v90 = (void *(__thiscall *)(void *))v54;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"world_to_ao_map";
  v56 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v55,
                                                    (const char *)s_manager.m_variable);
  v58 = 0;
  this = 0;
  if ( v56 )
  {
    v58 = (volatile signed __int32 *)v56;
    this = v56;
    v57 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v56, 1u);
  }
  v3->m_c_world_to_ao_map = vostok::render::backend::register_constant_host(
                              v57,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              (const vostok::shared_string *)&this,
                              rc_float);
  if ( v58 )
  {
    v59 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v58, 0xFFFFFFFF);
    if ( !v59 )
    {
      v90 = (void *(__thiscall *)(void *))v58;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"ambient_volume_multiplier";
  v60 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v59,
                                                    (const char *)s_manager.m_variable);
  v62 = 0;
  this = 0;
  if ( v60 )
  {
    v62 = (volatile signed __int32 *)v60;
    this = v60;
    v61 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v60, 1u);
  }
  v3->m_c_ambient_volume_multiplier = vostok::render::backend::register_constant_host(
                                        v61,
                                        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                        (const vostok::shared_string *)&this,
                                        rc_float);
  if ( v62 )
  {
    v63 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v62, 0xFFFFFFFF);
    if ( !v63 )
    {
      v90 = (void *(__thiscall *)(void *))v62;
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v90 = (void *(__thiscall *)(void *))"world_to_probe";
  v64 = (vostok::render::stage_ambient_lighting *)vostok::strings::shared::manager::string(
                                                    v63,
                                                    (const char *)s_manager.m_variable);
  v66 = 0;
  this = 0;
  if ( v64 )
  {
    v66 = (void *(__thiscall *)(void *))v64;
    this = v64;
    v65 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v64, 1u);
  }
  v3->m_c_world_to_probe = vostok::render::backend::register_constant_host(
                             v65,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             (const vostok::shared_string *)&this,
                             rc_float);
  if ( v66 && !_InterlockedExchangeAdd((volatile signed __int32 *)v66, 0xFFFFFFFF) )
  {
    v90 = v66;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  buffer = vostok::render::resource_manager::create_buffer(
             0x450u,
             (bool)v66,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             du_sphere_vertices,
             enum_buffer_type_vertex,
             0,
             0);
  v68 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v68 = buffer;
  }
  m_object = (vostok::render::res_state *)v3->m_sphere_vertex_buffer.m_object;
  v3->m_sphere_vertex_buffer.m_object = v68;
  if ( m_object )
  {
    v70 = m_object->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v71 = vostok::render::resource_manager::create_buffer(
          0x438u,
          (bool)m_object,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          du_sphere_faces,
          enum_buffer_type_index,
          0,
          0);
  v72 = 0;
  if ( v71 )
  {
    ++v71->m_reference_count;
    v72 = v71;
  }
  v73 = (vostok::render::res_state *)v3->m_sphere_index_buffer.m_object;
  v3->m_sphere_index_buffer.m_object = v72;
  if ( v73 )
  {
    v70 = v73->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        v73,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v74 = v3->m_sphere_vertex_buffer.m_object;
  v90 = (void *(__thiscall *)(void *))v3->m_sphere_index_buffer.m_object;
  desc[0].SemanticName = "POSITION";
  desc[0].SemanticIndex = 0;
  desc[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
  desc[0].InputSlot = 0;
  desc[0].AlignedByteOffset = 0;
  desc[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  desc[0].InstanceDataStepRate = 0;
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)desc,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               1u,
               0xCu,
               v74,
               (vostok::render::untyped_buffer *)v90);
  v76 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v76 = geometry;
  }
  v77 = v3->m_sphere_geometry.m_object;
  v3->m_sphere_geometry.m_object = v76;
  if ( v77 )
  {
    v70 = v77->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v77);
  }
  v78 = vostok::render::resource_manager::create_buffer(
          0x60u,
          (bool)v73,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          vostok::geometry_utils::cube_solid::vertices,
          enum_buffer_type_vertex,
          0,
          0);
  this = 0;
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v78,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this);
  v79 = (vostok::render::res_state *)v3->m_box_vertex_buffer.m_object;
  v3->m_box_vertex_buffer.m_object = (vostok::render::untyped_buffer *)this;
  if ( v79 )
  {
    v70 = v79->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        v79,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v80 = alloca(72);
  memmove(v86, (unsigned __int8 *)vostok::geometry_utils::cube_solid::faces, 0x48u);
  v81 = vostok::render::resource_manager::create_buffer(
          0x48u,
          (bool)v79,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v86,
          enum_buffer_type_index,
          0,
          0);
  this = 0;
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v81,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&this);
  v82 = (vostok::render::res_state *)v3->m_box_index_buffer.m_object;
  v3->m_box_index_buffer.m_object = (vostok::render::untyped_buffer *)this;
  if ( v82 )
  {
    v70 = v82->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        v82,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v83 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)desc,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          1u,
          0xCu,
          v3->m_box_vertex_buffer.m_object,
          v3->m_box_index_buffer.m_object);
  v84 = 0;
  if ( v83 )
  {
    ++v83->m_reference_count;
    v84 = v83;
  }
  v85 = v3->m_box_geometry.m_object;
  v3->m_box_geometry.m_object = v84;
  if ( v85 )
  {
    v70 = v85->m_reference_count-- == 1;
    if ( v70 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v85);
  }
}

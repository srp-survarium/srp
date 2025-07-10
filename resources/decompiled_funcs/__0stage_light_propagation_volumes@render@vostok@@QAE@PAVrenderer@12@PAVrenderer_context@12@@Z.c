void __userpurge vostok::render::stage_light_propagation_volumes::stage_light_propagation_volumes(
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>,
        vostok::render::stage_light_propagation_volumes *this)
{
  unsigned int v3; // ebx
  survarium::game_action_id *M_start; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // eax
  vostok::render::radiance_volume *v8; // eax
  vostok::render::resource_manager *v9; // ecx
  float v10; // xmm0_4
  vostok::render::resource_manager *v11; // edx
  unsigned int v12; // ecx
  float v13; // eax
  double v14; // st7
  vostok::render::radiance_volume *m_rsm_downsampled_size; // ecx
  vostok::render::render_target *render_target; // eax
  vostok::render::render_target *v17; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v19; // eax
  vostok::render::render_target *v20; // ecx
  vostok::render::render_target *v21; // eax
  vostok::render::render_target *v22; // eax
  vostok::render::render_target *v23; // ecx
  vostok::render::render_target *v24; // eax
  vostok::render::render_target *v25; // eax
  vostok::render::render_target *v26; // ecx
  const char *v27; // eax
  bool v28; // zf
  vostok::strings::shared::profile *v29; // eax
  vostok::render::backend *v30; // ecx
  vostok::strings::shared::manager *v31; // esi
  vostok::strings::shared::profile *v32; // eax
  vostok::render::backend *v33; // ecx
  vostok::strings::shared::manager *v34; // esi
  vostok::strings::shared::profile *v35; // eax
  vostok::render::backend *v36; // ecx
  vostok::strings::shared::manager *v37; // esi
  vostok::strings::shared::profile *v38; // eax
  vostok::render::backend *v39; // ecx
  vostok::strings::shared::manager *v40; // esi
  vostok::strings::shared::profile *v41; // eax
  vostok::render::backend *v42; // ecx
  vostok::strings::shared::manager *v43; // esi
  vostok::strings::shared::profile *v44; // eax
  vostok::render::backend *v45; // ecx
  vostok::strings::shared::manager *v46; // esi
  vostok::strings::shared::profile *v47; // eax
  vostok::render::backend *v48; // ecx
  vostok::strings::shared::manager *v49; // esi
  vostok::strings::shared::profile *v50; // eax
  vostok::render::backend *v51; // ecx
  vostok::strings::shared::manager *v52; // esi
  vostok::render::stage_light_propagation_volumes *v53; // ecx
  vostok::render::stage_light_propagation_volumes *v54; // ecx
  vostok::strings::shared::profile *v55; // eax
  vostok::render::backend *v56; // ecx
  vostok::strings::shared::manager *v57; // esi
  unsigned int v58; // esi
  vostok::render::effect_options_descriptor *v59; // eax
  const void **p_destroyer; // eax
  survarium::options_tab *v61; // edi
  vostok::strings::shared::profile *v62; // eax
  vostok::strings::shared::profile *v63; // esi
  survarium::game *m_game; // ecx
  int x; // eax
  HRESULT v66; // eax
  const char *d3d11_error_string; // eax
  vostok::strings::shared::profile *v68; // eax
  char *m_movie; // esi
  unsigned int v70; // eax
  char v71; // dl
  unsigned int *v72; // ecx
  float v73; // ecx
  unsigned int *v74; // eax
  unsigned int v75; // ecx
  vostok::render::grass_render_model *v76; // eax
  unsigned int v77; // ecx
  unsigned __int8 *v78; // ebx
  unsigned __int8 *v79; // eax
  unsigned int v80; // esi
  int v81; // eax
  vostok::shared_string *v82; // eax
  survarium::game *v83; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v85; // edx
  survarium::options_item_base **v86; // ecx
  vostok::render::untyped_buffer *v87; // ecx
  vostok::render::res_state *v88; // edi
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v90; // ecx
  vostok::render::res_geometry *v91; // eax
  float in_flux_amplifier; // [esp+0h] [ebp-540h]
  float v93; // [esp+4h] [ebp-53Ch]
  unsigned int v94; // [esp+8h] [ebp-538h]
  unsigned int v95; // [esp+8h] [ebp-538h]
  unsigned int v96; // [esp+8h] [ebp-538h]
  unsigned int v97; // [esp+8h] [ebp-538h]
  unsigned int v98; // [esp+Ch] [ebp-534h]
  unsigned int v99; // [esp+Ch] [ebp-534h]
  unsigned int v100; // [esp+Ch] [ebp-534h]
  unsigned int v101; // [esp+Ch] [ebp-534h]
  vostok::shared_string name; // [esp+18h] [ebp-528h] BYREF
  bool do_debug_break[2]; // [esp+1Eh] [ebp-522h] BYREF
  unsigned int in_num_propagate_iterations[2]; // [esp+20h] [ebp-520h] BYREF
  int v105; // [esp+28h] [ebp-518h]
  int v106; // [esp+34h] [ebp-50Ch]
  int v107; // [esp+38h] [ebp-508h] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+3Ch] [ebp-504h] BYREF
  int v109; // [esp+54h] [ebp-4ECh]
  int v110; // [esp+58h] [ebp-4E8h]
  unsigned __int16 indices[6]; // [esp+5Ch] [ebp-4E4h] BYREF
  float cascade_flux_scales[8]; // [esp+68h] [ebp-4D8h] BYREF
  float cascade_cells_scales[8]; // [esp+88h] [ebp-4B8h]
  float cascade_iteration_scales[8]; // [esp+A8h] [ebp-498h]
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+C8h] [ebp-478h] BYREF
  vostok::math::float4x4 v116; // [esp+100h] [ebp-440h] BYREF
  unsigned __int8 data[1024]; // [esp+140h] [ebp-400h] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_light_propagation_volumes_vtbl *)&stru_964DF4.m_name;
  vostok::render::box_geometry::box_geometry((vostok::render::box_geometry *)in_renderer);
  v3 = 0;
  this->m_has_indirect_lighting = 0;
  this->m_rt_downsampled_scene.m_object = 0;
  this->m_t_downsampled_scene.m_object = 0;
  `vector constructor iterator'(
    (char *)this->m_caster_models,
    0xCu,
    4,
    (void *(__thiscall *)(void *))vostok::render::vector<vostok::render::lpv_render_surface>::vector<vostok::render::lpv_render_surface>);
  `vector constructor iterator'(
    (char *)this->m_rms_depth_stencil_source,
    4u,
    4,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_fill_rsm_effect,
    4u,
    15,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  this->m_downsample_rsm_effect.m_object = 0;
  this->m_apply_indirect_lighting_effect.m_object = 0;
  this->m_downsample_gbuffer_effect.m_object = 0;
  this->m_screen_vertex_ib.m_object = 0;
  this->m_screen_vertex_geometry.m_object = 0;
  v105 = 0;
  *(_QWORD *)in_num_propagate_iterations = 0;
  *(_QWORD *)&this->start_render_eye_position.x = 0;
  this->start_render_eye_position.z = 0.0;
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  v5 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 36);
  this->m_num_cascades = v5;
  if ( v5 > 1 )
  {
    if ( v5 > 7 )
      v5 = 7;
  }
  else
  {
    v5 = 1;
  }
  this->m_num_cascades = v5;
  this->m_grid_size = M_start[34];
  this->m_rsm_source_size = M_start[33];
  v6 = *((_DWORD *)M_start + 33);
  v7 = 476 * this->m_num_cascades;
  this->m_rsm_downsampled_size = v6 >> 1;
  v8 = (vostok::render::radiance_volume *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            v7);
  *(float *)&desc.destroyer = retry_to_increase_quality_period_sec;
  desc.data = (unsigned __int8 *)1084227584;
  desc.id = (const char *)clear_value;
  desc.bytes = 1086324736;
  LODWORD(cascade_cells_scales[0]) = clear_value;
  LODWORD(cascade_cells_scales[1]) = clear_value;
  LODWORD(cascade_cells_scales[2]) = clear_value;
  LODWORD(cascade_cells_scales[3]) = clear_value;
  LODWORD(cascade_cells_scales[4]) = clear_value;
  LODWORD(cascade_cells_scales[5]) = clear_value;
  LODWORD(cascade_cells_scales[6]) = clear_value;
  LODWORD(cascade_cells_scales[7]) = clear_value;
  LODWORD(cascade_flux_scales[0]) = clear_value;
  LODWORD(cascade_flux_scales[1]) = clear_value;
  LODWORD(cascade_flux_scales[2]) = clear_value;
  LODWORD(cascade_flux_scales[3]) = clear_value;
  LODWORD(cascade_flux_scales[4]) = clear_value;
  LODWORD(cascade_flux_scales[5]) = clear_value;
  LODWORD(cascade_flux_scales[6]) = clear_value;
  LODWORD(cascade_flux_scales[7]) = clear_value;
  LODWORD(cascade_iteration_scales[0]) = clear_value;
  *(_DWORD *)&desc.type = 1094713344;
  cascade_iteration_scales[1] = FLOAT_0_5;
  this->m_radiance_volume = v8;
  *(_DWORD *)&desc.memory_size = 1098907648;
  cascade_iteration_scales[2] = 0.25;
  v109 = 1103101952;
  cascade_iteration_scales[3] = 0.125;
  cascade_iteration_scales[4] = 0.125;
  cascade_iteration_scales[5] = 0.125;
  cascade_iteration_scales[6] = 0.125;
  cascade_iteration_scales[7] = 0.125;
  v10 = *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 3);
  v110 = 1107296256;
  *(float *)&v107 = v10;
  if ( this->m_num_cascades )
  {
    v106 = 0;
    name.m_pointer.m_object = (vostok::strings::shared::profile *)this->m_previous_proj_matrix;
    do
    {
      v11 = (vostok::render::resource_manager *)((char *)this->m_radiance_volume + v106);
      if ( v11 )
      {
        v93 = cascade_flux_scales[v3]
            * *((float *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
              + 4);
        in_flux_amplifier = *((float *)&desc.id + v3) * *(float *)&v107;
        v12 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
              + 34);
        *(_QWORD *)in_num_propagate_iterations = (__int64)((double)*((unsigned int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                                                                   + 35)
                                                         * cascade_iteration_scales[v3]);
        v13 = *(float *)in_num_propagate_iterations;
        in_num_propagate_iterations[0] = v12;
        v14 = (double)v12 * cascade_cells_scales[v3];
        m_rsm_downsampled_size = (vostok::render::radiance_volume *)this->m_rsm_downsampled_size;
        *(_QWORD *)in_num_propagate_iterations = (__int64)v14;
        vostok::render::radiance_volume::radiance_volume(
          m_rsm_downsampled_size,
          v11,
          (unsigned int)m_rsm_downsampled_size,
          (vostok::render::res_texture *)(__int64)v14,
          v13,
          in_flux_amplifier,
          v93);
      }
      qmemcpy(&name.m_pointer.m_object[-16], vostok::math::float4x4::identity(&v116), 0x40u);
      v106 += 476;
      ++v3;
      qmemcpy(name.m_pointer.m_object, vostok::math::float4x4::identity(&v116), 0x40u);
      v9 = 0;
      name.m_pointer.m_object += 4;
    }
    while ( v3 < this->m_num_cascades );
  }
  render_target = vostok::render::resource_manager::create_render_target(
                    v9,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                    "$user$rms_depth_stencil0",
                    (vostok::render::res_texture *)this->m_rsm_source_size,
                    (ID3D11Texture2D **)this->m_rsm_source_size,
                    (const char *)0x35,
                    enum_rt_usage_depth_stencil,
                    0,
                    0,
                    v94,
                    v98);
  v17 = 0;
  if ( render_target )
  {
    ++render_target->m_reference_count;
    v17 = render_target;
  }
  m_object = this->m_rms_depth_stencil_source[0].m_object;
  this->m_rms_depth_stencil_source[0].m_object = v17;
  if ( m_object )
  {
    if ( !--m_object->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v17,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)m_object);
  }
  v19 = vostok::render::resource_manager::create_render_target(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$rms_depth_stencil1",
          (vostok::render::res_texture *)this->m_rsm_source_size,
          (ID3D11Texture2D **)this->m_rsm_source_size,
          (const char *)0x35,
          enum_rt_usage_depth_stencil,
          0,
          0,
          v95,
          v99);
  v20 = 0;
  if ( v19 )
  {
    ++v19->m_reference_count;
    v20 = v19;
  }
  v21 = this->m_rms_depth_stencil_source[1].m_object;
  this->m_rms_depth_stencil_source[1].m_object = v20;
  if ( v21 )
  {
    if ( !--v21->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v20,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v21);
  }
  v22 = vostok::render::resource_manager::create_render_target(
          (vostok::render::resource_manager *)v20,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$rms_depth_stencil2",
          (vostok::render::res_texture *)this->m_rsm_source_size,
          (ID3D11Texture2D **)this->m_rsm_source_size,
          (const char *)0x35,
          enum_rt_usage_depth_stencil,
          0,
          0,
          v96,
          v100);
  v23 = 0;
  if ( v22 )
  {
    ++v22->m_reference_count;
    v23 = v22;
  }
  v24 = this->m_rms_depth_stencil_source[2].m_object;
  this->m_rms_depth_stencil_source[2].m_object = v23;
  if ( v24 )
  {
    if ( !--v24->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v24);
  }
  v25 = vostok::render::resource_manager::create_render_target(
          (vostok::render::resource_manager *)v23,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          "$user$rms_depth_stencil3",
          (vostok::render::res_texture *)this->m_rsm_source_size,
          (ID3D11Texture2D **)this->m_rsm_source_size,
          (const char *)0x35,
          enum_rt_usage_depth_stencil,
          0,
          0,
          v97,
          v101);
  v26 = 0;
  if ( v25 )
  {
    ++v25->m_reference_count;
    v26 = v25;
  }
  v27 = (const char *)this->m_rms_depth_stencil_source[3].m_object;
  this->m_rms_depth_stencil_source[3].m_object = v26;
  if ( v27 )
  {
    v28 = (*(_DWORD *)v27)-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v26,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v27);
  }
  v29 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v31 = 0;
  name.m_pointer.m_object = 0;
  if ( v29 )
  {
    v31 = (vostok::strings::shared::manager *)v29;
    name.m_pointer.m_object = v29;
    _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  this->m_c_interreflection_contribution = vostok::render::backend::register_constant_host(
                                             v30,
                                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                             &name,
                                             rc_float);
  if ( v31 && !_InterlockedExchangeAdd((volatile signed __int32 *)v31, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v31, (vostok::strings::shared::profile *)s_manager.m_variable);
  v32 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v34 = 0;
  name.m_pointer.m_object = 0;
  if ( v32 )
  {
    v34 = (vostok::strings::shared::manager *)v32;
    name.m_pointer.m_object = v32;
    _InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  this->m_c_cascade_index = vostok::render::backend::register_constant_host(
                              v33,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_int);
  if ( v34 && !_InterlockedExchangeAdd((volatile signed __int32 *)v34, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v34, (vostok::strings::shared::profile *)s_manager.m_variable);
  v35 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v37 = 0;
  name.m_pointer.m_object = 0;
  if ( v35 )
  {
    v37 = (vostok::strings::shared::manager *)v35;
    name.m_pointer.m_object = v35;
    _InterlockedExchangeAdd(&v35->m_reference_count, 1u);
  }
  this->m_c_num_cascades = vostok::render::backend::register_constant_host(
                             v36,
                             (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                             &name,
                             rc_int);
  if ( v37 && !_InterlockedExchangeAdd((volatile signed __int32 *)v37, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v37, (vostok::strings::shared::profile *)s_manager.m_variable);
  v38 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v40 = 0;
  name.m_pointer.m_object = 0;
  if ( v38 )
  {
    v40 = (vostok::strings::shared::manager *)v38;
    name.m_pointer.m_object = v38;
    _InterlockedExchangeAdd(&v38->m_reference_count, 1u);
  }
  this->m_c_ambient_color = vostok::render::backend::register_constant_host(
                              v39,
                              (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                              &name,
                              rc_float);
  if ( v40 && !_InterlockedExchangeAdd((volatile signed __int32 *)v40, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v40, (vostok::strings::shared::profile *)s_manager.m_variable);
  v41 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v43 = 0;
  name.m_pointer.m_object = 0;
  if ( v41 )
  {
    v43 = (vostok::strings::shared::manager *)v41;
    name.m_pointer.m_object = v41;
    _InterlockedExchangeAdd(&v41->m_reference_count, 1u);
  }
  this->m_c_smaller_cascade_grid_cell_size = vostok::render::backend::register_constant_host(
                                               v42,
                                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                               &name,
                                               rc_float);
  if ( v43 && !_InterlockedExchangeAdd((volatile signed __int32 *)v43, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v43, (vostok::strings::shared::profile *)s_manager.m_variable);
  v44 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v46 = 0;
  name.m_pointer.m_object = 0;
  if ( v44 )
  {
    v46 = (vostok::strings::shared::manager *)v44;
    name.m_pointer.m_object = v44;
    _InterlockedExchangeAdd(&v44->m_reference_count, 1u);
  }
  this->m_c_smaller_cascade_grid_size = vostok::render::backend::register_constant_host(
                                          v45,
                                          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                          &name,
                                          rc_float);
  if ( v46 && !_InterlockedExchangeAdd((volatile signed __int32 *)v46, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v46, (vostok::strings::shared::profile *)s_manager.m_variable);
  v47 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v49 = 0;
  name.m_pointer.m_object = 0;
  if ( v47 )
  {
    v49 = (vostok::strings::shared::manager *)v47;
    name.m_pointer.m_object = v47;
    _InterlockedExchangeAdd(&v47->m_reference_count, 1u);
  }
  this->m_c_smaller_cascade_grid_origin = vostok::render::backend::register_constant_host(
                                            v48,
                                            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                            &name,
                                            rc_float);
  if ( v49 && !_InterlockedExchangeAdd((volatile signed __int32 *)v49, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v49, (vostok::strings::shared::profile *)s_manager.m_variable);
  v50 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v52 = 0;
  name.m_pointer.m_object = 0;
  if ( v50 )
  {
    v52 = (vostok::strings::shared::manager *)v50;
    name.m_pointer.m_object = v50;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  this->m_c_radiance_blend_factor = vostok::render::backend::register_constant_host(
                                      v51,
                                      (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                      &name,
                                      rc_float);
  if ( v52 )
  {
    v53 = (vostok::render::stage_light_propagation_volumes *)v52;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v52, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(v52, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  vostok::render::stage_light_propagation_volumes::register_rsm_constans(v53, this);
  vostok::render::stage_light_propagation_volumes::register_light_constans(v54, this);
  v55 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v57 = 0;
  name.m_pointer.m_object = 0;
  if ( v55 )
  {
    v57 = (vostok::strings::shared::manager *)v55;
    name.m_pointer.m_object = v55;
    _InterlockedExchangeAdd(&v55->m_reference_count, 1u);
  }
  this->m_c_eye_ray_corner = vostok::render::backend::register_constant_host(
                               v56,
                               (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                               &name,
                               rc_float);
  if ( v57 && !_InterlockedExchangeAdd((volatile signed __int32 *)v57, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(v57, (vostok::strings::shared::profile *)s_manager.m_variable);
  v58 = 0;
  name.m_pointer.m_object = (vostok::strings::shared::profile *)this->m_fill_rsm_effect;
  do
  {
    if ( v58 != 12 )
    {
      desc.data = &data[24];
      desc.type = 3;
      desc.bytes = 0;
      desc.count = 0;
      desc.id = 0;
      desc.destroyer = 0;
      desc.memory_size = 1024;
      v59 = vostok::render::effect_options_descriptor::operator[](
              (vostok::render::effect_options_descriptor *)0x400,
              (int)&desc,
              (const char *)&key);
      v28 = (`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard'
           & 1) == 0;
      v59->data = (unsigned __int8 *)v58;
      v59->count = 4;
      if ( v28 )
      {
        `vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::`local static guard' |= 1u;
        LOWORD(`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id) = ++vostok::render::static_type::type_id_counter;
      }
      v59->type = (unsigned __int16)`vostok::render::static_type::get_type_id<enum vostok::render::enum_vertex_input_type>'::`2'::current_id;
      p_destroyer = &v59->destroyer;
      if ( p_destroyer )
        *p_destroyer = &vostok::render::destroy_data_helper<enum vostok::render::enum_vertex_input_type const>::`vftable';
      vostok::render::effect_manager::create_effect<vostok::render::effect_fill_reflective_shadow_map>(
        (vostok::render::effect_options_descriptor *)name.m_pointer.m_object,
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
    }
    name.m_pointer.m_object = (vostok::strings::shared::profile *)((char *)name.m_pointer.m_object + 4);
    ++v58;
  }
  while ( v58 < 0xF );
  v61 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  indices[1] = 1;
  indices[0] = 0;
  indices[3] = 3;
  indices[2] = 2;
  indices[4] = 2;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  indices[5] = 1;
  v62 = (vostok::strings::shared::profile *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              0x10u);
  v63 = v62;
  if ( v62 )
  {
    m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game;
    v62->m_length = 12;
    LODWORD(cascade_flux_scales[0]) = 12;
    v62->m_reference_count = 0;
    v62->m_checksum = 1;
    desc.id = (const char *)indices;
    x = m_game->m_game_world.m_mouse_pos.x;
    cascade_flux_scales[1] = 0.0;
    LODWORD(cascade_flux_scales[2]) = 2;
    cascade_flux_scales[3] = 0.0;
    cascade_flux_scales[4] = 0.0;
    desc.destroyer = 0;
    desc.data = 0;
    v66 = (*(int (__stdcall **)(int, float *, vostok::render::effect_options_descriptor *, vostok::strings::shared::profile **))(*(_DWORD *)x + 12))(
            x,
            cascade_flux_scales,
            &desc,
            &v63->next_in_hashset);
    if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind)
      && v66 < 0 )
    {
      do_debug_break[0] = 1;
      d3d11_error_string = make_d3d11_error_string(v66);
      vostok::debug::on_error(
        do_debug_break,
        process_error_true,
        (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_to_bind,
        assert_untyped,
        "assertion_failed",
        d3d11_error_string,
        ".\\untyped_buffer.cpp",
        "vostok::render::untyped_buffer::untyped_buffer",
        0x2Au);
      if ( vostok::debug::is_debugger_present() || do_debug_break[0] )
        __debugbreak();
    }
    v68 = v63;
    name.m_pointer.m_object = v63;
  }
  else
  {
    v68 = 0;
    name.m_pointer.m_object = 0;
  }
  v61[2].m_options += 3;
  m_movie = (char *)v61[10].m_movie;
  if ( m_movie == (char *)v61[11].m_options )
  {
    v70 = (m_movie - (char *)v61[10].m_game) >> 2;
    v71 = 1;
    v107 = 1;
    in_num_propagate_iterations[0] = v70;
    if ( v70 == 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v72 = in_num_propagate_iterations;
    if ( v70 <= 1 )
      v72 = (unsigned int *)&v107;
    LODWORD(v73) = v70 + *v72;
    v106 = LODWORD(v73);
    if ( LODWORD(v73) > 0x3FFFFFFF || LODWORD(v73) < v70 )
    {
      v73 = 1.9999999;
      v106 = 0x3FFFFFFF;
    }
    *(float *)&v107 = v73;
    in_num_propagate_iterations[0] = 1;
    v74 = in_num_propagate_iterations;
    if ( v73 != 0.0 )
      v74 = (unsigned int *)&v107;
    v75 = *v74;
    v76 = vostok::render::g_allocator.m_object;
    v77 = 4 * v75;
    if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v77 )
      v71 = 0;
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v71;
    if ( v77 )
      v78 = (unsigned __int8 *)vostok_mspace_malloc((void *)HIDWORD(v76->m_reconstruction_info_actuality_tick), v77);
    else
      v78 = 0;
    v79 = (unsigned __int8 *)v61[10].m_game;
    v80 = m_movie - (char *)v79;
    if ( v80 )
    {
      memmove(v78, v79, v80);
      v82 = (vostok::shared_string *)(v80 + v81);
    }
    else
    {
      v82 = (vostok::shared_string *)v78;
    }
    v82->m_pointer.m_object = name.m_pointer.m_object;
    in_num_propagate_iterations[0] = (unsigned int)&v82[1];
    v83 = v61[10].m_game;
    if ( v83 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v83);
    }
    v85 = in_num_propagate_iterations[0];
    v86 = (survarium::options_item_base **)&v78[4 * v106];
    v68 = name.m_pointer.m_object;
    v61[10].m_game = (survarium::game *)v78;
    v61[10].m_movie = (vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)v85;
    v61[11].m_options = v86;
  }
  else
  {
    *(_DWORD *)m_movie = v68;
    ++v61[10].m_movie;
  }
  v87 = 0;
  if ( v68 )
  {
    ++v68->m_reference_count;
    v87 = (vostok::render::untyped_buffer *)v68;
  }
  v88 = (vostok::render::res_state *)this->m_screen_vertex_ib.m_object;
  this->m_screen_vertex_ib.m_object = v87;
  if ( v88 )
  {
    v28 = v88->m_reference_count-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        v88,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)screen_vertex_layout,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               2u,
               0x18u,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               this->m_screen_vertex_ib.m_object);
  v90 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v90 = geometry;
  }
  v91 = this->m_screen_vertex_geometry.m_object;
  this->m_screen_vertex_geometry.m_object = v90;
  if ( v91 )
  {
    v28 = v91->m_reference_count-- == 1;
    if ( v28 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v91);
  }
  vostok::render::effect_manager::create_effect<vostok::render::effect_downsample_reflective_shadow_map>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_downsample_rsm_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_indirect_lighting>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_apply_indirect_lighting_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_downsample_gbuffer>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_downsample_gbuffer_effect);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 258);
}

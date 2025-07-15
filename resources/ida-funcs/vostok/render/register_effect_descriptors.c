void __cdecl vostok::render::register_effect_descriptors()
{
  vostok::render::effect_descriptor *v0; // eax
  vostok::render::effect_descriptor *v1; // eax
  vostok::render::effect_descriptor *v2; // eax
  vostok::render::effect_descriptor *v3; // eax
  vostok::render::effect_descriptor *v4; // eax
  vostok::render::effect_descriptor *v5; // eax
  vostok::render::effect_descriptor *v6; // eax
  vostok::render::effect_descriptor *v7; // eax
  vostok::render::effect_descriptor *v8; // eax
  vostok::render::effect_descriptor *v9; // eax
  vostok::render::effect_descriptor *v10; // eax
  vostok::render::effect_descriptor *v11; // eax
  vostok::render::effect_descriptor *v12; // eax
  vostok::render::effect_descriptor *v13; // eax
  vostok::render::effect_descriptor *v14; // eax
  vostok::render::effect_descriptor *v15; // eax
  vostok::render::effect_descriptor *v16; // eax
  vostok::render::effect_descriptor *v17; // eax
  vostok::render::effect_descriptor *v18; // eax
  vostok::render::effect_descriptor *v19; // eax
  vostok::render::effect_descriptor *v20; // eax
  vostok::render::effect_descriptor *v21; // eax
  vostok::render::effect_descriptor *v22; // eax
  vostok::render::effect_descriptor *v23; // eax
  int *v24; // eax
  int *v25; // eax
  vostok::render::effect_descriptor *v26; // eax
  vostok::render::effect_descriptor *v27; // eax
  vostok::render::effect_descriptor *v28; // eax
  vostok::render::effect_descriptor *v29; // eax
  vostok::render::effect_manager *m_conflicted_action_to_bind; // [esp-Ch] [ebp-Ch]

  v0 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v0 )
    v0->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_passes;
  else
    v0 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v0);
  v1 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v1 )
    v1->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_effects._M_impl._M_end_of_storage;
  else
    v1 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_shader_cache_info._M_impl._M_end_of_storage._M_data,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v1);
  v2 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v2 )
    v2->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_passes._M_t._M_node_count;
  else
    v2 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_passes._M_t._M_node_count,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v2);
  v3 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v3 )
    v3->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_techniques;
  else
    v3 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_960AE0,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v3);
  v4 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v4 )
    v4->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_passes._M_t._M_node_count;
  else
    v4 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_shaders._M_t._M_header._M_data._M_left,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v4);
  v5 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v5 )
    v5->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_fstage_blend_subuv_materials::`vftable';
  else
    v5 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_techniques._M_t._M_header._M_data._M_left,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v5);
  v6 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v6 )
    v6->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_effect_descriptors._M_t._M_header._M_data._M_right;
  else
    v6 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_effects._M_impl._M_end_of_storage,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v6);
  v7 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v7 )
    v7->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_shaders._M_t._M_header._M_data._M_left;
  else
    v7 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_effect_descriptors._M_t._M_header._M_data._M_right,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v7);
  v8 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v8 )
    v8->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_lighting_stage_organic_base_materials::`vftable';
  else
    v8 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_effect_descriptors_by_texture._M_t._M_header._M_data._M_left,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v8);
  v9 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                              4u);
  if ( v9 )
    v9->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_techniques._M_t._M_node_count;
  else
    v9 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9662C0.m_effects_deleted_in_pending._M_impl._M_finish,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v9);
  v10 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v10 )
    v10->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_effect_descriptors_by_texture._M_t._M_header._M_data._M_parent;
  else
    v10 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v10);
  v11 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v11 )
    v11->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_effect_descriptors_by_texture._M_t._M_key_compare;
  else
    v11 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_passes._M_t._M_header._M_data._M_parent,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v11);
  v12 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v12 )
    v12->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_fstage_smoke_custom_lighted_materials::`vftable';
  else
    v12 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_shaders._M_t._M_header._M_data._M_left,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v12);
  v13 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v13 )
    v13->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_distortion_stage_panner_materials::`vftable';
  else
    v13 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_techniques._M_t._M_node_count,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v13);
  v14 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v14 )
    v14->__vftable = (vostok::render::effect_descriptor_vtbl *)&stru_9664E4.m_effects_deleted_in_pending._M_impl._M_end_of_storage;
  else
    v14 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_effect_descriptors,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v14);
  v15 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v15 )
    v15->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_gstage_default_materials::`vftable';
  else
    v15 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_effect_descriptors._M_t._M_key_compare,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v15);
  v16 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v16 )
    v16->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_gstage_terrain_materials::`vftable';
  else
    v16 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_effect_descriptors_by_texture._M_t._M_header._M_data._M_right,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v16);
  v17 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v17 )
    v17->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_gstage_default_materials::`vftable';
  else
    v17 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966378.m_effects_deleted_in_pending,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v17);
  v18 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v18 )
    v18->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_gstage_burning_wood_materials::`vftable';
  else
    v18 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v18);
  v19 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v19 )
    v19->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_post_process_blend_texture_materials::`vftable';
  else
    v19 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_passes,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v19);
  v20 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v20 )
    v20->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_post_process_distortion_materials::`vftable';
  else
    v20 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_shaders._M_t._M_header._M_data._M_parent,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v20);
  v21 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v21 )
    v21->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_post_process_terrain_debug_materials::`vftable';
  else
    v21 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_techniques._M_t._M_header._M_data._M_parent,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v21);
  v22 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v22 )
    v22->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_debug_editor_wireframe::`vftable';
  else
    v22 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_effect_descriptors._M_t._M_header._M_data._M_parent,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v22);
  v23 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v23 )
    v23->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::depth_accumulate_material_effect::`vftable';
  else
    v23 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_960AE0.m_techniques._M_t._M_key_compare,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v23);
  v24 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          8u);
  if ( v24 )
  {
    *v24 = (int)&vostok::render::decal_default_material_effect::`vftable';
    *((_BYTE *)v24 + 4) = 0;
  }
  else
  {
    v24 = 0;
  }
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_effect_descriptors_by_texture._M_t._M_header._M_data._M_parent,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::render::effect_descriptor *)v24);
  v25 = vostok::memory::doug_lea_allocator::malloc_impl(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          8u);
  if ( v25 )
  {
    *v25 = (int)&vostok::render::decal_default_material_effect::`vftable';
    *((_BYTE *)v25 + 4) = 1;
  }
  else
  {
    v25 = 0;
  }
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_effect_descriptors_by_texture._M_t._M_key_compare,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    (vostok::render::effect_descriptor *)v25);
  v26 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v26 )
    v26->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::sky_default_material_effect::`vftable';
  else
    v26 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_966430.m_effects_deleted_in_pending._M_impl._M_end_of_storage,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v26);
  v27 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v27 )
    v27->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_sky_sphere_default_materials::`vftable';
  else
    v27 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_9664E4,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v27);
  v28 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v28 )
    v28->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_fstage_simpe_water_materials::`vftable';
  else
    v28 = 0;
  vostok::render::effect_manager::register_effect_desctiptor(
    (vostok::render::effect_manager *)&stru_960AE0.m_shader_cache_info._M_impl._M_end_of_storage,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    v28);
  v29 = (vostok::render::effect_descriptor *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               4u);
  if ( v29 )
  {
    m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
    v29->__vftable = (vostok::render::effect_descriptor_vtbl *)&vostok::render::effect_fstage_default_view_angle_dependent_materials::`vftable';
    vostok::render::effect_manager::register_effect_desctiptor(
      (vostok::render::effect_manager *)&stru_960AE0.m_passes._M_t._M_node_count,
      m_conflicted_action_to_bind,
      v29);
  }
  else
  {
    vostok::render::effect_manager::register_effect_desctiptor(
      (vostok::render::effect_manager *)&stru_960AE0.m_passes._M_t._M_node_count,
      (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
      0);
  }
}

void __thiscall vostok::render::stage_postprocess::~stage_postprocess(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *thisa)
{
  vostok::render::material *m_object; // eax
  vostok::render::res_texture *v3; // ecx
  vostok::render::res_texture *v4; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_geometry *v7; // eax
  bool v8; // zf
  vostok::render::untyped_buffer *v9; // eax
  vostok::render::res_effect *v10; // eax
  vostok::render::res_effect *v11; // eax
  vostok::render::res_effect *v12; // eax
  vostok::render::res_effect *v13; // eax
  vostok::render::res_effect *v14; // eax
  vostok::render::res_effect *v15; // eax
  vostok::render::res_effect *v16; // eax
  vostok::render::res_effect *v17; // eax
  vostok::render::res_effect *v18; // eax
  vostok::render::res_effect *v19; // eax
  vostok::render::res_effect *v20; // eax
  vostok::render::res_effect *v21; // eax
  vostok::render::res_effect *v22; // eax
  vostok::render::res_effect *v23; // eax
  vostok::resources::unmanaged_resource **p_m_object; // esi
  int i; // edi
  int v26; // eax
  vostok::resources::unmanaged_resource **v27; // esi
  int j; // edi
  int v29; // eax
  vostok::render::res_effect *v30; // eax
  vostok::render::res_effect *v31; // eax
  vostok::render::res_effect *v32; // eax
  vostok::render::res_effect *v33; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v34; // [esp+0h] [ebp-Ch]
  const stlp_std::__false_type *v35; // [esp+4h] [ebp-8h]

  if ( thisa->m_prev_matrix_map._M_t._M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)&thisa->m_prev_matrix_map,
      thisa->m_prev_matrix_map._M_t._M_header._M_data._M_parent);
    thisa->m_prev_matrix_map._M_t._M_header._M_data._M_left = &thisa->m_prev_matrix_map._M_t._M_header._M_data;
    thisa->m_prev_matrix_map._M_t._M_header._M_data._M_parent = 0;
    thisa->m_prev_matrix_map._M_t._M_header._M_data._M_right = &thisa->m_prev_matrix_map._M_t._M_header._M_data;
    thisa->m_prev_matrix_map._M_t._M_node_count = 0;
  }
  m_object = thisa->m_test_material.m_object;
  if ( m_object )
  {
    this = (vostok::render::stage_postprocess *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &thisa->m_test_material.m_object->vostok::resources::unmanaged_intrusive_base,
        thisa->m_test_material.m_object);
  }
  stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>::~_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects>>((stlp_std::priv::_Impl_vector<vostok::render::material_effects,vostok::render::std_allocator<vostok::render::material_effects> > *)this);
  v4 = thisa->m_color_grading_base_lut.m_object;
  if ( v4 )
  {
    if ( !--v4->m_reference_count )
      vostok::render::res_texture::destroy_impl(v3);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_textures.m_container._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)thisa->m_textures.m_container._M_impl._M_start,
    v34,
    v35);
  M_start = thisa->m_textures.m_container._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v7 = thisa->m_screen_vertex_geometry.m_object;
  if ( v7 )
  {
    v8 = v7->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_screen_vertex_geometry.m_object);
  }
  v9 = thisa->m_screen_vertex_ib.m_object;
  if ( v9 )
  {
    v8 = v9->m_reference_count-- == 1;
    if ( v8 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_screen_vertex_ib.m_object);
  }
  v10 = thisa->m_motion_vectors_accumulation_effect.m_object;
  if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_motion_vectors_accumulation_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_motion_vectors_accumulation_effect.m_object);
  v11 = thisa->m_aberration_effect.m_object;
  if ( v11 && !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_aberration_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_aberration_effect.m_object);
  v12 = thisa->m_temporal_antialiasing_effect.m_object;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_temporal_antialiasing_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_temporal_antialiasing_effect.m_object);
  v13 = thisa->m_olta_effect.m_object;
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_olta_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_olta_effect.m_object);
  v14 = thisa->m_motion_blur_effect.m_object;
  if ( v14 && !_InterlockedExchangeAdd(&v14->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_motion_blur_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_motion_blur_effect.m_object);
  v15 = thisa->m_lens_flares_effect.m_object;
  if ( v15 && !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_lens_flares_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_lens_flares_effect.m_object);
  v16 = thisa->m_image_space_reflections_effect.m_object;
  if ( v16 && !_InterlockedExchangeAdd(&v16->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_image_space_reflections_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_image_space_reflections_effect.m_object);
  v17 = thisa->m_post_process_downsample_frame_effect.m_object;
  if ( v17 && !_InterlockedExchangeAdd(&v17->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_post_process_downsample_frame_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_post_process_downsample_frame_effect.m_object);
  v18 = thisa->m_god_rays_effect.m_object;
  if ( v18 && !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_god_rays_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_god_rays_effect.m_object);
  v19 = thisa->m_post_process_shader_sharpen.m_object;
  if ( v19 && !_InterlockedExchangeAdd(&v19->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_post_process_shader_sharpen.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_post_process_shader_sharpen.m_object);
  v20 = thisa->m_post_process_antialiasing_shader_sraa.m_object;
  if ( v20 && !_InterlockedExchangeAdd(&v20->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_post_process_antialiasing_shader_sraa.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_post_process_antialiasing_shader_sraa.m_object);
  v21 = thisa->m_post_process_antialiasing_shader_fxaa.m_object;
  if ( v21 && !_InterlockedExchangeAdd(&v21->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_post_process_antialiasing_shader_fxaa.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_post_process_antialiasing_shader_fxaa.m_object);
  v22 = thisa->m_post_process_antialiasing_shader.m_object;
  if ( v22 && !_InterlockedExchangeAdd(&v22->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_post_process_antialiasing_shader.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_post_process_antialiasing_shader.m_object);
  v23 = thisa->m_sh_effect_copy_image.m_object;
  p_m_object = &thisa->m_sh_effect_copy_image.m_object;
  if ( v23 && !_InterlockedExchangeAdd(&v23->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
      *p_m_object);
  for ( i = 7; i >= 0; --i )
  {
    v26 = (int)*--p_m_object;
    if ( v26 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v26 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &(*p_m_object)->vostok::resources::unmanaged_intrusive_base,
        *p_m_object);
  }
  v27 = &thisa->m_sh_complex_blend[0][0][0].m_object;
  for ( j = 7; j >= 0; --j )
  {
    v29 = (int)*--v27;
    if ( v29 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v29 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v27)->vostok::resources::unmanaged_intrusive_base, *v27);
  }
  v30 = thisa->m_sh_eye_adaptation.m_object;
  if ( v30 && !_InterlockedExchangeAdd(&v30->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_eye_adaptation.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_eye_adaptation.m_object);
  v31 = thisa->m_sh_gather_luminance_histogram.m_object;
  if ( v31 && !_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_gather_luminance_histogram.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_gather_luminance_histogram.m_object);
  v32 = thisa->m_sh_gather_luminance.m_object;
  if ( v32 && !_InterlockedExchangeAdd(&v32->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_gather_luminance.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_gather_luminance.m_object);
  v33 = thisa->m_sh_gather_bloom.m_object;
  if ( v33 && !_InterlockedExchangeAdd(&v33->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_sh_gather_bloom.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_sh_gather_bloom.m_object);
  thisa->__vftable = (vostok::render::stage_postprocess_vtbl *)&vostok::render::stage::`vftable';
}

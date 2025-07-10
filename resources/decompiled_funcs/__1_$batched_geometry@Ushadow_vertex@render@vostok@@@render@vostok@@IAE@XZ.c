void __userpurge vostok::render::batched_geometry<vostok::render::shadow_vertex>::~batched_geometry<vostok::render::shadow_vertex>(
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *this@<ecx>,
        vostok::render::geometry_batch *a2@<edi>,
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *thisa)
{
  vostok::render::material_effects_instance *m_object; // eax
  unsigned __int16 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::shadow_vertex *v7; // eax
  void *v8; // esi
  vostok::render::res_declaration *v9; // eax
  void **p_m_object; // edi
  stlp_std::reverse_iterator<vostok::render::geometry_batch *> v11; // ecx
  stlp_std::reverse_iterator<vostok::render::geometry_batch *> v12; // eax
  void *v13; // eax
  void *v14; // esi
  vostok::render::geometry_batch *v15; // eax
  void *v16; // esi
  vostok::render::geometry_batch *v17; // [esp-4h] [ebp-10h]
  const stlp_std::__false_type *v18; // [esp+0h] [ebp-Ch]
  int thisb; // [esp+10h] [ebp+4h]

  v17 = a2;
  thisa->__vftable = (vostok::render::batched_geometry<vostok::render::shadow_vertex>_vtbl *)&vostok::render::batched_geometry<vostok::render::shadow_vertex>::`vftable';
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate((vostok::render::batched_geometry<vostok::render::lpv_vertex> *)this);
  m_object = thisa->m_materail_effects_instance.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &thisa->m_materail_effects_instance.m_object->vostok::resources::unmanaged_intrusive_base,
      thisa->m_materail_effects_instance.m_object);
  M_start = thisa->m_indices._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v7 = thisa->m_vertices._M_impl._M_start;
  if ( v7 )
  {
    v8 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v8, v7);
  }
  v9 = thisa->m_layout.m_object;
  if ( v9 )
  {
    if ( !--v9->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        thisa->m_layout.m_object);
  }
  p_m_object = (void **)&thisa->m_layout.m_object;
  for ( thisb = 7; thisb >= 0; --thisb )
  {
    v11.current = (vostok::render::geometry_batch *)*(p_m_object - 2);
    v12.current = (vostok::render::geometry_batch *)*(p_m_object - 3);
    p_m_object -= 3;
    stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::geometry_batch *>,vostok::render::geometry_batch>(
      v11,
      v12,
      v17,
      v18);
    v13 = *p_m_object;
    if ( *p_m_object )
    {
      v14 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v14, v13);
    }
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::geometry_batch *>,vostok::render::geometry_batch>(
    (stlp_std::reverse_iterator<vostok::render::geometry_batch *>)thisa->m_geometry_batches._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::render::geometry_batch *>)thisa->m_geometry_batches._M_impl._M_start,
    v17,
    v18);
  v15 = thisa->m_geometry_batches._M_impl._M_start;
  if ( v15 )
  {
    v16 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v16, v15);
  }
}

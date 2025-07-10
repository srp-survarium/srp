void __thiscall vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this,
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *thisa)
{
  vostok::render::geometry_batch *M_finish; // ebx
  vostok::render::geometry_batch *i; // esi
  const vostok::render::res_geometry *m_object; // eax
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::render::geometry_batch *M_start; // esi
  unsigned __int16 *v8; // eax
  vostok::render::lpv_vertex *v9; // eax
  vostok::render::geometry_batch *v10; // [esp+0h] [ebp-10h]
  const stlp_std::__false_type *v11; // [esp+4h] [ebp-Ch]

  M_finish = thisa->m_geometry_batches._M_impl._M_finish;
  for ( i = thisa->m_geometry_batches._M_impl._M_start; i != M_finish; ++i )
  {
    m_object = i->geometry.m_object;
    i->geometry.m_object = 0;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          m_object);
    }
    v6 = i->mtl.m_object;
    i->mtl.m_object = 0;
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
  M_start = thisa->m_geometry_batches._M_impl._M_start;
  if ( M_start != thisa->m_geometry_batches._M_impl._M_finish )
  {
    stlp_std::__destroy_range_aux<vostok::render::geometry_batch *,vostok::render::geometry_batch>(
      M_start,
      thisa->m_geometry_batches._M_impl._M_finish,
      v10,
      v11);
    thisa->m_geometry_batches._M_impl._M_finish = M_start;
  }
  v8 = thisa->m_indices._M_impl._M_start;
  if ( v8 != thisa->m_indices._M_impl._M_finish )
    thisa->m_indices._M_impl._M_finish = v8;
  v9 = thisa->m_vertices._M_impl._M_start;
  if ( v9 != thisa->m_vertices._M_impl._M_finish )
    thisa->m_vertices._M_impl._M_finish = v9;
}

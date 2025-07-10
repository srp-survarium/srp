void __thiscall vostok::render::batched_geometry<vostok::render::lpv_vertex>::finalize_batch(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this,
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *thisa)
{
  vostok::render::res_geometry *v2; // edi
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v4; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::render::material_effects_instance *m_object; // eax
  vostok::render::geometry_batch *v7; // eax
  stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch> > *v8; // ecx
  vostok::render::geometry_batch *M_finish; // edx
  bool v10; // zf
  unsigned __int16 *M_start; // eax
  vostok::render::lpv_vertex *v12; // eax
  vostok::render::untyped_buffer *v13; // edi
  vostok::render::untyped_buffer *v14; // edi
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> v15; // [esp-4h] [ebp-4Ch]
  const stlp_std::__false_type *v16; // [esp+0h] [ebp-48h]
  unsigned int v17; // [esp+4h] [ebp-44h]
  bool v18; // [esp+8h] [ebp-40h]
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> in_geometry; // [esp+Ch] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> ib; // [esp+10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> vb; // [esp+14h] [ebp-34h]
  __int64 v22; // [esp+18h] [ebp-30h]
  int v23; // [esp+20h] [ebp-28h]
  vostok::render::geometry_batch v24; // [esp+24h] [ebp-24h] BYREF

  if ( thisa->m_vertices._M_impl._M_finish - thisa->m_vertices._M_impl._M_start
    && (((char *)thisa->m_indices._M_impl._M_finish - (char *)thisa->m_indices._M_impl._M_start) & 0xFFFFFFFE) != 0 )
  {
    v2 = 0;
    buffer = vostok::render::resource_manager::create_buffer(
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               20 * (thisa->m_vertices._M_impl._M_finish - thisa->m_vertices._M_impl._M_start),
               thisa->m_vertices._M_impl._M_start,
               enum_buffer_type_vertex,
               0,
               0);
    vb.m_object = 0;
    if ( buffer )
    {
      ++buffer->m_reference_count;
      vb.m_object = buffer;
    }
    v4 = vostok::render::resource_manager::create_buffer(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           2 * (thisa->m_indices._M_impl._M_finish - thisa->m_indices._M_impl._M_start),
           thisa->m_indices._M_impl._M_start,
           enum_buffer_type_index,
           0,
           0);
    ib.m_object = 0;
    if ( v4 )
    {
      ++v4->m_reference_count;
      ib.m_object = v4;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                 thisa->m_layout.m_object,
                 0x14u,
                 vb.m_object,
                 ib.m_object);
    in_geometry.m_object = 0;
    if ( geometry )
    {
      ++geometry->m_reference_count;
      in_geometry.m_object = geometry;
      v2 = geometry;
    }
    v15.m_object = 0;
    m_object = thisa->m_materail_effects_instance.m_object;
    if ( m_object )
    {
      v15.m_object = thisa->m_materail_effects_instance.m_object;
      _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
    }
    vostok::render::geometry_batch::geometry_batch(
      &v24,
      &thisa->m_bbox,
      &in_geometry,
      thisa->m_indices._M_impl._M_finish - thisa->m_indices._M_impl._M_start,
      v15);
    M_finish = thisa->m_geometry_batches._M_impl._M_finish;
    if ( M_finish == thisa->m_geometry_batches._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::geometry_batch,vostok::render::std_allocator<vostok::render::geometry_batch>>::_M_insert_overflow_aux(
        v8,
        M_finish,
        v7,
        v16,
        v17,
        v18);
      v2 = in_geometry.m_object;
    }
    else
    {
      if ( M_finish )
        vostok::render::geometry_batch::geometry_batch(v7, (const vostok::render::geometry_batch *)v16);
      ++thisa->m_geometry_batches._M_impl._M_finish;
    }
    vostok::render::geometry_batch::~geometry_batch((vostok::render::geometry_batch *)v8);
    if ( v2 )
    {
      v10 = v2->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v2);
    }
    v22 = 0;
    v23 = 0;
    *(_QWORD *)&thisa->m_bbox.min.x = 0;
    memset(&v24.bbox.min.elements[2], 0, 12);
    *(_QWORD *)&thisa->m_bbox.min.elements[2] = 0;
    v24.bbox.max.z = 0.0;
    *(_QWORD *)&thisa->m_bbox.max.elements[1] = LODWORD(v24.bbox.max.y);
    M_start = thisa->m_indices._M_impl._M_start;
    if ( M_start != thisa->m_indices._M_impl._M_finish )
      thisa->m_indices._M_impl._M_finish = M_start;
    v12 = thisa->m_vertices._M_impl._M_start;
    if ( v12 != thisa->m_vertices._M_impl._M_finish )
      thisa->m_vertices._M_impl._M_finish = v12;
    v13 = ib.m_object;
    if ( ib.m_object )
    {
      v10 = ib.m_object->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v13);
    }
    v14 = vb.m_object;
    if ( vb.m_object )
    {
      v10 = vb.m_object->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v14);
    }
  }
}

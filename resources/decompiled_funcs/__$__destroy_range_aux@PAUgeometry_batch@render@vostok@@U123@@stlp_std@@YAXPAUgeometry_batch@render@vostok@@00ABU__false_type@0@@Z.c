void __usercall stlp_std::__destroy_range_aux<vostok::render::geometry_batch *,vostok::render::geometry_batch>(
        vostok::render::geometry_batch *__first@<eax>,
        vostok::render::geometry_batch *__last@<edi>)
{
  vostok::render::geometry_batch *i; // esi
  vostok::render::res_geometry *m_object; // eax
  vostok::render::material_effects_instance *v5; // eax

  for ( i = __first; i != __last; ++i )
  {
    m_object = i->geometry.m_object;
    if ( m_object )
    {
      if ( m_object->m_reference_count-- == 1 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          i->geometry.m_object);
    }
    v5 = i->mtl.m_object;
    if ( v5 )
    {
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &i->mtl.m_object->vostok::resources::unmanaged_intrusive_base,
          i->mtl.m_object);
    }
  }
}

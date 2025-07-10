vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::res_geometry **a2@<esi>)
{
  vostok::render::res_geometry *m_object; // ecx
  vostok::render::res_geometry *v3; // eax
  const vostok::render::res_geometry *v4; // ecx
  const vostok::render::res_geometry *v5; // eax

  m_object = this->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    ++m_object->m_reference_count;
  }
  v4 = v3;
  v5 = *a2;
  *a2 = v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v5);
  }
  return (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}

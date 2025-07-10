vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *__usercall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=@<eax>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        const vostok::render::res_geometry **a2@<esi>)
{
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // ecx
  const vostok::render::res_geometry *v4; // eax

  v2 = 0;
  if ( this )
  {
    ++this->m_object;
    v2 = this;
  }
  v3 = v2;
  v4 = *a2;
  *a2 = (const vostok::render::res_geometry *)v3;
  if ( v4 )
  {
    if ( v4->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v4);
  }
  return (vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2;
}

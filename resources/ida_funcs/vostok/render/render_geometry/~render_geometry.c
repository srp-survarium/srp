void __usercall vostok::render::render_geometry::~render_geometry(
        vostok::render::render_geometry *this@<ecx>,
        const vostok::render::res_geometry **a2@<esi>)
{
  const vostok::render::res_geometry *v2; // eax
  bool v3; // zf
  const vostok::render::res_geometry *v4; // eax
  const vostok::render::res_geometry *v5; // eax

  v2 = a2[2];
  if ( v2 )
  {
    v3 = v2->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        a2[2]);
  }
  v4 = a2[1];
  if ( v4 )
  {
    v3 = v4->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        a2[1]);
  }
  v5 = *a2;
  if ( *a2 )
  {
    v3 = v5->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *a2);
  }
}

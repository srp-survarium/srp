void __usercall vostok::render::res_geometry::~res_geometry(vostok::render::res_geometry *this@<ecx>, int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax

  v2 = *(_DWORD **)(a2 + 16);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_declaration **)(a2 + 16));
  }
  v4 = *(_DWORD **)(a2 + 8);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        *(vostok::render::res_state **)(a2 + 8),
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  v5 = *(_DWORD **)(a2 + 4);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        *(vostok::render::res_state **)(a2 + 4),
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
}

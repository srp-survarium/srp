void __usercall vostok::render::decal_shader_constants_and_geometry::~decal_shader_constants_and_geometry(
        vostok::render::decal_shader_constants_and_geometry *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax

  v2 = *(_DWORD **)(a2 + 24);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 24));
  }
  v4 = *(_DWORD **)(a2 + 20);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 20));
  }
  v5 = *(_DWORD **)(a2 + 16);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 16));
  }
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_waiting_for_bind_action = kLEFT;
}

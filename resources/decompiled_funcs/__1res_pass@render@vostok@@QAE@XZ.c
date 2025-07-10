void __usercall vostok::render::res_pass::~res_pass(vostok::render::res_pass *this@<ecx>, int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax

  v2 = *(_DWORD **)(a2 + 20);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_input_layout **)(a2 + 20));
  }
  v4 = *(_DWORD **)(a2 + 16);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs<vostok::render::ps_data> **)(a2 + 16));
  }
  v5 = *(_DWORD **)(a2 + 12);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs<vostok::render::gs_data> **)(a2 + 12));
  }
  v6 = *(_DWORD **)(a2 + 8);
  if ( v6 )
  {
    v3 = (*v6)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_xs<vostok::render::vs_data> **)(a2 + 8));
  }
  v7 = *(_DWORD **)(a2 + 4);
  if ( v7 )
  {
    v3 = (*v7)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_state **)(a2 + 4));
  }
}

void __usercall vostok::render::res_xs<vostok::render::vs_data>::~res_xs<vostok::render::vs_data>(
        vostok::render::res_xs<vostok::render::vs_data> *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v2 = *(_DWORD **)(a2 + 16);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_sampler_list **)(a2 + 16));
  }
  v4 = *(_DWORD **)(a2 + 12);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_texture_list **)(a2 + 12));
  }
  v5 = *(_DWORD **)(a2 + 8);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::shader_constant_table **)(a2 + 8));
  }
  v6 = *(_DWORD **)(a2 + 4);
  if ( v6 )
  {
    v3 = (*v6)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        (vostok::render::resource_manager *)this,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_xs_hw<vostok::render::vs_data> **)(a2 + 4));
  }
}

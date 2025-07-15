void __usercall vostok::render::stage_lights::light_geometry::~light_geometry(
        vostok::render::stage_lights::light_geometry *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  const vostok::render::untyped_buffer *v5; // eax

  v2 = *(_DWORD **)(a2 + 8);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 8));
  }
  v4 = *(_DWORD **)(a2 + 4);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 4));
  }
  v5 = *(const vostok::render::untyped_buffer **)a2;
  if ( *(_DWORD *)a2 )
  {
    v3 = v5->m_reference_count-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)a2);
  }
}

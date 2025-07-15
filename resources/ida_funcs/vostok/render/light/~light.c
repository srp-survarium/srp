void __usercall vostok::render::light::~light(vostok::render::light *this@<ecx>, int a2@<edi>)
{
  vostok::render::res_texture *v2; // ecx
  void *v3; // eax
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax

  vostok::render::light::remove_collision(this, (vostok::render::light *)a2);
  if ( *(_DWORD *)(a2 + 320) )
  {
    v3 = *(void **)(a2 + 312);
    if ( v3 )
      pt3free(v3);
    *(_DWORD *)(a2 + 312) = 0;
    *(_DWORD *)(a2 + 320) = 0;
  }
  v4 = *(_DWORD *)(a2 + 260);
  if ( v4 )
  {
    v5 = (*(_DWORD *)(v4 + 4))-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(v2, *(const vostok::render::res_texture **)(a2 + 260));
  }
  v6 = *(_DWORD **)(a2 + 256);
  if ( v6 )
  {
    v5 = (*v6)-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const char **)(a2 + 256));
  }
}

void __usercall vostok::render::stage_shadow_direct::~stage_shadow_direct(
        vostok::render::stage_shadow_direct *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  int v5; // eax

  *(_DWORD *)a2 = &vostok::render::stage_shadow_direct::`vftable';
  v2 = *(_DWORD *)(a2 + 2740);
  if ( v2 )
  {
    v3 = (*(_DWORD *)(v2 + 4))-- == 1;
    if ( v3 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        *(const vostok::render::res_texture **)(a2 + 2740));
  }
  v4 = *(_DWORD **)(a2 + 2736);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const char **)(a2 + 2736));
  }
  v5 = *(_DWORD *)(a2 + 40);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 40) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 40));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

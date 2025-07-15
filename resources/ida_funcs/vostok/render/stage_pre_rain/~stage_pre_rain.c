void __usercall vostok::render::stage_pre_rain::~stage_pre_rain(
        vostok::render::stage_pre_rain *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax

  *(_DWORD *)a2 = &stru_963F84.m_name.m_string.m_buffer[128];
  v2 = *(_DWORD *)(a2 + 28);
  if ( v2 )
  {
    this = (vostok::render::stage_pre_rain *)_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 28) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 28));
  }
  v3 = *(_DWORD *)(a2 + 24);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 24) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 24));
  v4 = *(_DWORD *)(a2 + 20);
  if ( v4 )
  {
    v5 = (*(_DWORD *)(v4 + 4))-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(
        (vostok::render::res_texture *)this,
        *(const vostok::render::res_texture **)(a2 + 20));
  }
  v6 = *(_DWORD **)(a2 + 16);
  if ( v6 )
  {
    v5 = (*v6)-- == 1;
    if ( v5 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const char **)(a2 + 16));
  }
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

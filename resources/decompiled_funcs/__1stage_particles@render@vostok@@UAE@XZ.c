void __usercall vostok::render::stage_particles::~stage_particles(
        vostok::render::stage_particles *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  *(_DWORD *)a2 = &vostok::render::stage_particles::`vftable';
  v2 = *(_DWORD **)(a2 + 40);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_geometry **)(a2 + 40));
  }
  v4 = *(_DWORD **)(a2 + 36);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_geometry **)(a2 + 36));
  }
  v5 = *(_DWORD **)(a2 + 32);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_geometry **)(a2 + 32));
  }
  v6 = *(_DWORD *)(a2 + 28);
  if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 28) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 28));
  v7 = *(_DWORD *)(a2 + 24);
  if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 24) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 24));
  v8 = *(_DWORD *)(a2 + 20);
  if ( v8 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 20) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 20));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

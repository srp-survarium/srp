void __usercall vostok::render::stage_ambient_occlusion::~stage_ambient_occlusion(
        vostok::render::stage_ambient_occlusion *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v2 = *(_DWORD **)(a2 + 44);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 44));
  }
  v4 = *(_DWORD **)(a2 + 40);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 40));
  }
  v5 = *(_DWORD *)(a2 + 36);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 36) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 36));
  v6 = *(_DWORD *)(a2 + 32);
  if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 32) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 32));
  v7 = *(_DWORD *)(a2 + 28);
  if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 28) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 28));
  v8 = *(_DWORD *)(a2 + 24);
  if ( v8 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 24) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 24));
  v9 = *(_DWORD *)(a2 + 20);
  if ( v9 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 20) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 20));
  v10 = *(_DWORD *)(a2 + 16);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

void __usercall vostok::render::stage_ambient_lighting::~stage_ambient_lighting(
        vostok::render::stage_ambient_lighting *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax
  bool v3; // zf
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  vostok::resources::unmanaged_resource **v14; // edi
  int i; // ebx
  int v16; // eax
  int v17; // eax

  v2 = *(_DWORD **)(a2 + 160);
  if ( v2 )
  {
    v3 = (*v2)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 160));
  }
  v4 = *(_DWORD **)(a2 + 156);
  if ( v4 )
  {
    v3 = (*v4)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 156));
  }
  v5 = *(_DWORD **)(a2 + 152);
  if ( v5 )
  {
    v3 = (*v5)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 152));
  }
  v6 = *(_DWORD **)(a2 + 148);
  if ( v6 )
  {
    v3 = (*v6)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 148));
  }
  v7 = *(_DWORD **)(a2 + 144);
  if ( v7 )
  {
    v3 = (*v7)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 144));
  }
  v8 = *(_DWORD **)(a2 + 140);
  if ( v8 )
  {
    v3 = (*v8)-- == 1;
    if ( v3 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::untyped_buffer **)(a2 + 140));
  }
  v9 = *(_DWORD *)(a2 + 68);
  if ( v9 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 68) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 68));
  v10 = *(_DWORD *)(a2 + 64);
  if ( v10 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 64) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 64));
  v11 = *(_DWORD *)(a2 + 60);
  if ( v11 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 60) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 60));
  v12 = *(_DWORD *)(a2 + 56);
  if ( v12 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v12 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 56) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 56));
  v13 = *(_DWORD *)(a2 + 52);
  v14 = (vostok::resources::unmanaged_resource **)(a2 + 52);
  if ( v13 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v13 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&(*v14)->vostok::resources::unmanaged_intrusive_base, *v14);
  for ( i = 7; i >= 0; --i )
  {
    v16 = (int)*--v14;
    if ( v16 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v16 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v14)->vostok::resources::unmanaged_intrusive_base, *v14);
  }
  v17 = *(_DWORD *)(a2 + 16);
  if ( v17 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v17 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

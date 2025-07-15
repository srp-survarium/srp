void __usercall vostok::render::stage_volume_fog::~stage_volume_fog(
        vostok::render::stage_volume_fog *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // eax

  *(_DWORD *)a2 = &vostok::render::stage_volume_fog::`vftable';
  v2 = *(_DWORD *)(a2 + 44);
  if ( v2 )
  {
    this = (vostok::render::stage_volume_fog *)_InterlockedExchangeAdd(
                                                 (volatile signed __int32 *)(v2 + 208),
                                                 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 44) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 44));
  }
  v3 = *(_DWORD *)(a2 + 40);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 40) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 40));
  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, a2 + 20);
  v4 = *(_DWORD **)(a2 + 16);
  if ( v4 )
  {
    if ( (*v4)-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(const vostok::render::res_geometry **)(a2 + 16));
  }
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

void __usercall vostok::render::stage_gbuffer::~stage_gbuffer(vostok::render::stage_gbuffer *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  _DWORD *v4; // eax

  *(_DWORD *)a2 = &stru_963F84.m_rescale_min.w;
  v2 = *(_DWORD *)(a2 + 116);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 116) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 116));
  v3 = *(_DWORD *)(a2 + 112);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 112) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 112));
  v4 = *(_DWORD **)(a2 + 16);
  if ( v4 )
  {
    if ( (*v4)-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *(vostok::render::res_state **)(a2 + 16));
  }
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

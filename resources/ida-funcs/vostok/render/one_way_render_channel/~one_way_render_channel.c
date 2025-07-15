void __usercall vostok::render::one_way_render_channel::~one_way_render_channel(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  v2 = *(_DWORD *)(a2 + 172);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 172) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 172));
  v3 = *(_DWORD *)(a2 + 168);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 168) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 168));
  CloseHandle(*(HANDLE *)(a2 + 144));
}

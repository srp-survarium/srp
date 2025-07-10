void __usercall vostok::render::stage_forward::~stage_forward(vostok::render::stage_forward *this@<ecx>, int a2@<edi>)
{
  vostok::resources::unmanaged_resource **v2; // esi
  int i; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  *(_DWORD *)a2 = &stru_965008.m_name.m_string.m_buffer[204];
  v2 = (vostok::resources::unmanaged_resource **)(a2 + 84);
  for ( i = 14; i >= 0; --i )
  {
    v4 = (int)*--v2;
    if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*v2)->vostok::resources::unmanaged_intrusive_base, *v2);
  }
  v5 = *(_DWORD *)(a2 + 20);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 20) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 20));
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

void __usercall survarium::booby_trap_set::~booby_trap_set(survarium::booby_trap_set *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  void (__cdecl *v6)(int, int, int); // eax

  *(_DWORD *)a2 = &survarium::booby_trap_set::`vftable';
  v2 = *(_DWORD *)(a2 + 380);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 380) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 380));
  v3 = *(_DWORD *)(a2 + 376);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 376) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 376));
  v4 = *(_DWORD *)(a2 + 372);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 372) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 372));
  v5 = *(_DWORD *)(a2 + 328);
  if ( v5 )
  {
    if ( (v5 & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(int, int, int))(v5 & 0xFFFFFFFE);
      if ( v6 )
        v6(a2 + 336, a2 + 336, 2);
    }
    *(_DWORD *)(a2 + 328) = 0;
  }
  survarium::booby_trap_set_core::~booby_trap_set_core((survarium::booby_trap_set_core *)a2);
}

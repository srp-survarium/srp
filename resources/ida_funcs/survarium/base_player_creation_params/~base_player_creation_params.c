void __usercall survarium::base_player_creation_params::~base_player_creation_params(
        survarium::base_player_creation_params *this@<ecx>,
        int a2@<eax>)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v3 = *(_DWORD *)(a2 + 288);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 288) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 288));
  v4 = *(_DWORD *)(a2 + 280);
  if ( v4 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 280) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 280));
  v5 = *(_DWORD *)(a2 + 276);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 276) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 276));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 136));
}

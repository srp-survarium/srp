void __usercall vostok::render::stage_decals_accumulate::~stage_decals_accumulate(
        vostok::render::stage_decals_accumulate *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  int v3; // eax

  *(_DWORD *)a2 = &stru_963F84.m_desc.SampleDesc.Quality;
  v2 = *(_DWORD *)(a2 + 20);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 20) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 20));
  v3 = *(_DWORD *)(a2 + 16);
  if ( v3 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

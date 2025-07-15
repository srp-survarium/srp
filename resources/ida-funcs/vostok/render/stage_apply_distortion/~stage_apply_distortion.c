void __usercall vostok::render::stage_apply_distortion::~stage_apply_distortion(
        vostok::render::stage_apply_distortion *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  *(_DWORD *)a2 = &stru_965008.m_sh_res_view;
  v2 = *(_DWORD *)(a2 + 16);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

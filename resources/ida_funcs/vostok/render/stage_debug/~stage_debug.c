void __usercall vostok::render::stage_debug::~stage_debug(vostok::render::stage_debug *this@<ecx>, int a2@<edi>)
{
  int v2; // eax

  *(_DWORD *)a2 = &vostok::render::stage_debug::`vftable';
  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, a2 + 20);
  v2 = *(_DWORD *)(a2 + 16);
  if ( v2 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

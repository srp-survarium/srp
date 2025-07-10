void __usercall vostok::render::stage_sun::~stage_sun(vostok::render::stage_sun *this@<ecx>, int a2@<edi>)
{
  vostok::render::res_texture *v2; // ecx
  int v3; // eax
  int v5; // eax

  vostok::render::box_geometry::~box_geometry((vostok::render::box_geometry *)this, a2 + 24);
  v3 = *(_DWORD *)(a2 + 20);
  if ( v3 )
  {
    if ( (*(_DWORD *)(v3 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(v2);
  }
  v5 = *(_DWORD *)(a2 + 16);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 16) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 16));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

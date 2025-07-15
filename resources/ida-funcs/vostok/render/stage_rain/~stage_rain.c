void __usercall vostok::render::stage_rain::~stage_rain(vostok::render::stage_rain *this@<ecx>, int a2@<edi>)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v3; // eax
  vostok::render::box_geometry *v4; // ecx
  vostok::render::res_texture *v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax

  *(_DWORD *)a2 = &vostok::render::stage_rain::`vftable';
  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v3 = (void *)(*(_DWORD *)(a2 + 48) - 8);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  vostok::render::box_geometry::~box_geometry(v4, a2 + 28);
  v6 = *(_DWORD *)(a2 + 24);
  if ( v6 )
  {
    v5 = (vostok::render::res_texture *)_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF);
    if ( !v5 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 24) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 24));
  }
  v7 = *(_DWORD *)(a2 + 20);
  if ( v7 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 20) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 20));
  v8 = *(_DWORD *)(a2 + 16);
  if ( v8 )
  {
    if ( (*(_DWORD *)(v8 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(v5, *(const vostok::render::res_texture **)(a2 + 16));
  }
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}

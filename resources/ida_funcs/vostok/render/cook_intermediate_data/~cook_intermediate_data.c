void __usercall vostok::render::cook_intermediate_data::~cook_intermediate_data(
        vostok::render::cook_intermediate_data *this@<ecx>,
        int a2@<eax>)
{
  void *v3; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  int v5; // eax
  int v6; // eax

  v3 = *(void **)(a2 + 300);
  if ( v3 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  }
  v5 = *(_DWORD *)(a2 + 296);
  if ( v5 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v5 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 296) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 296));
  v6 = *(_DWORD *)(a2 + 284);
  if ( v6 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 284) + 208),
        *(vostok::resources::unmanaged_resource **)(a2 + 284));
  }
}

void __userpurge vostok::render::culling::portal_sector_system::portal_sector_system(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> structure)
{
  vostok::render::culling::portal_sector_structure *m_object; // eax
  void *v5; // eax
  char *v6; // ecx
  int v7; // eax
  vostok::render::culling::portal_sector_system *v8; // ecx
  vostok::render::culling::sector_double_query_preventer *v9; // eax
  int v10; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  m_object = structure.m_object;
  *(_DWORD *)a2 = &vostok::render::culling::portal_sector_system::`vftable';
  *(_DWORD *)(a2 + 264) = 0;
  if ( structure.m_object )
  {
    *(vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *)(a2 + 264) = structure;
    _InterlockedExchangeAdd(&structure.m_object->m_reference_count, 1u);
    m_object = structure.m_object;
  }
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         16 * (m_object->m_portals.m_end - m_object->m_portals.m_begin));
  *(_DWORD *)(a2 + 288) = v5;
  *(_DWORD *)(a2 + 292) = v5;
  *(_DWORD *)(a2 + 296) = v5;
  v6 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                 structure.m_object->m_portals.m_end - structure.m_object->m_portals.m_begin);
  *(_DWORD *)(a2 + 300) = v6;
  v7 = structure.m_object->m_portals.m_end - structure.m_object->m_portals.m_begin;
  *(_DWORD *)(a2 + 304) = v6;
  v8 = (vostok::render::culling::portal_sector_system *)&v6[v7];
  *(_DWORD *)(a2 + 308) = v8;
  *(_DWORD *)(a2 + 312) = 0;
  vostok::render::culling::portal_sector_system::initialize_portals_occlusion_bounds_and_results(v8, (_DWORD *)a2);
  v9 = (vostok::render::culling::sector_double_query_preventer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                   0x1Cu);
  if ( v9 )
    vostok::render::culling::sector_double_query_preventer::sector_double_query_preventer(
      (*(_DWORD *)(*(_DWORD *)(a2 + 264) + 292) - *(_DWORD *)(*(_DWORD *)(a2 + 264) + 288)) >> 5,
      v9,
      *(const vostok::render::culling::spatial_sector **)(*(_DWORD *)(a2 + 264) + 288));
  else
    v10 = 0;
  *(_DWORD *)(a2 + 284) = v10;
  if ( structure.m_object )
  {
    if ( !_InterlockedExchangeAdd(&structure.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &structure.m_object->vostok::resources::unmanaged_intrusive_base,
        structure.m_object);
  }
}

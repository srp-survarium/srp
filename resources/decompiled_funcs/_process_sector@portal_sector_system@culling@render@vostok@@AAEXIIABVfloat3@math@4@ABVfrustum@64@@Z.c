void __userpurge vostok::render::culling::portal_sector_system::process_sector(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        vostok::render::culling::portal_sector_system *a2@<edi>,
        unsigned int sector_id,
        unsigned int input_portal_id,
        const vostok::math::float3 *view_pos,
        const vostok::math::frustum *f)
{
  unsigned int v6; // eax
  unsigned int *v7; // esi
  unsigned int *i; // ebx
  unsigned int v9; // eax

  v6 = (unsigned int)&a2->m_structure.m_object->m_sectors.m_begin[sector_id];
  v7 = *(unsigned int **)(v6 + 24);
  for ( i = &v7[*(_DWORD *)(v6 + 28)]; v7 != i; ++v7 )
  {
    v9 = *v7;
    if ( *v7 != input_portal_id && a2->m_structure.m_object->m_portals.m_begin[v9].m_visible )
      vostok::render::culling::portal_sector_system::process_portal_by_frustum_intersection(
        a2,
        v9,
        f,
        sector_id,
        view_pos);
  }
}

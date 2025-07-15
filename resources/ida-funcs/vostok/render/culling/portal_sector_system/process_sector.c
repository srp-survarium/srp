void __thiscall vostok::render::culling::portal_sector_system::process_sector(
        vostok::render::culling::portal_sector_system *this,
        vostok::math::float3 *sector_id,
        const vostok::math::frustum *input_portal_id,
        const vostok::math::float3 *view_pos,
        const vostok::math::frustum *f)
{
  vostok::render::culling::spatial_sector *v6; // eax
  int v7; // ebx
  const vostok::math::frustum **i; // edi
  const vostok::math::frustum *v9; // eax

  v6 = &this->m_structure.m_object->m_sectors.m_begin[(_DWORD)sector_id];
  v7 = (int)&v6->m_portal_ids[v6->m_portals_count];
  for ( i = (const vostok::math::frustum **)v6->m_portal_ids; i != (const vostok::math::frustum **)v7; ++i )
  {
    v9 = *i;
    if ( *i != input_portal_id && this->m_structure.m_object->m_portals.m_begin[(_DWORD)v9].m_visible )
      vostok::render::culling::portal_sector_system::process_portal_by_frustum_intersection(
        (vostok::render::culling::portal_sector_system *)(76 * (_DWORD)v9),
        *(float *)&i,
        *(float *)&this,
        this,
        v9,
        (unsigned int)f,
        sector_id,
        view_pos);
  }
}

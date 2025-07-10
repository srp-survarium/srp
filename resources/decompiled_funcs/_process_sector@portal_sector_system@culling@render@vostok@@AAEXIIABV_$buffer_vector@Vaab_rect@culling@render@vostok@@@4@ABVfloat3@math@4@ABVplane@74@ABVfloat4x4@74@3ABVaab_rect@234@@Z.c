void __userpurge vostok::render::culling::portal_sector_system::process_sector(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        vostok::render::culling::portal_sector_system *a2@<edi>,
        unsigned int sector_id,
        unsigned int input_portal_id,
        const vostok::buffer_vector<vostok::render::culling::aab_rect> *portals_rects,
        const vostok::math::float3 *view_pos,
        const vostok::math::plane *far_plane,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float4x4 *inv_mat_vp,
        const vostok::render::culling::aab_rect *rect)
{
  unsigned int v10; // eax
  int v11; // ebp
  unsigned int *i; // esi
  unsigned int v13; // eax

  v10 = (unsigned int)&a2->m_structure.m_object->m_sectors.m_begin[sector_id];
  v11 = *(_DWORD *)(v10 + 24) + 4 * *(_DWORD *)(v10 + 28);
  for ( i = *(unsigned int **)(v10 + 24); i != (unsigned int *)v11; ++i )
  {
    v13 = *i;
    if ( *i != input_portal_id && a2->m_structure.m_object->m_portals.m_begin[v13].m_visible )
      vostok::render::culling::portal_sector_system::process_portal_in_screen_space(
        a2,
        v13,
        sector_id,
        portals_rects,
        view_pos,
        far_plane,
        mat_vp,
        inv_mat_vp,
        rect);
  }
}

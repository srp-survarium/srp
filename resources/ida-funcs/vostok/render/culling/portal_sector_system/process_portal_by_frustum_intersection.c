void __userpurge vostok::render::culling::portal_sector_system::process_portal_by_frustum_intersection(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        float a2@<edi>,
        float a3@<esi>,
        vostok::render::culling::portal_sector_system *portal_id,
        const vostok::math::frustum *f,
        unsigned int sector_id,
        const vostok::math::float3 *view_pos,
        const vostok::math::float3 *a8)
{
  vostok::render::culling::portal *v8; // esi
  vostok::math::float3 *v9; // esi
  vostok::math::float3 v10; // [esp-14h] [ebp-C0h]
  vostok::math::frustum fa; // [esp+0h] [ebp-ACh] BYREF
  vostok::math::float3 vertices[4]; // [esp+78h] [ebp-34h] BYREF

  v10.z = a3;
  v8 = &portal_id->m_structure.m_object->m_portals.m_begin[(_DWORD)f];
  v10.y = a2;
  if ( (const vostok::math::float3 *)v8->m_sectors[(float)((float)((float)((float)(v8->m_plane.normal.z
                                                                                 * COERCE_FLOAT(
                                                                                     *(_DWORD *)(sector_id + 88)
                                                                                   ^ _mask__NegFloat_))
                                                                         + (float)(v8->m_plane.normal.y
                                                                                 * COERCE_FLOAT(
                                                                                     *(_DWORD *)(sector_id + 84)
                                                                                   ^ _mask__NegFloat_)))
                                                                 + (float)(v8->m_plane.normal.x
                                                                         * COERCE_FLOAT(
                                                                             *(_DWORD *)(sector_id + 80)
                                                                           ^ _mask__NegFloat_)))
                                                         + v8->m_plane.d) > 0.0] != view_pos )
  {
    stlp_std::priv::__copy_trivial(
      (unsigned __int8 *)v8->m_points,
      (unsigned __int8 *)&v8->m_visible,
      (unsigned __int8 *)vertices);
    LODWORD(v10.x) = vertices;
    if ( vostok::render::culling::cull_points_by_frustum((const vostok::math::frustum *)sector_id, v10)
      && fabs(
           fsqrt(
             (float)((float)((float)(vertices[1].z - vertices[0].z) * (float)(vertices[1].z - vertices[0].z))
                   + (float)((float)(vertices[1].y - vertices[0].y) * (float)(vertices[1].y - vertices[0].y)))
           + (float)((float)(vertices[1].x - vertices[0].x) * (float)(vertices[1].x - vertices[0].x)))
         * fsqrt(
             (float)((float)((float)(vertices[2].z - vertices[1].z) * (float)(vertices[2].z - vertices[1].z))
                   + (float)((float)(vertices[2].y - vertices[1].y) * (float)(vertices[2].y - vertices[1].y)))
           + (float)((float)(vertices[2].x - vertices[1].x) * (float)(vertices[2].x - vertices[1].x)))) >= 0.001 )
    {
      if ( view_pos == (const vostok::math::float3 *)v8->m_sectors[0] )
        v9 = (vostok::math::float3 *)v8->m_sectors[1];
      else
        v9 = (vostok::math::float3 *)v8->m_sectors[0];
      if ( vostok::render::culling::sector_double_query_preventer::is_possible_points_for_frustum(
             portal_id->m_preventer,
             (unsigned int)v9,
             (const vostok::math::float3 (*)[4])vertices) )
      {
        vostok::render::culling::create_frustum_from_four_points(
          a8,
          (vostok::math::float3 (*)[4])vertices,
          &fa,
          sector_id + 80);
        vostok::render::culling::sector_double_query_preventer::add_frustum(
          portal_id->m_preventer,
          (unsigned int)v9,
          &fa);
        vostok::render::culling::portal_sector_system::process_sector(portal_id, v9, f, a8, &fa);
      }
    }
  }
}

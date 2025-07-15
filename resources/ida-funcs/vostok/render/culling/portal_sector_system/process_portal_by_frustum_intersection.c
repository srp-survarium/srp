void __thiscall vostok::render::culling::portal_sector_system::process_portal_by_frustum_intersection(
        vostok::render::culling::portal_sector_system *this,
        unsigned int portal_id,
        const vostok::math::frustum *f,
        unsigned int sector_id,
        const vostok::math::float3 *view_pos)
{
  vostok::render::culling::portal *v6; // esi
  unsigned int v7; // esi
  float v8; // [esp+14h] [ebp-B8h]
  float v9; // [esp+14h] [ebp-B8h]
  float v10; // [esp+18h] [ebp-B4h]
  float v11; // [esp+1Ch] [ebp-B0h]
  float v12; // [esp+20h] [ebp-ACh]
  vostok::math::float3 points[4]; // [esp+24h] [ebp-A8h] BYREF
  vostok::math::frustum result; // [esp+54h] [ebp-78h] BYREF

  v6 = &this->m_structure.m_object->m_portals.m_begin[portal_id];
  if ( v6->m_sectors[(float)((float)((float)((float)(v6->m_plane.normal.z * (float)-f->m_planes[4].plane.normal.z)
                                           + (float)(v6->m_plane.normal.y * (float)-f->m_planes[4].plane.normal.y))
                                   + (float)(v6->m_plane.normal.x * (float)-f->m_planes[4].plane.normal.x))
                           + v6->m_plane.d) > 0.0] != sector_id )
  {
    memmove((unsigned __int8 *)points, (unsigned __int8 *)v6->m_points, 0x30u);
    if ( vostok::render::culling::cull_points_by_frustum(f, (vostok::math::float3 (*)[4])points) )
    {
      v10 = points[2].x - points[1].x;
      v11 = points[2].y - points[1].y;
      v12 = points[2].z - points[1].z;
      v8 = sqrtf(
             (float)((float)((float)(points[1].z - points[0].z) * (float)(points[1].z - points[0].z))
                   + (float)((float)(points[1].y - points[0].y) * (float)(points[1].y - points[0].y)))
           + (float)((float)(points[1].x - points[0].x) * (float)(points[1].x - points[0].x)));
      v9 = sqrtf((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v10 * v10)) * v8;
      if ( COERCE_FLOAT(LODWORD(v9) & 0x7FFFFFFF) >= 0.001 )
      {
        if ( sector_id == v6->m_sectors[0] )
          v7 = v6->m_sectors[1];
        else
          v7 = v6->m_sectors[0];
        if ( vostok::render::culling::sector_double_query_preventer::is_possible_points_for_frustum(
               this->m_preventer,
               v7,
               (const vostok::math::float3 (*)[4])points) )
        {
          vostok::render::culling::create_frustum_from_four_points(
            &result,
            view_pos,
            (const vostok::math::float3 (*)[4])points,
            &f->m_planes[4].plane);
          vostok::render::culling::sector_double_query_preventer::add_frustum(this->m_preventer, &result, v7);
          vostok::render::culling::portal_sector_system::process_sector(
            (vostok::render::culling::portal_sector_system *)portal_id,
            this,
            v7,
            portal_id,
            view_pos,
            &result);
        }
      }
    }
  }
}

void __userpurge vostok::render::culling::portal_sector_system::make_frustum_images(
        const vostok::math::float3 *view_dir@<eax>,
        unsigned int a2@<edi>,
        vostok::render::culling::portal_sector_system *this)
{
  __int64 v3; // xmm0_8
  float z; // eax
  vostok::render::culling::portal_sector_structure *m_object; // esi
  void *v6; // esp
  vostok::render::culling::spatial_sector *m_end; // ebx
  vostok::math::aabb *p_m_aabb; // esi
  unsigned int *v9; // edi
  vostok::math::float3 *v10; // eax
  unsigned int v11[3]; // [esp-Ch] [ebp-24h] BYREF
  vostok::math::float3 v12; // [esp+0h] [ebp-18h] BYREF
  unsigned int *v13; // [esp+Ch] [ebp-Ch]
  unsigned int furthest_vertex_id; // [esp+10h] [ebp-8h]

  v3 = *(_QWORD *)&view_dir->x;
  z = view_dir->z;
  *(_QWORD *)&v12.x = v3;
  v11[0] = a2;
  v12.z = z;
  if ( *(float *)&v3 < 0.0 )
  {
    if ( v12.y < 0.0 )
    {
      furthest_vertex_id = v12.z >= 0.0;
    }
    else if ( v12.z < 0.0 )
    {
      furthest_vertex_id = 3;
    }
    else
    {
      furthest_vertex_id = 2;
    }
  }
  else if ( v12.y < 0.0 )
  {
    if ( v12.z < 0.0 )
      furthest_vertex_id = 4;
    else
      furthest_vertex_id = 5;
  }
  else if ( v12.z < 0.0 )
  {
    furthest_vertex_id = 6;
  }
  else
  {
    furthest_vertex_id = 7;
  }
  m_object = this->m_structure.m_object;
  v6 = alloca(12 * (m_object->m_sectors.m_end - m_object->m_sectors.m_begin));
  m_end = m_object->m_sectors.m_end;
  p_m_aabb = &m_object->m_sectors.m_begin->m_aabb;
  v9 = v11;
  v13 = v11;
  if ( p_m_aabb != (vostok::math::aabb *)m_end )
  {
    do
    {
      v10 = vostok::math::aabb::vertex(p_m_aabb, &v12, (vostok::math::float3 *)furthest_vertex_id, v11[0]);
      if ( v9 )
      {
        *(_QWORD *)v9 = *(_QWORD *)&v10->x;
        v9[2] = LODWORD(v10->z);
      }
      p_m_aabb = (vostok::math::aabb *)((char *)p_m_aabb + 32);
      v9 += 3;
    }
    while ( p_m_aabb != (vostok::math::aabb *)m_end );
    v9 = v13;
  }
  vostok::render::culling::sector_double_query_preventer::make_frustum_images(
    (vostok::render::culling::sector_double_query_preventer *)this,
    this->m_preventer,
    (const vostok::math::float3 *)v9);
}

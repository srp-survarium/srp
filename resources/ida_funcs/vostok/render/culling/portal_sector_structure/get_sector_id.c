vostok::memory::base_allocator *__userpurge vostok::render::culling::portal_sector_structure::get_sector_id@<eax>(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::memory::base_allocator *allocator,
        const vostok::math::float3 *pos)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  __int64 v9; // xmm4_8
  vostok::collision::space_partitioning_tree *m_sectors_spatial_tree; // ecx
  float v12; // esi
  const vostok::math::float4x4 *v13; // eax
  vostok::collision::triangle_result *M_data; // edx
  vostok::render::culling::portal *m_begin; // ebx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  unsigned int v19; // ecx
  vostok::collision::triangle_result *v20; // esi
  vostok::memory::base_allocator *m_allocator; // xmm3_4
  unsigned int v22; // edx
  float *p_x; // ecx
  float v24; // esi
  vostok::vectora<vostok::collision::triangle_result> results; // [esp+1Ch] [ebp-E4h] BYREF
  float dist; // [esp+2Ch] [ebp-D4h]
  __int64 v29; // [esp+30h] [ebp-D0h] BYREF
  int v30; // [esp+38h] [ebp-C8h]
  vostok::math::aabb aabb; // [esp+3Ch] [ebp-C4h] BYREF
  vostok::math::cuboid v32; // [esp+54h] [ebp-ACh] BYREF
  char v33; // [esp+CCh] [ebp-34h] BYREF

  x = pos->x;
  *(float *)&results._M_impl._M_start = pos->x - 0.1;
  y = pos->y;
  *(float *)&results._M_impl._M_finish = y - 0.1;
  z = pos->z;
  v9 = *(_QWORD *)&results._M_impl._M_start;
  results._M_impl._M_end_of_storage.m_allocator = allocator;
  *(float *)&results._M_impl._M_start = x + 0.1;
  *(float *)&results._M_impl._M_finish = y + 0.1;
  aabb.min.z = z + 0.1;
  m_sectors_spatial_tree = this->m_sectors_spatial_tree;
  *(float *)&v30 = z - 0.1;
  v29 = v9;
  *(_QWORD *)&aabb.min.x = *(_QWORD *)&results._M_impl._M_start;
  results._M_impl._M_start = 0;
  results._M_impl._M_finish = 0;
  results._M_impl._M_end_of_storage._M_data = 0;
  if ( !((unsigned __int8 (__thiscall *)(vostok::collision::space_partitioning_tree *, int, __int64 *, vostok::vectora<vostok::collision::triangle_result> *, int, int, int))m_sectors_spatial_tree->aabb_query)(
          m_sectors_spatial_tree,
          1,
          &v29,
          &results,
          a3,
          a4,
          a2) )
    goto LABEL_14;
  v12 = dist;
  results._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)results._M_impl._M_end_of_storage._M_data->object->m_user_data;
  if ( stlp_std::priv::__find_if<vostok::collision::triangle_result *,stlp_std::unary_negate<vostok::render::culling::collision_result_user_data_equalls_to>>(
         results._M_impl._M_end_of_storage._M_data + 1,
         (vostok::collision::triangle_result *)LODWORD(dist),
         (stlp_std::unary_negate<vostok::render::culling::collision_result_user_data_equalls_to>)results._M_impl._M_end_of_storage.m_allocator) == (vostok::collision::triangle_result *)LODWORD(v12) )
    goto LABEL_14;
  if ( results._M_impl._M_end_of_storage._M_data != (vostok::collision::triangle_result *)LODWORD(v12) )
    dist = *(float *)&results._M_impl._M_end_of_storage._M_data;
  v13 = vostok::math::float4x4::identity((vostok::math::float4x4 *)&v33);
  vostok::math::cuboid::cuboid(&v32, &aabb, v13);
  if ( this->m_portals_geometry->cuboid_query(
         this->m_portals_geometry,
         0,
         &v32,
         (vostok::vectora<vostok::collision::triangle_result> *)&results._M_impl._M_end_of_storage._M_data) )
  {
    M_data = results._M_impl._M_end_of_storage._M_data;
    m_begin = this->m_portals.m_begin;
    v16 = pos->z;
    v17 = pos->y;
    v18 = pos->x;
    v19 = results._M_impl._M_end_of_storage._M_data->triangle_id >> 1;
    v20 = results._M_impl._M_end_of_storage._M_data + 1;
    results._M_impl._M_end_of_storage.m_allocator = COERCE_VOSTOK_MEMORY_BASE_ALLOCATOR_(
                                                      fabs(
                                                        (float)((float)((float)(m_begin[v19].m_plane.normal.z * v16)
                                                                      + (float)(m_begin[v19].m_plane.normal.y * v17))
                                                              + (float)(pos->x * m_begin[v19].m_plane.normal.x))
                                                      + m_begin[v19].m_plane.d));
    if ( &results._M_impl._M_end_of_storage._M_data[1] != (vostok::collision::triangle_result *)LODWORD(dist) )
    {
      m_allocator = results._M_impl._M_end_of_storage.m_allocator;
      do
      {
        v22 = v20->triangle_id >> 1;
        if ( v22 != v19 )
        {
          *(float *)&results._M_impl._M_end_of_storage.m_allocator = (float)((float)((float)(m_begin[v22].m_plane.normal.z
                                                                                           * v16)
                                                                                   + (float)(m_begin[v22].m_plane.normal.y
                                                                                           * v17))
                                                                           + (float)(v18 * m_begin[v22].m_plane.normal.x))
                                                                   + m_begin[v22].m_plane.d;
          v30 = (int)results._M_impl._M_end_of_storage.m_allocator & 0x7FFFFFFF;
          if ( *(float *)&m_allocator > COERCE_FLOAT((int)results._M_impl._M_end_of_storage.m_allocator & 0x7FFFFFFF) )
          {
            m_allocator = (vostok::memory::base_allocator *)((int)results._M_impl._M_end_of_storage.m_allocator
                                                           & 0x7FFFFFFF);
            v19 = v22;
          }
        }
        ++v20;
      }
      while ( v20 != (vostok::collision::triangle_result *)LODWORD(dist) );
      M_data = results._M_impl._M_end_of_storage._M_data;
    }
    p_x = &m_begin[v19].m_plane.normal.x;
    v24 = p_x[((float)((float)((float)((float)(p_x[2] * v16) + (float)(p_x[1] * v17)) + (float)(v18 * *p_x)) + p_x[3]) <= 0.0)
            + 4];
    (*(void (__thiscall **)(_DWORD, vostok::collision::triangle_result *))(*(_DWORD *)v29 + 24))(v29, M_data);
    return (vostok::memory::base_allocator *)LODWORD(v24);
  }
  else
  {
LABEL_14:
    if ( results._M_impl._M_end_of_storage._M_data )
      (*(void (__thiscall **)(_DWORD, vostok::collision::triangle_result *))(*(_DWORD *)v29 + 24))(
        v29,
        results._M_impl._M_end_of_storage._M_data);
    return results._M_impl._M_end_of_storage.m_allocator;
  }
}

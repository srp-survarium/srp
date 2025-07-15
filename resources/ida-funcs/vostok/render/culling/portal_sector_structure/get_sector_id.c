unsigned int __usercall vostok::render::culling::portal_sector_structure::get_sector_id@<eax>(
        vostok::render::culling::portal_sector_structure *this@<edx>,
        const vostok::math::float3 *pos@<ecx>,
        int a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>)
{
  vostok::collision::space_partitioning_tree *m_sectors_spatial_tree; // ecx
  vostok::collision::triangle_result *v8; // ebx
  vostok::collision::triangle_result *v9; // eax
  vostok::math::float4x4 *v10; // eax
  vostok::render::culling::portal *m_begin; // edi
  float z; // xmm1_4
  float y; // xmm2_4
  float x; // xmm3_4
  unsigned int v15; // ecx
  vostok::collision::triangle_result *v16; // edx
  float v17; // xmm0_4
  unsigned int v18; // ebx
  float *p_x; // ecx
  vostok::math::float4x4 *v23; // [esp-4h] [ebp-2100h]
  vostok::collision::triangle_result *v24; // [esp+4h] [ebp-20F8h] BYREF
  vostok::collision::triangle_result *__last; // [esp+8h] [ebp-20F4h]
  char *v26; // [esp+Ch] [ebp-20F0h]
  _BYTE v27[8192]; // [esp+10h] [ebp-20ECh] BYREF
  char v28; // [esp+2010h] [ebp-ECh] BYREF
  vostok::math::float4x4 v29; // [esp+2014h] [ebp-E8h] BYREF
  vostok::math::cuboid v30; // [esp+2054h] [ebp-A8h] BYREF
  vostok::math::aabb v31; // [esp+20D0h] [ebp-2Ch] BYREF
  vostok::math::float3 v32; // [esp+20E8h] [ebp-14h] BYREF
  float v33; // [esp+20F4h] [ebp-8h]
  stlp_std::unary_negate<vostok::render::culling::collision_result_user_data_equalls_to> v34; // [esp+20F8h] [ebp-4h]

  v34._M_pred.m_user_data = 0;
  v32.x = FLOAT_0_1;
  v32.y = FLOAT_0_1;
  v32.z = FLOAT_0_1;
  vostok::math::create_aabb_center_radius(&v32, pos, &v31);
  m_sectors_spatial_tree = this->m_sectors_spatial_tree;
  v24 = (vostok::collision::triangle_result *)v27;
  __last = (vostok::collision::triangle_result *)v27;
  v26 = &v28;
  if ( !((unsigned __int8 (__thiscall *)(vostok::collision::space_partitioning_tree *, int, vostok::math::aabb *, vostok::collision::triangle_result **, int, int, int))m_sectors_spatial_tree->aabb_query)(
          m_sectors_spatial_tree,
          1,
          &v31,
          &v24,
          a4,
          a5,
          a3) )
    return v34._M_pred.m_user_data;
  v8 = v24;
  v34._M_pred.m_user_data = (unsigned int)v24->object->m_user_data;
  v9 = stlp_std::find_if<vostok::collision::triangle_result *,stlp_std::unary_negate<vostok::render::culling::collision_result_user_data_equalls_to>>(
         v24 + 1,
         __last,
         v34);
  if ( v9 == __last )
    return v34._M_pred.m_user_data;
  __last = v8;
  v10 = vostok::math::float4x4::identity(v23, &v29);
  vostok::math::cuboid::cuboid(&v31, v10, &v30);
  if ( !this->m_portals_geometry->cuboid_query(
          this->m_portals_geometry,
          0,
          &v30,
          (vostok::buffer_vector<vostok::collision::triangle_result> *)&v24) )
    return v34._M_pred.m_user_data;
  m_begin = this->m_portals.m_begin;
  z = pos->z;
  y = pos->y;
  x = pos->x;
  v15 = v24->triangle_id >> 1;
  v16 = v24 + 1;
  v34._M_pred.m_user_data = fabs(
                              (float)((float)((float)(m_begin[v15].m_plane.normal.y * y)
                                            + (float)(m_begin[v15].m_plane.normal.z * z))
                                    + (float)(pos->x * m_begin[v15].m_plane.normal.x))
                            + m_begin[v15].m_plane.d);
  if ( &v24[1] != __last )
  {
    v17 = *(float *)&v34._M_pred.m_user_data;
    do
    {
      v18 = v16->triangle_id >> 1;
      if ( v18 != v15 )
      {
        v33 = (float)((float)((float)(m_begin[v18].m_plane.normal.y * y) + (float)(m_begin[v18].m_plane.normal.z * z))
                    + (float)(x * m_begin[v18].m_plane.normal.x))
            + m_begin[v18].m_plane.d;
        v34._M_pred.m_user_data = LODWORD(v33) & 0x7FFFFFFF;
        if ( v17 > COERCE_FLOAT(LODWORD(v33) & 0x7FFFFFFF) )
        {
          v17 = *(float *)&v34._M_pred.m_user_data;
          v15 = v18;
        }
      }
      ++v16;
    }
    while ( v16 != __last );
  }
  p_x = &m_begin[v15].m_plane.normal.x;
  return LODWORD(p_x[((float)((float)((float)((float)(p_x[1] * y) + (float)(p_x[2] * z)) + (float)(*p_x * x)) + p_x[3]) <= 0.0)
                   + 4]);
}

bool __userpurge vostok::collision::terrain_data::ray_test_quad@<al>(
        int y@<edx>,
        int x@<eax>,
        vostok::collision::terrain_data *this,
        const vostok::math::float3 *ray_point,
        const vostok::math::float3 *ray_dir,
        float max_distance,
        float *range,
        bool log_out)
{
  unsigned int m_vertex_row_size; // ecx
  unsigned int v10; // ecx
  unsigned __int16 v11; // si
  vostok::math::float3 *v12; // esi
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v15; // [esp-Ch] [ebp-5Ch]
  unsigned __int16 quad_2; // [esp+16h] [ebp-3Ah]
  vostok::math::float3 v17; // [esp+20h] [ebp-30h] BYREF
  vostok::math::float3 v18; // [esp+2Ch] [ebp-24h] BYREF
  vostok::math::float3 v19; // [esp+38h] [ebp-18h] BYREF
  vostok::math::float3 v20; // [esp+44h] [ebp-Ch] BYREF
  vostok::math::float3 *thisa; // [esp+54h] [ebp+4h]

  if ( x < 0 )
    return 0;
  if ( y < 0 )
    return 0;
  m_vertex_row_size = this->m_vertex_row_size;
  if ( x >= (int)(m_vertex_row_size - 1) || y >= (int)(m_vertex_row_size - 1) )
    return 0;
  v10 = m_vertex_row_size - 1;
  quad_2 = (unsigned __int16)(x + y * v10) / v10 + x + y * v10;
  v11 = v10 + quad_2 + 1;
  v15 = vostok::collision::terrain_data::position(v10 + quad_2 + 2, &v17, this);
  thisa = vostok::collision::terrain_data::position(v11, &v18, this);
  v12 = vostok::collision::terrain_data::position(quad_2 + 1, &v19, this);
  v13 = vostok::collision::terrain_data::position(quad_2, &v20, this);
  return vostok::collision::ray_test_quad(v13, v12, thisa, range, v15, ray_point, ray_dir, max_distance);
}

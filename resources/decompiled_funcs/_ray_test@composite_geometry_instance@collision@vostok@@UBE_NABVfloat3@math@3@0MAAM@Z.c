char __thiscall vostok::collision::composite_geometry_instance::ray_test(
        vostok::collision::composite_geometry_instance *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v9; // xmm7_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  unsigned int v15; // xmm3_4
  unsigned int v16; // xmm4_4
  float v17; // xmm7_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  const vostok::collision::composite_geometry *m_geometry; // esi
  vostok::collision::geometry_instance **m_begin; // edi
  vostok::collision::geometry_instance **m_end; // esi
  float v30; // [esp+14h] [ebp-28h]
  vostok::math::float3 new_origin; // [esp+18h] [ebp-24h] BYREF
  float v32; // [esp+24h] [ebp-18h]
  float v33; // [esp+28h] [ebp-14h]
  vostok::math::float3 new_direction; // [esp+30h] [ebp-Ch] BYREF
  float new_max_distancea; // [esp+40h] [ebp+4h]
  float new_max_distance; // [esp+40h] [ebp+4h]
  float directiona; // [esp+44h] [ebp+8h]

  z = origin->z;
  y = origin->y;
  x = origin->x;
  v9 = direction->x;
  v11 = (float)((float)(this->m_inverted_matrix.j.x * y) + (float)(this->m_inverted_matrix.k.x * z))
      + (float)(this->m_inverted_matrix.i.x * origin->x);
  v12 = (float)((float)(this->m_inverted_matrix.i.y * origin->x) + (float)(this->m_inverted_matrix.j.y * y))
      + (float)(this->m_inverted_matrix.k.y * z);
  directiona = direction->y;
  new_max_distancea = v9;
  v13 = this->m_inverted_matrix.j.x * directiona;
  v14 = this->m_inverted_matrix.k.x;
  new_origin.z = (float)((float)((float)(this->m_inverted_matrix.i.z * x) + (float)(this->m_inverted_matrix.j.z * y))
                       + (float)(this->m_inverted_matrix.k.z * z))
               + this->m_inverted_matrix.c.z;
  *(float *)&v15 = v11 + this->m_inverted_matrix.c.x;
  *(float *)&v16 = v12 + this->m_inverted_matrix.c.y;
  v30 = direction->z;
  v17 = (float)(v13 + (float)(v14 * v30)) + (float)(new_max_distancea * this->m_inverted_matrix.i.x);
  v18 = this->m_inverted_matrix.j.z * directiona;
  new_direction.y = (float)((float)(this->m_inverted_matrix.i.y * new_max_distancea)
                          + (float)(this->m_inverted_matrix.j.y * directiona))
                  + (float)(this->m_inverted_matrix.k.y * v30);
  v19 = (float)(this->m_inverted_matrix.i.z * new_max_distancea) + v18;
  new_direction.x = v17;
  new_direction.z = v19 + (float)(this->m_inverted_matrix.k.z * v30);
  v32 = new_max_distancea * max_distance;
  *(_QWORD *)&new_origin.x = __PAIR64__(v16, v15);
  v33 = directiona * max_distance;
  v20 = x + (float)(new_max_distancea * max_distance);
  v21 = y + (float)(directiona * max_distance);
  v22 = z + (float)(v30 * max_distance);
  v23 = (float)((float)((float)((float)(this->m_inverted_matrix.k.x * v22) + (float)(this->m_inverted_matrix.j.x * v21))
                      + (float)(v20 * this->m_inverted_matrix.i.x))
              + this->m_inverted_matrix.c.x)
      - *(float *)&v15;
  v24 = (float)((float)((float)((float)(this->m_inverted_matrix.k.z * v22) + (float)(this->m_inverted_matrix.j.z * v21))
                      + (float)(this->m_inverted_matrix.i.z * v20))
              + this->m_inverted_matrix.c.z)
      - new_origin.z;
  v25 = (float)((float)((float)((float)(this->m_inverted_matrix.k.y * v22) + (float)(this->m_inverted_matrix.j.y * v21))
                      + (float)(this->m_inverted_matrix.i.y * v20))
              + this->m_inverted_matrix.c.y)
      - *(float *)&v16;
  new_max_distance = sqrtf((float)((float)(v24 * v24) + (float)(v25 * v25)) + (float)(v23 * v23));
  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  m_end = m_geometry->m_geometry_instances.m_end;
  if ( m_begin == m_end )
    return 0;
  while ( !((unsigned __int8 (__stdcall *)(vostok::math::float3 *, vostok::math::float3 *, float, float *))(*m_begin)->ray_test)(
             &new_origin,
             &new_direction,
             COERCE_FLOAT(LODWORD(new_max_distance)),
             distance) )
  {
    if ( ++m_begin == m_end )
      return 0;
  }
  *distance = (float)(*distance / new_max_distance) * max_distance;
  return 1;
}

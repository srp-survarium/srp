char __thiscall vostok::collision::triangle_mesh_geometry_instance::ray_test(
        vostok::collision::triangle_mesh_geometry_instance *this,
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
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  char result; // al
  float v27; // [esp+Ch] [ebp-28h]
  vostok::math::float3 new_origin; // [esp+10h] [ebp-24h] BYREF
  float v29; // [esp+1Ch] [ebp-18h]
  float v30; // [esp+20h] [ebp-14h]
  vostok::math::float3 new_direction; // [esp+28h] [ebp-Ch] BYREF
  float new_max_distancea; // [esp+38h] [ebp+4h]
  float new_max_distance; // [esp+38h] [ebp+4h]
  float directiona; // [esp+3Ch] [ebp+8h]

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
  v27 = direction->z;
  v17 = (float)(v13 + (float)(v14 * v27)) + (float)(this->m_inverted_matrix.i.x * new_max_distancea);
  v18 = this->m_inverted_matrix.j.z * directiona;
  new_direction.y = (float)((float)(this->m_inverted_matrix.i.y * new_max_distancea)
                          + (float)(this->m_inverted_matrix.j.y * directiona))
                  + (float)(this->m_inverted_matrix.k.y * v27);
  v19 = (float)(this->m_inverted_matrix.i.z * new_max_distancea) + v18;
  new_direction.x = v17;
  new_direction.z = v19 + (float)(this->m_inverted_matrix.k.z * v27);
  v29 = new_max_distancea * max_distance;
  *(_QWORD *)&new_origin.x = __PAIR64__(v16, v15);
  v30 = directiona * max_distance;
  v20 = y + (float)(directiona * max_distance);
  v21 = x + (float)(new_max_distancea * max_distance);
  v22 = z + (float)(v27 * max_distance);
  v23 = (float)((float)((float)((float)(this->m_inverted_matrix.k.x * v22) + (float)(this->m_inverted_matrix.j.x * v20))
                      + (float)(this->m_inverted_matrix.i.x * v21))
              + this->m_inverted_matrix.c.x)
      - *(float *)&v15;
  v24 = (float)((float)((float)((float)(this->m_inverted_matrix.k.z * v22) + (float)(this->m_inverted_matrix.j.z * v20))
                      + (float)(this->m_inverted_matrix.i.z * v21))
              + this->m_inverted_matrix.c.z)
      - new_origin.z;
  v25 = (float)((float)((float)((float)(this->m_inverted_matrix.k.y * v22) + (float)(this->m_inverted_matrix.j.y * v20))
                      + (float)(this->m_inverted_matrix.i.y * v21))
              + this->m_inverted_matrix.c.y)
      - *(float *)&v16;
  new_max_distance = sqrtf((float)((float)(v24 * v24) + (float)(v25 * v25)) + (float)(v23 * v23));
  result = ((int (__stdcall *)(vostok::math::float3 *, vostok::math::float3 *, _DWORD, float *))this->m_triangle_mesh->ray_test)(
             &new_origin,
             &new_direction,
             LODWORD(new_max_distance),
             distance);
  if ( result )
  {
    *distance = (float)(*distance / new_max_distance) * max_distance;
    return 1;
  }
  return result;
}

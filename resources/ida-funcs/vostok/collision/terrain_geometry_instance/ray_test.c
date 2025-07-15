bool __userpurge vostok::collision::terrain_geometry_instance::ray_test@<al>(
        vostok::collision::terrain_geometry_instance *this@<ecx>,
        bool a2@<dil>,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v10; // xmm7_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  unsigned int v16; // xmm3_4
  unsigned int v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  bool result; // al
  long double v24; // st7
  float v25; // [esp+Ch] [ebp-28h]
  float v26; // [esp+10h] [ebp-24h]
  float v27; // [esp+14h] [ebp-20h]
  float v28; // [esp+18h] [ebp-1Ch]
  vostok::math::float3 new_origin; // [esp+1Ch] [ebp-18h] BYREF
  vostok::math::float3 new_direction; // [esp+28h] [ebp-Ch] BYREF
  const vostok::math::float3 *origina; // [esp+38h] [ebp+4h]
  float directiona; // [esp+3Ch] [ebp+8h]

  z = origin->z;
  y = origin->y;
  x = origin->x;
  v10 = direction->x;
  v11 = (float)((float)(this->m_inverted_matrix.j.x * y) + (float)(this->m_inverted_matrix.k.x * z))
      + (float)(this->m_inverted_matrix.i.x * origin->x);
  v12 = (float)((float)(this->m_inverted_matrix.i.y * origin->x) + (float)(this->m_inverted_matrix.j.y * y))
      + (float)(this->m_inverted_matrix.k.y * z);
  directiona = direction->y;
  *(float *)&origina = v10;
  v13 = this->m_inverted_matrix.j.x * directiona;
  v14 = this->m_inverted_matrix.k.x;
  new_origin.z = (float)((float)((float)(this->m_inverted_matrix.i.z * x) + (float)(this->m_inverted_matrix.j.z * y))
                       + (float)(this->m_inverted_matrix.k.z * z))
               + this->m_inverted_matrix.c.z;
  v25 = direction->z;
  v15 = (float)(v13 + (float)(v14 * v25)) + (float)(this->m_inverted_matrix.i.x * *(float *)&origina);
  *(float *)&v16 = v11 + this->m_inverted_matrix.c.x;
  *(float *)&v17 = v12 + this->m_inverted_matrix.c.y;
  v18 = this->m_inverted_matrix.j.z * directiona;
  new_direction.y = (float)((float)(this->m_inverted_matrix.i.y * *(float *)&origina)
                          + (float)(this->m_inverted_matrix.j.y * directiona))
                  + (float)(this->m_inverted_matrix.k.y * v25);
  v19 = (float)(this->m_inverted_matrix.i.z * *(float *)&origina) + v18;
  new_direction.x = v15;
  new_direction.z = v19 + (float)(this->m_inverted_matrix.k.z * v25);
  v20 = x + (float)(*(float *)&origina * max_distance);
  *(_QWORD *)&new_origin.x = __PAIR64__(v17, v16);
  v21 = y + (float)(directiona * max_distance);
  v22 = z + (float)(v25 * max_distance);
  v26 = (float)((float)((float)((float)(this->m_inverted_matrix.k.x * v22) + (float)(this->m_inverted_matrix.j.x * v21))
                      + (float)(this->m_inverted_matrix.i.x * v20))
              + this->m_inverted_matrix.c.x)
      - *(float *)&v16;
  v27 = (float)((float)((float)((float)(this->m_inverted_matrix.k.y * v22) + (float)(this->m_inverted_matrix.j.y * v21))
                      + (float)(this->m_inverted_matrix.i.y * v20))
              + this->m_inverted_matrix.c.y)
      - *(float *)&v17;
  v28 = (float)((float)((float)((float)(this->m_inverted_matrix.k.z * v22) + (float)(this->m_inverted_matrix.j.z * v21))
                      + (float)(this->m_inverted_matrix.i.z * v20))
              + this->m_inverted_matrix.c.z)
      - new_origin.z;
  result = vostok::collision::terrain_ray_test<vostok::collision::terrain_data>(
             &new_origin,
             &new_direction,
             a2,
             &this->m_data,
             max_distance,
             distance);
  if ( result )
  {
    v24 = sqrtf((float)((float)(v28 * v28) + (float)(v27 * v27)) + (float)(v26 * v26));
    result = 1;
    *distance = *distance / v24 * max_distance;
  }
  return result;
}

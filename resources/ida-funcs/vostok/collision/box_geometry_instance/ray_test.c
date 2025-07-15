bool __thiscall vostok::collision::box_geometry_instance::ray_test(
        vostok::collision::box_geometry_instance *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  unsigned int v12; // xmm3_4
  unsigned int v13; // xmm4_4
  float v14; // xmm7_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm7_4
  float v19; // xmm5_4
  bool result; // al
  long double v21; // st7
  __int64 v22; // [esp+154h] [ebp-80h]
  float v23; // [esp+15Ch] [ebp-78h]
  float v24; // [esp+160h] [ebp-74h]
  float v25; // [esp+164h] [ebp-70h]
  float v26; // [esp+168h] [ebp-6Ch]
  vostok::math::float3 v27; // [esp+16Ch] [ebp-68h] BYREF
  vostok::math::float3 v28; // [esp+178h] [ebp-5Ch] BYREF
  vostok::collision::colliders::sse::aabb_a16 v29; // [esp+184h] [ebp-50h] BYREF
  vostok::collision::colliders::ray_aabb_collider v30; // [esp+1A4h] [ebp-30h] BYREF

  z = origin->z;
  y = origin->y;
  x = origin->x;
  v8 = (float)((float)(this->m_inverted_matrix.j.x * y) + (float)(this->m_inverted_matrix.k.x * z))
     + (float)(origin->x * this->m_inverted_matrix.i.x);
  v9 = (float)((float)(this->m_inverted_matrix.i.y * origin->x) + (float)(this->m_inverted_matrix.j.y * y))
     + (float)(this->m_inverted_matrix.k.y * z);
  v22 = *(_QWORD *)&direction->x;
  v10 = this->m_inverted_matrix.j.x * direction->y;
  v11 = this->m_inverted_matrix.k.x;
  v27.z = (float)((float)((float)(this->m_inverted_matrix.i.z * origin->x) + (float)(this->m_inverted_matrix.j.z * y))
                + (float)(this->m_inverted_matrix.k.z * z))
        + this->m_inverted_matrix.c.z;
  v23 = direction->z;
  *(float *)&v12 = v8 + this->m_inverted_matrix.c.x;
  *(float *)&v13 = v9 + this->m_inverted_matrix.c.y;
  v14 = (float)(v10 + (float)(v11 * v23)) + (float)(*(float *)&v22 * this->m_inverted_matrix.i.x);
  v15 = this->m_inverted_matrix.j.z * *((float *)&v22 + 1);
  v28.y = (float)((float)(this->m_inverted_matrix.i.y * *(float *)&v22)
                + (float)(this->m_inverted_matrix.j.y * *((float *)&v22 + 1)))
        + (float)(this->m_inverted_matrix.k.y * v23);
  v16 = (float)(this->m_inverted_matrix.i.z * *(float *)&v22) + v15;
  v28.x = v14;
  v28.z = v16 + (float)(this->m_inverted_matrix.k.z * v23);
  v17 = x + (float)(*(float *)&v22 * max_distance);
  *(_QWORD *)&v27.x = __PAIR64__(v13, v12);
  v18 = y + (float)(*((float *)&v22 + 1) * max_distance);
  v19 = z + (float)(v23 * max_distance);
  v24 = (float)((float)((float)((float)(this->m_inverted_matrix.k.x * v19) + (float)(this->m_inverted_matrix.j.x * v18))
                      + (float)(this->m_inverted_matrix.i.x * v17))
              + this->m_inverted_matrix.c.x)
      - *(float *)&v12;
  v25 = (float)((float)((float)((float)(this->m_inverted_matrix.k.y * v19) + (float)(this->m_inverted_matrix.j.y * v18))
                      + (float)(this->m_inverted_matrix.i.y * v17))
              + this->m_inverted_matrix.c.y)
      - *(float *)&v13;
  v26 = (float)((float)((float)((float)(this->m_inverted_matrix.k.z * v19) + (float)(this->m_inverted_matrix.j.z * v18))
                      + (float)(this->m_inverted_matrix.i.z * v17))
              + this->m_inverted_matrix.c.z)
      - v27.z;
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&v30, &v27, &v28);
  *(_QWORD *)&v29.min.x = 0xBF800000BF800000uLL;
  LODWORD(v27.z) = clear_value;
  v29.min.z = -1.0;
  LODWORD(v27.x) = clear_value;
  LODWORD(v27.y) = clear_value;
  v29.min.padding = 0.0;
  *(_QWORD *)&v29.max.x = *(_QWORD *)&v27.x;
  LODWORD(v29.max.z) = clear_value;
  v29.max.padding = 0.0;
  result = vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(&v30, &v29, distance);
  if ( result )
  {
    v21 = sqrtf((float)((float)(v26 * v26) + (float)(v25 * v25)) + (float)(v24 * v24));
    result = 1;
    *distance = *distance / v21 * max_distance;
  }
  return result;
}

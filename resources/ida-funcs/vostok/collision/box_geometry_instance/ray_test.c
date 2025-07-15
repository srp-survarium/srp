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
  float v15; // xmm6_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  bool result; // al
  __int64 v21; // [esp+10h] [ebp-80h]
  float v22; // [esp+18h] [ebp-78h]
  float v23; // [esp+1Ch] [ebp-74h]
  float v24; // [esp+20h] [ebp-70h]
  float v25; // [esp+24h] [ebp-6Ch]
  vostok::math::float3 origina; // [esp+28h] [ebp-68h] BYREF
  vostok::math::float3 directiona; // [esp+34h] [ebp-5Ch] BYREF
  vostok::collision::colliders::sse::aabb_a16 aabb; // [esp+40h] [ebp-50h] BYREF
  vostok::collision::colliders::ray_aabb_collider v29; // [esp+60h] [ebp-30h] BYREF

  z = origin->z;
  y = origin->y;
  x = origin->x;
  v8 = (float)((float)(this->m_inverted_matrix.j.x * y) + (float)(this->m_inverted_matrix.k.x * z))
     + (float)(origin->x * this->m_inverted_matrix.i.x);
  v9 = (float)((float)(this->m_inverted_matrix.i.y * origin->x) + (float)(this->m_inverted_matrix.j.y * y))
     + (float)(this->m_inverted_matrix.k.y * z);
  v21 = *(_QWORD *)&direction->x;
  v10 = this->m_inverted_matrix.j.x * direction->y;
  v11 = this->m_inverted_matrix.k.x;
  origina.z = (float)((float)((float)(this->m_inverted_matrix.i.z * origin->x) + (float)(this->m_inverted_matrix.j.z * y))
                    + (float)(this->m_inverted_matrix.k.z * z))
            + this->m_inverted_matrix.c.z;
  v22 = direction->z;
  *(float *)&v12 = v8 + this->m_inverted_matrix.c.x;
  *(float *)&v13 = v9 + this->m_inverted_matrix.c.y;
  v14 = (float)(v10 + (float)(v11 * v22)) + (float)(*(float *)&v21 * this->m_inverted_matrix.i.x);
  v15 = this->m_inverted_matrix.i.z * *(float *)&v21;
  directiona.y = (float)((float)(this->m_inverted_matrix.i.y * *(float *)&v21)
                       + (float)(this->m_inverted_matrix.j.y * *((float *)&v21 + 1)))
               + (float)(this->m_inverted_matrix.k.y * v22);
  v16 = v15 + (float)(this->m_inverted_matrix.j.z * *((float *)&v21 + 1));
  directiona.x = v14;
  directiona.z = v16 + (float)(this->m_inverted_matrix.k.z * v22);
  v17 = x + (float)(*(float *)&v21 * max_distance);
  v18 = y + (float)(*((float *)&v21 + 1) * max_distance);
  *(_QWORD *)&origina.x = __PAIR64__(v13, v12);
  v19 = z + (float)(v22 * max_distance);
  v23 = (float)((float)((float)((float)(this->m_inverted_matrix.k.x * v19) + (float)(this->m_inverted_matrix.j.x * v18))
                      + (float)(this->m_inverted_matrix.i.x * v17))
              + this->m_inverted_matrix.c.x)
      - *(float *)&v12;
  v24 = (float)((float)((float)((float)(this->m_inverted_matrix.k.y * v19) + (float)(this->m_inverted_matrix.j.y * v18))
                      + (float)(this->m_inverted_matrix.i.y * v17))
              + this->m_inverted_matrix.c.y)
      - *(float *)&v13;
  v25 = (float)((float)((float)((float)(this->m_inverted_matrix.k.z * v19) + (float)(this->m_inverted_matrix.j.z * v18))
                      + (float)(this->m_inverted_matrix.i.z * v17))
              + this->m_inverted_matrix.c.z)
      - origina.z;
  vostok::collision::colliders::ray_aabb_collider::ray_aabb_collider(&v29, &directiona, &origina);
  directiona.x = s_bm_current_air_resistance;
  directiona.y = s_bm_current_air_resistance;
  directiona.z = s_bm_current_air_resistance;
  memset(&origina, 0, sizeof(origina));
  vostok::collision::colliders::sse::construct_aabb_a16(&origina, &directiona, &aabb);
  result = vostok::collision::colliders::ray_aabb_collider::intersects_aabb_sse(&aabb, &v29, distance);
  if ( result )
  {
    *distance = (float)(*distance / fsqrt((float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v23 * v23)))
              * max_distance;
    return 1;
  }
  return result;
}

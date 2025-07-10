void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  vostok::math::float4_pod *p_j; // edi
  const vostok::math::float4x4 *v6; // eax
  float m_half_length; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float z; // [esp+14h] [ebp-20h]
  float y; // [esp+14h] [ebp-20h]
  float v20; // [esp+18h] [ebp-1Ch]
  float v; // [esp+1Ch] [ebp-18h]
  float bounding_volumeb; // [esp+38h] [ebp+4h]
  float bounding_volumea; // [esp+38h] [ebp+4h]
  float testeea; // [esp+3Ch] [ebp+8h]

  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  p_j = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->j;
  v6 = this->m_testee->get_matrix(this->m_testee);
  m_half_length = bounding_volume->m_half_length;
  v9 = p_c->x - (float)(p_j->x * m_half_length);
  bounding_volumeb = p_c->y;
  v10 = bounding_volumeb - (float)(p_j->y * m_half_length);
  z = p_c->z;
  v11 = z - (float)(p_j->z * m_half_length);
  v12 = bounding_volume->m_half_length;
  v13 = bounding_volumeb + (float)(p_j->y * v12);
  v = (float)(p_c->x + (float)(p_j->x * v12)) - v9;
  v14 = (float)(z + (float)(p_j->z * v12)) - v11;
  v20 = v6->c.z;
  bounding_volumea = v6->c.x;
  y = v6->c.y;
  v15 = v13 - v10;
  v16 = (float)((float)((float)((float)(v20 - v11) * v14) + (float)((float)(y - v10) * v15))
              + (float)((float)(bounding_volumea - v9) * v))
      / (float)((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v * v));
  v17 = 0.0;
  if ( v16 > 0.0 )
  {
    v17 = *(float *)&clear_value;
    if ( *(float *)&clear_value >= v16 )
      v17 = (float)((float)((float)((float)(v20 - v11) * v14) + (float)((float)(y - v10) * v15))
                  + (float)((float)(bounding_volumea - v9) * v))
          / (float)((float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v * v));
  }
  testeea = sqrtf(
              (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                    + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
            + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
          + bounding_volume->m_radius;
  if ( (float)((float)((float)((float)((float)((float)(v17 * v) + v9) - bounding_volumea)
                             * (float)((float)((float)(v17 * v) + v9) - bounding_volumea))
                     + (float)((float)((float)((float)(v14 * v17) + v11) - v20)
                             * (float)((float)((float)(v14 * v17) + v11) - v20)))
             + (float)((float)((float)((float)(v15 * v17) + v10) - y) * (float)((float)((float)(v15 * v17) + v10) - y))) <= (float)(testeea * testeea) )
    this->m_result = 1;
}

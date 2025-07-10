void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  const vostok::math::float4x4 *v5; // eax
  float y; // xmm2_4
  float x; // xmm0_4
  float z; // xmm1_4
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  const vostok::math::float4x4 *v13; // esi
  float m_half_length; // xmm1_4
  float m_radius; // xmm0_4
  float v16; // [esp+18h] [ebp-64h]
  float v17; // [esp+1Ch] [ebp-60h]
  float v18; // [esp+20h] [ebp-5Ch]
  float v19; // [esp+24h] [ebp-58h]
  float v20; // [esp+28h] [ebp-54h]
  float v21; // [esp+2Ch] [ebp-50h]
  float v22; // [esp+30h] [ebp-4Ch]
  float v23; // [esp+34h] [ebp-48h]
  float v24; // [esp+38h] [ebp-44h]
  vostok::math::float4x4 inverted_matrix; // [esp+3Ch] [ebp-40h] BYREF

  v4 = this->m_testee->get_matrix(this->m_testee);
  invert_impl(
    v4,
    &inverted_matrix,
    (float)((float)((float)((float)(v4->j.y * v4->k.z) - (float)(v4->j.z * v4->k.y)) * v4->i.x)
          - (float)((float)((float)(v4->j.x * v4->k.z) - (float)(v4->k.x * v4->j.z)) * v4->i.y))
  + (float)((float)((float)(v4->j.x * v4->k.y) - (float)(v4->k.x * v4->j.y)) * v4->i.z));
  v5 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  y = v5->j.y;
  x = v5->j.x;
  z = v5->j.z;
  v22 = (float)((float)(x * inverted_matrix.i.x) + (float)(y * inverted_matrix.j.x)) + (float)(z * inverted_matrix.k.x);
  v23 = (float)((float)(x * inverted_matrix.i.y) + (float)(y * inverted_matrix.j.y)) + (float)(z * inverted_matrix.k.y);
  v24 = (float)((float)(x * inverted_matrix.i.z) + (float)(y * inverted_matrix.j.z)) + (float)(z * inverted_matrix.k.z);
  v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v10 = v9->c.y;
  v11 = v9->c.z;
  v16 = (float)((float)((float)(v9->c.x * inverted_matrix.i.x) + (float)(v10 * inverted_matrix.j.x))
              + (float)(v11 * inverted_matrix.k.x))
      + inverted_matrix.c.x;
  v12 = v9->c.x;
  v17 = (float)((float)((float)(v12 * inverted_matrix.i.y) + (float)(v10 * inverted_matrix.j.y))
              + (float)(v11 * inverted_matrix.k.y))
      + inverted_matrix.c.y;
  v18 = (float)((float)((float)(v12 * inverted_matrix.i.z) + (float)(v10 * inverted_matrix.j.z))
              + (float)(v11 * inverted_matrix.k.z))
      + inverted_matrix.c.z;
  v13 = testee->get_matrix(testee);
  v19 = sqrtf((float)((float)(v13->i.z * v13->i.z) + (float)(v13->i.x * v13->i.x)) + (float)(v13->i.y * v13->i.y));
  v20 = sqrtf((float)((float)(v13->j.z * v13->j.z) + (float)(v13->j.x * v13->j.x)) + (float)(v13->j.y * v13->j.y));
  v21 = sqrtf((float)((float)(v13->k.x * v13->k.x) + (float)(v13->k.y * v13->k.y)) + (float)(v13->k.z * v13->k.z));
  m_half_length = bounding_volume->m_half_length;
  m_radius = bounding_volume->m_radius;
  if ( COERCE_FLOAT(LODWORD(v16) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v19)
                                                        + m_radius)
    && COERCE_FLOAT(LODWORD(v17) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v20)
                                                        + m_radius)
    && COERCE_FLOAT(LODWORD(v18) & 0x7FFFFFFF) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)
                                                                        * m_half_length)
                                                                + v21)
                                                        + m_radius)
    && fabs((float)(v17 * v24) - (float)(v18 * v23)) <= (float)((float)((float)(v21
                                                                              * COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF))
                                                                      + (float)(v20
                                                                              * COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)))
                                                              + m_radius)
    && fabs((float)(v18 * v22) - (float)(v24 * v16)) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF)
                                                                              * v19)
                                                                      + (float)(v21
                                                                              * COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)))
                                                              + m_radius)
    && fabs((float)(v23 * v16) - (float)(v17 * v22)) <= (float)((float)((float)(COERCE_FLOAT(LODWORD(v23) & 0x7FFFFFFF)
                                                                              * v19)
                                                                      + (float)(v20
                                                                              * COERCE_FLOAT(LODWORD(v22) & 0x7FFFFFFF)))
                                                              + m_radius) )
  {
    this->m_result = 1;
  }
}

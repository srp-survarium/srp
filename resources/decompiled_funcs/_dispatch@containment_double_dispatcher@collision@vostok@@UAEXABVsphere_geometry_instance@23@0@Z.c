void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float z; // xmm2_4
  float x; // xmm1_4
  float y; // xmm0_4
  long double v9; // st7
  float v10; // xmm0_4
  float v11; // xmm0_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // [esp+10h] [ebp-4h]
  float v17; // [esp+10h] [ebp-4h]
  float bounding_volumea; // [esp+18h] [ebp+4h]
  float bounding_volumeb; // [esp+18h] [ebp+4h]
  float testeea; // [esp+1Ch] [ebp+8h]
  float testeeb; // [esp+1Ch] [ebp+8h]
  float testeec; // [esp+1Ch] [ebp+8h]
  float testeed; // [esp+1Ch] [ebp+8h]

  z = testee->m_matrix.i.z;
  x = testee->m_matrix.i.x;
  y = testee->m_matrix.i.y;
  v16 = bounding_volume->m_matrix.i.x;
  bounding_volumea = bounding_volume->m_matrix.i.z;
  testeea = bounding_volume->m_matrix.i.y;
  v9 = sqrtf((float)((float)(z * z) + (float)(x * x)) + (float)(y * y));
  v10 = testeea;
  testeeb = v9;
  if ( testeeb <= sqrtf((float)((float)(v10 * v10) + (float)(bounding_volumea * bounding_volumea)) + (float)(v16 * v16)) )
  {
    v17 = testee->m_matrix.i.x;
    bounding_volumeb = testee->m_matrix.i.z;
    v11 = testee->m_matrix.i.y;
    testeec = sqrtf(
                (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                      + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
              + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
    testeed = testeec
            - sqrtf((float)((float)(v11 * v11) + (float)(bounding_volumeb * bounding_volumeb)) + (float)(v17 * v17));
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v13 = this->m_testee->get_matrix(this->m_testee);
    v14 = v13->c.z - p_c->z;
    v15 = v13->c.y - p_c->y;
    this->m_result = (float)(testeed * testeed) >= (float)((float)((float)(v14 * v14) + (float)(v15 * v15))
                                                         + (float)((float)(v13->c.x - p_c->x)
                                                                 * (float)(v13->c.x - p_c->x)));
  }
}

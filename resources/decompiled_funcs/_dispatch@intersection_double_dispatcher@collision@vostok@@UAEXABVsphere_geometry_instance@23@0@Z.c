void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float v4; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
  long double v7; // st7
  float v8; // xmm0_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  float y; // [esp+Ch] [ebp-4h]
  float bounding_volumea; // [esp+14h] [ebp+4h]
  float bounding_volumeb; // [esp+14h] [ebp+4h]
  float bounding_volumec; // [esp+14h] [ebp+4h]
  float testeea; // [esp+18h] [ebp+8h]

  y = bounding_volume->m_matrix.i.y;
  v4 = testee->m_matrix.i.y;
  z = testee->m_matrix.i.z;
  x = testee->m_matrix.i.x;
  testeea = bounding_volume->m_matrix.i.x;
  bounding_volumea = bounding_volume->m_matrix.i.z;
  v7 = sqrtf((float)((float)(v4 * v4) + (float)(z * z)) + (float)(x * x));
  v8 = bounding_volumea;
  bounding_volumeb = v7;
  bounding_volumec = sqrtf((float)((float)(v8 * v8) + (float)(testeea * testeea)) + (float)(y * y)) + bounding_volumeb;
  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v10 = this->m_testee->get_matrix(this->m_testee);
  v11 = v10->c.z - p_c->z;
  v12 = v10->c.y - p_c->y;
  if ( (float)((float)((float)(v11 * v11) + (float)(v12 * v12))
             + (float)((float)(v10->c.x - p_c->x) * (float)(v10->c.x - p_c->x))) <= (float)(bounding_volumec
                                                                                          * bounding_volumec) )
    this->m_result = 1;
}

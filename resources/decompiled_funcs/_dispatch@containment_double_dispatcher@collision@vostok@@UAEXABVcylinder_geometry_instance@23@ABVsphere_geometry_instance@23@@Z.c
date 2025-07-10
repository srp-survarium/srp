void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float v5; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  long double v9; // st7
  float v10; // xmm0_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm0_4
  const vostok::math::float4x4 *v14; // eax
  const vostok::math::float4x4 *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float x; // [esp+14h] [ebp-24h]
  float v21; // [esp+14h] [ebp-24h]
  float v22; // [esp+18h] [ebp-20h]
  float projection_on_axe; // [esp+1Ch] [ebp-1Ch]
  float projection_on_axea; // [esp+1Ch] [ebp-1Ch]
  float v25; // [esp+24h] [ebp-14h]
  float v26; // [esp+28h] [ebp-10h]
  float v27; // [esp+2Ch] [ebp-Ch]
  float bounding_volumea; // [esp+3Ch] [ebp+4h]
  float bounding_volumeb; // [esp+3Ch] [ebp+4h]
  float bounding_volumec; // [esp+3Ch] [ebp+4h]
  float testeea; // [esp+40h] [ebp+8h]
  float testeeb; // [esp+40h] [ebp+8h]
  float testeec; // [esp+40h] [ebp+8h]
  float testeed; // [esp+40h] [ebp+8h]
  float testeee; // [esp+40h] [ebp+8h]

  x = bounding_volume->m_matrix.i.x;
  bounding_volumea = bounding_volume->m_matrix.i.z;
  v5 = testee->m_matrix.i.x;
  y = testee->m_matrix.i.y;
  z = testee->m_matrix.i.z;
  testeea = bounding_volume->m_matrix.i.y;
  v9 = sqrtf((float)((float)(v5 * v5) + (float)(y * y)) + (float)(z * z));
  v10 = testeea;
  testeeb = v9;
  if ( testeeb <= sqrtf((float)((float)(v10 * v10) + (float)(bounding_volumea * bounding_volumea)) + (float)(x * x)) )
  {
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v12 = this->m_testee->get_matrix(this->m_testee);
    v13 = v12->c.x - p_c->x;
    v12 = (const vostok::math::float4x4 *)((char *)v12 + 48);
    v25 = v12->i.y - p_c->y;
    v26 = v12->i.z - p_c->z;
    v14 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v22 = bounding_volume->m_matrix.j.x;
    v21 = bounding_volume->m_matrix.j.z;
    bounding_volumeb = bounding_volume->m_matrix.j.y;
    projection_on_axe = (float)((float)(v14->j.z * v26) + (float)(v14->j.y * v25)) + (float)(v14->j.x * v13);
    testeec = sqrtf(
                (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
            + fabs(projection_on_axe);
    if ( testeec <= sqrtf((float)((float)(bounding_volumeb * bounding_volumeb) + (float)(v21 * v21)) + (float)(v22 * v22)) )
    {
      v15 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      v16 = (float)(v15->j.y * projection_on_axe) - v25;
      v17 = (float)(v15->j.z * projection_on_axe) - v26;
      v18 = (float)(v15->j.x * projection_on_axe) - v13;
      projection_on_axea = testee->m_matrix.i.x;
      bounding_volumec = testee->m_matrix.i.z;
      v27 = v18;
      v19 = testee->m_matrix.i.y;
      testeed = sqrtf(
                  (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                        + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
                + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
      testeee = testeed
              - sqrtf(
                  (float)((float)(v19 * v19) + (float)(bounding_volumec * bounding_volumec))
                + (float)(projection_on_axea * projection_on_axea));
      this->m_result = (float)(testeee * testeee) >= (float)((float)((float)(v17 * v17) + (float)(v16 * v16))
                                                           + (float)(v27 * v27));
    }
  }
}

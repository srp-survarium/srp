void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  const vostok::math::float4x4 *v5; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v7; // eax
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm1_4
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm3_4
  const vostok::math::float4x4 *v14; // eax
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float capsule_origin; // [esp+10h] [ebp-18h]
  float capsule_origin_4; // [esp+14h] [ebp-14h]
  float capsule_origin_8; // [esp+18h] [ebp-10h]
  float closest_point; // [esp+1Ch] [ebp-Ch]
  float closest_point_4a; // [esp+20h] [ebp-8h]
  float closest_point_4; // [esp+20h] [ebp-8h]
  float closest_point_8a; // [esp+24h] [ebp-4h]
  float closest_point_8; // [esp+24h] [ebp-4h]
  float testeea; // [esp+30h] [ebp+8h]
  float testeeb; // [esp+30h] [ebp+8h]
  float testeec; // [esp+30h] [ebp+8h]

  if ( sqrtf(
         (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
               + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
       + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x)) <= bounding_volume->m_radius )
  {
    testeea = bounding_volume->m_half_length;
    v5 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    x = v5->j.x;
    v5 = (const vostok::math::float4x4 *)((char *)v5 + 16);
    closest_point_4a = v5->i.y * testeea;
    closest_point_8a = v5->i.z * testeea;
    v7 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v8 = v7->c.x - (float)(x * testeea);
    v7 = (const vostok::math::float4x4 *)((char *)v7 + 48);
    capsule_origin = v8;
    capsule_origin_4 = v7->i.y - closest_point_4a;
    capsule_origin_8 = v7->i.z - closest_point_8a;
    testeeb = bounding_volume->m_half_length * 2.0;
    v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v10 = v9->j.x;
    v9 = (const vostok::math::float4x4 *)((char *)v9 + 16);
    closest_point = v10 * testeeb;
    closest_point_4 = v9->i.y * testeeb;
    closest_point_8 = v9->i.z * testeeb;
    v11 = this->m_testee->get_matrix(this->m_testee);
    v12 = (float)((float)((float)((float)(v11->c.x - v8) * closest_point)
                        + (float)((float)(v11->c.z - capsule_origin_8) * closest_point_8))
                + (float)((float)(v11->c.y - capsule_origin_4) * closest_point_4))
        / (float)((float)((float)(closest_point * closest_point) + (float)(closest_point_8 * closest_point_8))
                + (float)(closest_point_4 * closest_point_4));
    v13 = 0.0;
    if ( v12 > 0.0 )
    {
      v13 = *(float *)&clear_value;
      if ( *(float *)&clear_value >= v12 )
        v13 = (float)((float)((float)((float)(v11->c.x - capsule_origin) * closest_point)
                            + (float)((float)(v11->c.z - capsule_origin_8) * closest_point_8))
                    + (float)((float)(v11->c.y - capsule_origin_4) * closest_point_4))
            / (float)((float)((float)(closest_point * closest_point) + (float)(closest_point_8 * closest_point_8))
                    + (float)(closest_point_4 * closest_point_4));
    }
    testeec = bounding_volume->m_radius
            - sqrtf(
                (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                      + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
              + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z));
    v14 = this->m_testee->get_matrix(this->m_testee);
    v15 = v14->c.z - (float)((float)(closest_point_8 * v13) + capsule_origin_8);
    v16 = v14->c.y - (float)((float)(closest_point_4 * v13) + capsule_origin_4);
    v17 = v14->c.x - (float)((float)(v13 * closest_point) + capsule_origin);
    if ( (float)((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v17 * v17)) <= (float)(testeec * testeec) )
      this->m_result = 1;
  }
}

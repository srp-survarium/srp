void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v5; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v7; // eax
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  float v11; // xmm1_4
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm0_4
  const vostok::math::float4x4 *v14; // eax
  float capsule_end_point_4; // [esp+14h] [ebp-14h]
  float capsule_end_point_4a; // [esp+14h] [ebp-14h]
  float capsule_end_point_8; // [esp+18h] [ebp-10h]
  float capsule_end_point_8a; // [esp+18h] [ebp-10h]
  float capsule_start_point_4; // [esp+20h] [ebp-8h]
  float capsule_start_point_4a; // [esp+20h] [ebp-8h]
  float capsule_start_point_8; // [esp+24h] [ebp-4h]
  float capsule_start_point_8a; // [esp+24h] [ebp-4h]
  float bounding_volumea; // [esp+2Ch] [ebp+4h]
  float bounding_volumeb; // [esp+2Ch] [ebp+4h]
  float bounding_volumec; // [esp+2Ch] [ebp+4h]
  float bounding_volumed; // [esp+2Ch] [ebp+4h]

  if ( testee->m_radius <= sqrtf(
                             (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                                   + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
                           + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x)) )
  {
    bounding_volumea = testee->m_half_length;
    v5 = this->m_testee->get_matrix(this->m_testee);
    x = v5->j.x;
    v5 = (const vostok::math::float4x4 *)((char *)v5 + 16);
    capsule_end_point_4 = v5->i.y * bounding_volumea;
    capsule_end_point_8 = v5->i.z * bounding_volumea;
    v7 = this->m_testee->get_matrix(this->m_testee);
    v8 = v7->c.x - (float)(x * bounding_volumea);
    v7 = (const vostok::math::float4x4 *)((char *)v7 + 48);
    capsule_start_point_4 = v7->i.y - capsule_end_point_4;
    capsule_start_point_8 = v7->i.z - capsule_end_point_8;
    bounding_volumeb = sqrtf(
                         (float)((float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x)
                               + (float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y))
                       + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
                     - testee->m_radius;
    v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)((float)((float)((float)(v8 - v9->c.x) * (float)(v8 - v9->c.x))
                       + (float)((float)(capsule_start_point_8 - v9->c.z) * (float)(capsule_start_point_8 - v9->c.z)))
               + (float)((float)(capsule_start_point_4 - v9->c.y) * (float)(capsule_start_point_4 - v9->c.y))) <= (float)(bounding_volumeb * bounding_volumeb) )
    {
      bounding_volumec = testee->m_half_length;
      v10 = this->m_testee->get_matrix(this->m_testee);
      v11 = v10->j.x;
      v10 = (const vostok::math::float4x4 *)((char *)v10 + 16);
      capsule_start_point_4a = v10->i.y * bounding_volumec;
      capsule_start_point_8a = v10->i.z * bounding_volumec;
      v12 = this->m_testee->get_matrix(this->m_testee);
      v13 = (float)(v11 * bounding_volumec) + v12->c.x;
      v12 = (const vostok::math::float4x4 *)((char *)v12 + 48);
      capsule_end_point_4a = v12->i.y + capsule_start_point_4a;
      capsule_end_point_8a = v12->i.z + capsule_start_point_8a;
      bounding_volumed = sqrtf(
                           (float)((float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x)
                                 + (float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y))
                         + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
                       - testee->m_radius;
      v14 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      if ( (float)((float)((float)((float)(capsule_end_point_8a - v14->c.z) * (float)(capsule_end_point_8a - v14->c.z))
                         + (float)((float)(capsule_end_point_4a - v14->c.y) * (float)(capsule_end_point_4a - v14->c.y)))
                 + (float)((float)(v13 - v14->c.x) * (float)(v13 - v14->c.x))) <= (float)(bounding_volumed
                                                                                        * bounding_volumed) )
        this->m_result = 1;
    }
  }
}

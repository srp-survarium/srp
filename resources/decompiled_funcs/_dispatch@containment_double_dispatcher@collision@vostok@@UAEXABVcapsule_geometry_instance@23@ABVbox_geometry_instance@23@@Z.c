void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // esi
  long double v5; // st7
  const vostok::collision::geometry_instance *m_bounding_volume; // ecx
  float m_radius; // xmm0_4
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  float *v9; // eax
  float v10; // xmm1_4
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  const vostok::math::float4x4 *v13; // eax
  float v14; // xmm6_4
  float *p_y; // ecx
  unsigned int v16; // eax
  float v17; // xmm7_4
  float v18; // xmm5_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float m_half_length; // [esp+14h] [ebp-60h]
  float v25; // [esp+14h] [ebp-60h]
  float v26; // [esp+14h] [ebp-60h]
  float squared_capsule_radius; // [esp+18h] [ebp-5Ch]
  float capsule_origin; // [esp+1Ch] [ebp-58h]
  float capsule_origin_4; // [esp+20h] [ebp-54h]
  float capsule_origin_8; // [esp+24h] [ebp-50h]
  float capsule_displacement; // [esp+28h] [ebp-4Ch]
  float capsule_displacement_4a; // [esp+2Ch] [ebp-48h]
  float capsule_displacement_4b; // [esp+2Ch] [ebp-48h]
  float capsule_displacement_4; // [esp+2Ch] [ebp-48h]
  float capsule_displacement_8a; // [esp+30h] [ebp-44h]
  float capsule_displacement_8; // [esp+30h] [ebp-44h]
  vostok::math::float4x4 matrix; // [esp+34h] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v4 = testee->get_matrix(testee);
  capsule_displacement = sqrtf((float)((float)(v4->i.z * v4->i.z) + (float)(v4->i.x * v4->i.x)) + (float)(v4->i.y * v4->i.y));
  capsule_displacement_4a = sqrtf(
                              (float)((float)(v4->j.y * v4->j.y) + (float)(v4->j.z * v4->j.z))
                            + (float)(v4->j.x * v4->j.x));
  v5 = sqrtf((float)((float)(v4->k.y * v4->k.y) + (float)(v4->k.z * v4->k.z)) + (float)(v4->k.x * v4->k.x));
  matrix.i.x = capsule_displacement * matrix.i.x;
  matrix.j.x = matrix.j.x * capsule_displacement_4a;
  matrix.i.y = matrix.i.y * capsule_displacement;
  matrix.j.y = capsule_displacement_4a * matrix.j.y;
  matrix.i.z = matrix.i.z * capsule_displacement;
  matrix.j.z = matrix.j.z * capsule_displacement_4a;
  matrix.k.x = matrix.k.x * v5;
  m_bounding_volume = this->m_bounding_volume;
  m_radius = bounding_volume->m_radius;
  get_matrix = m_bounding_volume->get_matrix;
  matrix.k.y = matrix.k.y * v5;
  squared_capsule_radius = m_radius * m_radius;
  m_half_length = bounding_volume->m_half_length;
  matrix.k.z = v5 * matrix.k.z;
  v9 = (float *)get_matrix((vostok::collision::geometry_instance *)m_bounding_volume);
  v10 = v9[4];
  v9 += 4;
  capsule_displacement_4b = v9[1] * m_half_length;
  capsule_displacement_8a = v9[2] * m_half_length;
  v11 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v12 = v11->c.x - (float)(v10 * m_half_length);
  v11 = (const vostok::math::float4x4 *)((char *)v11 + 48);
  capsule_origin = v12;
  capsule_origin_4 = v11->i.y - capsule_displacement_4b;
  capsule_origin_8 = v11->i.z - capsule_displacement_8a;
  v25 = bounding_volume->m_half_length * 2.0;
  v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v14 = v13->j.x * v25;
  capsule_displacement_8 = v13->j.z * v25;
  capsule_displacement_4 = v13->j.y * v25;
  v26 = (float)((float)(v14 * v14) + (float)(capsule_displacement_8 * capsule_displacement_8))
      + (float)(capsule_displacement_4 * capsule_displacement_4);
  p_y = &cuboid_vertices[0].y;
  v16 = 0;
  while ( 1 )
  {
    v17 = 0.0;
    v18 = p_y[1];
    v19 = (float)((float)((float)(v18 * matrix.k.x) + (float)(*(p_y - 1) * matrix.i.x)) + (float)(*p_y * matrix.j.x))
        + matrix.c.x;
    v20 = *(p_y - 1);
    v21 = (float)((float)((float)(v20 * matrix.i.z) + (float)(v18 * matrix.k.z)) + (float)(matrix.j.z * *p_y))
        + matrix.c.z;
    v22 = (float)((float)((float)(v20 * matrix.i.y) + (float)(v18 * matrix.k.y)) + (float)(matrix.j.y * *p_y))
        + matrix.c.y;
    v23 = (float)((float)((float)((float)(v19 - capsule_origin) * v14)
                        + (float)((float)(v21 - capsule_origin_8) * capsule_displacement_8))
                + (float)((float)(v22 - capsule_origin_4) * capsule_displacement_4))
        / v26;
    if ( v23 > 0.0 )
    {
      v17 = *(float *)&clear_value;
      if ( *(float *)&clear_value >= v23 )
        v17 = (float)((float)((float)((float)(v19 - capsule_origin) * v14)
                            + (float)((float)(v21 - capsule_origin_8) * capsule_displacement_8))
                    + (float)((float)(v22 - capsule_origin_4) * capsule_displacement_4))
            / v26;
    }
    if ( squared_capsule_radius < (float)((float)((float)((float)(v21
                                                                - (float)((float)(capsule_displacement_8 * v17)
                                                                        + capsule_origin_8))
                                                        * (float)(v21
                                                                - (float)((float)(capsule_displacement_8 * v17)
                                                                        + capsule_origin_8)))
                                                + (float)((float)(v22
                                                                - (float)((float)(capsule_displacement_4 * v17)
                                                                        + capsule_origin_4))
                                                        * (float)(v22
                                                                - (float)((float)(capsule_displacement_4 * v17)
                                                                        + capsule_origin_4))))
                                        + (float)((float)(v19 - (float)((float)(v17 * v14) + capsule_origin))
                                                * (float)(v19 - (float)((float)(v17 * v14) + capsule_origin)))) )
      break;
    v16 += 12;
    p_y += 3;
    if ( v16 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
  }
}

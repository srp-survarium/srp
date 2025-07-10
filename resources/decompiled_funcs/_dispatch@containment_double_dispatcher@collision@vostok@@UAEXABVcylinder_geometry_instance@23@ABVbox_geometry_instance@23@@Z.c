void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // esi
  long double v5; // st7
  float z; // xmm1_4
  float x; // xmm0_4
  float y; // xmm3_4
  long double v9; // st7
  float *p_y; // edi
  float v11; // xmm0_4
  float v12; // xmm4_4
  const vostok::math::float4x4 *v13; // ecx
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  unsigned int v18; // [esp+14h] [ebp-60h]
  float v19; // [esp+20h] [ebp-54h]
  float squared_cylinder_radius; // [esp+24h] [ebp-50h]
  float v21; // [esp+28h] [ebp-4Ch]
  float v22; // [esp+28h] [ebp-4Ch]
  float v23; // [esp+2Ch] [ebp-48h]
  float v24; // [esp+2Ch] [ebp-48h]
  float v25; // [esp+30h] [ebp-44h]
  vostok::math::float4x4 matrix; // [esp+34h] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v4 = testee->get_matrix(testee);
  v21 = sqrtf((float)((float)(v4->i.y * v4->i.y) + (float)(v4->i.z * v4->i.z)) + (float)(v4->i.x * v4->i.x));
  v23 = sqrtf((float)((float)(v4->j.y * v4->j.y) + (float)(v4->j.z * v4->j.z)) + (float)(v4->j.x * v4->j.x));
  v5 = sqrtf((float)((float)(v4->k.y * v4->k.y) + (float)(v4->k.z * v4->k.z)) + (float)(v4->k.x * v4->k.x));
  matrix.i.x = v21 * matrix.i.x;
  matrix.j.x = matrix.j.x * v23;
  matrix.i.y = matrix.i.y * v21;
  matrix.j.y = v23 * matrix.j.y;
  matrix.i.z = matrix.i.z * v21;
  matrix.j.z = matrix.j.z * v23;
  matrix.k.x = matrix.k.x * v5;
  z = bounding_volume->m_matrix.i.z;
  x = bounding_volume->m_matrix.i.x;
  y = bounding_volume->m_matrix.i.y;
  matrix.k.y = matrix.k.y * v5;
  matrix.k.z = v5 * matrix.k.z;
  v9 = sqrtf((float)((float)(y * y) + (float)(z * z)) + (float)(x * x));
  p_y = &cuboid_vertices[0].y;
  squared_cylinder_radius = v9 * v9;
  v18 = 0;
  while ( 1 )
  {
    v11 = p_y[1];
    v22 = (float)((float)((float)(v11 * matrix.k.x) + (float)(*(p_y - 1) * matrix.i.x)) + (float)(*p_y * matrix.j.x))
        + matrix.c.x;
    v12 = *(p_y - 1);
    v24 = (float)((float)((float)(v11 * matrix.k.y) + (float)(*p_y * matrix.j.y)) + (float)(v12 * matrix.i.y))
        + matrix.c.y;
    v25 = (float)((float)((float)(v11 * matrix.k.z) + (float)(v12 * matrix.i.z)) + (float)(*p_y * matrix.j.z))
        + matrix.c.z;
    v19 = sqrtf(
            (float)((float)(bounding_volume->m_matrix.j.y * bounding_volume->m_matrix.j.y)
                  + (float)(bounding_volume->m_matrix.j.z * bounding_volume->m_matrix.j.z))
          + (float)(bounding_volume->m_matrix.j.x * bounding_volume->m_matrix.j.x));
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v14 = v22 - v13->c.x;
    v15 = v24 - v13->c.y;
    v16 = v25 - v13->c.z;
    if ( fabs((float)((float)(v13->j.z * v16) + (float)(v13->j.y * v15)) + (float)(v13->j.x * v14)) > (double)v19 )
      break;
    v17 = (float)((float)(v13->j.z * v16) + (float)(v13->j.y * v15)) + (float)(v13->j.x * v14);
    if ( squared_cylinder_radius < (float)((float)((float)((float)((float)(v13->j.z * v17) - v16)
                                                         * (float)((float)(v13->j.z * v17) - v16))
                                                 + (float)((float)((float)(v13->j.y * v17) - v15)
                                                         * (float)((float)(v13->j.y * v17) - v15)))
                                         + (float)((float)((float)(v13->j.x * v17) - v14)
                                                 * (float)((float)(v13->j.x * v17) - v14))) )
      break;
    p_y += 3;
    v18 += 12;
    if ( v18 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
  }
}

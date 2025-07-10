void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // esi
  long double v5; // st7
  float z; // xmm1_4
  float x; // xmm0_4
  float y; // xmm3_4
  long double v9; // st7
  float *p_y; // esi
  unsigned int v11; // edi
  float v12; // xmm1_4
  float v13; // xmm3_4
  const vostok::math::float4x4 *v14; // eax
  float squared_sphere_radius; // [esp+14h] [ebp-50h]
  float v16; // [esp+18h] [ebp-4Ch]
  float v17; // [esp+18h] [ebp-4Ch]
  float v18; // [esp+1Ch] [ebp-48h]
  float v19; // [esp+1Ch] [ebp-48h]
  float v20; // [esp+20h] [ebp-44h]
  vostok::math::float4x4 matrix; // [esp+24h] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v4 = testee->get_matrix(testee);
  v16 = sqrtf((float)((float)(v4->i.y * v4->i.y) + (float)(v4->i.z * v4->i.z)) + (float)(v4->i.x * v4->i.x));
  v18 = sqrtf((float)((float)(v4->j.y * v4->j.y) + (float)(v4->j.z * v4->j.z)) + (float)(v4->j.x * v4->j.x));
  v5 = sqrtf((float)((float)(v4->k.x * v4->k.x) + (float)(v4->k.y * v4->k.y)) + (float)(v4->k.z * v4->k.z));
  matrix.i.x = v16 * matrix.i.x;
  matrix.j.x = matrix.j.x * v18;
  matrix.i.y = matrix.i.y * v16;
  matrix.j.y = v18 * matrix.j.y;
  matrix.i.z = matrix.i.z * v16;
  matrix.j.z = matrix.j.z * v18;
  matrix.k.x = matrix.k.x * v5;
  z = bounding_volume->m_matrix.i.z;
  x = bounding_volume->m_matrix.i.x;
  y = bounding_volume->m_matrix.i.y;
  matrix.k.y = matrix.k.y * v5;
  matrix.k.z = v5 * matrix.k.z;
  v9 = sqrtf((float)((float)(y * y) + (float)(z * z)) + (float)(x * x));
  p_y = &cuboid_vertices[0].y;
  v11 = 0;
  while ( 1 )
  {
    v12 = p_y[1];
    v13 = *(p_y - 1);
    v17 = (float)((float)((float)(matrix.i.x * v13) + (float)(matrix.k.x * v12)) + (float)(matrix.j.x * *p_y))
        + matrix.c.x;
    v19 = (float)((float)((float)(matrix.k.y * v12) + (float)(matrix.i.y * v13)) + (float)(matrix.j.y * *p_y))
        + matrix.c.y;
    v20 = (float)((float)((float)(matrix.i.z * v13) + (float)(matrix.k.z * v12)) + (float)(matrix.j.z * *p_y))
        + matrix.c.z;
    v14 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    squared_sphere_radius = v9 * v9;
    if ( squared_sphere_radius < (float)((float)((float)((float)(v20 - v14->c.z) * (float)(v20 - v14->c.z))
                                               + (float)((float)(v19 - v14->c.y) * (float)(v19 - v14->c.y)))
                                       + (float)((float)(v17 - v14->c.x) * (float)(v17 - v14->c.x))) )
      break;
    v11 += 12;
    p_y += 3;
    if ( v11 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
  }
}

void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v3; // esi
  long double v4; // st7
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float *p_y; // edi
  float v9; // xmm3_4
  float v10; // xmm1_4
  const vostok::math::float4x4 *v11; // esi
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  unsigned int v16; // [esp+14h] [ebp-78h]
  float v18; // [esp+34h] [ebp-58h]
  float v19; // [esp+38h] [ebp-54h]
  float v20; // [esp+3Ch] [ebp-50h]
  float v21; // [esp+40h] [ebp-4Ch]
  float v22; // [esp+40h] [ebp-4Ch]
  float v23; // [esp+44h] [ebp-48h]
  float v24; // [esp+44h] [ebp-48h]
  float v25; // [esp+48h] [ebp-44h]
  vostok::math::float4x4 matrix; // [esp+4Ch] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v3 = testee->get_matrix(testee);
  v21 = sqrtf((float)((float)(v3->i.y * v3->i.y) + (float)(v3->i.z * v3->i.z)) + (float)(v3->i.x * v3->i.x));
  v23 = sqrtf((float)((float)(v3->j.y * v3->j.y) + (float)(v3->j.z * v3->j.z)) + (float)(v3->j.x * v3->j.x));
  v4 = sqrtf((float)((float)(v3->k.y * v3->k.y) + (float)(v3->k.z * v3->k.z)) + (float)(v3->k.x * v3->k.x));
  x = v21 * matrix.i.x;
  matrix.j.x = matrix.j.x * v23;
  y = matrix.i.y * v21;
  z = matrix.i.z * v21;
  matrix.j.y = v23 * matrix.j.y;
  matrix.i.x = v21 * matrix.i.x;
  matrix.i.y = matrix.i.y * v21;
  matrix.i.z = matrix.i.z * v21;
  matrix.j.z = matrix.j.z * v23;
  matrix.k.x = matrix.k.x * v4;
  p_y = &cuboid_vertices[0].y;
  v16 = 0;
  matrix.k.y = matrix.k.y * v4;
  matrix.k.z = v4 * matrix.k.z;
  while ( 1 )
  {
    v9 = *(p_y - 1);
    v10 = p_y[1];
    v18 = (float)((float)((float)(v10 * matrix.k.x) + (float)(v9 * x)) + (float)(*p_y * matrix.j.x)) + matrix.c.x;
    v19 = (float)((float)((float)(y * v9) + (float)(matrix.k.y * v10)) + (float)(matrix.j.y * *p_y)) + matrix.c.y;
    v20 = (float)((float)((float)(z * v9) + (float)(matrix.k.z * v10)) + (float)(matrix.j.z * *p_y)) + matrix.c.z;
    v11 = bounding_volume->get_matrix(bounding_volume);
    v22 = sqrtf((float)((float)(v11->i.x * v11->i.x) + (float)(v11->i.y * v11->i.y)) + (float)(v11->i.z * v11->i.z));
    v24 = sqrtf((float)((float)(v11->j.x * v11->j.x) + (float)(v11->j.y * v11->j.y)) + (float)(v11->j.z * v11->j.z));
    v25 = sqrtf((float)((float)(v11->k.y * v11->k.y) + (float)(v11->k.z * v11->k.z)) + (float)(v11->k.x * v11->k.x));
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v13 = v19 - v12->c.y;
    v14 = v20 - v12->c.z;
    v15 = v18 - v12->c.x;
    if ( fabs((float)((float)(v12->i.z * v14) + (float)(v12->i.y * v13)) + (float)(v12->i.x * v15)) > v22
      || fabs((float)((float)(v12->j.z * v14) + (float)(v12->j.y * v13)) + (float)(v12->j.x * v15)) > v24
      || fabs((float)((float)(v12->k.z * v14) + (float)(v12->k.y * v13)) + (float)(v12->k.x * v15)) > v25 )
    {
      break;
    }
    p_y += 3;
    v16 += 12;
    if ( v16 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
    z = matrix.i.z;
    y = matrix.i.y;
    x = matrix.i.x;
  }
}

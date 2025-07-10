void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // ebx
  vostok::math::float4_pod *v5; // edi
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm0_4
  const vostok::math::float4x4 *v8; // eax
  float y; // xmm4_4
  float z; // xmm2_4
  float x; // xmm5_4
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  long double v18; // st7
  const vostok::math::float4x4 *v20; // eax
  const vostok::math::float4x4 *v21; // eax
  const vostok::math::float4x4 *v22; // eax
  float v23; // [esp+10h] [ebp-28h]
  __int64 far_cylinder_edge_center; // [esp+14h] [ebp-24h]
  float far_cylinder_edge_center_4; // [esp+18h] [ebp-20h]
  float far_cylinder_edge_center_8b; // [esp+1Ch] [ebp-1Ch]
  float far_cylinder_edge_center_8; // [esp+1Ch] [ebp-1Ch]
  float far_cylinder_edge_center_8a; // [esp+1Ch] [ebp-1Ch]
  float cross_product; // [esp+20h] [ebp-18h]
  float cross_producta; // [esp+20h] [ebp-18h]
  float cross_product_4; // [esp+24h] [ebp-14h]
  float cross_product_4a; // [esp+24h] [ebp-14h]
  float cross_product_8; // [esp+28h] [ebp-10h]
  float cross_product_8a; // [esp+28h] [ebp-10h]
  float testeea; // [esp+40h] [ebp+8h]
  float testeeb; // [esp+40h] [ebp+8h]
  float testeec; // [esp+40h] [ebp+8h]
  float testeed; // [esp+40h] [ebp+8h]

  p_c = &this->m_testee->get_matrix(this->m_testee)->c;
  v5 = &this->m_testee->get_matrix(this->m_testee)->c;
  v6 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v7 = v6->c.x - v5->x;
  v6 = (const vostok::math::float4x4 *)((char *)v6 + 48);
  far_cylinder_edge_center_4 = v6->i.y - v5->y;
  far_cylinder_edge_center_8b = v6->i.z - v5->z;
  v8 = this->m_testee->get_matrix(this->m_testee);
  y = v8->j.y;
  z = v8->j.z;
  x = v8->j.x;
  cross_product_8 = (float)(far_cylinder_edge_center_4 * x) - (float)(y * v7);
  cross_product = (float)(far_cylinder_edge_center_8b * y) - (float)(far_cylinder_edge_center_4 * z);
  cross_product_4 = (float)(z * v7) - (float)(far_cylinder_edge_center_8b * x);
  v12 = this->m_testee->get_matrix(this->m_testee);
  if ( (float)((float)(cross_product_8 + cross_product_4) + cross_product) == 0.0 )
  {
    far_cylinder_edge_center = *(_QWORD *)&v12->i.x;
    far_cylinder_edge_center_8 = v12->i.z;
  }
  else
  {
    v13 = v12->j.z;
    v14 = (float)(v12->j.y * cross_product_8) - (float)(v13 * cross_product_4);
    v15 = v12->j.x;
    v16 = (float)(v15 * cross_product_4) - (float)(v12->j.y * cross_product);
    v17 = (float)(v13 * cross_product) - (float)(v15 * cross_product_8);
    v18 = 1.0 / sqrtf((float)((float)(v16 * v16) + (float)(v17 * v17)) + (float)(v14 * v14));
    v23 = v18;
    *(float *)&far_cylinder_edge_center = v23 * v14;
    *((float *)&far_cylinder_edge_center + 1) = v17 * v18;
    far_cylinder_edge_center_8 = v18 * v16;
  }
  testeea = sqrtf(
              (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
                    + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
            + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z));
  *(float *)&far_cylinder_edge_center = p_c->x + (float)(*(float *)&far_cylinder_edge_center * testeea);
  *((float *)&far_cylinder_edge_center + 1) = p_c->y + (float)(*((float *)&far_cylinder_edge_center + 1) * testeea);
  far_cylinder_edge_center_8a = p_c->z + (float)(far_cylinder_edge_center_8 * testeea);
  testeeb = sqrtf(
              (float)((float)(testee->m_matrix.j.x * testee->m_matrix.j.x)
                    + (float)(testee->m_matrix.j.y * testee->m_matrix.j.y))
            + (float)(testee->m_matrix.j.z * testee->m_matrix.j.z));
  v20 = this->m_testee->get_matrix(this->m_testee);
  cross_product_8a = v20->j.z * testeeb;
  cross_product_4a = v20->j.y * testeeb;
  cross_producta = v20->j.x * testeeb;
  testeec = sqrtf(
              (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                    + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
            + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
  v21 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  if ( (float)((float)((float)((float)((float)(cross_producta + *(float *)&far_cylinder_edge_center) - v21->c.x)
                             * (float)((float)(cross_producta + *(float *)&far_cylinder_edge_center) - v21->c.x))
                     + (float)((float)((float)(cross_product_8a + far_cylinder_edge_center_8a) - v21->c.z)
                             * (float)((float)(cross_product_8a + far_cylinder_edge_center_8a) - v21->c.z)))
             + (float)((float)((float)(cross_product_4a + *((float *)&far_cylinder_edge_center + 1)) - v21->c.y)
                     * (float)((float)(cross_product_4a + *((float *)&far_cylinder_edge_center + 1)) - v21->c.y))) <= (float)(testeec * testeec) )
  {
    testeed = sqrtf(
                (float)((float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z)
                      + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x))
              + (float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y));
    v22 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)((float)((float)((float)((float)(*(float *)&far_cylinder_edge_center - cross_producta) - v22->c.x)
                               * (float)((float)(*(float *)&far_cylinder_edge_center - cross_producta) - v22->c.x))
                       + (float)((float)((float)(far_cylinder_edge_center_8a - cross_product_8a) - v22->c.z)
                               * (float)((float)(far_cylinder_edge_center_8a - cross_product_8a) - v22->c.z)))
               + (float)((float)((float)(*((float *)&far_cylinder_edge_center + 1) - cross_product_4a) - v22->c.y)
                       * (float)((float)(*((float *)&far_cylinder_edge_center + 1) - cross_product_4a) - v22->c.y))) <= (float)(testeed * testeed) )
      this->m_result = 1;
  }
}

void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm0_4
  float z; // xmm2_4
  float x; // xmm1_4
  const vostok::math::float4x4 *v10; // eax
  double v11; // st7
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  float *v13; // esi
  vostok::math::float4_pod *v14; // edi
  const vostok::math::float3 *v15; // esi
  const vostok::math::float3 *v16; // eax
  vostok::math::float4_pod *v17; // edi
  vostok::math::float4_pod *p_k; // esi
  const vostok::math::float3 *v19; // eax
  vostok::math::float4_pod *v20; // edi
  vostok::math::float4_pod *p_j; // esi
  vostok::math::float4_pod *v22; // ebp
  const vostok::math::float3 *v23; // eax
  vostok::math::float3 *test_cylinder_up_axis; // [esp+18h] [ebp-28h]
  vostok::math::float3 *test_cylinder_up_axisa; // [esp+18h] [ebp-28h]
  float v26; // [esp+1Ch] [ebp-24h]
  float v27; // [esp+20h] [ebp-20h]
  float v28; // [esp+24h] [ebp-1Ch]
  vostok::math::float3 center_to_cup_vector; // [esp+28h] [ebp-18h] BYREF
  vostok::math::float3 test_cylinder_relative_position; // [esp+34h] [ebp-Ch] BYREF
  const vostok::math::float3 *bounding_volumea; // [esp+44h] [ebp+4h]
  const vostok::math::float3 *bounding_volumeb; // [esp+44h] [ebp+4h]
  const vostok::math::float3 *bounding_volumec; // [esp+44h] [ebp+4h]
  float testeea; // [esp+48h] [ebp+8h]
  float testeeb; // [esp+48h] [ebp+8h]
  float testeec; // [esp+48h] [ebp+8h]
  float testeed; // [esp+48h] [ebp+8h]

  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v5 = this->m_testee->get_matrix(this->m_testee);
  v6 = v5->c.x - p_c->x;
  z = testee->m_matrix.j.z;
  x = testee->m_matrix.j.x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 48);
  test_cylinder_relative_position.x = v6;
  test_cylinder_relative_position.y = v5->i.y - p_c->y;
  test_cylinder_relative_position.z = v5->i.z - p_c->z;
  testeea = sqrtf((float)((float)(z * z) + (float)(x * x)) + (float)(testee->m_matrix.j.y * testee->m_matrix.j.y));
  v10 = this->m_testee->get_matrix(this->m_testee);
  v11 = v10->j.x;
  v10 = (const vostok::math::float4x4 *)((char *)v10 + 16);
  center_to_cup_vector.x = v11 * testeea;
  center_to_cup_vector.y = v10->i.y * testeea;
  get_matrix = bounding_volume->get_matrix;
  center_to_cup_vector.z = testeea * v10->i.z;
  v13 = (float *)get_matrix(&bounding_volume->vostok::collision::geometry_instance);
  v26 = sqrtf((float)((float)(*v13 * *v13) + (float)(v13[1] * v13[1])) + (float)(v13[2] * v13[2]));
  v27 = sqrtf((float)((float)(v13[5] * v13[5]) + (float)(v13[6] * v13[6])) + (float)(v13[4] * v13[4]));
  v28 = sqrtf((float)((float)(v13[9] * v13[9]) + (float)(v13[10] * v13[10])) + (float)(v13[8] * v13[8]));
  v14 = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v15 = (const vostok::math::float3 *)this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  testeeb = sqrtf(
              (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                    + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
            + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
  bounding_volumea = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
  test_cylinder_up_axis = (vostok::math::float3 *)&this->m_testee->get_matrix(this->m_testee)->lines[1];
  v16 = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
  if ( vostok::collision::is_inside_range(
         test_cylinder_up_axis,
         bounding_volumea,
         v15,
         (const vostok::math::float3 *)v14,
         &test_cylinder_relative_position,
         v16 + 4,
         &center_to_cup_vector,
         testeeb,
         v26) )
  {
    v17 = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    p_k = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->k;
    testeec = sqrtf(
                (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
    bounding_volumeb = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
    test_cylinder_up_axisa = (vostok::math::float3 *)&this->m_testee->get_matrix(this->m_testee)->lines[1];
    v19 = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
    if ( vostok::collision::is_inside_range(
           test_cylinder_up_axisa,
           bounding_volumeb,
           (const vostok::math::float3 *)p_k,
           (const vostok::math::float3 *)v17,
           &test_cylinder_relative_position,
           v19 + 4,
           &center_to_cup_vector,
           testeec,
           v28) )
    {
      v20 = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
      p_j = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->j;
      testeed = sqrtf(
                  (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                        + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
                + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
      bounding_volumec = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
      v22 = &this->m_testee->get_matrix(this->m_testee)->j;
      v23 = (const vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
      if ( vostok::collision::is_inside_range(
             (const vostok::math::float3 *)v22,
             bounding_volumec,
             (const vostok::math::float3 *)p_j,
             (const vostok::math::float3 *)v20,
             &test_cylinder_relative_position,
             v23 + 4,
             &center_to_cup_vector,
             testeed,
             v27) )
      {
        this->m_result = 1;
      }
    }
  }
}

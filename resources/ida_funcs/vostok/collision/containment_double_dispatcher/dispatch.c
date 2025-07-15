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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v5; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v7; // eax
  float v8; // xmm0_4
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // edi
  const vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  const vostok::math::float4x4 *v14; // eax
  const vostok::math::float4x4 *v15; // eax
  float v16; // xmm1_4
  const vostok::math::float4x4 *v17; // eax
  float v18; // xmm0_4
  const vostok::math::float4x4 *v19; // eax
  float v20; // xmm0_4
  const vostok::math::float4x4 *v21; // eax
  const vostok::math::float4x4 *v22; // eax
  const vostok::math::float4x4 *v23; // eax
  float center_to_point_center_4; // [esp+1Ch] [ebp-2Ch]
  float center_to_point_center_4a; // [esp+1Ch] [ebp-2Ch]
  float center_to_point_center_8; // [esp+20h] [ebp-28h]
  float center_to_point_center_8a; // [esp+20h] [ebp-28h]
  float v28; // [esp+24h] [ebp-24h]
  float v29; // [esp+28h] [ebp-20h]
  float v30; // [esp+28h] [ebp-20h]
  float v31; // [esp+2Ch] [ebp-1Ch]
  float v32; // [esp+2Ch] [ebp-1Ch]
  float capsule_start_point_4; // [esp+34h] [ebp-14h]
  float capsule_start_point_4a; // [esp+34h] [ebp-14h]
  float capsule_start_point_8; // [esp+38h] [ebp-10h]
  float capsule_start_point_8a; // [esp+38h] [ebp-10h]
  float capsule_end_point_4; // [esp+40h] [ebp-8h]
  float capsule_end_point_8; // [esp+44h] [ebp-4h]
  float testee_radiusa; // [esp+50h] [ebp+8h]
  float testee_radius; // [esp+50h] [ebp+8h]
  float testee_radiusb; // [esp+50h] [ebp+8h]

  testee_radiusa = testee->m_half_length;
  v5 = this->m_testee->get_matrix(this->m_testee);
  x = v5->j.x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 16);
  v29 = v5->i.y * testee_radiusa;
  v31 = v5->i.z * testee_radiusa;
  v7 = this->m_testee->get_matrix(this->m_testee);
  v8 = v7->c.x - (float)(x * testee_radiusa);
  v7 = (const vostok::math::float4x4 *)((char *)v7 + 48);
  capsule_start_point_4 = v7->i.y - v29;
  capsule_start_point_8 = v7->i.z - v31;
  v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v10 = v8 - v9->c.x;
  v9 = (const vostok::math::float4x4 *)((char *)v9 + 48);
  center_to_point_center_4 = capsule_start_point_4 - v9->i.y;
  center_to_point_center_8 = capsule_start_point_8 - v9->i.z;
  v11 = bounding_volume->get_matrix(bounding_volume);
  v28 = sqrtf((float)((float)(v11->i.x * v11->i.x) + (float)(v11->i.y * v11->i.y)) + (float)(v11->i.z * v11->i.z));
  v30 = sqrtf((float)((float)(v11->j.z * v11->j.z) + (float)(v11->j.x * v11->j.x)) + (float)(v11->j.y * v11->j.y));
  v32 = sqrtf((float)((float)(v11->k.y * v11->k.y) + (float)(v11->k.z * v11->k.z)) + (float)(v11->k.x * v11->k.x));
  testee_radius = testee->m_radius;
  v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  if ( (float)(fabs(
                 (float)((float)(v12->i.z * center_to_point_center_8) + (float)(v12->i.y * center_to_point_center_4))
               + (float)(v12->i.x * v10))
             + testee_radius) <= v28 )
  {
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)(fabs(
                   (float)((float)(v13->j.z * center_to_point_center_8) + (float)(v13->j.y * center_to_point_center_4))
                 + (float)(v13->j.x * v10))
               + testee_radius) <= v30 )
    {
      v14 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      if ( (float)(fabs(
                     (float)((float)(v14->k.z * center_to_point_center_8) + (float)(v14->k.y * center_to_point_center_4))
                   + (float)(v14->k.x * v10))
                 + testee_radius) <= v32 )
      {
        testee_radiusb = testee->m_half_length;
        v15 = this->m_testee->get_matrix(this->m_testee);
        v16 = v15->j.x;
        v15 = (const vostok::math::float4x4 *)((char *)v15 + 16);
        capsule_start_point_4a = v15->i.y * testee_radiusb;
        capsule_start_point_8a = v15->i.z * testee_radiusb;
        v17 = this->m_testee->get_matrix(this->m_testee);
        v18 = v17->c.x + (float)(v16 * testee_radiusb);
        v17 = (const vostok::math::float4x4 *)((char *)v17 + 48);
        capsule_end_point_4 = v17->i.y + capsule_start_point_4a;
        capsule_end_point_8 = v17->i.z + capsule_start_point_8a;
        v19 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
        v20 = v18 - v19->c.x;
        v19 = (const vostok::math::float4x4 *)((char *)v19 + 48);
        center_to_point_center_4a = capsule_end_point_4 - v19->i.y;
        center_to_point_center_8a = capsule_end_point_8 - v19->i.z;
        v21 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
        if ( (float)(testee->m_radius
                   + fabs(
                       (float)((float)(v21->i.z * center_to_point_center_8a)
                             + (float)(v21->i.y * center_to_point_center_4a))
                     + (float)(v21->i.x * v20))) <= v28 )
        {
          v22 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
          if ( (float)(testee->m_radius
                     + fabs(
                         (float)((float)(v22->j.z * center_to_point_center_8a)
                               + (float)(v22->j.y * center_to_point_center_4a))
                       + (float)(v20 * v22->j.x))) <= v30 )
          {
            v23 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
            if ( (float)(testee->m_radius
                       + fabs(
                           (float)((float)(v23->k.z * center_to_point_center_8a)
                                 + (float)(v23->k.y * center_to_point_center_4a))
                         + (float)(v20 * v23->k.x))) <= v32 )
              this->m_result = 1;
          }
        }
      }
    }
  }
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // eax
  const vostok::math::float4x4 *v8; // esi
  const vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  float projection_on_x; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+14h] [ebp-14h]
  float v13; // [esp+18h] [ebp-10h]
  float v14; // [esp+1Ch] [ebp-Ch]
  float v15; // [esp+20h] [ebp-8h]
  float v16; // [esp+24h] [ebp-4h]
  float projection_on_z; // [esp+2Ch] [ebp+4h]
  float projection_on_za; // [esp+2Ch] [ebp+4h]

  p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
  v5 = this->m_testee->get_matrix(this->m_testee);
  v6 = v5->c.x - p_c->x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 48);
  v12 = v5->i.y - p_c->y;
  v13 = v5->i.z - p_c->z;
  v7 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  projection_on_x = fabs((float)((float)(v7->i.z * v13) + (float)(v7->i.y * v12)) + (float)(v7->i.x * v6));
  v8 = bounding_volume->get_matrix(bounding_volume);
  v14 = sqrtf((float)((float)(v8->i.y * v8->i.y) + (float)(v8->i.z * v8->i.z)) + (float)(v8->i.x * v8->i.x));
  v15 = sqrtf((float)((float)(v8->j.x * v8->j.x) + (float)(v8->j.y * v8->j.y)) + (float)(v8->j.z * v8->j.z));
  v16 = sqrtf((float)((float)(v8->k.y * v8->k.y) + (float)(v8->k.z * v8->k.z)) + (float)(v8->k.x * v8->k.x));
  if ( sqrtf(
         (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
               + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
       + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
     + projection_on_x <= v14 )
  {
    v9 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    projection_on_z = fabs((float)((float)(v9->j.z * v13) + (float)(v9->j.y * v12)) + (float)(v6 * v9->j.x));
    if ( sqrtf(
           (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                 + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
       + projection_on_z <= v15 )
    {
      v10 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      projection_on_za = fabs((float)((float)(v10->k.z * v13) + (float)(v10->k.y * v12)) + (float)(v10->k.x * v6));
      if ( sqrtf(
             (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
                   + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
           + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + projection_on_za <= v16 )
        this->m_result = 1;
    }
  }
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::box_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-124h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x736666);
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  ;
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  ;
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-130h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x7365A6);
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  const vostok::math::float3 *v4; // ebx
  const vostok::math::float3 *v5; // edi
  const vostok::math::float4x4 *v6; // eax
  double x; // st7
  float y; // xmm2_4
  float z; // xmm1_4
  float v10; // xmm0_4
  const vostok::math::float4x4 *v11; // eax
  const vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  const vostok::collision::geometry_instance *m_testee; // ecx
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  unsigned int v16; // xmm0_4
  unsigned int v17; // xmm2_4
  float *v18; // eax
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm5_4
  vostok::math::float4_pod *p_j; // esi
  const vostok::math::float4x4 *v25; // eax
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  const vostok::math::float4x4 *v33; // eax
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm6_4
  float v37; // xmm3_4
  const vostok::collision::geometry_instance *m_bounding_volume; // ecx
  const vostok::math::float4x4 *(__thiscall *v39)(vostok::collision::geometry_instance *); // eax
  unsigned int v40; // xmm1_4
  unsigned int v41; // xmm2_4
  float *v42; // eax
  const vostok::math::float4x4 *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v47; // xmm0_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  const vostok::collision::geometry_instance *v50; // ecx
  const vostok::math::float4x4 *(__thiscall *v51)(vostok::collision::geometry_instance *); // eax
  float *v52; // eax
  const vostok::math::float4x4 *v53; // eax
  float v54; // xmm2_4
  unsigned int v55; // xmm1_4
  unsigned int v56; // xmm0_4
  float v57; // xmm2_4
  float v58; // [esp+18h] [ebp-40h]
  float v59; // [esp+18h] [ebp-40h]
  float test_cylinder_radius; // [esp+1Ch] [ebp-3Ch]
  vostok::math::float3 *range_axis; // [esp+20h] [ebp-38h]
  vostok::math::float3 *test_cylinder_alternative_axis; // [esp+24h] [ebp-34h]
  float test_cylinder_alternative_axisa; // [esp+24h] [ebp-34h]
  vostok::math::float3 center_to_cup_vector; // [esp+28h] [ebp-30h] BYREF
  vostok::math::float3 cylinder_x_axe; // [esp+34h] [ebp-24h] BYREF
  float v66; // [esp+40h] [ebp-18h]
  float v67; // [esp+44h] [ebp-14h]
  float v68; // [esp+48h] [ebp-10h]
  vostok::math::float3 test_cylinder_relative_position; // [esp+4Ch] [ebp-Ch] BYREF
  float bounding_volumea; // [esp+5Ch] [ebp+4h]
  float projection_on_axe; // [esp+60h] [ebp+8h]
  float projection_on_axea; // [esp+60h] [ebp+8h]
  float projection_on_axeb; // [esp+60h] [ebp+8h]
  float projection_on_axec; // [esp+60h] [ebp+8h]

  v4 = (const vostok::math::float3 *)&this->m_testee->get_matrix(this->m_testee)->lines[3];
  v5 = (const vostok::math::float3 *)&this->m_bounding_volume->get_matrix(this->m_bounding_volume)->lines[3];
  v58 = sqrtf(
          (float)((float)(testee->m_matrix.j.x * testee->m_matrix.j.x)
                + (float)(testee->m_matrix.j.y * testee->m_matrix.j.y))
        + (float)(testee->m_matrix.j.z * testee->m_matrix.j.z));
  v6 = this->m_testee->get_matrix(this->m_testee);
  x = v6->j.x;
  v6 = (const vostok::math::float4x4 *)((char *)v6 + 16);
  center_to_cup_vector.x = x * v58;
  center_to_cup_vector.y = v6->i.y * v58;
  y = bounding_volume->m_matrix.j.y;
  z = bounding_volume->m_matrix.j.z;
  v10 = bounding_volume->m_matrix.j.x;
  center_to_cup_vector.z = v58 * v6->i.z;
  v59 = sqrtf((float)((float)(y * y) + (float)(z * z)) + (float)(v10 * v10));
  range_axis = (vostok::math::float3 *)&this->m_bounding_volume->get_matrix(this->m_bounding_volume)->lines[1];
  test_cylinder_radius = sqrtf(
                           (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                                 + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
                         + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
  test_cylinder_alternative_axis = (vostok::math::float3 *)this->m_testee->get_matrix(this->m_testee);
  v11 = this->m_testee->get_matrix(this->m_testee);
  test_cylinder_relative_position.x = v4->x - v5->x;
  test_cylinder_relative_position.y = v4->y - v5->y;
  test_cylinder_relative_position.z = v4->z - v5->z;
  if ( vostok::collision::is_inside_range(
         (const vostok::math::float3 *)&v11->lines[1],
         test_cylinder_alternative_axis,
         range_axis,
         v5,
         &test_cylinder_relative_position,
         v4,
         &center_to_cup_vector,
         test_cylinder_radius,
         v59) )
  {
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    test_cylinder_alternative_axisa = (float)((float)(v12->j.z * (float)(v4->z - v5->z))
                                            + (float)(v12->j.y * (float)(v4->y - v5->y)))
                                    + (float)(v12->j.x * (float)(v4->x - v5->x));
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    m_testee = this->m_testee;
    get_matrix = m_testee->get_matrix;
    *(float *)&v16 = (float)((float)(v13->j.y * test_cylinder_alternative_axisa) + v5->y) - v4->y;
    *(float *)&v17 = (float)(v5->z + (float)(v13->j.z * test_cylinder_alternative_axisa)) - v4->z;
    cylinder_x_axe.x = (float)(v5->x + (float)(v13->j.x * test_cylinder_alternative_axisa)) - v4->x;
    *(_QWORD *)&cylinder_x_axe.elements[1] = __PAIR64__(v17, v16);
    v18 = (float *)get_matrix((vostok::collision::geometry_instance *)m_testee);
    v19 = v18[6];
    v20 = v18[5];
    v21 = (float)(v20 * cylinder_x_axe.z) - (float)(v19 * cylinder_x_axe.y);
    v22 = cylinder_x_axe.x * v19;
    v23 = v18[4];
    v66 = v21;
    v68 = (float)(v23 * cylinder_x_axe.y) - (float)(cylinder_x_axe.x * v20);
    v67 = v22 - (float)(v23 * cylinder_x_axe.z);
    if ( fabs((float)(v21 + v68) + v67) >= 0.0000099999997 )
    {
      v33 = this->m_testee->get_matrix(this->m_testee);
      v34 = v33->j.z;
      v35 = v33->j.y;
      test_cylinder_relative_position.x = (float)(v35 * v68) - (float)(v34 * v67);
      v36 = v66 * v34;
      v37 = v33->j.x;
      test_cylinder_relative_position.z = (float)(v37 * v67) - (float)(v66 * v35);
      test_cylinder_relative_position.y = v36 - (float)(v37 * v68);
      cylinder_x_axe = test_cylinder_relative_position;
      vostok::math::float3_pod::normalize(&cylinder_x_axe);
    }
    else
    {
      p_j = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->j;
      v25 = this->m_testee->get_matrix(this->m_testee);
      v26 = v25->j.z;
      v27 = v25->j.y;
      v28 = p_j->z;
      v29 = p_j->y;
      v30 = p_j->x;
      test_cylinder_relative_position.x = (float)(v27 * v28) - (float)(v26 * v29);
      v31 = v30 * v26;
      v32 = v25->j.x;
      test_cylinder_relative_position.z = (float)(v32 * v29) - (float)(v30 * v27);
      test_cylinder_relative_position.y = v31 - (float)(v32 * v28);
      cylinder_x_axe = test_cylinder_relative_position;
    }
    projection_on_axe = sqrtf(
                          (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                                + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
                        + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
    m_bounding_volume = this->m_bounding_volume;
    v39 = m_bounding_volume->get_matrix;
    test_cylinder_relative_position.x = (float)(cylinder_x_axe.x * projection_on_axe) + v4->x;
    *(float *)&v40 = (float)(cylinder_x_axe.z * projection_on_axe) + v4->z;
    cylinder_x_axe.x = test_cylinder_relative_position.x + center_to_cup_vector.x;
    *(float *)&v41 = v4->y + (float)(cylinder_x_axe.y * projection_on_axe);
    cylinder_x_axe.y = center_to_cup_vector.y + *(float *)&v41;
    *(_QWORD *)&test_cylinder_relative_position.elements[1] = __PAIR64__(v40, v41);
    cylinder_x_axe.z = center_to_cup_vector.z + *(float *)&v40;
    v42 = (float *)v39((vostok::collision::geometry_instance *)m_bounding_volume);
    projection_on_axea = (float)((float)(v42[6] * (float)(cylinder_x_axe.z - v5->z))
                               + (float)(v42[5] * (float)(cylinder_x_axe.y - v5->y)))
                       + (float)((float)(cylinder_x_axe.x - v5->x) * v42[4]);
    v43 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v44 = v43->j.y;
    v45 = v43->j.z;
    v66 = (float)(v43->j.x * projection_on_axea) + v5->x;
    v47 = v5->z + (float)(v45 * projection_on_axea);
    v48 = bounding_volume->m_matrix.i.z;
    v67 = (float)(v44 * projection_on_axea) + v5->y;
    v49 = bounding_volume->m_matrix.i.x;
    v68 = v47;
    bounding_volumea = sqrtf(
                         (float)((float)(v48 * v48) + (float)(v49 * v49))
                       + (float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y));
    if ( (float)((float)((float)((float)(cylinder_x_axe.x - v66) * (float)(cylinder_x_axe.x - v66))
                       + (float)((float)(cylinder_x_axe.z - v68) * (float)(cylinder_x_axe.z - v68)))
               + (float)((float)(cylinder_x_axe.y - v67) * (float)(cylinder_x_axe.y - v67))) <= (float)(bounding_volumea * bounding_volumea) )
    {
      v50 = this->m_bounding_volume;
      v51 = v50->get_matrix;
      cylinder_x_axe.x = test_cylinder_relative_position.x - center_to_cup_vector.x;
      cylinder_x_axe.y = test_cylinder_relative_position.y - center_to_cup_vector.y;
      cylinder_x_axe.z = test_cylinder_relative_position.z - center_to_cup_vector.z;
      v52 = (float *)v51((vostok::collision::geometry_instance *)v50);
      projection_on_axeb = (float)((float)(v52[6] * (float)(cylinder_x_axe.z - v5->z))
                                 + (float)(v52[5] * (float)(cylinder_x_axe.y - v5->y)))
                         + (float)((float)(cylinder_x_axe.x - v5->x) * v52[4]);
      v53 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
      v54 = v53->j.z;
      *(float *)&v55 = (float)(v53->j.y * projection_on_axeb) + v5->y;
      test_cylinder_relative_position.x = (float)(v53->j.x * projection_on_axeb) + v5->x;
      *(float *)&v56 = v5->z + (float)(v54 * projection_on_axeb);
      v57 = bounding_volume->m_matrix.i.y;
      *(_QWORD *)&test_cylinder_relative_position.elements[1] = __PAIR64__(v56, v55);
      projection_on_axec = sqrtf(
                             (float)((float)(v57 * v57)
                                   + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
                           + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
      if ( (float)((float)((float)((float)(cylinder_x_axe.x - test_cylinder_relative_position.x)
                                 * (float)(cylinder_x_axe.x - test_cylinder_relative_position.x))
                         + (float)((float)(cylinder_x_axe.z - test_cylinder_relative_position.z)
                                 * (float)(cylinder_x_axe.z - test_cylinder_relative_position.z)))
                 + (float)((float)(cylinder_x_axe.y - test_cylinder_relative_position.y)
                         * (float)(cylinder_x_axe.y - test_cylinder_relative_position.y))) <= (float)(projection_on_axec * projection_on_axec) )
        this->m_result = 1;
    }
  }
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  ;
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::cylinder_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[136]; // [esp-88h] [ebp-124h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x7365E6);
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  float z; // xmm2_4
  float x; // xmm1_4
  float y; // xmm0_4
  long double v9; // st7
  float v10; // xmm0_4
  float v11; // xmm0_4
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v13; // eax
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // [esp+10h] [ebp-4h]
  float v17; // [esp+10h] [ebp-4h]
  float bounding_volumea; // [esp+18h] [ebp+4h]
  float bounding_volumeb; // [esp+18h] [ebp+4h]
  float testeea; // [esp+1Ch] [ebp+8h]
  float testeeb; // [esp+1Ch] [ebp+8h]
  float testeec; // [esp+1Ch] [ebp+8h]
  float testeed; // [esp+1Ch] [ebp+8h]

  z = testee->m_matrix.i.z;
  x = testee->m_matrix.i.x;
  y = testee->m_matrix.i.y;
  v16 = bounding_volume->m_matrix.i.x;
  bounding_volumea = bounding_volume->m_matrix.i.z;
  testeea = bounding_volume->m_matrix.i.y;
  v9 = sqrtf((float)((float)(z * z) + (float)(x * x)) + (float)(y * y));
  v10 = testeea;
  testeeb = v9;
  if ( testeeb <= sqrtf((float)((float)(v10 * v10) + (float)(bounding_volumea * bounding_volumea)) + (float)(v16 * v16)) )
  {
    v17 = testee->m_matrix.i.x;
    bounding_volumeb = testee->m_matrix.i.z;
    v11 = testee->m_matrix.i.y;
    testeec = sqrtf(
                (float)((float)(bounding_volume->m_matrix.i.y * bounding_volume->m_matrix.i.y)
                      + (float)(bounding_volume->m_matrix.i.z * bounding_volume->m_matrix.i.z))
              + (float)(bounding_volume->m_matrix.i.x * bounding_volume->m_matrix.i.x));
    testeed = testeec
            - sqrtf((float)((float)(v11 * v11) + (float)(bounding_volumeb * bounding_volumeb)) + (float)(v17 * v17));
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v13 = this->m_testee->get_matrix(this->m_testee);
    v14 = v13->c.z - p_c->z;
    v15 = v13->c.y - p_c->y;
    this->m_result = (float)(testeed * testeed) >= (float)((float)((float)(v14 * v14) + (float)(v15 * v15))
                                                         + (float)((float)(v13->c.x - p_c->x)
                                                                 * (float)(v13->c.x - p_c->x)));
  }
}


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


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::sphere_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[72]; // [esp-48h] [ebp-E4h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x736623);
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::truncated_sphere_geometry_instance *testee)
{
  _BYTE v3[148]; // [esp-94h] [ebp-130h] BYREF
  _BYTE v4[148]; // [esp+0h] [ebp-9Ch] BYREF

  qmemcpy(v4, testee, sizeof(v4));
  qmemcpy(v3, bounding_volume, sizeof(v3));
  survarium::weapon_user_dead_state::finalize(0);
  JUMPOUT(0x736566);
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::box_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // esi
  long double v5; // st7
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float *p_y; // edi
  float v10; // xmm0_4
  float v11; // xmm2_4
  const vostok::math::float4x4 *v12; // eax
  const vostok::math::float4x4 *v13; // eax
  float v14; // xmm0_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v16; // eax
  unsigned int i; // ecx
  unsigned int v18; // [esp+10h] [ebp-7Ch]
  float squared_sphere_radius; // [esp+14h] [ebp-78h]
  float v20; // [esp+18h] [ebp-74h]
  float v21; // [esp+1Ch] [ebp-70h]
  float v22; // [esp+20h] [ebp-6Ch]
  float volume_to_vertex; // [esp+24h] [ebp-68h]
  float volume_to_vertex_4a; // [esp+28h] [ebp-64h]
  float volume_to_vertex_4; // [esp+28h] [ebp-64h]
  float volume_to_vertex_8; // [esp+2Ch] [ebp-60h]
  __int64 plane_8; // [esp+44h] [ebp-48h]
  vostok::math::float4x4 matrix; // [esp+4Ch] [ebp-40h] BYREF

  qmemcpy((void *)&matrix, this->m_testee->get_matrix(this->m_testee), sizeof(matrix));
  v4 = testee->get_matrix(testee);
  volume_to_vertex = sqrtf((float)((float)(v4->i.y * v4->i.y) + (float)(v4->i.z * v4->i.z)) + (float)(v4->i.x * v4->i.x));
  volume_to_vertex_4a = sqrtf((float)((float)(v4->j.z * v4->j.z) + (float)(v4->j.x * v4->j.x)) + (float)(v4->j.y * v4->j.y));
  v5 = sqrtf((float)((float)(v4->k.y * v4->k.y) + (float)(v4->k.z * v4->k.z)) + (float)(v4->k.x * v4->k.x));
  x = volume_to_vertex * matrix.i.x;
  matrix.j.x = matrix.j.x * volume_to_vertex_4a;
  y = matrix.i.y * volume_to_vertex;
  z = matrix.i.z * volume_to_vertex;
  matrix.j.y = volume_to_vertex_4a * matrix.j.y;
  matrix.i.x = volume_to_vertex * matrix.i.x;
  matrix.i.y = matrix.i.y * volume_to_vertex;
  matrix.i.z = matrix.i.z * volume_to_vertex;
  matrix.j.z = matrix.j.z * volume_to_vertex_4a;
  matrix.k.x = matrix.k.x * v5;
  squared_sphere_radius = bounding_volume->m_radius * bounding_volume->m_radius;
  p_y = &cuboid_vertices[0].y;
  matrix.k.y = matrix.k.y * v5;
  v18 = 0;
  matrix.k.z = v5 * matrix.k.z;
  while ( 1 )
  {
    v10 = *(p_y - 1);
    v11 = p_y[1];
    v20 = (float)((float)((float)(v11 * matrix.k.x) + (float)(v10 * x)) + (float)(*p_y * matrix.j.x)) + matrix.c.x;
    v21 = (float)((float)((float)(v10 * y) + (float)(matrix.k.y * v11)) + (float)(matrix.j.y * *p_y)) + matrix.c.y;
    v22 = (float)((float)((float)(v10 * z) + (float)(matrix.k.z * v11)) + (float)(matrix.j.z * *p_y)) + matrix.c.z;
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( squared_sphere_radius < (float)((float)((float)((float)(v20 - v12->c.x) * (float)(v20 - v12->c.x))
                                               + (float)((float)(v22 - v12->c.z) * (float)(v22 - v12->c.z)))
                                       + (float)((float)(v21 - v12->c.y) * (float)(v21 - v12->c.y))) )
      break;
    v13 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v14 = v20 - v13->c.x;
    v13 = (const vostok::math::float4x4 *)((char *)v13 + 48);
    volume_to_vertex_4 = v21 - v13->i.y;
    volume_to_vertex_8 = v22 - v13->i.z;
    this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
    m_begin = bounding_volume->m_planes.m_begin;
    v16 = bounding_volume->m_planes.m_end - m_begin;
    for ( i = 0; i < v16; ++m_begin )
    {
      plane_8 = *(_QWORD *)&m_begin->elements[2];
      if ( (float)((float)((float)((float)(v14
                                         - (float)((float)(*((float *)&plane_8 + 1) * m_begin->x)
                                                 * bounding_volume->m_radius))
                                 * m_begin->x)
                         + (float)((float)(volume_to_vertex_8
                                         - (float)((float)(*((float *)&plane_8 + 1) * *(float *)&plane_8)
                                                 * bounding_volume->m_radius))
                                 * *(float *)&plane_8))
                 + (float)((float)(volume_to_vertex_4
                                 - (float)((float)(*((float *)&plane_8 + 1) * m_begin->y) * bounding_volume->m_radius))
                         * m_begin->y)) > 0.0 )
        return;
      ++i;
    }
    p_y += 3;
    v18 += 12;
    if ( v18 >= 0x60 )
    {
      this->m_result = 1;
      return;
    }
    z = matrix.i.z;
    y = matrix.i.y;
    x = matrix.i.x;
  }
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm0_4
  const vostok::math::float4x4 *v8; // eax
  float v9; // xmm1_4
  const vostok::math::float4x4 *v10; // eax
  float v11; // xmm0_4
  const vostok::math::float4x4 *v12; // eax
  float v13; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v16; // xmm2_4
  vostok::math::float4_pod *p_c; // eax
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm5_4
  vostok::math::float4 *m_begin; // edx
  unsigned int v23; // eax
  unsigned int v24; // ecx
  float m_radius; // xmm3_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  float m_half_length; // [esp+Ch] [ebp-3Ch]
  float v29; // [esp+Ch] [ebp-3Ch]
  float v30; // [esp+10h] [ebp-38h]
  float plane_point; // [esp+14h] [ebp-34h]
  float plane_point_4; // [esp+18h] [ebp-30h]
  float plane_point_8; // [esp+1Ch] [ebp-2Ch]
  float plane_point_8a; // [esp+1Ch] [ebp-2Ch]
  float volume_to_second_testee_point; // [esp+20h] [ebp-28h]
  float volume_to_second_testee_point_4; // [esp+24h] [ebp-24h]
  float volume_to_second_testee_point_4a; // [esp+24h] [ebp-24h]
  float volume_to_second_testee_point_8; // [esp+28h] [ebp-20h]
  float volume_to_second_testee_point_8a; // [esp+28h] [ebp-20h]
  float volume_to_first_testee_point_4; // [esp+30h] [ebp-18h]
  float volume_to_first_testee_point_8; // [esp+34h] [ebp-14h]
  float volume_to_first_testee_point_8a; // [esp+34h] [ebp-14h]
  __int64 plane_8; // [esp+40h] [ebp-8h]

  if ( testee->m_radius <= bounding_volume->m_radius )
  {
    m_half_length = testee->m_half_length;
    v4 = this->m_testee->get_matrix(this->m_testee);
    x = v4->j.x;
    v4 = (const vostok::math::float4x4 *)((char *)v4 + 16);
    volume_to_second_testee_point_4 = v4->i.y * m_half_length;
    volume_to_second_testee_point_8 = v4->i.z * m_half_length;
    v6 = this->m_testee->get_matrix(this->m_testee);
    v7 = v6->c.x + (float)(x * m_half_length);
    v6 = (const vostok::math::float4x4 *)((char *)v6 + 48);
    plane_point = v7;
    plane_point_4 = v6->i.y + volume_to_second_testee_point_4;
    plane_point_8 = v6->i.z + volume_to_second_testee_point_8;
    v29 = testee->m_half_length;
    v8 = this->m_testee->get_matrix(this->m_testee);
    v9 = v8->j.x;
    v8 = (const vostok::math::float4x4 *)((char *)v8 + 16);
    volume_to_second_testee_point_4a = v8->i.y * v29;
    volume_to_second_testee_point_8a = v8->i.z * v29;
    v10 = this->m_testee->get_matrix(this->m_testee);
    v11 = v10->c.x - (float)(v9 * v29);
    v10 = (const vostok::math::float4x4 *)((char *)v10 + 48);
    volume_to_first_testee_point_4 = v10->i.y - volume_to_second_testee_point_4a;
    volume_to_first_testee_point_8 = v10->i.z - volume_to_second_testee_point_8a;
    v12 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    v13 = v12->c.x;
    y = v12->c.y;
    z = v12->c.z;
    v16 = bounding_volume->m_radius - testee->m_radius;
    p_c = &v12->c;
    if ( (float)((float)((float)((float)(plane_point - v13) * (float)(plane_point - v13))
                       + (float)((float)(plane_point_8 - z) * (float)(plane_point_8 - z)))
               + (float)((float)(plane_point_4 - y) * (float)(plane_point_4 - y))) <= (float)(v16 * v16) )
    {
      v18 = v11 - v13;
      if ( (float)((float)((float)(v18 * v18)
                         + (float)((float)(volume_to_first_testee_point_8 - z)
                                 * (float)(volume_to_first_testee_point_8 - z)))
                 + (float)((float)(volume_to_first_testee_point_4 - y) * (float)(volume_to_first_testee_point_4 - y))) <= (float)(v16 * v16) )
      {
        v19 = p_c->y;
        v20 = p_c->z;
        v21 = volume_to_first_testee_point_8 - v20;
        volume_to_first_testee_point_8a = plane_point_8 - v20;
        volume_to_second_testee_point = v18;
        this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
        m_begin = bounding_volume->m_planes.m_begin;
        v23 = bounding_volume->m_planes.m_end - m_begin;
        v24 = 0;
        if ( v23 )
        {
          m_radius = bounding_volume->m_radius;
          v30 = -testee->m_radius;
          while ( 1 )
          {
            plane_8 = *(_QWORD *)&m_begin->elements[2];
            v26 = (float)(*((float *)&plane_8 + 1) * m_begin->x) * m_radius;
            plane_point_8a = (float)(*((float *)&plane_8 + 1) * *(float *)&plane_8) * m_radius;
            v27 = (float)(*((float *)&plane_8 + 1) * m_begin->y) * m_radius;
            if ( (float)((float)((float)((float)((float)(plane_point - v13) - v26) * m_begin->x)
                               + (float)((float)(volume_to_first_testee_point_8a - plane_point_8a) * *(float *)&plane_8))
                       + (float)((float)((float)(plane_point_4 - v19) - v27) * m_begin->y)) > v30
              || (float)((float)((float)((float)(volume_to_second_testee_point - v26) * m_begin->x)
                               + (float)((float)(v21 - plane_point_8a) * m_begin->z))
                       + (float)((float)((float)(volume_to_first_testee_point_4 - v19) - v27) * m_begin->y)) > v30 )
            {
              break;
            }
            ++v24;
            ++m_begin;
            if ( v24 >= v23 )
              goto LABEL_10;
            m_radius = bounding_volume->m_radius;
          }
        }
        else
        {
LABEL_10:
          this->m_result = 1;
        }
      }
    }
  }
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::cylinder_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // edi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm0_4
  const vostok::math::float4x4 *v7; // eax
  float y; // xmm5_4
  float z; // xmm6_4
  float x; // xmm7_4
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  long double v17; // st7
  const vostok::math::float4x4 *v18; // eax
  const vostok::math::float4x4 *v19; // eax
  const vostok::math::float4x4 *v20; // eax
  const vostok::collision::truncated_sphere_geometry_instance *v21; // ecx
  vostok::math::float4 *m_begin; // eax
  float m_radius; // xmm3_4
  const vostok::math::float4x4 *v24; // eax
  float v25; // xmm0_4
  int v26; // [esp+14h] [ebp-50h]
  float ia; // [esp+18h] [ebp-4Ch]
  float ib; // [esp+18h] [ebp-4Ch]
  float ic; // [esp+18h] [ebp-4Ch]
  float id; // [esp+18h] [ebp-4Ch]
  float ie; // [esp+18h] [ebp-4Ch]
  unsigned int i; // [esp+18h] [ebp-4Ch]
  float v33; // [esp+1Ch] [ebp-48h]
  float v34; // [esp+1Ch] [ebp-48h]
  float v35; // [esp+20h] [ebp-44h]
  float v36; // [esp+24h] [ebp-40h]
  float v37; // [esp+28h] [ebp-3Ch]
  unsigned int count; // [esp+2Ch] [ebp-38h]
  __int64 testee_x_axe; // [esp+30h] [ebp-34h]
  float testee_x_axe_4; // [esp+34h] [ebp-30h]
  float testee_x_axe_8b; // [esp+38h] [ebp-2Ch]
  float testee_x_axe_8; // [esp+38h] [ebp-2Ch]
  float testee_x_axe_8a; // [esp+38h] [ebp-2Ch]
  float plane_position; // [esp+3Ch] [ebp-28h]
  float plane_positiona; // [esp+3Ch] [ebp-28h]
  float plane_position_4; // [esp+40h] [ebp-24h]
  float plane_position_4a; // [esp+40h] [ebp-24h]
  float plane_position_4b; // [esp+40h] [ebp-24h]
  float plane_position_8; // [esp+44h] [ebp-20h]
  float plane_position_8a; // [esp+44h] [ebp-20h]
  float plane_position_8b; // [esp+44h] [ebp-20h]
  __int64 plane; // [esp+54h] [ebp-10h]
  __int64 plane_8; // [esp+5Ch] [ebp-8h]

  p_c = &this->m_testee->get_matrix(this->m_testee)->c;
  v5 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v6 = v5->c.x - p_c->x;
  v5 = (const vostok::math::float4x4 *)((char *)v5 + 48);
  testee_x_axe_4 = v5->i.y - p_c->y;
  testee_x_axe_8b = v5->i.z - p_c->z;
  v7 = this->m_testee->get_matrix(this->m_testee);
  y = v7->j.y;
  z = v7->j.z;
  x = v7->j.x;
  plane_position_8 = (float)(testee_x_axe_4 * x) - (float)(v6 * y);
  plane_position = (float)(testee_x_axe_8b * y) - (float)(testee_x_axe_4 * z);
  plane_position_4 = (float)(v6 * z) - (float)(testee_x_axe_8b * x);
  v11 = this->m_testee->get_matrix(this->m_testee);
  if ( (float)((float)(plane_position_8 + plane_position_4) + plane_position) == 0.0 )
  {
    testee_x_axe = *(_QWORD *)&v11->i.x;
    testee_x_axe_8 = v11->i.z;
  }
  else
  {
    v12 = v11->j.z;
    v13 = (float)(v11->j.y * plane_position_8) - (float)(v12 * plane_position_4);
    v14 = v11->j.x;
    v15 = (float)(v14 * plane_position_4) - (float)(v11->j.y * plane_position);
    v16 = (float)(v12 * plane_position) - (float)(v14 * plane_position_8);
    v17 = 1.0 / sqrtf((float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v13 * v13));
    ia = v17;
    *(float *)&testee_x_axe = ia * v13;
    *((float *)&testee_x_axe + 1) = v16 * v17;
    testee_x_axe_8 = v17 * v15;
  }
  ib = sqrtf(
         (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
               + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
       + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z));
  *(float *)&testee_x_axe = p_c->x + (float)(*(float *)&testee_x_axe * ib);
  testee_x_axe_8a = (float)(testee_x_axe_8 * ib) + p_c->z;
  *((float *)&testee_x_axe + 1) = (float)(*((float *)&testee_x_axe + 1) * ib) + p_c->y;
  ic = sqrtf(
         (float)((float)(testee->m_matrix.j.x * testee->m_matrix.j.x)
               + (float)(testee->m_matrix.j.y * testee->m_matrix.j.y))
       + (float)(testee->m_matrix.j.z * testee->m_matrix.j.z));
  v18 = this->m_testee->get_matrix(this->m_testee);
  plane_positiona = v18->j.x * ic;
  plane_position_4a = v18->j.y * ic;
  plane_position_8a = v18->j.z * ic;
  id = bounding_volume->m_radius;
  v19 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  if ( (float)((float)((float)((float)((float)(plane_position_8a + testee_x_axe_8a) - v19->c.z)
                             * (float)((float)(plane_position_8a + testee_x_axe_8a) - v19->c.z))
                     + (float)((float)((float)(plane_position_4a + *((float *)&testee_x_axe + 1)) - v19->c.y)
                             * (float)((float)(plane_position_4a + *((float *)&testee_x_axe + 1)) - v19->c.y)))
             + (float)((float)((float)(plane_positiona + *(float *)&testee_x_axe) - v19->c.x)
                     * (float)((float)(plane_positiona + *(float *)&testee_x_axe) - v19->c.x))) <= (float)(id * id) )
  {
    ie = bounding_volume->m_radius;
    v20 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
    if ( (float)((float)((float)((float)((float)(testee_x_axe_8a - plane_position_8a) - v20->c.z)
                               * (float)((float)(testee_x_axe_8a - plane_position_8a) - v20->c.z))
                       + (float)((float)((float)(*((float *)&testee_x_axe + 1) - plane_position_4a) - v20->c.y)
                               * (float)((float)(*((float *)&testee_x_axe + 1) - plane_position_4a) - v20->c.y)))
               + (float)((float)((float)(*(float *)&testee_x_axe - plane_positiona) - v20->c.x)
                       * (float)((float)(*(float *)&testee_x_axe - plane_positiona) - v20->c.x))) <= (float)(ie * ie) )
    {
      this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
      v21 = bounding_volume;
      count = bounding_volume->m_planes.m_end - bounding_volume->m_planes.m_begin;
      i = 0;
      if ( count )
      {
        v26 = 0;
        while ( 1 )
        {
          m_begin = v21->m_planes.m_begin;
          m_radius = v21->m_radius;
          plane = *(_QWORD *)&m_begin[v26].x;
          plane_8 = *(_QWORD *)&m_begin[v26].elements[2];
          v24 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
          v25 = (float)((float)(*(float *)&plane * *((float *)&plane_8 + 1)) * m_radius) + v24->c.x;
          v24 = (const vostok::math::float4x4 *)((char *)v24 + 48);
          plane_position_4b = v24->i.y + (float)((float)(*((float *)&plane + 1) * *((float *)&plane_8 + 1)) * m_radius);
          plane_position_8b = v24->i.z + (float)((float)(*(float *)&plane_8 * *((float *)&plane_8 + 1)) * m_radius);
          this->m_testee->get_matrix((vostok::collision::geometry_instance *)this->m_testee);
          this->m_testee->get_matrix((vostok::collision::geometry_instance *)this->m_testee);
          v35 = p_c->x - v25;
          v36 = p_c->y - plane_position_4b;
          v37 = p_c->z - plane_position_8b;
          v33 = *(float *)&plane_8 * v37 + *((float *)&plane + 1) * v36 + v35 * *(float *)&plane;
          if ( v33 > -sqrtf(
                        (float)((float)(testee->m_matrix.i.x * testee->m_matrix.i.x)
                              + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y))
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z)) )
            break;
          v34 = v36 * *((float *)&plane + 1) + v37 * *(float *)&plane_8 + v35 * *(float *)&plane;
          if ( v34 > -sqrtf(
                        (float)((float)(testee->m_matrix.i.z * testee->m_matrix.i.z)
                              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x))
                      + (float)(testee->m_matrix.i.y * testee->m_matrix.i.y)) )
            break;
          ++v26;
          if ( ++i >= count )
            goto LABEL_12;
          v21 = bounding_volume;
        }
      }
      else
      {
LABEL_12:
        this->m_result = 1;
      }
    }
  }
}


void __thiscall vostok::collision::containment_double_dispatcher::dispatch(
        vostok::collision::containment_double_dispatcher *this,
        const vostok::collision::truncated_sphere_geometry_instance *bounding_volume,
        const vostok::collision::sphere_geometry_instance *testee)
{
  vostok::math::float4_pod *p_c; // esi
  const vostok::math::float4x4 *v5; // eax
  float v6; // xmm2_4
  float v7; // xmm1_4
  vostok::math::float4_pod *v8; // esi
  const vostok::math::float4x4 *v9; // eax
  float v10; // xmm0_4
  unsigned int v11; // esi
  long double v12; // st7
  vostok::math::float4 *v13; // eax
  float i; // [esp+14h] [ebp-38h]
  float ib; // [esp+14h] [ebp-38h]
  unsigned int ia; // [esp+14h] [ebp-38h]
  vostok::math::float4 *m_begin; // [esp+18h] [ebp-34h]
  float m_radius; // [esp+1Ch] [ebp-30h]
  float v19; // [esp+20h] [ebp-2Ch]
  float volume_ot_testee_position_4; // [esp+28h] [ebp-24h]
  float volume_ot_testee_position_8; // [esp+2Ch] [ebp-20h]
  __int64 plane_8; // [esp+44h] [ebp-8h]

  i = bounding_volume->m_radius;
  if ( sqrtf(
         (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
               + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
       + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x)) <= i )
  {
    ib = i
       - sqrtf(
           (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                 + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
         + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
    p_c = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
    v5 = this->m_testee->get_matrix(this->m_testee);
    v6 = v5->c.z - p_c->z;
    v7 = v5->c.y - p_c->y;
    if ( (float)((float)((float)((float)(v5->c.x - p_c->x) * (float)(v5->c.x - p_c->x)) + (float)(v6 * v6))
               + (float)(v7 * v7)) <= (float)(ib * ib) )
    {
      v8 = &this->m_bounding_volume->get_matrix(this->m_bounding_volume)->c;
      v9 = this->m_testee->get_matrix(this->m_testee);
      v10 = v9->c.x - v8->x;
      v9 = (const vostok::math::float4x4 *)((char *)v9 + 48);
      volume_ot_testee_position_4 = v9->i.y - v8->y;
      volume_ot_testee_position_8 = v9->i.z - v8->z;
      this->m_bounding_volume->get_matrix((vostok::collision::geometry_instance *)this->m_bounding_volume);
      v11 = bounding_volume->m_planes.m_end - bounding_volume->m_planes.m_begin;
      m_begin = bounding_volume->m_planes.m_begin;
      ia = 0;
      if ( v11 )
      {
        m_radius = bounding_volume->m_radius;
        v12 = sqrtf(
                (float)((float)(testee->m_matrix.i.y * testee->m_matrix.i.y)
                      + (float)(testee->m_matrix.i.z * testee->m_matrix.i.z))
              + (float)(testee->m_matrix.i.x * testee->m_matrix.i.x));
        v13 = m_begin;
        while ( 1 )
        {
          plane_8 = *(_QWORD *)&v13->elements[2];
          v19 = -v12;
          if ( (float)((float)((float)((float)(volume_ot_testee_position_8
                                             - (float)((float)(*((float *)&plane_8 + 1) * *(float *)&plane_8) * m_radius))
                                     * *(float *)&plane_8)
                             + (float)((float)(volume_ot_testee_position_4
                                             - (float)((float)(*((float *)&plane_8 + 1) * v13->y) * m_radius))
                                     * v13->y))
                     + (float)((float)(v10 - (float)((float)(*((float *)&plane_8 + 1) * v13->x) * m_radius)) * v13->x)) > v19 )
            break;
          ++v13;
          if ( ++ia >= v11 )
            goto LABEL_7;
        }
      }
      else
      {
LABEL_7:
        this->m_result = 1;
      }
    }
  }
}

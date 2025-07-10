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

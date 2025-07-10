vostok::math::float3 *__usercall vostok::collision::nearest_cylinder_edge_center@<eax>(
        const vostok::math::float3 *test_cylinder_center@<edi>,
        const vostok::math::float3 *test_cylinder_up_axis@<eax>,
        const vostok::math::float3 *test_cylinder_alternative_axis@<ecx>,
        const vostok::math::float3 *to_point_vector@<esi>,
        float *test_cylinder_radius,
        const vostok::math::float3 *test_cylinder_relative_position,
        const vostok::math::float3 *test_cylinder_relative_positiona)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float x; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v14; // xmm4_4
  float v16; // xmm0_4
  long double v17; // st7
  bool v18; // cc
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // edx
  float v25; // eax
  vostok::math::float3 to_extremums_axis; // [esp+Ch] [ebp-18h]
  float to_extremums_axis_8; // [esp+14h] [ebp-10h]
  float v28; // [esp+18h] [ebp-Ch]
  __int64 v29; // [esp+18h] [ebp-Ch]
  __int64 v30; // [esp+18h] [ebp-Ch]
  float v31; // [esp+1Ch] [ebp-8h]
  float v32; // [esp+28h] [ebp+4h]
  float test_cylinder_relative_positionb; // [esp+30h] [ebp+Ch]

  y = test_cylinder_up_axis->y;
  z = test_cylinder_up_axis->z;
  x = to_point_vector->x;
  v10 = (float)(to_point_vector->z * y) - (float)(to_point_vector->y * z);
  v11 = test_cylinder_up_axis->x;
  v12 = (float)(to_point_vector->x * z) - (float)(test_cylinder_up_axis->x * to_point_vector->z);
  v14 = (float)(test_cylinder_up_axis->x * to_point_vector->y) - (float)(to_point_vector->x * y);
  v32 = to_point_vector->x;
  if ( fabs((float)(v14 + v12) + v10) >= 0.0000099999997 )
  {
    v28 = (float)(test_cylinder_up_axis->y * v14) - (float)(test_cylinder_up_axis->z * v12);
    v31 = (float)(test_cylinder_up_axis->z * v10) - (float)(v11 * v14);
    to_extremums_axis_8 = (float)(v11 * v12) - (float)(test_cylinder_up_axis->y * v10);
    v17 = 1.0
        / sqrtf((float)((float)(to_extremums_axis_8 * to_extremums_axis_8) + (float)(v28 * v28)) + (float)(v31 * v31));
    x = v32;
    test_cylinder_relative_positionb = v17;
    v16 = test_cylinder_relative_positionb * v28;
    to_extremums_axis.y = v31 * v17;
    to_extremums_axis.z = v17 * to_extremums_axis_8;
  }
  else
  {
    to_extremums_axis = *test_cylinder_alternative_axis;
    v16 = test_cylinder_alternative_axis->x;
  }
  v18 = (float)((float)((float)(test_cylinder_relative_positiona->z * to_point_vector->z)
                      + (float)(test_cylinder_relative_positiona->y * to_point_vector->y))
              + (float)(x * test_cylinder_relative_positiona->x)) <= 0.0;
  v19 = v16 * *(float *)&test_cylinder_relative_position;
  v20 = to_extremums_axis.y * *(float *)&test_cylinder_relative_position;
  v21 = to_extremums_axis.z * *(float *)&test_cylinder_relative_position;
  v22 = test_cylinder_center->x;
  if ( v18 )
  {
    *((float *)&v30 + 1) = test_cylinder_center->y + v20;
    v25 = test_cylinder_center->z + v21;
    *(float *)&v30 = v22 + v19;
    *(_QWORD *)test_cylinder_radius = v30;
    test_cylinder_radius[2] = v25;
  }
  else
  {
    *((float *)&v29 + 1) = test_cylinder_center->y - v20;
    v23 = test_cylinder_center->z - v21;
    *(float *)&v29 = v22 - v19;
    *(_QWORD *)test_cylinder_radius = v29;
    test_cylinder_radius[2] = v23;
  }
  return (vostok::math::float3 *)test_cylinder_radius;
}

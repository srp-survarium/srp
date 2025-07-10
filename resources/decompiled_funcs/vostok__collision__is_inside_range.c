bool __usercall vostok::collision::is_inside_range@<al>(
        const vostok::math::float3 *test_cylinder_up_axis@<eax>,
        const vostok::math::float3 *test_cylinder_alternative_axis@<ecx>,
        const vostok::math::float3 *range_axis@<esi>,
        const vostok::math::float3 *range_center@<edi>,
        const vostok::math::float3 *test_cylinder_relative_position,
        const vostok::math::float3 *test_cylinder_center,
        const vostok::math::float3 *test_cylinder_center_to_cap_vector,
        float test_cylinder_radius,
        float range_half_size)
{
  float y; // xmm1_4
  float z; // xmm6_4
  float x; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm1_4
  unsigned int v19; // xmm4_4
  long double v20; // st7
  float v21; // xmm5_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v29; // [esp+Ch] [ebp-28h]
  float v30; // [esp+10h] [ebp-24h]
  __int64 v31; // [esp+14h] [ebp-20h]
  vostok::math::float3 to_extremums_axis; // [esp+1Ch] [ebp-18h]
  unsigned int v33; // [esp+28h] [ebp-Ch]
  float v34; // [esp+28h] [ebp-Ch]
  float v35; // [esp+2Ch] [ebp-8h]
  float test_cylinder_relative_positiona; // [esp+38h] [ebp+4h]
  float test_cylinder_center_to_cap_vectora; // [esp+40h] [ebp+Ch]

  y = test_cylinder_up_axis->y;
  z = test_cylinder_up_axis->z;
  x = range_axis->x;
  v14 = (float)(range_axis->z * y) - (float)(range_axis->y * z);
  v15 = test_cylinder_up_axis->x;
  v16 = (float)(range_axis->x * z) - (float)(test_cylinder_up_axis->x * range_axis->z);
  v17 = (float)(test_cylinder_up_axis->x * range_axis->y) - (float)(range_axis->x * y);
  test_cylinder_relative_positiona = range_axis->x;
  if ( fabs((float)(v17 + v16) + v14) >= 0.0000099999997 )
  {
    *(float *)&v19 = (float)(test_cylinder_up_axis->z * v14) - (float)(v15 * v17);
    *(float *)&v33 = (float)(test_cylinder_up_axis->y * v17) - (float)(test_cylinder_up_axis->z * v16);
    *(_QWORD *)&to_extremums_axis.x = __PAIR64__(v19, v33);
    to_extremums_axis.z = (float)(v15 * v16) - (float)(test_cylinder_up_axis->y * v14);
    v20 = 1.0
        / sqrtf(
            (float)((float)(to_extremums_axis.z * to_extremums_axis.z) + (float)(*(float *)&v19 * *(float *)&v19))
          + (float)(to_extremums_axis.x * to_extremums_axis.x));
    x = test_cylinder_relative_positiona;
    test_cylinder_center_to_cap_vectora = v20;
    v18 = test_cylinder_center_to_cap_vectora * *(float *)&v33;
    to_extremums_axis.y = to_extremums_axis.y * v20;
    to_extremums_axis.z = v20 * to_extremums_axis.z;
  }
  else
  {
    to_extremums_axis = *test_cylinder_alternative_axis;
    v18 = test_cylinder_alternative_axis->x;
  }
  v21 = range_axis->z;
  v22 = range_axis->y;
  v23 = v18 * test_cylinder_radius;
  v24 = to_extremums_axis.z * test_cylinder_radius;
  v25 = to_extremums_axis.y * test_cylinder_radius;
  if ( (float)((float)((float)(test_cylinder_relative_position->y * v22)
                     + (float)(test_cylinder_relative_position->z * v21))
             + (float)(x * test_cylinder_relative_position->x)) <= 0.0 )
  {
    v34 = v23 + test_cylinder_center->x;
    v35 = test_cylinder_center->y + v25;
    v27 = test_cylinder_center->z + v24;
  }
  else
  {
    v26 = test_cylinder_center->x - v23;
    v35 = test_cylinder_center->y - v25;
    v27 = test_cylinder_center->z - v24;
    v34 = v26;
  }
  v29 = test_cylinder_center_to_cap_vector->y;
  v31 = *(_QWORD *)&range_center->elements[1];
  v30 = test_cylinder_center_to_cap_vector->z;
  return fabs(
           (float)((float)(v22 * (float)((float)(v29 + v35) - *(float *)&v31))
                 + (float)(v21 * (float)((float)(v30 + v27) - *((float *)&v31 + 1))))
         + (float)(x * (float)((float)(test_cylinder_center_to_cap_vector->x + v34) - range_center->x))) <= range_half_size
      && fabs(
           (float)((float)(v22 * (float)((float)(v35 - v29) - *(float *)&v31))
                 + (float)(v21 * (float)((float)(v27 - v30) - *((float *)&v31 + 1))))
         + (float)(x * (float)((float)(v34 - test_cylinder_center_to_cap_vector->x) - range_center->x))) <= range_half_size;
}

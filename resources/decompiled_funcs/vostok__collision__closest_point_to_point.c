void __usercall vostok::collision::closest_point_to_point(
        vostok::math::float3 *result@<esi>,
        const vostok::math::float3 *box_half_sides@<edx>,
        const vostok::math::float3 *point@<ecx>,
        const vostok::math::float4x4 *box_matrix)
{
  float v5; // xmm2_4
  float v6; // xmm3_4
  float x; // xmm6_4
  float v8; // xmm1_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  float y; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float z; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // eax
  __int64 v19; // [esp+0h] [ebp-14h]
  __int64 v20; // [esp+8h] [ebp-Ch]
  float box_matrixa; // [esp+18h] [ebp+4h]

  v5 = point->y - box_matrix->c.y;
  v6 = point->z - box_matrix->c.z;
  x = box_matrix->i.x;
  v8 = point->x - box_matrix->c.x;
  v9 = box_half_sides->x;
  v19 = *(_QWORD *)&box_matrix->lines[0].elements[1];
  v10 = (float)((float)(*((float *)&v19 + 1) * v6) + (float)(*(float *)&v19 * v5)) + (float)(box_matrix->i.x * v8);
  if ( (float)-box_half_sides->x < v10 )
  {
    if ( v9 < v10 )
      box_matrixa = box_half_sides->x;
    else
      box_matrixa = (float)((float)(*((float *)&v19 + 1) * v6) + (float)(*(float *)&v19 * v5))
                  + (float)(box_matrix->i.x * v8);
  }
  else
  {
    box_matrixa = -v9;
  }
  y = box_half_sides->y;
  v12 = (float)((float)(box_matrix->j.z * v6) + (float)(box_matrix->j.y * v5)) + (float)(box_matrix->j.x * v8);
  if ( (float)-y < v12 )
  {
    if ( y >= v12 )
      y = (float)((float)(box_matrix->j.z * v6) + (float)(box_matrix->j.y * v5)) + (float)(box_matrix->j.x * v8);
  }
  else
  {
    y = -box_half_sides->y;
  }
  v13 = (float)((float)(box_matrix->k.z * v6) + (float)(box_matrix->k.y * v5)) + (float)(v8 * box_matrix->k.x);
  if ( (float)-box_half_sides->z < v13 )
  {
    if ( box_half_sides->z < v13 )
      z = box_half_sides->z;
    else
      z = (float)((float)(box_matrix->k.z * v6) + (float)(box_matrix->k.y * v5)) + (float)(v8 * box_matrix->k.x);
  }
  else
  {
    z = -box_half_sides->z;
  }
  v15 = box_matrix->k.y * z;
  v16 = box_matrix->k.z * z;
  v17 = (float)((float)((float)(x * box_matrixa) + (float)(box_matrix->j.x * y)) + (float)(box_matrix->k.x * z))
      + box_matrix->c.x;
  *((float *)&v20 + 1) = box_matrix->c.y
                       + (float)((float)((float)(*(float *)&v19 * box_matrixa) + (float)(box_matrix->j.y * y)) + v15);
  v18 = box_matrix->c.z
      + (float)((float)((float)(*((float *)&v19 + 1) * box_matrixa) + (float)(box_matrix->j.z * y)) + v16);
  *(float *)&v20 = v17;
  *(_QWORD *)&result->x = v20;
  result->z = v18;
}

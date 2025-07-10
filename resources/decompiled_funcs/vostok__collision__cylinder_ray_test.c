char __usercall vostok::collision::cylinder_ray_test@<al>(
        const vostok::math::float3 *ray_origin@<edi>,
        const vostok::math::float3 *ray_direction@<esi>,
        float cylinder_radius,
        float cylinder_half_length,
        float max_distance,
        float *distance)
{
  vostok::math::float4x4 *v6; // eax
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // eax
  float v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  int v20; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float k; // [esp+8h] [ebp-B4h]
  float uv; // [esp+Ch] [ebp-B0h] BYREF
  vostok::math::float3 dir; // [esp+10h] [ebp-ACh] BYREF
  vostok::math::float3 start; // [esp+1Ch] [ebp-A0h] BYREF
  vostok::math::plane p; // [esp+28h] [ebp-94h] BYREF
  vostok::math::float3 q; // [esp+38h] [ebp-84h]
  float A; // [esp+44h] [ebp-78h]
  float B; // [esp+48h] [ebp-74h]
  float R[12]; // [esp+4Ch] [ebp-70h]
  vostok::math::float4x4 v41; // [esp+7Ch] [ebp-40h] BYREF

  v6 = vostok::math::float4x4::identity(&v41);
  x = v6->j.x;
  y = v6->j.y;
  z = v6->j.z;
  v10 = v6->c.x;
  v11 = v6->c.y;
  v12 = v6->c.z;
  v13 = ray_origin->z;
  *(_QWORD *)&start.x = *(_QWORD *)&ray_origin->x;
  v14 = ray_direction->z;
  *(_QWORD *)&dir.x = *(_QWORD *)&ray_direction->x;
  v15 = start.x - v10;
  p.normal.z = v12;
  *(_QWORD *)&p.normal.x = __PAIR64__(LODWORD(v11), LODWORD(v10));
  start.z = v13;
  R[9] = z;
  v16 = (float)((float)((float)(start.y - v11) * y) + (float)((float)(v13 - v12) * z))
      + (float)((float)(start.x - v10) * x);
  v17 = (float)(y * v16) - (float)(start.y - v11);
  q.z = (float)(R[9] * v16) - (float)(v13 - v12);
  v18 = (float)(x * v16) - v15;
  v19 = (float)((float)((float)(v17 * v17) + (float)(q.z * q.z)) + (float)(v18 * v18))
      - (float)(cylinder_radius * cylinder_radius);
  v20 = 0;
  R[1] = x;
  R[5] = y;
  dir.z = v14;
  if ( v19 < 0.0 )
  {
    v21 = -cylinder_half_length;
    if ( (float)-cylinder_half_length > v16 || v16 > cylinder_half_length )
    {
      if ( v16 >= 0.0 )
      {
        v27 = cylinder_half_length;
        goto LABEL_19;
      }
LABEL_18:
      v27 = v21;
      goto LABEL_19;
    }
    v20 = 1;
  }
  v22 = (float)((float)(dir.y * y) + (float)(dir.z * R[9])) + (float)(dir.x * x);
  v23 = (float)(v22 * x) - dir.x;
  v24 = (float)(v22 * y) - dir.y;
  uv = v22;
  v25 = (float)(v22 * R[9]) - dir.z;
  A = (float)((float)(v24 * v24) + (float)(v25 * v25)) + (float)(v23 * v23);
  B = (float)((float)((float)(v24 * v17) + (float)(v25 * q.z)) + (float)(v23 * v18)) * 2.0;
  v26 = (float)(A * v19) * 4.0;
  if ( (float)((float)(B * B) - v26) >= 0.0 )
  {
    k = sqrtf((float)(B * B) - v26);
    v28 = *(float *)&clear_value / (float)(A * 2.0);
    v29 = (float)((float)-B - k) * v28;
    if ( v29 < 0.0 )
    {
      v29 = (float)(k - B) * v28;
      if ( v29 < 0.0 )
        return 0;
    }
    if ( v29 > max_distance )
      return 0;
    v21 = cylinder_half_length;
    v30 = (float)((float)((float)((float)((float)(dir.y * v29) + start.y) - p.normal.y) * R[5])
                + (float)((float)((float)((float)(dir.z * v29) + start.z) - p.normal.z) * R[9]))
        + (float)((float)((float)((float)(dir.x * v29) + start.x) - p.normal.x) * R[1]);
    v27 = -cylinder_half_length;
    if ( v30 >= (float)-cylinder_half_length && cylinder_half_length >= v30 )
    {
      *distance = v29;
      return 1;
    }
    if ( v30 < 0.0 )
      goto LABEL_19;
    goto LABEL_18;
  }
  if ( !v20 )
    return 0;
  v27 = cylinder_half_length;
  if ( uv < 0.0 )
    v27 = -cylinder_half_length;
LABEL_19:
  q.x = 0.0;
  *(_QWORD *)&q.elements[1] = (unsigned int)clear_value;
  p.normal.z = 0.0;
  *(_QWORD *)&p.normal.x = *(_QWORD *)&q.x;
  p.d = -v27;
  if ( vostok::math::plane::intersect_ray(&dir, &start, &p, &uv)
    && cylinder_radius > sqrtf(
                           (float)((float)((float)(start.z + (float)(dir.z * uv))
                                         * (float)(start.z + (float)(dir.z * uv)))
                                 + (float)((float)((float)(start.y + (float)(dir.y * uv)) - v27)
                                         * (float)((float)(start.y + (float)(dir.y * uv)) - v27)))
                         + (float)((float)((float)(dir.x * uv) + start.x) * (float)((float)(dir.x * uv) + start.x))) )
  {
    *distance = uv;
    return 1;
  }
  return 0;
}

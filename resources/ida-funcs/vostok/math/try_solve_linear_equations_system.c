char __cdecl vostok::math::try_solve_linear_equations_system(
        const vostok::math::float3 *first,
        const vostok::math::float3 *second,
        const vostok::math::float3 *third,
        const vostok::math::float3 *b,
        vostok::math::float3 *result)
{
  vostok::math::float4x4 *v5; // ecx
  char v6; // al
  float z; // xmm2_4
  float x; // xmm0_4
  float y; // xmm1_4
  vostok::math::float4x4 v10; // [esp+10h] [ebp-94h] BYREF
  vostok::math::float4x4 v11; // [esp+50h] [ebp-54h] BYREF
  vostok::math::float3 v12; // [esp+94h] [ebp-10h]

  qmemcpy(&v10, vostok::math::float4x4::identity(v5, &v11), sizeof(v10));
  *(_QWORD *)&v10.i.x = *(_QWORD *)&first->x;
  v10.i.z = first->z;
  *(_QWORD *)&v10.lines[1].x = *(_QWORD *)&second->x;
  v10.j.z = second->z;
  *(_QWORD *)&v10.lines[2].x = *(_QWORD *)&third->x;
  v10.k.z = third->z;
  v6 = vostok::math::float4x4::try_invert(&v10, &v11);
  if ( v6 )
  {
    z = b->z;
    x = b->x;
    y = b->y;
    v12.x = (float)((float)(b->x * v11.i.x) + (float)(z * v11.i.z)) + (float)(y * v11.i.y);
    v12.y = (float)((float)(x * v11.j.x) + (float)(y * v11.j.y)) + (float)(z * v11.j.z);
    v12.z = (float)((float)(x * v11.k.x) + (float)(y * v11.k.y)) + (float)(z * v11.k.z);
    *result = v12;
    return 1;
  }
  return v6;
}

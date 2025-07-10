char __cdecl vostok::math::try_solve_linear_equations_system(
        const vostok::math::float3 *first,
        const vostok::math::float3 *second,
        const vostok::math::float3 *third,
        const vostok::math::float3 *b,
        vostok::math::float3 *result)
{
  vostok::math::float4x4 *v5; // eax
  float z; // edx
  vostok::math::float4x4 *v7; // esi
  __int64 v8; // xmm0_8
  float v9; // eax
  float v10; // ecx
  __int64 v11; // xmm0_8
  char v12; // al
  float v13; // xmm2_4
  float y; // xmm1_4
  float v15; // ecx
  __int64 v16; // [esp+14h] [ebp-8Ch]
  vostok::math::float4x4 inverted; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 m; // [esp+60h] [ebp-40h] BYREF

  v5 = vostok::math::float4x4::identity(&inverted);
  z = third->z;
  v7 = v5;
  v8 = *(_QWORD *)&first->x;
  v9 = first->z;
  qmemcpy((void *)&m, v7, sizeof(m));
  v10 = second->z;
  m.i.z = v9;
  *(_QWORD *)&m.i.x = v8;
  *(_QWORD *)&m.lines[1].x = *(_QWORD *)&second->x;
  v11 = *(_QWORD *)&third->x;
  m.j.z = v10;
  *(_QWORD *)&m.lines[2].x = v11;
  m.k.z = z;
  v12 = vostok::math::float4x4::try_invert(&m, &inverted);
  if ( v12 )
  {
    v13 = b->z;
    y = b->y;
    *(float *)&v16 = (float)((float)(b->x * inverted.i.x) + (float)(v13 * inverted.i.z)) + (float)(y * inverted.i.y);
    v15 = (float)((float)(b->x * inverted.k.x) + (float)(y * inverted.k.y)) + (float)(v13 * inverted.k.z);
    *((float *)&v16 + 1) = (float)((float)(b->x * inverted.j.x) + (float)(y * inverted.j.y))
                         + (float)(v13 * inverted.j.z);
    *(_QWORD *)&result->x = v16;
    result->z = v15;
    return 1;
  }
  return v12;
}

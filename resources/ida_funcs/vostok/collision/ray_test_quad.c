bool __usercall vostok::collision::ray_test_quad@<al>(
        const vostok::math::float3 *v_lt@<ecx>,
        const vostok::math::float3 *v_rt@<esi>,
        const vostok::math::float3 *v_lb@<eax>,
        float *range@<edi>,
        const vostok::math::float3 *v_rb,
        const vostok::math::float3 *pos,
        const vostok::math::float3 *dir,
        float max_distance)
{
  __int64 v8; // xmm0_8
  float z; // eax
  float v10; // edx
  __int64 v11; // xmm0_8
  float v12; // ecx
  bool result; // al
  __int64 v14; // xmm0_8
  float v15; // ecx
  __int64 v16; // xmm0_8
  vostok::math::float3 v2; // [esp+10h] [ebp-24h] BYREF
  vostok::math::float3 v1; // [esp+1Ch] [ebp-18h] BYREF
  vostok::math::float3 v0; // [esp+28h] [ebp-Ch] BYREF

  v8 = *(_QWORD *)&v_lb->x;
  z = v_lb->z;
  v10 = v_rt->z;
  *(_QWORD *)&v0.x = v8;
  v11 = *(_QWORD *)&v_lt->x;
  v12 = v_lt->z;
  v0.z = z;
  v1.z = v12;
  v2.z = v10;
  *(_QWORD *)&v1.x = v11;
  *(_QWORD *)&v2.x = *(_QWORD *)&v_rt->x;
  result = vostok::collision::test_triangle(&v0, &v1, &v2, pos, dir, max_distance, range);
  if ( !result )
  {
    v14 = *(_QWORD *)&v_rt->x;
    v1.z = v_rt->z;
    v15 = v_rb->z;
    *(_QWORD *)&v1.x = v14;
    v16 = *(_QWORD *)&v_rb->x;
    v2.z = v15;
    *(_QWORD *)&v2.x = v16;
    return vostok::collision::test_triangle(&v0, &v1, &v2, pos, dir, max_distance, range);
  }
  return result;
}

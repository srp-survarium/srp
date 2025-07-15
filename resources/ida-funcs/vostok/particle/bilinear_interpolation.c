// local variable allocation has failed, the output may be wrong!
vostok::math::float4_pod *__cdecl vostok::particle::bilinear_interpolation<vostok::math::float4_pod>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod a0,
        vostok::math::float4_pod b0,
        vostok::math::float4_pod a1,
        vostok::math::float4_pod b1,
        __int64 alpha0)
{
  vostok::math::float4_pod *v6; // eax
  vostok::math::float4_pod *v7; // ebx
  vostok::math::float4_pod *v8; // esi
  vostok::math::float4_pod *v9; // eax
  __int64 v10; // [esp-20h] [ebp-54h]
  __int64 v11; // [esp-20h] [ebp-54h]
  vostok::math::float4_pod v14; // [esp-10h] [ebp-44h]
  __int64 v15; // [esp-8h] [ebp-3Ch]
  vostok::math::float4_pod v17; // [esp+10h] [ebp-24h] BYREF
  vostok::math::float4_pod v18; // [esp+20h] [ebp-14h] BYREF

  v15 = *(_QWORD *)&a1.x;
  v10 = *(_QWORD *)&a0.elements[2];
  v6 = vostok::math::linear_interpolation<vostok::math::float4_pod>(
         &v18,
         a0.x,
         *(vostok::math::float4_pod *)((char *)&b0 - 8),
         *(vostok::math::float4_pod *)((char *)&b0 + 8));
  v11 = *(_QWORD *)&a1.elements[2];
  v7 = v6;
  v14 = *vostok::math::linear_interpolation<vostok::math::float4_pod>(
           &v17,
           a0.x,
           *(vostok::math::float4_pod *)((char *)&b1 - 8),
           *(vostok::math::float4_pod *)((char *)&b1 + 8));
  v8 = vostok::math::linear_interpolation<vostok::math::float4_pod>(&v17, a0.y, *v7, v14);
  v9 = result;
  result->x = v8->x;
  v8 = (vostok::math::float4_pod *)((char *)v8 + 4);
  result->y = v8->x;
  *(_QWORD *)&result->elements[2] = *(_QWORD *)&v8->elements[1];
  return v9;
}

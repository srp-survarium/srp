vostok::math::float3 *__fastcall stlp_std::accumulate<vostok::math::float3 const *,vostok::math::float3>(
        const vostok::math::float3 *__first,
        const vostok::math::float3 *__last,
        vostok::math::float3 _Init,
        float _Init_8)
{
  vostok::math::float3 *result; // eax
  __int64 v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-4h]

  for ( result = (vostok::math::float3 *)LODWORD(_Init.x); __first != __last; _Init_8 = v6 )
  {
    *(float *)&v5 = __first->x + _Init.y;
    *((float *)&v5 + 1) = __first->y + _Init.z;
    v6 = __first->z + _Init_8;
    ++__first;
    *(_QWORD *)&_Init.elements[1] = v5;
  }
  *(_QWORD *)LODWORD(_Init.x) = *(_QWORD *)&_Init.elements[1];
  *(float *)(LODWORD(_Init.x) + 8) = _Init_8;
  return result;
}

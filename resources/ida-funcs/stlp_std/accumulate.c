vostok::math::float3 *__usercall stlp_std::accumulate<vostok::math::float3 const *,vostok::math::float3>@<eax>(
        const vostok::math::float3 *__first@<eax>,
        const vostok::math::float3 *__last,
        vostok::math::float3 _Init,
        float a4)
{
  vostok::math::float3 *result; // eax
  __int64 v5; // [esp+8h] [ebp-Ch]

  while ( __first != (const vostok::math::float3 *)LODWORD(_Init.x) )
  {
    *(float *)&v5 = __first->x + _Init.y;
    *((float *)&v5 + 1) = __first->y + _Init.z;
    *(_QWORD *)&_Init.elements[1] = v5;
    a4 = __first->z + a4;
    ++__first;
  }
  result = (vostok::math::float3 *)__last;
  *(_QWORD *)&__last->x = *(_QWORD *)&_Init.elements[1];
  __last->z = a4;
  return result;
}

vostok::math::float4x4 *__usercall stlp_std::priv::__uninitialized_fill_n<vostok::math::float4x4 *,unsigned int,vostok::math::float4x4>@<eax>(
        unsigned int __n@<eax>,
        vostok::math::float4x4 *__first,
        const vostok::math::float4x4 *__x)
{
  vostok::math::float4x4 *v3; // ebx
  vostok::math::float4x4 *result; // eax
  int i; // edx

  v3 = __first;
  result = &__first[__n];
  for ( i = result - __first; i > 0; ++v3 )
  {
    if ( v3 )
      qmemcpy((void *)v3, __x, sizeof(vostok::math::float4x4));
    --i;
  }
  return result;
}

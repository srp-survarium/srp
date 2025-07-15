vostok::math::float4x4 *__usercall vostok::math::create_scale@<eax>(
        const vostok::math::float3 *scale@<edi>,
        int a2@<esi>)
{
  const vostok::math::float4x4 *v2; // xmm0_4
  vostok::math::float4x4 *result; // eax

  memset((unsigned __int8 *)a2, 0, 0x40u);
  v2 = clear_value;
  *(float *)a2 = scale->x;
  *(float *)(a2 + 20) = scale->y;
  *(_DWORD *)(a2 + 60) = v2;
  result = (vostok::math::float4x4 *)a2;
  *(float *)(a2 + 40) = scale->z;
  return result;
}

vostok::math::float4x4 *__usercall vostok::math::create_uniform_scale@<eax>(
        float *scale@<eax>,
        vostok::math::float4x4 *a2@<ecx>)
{
  vostok::math::float3 v4; // [esp+0h] [ebp-Ch] BYREF

  v4.x = *scale;
  v4.y = v4.x;
  v4.z = v4.x;
  vostok::math::create_scale(&v4, a2);
  return a2;
}

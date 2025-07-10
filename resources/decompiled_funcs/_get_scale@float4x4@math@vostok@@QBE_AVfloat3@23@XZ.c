vostok::math::float3 *__usercall vostok::math::float4x4::get_scale@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        float *a2@<edi>,
        float *a3@<esi>)
{
  *a2 = sqrtf((float)((float)(a3[1] * a3[1]) + (float)(a3[2] * a3[2])) + (float)(*a3 * *a3));
  a2[1] = sqrtf((float)((float)(a3[5] * a3[5]) + (float)(a3[6] * a3[6])) + (float)(a3[4] * a3[4]));
  a2[2] = sqrtf((float)((float)(a3[10] * a3[10]) + (float)(a3[8] * a3[8])) + (float)(a3[9] * a3[9]));
  return (vostok::math::float3 *)a2;
}

int __userpurge vostok::math::float2::float2@<eax>(
        vostok::math::float2 *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        float fY,
        float a5)
{
  *(_DWORD *)result = a3;
  *(float *)(result + 4) = fY;
  return result;
}


void __usercall vostok::math::float2::float2(vostok::math::float2 *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm0_4

  v2 = SNaN;
  *a2 = SNaN;
  a2[1] = v2;
}

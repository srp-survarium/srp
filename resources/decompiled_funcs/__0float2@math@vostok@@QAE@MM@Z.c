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

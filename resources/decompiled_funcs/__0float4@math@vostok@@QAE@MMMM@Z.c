int __userpurge vostok::math::float4::float4@<eax>(
        vostok::math::float4 *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        float other_y,
        float other_z,
        float other_w,
        float a7)
{
  *(_DWORD *)result = a3;
  *(float *)(result + 4) = other_y;
  *(float *)(result + 8) = other_z;
  *(float *)(result + 12) = other_w;
  return result;
}

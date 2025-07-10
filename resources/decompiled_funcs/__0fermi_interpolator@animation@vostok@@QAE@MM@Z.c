int __userpurge vostok::animation::fermi_interpolator::fermi_interpolator@<eax>(
        vostok::animation::fermi_interpolator *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        float epsilon,
        float a5)
{
  *(_DWORD *)(result + 4) = a3;
  *(_DWORD *)result = &vostok::animation::fermi_interpolator::`vftable';
  *(float *)(result + 8) = epsilon;
  return result;
}

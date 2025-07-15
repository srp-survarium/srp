float __usercall dDOT@<xmm0>(const float *a@<ecx>, const float *b@<eax>)
{
  return (float)((float)(a[2] * b[2]) + (float)(a[1] * b[1])) + (float)(*a * *b);
}

float __usercall dDOT41@<xmm0>(const float *a@<ecx>, const float *b@<eax>)
{
  return (float)((float)(a[8] * b[2]) + (float)(a[4] * b[1])) + (float)(*a * *b);
}

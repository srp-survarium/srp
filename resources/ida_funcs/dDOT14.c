float __usercall dDOT14@<xmm0>(const float *a@<ecx>, const float *b@<eax>)
{
  return (float)((float)(b[8] * a[2]) + (float)(a[1] * b[4])) + (float)(*a * *b);
}

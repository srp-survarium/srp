float __usercall dDOT44@<xmm0>(const float *a@<ecx>, const float *b@<eax>)
{
  return (float)((float)(a[8] * b[8]) + (float)(a[4] * b[4])) + (float)(*a * *b);
}

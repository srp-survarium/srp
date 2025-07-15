int __usercall Lerp_btVector3_@<eax>(float *a1@<edx>, float *a2@<ecx>, float a3@<xmm6>, int a4)
{
  int result; // eax
  float v5; // xmm4_4
  float v6; // xmm5_4

  result = a4;
  v5 = a1[1] + (float)((float)(a2[1] - a1[1]) * a3);
  v6 = a1[2] + (float)((float)(a2[2] - a1[2]) * a3);
  *(float *)a4 = *a1 + (float)((float)(*a2 - *a1) * a3);
  *(float *)(a4 + 4) = v5;
  *(float *)(a4 + 8) = v6;
  *(_DWORD *)(a4 + 12) = 0;
  return result;
}

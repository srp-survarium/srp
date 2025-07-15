int __usercall btDbvtAabbMm::FromCR@<eax>(int result@<eax>, float *a2@<ecx>, float a3@<xmm4>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = *a2;
  v4 = a2[1];
  v5 = a2[2];
  *(float *)result = *a2 - a3;
  *(float *)(result + 4) = v4 - a3;
  *(float *)(result + 8) = v5 - a3;
  *(_DWORD *)(result + 12) = 0;
  *(float *)(result + 16) = v3 + a3;
  *(float *)(result + 20) = v4 + a3;
  *(float *)(result + 24) = v5 + a3;
  *(_DWORD *)(result + 28) = 0;
  return result;
}

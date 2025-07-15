int __usercall btRotationalLimitMotor::testLimitValue@<eax>(
        btRotationalLimitMotor *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>)
{
  float v3; // xmm1_4
  float v4; // xmm2_4

  v3 = *(float *)a2;
  v4 = *(float *)(a2 + 4);
  if ( *(float *)a2 > v4 )
    goto LABEL_6;
  if ( v3 > a3 )
  {
    *(_DWORD *)(a2 + 56) = 1;
    *(float *)(a2 + 48) = a3 - v3;
    return 1;
  }
  if ( a3 <= v4 )
  {
LABEL_6:
    *(_DWORD *)(a2 + 56) = 0;
    return 0;
  }
  else
  {
    *(_DWORD *)(a2 + 56) = 2;
    *(float *)(a2 + 48) = a3 - v4;
    return 2;
  }
}

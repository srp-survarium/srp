btMatrix3x3 *__usercall Mul@<eax>(const btMatrix3x3 *a@<eax>, float *b, float a3)
{
  float *v3; // ecx
  float *v4; // eax
  int v5; // edx
  float v6; // xmm0_4
  _DWORD *v7; // edi
  float v9; // [esp+Ch] [ebp-Ch]

  v3 = b;
  v4 = &a->m_el[0].mVec128.m128_f32[2];
  v5 = 3;
  do
  {
    v9 = *(v4 - 1) * a3;
    v6 = *v4 * a3;
    *v3 = *(v4 - 2) * a3;
    v3[1] = v9;
    v3[2] = v6;
    v7 = v3 + 3;
    v4 += 4;
    v3 += 4;
    --v5;
    *v7 = 0;
  }
  while ( v5 );
  return (btMatrix3x3 *)b;
}

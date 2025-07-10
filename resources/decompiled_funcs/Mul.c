_QWORD *__usercall Mul@<eax>(_QWORD *result@<eax>, float *a2@<ecx>, float a3@<xmm0>)
{
  float v3; // xmm1_4
  unsigned int v4; // xmm2_4
  __int64 v5; // [esp+0h] [ebp-10h]
  unsigned int v6; // [esp+8h] [ebp-8h]

  *(float *)&v5 = *a2 * a3;
  *((float *)&v5 + 1) = a2[1] * a3;
  v3 = a2[2];
  *result = v5;
  result[1] = COERCE_UNSIGNED_INT(v3 * a3);
  *(float *)&v5 = a2[4] * a3;
  *((float *)&v5 + 1) = a2[5] * a3;
  *(float *)&v6 = a2[6] * a3;
  result[2] = v5;
  result[3] = v6;
  *(float *)&v5 = a2[8] * a3;
  *((float *)&v5 + 1) = a2[9] * a3;
  *(float *)&v4 = a2[10] * a3;
  result[4] = v5;
  result[5] = v4;
  return result;
}

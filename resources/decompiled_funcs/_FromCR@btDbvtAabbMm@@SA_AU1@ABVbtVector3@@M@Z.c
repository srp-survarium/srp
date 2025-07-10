struct btDbvtAabbMm *__usercall btDbvtAabbMm::FromCR@<eax>(
        struct btDbvtAabbMm *result@<eax>,
        float *a2@<ecx>,
        float a3@<xmm0>)
{
  float v3; // xmm1_4
  unsigned int v4; // xmm2_4
  unsigned __int64 v5; // [esp+0h] [ebp-10h]

  *(float *)&v5 = *a2 - a3;
  *((float *)&v5 + 1) = a2[1] - a3;
  v3 = a2[2];
  result->mi.mVec128.m128_u64[0] = v5;
  result->mi.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v3 - a3);
  *(float *)&v5 = *a2 + a3;
  *((float *)&v5 + 1) = a2[1] + a3;
  *(float *)&v4 = a2[2] + a3;
  result->mx.mVec128.m128_u64[0] = v5;
  result->mx.mVec128.m128_u64[1] = v4;
  return result;
}

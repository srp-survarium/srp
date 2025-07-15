btSparseSdf<3>::IntFrac *__usercall btSparseSdf<3>::Decompose@<eax>(
        btSparseSdf<3>::IntFrac *result@<eax>,
        float a2@<xmm1>)
{
  float v2; // xmm1_4
  int v3; // esi
  float v4; // xmm0_4
  int v5; // ecx
  float v6; // xmm0_4

  v2 = a2 * 0.33333334;
  if ( v2 >= 0.0 )
    v3 = 0;
  else
    v3 = (int)(float)(s_bm_current_air_resistance - v2);
  v4 = (float)v3 + v2;
  v5 = (int)v4;
  v6 = (float)(v4 - (float)(int)v4) * 3.0;
  result->i = (int)v6;
  result->f = v6 - (float)(int)v6;
  result->b = v5 - v3;
  return result;
}

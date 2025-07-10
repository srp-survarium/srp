double __usercall compute_gaussian_value@<st0>(float a1@<xmm1>, float a2@<xmm2>)
{
  double v4; // st7
  float v6; // [esp+4h] [ebp-Ch]

  v4 = expf(v6);
  sqrtf((float)(a1 * a1) * 6.2831855);
  return 1.0 / v4 * (float)((float)-(float)(a2 * a2) / (float)((float)(a1 * a1) * 2.0));
}

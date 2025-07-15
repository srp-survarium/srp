void __usercall Wm4::Vector2<float>::Normalize(Wm4::Vector2<float> *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = a2[1];
  v3 = *a2;
  v4 = fsqrt((float)(v3 * v3) + (float)(v2 * v2));
  if ( v4 <= 0.000001 )
  {
    *a2 = 0.0;
    a2[1] = 0.0;
  }
  else
  {
    v5 = v2 * (float)(s_bm_current_air_resistance / v4);
    *a2 = v3 * (float)(s_bm_current_air_resistance / v4);
    a2[1] = v5;
  }
}

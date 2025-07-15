void __usercall checkMonotonic(float *x1@<ecx>, float *x2@<eax>)
{
  float v2; // xmm4_4
  bool v3; // cc
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float v11; // xmm0_4

  v2 = s_bm_current_air_resistance;
  v3 = *x1 >= 0.0;
  v4 = s_bm_current_air_resistance - *x2;
  *x2 = v4;
  if ( !v3 )
    *x1 = 0.0;
  if ( v4 < 0.0 )
    *x2 = 0.0;
  v5 = *x1;
  if ( *x1 > v2 || *x2 > v2 )
  {
    v6 = *x2;
    v7 = v5 - 2.0;
    v8 = sMachineTolerance;
    if ( (float)((float)((float)((float)((float)((float)(v5 - 2.0) + v6) * v5) + (float)((float)(*x2 - 2.0) * v6)) + v2)
               + sMachineTolerance) > 0.0 )
    {
      if ( (float)(v5 + sMachineTolerance) >= 1.3333334 )
      {
        *x1 = 1.3333334 - sMachineTolerance;
        *x2 = 0.33333334 - v8;
      }
      else
      {
        v9 = fsqrt((float)(v7 * v7) - (float)((float)((float)(v5 - v2) * (float)(v5 - v2)) * 4.0));
        v10 = (float)(v9 - v7) * 0.5;
        if ( (float)(v6 + sMachineTolerance) <= v10 )
        {
          v11 = sMachineTolerance + (float)((float)(COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) - v9) * 0.5);
          if ( v11 > v6 )
            *x2 = v11;
        }
        else
        {
          *x2 = v10 - sMachineTolerance;
        }
      }
    }
  }
  *x2 = v2 - *x2;
}

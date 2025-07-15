int __usercall ag_zeroin2@<xmm0>(ag_polynomial *pars@<edx>, float a, float b, float fa, float fb)
{
  float v5; // xmm7_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  int deg; // eax
  float i; // xmm0_4
  float v22; // [esp+0h] [ebp-20h]
  float v23; // [esp+8h] [ebp-18h]
  float v24; // [esp+Ch] [ebp-14h]
  float v25; // [esp+10h] [ebp-10h]
  float v26; // [esp+18h] [ebp-8h]
  float v27; // [esp+1Ch] [ebp-4h]

  v5 = retry_to_increase_quality_period_sec;
label1:
  v6 = fa;
  v24 = a;
  v23 = fa;
  v27 = b - a;
  v25 = b - a;
  while ( 1 )
  {
    if ( COERCE_FLOAT(LODWORD(fb) & _mask__AbsFloat_) > COERCE_FLOAT(LODWORD(v6) & _mask__AbsFloat_) )
    {
      v7 = v24;
      a = b;
      v24 = b;
      b = v7;
      fa = fb;
      fb = v6;
      v23 = fa;
    }
    v8 = (float)(v24 - b) * 0.5;
    v9 = (float)(COERCE_FLOAT(LODWORD(b) & _mask__AbsFloat_) * sMachineTolerance) * v5;
    if ( COERCE_FLOAT(LODWORD(v8) & _mask__AbsFloat_) <= v9 || fb == 0.0 )
      return LODWORD(b);
    if ( v9 > COERCE_FLOAT(LODWORD(v25) & _mask__AbsFloat_)
      || COERCE_FLOAT(LODWORD(fb) & _mask__AbsFloat_) >= COERCE_FLOAT(LODWORD(fa) & _mask__AbsFloat_) )
    {
      v27 = (float)(v24 - b) * 0.5;
      v25 = v27;
    }
    else
    {
      v10 = fb / fa;
      if ( a == v24 )
      {
        v11 = (float)(v10 * v8) * v5;
        v12 = s_bm_current_air_resistance - v10;
      }
      else
      {
        v13 = (float)(s_bm_current_air_resistance / v23) * fa;
        v14 = (float)(s_bm_current_air_resistance / v23) * fb;
        v15 = (float)((float)(v13 - v14) * v13) * (float)((float)(v24 - b) * 0.5);
        v16 = v14 - s_bm_current_air_resistance;
        v17 = v15 * v5;
        v5 = retry_to_increase_quality_period_sec;
        v11 = (float)(v17 - (float)((float)(b - a) * v16)) * v10;
        v12 = (float)((float)(v13 - s_bm_current_air_resistance) * (float)(v10 - s_bm_current_air_resistance)) * v16;
        v8 = (float)(v24 - b) * 0.5;
      }
      v26 = v12;
      if ( v11 <= 0.0 )
      {
        LODWORD(v11) ^= _mask__NegFloat_;
      }
      else
      {
        LODWORD(v12) ^= _mask__NegFloat_;
        v26 = v12;
      }
      v22 = v25;
      v25 = v27;
      if ( v12 * v8 * 3.0 - COERCE_FLOAT(COERCE_UNSIGNED_INT(v26 * v9) & _mask__AbsFloat_) <= (float)(v11 * v5)
        || COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v26 * v22 * 0.5) & _mask__AbsDouble_) <= v11 )
      {
        v18 = (float)(v24 - b) * 0.5;
        v25 = v18;
      }
      else
      {
        v18 = v11 / v26;
      }
      v8 = (float)(v24 - b) * 0.5;
      v27 = v18;
    }
    fa = fb;
    a = b;
    if ( COERCE_FLOAT(LODWORD(v27) & _mask__AbsFloat_) > v9 )
    {
      v9 = v27;
LABEL_24:
      b = v9 + b;
      goto LABEL_26;
    }
    if ( v8 > 0.0 )
      goto LABEL_24;
    b = b - v9;
LABEL_26:
    deg = pars->deg;
    for ( i = pars->p[deg]; --deg >= 0; i = (float)(i * b) + pars->p[deg] )
      ;
    v6 = v23;
    fb = i;
    if ( (float)((float)(v23 / COERCE_FLOAT(LODWORD(v23) & _mask__AbsFloat_)) * i) > 0.0 )
      goto label1;
  }
}

void __usercall engineBezierCreate(vostok::animation::EtCurve *animCurve@<edx>, float *x@<edi>, float *y@<esi>)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // [esp+0h] [ebp-1Ch]
  float v19; // [esp+4h] [ebp-18h]
  float v20; // [esp+8h] [ebp-14h]
  float v21; // [esp+10h] [ebp-Ch]
  float v22; // [esp+14h] [ebp-8h] BYREF
  float v23; // [esp+18h] [ebp-4h] BYREF

  v3 = s_bm_current_air_resistance;
  if ( !sInited )
  {
    v4 = s_bm_current_air_resistance;
    do
      v4 = v4 * 0.5;
    while ( (float)(v4 + s_bm_current_air_resistance) > s_bm_current_air_resistance );
    sMachineTolerance = v4 * 2.0;
    sInited = 1;
  }
  if ( animCurve )
  {
    v5 = *x;
    v18 = x[3];
    v6 = v18 - *x;
    v20 = *x;
    if ( v6 != 0.0 )
    {
      v8 = (float)(x[2] - v5) * (float)(s_bm_current_air_resistance / v6);
      v23 = (float)(x[1] - v5) * (float)(s_bm_current_air_resistance / v6);
      v7 = v23;
      v22 = v8;
      animCurve->isLinear = v23 == 0.33333334 && v8 == 0.66666669;
      v21 = v7;
      v19 = v8;
      if ( v7 < 0.0 )
      {
        v7 = 0.0;
        v23 = 0.0;
      }
      if ( v8 > v3 )
      {
        v8 = v3;
        v22 = v3;
      }
      if ( v7 > v3 || v8 < -1.0 )
      {
        checkMonotonic(&v23, &v22);
        v7 = v23;
        v8 = v22;
        v5 = v20;
        v3 = s_bm_current_air_resistance;
      }
      if ( v7 != v21 )
      {
        x[1] = (float)(v7 * v6) + v5;
        if ( v21 != 0.0 )
          y[1] = (float)((float)((float)(y[1] - *y) / v21) * v7) + *y;
      }
      if ( v8 != v19 )
      {
        x[2] = (float)(v8 * v6) + v5;
        if ( v19 != v3 )
          y[2] = y[3] - (float)((float)((float)(y[3] - y[2]) * (float)(v3 - v8)) / (float)(v3 - v19));
      }
      v9 = y[3];
      animCurve->fX1 = v5;
      animCurve->fX4 = v18;
      v10 = v3 - v8;
      v11 = v8;
      v12 = y[2];
      v13 = v11 - v7;
      v14 = v13 - v7;
      animCurve->fCoeff[1] = v7 * 3.0;
      v15 = y[1];
      animCurve->fCoeff[3] = (float)(v10 - v13) - v14;
      animCurve->fCoeff[2] = v14 * 3.0;
      animCurve->fCoeff[0] = 0.0;
      v16 = *y;
      v17 = v15 - *y;
      animCurve->fPolyY[3] = (float)((float)(v9 - v12) - (float)(v12 - v15)) - (float)((float)(v12 - v15) - v17);
      animCurve->fPolyY[2] = (float)((float)(v12 - v15) - v17) * 3.0;
      animCurve->fPolyY[1] = v17 * 3.0;
      animCurve->fPolyY[0] = v16;
    }
  }
}

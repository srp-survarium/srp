float __usercall engineBezierEvaluate@<xmm0>(vostok::animation::EtCurve *animCurve@<esi>, float a2@<xmm1>)
{
  float v3; // xmm1_4
  float fX4; // xmm0_4
  float Roots[5]; // [esp+18h] [ebp-24h] BYREF
  float Poly[4]; // [esp+2Ch] [ebp-10h] BYREF

  if ( !animCurve )
    return 0.0;
  if ( animCurve->fX1 == a2 )
  {
    v3 = 0.0;
  }
  else
  {
    fX4 = animCurve->fX4;
    if ( fX4 == a2 )
      v3 = s_bm_current_air_resistance;
    else
      v3 = (float)(a2 - animCurve->fX1) / (float)(fX4 - animCurve->fX1);
  }
  if ( !animCurve->isLinear )
  {
    Poly[3] = animCurve->fCoeff[3];
    Poly[2] = animCurve->fCoeff[2];
    Poly[1] = animCurve->fCoeff[1];
    Poly[0] = animCurve->fCoeff[0] - v3;
    if ( polyZeroes(Poly, 3, 0.0, 1, 1.0, 1, Roots) == 1 )
      v3 = Roots[0];
    else
      v3 = 0.0;
  }
  return (float)((float)((float)((float)((float)(animCurve->fPolyY[3] * v3) + animCurve->fPolyY[2]) * v3)
                       + animCurve->fPolyY[1])
               * v3)
       + animCurve->fPolyY[0];
}

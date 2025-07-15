__int64 __usercall evaluateInfinities@<xmm0>(vostok::animation::EtCurve *animCurve@<eax>, float time, bool evalPre)
{
  vostok::animation::EtKey *M_start; // eax
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  __int64 result; // xmm0_8
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  vostok::animation::EtInfinityType preInfinity; // eax
  float v13; // xmm0_4
  vostok::animation::EtKey *v14; // esi
  float inTanX; // xmm2_4
  float v16; // xmm1_4
  vostok::animation::EtInfinityType postInfinity; // eax
  vostok::animation::EtKey *M_finish; // esi
  float outTanX; // xmm2_4
  __int64 v20; // xmm1_8
  double timea; // [esp+0h] [ebp-1Ch]
  double timeb; // [esp+0h] [ebp-1Ch]
  float v23; // [esp+8h] [ebp-14h] BYREF
  float v24; // [esp+Ch] [ebp-10h]
  float v25; // [esp+10h] [ebp-Ch]
  float v26; // [esp+14h] [ebp-8h] BYREF
  float v27; // [esp+18h] [ebp-4h]

  if ( !animCurve )
    return 0;
  M_start = animCurve->keyList._M_impl._M_start;
  if ( M_start == animCurve->keyList._M_impl._M_finish )
    return 0;
  v5 = M_start->time;
  v6 = animCurve->keyList._M_impl._M_finish[-1].time;
  v7 = v6 - M_start->time;
  v24 = M_start->time;
  v25 = v6;
  v23 = v7;
  if ( v7 == 0.0 )
    return LODWORD(animCurve->keyList._M_impl._M_start->value);
  LODWORD(timea) = &v26;
  if ( time <= v6 )
    v9 = time - v5;
  else
    v9 = time - v6;
  v27 = fabs(modf(v9 / v7, timea));
  v10 = v27 * v23;
  v11 = COERCE_FLOAT(LODWORD(v26) & _mask__AbsFloat_) + s_bm_current_air_resistance;
  v27 = v27 * v23;
  v26 = v11;
  if ( evalPre )
  {
    preInfinity = animCurve->preInfinity;
    if ( preInfinity != kInfinityOscillate )
    {
      if ( preInfinity != kInfinityCycle && preInfinity != kInfinityCycleRelative )
      {
        if ( preInfinity == kInfinityLinear )
        {
          v14 = animCurve->keyList._M_impl._M_start;
          inTanX = v14->inTanX;
          result = LODWORD(v14->value);
          if ( inTanX == 0.0 )
            return result;
          v16 = (float)((float)(v24 - time) * v14->inTanY) / inTanX;
          goto LABEL_17;
        }
        goto LABEL_29;
      }
      v13 = v25 - v10;
      goto LABEL_22;
    }
    LODWORD(timeb) = &v23;
    if ( modf(v11 * 0.5, timeb) == 0.0 )
      goto LABEL_11;
    goto LABEL_21;
  }
  postInfinity = animCurve->postInfinity;
  switch ( postInfinity )
  {
    case kInfinityOscillate:
      LODWORD(timeb) = &v23;
      if ( modf(v11 * 0.5, timeb) != 0.0 )
      {
LABEL_11:
        v13 = v25 - v27;
LABEL_22:
        v27 = v13;
        break;
      }
LABEL_21:
      v13 = v27 + v24;
      goto LABEL_22;
    case kInfinityCycle:
    case kInfinityCycleRelative:
      v27 = v10 + v24;
      break;
    case kInfinityLinear:
      M_finish = animCurve->keyList._M_impl._M_finish;
      outTanX = M_finish[-1].outTanX;
      result = LODWORD(M_finish[-1].value);
      if ( outTanX != 0.0 )
      {
        v20 = LODWORD(time);
        *(float *)&v20 = (float)((float)((float)(time - v25) * M_finish[-1].outTanY) / outTanX) + *(float *)&result;
        return v20;
      }
      return result;
  }
LABEL_29:
  v24 = vostok::animation::engineAnimEvaluate(animCurve, v27);
  if ( evalPre )
  {
    if ( animCurve->preInfinity == kInfinityCycleRelative )
    {
      v16 = (float)(animCurve->keyList._M_impl._M_finish[-1].value - animCurve->keyList._M_impl._M_start->value) * v26;
      result = LODWORD(v24);
LABEL_17:
      *(float *)&result = *(float *)&result - v16;
      return result;
    }
  }
  else if ( animCurve->postInfinity == kInfinityCycleRelative )
  {
    result = LODWORD(animCurve->keyList._M_impl._M_finish[-1].value);
    *(float *)&result = (float)((float)(*(float *)&result - animCurve->keyList._M_impl._M_start->value) * v26) + v24;
    return result;
  }
  return LODWORD(v24);
}

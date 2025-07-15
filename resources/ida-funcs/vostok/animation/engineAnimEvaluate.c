double __cdecl vostok::animation::engineAnimEvaluate(vostok::animation::EtCurve *animCurve, float time)
{
  int v2; // edi
  vostok::animation::EtKey *M_start; // eax
  float v4; // xmm3_4
  vostok::animation::EtKey *M_finish; // esi
  int lastIndex; // esi
  vostok::animation::EtKey *v8; // ecx
  int v9; // esi
  int v10; // eax
  vostok::animation::EtKey *v11; // edx
  vostok::animation::EtKey *v12; // ecx
  float outTanX; // xmm0_4
  float v14; // xmm0_4
  char v15; // al
  vostok::animation::EtKey *v16; // eax
  float outTanY; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm5_4
  float *p_time; // edi
  bool v21; // zf
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm6_4
  float v33; // xmm1_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm0_4
  vostok::animation::EtKey *lastKey; // eax
  char v39; // [esp+1Bh] [ebp-2Dh]
  vostok::animation::EtKey *v40; // [esp+1Ch] [ebp-2Ch]
  int v41; // [esp+20h] [ebp-28h] BYREF
  float v42[2]; // [esp+28h] [ebp-20h] BYREF
  float v43; // [esp+30h] [ebp-18h]
  float v44; // [esp+34h] [ebp-14h]
  float v45[2]; // [esp+38h] [ebp-10h] BYREF
  float v46; // [esp+40h] [ebp-8h]
  float v47; // [esp+44h] [ebp-4h]

  v2 = -33698355;
  v39 = 0;
  v40 = 0;
  v41 = -33698355;
  if ( !animCurve )
    return 0.0;
  M_start = animCurve->keyList._M_impl._M_start;
  if ( M_start == animCurve->keyList._M_impl._M_finish )
    return 0.0;
  v4 = time;
  if ( M_start->time <= time )
  {
    M_finish = animCurve->keyList._M_impl._M_finish;
    if ( time > M_finish[-1].time )
    {
      if ( animCurve->postInfinity )
        return COERCE_FLOAT(evaluateInfinities(animCurve, time, 0));
      return M_finish[-1].value;
    }
    if ( animCurve->isStatic )
      return M_start->value;
    if ( animCurve->lastKey )
    {
      lastIndex = animCurve->lastIndex;
      if ( lastIndex >= animCurve->keyList._M_impl._M_finish - animCurve->keyList._M_impl._M_start - 1
        || time <= animCurve->lastKey->time )
      {
        if ( lastIndex > 0 && animCurve->lastKey->time > time )
        {
          v8 = &animCurve->keyList._M_impl._M_start[lastIndex - 1];
          v14 = v8->time;
          v40 = v8;
          if ( time > v8->time )
          {
            v2 = animCurve->lastIndex;
            v41 = v2;
            v39 = 1;
          }
          if ( time == v14 )
          {
            v9 = lastIndex - 1;
            goto LABEL_17;
          }
          if ( v39 )
          {
LABEL_20:
            v10 = v2 - 1;
            if ( animCurve->lastInterval != v2 - 1 )
            {
              v11 = animCurve->keyList._M_impl._M_start;
              animCurve->lastInterval = v10;
              animCurve->lastIndex = v10;
              v12 = &v11[v10];
              animCurve->lastKey = v12;
              outTanX = v12->outTanX;
              if ( outTanX == 0.0 && v12->outTanY == 0.0 )
              {
                animCurve->isStep = 1;
              }
              else if ( outTanX == float_max_30 && v12->outTanY == float_max_30 )
              {
                animCurve->isStepNext = 1;
                v40 = &v11[v2];
              }
              else
              {
                animCurve->isStep = 0;
                animCurve->isStepNext = 0;
                outTanY = v12->outTanY;
                v18 = v12->outTanX;
                v19 = v12->time;
                p_time = &v11[v2].time;
                v21 = !animCurve->isWeighted;
                v22 = *p_time;
                v23 = p_time[2];
                v42[0] = v12->value;
                v24 = (float)(outTanY * 0.33333334) + v42[0];
                v44 = p_time[1];
                v46 = v22 - (float)(v23 * 0.33333334);
                v25 = (float)(v18 * 0.33333334) + v19;
                v26 = v44 - (float)(p_time[3] * 0.33333334);
                v45[0] = v19;
                v45[1] = v25;
                v42[1] = v24;
                v40 = (vostok::animation::EtKey *)p_time;
                v47 = v22;
                v43 = v26;
                if ( v21 )
                {
                  v27 = v44 - v42[0];
                  v28 = v25 - v19;
                  animCurve->fX1 = v19;
                  v29 = v22 - v19;
                  v30 = 0.0;
                  v31 = 0.0;
                  if ( v28 != 0.0 )
                    v31 = (float)(v24 - v42[0]) / v28;
                  v32 = v22 - v46;
                  if ( v32 != 0.0 )
                    v30 = (float)(v44 - v43) / v32;
                  v33 = s_bm_current_air_resistance / (float)(v29 * v29);
                  v34 = v30 * v29;
                  v35 = (float)((float)(v34 + (float)(v31 * v29)) - v27) - v27;
                  animCurve->fCoeff[1] = (float)((float)((float)((float)(v27 * 3.0) - (float)(v31 * v29))
                                                       - (float)(v31 * v29))
                                               - v34)
                                       * v33;
                  v36 = v42[0];
                  animCurve->fCoeff[0] = (float)(v35 / v29) * v33;
                  animCurve->fCoeff[2] = v31;
                  animCurve->fCoeff[3] = v36;
                }
                else
                {
                  engineBezierCreate(animCurve, v45, v42);
                }
                v4 = time;
              }
            }
            if ( animCurve->isStep )
            {
              lastKey = animCurve->lastKey;
            }
            else
            {
              if ( !animCurve->isStepNext )
              {
                if ( animCurve->isWeighted )
                  return engineBezierEvaluate(animCurve, v4);
                else
                  return (float)((float)((float)((float)((float)((float)(animCurve->fCoeff[0]
                                                                       * (float)(v4 - animCurve->fX1))
                                                               + animCurve->fCoeff[1])
                                                       * (float)(v4 - animCurve->fX1))
                                               + animCurve->fCoeff[2])
                                       * (float)(v4 - animCurve->fX1))
                               + animCurve->fCoeff[3]);
              }
              lastKey = v40;
            }
            return lastKey->value;
          }
        }
      }
      else
      {
        v8 = &animCurve->keyList._M_impl._M_start[lastIndex + 1];
        v40 = v8;
        if ( time == v8->time )
        {
          v9 = lastIndex + 1;
LABEL_17:
          animCurve->lastKey = v8;
          animCurve->lastIndex = v9;
          return v8->value;
        }
        if ( v8->time > time )
        {
          v2 = lastIndex + 1;
          goto LABEL_20;
        }
      }
      M_finish = animCurve->keyList._M_impl._M_finish;
    }
    v15 = find(animCurve, &v41, time);
    v2 = v41;
    if ( v15 || !v41 )
    {
      M_start = &animCurve->keyList._M_impl._M_start[v41];
      animCurve->lastKey = M_start;
      animCurve->lastIndex = v2;
      return M_start->value;
    }
    if ( v41 == animCurve->keyList._M_impl._M_finish - animCurve->keyList._M_impl._M_start )
    {
      v16 = animCurve->keyList._M_impl._M_start;
      animCurve->lastIndex = 0;
      animCurve->lastKey = v16;
      return M_finish[-1].value;
    }
    goto LABEL_20;
  }
  if ( animCurve->preInfinity == kInfinityConstant )
    return M_start->value;
  return COERCE_FLOAT(evaluateInfinities(animCurve, time, 1));
}

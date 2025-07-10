char __usercall btGeneric6DofConstraint::testAngularLimitMotor@<al>(
        btGeneric6DofConstraint *this@<ecx>,
        int axis_index@<eax>)
{
  float v2; // xmm0_4
  int v3; // edx
  float v4; // xmm1_4
  int v5; // eax
  float v6; // xmm2_4
  float *v7; // esi
  float *v8; // edi
  long double v9; // st7
  float v10; // xmm0_4
  long double v11; // st7
  float v12; // xmm0_4
  long double v13; // st7
  float v14; // xmm0_4
  long double v15; // st7
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  char result; // al
  float angle; // [esp+14h] [ebp-10h]
  float v21; // [esp+18h] [ebp-Ch]
  float v22; // [esp+18h] [ebp-Ch]
  float v23; // [esp+18h] [ebp-Ch]
  float v24; // [esp+18h] [ebp-Ch]
  float v25; // [esp+1Ch] [ebp-8h]
  float v26; // [esp+20h] [ebp-4h]

  v2 = this->m_calculatedAxisAngleDiff.mVec128.m128_f32[axis_index];
  v3 = (axis_index + 15) << 6;
  v4 = *(float *)((char *)&this->__vftable + v3);
  v5 = axis_index << 6;
  v6 = *(float *)((char *)&this->m_angularLimits[0].m_hiLimit + v5);
  v7 = (float *)((char *)this + v3);
  v8 = (float *)((char *)this + v5);
  angle = v2;
  if ( v4 < v6 )
  {
    if ( v4 <= v2 )
    {
      if ( v2 <= v6 )
        goto LABEL_25;
      v13 = fmodf(v2 - v6, 6.2831855);
      v23 = v13;
      v14 = v23;
      if ( v13 >= -3.1415927 )
      {
        if ( v23 > 3.1415927 )
          v14 = v23 - 6.2831855;
      }
      else
      {
        v14 = v23 + 6.2831855;
      }
      v25 = fabsf(v14);
      v15 = fmodf(angle - v4, 6.2831855);
      v24 = v15;
      v16 = v24;
      if ( v15 >= -3.1415927 )
      {
        if ( v24 > 3.1415927 )
          v16 = v24 - 6.2831855;
      }
      else
      {
        v16 = v24 + 6.2831855;
      }
      if ( v25 > fabsf(v16) )
      {
        v2 = angle - 6.2831855;
        goto LABEL_25;
      }
    }
    else
    {
      v9 = fmodf(v4 - v2, 6.2831855);
      v21 = v9;
      v10 = v21;
      if ( v9 >= -3.1415927 )
      {
        if ( v21 > 3.1415927 )
          v10 = v21 - 6.2831855;
      }
      else
      {
        v10 = v21 + 6.2831855;
      }
      v26 = fabsf(v10);
      v11 = fmodf(v6 - angle, 6.2831855);
      v22 = v11;
      v12 = v22;
      if ( v11 >= -3.1415927 )
      {
        if ( v22 > 3.1415927 )
          v12 = v22 - 6.2831855;
      }
      else
      {
        v12 = v22 + 6.2831855;
      }
      if ( fabsf(v12) <= v26 )
      {
        v2 = angle + 6.2831855;
        goto LABEL_25;
      }
    }
    v2 = angle;
  }
LABEL_25:
  v8[253] = v2;
  v17 = *v7;
  v18 = v7[1];
  result = 0;
  if ( *v7 > v18 )
    goto LABEL_30;
  if ( v17 <= v2 )
  {
    if ( v2 > v18 )
    {
      *((_DWORD *)v7 + 14) = 2;
      v7[12] = v2 - v18;
      goto LABEL_31;
    }
LABEL_30:
    v7[14] = 0.0;
    goto LABEL_31;
  }
  *((_DWORD *)v7 + 14) = 1;
  v7[12] = v2 - v17;
LABEL_31:
  if ( *((_DWORD *)v7 + 14) || *((_BYTE *)v7 + 44) )
    return 1;
  return result;
}

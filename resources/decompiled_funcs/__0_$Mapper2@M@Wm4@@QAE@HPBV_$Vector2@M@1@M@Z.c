void __userpurge Wm4::Mapper2<float>::Mapper2<float>(
        Wm4::Mapper2<float> *this@<ecx>,
        int a2@<esi>,
        int iVQuantity,
        vostok::math::float2 *akVertex,
        float fEpsilon)
{
  int v5; // edi
  const Wm4::Vector2<float> *v6; // edx
  float *v7; // ecx
  int v8; // ebx
  double v9; // st7
  float v10; // eax
  double v11; // st7
  float v12; // ecx
  double v13; // st6
  float v14; // edx
  bool v15; // c0
  bool v16; // c3
  int v17; // eax
  int v18; // ecx
  Wm4::Vector2<float> *v19; // ebp
  int v20; // eax
  float *v21; // edi
  vostok::math::float2 *v22; // eax
  vostok::math::float2 *v23; // ecx
  double v24; // st7
  vostok::math::float2 *v25; // ecx
  double v26; // st7
  int v27; // edx
  int v28; // edi
  long double v29; // st6
  bool v30; // c0
  float v31; // [esp+0h] [ebp-30h]
  float v32; // [esp+0h] [ebp-30h]
  const Wm4::Vector2<float> *v33; // [esp+4h] [ebp-2Ch]
  const Wm4::Vector2<float> *v34; // [esp+4h] [ebp-2Ch]
  float v35; // [esp+4h] [ebp-2Ch]
  float v36; // [esp+4h] [ebp-2Ch]
  const Wm4::Vector2<float> *v37; // [esp+4h] [ebp-2Ch]
  float fSign; // [esp+10h] [ebp-20h] BYREF
  int v39; // [esp+14h] [ebp-1Ch]
  float fLMax; // [esp+18h] [ebp-18h] BYREF
  int v41; // [esp+1Ch] [ebp-14h]
  float fMaxSign; // [esp+20h] [ebp-10h] BYREF
  float v43; // [esp+24h] [ebp-Ch]
  Wm4::Vector2<float> kDiff; // [esp+28h] [ebp-8h] BYREF
  float fLb; // [esp+38h] [ebp+8h]
  float fL; // [esp+38h] [ebp+8h]
  float fLc; // [esp+38h] [ebp+8h]
  int fLd; // [esp+38h] [ebp+8h]
  float fLe; // [esp+38h] [ebp+8h]
  float fLa; // [esp+38h] [ebp+8h]

  *(_BYTE *)(a2 + 36) = 0;
  Wm4::Vector2<float>::operator=(akVertex, (vostok::math::float2 *)a2);
  Wm4::Vector2<float>::operator=((vostok::math::float2 *)a2, (vostok::math::float2 *)(a2 + 8));
  v5 = 1;
  fLMax = 0.0;
  fSign = 0.0;
  v41 = 0;
  v39 = 0;
  if ( iVQuantity > 1 )
  {
    LODWORD(fMaxSign) = (char *)&fSign - a2;
    v6 = (const Wm4::Vector2<float> *)&akVertex[1];
    do
    {
      v7 = (float *)a2;
      v8 = 2;
      do
      {
        if ( *v7 <= (double)v6->m_afTuple[0] )
        {
          if ( v7[2] < (double)v6->m_afTuple[0] )
          {
            v10 = fMaxSign;
            v7[2] = v6->m_afTuple[0];
            *(_DWORD *)((char *)v7 + LODWORD(v10)) = v5;
          }
        }
        else
        {
          v9 = v6->m_afTuple[0];
          *(_DWORD *)((char *)&fLMax + (_DWORD)v7 - a2) = v5;
          *v7 = v9;
        }
        ++v7;
        v6 = (const Wm4::Vector2<float> *)((char *)v6 + 4);
        --v8;
      }
      while ( v8 );
      ++v5;
    }
    while ( v5 < iVQuantity );
  }
  Wm4::Vector2<float>::operator-(
    (Wm4::Vector2<float> *)a2,
    (Wm4::Vector2<float> *)&fMaxSign,
    (Wm4::Vector2<float> *)(a2 + 8),
    v33);
  v11 = fMaxSign;
  v12 = fLMax;
  *(float *)(a2 + 16) = fMaxSign;
  v13 = v43;
  v14 = fSign;
  v15 = v43 < v11;
  v16 = v43 == v11;
  *(float *)(a2 + 24) = v12;
  *(float *)(a2 + 28) = v14;
  if ( !v15 && !v16 )
  {
    v17 = v41;
    *(float *)(a2 + 16) = v13;
    v18 = v39;
    *(_DWORD *)(a2 + 24) = v17;
    *(_DWORD *)(a2 + 28) = v18;
  }
  v19 = (Wm4::Vector2<float> *)akVertex;
  Wm4::Vector2<float>::operator=(&akVertex[*(_DWORD *)(a2 + 24)], (vostok::math::float2 *)(a2 + 40));
  if ( fEpsilon <= (double)*(float *)(a2 + 16) )
  {
    v21 = (float *)(a2 + 48);
    v22 = (vostok::math::float2 *)Wm4::Vector2<float>::operator-(
                                    (Wm4::Vector2<float> *)(a2 + 40),
                                    &kDiff,
                                    (Wm4::Vector2<float> *)&akVertex[*(_DWORD *)(a2 + 28)],
                                    v34);
    Wm4::Vector2<float>::operator=(v22, (vostok::math::float2 *)(a2 + 48));
    fLb = *(float *)(a2 + 52) * *(float *)(a2 + 52) + *v21 * *v21;
    fL = sqrt(fLb);
    if ( fL <= 0.000001 )
    {
      v24 = 0.0;
      *v21 = 0.0;
    }
    else
    {
      fLc = 1.0 / fL;
      *v21 = *v21 * fLc;
      v24 = fLc * *(float *)(a2 + 52);
    }
    *(float *)(a2 + 52) = v24;
    v31 = -*v21;
    vostok::math::float2::float2(v23, (int)&fMaxSign, *(_DWORD *)(a2 + 52), v31, v35);
    v32 = -v43;
    *(float *)&fLd = -fMaxSign;
    vostok::math::float2::float2(v25, (int)&kDiff, fLd, v32, v36);
    Wm4::Vector2<float>::operator=((vostok::math::float2 *)&kDiff, (vostok::math::float2 *)(a2 + 56));
    v26 = 0.0;
    v27 = *(_DWORD *)(a2 + 24);
    fLMax = 0.0;
    v28 = 0;
    fMaxSign = 0.0;
    for ( *(_DWORD *)(a2 + 32) = v27; v28 < iVQuantity; ++v19 )
    {
      Wm4::Vector2<float>::operator-((Wm4::Vector2<float> *)(a2 + 40), &kDiff, v19, v37);
      fLe = *(float *)(a2 + 60) * kDiff.m_afTuple[1] + kDiff.m_afTuple[0] * *(float *)(a2 + 56);
      v26 = 0.0;
      v29 = fLe;
      if ( fLe <= 0.0 )
      {
        if ( v29 >= 0.0 )
          fSign = 0.0;
        else
          fSign = -1.0;
      }
      else
      {
        fSign = 1.0;
      }
      fLa = fabs(v29);
      if ( fLMax < (double)fLa )
      {
        fLMax = fLa;
        *(_DWORD *)(a2 + 32) = v28;
        fMaxSign = fSign;
      }
      ++v28;
    }
    if ( *(float *)(a2 + 16) * fEpsilon <= fLMax )
    {
      v30 = v26 < fMaxSign;
      *(_DWORD *)(a2 + 20) = 2;
      *(_BYTE *)(a2 + 36) = v30;
    }
    else
    {
      *(_DWORD *)(a2 + 32) = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(a2 + 20) = 1;
    }
  }
  else
  {
    v20 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 28) = v20;
    *(_DWORD *)(a2 + 32) = v20;
    *(_DWORD *)(a2 + 20) = 0;
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)&Wm4::Vector2<float>::ZERO,
      (vostok::math::float2 *)(a2 + 48));
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)&Wm4::Vector2<float>::ZERO,
      (vostok::math::float2 *)(a2 + 56));
  }
}

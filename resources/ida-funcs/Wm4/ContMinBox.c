Wm4::Box2<float> *__usercall Wm4::ContMinBox<float>@<eax>(
        Wm4::Vector2<float> *akPoint@<eax>,
        Wm4::Box2<float> *iQuantity,
        int fEpsilon)
{
  Wm4::ConvexHull2<float> *v4; // ecx
  float v5; // eax
  Wm4::ConvexHull1<float> *ConvexHull1; // ebx
  int *m_aiIndex; // esi
  Wm4::Vector2<float> *v9; // eax
  vostok::math::float2 *v10; // ecx
  Wm4::Vector2<float> *v11; // ecx
  vostok::math::float2 *v12; // ecx
  vostok::math::float2 *v13; // ecx
  Wm4::Vector2<float> *v14; // eax
  int v15; // esi
  Wm4::Vector2<float> *v16; // ebx
  int v17; // edi
  vostok::math::float2 *v18; // esi
  vostok::math::float2 *v19; // eax
  Wm4::Vector2<float> *v20; // ecx
  int v21; // edi
  vostok::math::float2 *v22; // eax
  Wm4::Vector2<float> *v23; // ecx
  signed int v24; // ecx
  int v25; // esi
  double v26; // st7
  int v27; // edx
  double v28; // st6
  double v29; // st6
  int v30; // edi
  Wm4::Vector2<float> *v31; // ecx
  double v32; // st5
  double v33; // st5
  double v34; // st6
  double v35; // st5
  double v36; // st5
  double v37; // st6
  double v38; // st5
  double v39; // st5
  double v40; // st7
  double v41; // st6
  double v42; // rt2
  double v43; // st5
  double v44; // st5
  vostok::math::float2 *v45; // ecx
  int v46; // edx
  double v47; // st5
  vostok::math::float2 *v48; // ecx
  vostok::math::float2 *v49; // ecx
  int v50; // eax
  vostok::math::float2 *v51; // ecx
  int v52; // eax
  int v53; // edi
  vostok::math::float2 *v54; // ecx
  vostok::math::float2 *v55; // ecx
  int v56; // eax
  vostok::math::float2 *v57; // ecx
  float v58; // edx
  float fEpsilona; // [esp+0h] [ebp-E4h]
  float fEpsilonb; // [esp+0h] [ebp-E4h]
  float fEpsilonc; // [esp+0h] [ebp-E4h]
  float fEpsilond; // [esp+0h] [ebp-E4h]
  float fEpsilone; // [esp+0h] [ebp-E4h]
  float fEpsilonf; // [esp+0h] [ebp-E4h]
  float fEpsilong; // [esp+0h] [ebp-E4h]
  float fEpsilonh; // [esp+0h] [ebp-E4h]
  float fEpsiloni; // [esp+0h] [ebp-E4h]
  float fEpsilonj; // [esp+0h] [ebp-E4h]
  float fEpsilonk; // [esp+0h] [ebp-E4h]
  bool v70; // [esp+4h] [ebp-E0h]
  const Wm4::Vector2<float> *v71; // [esp+4h] [ebp-E0h]
  float v72; // [esp+4h] [ebp-E0h]
  const Wm4::Vector2<float> *v73; // [esp+4h] [ebp-E0h]
  float v74; // [esp+4h] [ebp-E0h]
  float v75; // [esp+4h] [ebp-E0h]
  float v76; // [esp+4h] [ebp-E0h]
  float v77; // [esp+4h] [ebp-E0h]
  float v78; // [esp+4h] [ebp-E0h]
  float v79; // [esp+4h] [ebp-E0h]
  float v80; // [esp+4h] [ebp-E0h]
  Wm4::Query::Type v81; // [esp+8h] [ebp-DCh]
  int fMaxDot; // [esp+10h] [ebp-D4h]
  float fMaxDota; // [esp+10h] [ebp-D4h]
  float fMaxDotb; // [esp+10h] [ebp-D4h]
  float v85; // [esp+14h] [ebp-D0h]
  int v86; // [esp+14h] [ebp-D0h]
  int v87; // [esp+14h] [ebp-D0h]
  int v88; // [esp+14h] [ebp-D0h]
  float v89; // [esp+14h] [ebp-D0h]
  float v90; // [esp+14h] [ebp-D0h]
  int v91; // [esp+14h] [ebp-D0h]
  int v92; // [esp+14h] [ebp-D0h]
  int v93; // [esp+14h] [ebp-D0h]
  int v94; // [esp+14h] [ebp-D0h]
  float fDot; // [esp+18h] [ebp-CCh]
  float fDota; // [esp+18h] [ebp-CCh]
  float fDotb; // [esp+18h] [ebp-CCh]
  float fDotc; // [esp+18h] [ebp-CCh]
  float fMinAreaDiv4; // [esp+1Ch] [ebp-C8h] BYREF
  int iRIndex; // [esp+20h] [ebp-C4h]
  float fXMax; // [esp+24h] [ebp-C0h]
  int iBIndex; // [esp+28h] [ebp-BCh]
  int iTIndex; // [esp+2Ch] [ebp-B8h]
  void *p; // [esp+30h] [ebp-B4h]
  bool *abVisited; // [esp+34h] [ebp-B0h]
  Wm4::Vector2<float> kDiff; // [esp+38h] [ebp-ACh] BYREF
  Wm4::Vector2<float> kU; // [esp+40h] [ebp-A4h] BYREF
  Wm4::Box2<float> kBox; // [esp+48h] [ebp-9Ch] BYREF
  vostok::math::float2 v109; // [esp+68h] [ebp-7Ch] BYREF
  vostok::math::float2 v110; // [esp+70h] [ebp-74h] BYREF
  float v111[2]; // [esp+78h] [ebp-6Ch] BYREF
  vostok::math::float2 v112; // [esp+80h] [ebp-64h] BYREF
  vostok::math::float2 v113; // [esp+88h] [ebp-5Ch] BYREF
  vostok::math::float2 v114; // [esp+90h] [ebp-54h] BYREF
  vostok::math::float2 v115; // [esp+98h] [ebp-4Ch] BYREF
  vostok::math::float2 v116; // [esp+A0h] [ebp-44h] BYREF
  Wm4::ConvexHull2<float> kHull; // [esp+A8h] [ebp-3Ch] BYREF
  signed int iQuantitya; // [esp+F0h] [ebp+Ch]

  Wm4::ConvexHull2<float>::ConvexHull2<float>(&kHull, fEpsilon, akPoint, 0.0, v70, v81);
  if ( !kHull.m_iDimension )
  {
    Wm4::Vector2<float>::operator=((vostok::math::float2 *)akPoint, (vostok::math::float2 *)&kBox);
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)&Wm4::Vector2<float>::UNIT_X,
      (vostok::math::float2 *)kBox.Axis);
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)&Wm4::Vector2<float>::UNIT_Y,
      (vostok::math::float2 *)&kBox.Axis[1]);
    kBox.Extent[0] = 0.0;
    kBox.Extent[1] = 0.0;
    iQuantity->Center.m_afTuple[0] = kBox.Center.m_afTuple[0];
    iQuantity->Center.m_afTuple[1] = kBox.Center.m_afTuple[1];
    `vector copy constructor iterator'(
      (char *)iQuantity->Axis,
      (char *)kBox.Axis,
      8u,
      2,
      (void *(__thiscall *)(void *, void *))Wm4::Vector2<float>::Vector2<float>);
    v5 = kBox.Extent[0];
    iQuantity->Extent[1] = kBox.Extent[1];
    iQuantity->Extent[0] = v5;
    Wm4::ConvexHull2<float>::~ConvexHull2<float>(&kHull);
    return iQuantity;
  }
  if ( kHull.m_iDimension == 1 )
  {
    ConvexHull1 = Wm4::ConvexHull2<float>::GetConvexHull1(v4);
    m_aiIndex = ConvexHull1->m_aiIndex;
    v9 = Wm4::Vector2<float>::operator+(&akPoint[m_aiIndex[1]], (Wm4::Vector2<float> *)&v110, &akPoint[*m_aiIndex], v71);
    v85 = v9->m_afTuple[1] * 0.5;
    fEpsilona = v85;
    *(float *)&v86 = 0.5 * v9->m_afTuple[0];
    vostok::math::float2::float2(v10, (int)&v109, v86, fEpsilona, v72);
    Wm4::Vector2<float>::operator=(&v109, (vostok::math::float2 *)&kBox);
    Wm4::Vector2<float>::operator-(&akPoint[*m_aiIndex], &kDiff, &akPoint[m_aiIndex[1]], v73);
    kBox.Extent[0] = Wm4::Vector2<float>::Normalize(v11) * 0.5;
    kBox.Extent[1] = 0.0;
    Wm4::Vector2<float>::operator=((vostok::math::float2 *)&kDiff, (vostok::math::float2 *)kBox.Axis);
    fEpsilonb = -kBox.Axis[0].m_afTuple[0];
    vostok::math::float2::float2(v12, (int)&kDiff, SLODWORD(kBox.Axis[0].m_afTuple[1]), fEpsilonb, v74);
    fEpsilonc = -kDiff.m_afTuple[1];
    *(float *)&v87 = -kDiff.m_afTuple[0];
    vostok::math::float2::float2(v13, (int)&v109, v87, fEpsilonc, v75);
    Wm4::Vector2<float>::operator=(&v109, (vostok::math::float2 *)&kBox.Axis[1]);
    ((void (__thiscall *)(Wm4::ConvexHull1<float> *, int))ConvexHull1->~Wm4::ConvexHull1<float>)(ConvexHull1, 1);
    Wm4::Box2<float>::Box2<float>(iQuantity, &kBox);
    Wm4::ConvexHull2<float>::~ConvexHull2<float>(&kHull);
    return iQuantity;
  }
  iQuantitya = kHull.m_iSimplexQuantity;
  v14 = (Wm4::Vector2<float> *)operator new[](8 * kHull.m_iSimplexQuantity);
  v15 = 0;
  v16 = v14;
  if ( kHull.m_iSimplexQuantity > 0 )
  {
    p = v14;
    do
    {
      Wm4::Vector2<float>::operator=((vostok::math::float2 *)&akPoint[kHull.m_aiIndex[v15]], (vostok::math::float2 *)p);
      p = (char *)p + 8;
      ++v15;
    }
    while ( v15 < kHull.m_iSimplexQuantity );
  }
  Wm4::ConvexHull2<float>::~ConvexHull2<float>(&kHull);
  v88 = iQuantitya - 1;
  p = operator new[](8 * iQuantitya);
  v17 = 0;
  abVisited = (bool *)operator new[](iQuantitya);
  if ( iQuantitya - 1 > 0 )
  {
    v18 = (vostok::math::float2 *)p;
    fMaxDot = (char *)v16 - (_BYTE *)p;
    do
    {
      v19 = (vostok::math::float2 *)Wm4::Vector2<float>::operator-(
                                      (Wm4::Vector2<float> *)((char *)v18 + fMaxDot),
                                      (Wm4::Vector2<float> *)&v110,
                                      (Wm4::Vector2<float> *)((char *)&v18[1] + fMaxDot),
                                      v71);
      Wm4::Vector2<float>::operator=(v19, v18);
      Wm4::Vector2<float>::Normalize(v20);
      abVisited[v17++] = 0;
      ++v18;
    }
    while ( v17 < v88 );
  }
  v21 = iQuantitya - 1;
  v22 = (vostok::math::float2 *)Wm4::Vector2<float>::operator-(&v16[v88], (Wm4::Vector2<float> *)&v110, v16, v71);
  Wm4::Vector2<float>::operator=(v22, (vostok::math::float2 *)p + v88);
  Wm4::Vector2<float>::Normalize(v23);
  v24 = iQuantitya;
  abVisited[v88] = 0;
  fMinAreaDiv4 = v16->m_afTuple[0];
  v25 = 0;
  v26 = fMinAreaDiv4;
  v27 = 1;
  fXMax = fMinAreaDiv4;
  v28 = v16->m_afTuple[1];
  iRIndex = 0;
  fMaxDota = v28;
  iBIndex = 0;
  v29 = fMaxDota;
  iTIndex = 0;
  fDot = fMaxDota;
  if ( iQuantitya > 1 )
  {
    if ( v88 >= 4 )
    {
      v30 = 3;
      v31 = v16 + 2;
      do
      {
        if ( v31[-1].m_afTuple[0] <= v26 )
        {
          v25 = v27;
          fMinAreaDiv4 = v31[-1].m_afTuple[0];
          v26 = fMinAreaDiv4;
        }
        if ( fXMax <= (double)v31[-1].m_afTuple[0] )
        {
          v32 = v31[-1].m_afTuple[0];
          iRIndex = v27;
          fXMax = v32;
        }
        if ( v31[-1].m_afTuple[1] <= v29 )
        {
          iBIndex = v27;
          fMaxDota = v31[-1].m_afTuple[1];
          v29 = fMaxDota;
        }
        if ( fDot <= (double)v31[-1].m_afTuple[1] )
        {
          v33 = v31[-1].m_afTuple[1];
          iTIndex = v27;
          fDot = v33;
        }
        if ( v31->m_afTuple[0] <= v26 )
        {
          v25 = v30 - 1;
          fMinAreaDiv4 = v31->m_afTuple[0];
          v26 = fMinAreaDiv4;
        }
        if ( fXMax <= (double)v31->m_afTuple[0] )
        {
          fXMax = v31->m_afTuple[0];
          iRIndex = v30 - 1;
        }
        if ( v31->m_afTuple[1] <= v29 )
        {
          v34 = v31->m_afTuple[1];
          iBIndex = v30 - 1;
          fMaxDota = v34;
          v29 = fMaxDota;
        }
        if ( fDot <= (double)v31->m_afTuple[1] )
        {
          fDot = v31->m_afTuple[1];
          iTIndex = v30 - 1;
        }
        if ( v31[1].m_afTuple[0] <= v26 )
        {
          v25 = v30;
          fMinAreaDiv4 = v31[1].m_afTuple[0];
          v26 = fMinAreaDiv4;
        }
        if ( fXMax <= (double)v31[1].m_afTuple[0] )
        {
          v35 = v31[1].m_afTuple[0];
          iRIndex = v30;
          fXMax = v35;
        }
        if ( v31[1].m_afTuple[1] <= v29 )
        {
          iBIndex = v30;
          fMaxDota = v31[1].m_afTuple[1];
          v29 = fMaxDota;
        }
        if ( fDot <= (double)v31[1].m_afTuple[1] )
        {
          v36 = v31[1].m_afTuple[1];
          iTIndex = v30;
          fDot = v36;
        }
        if ( v31[2].m_afTuple[0] <= v26 )
        {
          v25 = v30 + 1;
          fMinAreaDiv4 = v31[2].m_afTuple[0];
          v26 = fMinAreaDiv4;
        }
        if ( fXMax <= (double)v31[2].m_afTuple[0] )
        {
          fXMax = v31[2].m_afTuple[0];
          iRIndex = v30 + 1;
        }
        if ( v31[2].m_afTuple[1] <= v29 )
        {
          v37 = v31[2].m_afTuple[1];
          iBIndex = v30 + 1;
          fMaxDota = v37;
          v29 = fMaxDota;
        }
        if ( fDot <= (double)v31[2].m_afTuple[1] )
        {
          fDot = v31[2].m_afTuple[1];
          iTIndex = v30 + 1;
        }
        v27 += 4;
        v30 += 4;
        v31 += 4;
      }
      while ( v27 < iQuantitya - 3 );
      v24 = iQuantitya;
      v21 = iQuantitya - 1;
    }
    for ( ; v27 < v24; ++v27 )
    {
      if ( v16[v27].m_afTuple[0] <= v26 )
      {
        v25 = v27;
        fMinAreaDiv4 = v16[v27].m_afTuple[0];
        v26 = fMinAreaDiv4;
      }
      if ( fXMax <= (double)v16[v27].m_afTuple[0] )
      {
        v38 = v16[v27].m_afTuple[0];
        iRIndex = v27;
        fXMax = v38;
      }
      if ( v16[v27].m_afTuple[1] <= v29 )
      {
        iBIndex = v27;
        fMaxDota = v16[v27].m_afTuple[1];
        v29 = fMaxDota;
      }
      if ( fDot <= (double)v16[v27].m_afTuple[1] )
      {
        v39 = v16[v27].m_afTuple[1];
        iTIndex = v27;
        fDot = v39;
      }
    }
  }
  if ( v25 == v21 && v16->m_afTuple[0] <= v26 )
  {
    v40 = v29;
    v25 = 0;
    fMinAreaDiv4 = v16->m_afTuple[0];
    v41 = fMinAreaDiv4;
  }
  else
  {
    v42 = v29;
    v41 = v26;
    v40 = v42;
  }
  if ( iRIndex == v21 && fXMax <= (double)v16->m_afTuple[0] )
  {
    v43 = v16->m_afTuple[0];
    iRIndex = 0;
    fXMax = v43;
  }
  if ( iBIndex == v21 && v16->m_afTuple[1] <= v40 )
  {
    iBIndex = 0;
    fMaxDota = v16->m_afTuple[1];
    v40 = fMaxDota;
  }
  if ( iTIndex == v21 && fDot <= (double)v16->m_afTuple[1] )
  {
    v44 = v16->m_afTuple[1];
    iTIndex = 0;
    fDot = v44;
  }
  kBox.Center.m_afTuple[0] = (v41 + fXMax) * 0.5;
  kBox.Center.m_afTuple[1] = (v40 + fDot) * 0.5;
  Wm4::Vector2<float>::operator=(
    (vostok::math::float2 *)&Wm4::Vector2<float>::UNIT_X,
    (vostok::math::float2 *)kBox.Axis);
  Wm4::Vector2<float>::operator=(
    (vostok::math::float2 *)&Wm4::Vector2<float>::UNIT_Y,
    (vostok::math::float2 *)&kBox.Axis[1]);
  kBox.Extent[0] = (fXMax - fMinAreaDiv4) * 0.5;
  kBox.Extent[1] = 0.5 * (fDot - fMaxDota);
  fMinAreaDiv4 = kBox.Extent[1] * kBox.Extent[0];
  Wm4::Vector2<float>::Vector2<float>(&kU, &Wm4::Vector2<float>::UNIT_X);
  Wm4::Vector2<float>::Vector2<float>(&kDiff, &Wm4::Vector2<float>::UNIT_Y);
  while ( 2 )
  {
    fMaxDotb = 0.0;
    v45 = (vostok::math::float2 *)((char *)p + 8 * iBIndex);
    v46 = 0;
    fDota = v45->y * kU.m_afTuple[1] + kU.m_afTuple[0] * v45->x;
    if ( fDota > 0.0 )
    {
      v46 = 3;
      fMaxDotb = *((float *)p + 2 * iBIndex + 1) * kU.m_afTuple[1] + kU.m_afTuple[0] * v45->x;
    }
    v47 = *((float *)p + 2 * iRIndex + 1);
    LODWORD(fXMax) = (char *)p + 8 * iRIndex;
    fDotb = v47 * kDiff.m_afTuple[1] + kDiff.m_afTuple[0] * *(float *)LODWORD(fXMax);
    if ( fMaxDotb < (double)fDotb )
    {
      fMaxDotb = v47 * kDiff.m_afTuple[1] + kDiff.m_afTuple[0] * *(float *)LODWORD(fXMax);
      v46 = 2;
    }
    v89 = kU.m_afTuple[0] * *((float *)p + 2 * iTIndex) + kU.m_afTuple[1] * *((float *)p + 2 * iTIndex + 1);
    fDotc = -v89;
    if ( fMaxDotb < (double)fDotc )
    {
      fMaxDotb = -v89;
      v46 = 4;
    }
    v90 = kDiff.m_afTuple[1] * *((float *)p + 2 * v25 + 1) + kDiff.m_afTuple[0] * *((float *)p + 2 * v25);
    if ( fMaxDotb < -v90 )
      v46 = 1;
    switch ( v46 )
    {
      case 0:
        goto $LN279;
      case 1:
        if ( abVisited[v25] )
          goto $LN279;
        fEpsilonj = -*((float *)p + 2 * v25 + 1);
        *(float *)&v94 = -*((float *)p + 2 * v25);
        vostok::math::float2::float2(v45, (int)&v116, v94, fEpsilonj, v76);
        Wm4::Vector2<float>::operator=(&v116, (vostok::math::float2 *)&kDiff);
        fEpsilonk = -kDiff.m_afTuple[0];
        vostok::math::float2::float2(v57, (int)&v110, SLODWORD(kDiff.m_afTuple[1]), fEpsilonk, v80);
        Wm4::Vector2<float>::operator=(&v110, (vostok::math::float2 *)&kU);
        Wm4::UpdateBox_float_(&v16[v25], &v16[iRIndex], &v16[iBIndex], &v16[iTIndex], &kU, &kDiff, &fMinAreaDiv4, &kBox);
        abVisited[v25] = 1;
        if ( ++v25 == iQuantitya )
          v25 = 0;
        continue;
      case 2:
        if ( abVisited[iRIndex] )
          goto $LN279;
        Wm4::Vector2<float>::operator=((vostok::math::float2 *)LODWORD(fXMax), (vostok::math::float2 *)&kDiff);
        fEpsilonf = -kDiff.m_afTuple[0];
        vostok::math::float2::float2(v51, (int)&v113, SLODWORD(kDiff.m_afTuple[1]), fEpsilonf, v76);
        Wm4::Vector2<float>::operator=(&v113, (vostok::math::float2 *)&kU);
        Wm4::UpdateBox_float_(&v16[v25], &v16[iRIndex], &v16[iBIndex], &v16[iTIndex], &kU, &kDiff, &fMinAreaDiv4, &kBox);
        v52 = iRIndex;
        abVisited[iRIndex] = 1;
        iRIndex = v52 + 1;
        if ( v52 + 1 == iQuantitya )
          iRIndex = 0;
        continue;
      case 3:
        if ( abVisited[iBIndex] )
          goto $LN279;
        Wm4::Vector2<float>::operator=(v45, (vostok::math::float2 *)&kU);
        fEpsilond = -kU.m_afTuple[0];
        vostok::math::float2::float2(v48, (int)v111, SLODWORD(kU.m_afTuple[1]), fEpsilond, v76);
        fEpsilone = -v111[1];
        *(float *)&v91 = -v111[0];
        vostok::math::float2::float2(v49, (int)&v115, v91, fEpsilone, v77);
        Wm4::Vector2<float>::operator=(&v115, (vostok::math::float2 *)&kDiff);
        Wm4::UpdateBox_float_(&v16[v25], &v16[iRIndex], &v16[iBIndex], &v16[iTIndex], &kU, &kDiff, &fMinAreaDiv4, &kBox);
        v50 = iBIndex;
        abVisited[iBIndex] = 1;
        iBIndex = v50 + 1;
        if ( v50 + 1 == iQuantitya )
          iBIndex = 0;
        continue;
      case 4:
        if ( !abVisited[iTIndex] )
        {
          v53 = iTIndex;
          fEpsilong = -*((float *)p + 2 * iTIndex + 1);
          *(float *)&v92 = -*((float *)p + 2 * iTIndex);
          vostok::math::float2::float2(v45, (int)&v112, v92, fEpsilong, v76);
          Wm4::Vector2<float>::operator=(&v112, (vostok::math::float2 *)&kU);
          fEpsilonh = -kU.m_afTuple[0];
          vostok::math::float2::float2(v54, (int)&v109, SLODWORD(kU.m_afTuple[1]), fEpsilonh, v78);
          fEpsiloni = -v109.y;
          *(float *)&v93 = -v109.x;
          vostok::math::float2::float2(v55, (int)&v114, v93, fEpsiloni, v79);
          Wm4::Vector2<float>::operator=(&v114, (vostok::math::float2 *)&kDiff);
          Wm4::UpdateBox_float_(&v16[v25], &v16[iRIndex], &v16[iBIndex], &v16[v53], &kU, &kDiff, &fMinAreaDiv4, &kBox);
          v56 = iTIndex;
          abVisited[iTIndex] = 1;
          iTIndex = v56 + 1;
          if ( v56 + 1 == iQuantitya )
            iTIndex = 0;
          continue;
        }
$LN279:
        operator delete[](abVisited);
        operator delete[](p);
        operator delete[](v16);
        iQuantity->Center.m_afTuple[0] = kBox.Center.m_afTuple[0];
        iQuantity->Center.m_afTuple[1] = kBox.Center.m_afTuple[1];
        `vector copy constructor iterator'(
          (char *)iQuantity->Axis,
          (char *)kBox.Axis,
          8u,
          2,
          (void *(__thiscall *)(void *, void *))Wm4::Vector2<float>::Vector2<float>);
        v58 = kBox.Extent[0];
        iQuantity->Extent[1] = kBox.Extent[1];
        iQuantity->Extent[0] = v58;
        return iQuantity;
      default:
        continue;
    }
  }
}

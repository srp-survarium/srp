Wm4::Box2<float> *__usercall Wm4::ContMinBox<float>@<eax>(
        Wm4::Vector2<float> *akPoint@<eax>,
        Wm4::Box2<float> *iQuantity,
        int fEpsilon)
{
  Wm4::ConvexHull2<float> *v4; // ecx
  Wm4::Box2<float> *v5; // esi
  Wm4::ConvexHull1<float> *ConvexHull1; // eax
  int *m_aiIndex; // edx
  Wm4::Vector2<float> *v8; // esi
  Wm4::Vector2<float> *v9; // ebx
  float v10; // xmm0_4
  Wm4::Vector2<float> *v11; // esi
  Wm4::Vector2<float> *v12; // edx
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  signed int m_iSimplexQuantity; // esi
  float *v19; // eax
  signed int v20; // ecx
  float *i; // ebx
  Wm4::Vector2<float> *v22; // eax
  Wm4::Vector2<float> *v23; // edi
  void *v24; // eax
  Wm4::Vector2<float> *v25; // ecx
  float *v26; // eax
  float *v27; // esi
  float v28; // xmm1_4
  bool v29; // cc
  float *v30; // eax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float *v33; // eax
  float v34; // xmm0_4
  float v35; // xmm2_4
  int v36; // eax
  float v37; // xmm1_4
  float v38; // xmm7_4
  float v39; // xmm6_4
  float v40; // xmm5_4
  float v41; // xmm3_4
  float v42; // xmm3_4
  float v43; // xmm2_4
  int v44; // ecx
  int v45; // edi
  float v46; // xmm1_4
  float v47; // xmm1_4
  int v48; // edx
  float v49; // xmm1_4
  int v50; // eax
  float v51; // xmm1_4
  bool v52; // zf
  float v53; // xmm2_4
  float v54; // xmm2_4
  float v55; // xmm2_4
  float v56; // xmm2_4
  Wm4::Vector2<float> *v58; // [esp-4h] [ebp-ACh]
  float v59; // [esp+0h] [ebp-A8h]
  bool v60; // [esp+4h] [ebp-A4h]
  Wm4::Query::Type v61; // [esp+8h] [ebp-A0h]
  Wm4::ConvexHull2<float> v62; // [esp+Ch] [ebp-9Ch] BYREF
  _DWORD *v63; // [esp+48h] [ebp-60h]
  Wm4::Box2<float> __that; // [esp+4Ch] [ebp-5Ch] BYREF
  float *v65; // [esp+6Ch] [ebp-3Ch]
  char *v66; // [esp+70h] [ebp-38h]
  float rfMinAreaDiv4; // [esp+74h] [ebp-34h] BYREF
  void *v68; // [esp+78h] [ebp-30h]
  float *v69; // [esp+7Ch] [ebp-2Ch]
  void *p; // [esp+80h] [ebp-28h]
  Wm4::Vector2<float> rkV; // [esp+84h] [ebp-24h] BYREF
  Wm4::Vector2<float> rkU; // [esp+8Ch] [ebp-1Ch] BYREF
  int v73; // [esp+94h] [ebp-14h]
  int v74; // [esp+98h] [ebp-10h]
  int v75; // [esp+9Ch] [ebp-Ch]
  float v76; // [esp+A0h] [ebp-8h]
  Wm4::Vector2<float> *v77; // [esp+A4h] [ebp-4h]
  int iVertexQuantity; // [esp+B4h] [ebp+Ch]

  Wm4::ConvexHull2<float>::ConvexHull2<float>(akPoint, (int)akPoint, &v62, fEpsilon, v59, v60, v61);
  if ( !v62.m_iDimension )
  {
    __that.Center.m_afTuple[0] = akPoint->m_afTuple[0];
    __that.Center.m_afTuple[1] = akPoint->m_afTuple[1];
    __that.Axis[0] = Wm4::Vector2<float>::UNIT_X;
    __that.Axis[1] = Wm4::Vector2<float>::UNIT_Y;
    __that.Extent[0] = 0.0;
    __that.Extent[1] = 0.0;
LABEL_3:
    v5 = iQuantity;
    Wm4::Box2<float>::Box2<float>(iQuantity, &__that);
    Wm4::ConvexHull2<float>::~ConvexHull2<float>(&v62);
    return v5;
  }
  if ( v62.m_iDimension == 1 )
  {
    ConvexHull1 = Wm4::ConvexHull2<float>::GetConvexHull1(v4, (int)&v62);
    m_aiIndex = ConvexHull1->m_aiIndex;
    v8 = &akPoint[m_aiIndex[1]];
    v9 = &akPoint[*m_aiIndex];
    v10 = v8->m_afTuple[1] + v9->m_afTuple[1];
    __that.Center.m_afTuple[0] = (float)(v8->m_afTuple[0] + v9->m_afTuple[0]) * 0.5;
    __that.Center.m_afTuple[1] = v10 * 0.5;
    v11 = &akPoint[*m_aiIndex];
    v12 = &akPoint[m_aiIndex[1]];
    v13 = v12->m_afTuple[0] - v11->m_afTuple[0];
    v14 = v12->m_afTuple[1] - v11->m_afTuple[1];
    v15 = fsqrt((float)(v13 * v13) + (float)(v14 * v14));
    if ( v15 <= 0.000001 )
    {
      v15 = 0.0;
      v16 = 0.0;
      v17 = 0.0;
    }
    else
    {
      v16 = (float)(s_bm_current_air_resistance / v15) * v13;
      v17 = v14 * (float)(s_bm_current_air_resistance / v15);
    }
    __that.Extent[0] = v15 * 0.5;
    __that.Axis[0].m_afTuple[0] = v16;
    __that.Axis[0].m_afTuple[1] = v17;
    __that.Extent[1] = 0.0;
    LODWORD(__that.Axis[1].m_afTuple[0]) = LODWORD(v17) ^ _mask__NegFloat_;
    __that.Axis[1].m_afTuple[1] = v16;
    ((void (__thiscall *)(Wm4::ConvexHull1<float> *, int))ConvexHull1->~Wm4::ConvexHull1<float>)(ConvexHull1, 1);
    goto LABEL_3;
  }
  m_iSimplexQuantity = v62.m_iSimplexQuantity;
  iVertexQuantity = v62.m_iSimplexQuantity;
  v19 = (float *)operator new[](8 * v62.m_iSimplexQuantity);
  v20 = 0;
  for ( i = v19; v20 < m_iSimplexQuantity; i[2 * v20 - 1] = v22->m_afTuple[1] )
  {
    v22 = &akPoint[v62.m_aiIndex[v20]];
    i[2 * v20++] = v22->m_afTuple[0];
  }
  Wm4::ConvexHull2<float>::~ConvexHull2<float>(&v62);
  v23 = (Wm4::Vector2<float> *)(m_iSimplexQuantity - 1);
  *(float *)&v68 = COERCE_FLOAT(operator new[](8 * m_iSimplexQuantity));
  v24 = operator new[](m_iSimplexQuantity);
  v77 = 0;
  v25 = v58;
  p = v24;
  if ( m_iSimplexQuantity - 1 > 0 )
  {
    v26 = (float *)v68;
    v76 = *(float *)&v68;
    v27 = i + 2;
    while ( 1 )
    {
      v28 = v27[1] - *(v27 - 1);
      *v26 = *v27 - *(v27 - 2);
      v26[1] = v28;
      Wm4::Vector2<float>::Normalize(v25, v26);
      v25 = v77;
      v77 = (Wm4::Vector2<float> *)((char *)v77 + 1);
      LODWORD(v76) += 8;
      v27 += 2;
      v29 = (int)v77 < (int)v23;
      *((_BYTE *)p + (_DWORD)v25) = 0;
      if ( !v29 )
        break;
      v26 = (float *)LODWORD(v76);
    }
  }
  v30 = &i[2 * (_DWORD)v23];
  v31 = *i - *v30;
  v32 = i[1] - v30[1];
  v33 = (float *)((char *)v68 + 8 * (_DWORD)v23);
  *v33 = v31;
  v33[1] = v32;
  Wm4::Vector2<float>::Normalize(v25, v33);
  *((_BYTE *)v23->m_afTuple + (_DWORD)p) = 0;
  v34 = *i;
  v35 = i[1];
  v36 = 1;
  v38 = *i;
  v39 = *i;
  v76 = v35;
  v37 = v35;
  v40 = v35;
  v77 = 0;
  v75 = 0;
  v74 = 0;
  v73 = 0;
  if ( iVertexQuantity > 1 )
  {
    do
    {
      v41 = i[2 * v36];
      if ( v38 >= v41 )
      {
        v38 = i[2 * v36];
        v77 = (Wm4::Vector2<float> *)v36;
      }
      if ( v41 >= v39 )
      {
        v39 = v41;
        v75 = v36;
      }
      v42 = i[2 * v36 + 1];
      if ( v37 >= v42 )
      {
        v37 = i[2 * v36 + 1];
        v74 = v36;
      }
      if ( v42 >= v40 )
      {
        v40 = v42;
        v73 = v36;
      }
      ++v36;
    }
    while ( v36 < iVertexQuantity );
    v76 = v37;
  }
  if ( v77 == v23 && v38 >= v34 )
  {
    v38 = v34;
    v77 = 0;
  }
  if ( (Wm4::Vector2<float> *)v75 == v23 && v34 >= v39 )
  {
    v39 = v34;
    v75 = 0;
  }
  if ( (Wm4::Vector2<float> *)v74 == v23 && v37 >= v35 )
  {
    v37 = v35;
    v76 = v35;
    v74 = 0;
  }
  if ( (Wm4::Vector2<float> *)v73 == v23 && v35 >= v40 )
  {
    v40 = v35;
    v73 = 0;
  }
  __that.Center.m_afTuple[0] = (float)(v39 + v38) * 0.5;
  __that.Center.m_afTuple[1] = (float)(v40 + v37) * 0.5;
  __that.Extent[1] = (float)(v40 - v76) * 0.5;
  __that.Axis[0] = Wm4::Vector2<float>::UNIT_X;
  __that.Axis[1] = Wm4::Vector2<float>::UNIT_Y;
  __that.Extent[0] = (float)(v39 - v38) * 0.5;
  rfMinAreaDiv4 = __that.Extent[1] * __that.Extent[0];
  rkU = Wm4::Vector2<float>::UNIT_X;
  rkV = Wm4::Vector2<float>::UNIT_Y;
  while ( 1 )
  {
    v43 = 0.0;
    v44 = 2 * v74;
    v45 = 0;
    v46 = (float)(*((float *)v68 + 2 * v74 + 1) * rkU.m_afTuple[1])
        + (float)(*((float *)v68 + 2 * v74) * rkU.m_afTuple[0]);
    v69 = (float *)((char *)v68 + 8 * v74);
    if ( v46 > 0.0 )
    {
      v43 = v46;
      v45 = 3;
    }
    LODWORD(v76) = 8 * v75;
    v47 = (float)(*((float *)v68 + 2 * v75 + 1) * rkV.m_afTuple[1])
        + (float)(rkV.m_afTuple[0] * *((float *)v68 + 2 * v75));
    v65 = (float *)((char *)v68 + 8 * v75);
    if ( v47 > v43 )
    {
      v43 = v47;
      v45 = 2;
    }
    v48 = 2 * v73;
    LODWORD(v49) = COERCE_UNSIGNED_INT(
                     (float)(*((float *)v68 + 2 * v73 + 1) * rkU.m_afTuple[1])
                   + (float)(rkU.m_afTuple[0] * *((float *)v68 + 2 * v73)))
                 ^ _mask__NegFloat_;
    v66 = (char *)v68 + 8 * v73;
    if ( v49 > v43 )
    {
      v43 = v49;
      v45 = 4;
    }
    v50 = 2 * (_DWORD)v77;
    LODWORD(v51) = COERCE_UNSIGNED_INT(
                     (float)(*((float *)v68 + 2 * (_DWORD)v77 + 1) * rkV.m_afTuple[1])
                   + (float)(*((float *)v68 + 2 * (_DWORD)v77) * rkV.m_afTuple[0]))
                 ^ _mask__NegFloat_;
    v63 = (char *)v68 + 8 * (_DWORD)v77;
    if ( v51 > v43 )
      v45 = 1;
    if ( !v45 )
      break;
    switch ( v45 )
    {
      case 1:
        v52 = *((_BYTE *)v77->m_afTuple + (_DWORD)p) == 0;
        v65 = (float *)((int)v77->m_afTuple + (_DWORD)p);
        if ( !v52 )
          goto LABEL_63;
        LODWORD(v56) = v63[1] ^ _mask__NegFloat_;
        LODWORD(rkV.m_afTuple[0]) = *v63 ^ _mask__NegFloat_;
        rkV.m_afTuple[1] = v56;
        rkU.m_afTuple[0] = v56;
        LODWORD(rkU.m_afTuple[1]) = LODWORD(rkV.m_afTuple[0]) ^ _mask__NegFloat_;
        Wm4::UpdateBox_float_(
          (const Wm4::Vector2<float> *)&i[v50],
          (const Wm4::Vector2<float> *)&i[v44],
          &rkV,
          &__that,
          (const Wm4::Vector2<float> *)((char *)i + LODWORD(v76)),
          (const Wm4::Vector2<float> *)&i[v48],
          &rkU,
          &rfMinAreaDiv4);
        v77 = (Wm4::Vector2<float> *)((char *)v77 + 1);
        *(_BYTE *)v65 = 1;
        if ( v77 == (Wm4::Vector2<float> *)iVertexQuantity )
          v77 = 0;
        break;
      case 2:
        v52 = *((_BYTE *)p + v75) == 0;
        v69 = (float *)((char *)p + v75);
        if ( !v52 )
          goto LABEL_63;
        v55 = v65[1];
        rkV.m_afTuple[0] = *v65;
        rkV.m_afTuple[1] = v55;
        rkU.m_afTuple[0] = v55;
        LODWORD(rkU.m_afTuple[1]) = LODWORD(rkV.m_afTuple[0]) ^ _mask__NegFloat_;
        Wm4::UpdateBox_float_(
          (const Wm4::Vector2<float> *)&i[v50],
          (const Wm4::Vector2<float> *)&i[v44],
          &rkV,
          &__that,
          (const Wm4::Vector2<float> *)((char *)i + LODWORD(v76)),
          (const Wm4::Vector2<float> *)&i[v48],
          &rkU,
          &rfMinAreaDiv4);
        ++v75;
        *(_BYTE *)v69 = 1;
        if ( v75 == iVertexQuantity )
          v75 = 0;
        break;
      case 3:
        v52 = *((_BYTE *)p + v74) == 0;
        v66 = (char *)p + v74;
        if ( !v52 )
          goto LABEL_63;
        v54 = v69[1];
        rkU.m_afTuple[0] = *v69;
        rkU.m_afTuple[1] = v54;
        LODWORD(rkV.m_afTuple[0]) = LODWORD(v54) ^ _mask__NegFloat_;
        rkV.m_afTuple[1] = rkU.m_afTuple[0];
        Wm4::UpdateBox_float_(
          (const Wm4::Vector2<float> *)&i[v50],
          (const Wm4::Vector2<float> *)&i[v44],
          &rkV,
          &__that,
          (const Wm4::Vector2<float> *)((char *)i + LODWORD(v76)),
          (const Wm4::Vector2<float> *)&i[v48],
          &rkU,
          &rfMinAreaDiv4);
        ++v74;
        *v66 = 1;
        if ( v74 == iVertexQuantity )
          v74 = 0;
        break;
      default:
        v52 = *((_BYTE *)p + v73) == 0;
        v69 = (float *)((char *)p + v73);
        if ( !v52 )
          goto LABEL_63;
        LODWORD(v53) = *((_DWORD *)v66 + 1) ^ _mask__NegFloat_;
        LODWORD(rkU.m_afTuple[0]) = *(_DWORD *)v66 ^ _mask__NegFloat_;
        rkU.m_afTuple[1] = v53;
        LODWORD(rkV.m_afTuple[0]) = LODWORD(v53) ^ _mask__NegFloat_;
        rkV.m_afTuple[1] = rkU.m_afTuple[0];
        Wm4::UpdateBox_float_(
          (const Wm4::Vector2<float> *)&i[v50],
          (const Wm4::Vector2<float> *)&i[v44],
          &rkV,
          &__that,
          (const Wm4::Vector2<float> *)((char *)i + LODWORD(v76)),
          (const Wm4::Vector2<float> *)&i[v48],
          &rkU,
          &rfMinAreaDiv4);
        ++v73;
        *(_BYTE *)v69 = 1;
        if ( v73 == iVertexQuantity )
          v73 = 0;
        break;
    }
  }
LABEL_63:
  operator delete[](p);
  operator delete[](v68);
  operator delete[](i);
  v5 = iQuantity;
  Wm4::Box2<float>::Box2<float>(iQuantity, &__that);
  return v5;
}

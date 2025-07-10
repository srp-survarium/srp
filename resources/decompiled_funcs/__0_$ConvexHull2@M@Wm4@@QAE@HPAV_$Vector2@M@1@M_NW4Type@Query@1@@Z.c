void __userpurge Wm4::ConvexHull2<float>::ConvexHull2<float>(
        int iVertexQuantity@<eax>,
        Wm4::Vector2<float> *akVertex@<ecx>,
        const Wm4::Vector2<float> *a3@<edi>,
        Wm4::ConvexHull2<float> *this,
        float fEpsilon,
        bool bOwner,
        Wm4::Query::Type eQueryType)
{
  Wm4::Mapper2<float> *m_iVertexQuantity; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // edi
  bool v12; // cc
  Wm4::Vector2<float> *v13; // eax
  vostok::math::float2 *v14; // eax
  Wm4::Query2<float> *v15; // eax
  Wm4::Vector2<float> *m_akSVertex; // ecx
  int v17; // edx
  int v18; // ecx
  Wm4::Vector2<float> *v19; // eax
  double v20; // st7
  float *m_afTuple; // eax
  float v22; // eax
  int v23; // edi
  int *v24; // eax
  int v25; // edx
  int *v26; // edi
  int *v27; // eax
  int v28; // ecx
  int v29; // edi
  int *v30; // eax
  int v31; // edx
  int v32; // edx
  Wm4::ConvexHull2<float> *v33; // ecx
  int v34; // edi
  float v35; // edi
  _DWORD *v36; // eax
  _DWORD *v37; // esi
  _DWORD *v38; // eax
  _DWORD *v39; // edi
  float m_fEpsilon; // [esp+0h] [ebp-6Ch]
  const Wm4::Vector2<float> *v41; // [esp+4h] [ebp-68h]
  float fScale; // [esp+10h] [ebp-5Ch] BYREF
  Wm4::Vector2<float> kMin; // [esp+14h] [ebp-58h] BYREF
  Wm4::Vector2<float> v44; // [esp+1Ch] [ebp-50h] BYREF
  float v45[2]; // [esp+24h] [ebp-48h] BYREF
  Wm4::Mapper2<float> kMapper; // [esp+2Ch] [ebp-40h] BYREF

  this->m_fEpsilon = fEpsilon;
  v41 = a3;
  this->m_eQueryType = QT_REAL;
  this->m_iVertexQuantity = iVertexQuantity;
  this->m_iDimension = 0;
  this->m_iSimplexQuantity = 0;
  this->m_aiIndex = 0;
  this->m_bOwner = 0;
  this->__vftable = (Wm4::ConvexHull2<float>_vtbl *)&Wm4::ConvexHull2<float>::`vftable';
  Wm4::Vector2<float>::Vector2<float>(&this->m_kLineOrigin, &Wm4::Vector2<float>::ZERO);
  Wm4::Vector2<float>::Vector2<float>(&this->m_kLineDirection, &Wm4::Vector2<float>::ZERO);
  m_iVertexQuantity = (Wm4::Mapper2<float> *)this->m_iVertexQuantity;
  m_fEpsilon = this->m_fEpsilon;
  this->m_akVertex = akVertex;
  this->m_akSVertex = 0;
  this->m_pkQuery = 0;
  Wm4::Mapper2<float>::Mapper2<float>(m_iVertexQuantity, (int)m_iVertexQuantity, akVertex, m_fEpsilon);
  if ( !kMapper.m_iDimension )
    return;
  if ( kMapper.m_iDimension == 1 )
  {
    this->m_iDimension = 1;
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)&kMapper.m_kOrigin,
      (vostok::math::float2 *)&this->m_kLineOrigin);
    Wm4::Vector2<float>::operator=(
      (vostok::math::float2 *)kMapper.m_akDirection,
      (vostok::math::float2 *)&this->m_kLineDirection);
    return;
  }
  v9 = 8 * this->m_iVertexQuantity;
  v10 = (unsigned __int64)(unsigned int)this->m_iVertexQuantity >> 29 != 0;
  this->m_iDimension = 2;
  this->m_akSVertex = (Wm4::Vector2<float> *)operator new[](v9 | -v10);
  Wm4::Vector2<float>::Vector2<float>(&kMin, &kMapper.m_kMin);
  v11 = 0;
  v12 = this->m_iVertexQuantity <= 0;
  fScale = 1.0 / kMapper.m_fMaxRange;
  if ( !v12 )
  {
    do
    {
      v13 = Wm4::Vector2<float>::operator-(&kMin, &v44, &this->m_akVertex[v11], v41);
      v14 = (vostok::math::float2 *)Wm4::Vector2<float>::operator*(v45, v13->m_afTuple, fScale);
      Wm4::Vector2<float>::operator=(v14, (vostok::math::float2 *)&this->m_akSVertex[v11++]);
    }
    while ( v11 < this->m_iVertexQuantity );
  }
  v15 = (Wm4::Query2<float> *)operator new(0xCu);
  if ( v15 )
  {
    m_akSVertex = this->m_akSVertex;
    v17 = this->m_iVertexQuantity;
    v15->__vftable = (Wm4::Query2<float>_vtbl *)&Wm4::Query2<float>::`vftable';
    v15->m_iVQuantity = v17;
    v15->m_akVertex = m_akSVertex;
  }
  else
  {
    v15 = 0;
  }
  v18 = 0;
  v12 = this->m_iVertexQuantity <= 0;
  this->m_pkQuery = v15;
  if ( !v12 )
  {
    do
    {
      v19 = this->m_akSVertex;
      v20 = v19[v18].m_afTuple[0];
      m_afTuple = v19[v18].m_afTuple;
      *m_afTuple = v20;
      ++v18;
      m_afTuple[1] = m_afTuple[1];
    }
    while ( v18 < this->m_iVertexQuantity );
  }
  v22 = COERCE_FLOAT(operator new(0x18u));
  if ( kMapper.m_bExtremeCCW )
  {
    v23 = kMapper.m_aiExtreme[1];
    if ( v22 == 0.0 )
    {
      fScale = 0.0;
    }
    else
    {
      *(_DWORD *)LODWORD(v22) = kMapper.m_aiExtreme[0];
      *(_DWORD *)(LODWORD(v22) + 4) = v23;
      *(_DWORD *)(LODWORD(v22) + 8) = 0;
      *(_DWORD *)(LODWORD(v22) + 12) = 0;
      *(_DWORD *)(LODWORD(v22) + 16) = 0;
      *(_DWORD *)(LODWORD(v22) + 20) = -1;
      fScale = v22;
    }
    v24 = (int *)operator new(0x18u);
    if ( v24 )
    {
      v25 = kMapper.m_aiExtreme[2];
      *v24 = v23;
      v24[1] = v25;
      v24[2] = 0;
      v24[3] = 0;
      v24[4] = 0;
      v24[5] = -1;
      v26 = v24;
    }
    else
    {
      v26 = 0;
    }
    v27 = (int *)operator new(0x18u);
    if ( v27 )
    {
      v28 = kMapper.m_aiExtreme[2];
LABEL_28:
      v32 = kMapper.m_aiExtreme[0];
      v27[5] = -1;
      v27[4] = 0;
      v27[3] = 0;
      v27[2] = 0;
      v27[1] = v32;
      *v27 = v28;
      goto LABEL_30;
    }
  }
  else
  {
    v29 = kMapper.m_aiExtreme[2];
    if ( v22 == 0.0 )
    {
      fScale = 0.0;
    }
    else
    {
      *(_DWORD *)LODWORD(v22) = kMapper.m_aiExtreme[0];
      *(_DWORD *)(LODWORD(v22) + 4) = v29;
      *(_DWORD *)(LODWORD(v22) + 8) = 0;
      *(_DWORD *)(LODWORD(v22) + 12) = 0;
      *(_DWORD *)(LODWORD(v22) + 16) = 0;
      *(_DWORD *)(LODWORD(v22) + 20) = -1;
      fScale = v22;
    }
    v30 = (int *)operator new(0x18u);
    if ( v30 )
    {
      v31 = kMapper.m_aiExtreme[1];
      *v30 = v29;
      v30[1] = v31;
      v30[2] = 0;
      v30[3] = 0;
      v30[4] = 0;
      v30[5] = -1;
      v26 = v30;
    }
    else
    {
      v26 = 0;
    }
    v27 = (int *)operator new(0x18u);
    if ( v27 )
    {
      v28 = kMapper.m_aiExtreme[1];
      goto LABEL_28;
    }
  }
  v27 = 0;
LABEL_30:
  *(float *)&v33 = fScale;
  *(_DWORD *)(LODWORD(fScale) + 12) = v26;
  v26[2] = (int)v33;
  v26[3] = (int)v27;
  v33->m_iVertexQuantity = (int)v27;
  v27[2] = (int)v26;
  v27[3] = (int)v33;
  v34 = 0;
  v12 = this->m_iVertexQuantity <= 0;
  fScale = *(float *)&v33;
  if ( v12 )
  {
LABEL_33:
    v35 = fScale;
    Wm4::HullEdge2<float>::GetIndices(
      (Wm4::HullEdge2<float> *)LODWORD(fScale),
      &this->m_iSimplexQuantity,
      &this->m_aiIndex);
    v36 = *(_DWORD **)(LODWORD(v35) + 12);
    if ( v36 )
    {
      do
      {
        if ( v36 == (_DWORD *)LODWORD(v35) )
          break;
        v37 = (_DWORD *)v36[3];
        operator delete(v36);
        v36 = v37;
      }
      while ( v37 );
    }
    operator delete((void *)LODWORD(v35));
  }
  else
  {
    while ( Wm4::ConvexHull2<float>::Update(v33, (Wm4::HullEdge2<float> **)this, (int)&fScale) )
    {
      if ( ++v34 >= this->m_iVertexQuantity )
        goto LABEL_33;
    }
    v38 = *(_DWORD **)(LODWORD(fScale) + 12);
    if ( v38 )
    {
      do
      {
        if ( v38 == (_DWORD *)LODWORD(fScale) )
          break;
        v39 = (_DWORD *)v38[3];
        operator delete(v38);
        v38 = v39;
      }
      while ( v39 );
    }
    operator delete((void *)LODWORD(fScale));
  }
}

void __userpurge Wm4::ConvexHull2<float>::ConvexHull2<float>(
        Wm4::Vector2<float> *akVertex@<eax>,
        int a2@<edi>,
        Wm4::HullEdge2<float> **this,
        int iVertexQuantity,
        float fEpsilon,
        bool bOwner,
        Wm4::Query::Type eQueryType)
{
  Wm4::ConvexHull2<float> *v7; // ebx
  Wm4::Mapper2<float> *v9; // ecx
  float v10; // xmm0_4
  int v11; // eax
  int v12; // ecx
  Wm4::Vector2<float> *v13; // eax
  float v14; // xmm2_4
  int v15; // esi
  int v16; // ecx
  bool v17; // cc
  float *m_afTuple; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // eax
  float v22; // xmm1_4
  Wm4::Query2<float> *v23; // eax
  Wm4::Vector2<float> *m_akSVertex; // ecx
  int v25; // edx
  int v26; // ecx
  float *v27; // eax
  Wm4::HullEdge2<float> **v28; // eax
  Wm4::ConvexHull2<float> *v29; // eax
  Wm4::ConvexHull2<float> *v30; // edi
  Wm4::HullEdge2<float> **v31; // eax
  int v32; // eax
  Wm4::HullEdge2<float> **v33; // eax
  int m_iSimplexQuantity; // ecx
  Wm4::HullEdge2<float> *v35; // ecx
  Wm4::ConvexHull2<float> *v36; // eax
  Wm4::HullEdge2<float> **v37; // eax
  int v38; // eax
  int v39; // eax
  Wm4::HullEdge2<float> *v40; // esi
  Wm4::ConvexHull2<float> *v41; // edi
  Wm4::ConvexHull2<float> *m_iDimension; // ecx
  Wm4::ConvexHull2<float> *v43; // eax
  int m_iVertexQuantity; // [esp-8h] [ebp-5Ch]
  float fEpsilona; // [esp+0h] [ebp-54h]
  Wm4::ConvexHull2<float> *fEpsilonb; // [esp+0h] [ebp-54h]
  Wm4::ConvexHull2<float> *fEpsilonc; // [esp+0h] [ebp-54h]
  int v48; // [esp+4h] [ebp-50h]
  float v49[5]; // [esp+14h] [ebp-40h] BYREF
  int v50; // [esp+28h] [ebp-2Ch]
  Wm4::HullEdge2<float> *v51; // [esp+2Ch] [ebp-28h]
  int iV0; // [esp+30h] [ebp-24h]
  Wm4::HullEdge2<float> *v53; // [esp+34h] [ebp-20h]
  char v54; // [esp+38h] [ebp-1Ch]
  float v55; // [esp+3Ch] [ebp-18h]
  float v56; // [esp+40h] [ebp-14h]
  float v57; // [esp+44h] [ebp-10h]
  float v58; // [esp+48h] [ebp-Ch]

  v7 = (Wm4::ConvexHull2<float> *)this;
  v48 = a2;
  Wm4::ConvexHull<float>::ConvexHull<float>((int)this, 3, 0, iVertexQuantity, 0);
  v7->__vftable = (Wm4::ConvexHull2<float>_vtbl *)&Wm4::ConvexHull2<float>::`vftable';
  v7->m_kLineOrigin = Wm4::Vector2<float>::ZERO;
  v7->m_kLineDirection = Wm4::Vector2<float>::ZERO;
  fEpsilona = v7->m_fEpsilon;
  m_iVertexQuantity = v7->m_iVertexQuantity;
  v7->m_akVertex = akVertex;
  v7->m_akSVertex = 0;
  v7->m_pkQuery = 0;
  Wm4::Mapper2<float>::Mapper2<float>(v9, (int)v49, m_iVertexQuantity, akVertex, fEpsilona);
  if ( !v50 )
    return;
  if ( v50 == 1 )
  {
    v10 = v55;
    v7->m_iDimension = 1;
    v7->m_kLineOrigin.m_afTuple[0] = v10;
    v7->m_kLineOrigin.m_afTuple[1] = v56;
    v7->m_kLineDirection.m_afTuple[0] = v57;
    v7->m_kLineDirection.m_afTuple[1] = v58;
    return;
  }
  v11 = 8 * v7->m_iVertexQuantity;
  v12 = (unsigned __int64)(unsigned int)v7->m_iVertexQuantity >> 29 != 0;
  v7->m_iDimension = 2;
  v13 = (Wm4::Vector2<float> *)operator new[](v11 | -v12);
  v14 = s_bm_current_air_resistance / v49[4];
  v15 = 0;
  v16 = 0;
  v17 = v7->m_iVertexQuantity <= 0;
  v7->m_akSVertex = v13;
  if ( !v17 )
  {
    do
    {
      m_afTuple = v7->m_akVertex[v16].m_afTuple;
      v19 = *m_afTuple;
      v20 = m_afTuple[1];
      v21 = v7->m_akSVertex[v16].m_afTuple;
      v22 = (float)(v20 - v49[1]) * v14;
      ++v16;
      *v21 = (float)(v19 - v49[0]) * v14;
      v21[1] = v22;
    }
    while ( v16 < v7->m_iVertexQuantity );
  }
  v23 = (Wm4::Query2<float> *)operator new(0xCu);
  if ( v23 )
  {
    m_akSVertex = v7->m_akSVertex;
    v25 = v7->m_iVertexQuantity;
    v23->__vftable = (Wm4::Query2<float>_vtbl *)&Wm4::Query2<float>::`vftable';
    v23->m_iVQuantity = v25;
    v23->m_akVertex = m_akSVertex;
  }
  else
  {
    v23 = 0;
  }
  v26 = 0;
  v17 = v7->m_iVertexQuantity <= 0;
  v7->m_pkQuery = v23;
  if ( !v17 )
  {
    do
    {
      v27 = v7->m_akSVertex[v26++].m_afTuple;
      *v27 = *v27;
      v27[1] = v27[1];
    }
    while ( v26 < v7->m_iVertexQuantity );
  }
  v28 = (Wm4::HullEdge2<float> **)operator new(0x18u);
  if ( !v54 )
  {
    if ( v28 )
    {
      Wm4::HullEdge2<float>::HullEdge2<float>(v51, v28, v53, a2);
      v30 = v36;
    }
    else
    {
      v30 = 0;
    }
    v37 = (Wm4::HullEdge2<float> **)operator new(0x18u);
    if ( v37 )
    {
      Wm4::HullEdge2<float>::HullEdge2<float>(v53, v37, (Wm4::HullEdge2<float> *)iV0, v48);
      v15 = v38;
    }
    v33 = (Wm4::HullEdge2<float> **)operator new(0x18u);
    m_iSimplexQuantity = (int)fEpsilonc;
    if ( v33 )
    {
      v35 = (Wm4::HullEdge2<float> *)iV0;
      goto LABEL_26;
    }
LABEL_27:
    v39 = 0;
    goto LABEL_28;
  }
  if ( v28 )
  {
    Wm4::HullEdge2<float>::HullEdge2<float>(v51, v28, (Wm4::HullEdge2<float> *)iV0, a2);
    v30 = v29;
  }
  else
  {
    v30 = 0;
  }
  v31 = (Wm4::HullEdge2<float> **)operator new(0x18u);
  if ( v31 )
  {
    Wm4::HullEdge2<float>::HullEdge2<float>((Wm4::HullEdge2<float> *)iV0, v31, v53, v48);
    v15 = v32;
  }
  v33 = (Wm4::HullEdge2<float> **)operator new(0x18u);
  m_iSimplexQuantity = (int)fEpsilonb;
  if ( !v33 )
    goto LABEL_27;
  v35 = v53;
LABEL_26:
  Wm4::HullEdge2<float>::HullEdge2<float>(v35, v33, v51, v48);
LABEL_28:
  v30->m_iDimension = v15;
  *(_DWORD *)(v15 + 8) = v30;
  *(_DWORD *)(v15 + 12) = v39;
  v30->m_iVertexQuantity = v39;
  *(_DWORD *)(v39 + 8) = v15;
  v40 = 0;
  *(_DWORD *)(v39 + 12) = v30;
  v17 = v7->m_iVertexQuantity <= 0;
  this = (Wm4::HullEdge2<float> **)v30;
  if ( v17 )
  {
LABEL_31:
    v41 = (Wm4::ConvexHull2<float> *)this;
    v7->m_iSimplexQuantity = 0;
    m_iDimension = v41;
    do
    {
      ++v7->m_iSimplexQuantity;
      m_iDimension = (Wm4::ConvexHull2<float> *)m_iDimension->m_iDimension;
    }
    while ( m_iDimension != v41 );
    v7->m_aiIndex = (int *)operator new[](4 * v7->m_iSimplexQuantity);
    v7->m_iSimplexQuantity = 0;
    v43 = v41;
    do
    {
      m_iSimplexQuantity = v7->m_iSimplexQuantity;
      v7->m_aiIndex[m_iSimplexQuantity] = (int)v43->__vftable;
      ++v7->m_iSimplexQuantity;
      v43 = (Wm4::ConvexHull2<float> *)v43->m_iDimension;
    }
    while ( v43 != v41 );
  }
  else
  {
    while ( Wm4::ConvexHull2<float>::Update(
              (Wm4::ConvexHull2<float> *)m_iSimplexQuantity,
              (int)v7,
              (Wm4::HullEdge2<float> **)v7,
              (Wm4::HullEdge2<float> **)&this,
              v40) )
    {
      v40 = (Wm4::HullEdge2<float> *)((char *)v40 + 1);
      if ( (int)v40 >= v7->m_iVertexQuantity )
        goto LABEL_31;
    }
    v41 = (Wm4::ConvexHull2<float> *)this;
  }
  Wm4::HullEdge2<float>::DeleteAll((Wm4::HullEdge2<float> *)m_iSimplexQuantity, v41);
}

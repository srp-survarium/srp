void __thiscall Scaleform::Render::Tessellator::processEdgeAA(Scaleform::Render::Tessellator *this)
{
  unsigned int v2; // ebx
  unsigned int i; // edi
  int v4; // eax
  unsigned __int8 *v5; // ebp
  Scaleform::Render::Tessellator::EdgeAAType *Array; // eax
  unsigned int Size; // ecx
  unsigned int v8; // ecx
  unsigned int j; // edx
  Scaleform::Render::TessVertex *v10; // eax
  int Mesh; // edi
  unsigned int k; // edi
  unsigned int v13; // edi
  Scaleform::Render::TessVertex *v14; // ebp
  Scaleform::Render::Tessellator::EdgeAAType *v15; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *rayVer; // edx
  Scaleform::Render::Tessellator::EdgeAAType *v17; // eax
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // ecx
  unsigned int v19; // eax
  Scaleform::Render::TessVertex **Pages; // edx
  float *p_x; // eax
  float *v22; // ecx
  unsigned int v23; // edi
  Scaleform::Render::Tessellator::TmpEdgeAAType *v24; // edi
  unsigned int v25; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v26; // eax
  Scaleform::Render::Tessellator::TmpEdgeAAType *v27; // ecx
  unsigned int m; // edi
  unsigned int v29; // [esp+20h] [ebp-24h]
  unsigned int v30; // [esp+20h] [ebp-24h]
  unsigned __int16 v31; // [esp+24h] [ebp-20h]
  unsigned int v32; // [esp+28h] [ebp-1Ch]
  float slope; // [esp+2Ch] [ebp-18h]
  unsigned int v34; // [esp+30h] [ebp-14h]
  Scaleform::Render::Tessellator::MonoVertexType *v35; // [esp+34h] [ebp-10h]
  Scaleform::Render::Tessellator::MonoVertexType *v36; // [esp+38h] [ebp-Ch]
  float v37; // [esp+3Ch] [ebp-8h]
  unsigned int style; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < this->Monotones.Size; v2 += v4 )
  {
    v4 = Scaleform::Render::Tessellator::countFanEdges(this, &this->Monotones.Pages[i >> 4][i & 0xF]);
    ++i;
  }
  if ( v2 > this->EdgeFans.Size )
  {
    v5 = Scaleform::Render::LinearHeap::Alloc(this->EdgeFans.pHeap, 12 * v2);
    memset((int)v5, 0, 12 * v2);
    Array = this->EdgeFans.Array;
    if ( Array )
    {
      Size = this->EdgeFans.Size;
      if ( Size )
        memcpy((int)v5, (const __m128i *)Array, 12 * Size);
    }
    this->EdgeFans.Array = (Scaleform::Render::Tessellator::EdgeAAType *)v5;
  }
  v8 = 0;
  this->EdgeFans.Size = v2;
  for ( j = 0; v8 < this->MeshVertices.Size; v10->Mesh = 0 )
  {
    v10 = &this->MeshVertices.Pages[v8 >> 4][v8 & 0xF];
    Mesh = v10->Mesh;
    v10->Idx = j;
    j += Mesh;
    ++v8;
  }
  for ( k = 0; k < this->Monotones.Size; ++k )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->Monotones.Pages[k >> 4][k & 0xF]);
  v13 = 0;
  v34 = this->MeshVertices.Size;
  v32 = 0;
  if ( v34 )
  {
    do
    {
      v14 = &this->MeshVertices.Pages[v13 >> 4][v13 & 0xF];
      this->TmpEdgeFan.Size = 0;
      v29 = 0;
      if ( v14->Mesh )
      {
        do
        {
          v15 = this->EdgeFans.Array;
          rayVer = v15[v29 + v14->Idx].rayVer;
          v17 = &v15[v29 + v14->Idx];
          cntVer = v17->cntVer;
          style = v17->style;
          v19 = rayVer->srcVer & 0xFFFFFFF;
          v35 = cntVer;
          v36 = rayVer;
          Pages = this->MeshVertices.Pages;
          p_x = &Pages[v19 >> 4][v19 & 0xF].x;
          v22 = &Pages[(cntVer->srcVer & 0xFFFFFFF) >> 4][cntVer->srcVer & 0xF].x;
          v37 = Scaleform::Render::Math2D::SlopeRatio(*v22, v22[1], *p_x, p_x[1]);
          v23 = this->TmpEdgeFan.Size >> 3;
          if ( v23 >= this->TmpEdgeFan.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>::allocPage(
              &this->TmpEdgeFan,
              v23);
          v24 = &this->TmpEdgeFan.Pages[v23][this->TmpEdgeFan.Size & 7];
          v24->cntVer = v35;
          v24->rayVer = v36;
          v24->slope = v37;
          v24->style = style;
          ++this->TmpEdgeFan.Size;
          ++v29;
        }
        while ( v29 < v14->Mesh );
        v13 = v32;
      }
      Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>,bool (__cdecl *)(Scaleform::Render::Tessellator::TmpEdgeAAType const &,Scaleform::Render::Tessellator::TmpEdgeAAType const &)>(
        &this->TmpEdgeFan,
        0,
        this->TmpEdgeFan.Size,
        (bool (__cdecl *)(const Scaleform::Render::Tessellator::TmpEdgeAAType *, const Scaleform::Render::Tessellator::TmpEdgeAAType *))Scaleform::Render::Tessellator::cmpEdgeAA);
      v25 = 0;
      slope = -1.0e30;
      v31 = 0;
      v30 = 0;
      if ( this->TmpEdgeFan.Size )
      {
        do
        {
          v26 = &this->EdgeFans.Array[v25 + v14->Idx];
          v27 = &this->TmpEdgeFan.Pages[v25 >> 3][v25 & 7];
          v26->cntVer = v27->cntVer;
          v26->rayVer = v27->rayVer;
          v26->style = v27->style;
          v26->slope = v31;
          if ( slope != v27->slope )
          {
            ++v31;
            slope = v27->slope;
          }
          v25 = v30 + 1;
          v30 = v25;
        }
        while ( v25 < this->TmpEdgeFan.Size );
        v13 = v32;
      }
      Scaleform::Render::Tessellator::processFan(this, v14->Idx, v14->Idx + v14->Mesh);
      ++v13;
      v14->Idx = -1;
      v14->Mesh = -1;
      v32 = v13;
    }
    while ( v13 < v34 );
  }
  for ( m = 0; m < this->Monotones.Size; ++m )
    Scaleform::Render::Tessellator::triangulateMonotoneAA(
      this,
      (Scaleform::Render::Tessellator::MonoVertexType *)&this->Monotones.Pages[m >> 4][m & 0xF]);
  Scaleform::Render::Tessellator::unflipTriangles(this);
  Scaleform::Render::Tessellator::emitTriangles(this);
}

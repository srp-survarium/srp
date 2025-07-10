void __thiscall Scaleform::Render::Tessellator::processEdgeAA(Scaleform::Render::Tessellator *this)
{
  unsigned int v2; // ebx
  unsigned int k; // edi
  unsigned int v4; // eax
  unsigned __int8 *v5; // ebp
  unsigned __int8 *Array; // eax
  unsigned int Size; // ecx
  unsigned int v8; // ecx
  unsigned int m; // edx
  Scaleform::Render::TessVertex *v10; // eax
  int Mesh; // edi
  unsigned int n; // edi
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
  unsigned int ii; // edi
  unsigned int j; // [esp+20h] [ebp-24h]
  unsigned int ja; // [esp+20h] [ebp-24h]
  unsigned __int16 slopeIdx; // [esp+24h] [ebp-20h]
  unsigned int i; // [esp+28h] [ebp-1Ch]
  float slope; // [esp+2Ch] [ebp-18h]
  unsigned int numVertices; // [esp+30h] [ebp-14h]
  Scaleform::Render::Tessellator::MonoVertexType *te; // [esp+34h] [ebp-10h]
  Scaleform::Render::Tessellator::MonoVertexType *te_4; // [esp+38h] [ebp-Ch]
  float te_8; // [esp+3Ch] [ebp-8h]
  unsigned int te_12; // [esp+40h] [ebp-4h]

  v2 = 0;
  for ( k = 0; k < this->Monotones.Size; v2 += v4 )
  {
    v4 = Scaleform::Render::Tessellator::countFanEdges(this, &this->Monotones.Pages[k >> 4][k & 0xF]);
    ++k;
  }
  if ( v2 > this->EdgeFans.Size )
  {
    v5 = Scaleform::Render::LinearHeap::Alloc(this->EdgeFans.pHeap, 12 * v2);
    memset((int)v5, 0, 12 * v2);
    Array = (unsigned __int8 *)this->EdgeFans.Array;
    if ( Array )
    {
      Size = this->EdgeFans.Size;
      if ( Size )
        memcpy(v5, Array, 12 * Size);
    }
    this->EdgeFans.Array = (Scaleform::Render::Tessellator::EdgeAAType *)v5;
  }
  v8 = 0;
  this->EdgeFans.Size = v2;
  for ( m = 0; v8 < this->MeshVertices.Size; v10->Mesh = 0 )
  {
    v10 = &this->MeshVertices.Pages[v8 >> 4][v8 & 0xF];
    Mesh = v10->Mesh;
    v10->Idx = m;
    m += Mesh;
    ++v8;
  }
  for ( n = 0; n < this->Monotones.Size; ++n )
    Scaleform::Render::Tessellator::collectFanEdges(this, &this->Monotones.Pages[n >> 4][n & 0xF]);
  v13 = 0;
  numVertices = this->MeshVertices.Size;
  i = 0;
  if ( numVertices )
  {
    do
    {
      v14 = &this->MeshVertices.Pages[v13 >> 4][v13 & 0xF];
      this->TmpEdgeFan.Size = 0;
      j = 0;
      if ( v14->Mesh )
      {
        do
        {
          v15 = this->EdgeFans.Array;
          rayVer = v15[j + v14->Idx].rayVer;
          v17 = &v15[j + v14->Idx];
          cntVer = v17->cntVer;
          te_12 = v17->style;
          v19 = rayVer->srcVer & 0xFFFFFFF;
          te = cntVer;
          te_4 = rayVer;
          Pages = this->MeshVertices.Pages;
          p_x = &Pages[v19 >> 4][v19 & 0xF].x;
          v22 = &Pages[(cntVer->srcVer & 0xFFFFFFF) >> 4][cntVer->srcVer & 0xF].x;
          te_8 = Scaleform::Render::Math2D::SlopeRatio(*v22, v22[1], *p_x, p_x[1]);
          v23 = this->TmpEdgeFan.Size >> 3;
          if ( v23 >= this->TmpEdgeFan.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>::allocPage(
              &this->TmpEdgeFan,
              v23);
          v24 = &this->TmpEdgeFan.Pages[v23][this->TmpEdgeFan.Size & 7];
          v24->cntVer = te;
          v24->rayVer = te_4;
          v24->slope = te_8;
          v24->style = te_12;
          ++this->TmpEdgeFan.Size;
          ++j;
        }
        while ( j < v14->Mesh );
        v13 = i;
      }
      Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::TmpEdgeAAType,3,4>,bool (__cdecl *)(Scaleform::Render::Tessellator::TmpEdgeAAType const &,Scaleform::Render::Tessellator::TmpEdgeAAType const &)>(
        &this->TmpEdgeFan,
        0,
        this->TmpEdgeFan.Size,
        (bool (__cdecl *)(const Scaleform::Render::Tessellator::TmpEdgeAAType *, const Scaleform::Render::Tessellator::TmpEdgeAAType *))Scaleform::Render::Tessellator::cmpEdgeAA);
      v25 = 0;
      slope = -1.0e30;
      slopeIdx = 0;
      ja = 0;
      if ( this->TmpEdgeFan.Size )
      {
        do
        {
          v26 = &this->EdgeFans.Array[v25 + v14->Idx];
          v27 = &this->TmpEdgeFan.Pages[v25 >> 3][v25 & 7];
          v26->cntVer = v27->cntVer;
          v26->rayVer = v27->rayVer;
          v26->style = v27->style;
          v26->slope = slopeIdx;
          if ( slope != v27->slope )
          {
            ++slopeIdx;
            slope = v27->slope;
          }
          v25 = ja + 1;
          ja = v25;
        }
        while ( v25 < this->TmpEdgeFan.Size );
        v13 = i;
      }
      Scaleform::Render::Tessellator::processFan(this, v14->Idx, v14->Idx + v14->Mesh);
      ++v13;
      v14->Idx = -1;
      v14->Mesh = -1;
      i = v13;
    }
    while ( v13 < numVertices );
  }
  for ( ii = 0; ii < this->Monotones.Size; ++ii )
    Scaleform::Render::Tessellator::triangulateMonotoneAA(
      this,
      (Scaleform::Render::Tessellator::MonoVertexType *)&this->Monotones.Pages[ii >> 4][ii & 0xF]);
  Scaleform::Render::Tessellator::unflipTriangles(this);
  Scaleform::Render::Tessellator::emitTriangles(this);
}

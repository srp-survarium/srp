void __thiscall Scaleform::Render::Hairliner::buildGraph(Scaleform::Render::Hairliner *this)
{
  unsigned int v2; // ebp
  unsigned int v3; // ebx
  unsigned int v4; // ebp
  unsigned int v5; // edi
  double y; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v7; // ecx
  unsigned int i; // edi
  unsigned int j; // ebp
  unsigned int v10; // edi
  unsigned int MaxPages; // eax
  unsigned __int8 *v12; // ebx
  unsigned int v13; // ecx
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned int v15; // ebx
  unsigned int v16; // ebp
  unsigned int v17; // edi
  double v18; // st7
  unsigned int v19; // eax
  unsigned int k; // edi
  Scaleform::Render::Hairliner::MonoChainType ***Pages; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v22; // edx
  unsigned int v23; // [esp+20h] [ebp-18h]
  float v24; // [esp+24h] [ebp-14h]
  float yb; // [esp+28h] [ebp-10h]
  unsigned int v26; // [esp+2Ch] [ebp-Ch]
  unsigned int v27; // [esp+2Ch] [ebp-Ch]
  float v28; // [esp+30h] [ebp-8h]
  Scaleform::Render::Hairliner::MonoChainType *v29; // [esp+30h] [ebp-8h]
  unsigned int v30; // [esp+30h] [ebp-8h]
  unsigned int v31; // [esp+34h] [ebp-4h]
  char Scanbeam; // [esp+34h] [ebp-4h]

  if ( this->SrcVertices.Size )
  {
    v2 = 0;
    do
    {
      v3 = this->Scanbeams.Size >> 4;
      if ( v3 >= this->Scanbeams.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
          &this->Scanbeams,
          this->Scanbeams.Size >> 4);
      this->Scanbeams.Pages[v3][this->Scanbeams.Size++ & 0xF] = v2++;
    }
    while ( v2 < this->SrcVertices.Size );
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &this->Scanbeams,
      0,
      this->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&this->SrcVertices);
    v4 = 0;
    v5 = 0;
    v26 = 0;
    if ( this->Scanbeams.Size )
    {
      y = (float)-1.0e30;
      do
      {
        v7 = &this->SrcVertices.Pages[this->Scanbeams.Pages[v4 >> 4][v4 & 0xF] >> 4][this->Scanbeams.Pages[v4 >> 4][v4 & 0xF]
                                                                                   & 0xF];
        v28 = fabs(v7->y);
        if ( v28 * this->Epsilon >= v7->y - y )
        {
          v7->y = y;
        }
        else
        {
          this->Scanbeams.Pages[v5 >> 4][v5 & 0xF] = this->Scanbeams.Pages[v4 >> 4][v4 & 0xF];
          v4 = v26;
          y = v7->y;
          ++v5;
        }
        v26 = ++v4;
      }
      while ( v4 < this->Scanbeams.Size );
    }
    if ( v5 < this->Scanbeams.Size )
      this->Scanbeams.Size = v5;
    for ( i = 0; i < this->Paths.Size; ++i )
      Scaleform::Render::Hairliner::decomposePath(this, &this->Paths.Pages[i >> 4][i & 0xF]);
    for ( j = 0; j < this->MonoChains.Size; ++j )
    {
      v10 = this->MonoChainsSorted.Size >> 4;
      v29 = &this->MonoChains.Pages[j >> 4][j & 0xF];
      if ( v10 >= this->MonoChainsSorted.NumPages )
      {
        MaxPages = this->MonoChainsSorted.MaxPages;
        if ( v10 >= MaxPages )
        {
          if ( this->MonoChainsSorted.Pages )
          {
            v12 = Scaleform::Render::LinearHeap::Alloc(this->MonoChainsSorted.pHeap, 8 * MaxPages);
            memcpy((int)v12, (const __m128i *)this->MonoChainsSorted.Pages, 4 * this->MonoChainsSorted.NumPages);
            v13 = this->MonoChainsSorted.MaxPages;
            this->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v12;
            this->MonoChainsSorted.MaxPages = 2 * v13;
          }
          else
          {
            pHeap = this->MonoChainsSorted.pHeap;
            this->MonoChainsSorted.MaxPages = 8;
            this->MonoChainsSorted.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)Scaleform::Render::LinearHeap::Alloc(
                                                                                              pHeap,
                                                                                              0x20u);
          }
        }
        this->MonoChainsSorted.Pages[v10] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(
                                                                                              this->MonoChainsSorted.pHeap,
                                                                                              0x40u);
        ++this->MonoChainsSorted.NumPages;
      }
      this->MonoChainsSorted.Pages[v10][this->MonoChainsSorted.Size++ & 0xF] = v29;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>,bool (__cdecl *)(Scaleform::Render::Hairliner::HorizontalEdgeType const &,Scaleform::Render::Hairliner::HorizontalEdgeType const &)>(
      &this->HorizontalEdges,
      0,
      this->HorizontalEdges.Size,
      (bool (__cdecl *)(const Scaleform::Render::Hairliner::HorizontalEdgeType *, const Scaleform::Render::Hairliner::HorizontalEdgeType *))Scaleform::Render::Scale9GridTess::cmpSlopes);
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8>,bool (__cdecl *)(Scaleform::Render::Hairliner::MonoChainType const *,Scaleform::Render::Hairliner::MonoChainType const *)>(
      &this->MonoChainsSorted,
      0,
      this->MonoChainsSorted.Size,
      (bool (__cdecl *)(const Scaleform::Render::Hairliner::MonoChainType *, const Scaleform::Render::Hairliner::MonoChainType *))Scaleform::Render::Hairliner::cmpMonoChains);
    v15 = 0;
    v24 = this->SrcVertices.Pages[**this->Scanbeams.Pages >> 4][**this->Scanbeams.Pages & 0xF].y;
    v16 = 0;
    yb = v24;
    v17 = 0;
    v27 = 0;
    this->LastX = -1.0e30;
    v23 = 0;
    for ( this->LastY = -1.0e30; v17 < this->Scanbeams.Size; yb = v24 )
    {
      v30 = ++v17;
      if ( v17 < this->Scanbeams.Size )
        v24 = this->SrcVertices.Pages[this->Scanbeams.Pages[v17 >> 4][v17 & 0xF] >> 4][this->Scanbeams.Pages[v17 >> 4][v17 & 0xF]
                                                                                     & 0xF].y;
      v18 = yb;
      v31 = v16;
      if ( v16 < this->MonoChainsSorted.Size )
      {
        do
        {
          if ( this->MonoChainsSorted.Pages[v16 >> 4][v16 & 0xF]->ySort > v18 )
            break;
          ++v16;
        }
        while ( v16 < this->MonoChainsSorted.Size );
        v27 = v16;
      }
      this->StartHorizontals = v15;
      if ( v15 < this->HorizontalEdges.Size )
      {
        do
        {
          if ( this->HorizontalEdges.Pages[v15 >> 2][v15 & 3].y > v18 )
            break;
          ++v15;
        }
        while ( v15 < this->HorizontalEdges.Size );
        v23 = v15;
      }
      this->NumHorizontals = v15 - this->StartHorizontals;
      Scanbeam = Scaleform::Render::Hairliner::nextScanbeam(this, yb, v24, v31, v16 - v31);
      if ( this->Intersections.Size )
        Scaleform::Render::Hairliner::processInterior(this, yb);
      else
        Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ActiveChains, yb);
      if ( (Scanbeam & 2) != 0 )
      {
        v19 = 0;
        for ( k = 0; v19 < this->ActiveChains.Size; ++v19 )
        {
          Pages = this->ActiveChains.Pages;
          v22 = Pages[v19 >> 4][v19 & 0xF];
          if ( (v22->flags & 1) == 0 )
          {
            Pages[k >> 4][k & 0xF] = v22;
            v16 = v27;
            ++k;
          }
          v15 = v23;
        }
        if ( k < this->ActiveChains.Size )
          this->ActiveChains.Size = k;
        v17 = v30;
      }
    }
  }
}

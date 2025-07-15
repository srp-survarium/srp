void __thiscall Scaleform::Render::Hairliner::buildGraph(Scaleform::Render::Hairliner *this)
{
  unsigned int v2; // ebp
  unsigned int v3; // ebx
  unsigned int v4; // ebp
  unsigned int v5; // edi
  double y; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v7; // ecx
  unsigned int j; // edi
  unsigned int k; // ebp
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
  unsigned int m; // edi
  Scaleform::Render::Hairliner::MonoChainType ***Pages; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v22; // edx
  unsigned int he; // [esp+20h] [ebp-18h]
  float yt; // [esp+24h] [ebp-14h]
  float y1; // [esp+28h] [ebp-10h]
  unsigned int i; // [esp+2Ch] [ebp-Ch]
  unsigned int ia; // [esp+2Ch] [ebp-Ch]
  float sbb; // [esp+30h] [ebp-8h]
  Scaleform::Render::Hairliner::MonoChainType *sb; // [esp+30h] [ebp-8h]
  unsigned int sba; // [esp+30h] [ebp-8h]
  unsigned int flags; // [esp+34h] [ebp-4h]
  char flagsa; // [esp+34h] [ebp-4h]

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
    i = 0;
    if ( this->Scanbeams.Size )
    {
      y = (float)-1.0e30;
      do
      {
        v7 = &this->SrcVertices.Pages[this->Scanbeams.Pages[v4 >> 4][v4 & 0xF] >> 4][this->Scanbeams.Pages[v4 >> 4][v4 & 0xF]
                                                                                   & 0xF];
        sbb = fabs(v7->y);
        if ( sbb * this->Epsilon >= v7->y - y )
        {
          v7->y = y;
        }
        else
        {
          this->Scanbeams.Pages[v5 >> 4][v5 & 0xF] = this->Scanbeams.Pages[v4 >> 4][v4 & 0xF];
          v4 = i;
          y = v7->y;
          ++v5;
        }
        i = ++v4;
      }
      while ( v4 < this->Scanbeams.Size );
    }
    if ( v5 < this->Scanbeams.Size )
      this->Scanbeams.Size = v5;
    for ( j = 0; j < this->Paths.Size; ++j )
      Scaleform::Render::Hairliner::decomposePath(this, (int)&this->Paths.Pages[j >> 4][j & 0xF]);
    for ( k = 0; k < this->MonoChains.Size; ++k )
    {
      v10 = this->MonoChainsSorted.Size >> 4;
      sb = &this->MonoChains.Pages[k >> 4][k & 0xF];
      if ( v10 >= this->MonoChainsSorted.NumPages )
      {
        MaxPages = this->MonoChainsSorted.MaxPages;
        if ( v10 >= MaxPages )
        {
          if ( this->MonoChainsSorted.Pages )
          {
            v12 = Scaleform::Render::LinearHeap::Alloc(this->MonoChainsSorted.pHeap, 8 * MaxPages);
            memcpy(v12, (unsigned __int8 *)this->MonoChainsSorted.Pages, 4 * this->MonoChainsSorted.NumPages);
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
      this->MonoChainsSorted.Pages[v10][this->MonoChainsSorted.Size++ & 0xF] = sb;
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
    yt = this->SrcVertices.Pages[**this->Scanbeams.Pages >> 4][**this->Scanbeams.Pages & 0xF].y;
    v16 = 0;
    y1 = yt;
    v17 = 0;
    ia = 0;
    this->LastX = -1.0e30;
    he = 0;
    for ( this->LastY = -1.0e30; v17 < this->Scanbeams.Size; y1 = yt )
    {
      sba = ++v17;
      if ( v17 < this->Scanbeams.Size )
        yt = this->SrcVertices.Pages[this->Scanbeams.Pages[v17 >> 4][v17 & 0xF] >> 4][this->Scanbeams.Pages[v17 >> 4][v17 & 0xF]
                                                                                    & 0xF].y;
      v18 = y1;
      flags = v16;
      if ( v16 < this->MonoChainsSorted.Size )
      {
        do
        {
          if ( this->MonoChainsSorted.Pages[v16 >> 4][v16 & 0xF]->ySort > v18 )
            break;
          ++v16;
        }
        while ( v16 < this->MonoChainsSorted.Size );
        ia = v16;
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
        he = v15;
      }
      this->NumHorizontals = v15 - this->StartHorizontals;
      flagsa = Scaleform::Render::Hairliner::nextScanbeam(this, y1, yt, flags, v16 - flags);
      if ( this->Intersections.Size )
        Scaleform::Render::Hairliner::processInterior(this, y1);
      else
        Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ActiveChains, y1);
      if ( (flagsa & 2) != 0 )
      {
        v19 = 0;
        for ( m = 0; v19 < this->ActiveChains.Size; ++v19 )
        {
          Pages = this->ActiveChains.Pages;
          v22 = Pages[v19 >> 4][v19 & 0xF];
          if ( (v22->flags & 1) == 0 )
          {
            Pages[m >> 4][m & 0xF] = v22;
            v16 = ia;
            ++m;
          }
          v15 = he;
        }
        if ( m < this->ActiveChains.Size )
          this->ActiveChains.Size = m;
        v17 = sba;
      }
    }
  }
}

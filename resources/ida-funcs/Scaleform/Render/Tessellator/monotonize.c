void __thiscall Scaleform::Render::Tessellator::monotonize(Scaleform::Render::Tessellator *this)
{
  unsigned int i; // ebx
  unsigned int v3; // ebp
  unsigned int v4; // edx
  unsigned int v5; // ebx
  double v6; // st7
  unsigned int v7; // ecx
  int v8; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v9; // edi
  unsigned int v10; // eax
  double y; // st6
  Scaleform::Render::Tessellator::SrcVertexType *v12; // edi
  unsigned int j; // edi
  unsigned int Size; // eax
  int v15; // ebx
  unsigned __int8 *v16; // ebp
  Scaleform::Render::Tessellator::MonoChainType **Array; // eax
  unsigned int v18; // ecx
  unsigned int k; // eax
  unsigned int v20; // eax
  unsigned int v21; // ebp
  unsigned int v22; // edi
  unsigned int v23; // ecx
  double v24; // st7
  unsigned int v25; // ebx
  Scaleform::Render::Tessellator::MonoChainType **v26; // edx
  Scaleform::Render::Tessellator::MonoChainType **v27; // edx
  unsigned int Scanbeam; // eax
  char v29; // bl
  unsigned int v30; // ebx
  unsigned int v31; // eax
  Scaleform::Render::Tessellator::MonoChainType ***Pages; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v33; // edx
  unsigned int v34; // [esp+20h] [ebp-10h]
  float yTop; // [esp+20h] [ebp-10h]
  float yb; // [esp+24h] [ebp-Ch]
  int v37; // [esp+28h] [ebp-8h]
  int m; // [esp+28h] [ebp-8h]
  float v39; // [esp+2Ch] [ebp-4h]
  unsigned int v40; // [esp+2Ch] [ebp-4h]
  unsigned int v41; // [esp+2Ch] [ebp-4h]

  if ( this->SrcVertices.Size )
  {
    Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
      &this->StyleCounts,
      this->MaxStyle + 1);
    for ( i = 0; i < this->SrcVertices.Size; ++i )
    {
      v3 = this->Scanbeams.Size >> 4;
      if ( v3 >= this->Scanbeams.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
          &this->Scanbeams,
          this->Scanbeams.Size >> 4);
      this->Scanbeams.Pages[v3][this->Scanbeams.Size++ & 0xF] = i;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<unsigned int,4,16>,Scaleform::Render::Tessellator::CmpScanbeams>(
      &this->Scanbeams,
      0,
      this->Scanbeams.Size,
      (Scaleform::Render::Tessellator::CmpScanbeams)&this->SrcVertices);
    v4 = 0;
    v5 = 0;
    v37 = 0;
    v34 = 0;
    if ( this->Scanbeams.Size )
    {
      v6 = (float)-1.0e30;
      do
      {
        v7 = v4 >> 4;
        v8 = v4 & 0xF;
        v9 = this->SrcVertices.Pages[this->Scanbeams.Pages[v7][v8] >> 4];
        v10 = this->Scanbeams.Pages[v7][v8] & 0xF;
        y = v9[v10].y;
        v12 = &v9[v10];
        v39 = fabs(v12->y);
        if ( v39 * this->Epsilon >= y - v6 )
        {
          v12->y = v6;
        }
        else
        {
          this->Scanbeams.Pages[v5 >> 4][v5 & 0xF] = this->Scanbeams.Pages[v7][v8];
          v6 = v12->y;
          v5 = ++v37;
        }
        v4 = v34 + 1;
        v34 = v4;
      }
      while ( v4 < this->Scanbeams.Size );
    }
    if ( v5 < this->Scanbeams.Size )
      this->Scanbeams.Size = v5;
    for ( j = 0; j < this->Paths.Size; ++j )
      Scaleform::Render::Tessellator::decomposePath(this, &this->Paths.Pages[j >> 4][j & 0xF]);
    Size = this->MonoChains.Size;
    v40 = Size;
    if ( Size > this->MonoChainsSorted.Size )
    {
      v15 = 4 * Size;
      v16 = Scaleform::Render::LinearHeap::Alloc(this->MonoChainsSorted.pHeap, 4 * Size);
      memset((int)v16, 0, v15);
      Array = this->MonoChainsSorted.Array;
      if ( Array )
      {
        v18 = this->MonoChainsSorted.Size;
        if ( v18 )
          memcpy((int)v16, (const __m128i *)Array, 4 * v18);
      }
      Size = v40;
      this->MonoChainsSorted.Array = (Scaleform::Render::Tessellator::MonoChainType **)v16;
    }
    this->MonoChainsSorted.Size = Size;
    for ( k = 0; k < this->MonoChains.Size; ++k )
      this->MonoChainsSorted.Array[k] = &this->MonoChains.Pages[k >> 4][k & 0xF];
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayUnsafe<Scaleform::Render::Tessellator::MonoChainType *>,bool (__cdecl *)(Scaleform::Render::Tessellator::MonoChainType const *,Scaleform::Render::Tessellator::MonoChainType const *)>(
      &this->MonoChainsSorted,
      0,
      this->MonoChainsSorted.Size,
      (bool (__cdecl *)(const Scaleform::Render::Tessellator::MonoChainType *, const Scaleform::Render::Tessellator::MonoChainType *))Scaleform::Render::Tessellator::cmpMonoChains);
    v20 = this->Scanbeams.Size;
    yTop = this->SrcVertices.Pages[**this->Scanbeams.Pages >> 4][**this->Scanbeams.Pages & 0xF].y;
    v21 = 0;
    v22 = 0;
    for ( yb = yTop; v21 < v20; yb = yTop )
    {
      v41 = ++v21;
      if ( v21 < v20 )
        yTop = this->SrcVertices.Pages[this->Scanbeams.Pages[v21 >> 4][v21 & 0xF] >> 4][this->Scanbeams.Pages[v21 >> 4][v21 & 0xF]
                                                                                      & 0xF].y;
      v23 = this->MonoChainsSorted.Size;
      v24 = yb;
      v25 = v22;
      if ( v22 < v23 )
      {
        if ( (int)(v23 - v22) < 4 )
        {
LABEL_34:
          if ( v22 < v23 )
          {
            v27 = &this->MonoChainsSorted.Array[v22];
            do
            {
              if ( (*v27)->ySort > v24 )
                break;
              ++v22;
              ++v27;
            }
            while ( v22 < v23 );
          }
        }
        else
        {
          v26 = &this->MonoChainsSorted.Array[v22 + 2];
          while ( (*(v26 - 2))->ySort <= v24 )
          {
            if ( (*(v26 - 1))->ySort > v24 )
            {
              ++v22;
              break;
            }
            if ( (*v26)->ySort > v24 )
            {
              v22 += 2;
              break;
            }
            if ( v26[1]->ySort > v24 )
            {
              v22 += 3;
              break;
            }
            v22 += 4;
            v26 += 4;
            if ( v22 >= v23 - 3 )
              goto LABEL_34;
          }
        }
      }
      Scanbeam = Scaleform::Render::Tessellator::nextScanbeam(this, yb, yTop, v25, v22 - v25);
      v29 = Scanbeam;
      if ( this->Intersections.Size )
      {
        Scaleform::Render::Tessellator::processInterior(this, yb, yTop, Scanbeam);
      }
      else
      {
        if ( Scanbeam )
          Scaleform::Render::Tessellator::perceiveStyles(this, &this->ActiveChains);
        Scaleform::Render::Tessellator::sweepScanbeam(this, &this->ActiveChains, yb);
      }
      if ( (v29 & 2) != 0 )
      {
        v30 = 0;
        v31 = 0;
        for ( m = 0; v31 < this->ActiveChains.Size; ++v31 )
        {
          Pages = this->ActiveChains.Pages;
          v33 = Pages[v31 >> 4][v31 & 0xF];
          if ( (v33->flags & 2) == 0 )
          {
            Pages[v30 >> 4][v30 & 0xF] = v33;
            v30 = ++m;
          }
          v21 = v41;
        }
        if ( v30 < this->ActiveChains.Size )
          this->ActiveChains.Size = v30;
      }
      v20 = this->Scanbeams.Size;
    }
  }
}

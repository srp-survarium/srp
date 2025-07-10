void __thiscall Scaleform::Render::Rasterizer::SweepScanline(
        Scaleform::Render::Rasterizer *this,
        unsigned int scanline,
        unsigned __int8 *pRaster,
        unsigned int numChannels,
        int gammaIdx)
{
  Scaleform::Render::Rasterizer::SortedY *Array; // ecx
  unsigned int Count; // edx
  Scaleform::Render::Rasterizer::Cell **v8; // eax
  int v9; // ebx
  Scaleform::Render::Rasterizer::Cell *v10; // esi
  int x; // edi
  int Area; // ecx
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  unsigned int numCells; // [esp+4h] [ebp-4h]
  const Scaleform::Render::Rasterizer::Cell *const *cells; // [esp+Ch] [ebp+4h]

  if ( scanline < this->SortedYs.Size )
  {
    Array = this->SortedYs.Array;
    Count = Array[scanline].Count;
    v8 = &this->SortedCells.Array[Array[scanline].Start];
    v9 = 0;
    cells = (const Scaleform::Render::Rasterizer::Cell *const *)v8;
    if ( Count )
    {
      while ( 1 )
      {
        v10 = *v8;
        v9 += (*v8)->Cover;
        x = (*v8)->x;
        Area = (*v8)->Area;
        numCells = --Count;
        if ( Count )
        {
          do
          {
            v10 = v8[1];
            ++v8;
            if ( v10->x != x )
              break;
            Area += v10->Area;
            v9 += v10->Cover;
            --Count;
          }
          while ( Count );
          cells = (const Scaleform::Render::Rasterizer::Cell *const *)v8;
          numCells = Count;
        }
        if ( Area )
        {
          v13 = ((v9 << 9) - Area) >> 9;
          if ( v13 < 0 )
            v13 = -v13;
          if ( this->FillRule == FillEvenOdd )
          {
            v13 &= 0x1FFu;
            if ( v13 > 256 )
              v13 = 512 - v13;
          }
          if ( v13 > 255 )
            v13 = 255;
          if ( numChannels )
            memset(
              (int)&pRaster[numChannels * (x - this->MinX)],
              (unsigned __int8 *)this->GammaLut[gammaIdx][v13],
              numChannels);
          Count = numCells;
          v8 = (Scaleform::Render::Rasterizer::Cell **)cells;
          ++x;
        }
        if ( !Count )
          break;
        v14 = v10->x;
        if ( v14 > x )
        {
          v15 = v9 << 9 >> 9;
          if ( v15 < 0 )
            v15 = -v15;
          if ( this->FillRule == FillEvenOdd )
          {
            v15 &= 0x1FFu;
            if ( v15 > 256 )
              v15 = 512 - v15;
          }
          if ( v15 > 255 )
            v15 = 255;
          v16 = v15 + (gammaIdx << 8);
          if ( this->GammaLut[0][v16] )
          {
            memset(
              (int)&pRaster[numChannels * (x - this->MinX)],
              (unsigned __int8 *)this->GammaLut[0][v16],
              numChannels * (v14 - x));
            Count = numCells;
          }
          v8 = (Scaleform::Render::Rasterizer::Cell **)cells;
        }
      }
    }
  }
}

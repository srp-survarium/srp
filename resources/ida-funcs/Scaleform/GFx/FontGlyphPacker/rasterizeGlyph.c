void __userpurge Scaleform::GFx::FontGlyphPacker::rasterizeGlyph(
        Scaleform::GFx::FontGlyphPacker *this@<ecx>,
        unsigned int *a2@<edi>,
        Scaleform::Render::RawImage *texImage,
        Scaleform::GFx::FontGlyphPacker::GlyphInfo *gi)
{
  const Scaleform::Render::ShapeDataInterface *v5; // esi
  unsigned int v6; // eax
  Scaleform::Render::Rasterizer *p_Ras; // edi
  void (__thiscall *Clear)(struct Scaleform::Render::Rasterizer *); // edx
  int i; // eax
  double v10; // st7
  int j; // eax
  double v12; // st7
  int PadPixels; // esi
  unsigned int v14; // edi
  int v15; // ebp
  int v16; // eax
  unsigned int v17; // esi
  Scaleform::Render::Palette *pObject; // esi
  bool first; // [esp+3Bh] [ebp-CDh]
  int y; // [esp+3Ch] [ebp-CCh]
  float yb; // [esp+3Ch] [ebp-CCh]
  float yc; // [esp+3Ch] [ebp-CCh]
  int ya; // [esp+3Ch] [ebp-CCh]
  float coord[6]; // [esp+40h] [ebp-C8h] BYREF
  Scaleform::Render::Rasterizer *v26; // [esp+58h] [ebp-B0h]
  Scaleform::Render::ImageData d; // [esp+5Ch] [ebp-ACh] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+84h] [ebp-84h] BYREF
  unsigned int styles[3]; // [esp+BCh] [ebp-4Ch] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+C8h] [ebp-40h] BYREF

  v5 = gi->pFont->pFont.pObject->GetPermanentGlyphShape(gi->pFont->pFont.pObject, gi->GlyphIndex);
  if ( v5 && !v5->IsEmpty(v5) )
  {
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    *(float *)&y = (double)this->PackTextureConfig.NominalSize / 1536.0;
    v6 = v5->GetStartingPos(v5);
    p_Ras = &this->Ras;
    pos.Sfactor = 1.0;
    pos.Pos = v6;
    Clear = this->Ras.Clear;
    memset(&pos.StartX, 0, 44);
    pos.Initialized = 0;
    first = 1;
    v26 = &this->Ras;
    Clear(&this->Ras);
    for ( i = v5->ReadPathInfo(v5, &pos, coord, styles);
          i;
          i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, float *))v5->ReadPathInfo)(
                v5,
                &pos.StartX,
                &coord[1]) )
    {
      v10 = *(float *)&y;
      if ( !first && i == 2 )
        break;
      first = 0;
      if ( styles[0] == styles[1] )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, unsigned int *))v5->SkipPathData)(
          v5,
          &pos,
          a2);
      }
      else
      {
        coord[0] = coord[0] * v10;
        coord[1] = v10 * coord[1];
        Scaleform::Render::Rasterizer::MoveTo(&this->Ras, coord[0], coord[1]);
        for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))v5->ReadEdge)(
                    v5,
                    &pos,
                    coord,
                    a2); j; j = v5->ReadEdge(v5, (Scaleform::Render::ShapePosInfo *)&pos.StartX, &coord[1]) )
        {
          v12 = coord[0];
          coord[1] = coord[1] * coord[0];
          if ( j == 1 )
          {
            coord[2] = v12 * coord[2];
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, coord[1], coord[2]);
          }
          else
          {
            coord[2] = coord[2] * v12;
            coord[3] = coord[3] * v12;
            coord[4] = v12 * coord[4];
            Scaleform::Render::TessellateQuadCurve(
              &this->Ras,
              (Scaleform::Render::ToleranceParams *)&param.CurveTolerance,
              coord[1],
              coord[2],
              coord[3],
              coord[4]);
          }
        }
        p_Ras->ClosePath(&this->Ras);
      }
      a2 = &styles[1];
    }
    if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
    {
      d.pPlanes = &d.Plane0;
      memset(&d, 0, 10);
      d.RawPlaneCount = 1;
      memset(&d.pPalette, 0, 24);
      Scaleform::Render::RawImage::GetImageData(texImage, &d);
      PadPixels = this->PackTextureConfig.PadPixels;
      v14 = this->Ras.MaxY - this->Ras.MinY + 1;
      yb = floor(gi->Bounds.x1);
      v15 = PadPixels + (int)yb;
      yc = floor(gi->Bounds.y1);
      v16 = PadPixels + (int)yc;
      v17 = 0;
      ya = v16;
      if ( v14 )
      {
        while ( 1 )
        {
          Scaleform::Render::Rasterizer::SweepScanline(
            v26,
            v17,
            &d.pPlanes->pData[d.pPlanes->Pitch * (v17 + v16) + v15],
            1u,
            0);
          if ( ++v17 >= v14 )
            break;
          v16 = ya;
        }
      }
      Scaleform::Render::ImageData::freePlanes(&d);
      if ( d.pPalette.pObject )
      {
        pObject = d.pPalette.pObject;
        if ( InterlockedExchangeAdd(&d.pPalette.pObject->RefCount.Value, -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
      p_Ras = v26;
    }
    p_Ras->Clear(p_Ras);
  }
}

void __userpurge Scaleform::GFx::FontGlyphPacker::rasterizeGlyph(
        Scaleform::GFx::FontGlyphPacker *this@<ecx>,
        int *a2@<edi>,
        Scaleform::Render::RawImage *texImage,
        Scaleform::GFx::FontGlyphPacker::GlyphInfo *gi)
{
  const Scaleform::Render::ShapeDataInterface *v5; // esi
  int v6; // eax
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
  char v20; // [esp+3Bh] [ebp-CDh]
  float v21; // [esp+3Ch] [ebp-CCh]
  float v22; // [esp+3Ch] [ebp-CCh]
  float v23; // [esp+3Ch] [ebp-CCh]
  int v24; // [esp+3Ch] [ebp-CCh]
  float x; // [esp+40h] [ebp-C8h] BYREF
  float x2; // [esp+44h] [ebp-C4h] BYREF
  float v27; // [esp+48h] [ebp-C0h]
  float v28; // [esp+4Ch] [ebp-BCh]
  float v29; // [esp+50h] [ebp-B8h]
  Scaleform::Render::Rasterizer *v30; // [esp+58h] [ebp-B0h]
  Scaleform::Render::ImageData v31; // [esp+5Ch] [ebp-ACh] BYREF
  int v32; // [esp+84h] [ebp-84h] BYREF
  float v33[12]; // [esp+88h] [ebp-80h] BYREF
  char v34; // [esp+B8h] [ebp-50h]
  int v35; // [esp+BCh] [ebp-4Ch] BYREF
  int v36; // [esp+C0h] [ebp-48h] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+C8h] [ebp-40h] BYREF

  v5 = gi->pFont->pFont.pObject->GetPermanentGlyphShape(gi->pFont->pFont.pObject, gi->GlyphIndex);
  if ( v5 && !v5->IsEmpty(v5) )
  {
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    v21 = (double)this->PackTextureConfig.NominalSize / 1536.0;
    v6 = v5->GetStartingPos(v5);
    p_Ras = &this->Ras;
    v33[11] = 1.0;
    v32 = v6;
    Clear = this->Ras.Clear;
    memset(v33, 0, 44);
    v34 = 0;
    v20 = 1;
    v30 = &this->Ras;
    Clear(&this->Ras);
    for ( i = v5->ReadPathInfo(v5, (Scaleform::Render::ShapePosInfo *)&v32, &x, (unsigned int *)&v35);
          i;
          i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, float *, float *))v5->ReadPathInfo)(
                v5,
                v33,
                &x2) )
    {
      v10 = v21;
      if ( !v20 && i == 2 )
        break;
      v20 = 0;
      if ( v35 == v36 )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, int *))v5->SkipPathData)(
          v5,
          &v32,
          a2);
      }
      else
      {
        x = x * v10;
        x2 = v10 * x2;
        Scaleform::Render::Rasterizer::MoveTo(&this->Ras, x, x2);
        for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v5->ReadEdge)(
                    v5,
                    &v32,
                    &x,
                    a2); j; j = v5->ReadEdge(v5, (Scaleform::Render::ShapePosInfo *)v33, &x2) )
        {
          v12 = x;
          x2 = x2 * x;
          if ( j == 1 )
          {
            v27 = v12 * v27;
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, x2, v27);
          }
          else
          {
            v27 = v27 * v12;
            v28 = v28 * v12;
            v29 = v12 * v29;
            Scaleform::Render::TessellateQuadCurve(
              &this->Ras,
              (Scaleform::Render::ToleranceParams *)&param.CurveTolerance,
              x2,
              v27,
              v28,
              v29);
          }
        }
        p_Ras->ClosePath(&this->Ras);
      }
      a2 = &v36;
    }
    if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
    {
      v31.pPlanes = &v31.Plane0;
      memset(&v31, 0, 10);
      v31.RawPlaneCount = 1;
      memset(&v31.pPalette, 0, 24);
      Scaleform::Render::RawImage::GetImageData(texImage, &v31);
      PadPixels = this->PackTextureConfig.PadPixels;
      v14 = this->Ras.MaxY - this->Ras.MinY + 1;
      v22 = floor(gi->Bounds.x1);
      v15 = PadPixels + (int)v22;
      v23 = floor(gi->Bounds.y1);
      v16 = PadPixels + (int)v23;
      v17 = 0;
      v24 = v16;
      if ( v14 )
      {
        while ( 1 )
        {
          Scaleform::Render::Rasterizer::SweepScanline(
            v30,
            v17,
            &v31.pPlanes->pData[v31.pPlanes->Pitch * (v17 + v16) + v15],
            1u,
            0);
          if ( ++v17 >= v14 )
            break;
          v16 = v24;
        }
      }
      Scaleform::Render::ImageData::freePlanes(&v31);
      if ( v31.pPalette.pObject )
      {
        pObject = v31.pPalette.pObject;
        if ( InterlockedExchangeAdd(&v31.pPalette.pObject->RefCount.Value, -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
      p_Ras = v30;
    }
    p_Ras->Clear(p_Ras);
  }
}

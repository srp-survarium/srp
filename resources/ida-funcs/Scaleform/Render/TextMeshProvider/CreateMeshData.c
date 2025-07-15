char __thiscall Scaleform::Render::TextMeshProvider::CreateMeshData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TextLayout *layout,
        __int64 ren,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp,
        unsigned int meshGenFlags)
{
  Scaleform::MemoryHeap *v7; // ecx
  int v8; // ecx
  float *v9; // eax
  double x1; // st7
  int v11; // ecx
  Scaleform::GFx::Resource *v12; // edi
  float *v13; // eax
  Scaleform::Render::TextLayout *v14; // esi
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int BorderColor; // esi
  unsigned int Flags; // eax
  double v18; // st7
  unsigned int v19; // edi
  double v20; // st6
  Scaleform::Render::TmpTextMeshEntry *v21; // edx
  Scaleform::Render::TmpTextMeshEntry *v22; // esi
  Scaleform::Render::Font *pFont; // ecx
  float (__thiscall *GetNominalGlyphHeight)(Scaleform::Render::Font *); // edx
  double v25; // st7
  Scaleform::Render::Font *v26; // ecx
  Scaleform::Render::Rect<float> *(__thiscall *GetGlyphBounds)(Scaleform::Render::Font *, unsigned int, Scaleform::Render::Rect<float> *); // eax
  double v28; // st5
  double v29; // st4
  double v30; // st6
  double v31; // st7
  unsigned int v32; // edi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v33; // esi
  Scaleform::Render::Mesh *v34; // eax
  float v35; // eax
  Scaleform::RefCountVImpl *pHandle; // ecx
  unsigned int x_4; // [esp+18h] [ebp-1A8h]
  int v39; // [esp+20h] [ebp-1A0h]
  char v40; // [esp+3Bh] [ebp-185h]
  char v41; // [esp+3Bh] [ebp-185h]
  BOOL v42; // [esp+3Ch] [ebp-184h]
  int v43; // [esp+3Ch] [ebp-184h]
  Scaleform::Render::Matrix2x4<float> left; // [esp+40h] [ebp-180h] BYREF
  Scaleform::Render::TextLayout::Record rec; // [esp+64h] [ebp-15Ch] BYREF
  float y1; // [esp+7Ch] [ebp-144h]
  Scaleform::Render::Rect<float> rect; // [esp+80h] [ebp-140h] BYREF
  float x2; // [esp+90h] [ebp-130h]
  Scaleform::Render::TmpTextStorage storage; // [esp+94h] [ebp-12Ch] BYREF
  Scaleform::Render::GlyphRunData v50; // [esp+D0h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix2x4<float> viewMatrix; // [esp+1A0h] [ebp-20h] BYREF

  this->pRenderer = (Scaleform::Render::Renderer2DImpl *)ren;
  v7 = Scaleform::Memory::pGlobalHeap;
  this->Flags &= 0xFFFFFF1F;
  storage.LHeap.pHeap = v7;
  memset(&storage.LHeap.pPagePool, 0, 12);
  memset(&storage.Entries.Size, 0, 16);
  memset(&storage.Layers.Size, 0, 16);
  storage.LHeap.Granularity = 0x2000;
  storage.Entries.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  storage.Layers.pHeap = (Scaleform::Render::LinearHeap *)&storage;
  v8 = *(_DWORD *)HIDWORD(ren);
  v9 = (float *)(**(_DWORD **)HIDWORD(ren)
               + 16 * ((unsigned __int8)byte_874214[5 * (*(_BYTE *)(**(_DWORD **)HIDWORD(ren) + 11) & 0xF)] + 1));
  viewMatrix.M[0][0] = *v9;
  viewMatrix.M[0][1] = v9[1];
  viewMatrix.M[0][2] = v9[2];
  viewMatrix.M[0][3] = v9[3];
  viewMatrix.M[1][0] = v9[4];
  viewMatrix.M[1][1] = v9[5];
  viewMatrix.M[1][2] = v9[6];
  viewMatrix.M[1][3] = v9[7];
  if ( (*(_BYTE *)(*(_DWORD *)v8 + 11) & 0x10) != 0
    || (LOBYTE(v42) = 1, Scaleform::Render::Matrix2x4<float>::IsFreeRotation(&viewMatrix, 0.000001)) )
  {
    LOBYTE(v42) = 0;
  }
  Scaleform::Render::GlyphRunData::GlyphRunData(&v50);
  x1 = layout->Bounds.x1;
  qmemcpy(&v50, &layout->Param, 0x2Cu);
  v50.Bounds.x1 = x1;
  v50.Bounds.y1 = layout->Bounds.y1;
  v50.Bounds.x2 = layout->Bounds.x2;
  v50.Bounds.y2 = layout->Bounds.y2;
  v50.FontSize = 0.0;
  v50.NomWidth = 0.0;
  v50.NomHeight = 0.0;
  v50.TexHeight = 0.0;
  v11 = *(_DWORD *)HIDWORD(ren);
  v50.NewLineX = 0.0;
  v50.NewLineY = 0.0;
  v12 = 0;
  v50.GlyphBounds.x1 = 0.0;
  v50.pFont = 0;
  v50.GlyphBounds.y1 = 0.0;
  v50.pFontHandle = 0;
  v50.GlyphBounds.x2 = 0.0;
  v50.VectorSize = 0;
  v50.GlyphBounds.y2 = 0.0;
  v50.RasterSize = 0;
  v50.mColor = 0;
  v13 = (float *)(*(_DWORD *)v11 + 16 * ((unsigned __int8)byte_874214[5 * (*(_BYTE *)(*(_DWORD *)v11 + 11) & 0xF)] + 1));
  v50.DirMtx.M[0][0] = *v13;
  v50.DirMtx.M[0][1] = v13[1];
  v50.DirMtx.M[0][2] = v13[2];
  v50.DirMtx.M[0][3] = v13[3];
  v50.DirMtx.M[1][0] = v13[4];
  v50.DirMtx.M[1][1] = v13[5];
  v50.DirMtx.M[1][2] = v13[6];
  v50.DirMtx.M[1][3] = v13[7];
  left.M[0][0] = 1.0;
  left.M[1][1] = 1.0;
  left.M[0][1] = 0.0;
  left.M[0][2] = 0.0;
  left.M[0][3] = 0.0;
  left.M[1][0] = 0.0;
  left.M[1][2] = 0.0;
  left.M[1][3] = 0.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&left, &v50.DirMtx);
  v50.InvMtx.M[0][0] = left.M[0][0];
  v50.InvMtx.M[0][1] = left.M[0][1];
  v50.InvMtx.M[0][2] = left.M[0][2];
  v50.InvMtx.M[0][3] = left.M[0][3];
  v50.InvMtx.M[1][0] = left.M[1][0];
  v50.InvMtx.M[1][1] = left.M[1][1];
  v50.InvMtx.M[1][2] = left.M[1][2];
  v50.InvMtx.M[1][3] = left.M[1][3];
  v50.HeightRatio = Scaleform::Render::TextMeshProvider::calcHeightRatio(
                      (const Scaleform::Render::MatrixPoolImpl::HMatrix *)HIDWORD(ren),
                      m4,
                      vp);
  v50.HintedNomHeight = 0;
  this->HeightRatio = v50.HeightRatio;
  if ( (*(_BYTE *)(**(_DWORD **)HIDWORD(ren) + 11) & 0x10) != 0 )
  {
    v50.Param.TextParam.Flags &= 0xFFFCu;
    v50.Param.ShadowParam.Flags &= 0xFFFCu;
  }
  this->Flags &= ~8u;
  v14 = layout;
  y1 = layout->ClipBox.y1;
  x2 = layout->ClipBox.x2;
  rect.x1 = layout->ClipBox.y2;
  this->ClipBox.x1 = layout->ClipBox.x1;
  this->ClipBox.y1 = y1;
  this->ClipBox.x2 = x2;
  this->ClipBox.y2 = rect.x1;
  if ( this->ClipBox.x2 > (double)this->ClipBox.x1 && this->ClipBox.y2 > (double)this->ClipBox.y1 )
    this->Flags |= 8u;
  this->Flags |= 0x10u;
  v40 = 1;
  do
  {
    v12 = (Scaleform::GFx::Resource *)Scaleform::Render::TextLayout::ReadNext(v14, (unsigned int)v12, &rec);
    if ( !v12 )
      break;
    switch ( rec.mChar.Tag )
    {
      case 0u:
        if ( (rec.mChar.Flags & 1) != 0 )
          v40 = 1;
        else
          v40 = Scaleform::Render::TextMeshProvider::addGlyph(
                  this,
                  &storage,
                  &v50,
                  rec.mChar.GlyphIndex,
                  (rec.mChar.Flags & 2) != 0,
                  (rec.mChar.Flags & 4) != 0,
                  v42,
                  meshGenFlags);
        v50.NewLineX = rec.mChar.Advance + v50.NewLineX;
        break;
      case 1u:
        v50.mColor = rec.mBackground.BackgroundColor;
        break;
      case 2u:
        Scaleform::Render::TextMeshProvider::addBackground(
          this,
          &storage,
          rec.mBackground.BackgroundColor,
          rec.mBackground.BorderColor,
          &v50.Bounds);
        break;
      case 3u:
        v50.NewLineX = rec.mChar.Advance;
        v50.NewLineY = rec.mLine.y;
        if ( v42 && (v50.pFont && (v50.pFont->Flags & 0x80) != 0 || (v50.Param.TextParam.Flags & 1) != 0) )
          v50.NewLineY = Scaleform::Render::TextMeshProvider::snapY(this, &v50);
        break;
      case 4u:
        pCache = this->pCache;
        BorderColor = rec.mBackground.BorderColor;
        v50.pFont = rec.mFont.pFont;
        v50.pFontHandle = Scaleform::Render::GlyphCache::RegisterFont(pCache, rec.mFont.pFont);
        v50.FontSize = rec.mChar.Advance;
        v50.TexHeight = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)BorderColor + 52))(BorderColor);
        if ( v42 && v50.pFont && (v50.pFont->Flags & 0x80) != 0 )
          v50.NewLineY = Scaleform::Render::TextMeshProvider::snapY(this, &v50);
        v14 = layout;
        break;
      case 5u:
        left.M[0][0] = rec.mLine.y;
        left.M[0][1] = rec.mSelection.y1;
        left.M[0][2] = rec.mSelection.x2;
        left.M[0][3] = rec.mSelection.y2;
        Scaleform::Render::TextMeshProvider::addSelection(
          this,
          &storage,
          rec.mBackground.BackgroundColor,
          (const Scaleform::Render::Rect<float> *)&left);
        break;
      case 6u:
        Scaleform::Render::TextMeshProvider::addUnderline(
          this,
          &storage,
          rec.mUnderline.mColor,
          (Scaleform::Render::TextUnderlineStyle)rec.mChar.GlyphIndex,
          rec.mChar.Advance,
          rec.mLine.y,
          rec.mSelection.y1);
        this->Flags |= 0x80u;
        break;
      case 7u:
        rect.x1 = rec.mLine.y;
        rect.y1 = rec.mSelection.y1;
        rect.x2 = rec.mSelection.x2;
        rect.y2 = rec.mSelection.y2;
        Scaleform::Render::TextMeshProvider::addCursor(this, &storage, rec.mBackground.BackgroundColor, &rect);
        break;
      case 8u:
        Scaleform::Render::TextMeshProvider::addImage(
          this,
          v12,
          (Scaleform::Render::ImageFillMode)v14,
          &storage,
          &v50,
          rec.mImage.pImage,
          rec.mLine.y,
          rec.mSelection.y1,
          rec.mSelection.x2,
          v42,
          v39);
        v50.NewLineX = rec.mSelection.y2 + v50.NewLineX;
        break;
      default:
        break;
    }
  }
  while ( v40 );
  Flags = this->Flags;
  if ( (Flags & 8) != 0 && (Flags & 0xC0) != 0 )
  {
    Scaleform::Render::TextMeshProvider::addMask(this, &storage);
    v18 = 0.0;
    this->ClearBox.x1 = 0.0;
    v19 = 0;
    this->ClearBox.y1 = 0.0;
    v41 = 1;
    rect.x1 = 0.0 + 0.0;
    v20 = rect.x1;
    this->ClearBox.x2 = rect.x1;
    for ( this->ClearBox.y2 = v20; v19 < storage.Entries.Size; ++v19 )
    {
      v21 = storage.Entries.Pages[v19 >> 6];
      left.M[0][0] = v18;
      left.M[0][1] = v18;
      left.M[0][2] = v18;
      left.M[0][3] = v18;
      v22 = &v21[v19 & 0x3F];
      switch ( v22->LayerType )
      {
        case 4u:
        case 5u:
        case 7u:
          left.M[0][0] = v22->EntryData.RasterData.Coord[0];
          left.M[0][1] = v22->EntryData.RasterData.Coord[1];
          left.M[0][2] = v22->EntryData.RasterData.Coord[2];
          left.M[0][3] = v22->EntryData.RasterData.Coord[3];
          break;
        case 8u:
          pFont = v22->EntryData.VectorData.pFont;
          GetNominalGlyphHeight = pFont->GetNominalGlyphHeight;
          *(double *)&rect.x1 = v22->EntryData.RasterData.Coord[2];
          v25 = ((double (__thiscall *)(Scaleform::Render::Font *))GetNominalGlyphHeight)(pFont);
          v26 = v22->EntryData.VectorData.pFont;
          GetGlyphBounds = v26->GetGlyphBounds;
          x_4 = v22->EntryData.VectorData.GlyphIndex;
          rect.x1 = *(double *)&rect.x1 / v25;
          GetGlyphBounds(v26, x_4, (Scaleform::Render::Rect<float> *)&left);
          left.M[0][0] = rect.x1 * left.M[0][0] + v22->EntryData.RasterData.Coord[3];
          left.M[0][1] = rect.x1 * left.M[0][1] + v22->EntryData.VectorData.y;
          left.M[0][2] = rect.x1 * left.M[0][2] + v22->EntryData.RasterData.Coord[3];
          left.M[0][3] = rect.x1 * left.M[0][3] + v22->EntryData.VectorData.y;
          v22->LayerType = 12;
          v18 = 0.0;
          break;
        default:
          break;
      }
      v28 = left.M[0][2];
      if ( left.M[0][2] > (double)left.M[0][0] )
      {
        v29 = left.M[0][1];
        if ( left.M[0][3] > (double)left.M[0][1] )
        {
          if ( v41 )
          {
            v30 = left.M[0][3];
            v41 = 0;
            this->ClearBox.x1 = left.M[0][0];
            this->ClearBox.y1 = v29;
            this->ClearBox.x2 = v28;
            this->ClearBox.y2 = v30;
          }
          else
          {
            Scaleform::Render::Rect<float>::Union(
              &this->ClearBox,
              left.M[0][0],
              left.M[0][1],
              left.M[0][2],
              left.M[0][3]);
            v18 = 0.0;
            v41 = 0;
          }
        }
      }
      if ( v22->LayerType == 9 )
        v22->LayerType = 13;
    }
    this->Flags |= 0x100u;
    rect.x1 = 1.0 / this->HeightRatio;
    v31 = rect.x1;
    this->ClearBox.x1 = this->ClearBox.x1 - rect.x1;
    this->ClearBox.y1 = this->ClearBox.y1 - v31;
    this->ClearBox.x2 = this->ClearBox.x2 + v31;
    this->ClearBox.y2 = v31 + this->ClearBox.y2;
  }
  Scaleform::Render::TextMeshProvider::UnpinSlots(this);
  this->Flags &= ~0x10u;
  Scaleform::Render::TextMeshProvider::sortEntries(this, &storage);
  v32 = 0;
  if ( this->Layers.Data.Size )
  {
    v43 = 0;
    do
    {
      v33 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)&this->Layers.Data.Data[v43];
      if ( v33->pHandle == (Scaleform::Render::MatrixPoolImpl::EntryHandle *)8
        || v33->pHandle == (Scaleform::Render::MatrixPoolImpl::EntryHandle *)12 )
      {
        Scaleform::Render::TextMeshProvider::createVectorGlyph(
          this,
          v32,
          (Scaleform::Render::Renderer2DImpl *)ren,
          (const Scaleform::Render::MatrixPoolImpl::HMatrix *)HIDWORD(ren),
          meshGenFlags);
        this->Flags |= 0x40u;
      }
      else
      {
        Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(
          v33 + 6,
          (const Scaleform::Render::MatrixPoolImpl::HMatrix *)HIDWORD(ren));
        LODWORD(rect.x1) = 70;
        v34 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           176,
                                           &rect);
        if ( v34 )
        {
          Scaleform::Render::Mesh::Mesh(
            v34,
            (Scaleform::Render::Renderer2DImpl *)ren,
            this,
            &viewMatrix,
            0.0,
            v32,
            meshGenFlags);
          y1 = v35;
        }
        else
        {
          y1 = 0.0;
        }
        pHandle = (Scaleform::RefCountVImpl *)v33[3].pHandle;
        if ( pHandle )
          Scaleform::RefCountImpl::Release(pHandle);
        *(float *)&v33[3].pHandle = y1;
      }
      ++v43;
      ++v32;
    }
    while ( v32 < this->Layers.Data.Size );
  }
  this->Flags |= 0x20u;
  Scaleform::Render::LinearHeap::ClearAndRelease(&storage.LHeap);
  return 1;
}

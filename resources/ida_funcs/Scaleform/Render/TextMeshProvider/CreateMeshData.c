char __thiscall Scaleform::Render::TextMeshProvider::CreateMeshData(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TextLayout *layout,
        Scaleform::Render::Renderer2DImpl *ren,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp,
        unsigned int meshGenFlags)
{
  Scaleform::MemoryHeap *v8; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  float *v10; // eax
  double x1; // st7
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v12; // ecx
  Scaleform::GFx::Resource *v13; // edi
  float *v14; // eax
  Scaleform::Render::TextLayout *v15; // esi
  Scaleform::Render::GlyphCache *pCache; // ecx
  unsigned int BorderColor; // esi
  unsigned int Flags; // eax
  double v19; // st7
  unsigned int v20; // edi
  double v21; // st6
  Scaleform::Render::TmpTextMeshEntry *v22; // edx
  Scaleform::Render::TmpTextMeshEntry *v23; // esi
  Scaleform::Render::Font *pFont; // ecx
  float (__thiscall *GetNominalGlyphHeight)(Scaleform::Render::Font *); // edx
  double v26; // st7
  Scaleform::Render::Font *v27; // ecx
  Scaleform::Render::Rect<float> *(__thiscall *GetGlyphBounds)(Scaleform::Render::Font *, unsigned int, Scaleform::Render::Rect<float> *); // eax
  double v29; // st5
  double v30; // st4
  double v31; // st6
  double v32; // st7
  unsigned int v33; // edi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v34; // esi
  Scaleform::Render::Mesh *v35; // eax
  float v36; // eax
  Scaleform::RefCountVImpl *v37; // ecx
  unsigned int x_4; // [esp+C20h] [ebp-1A8h]
  float v40; // [esp+C28h] [ebp-1A0h]
  char v41; // [esp+C43h] [ebp-185h]
  char v42; // [esp+C43h] [ebp-185h]
  bool v43; // [esp+C44h] [ebp-184h]
  bool v44[4]; // [esp+C44h] [ebp-184h]
  Scaleform::Render::Matrix2x4<float> v45; // [esp+C48h] [ebp-180h] BYREF
  Scaleform::Render::TextLayout::Record x; // [esp+C6Ch] [ebp-15Ch] BYREF
  float y1; // [esp+C84h] [ebp-144h]
  Scaleform::Render::Rect<float> rect; // [esp+C88h] [ebp-140h] BYREF
  float x2; // [esp+C98h] [ebp-130h]
  Scaleform::Render::TmpTextStorage v50; // [esp+C9Ch] [ebp-12Ch] BYREF
  Scaleform::Render::GlyphRunData v51; // [esp+CD8h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix2x4<float> v52; // [esp+DA8h] [ebp-20h] BYREF

  this->pRenderer = ren;
  v8 = Scaleform::Memory::pGlobalHeap;
  this->Flags &= 0xFFFFFF1F;
  v50.LHeap.pHeap = v8;
  memset(&v50.LHeap.pPagePool, 0, 12);
  memset(&v50.Entries.Size, 0, 16);
  memset(&v50.Layers.Size, 0, 16);
  v50.LHeap.Granularity = 0x2000;
  v50.Entries.pHeap = (Scaleform::Render::LinearHeap *)&v50;
  v50.Layers.pHeap = (Scaleform::Render::LinearHeap *)&v50;
  pHandle = m->pHandle;
  v10 = (float *)(&m->pHandle->pHeader[1].RefCount
                + 4 * (unsigned __int8)byte_9B2B74[5 * (m->pHandle->pHeader->Format & 0xF)]);
  v52.M[0][0] = *v10;
  v52.M[0][1] = v10[1];
  v52.M[0][2] = v10[2];
  v52.M[0][3] = v10[3];
  v52.M[1][0] = v10[4];
  v52.M[1][1] = v10[5];
  v52.M[1][2] = v10[6];
  v52.M[1][3] = v10[7];
  if ( (pHandle->pHeader->Format & 0x10) != 0
    || (v43 = 1, Scaleform::Render::Matrix2x4<float>::IsFreeRotation(&v52, 0.000001)) )
  {
    v43 = 0;
  }
  Scaleform::Render::GlyphRunData::GlyphRunData(&v51);
  x1 = layout->Bounds.x1;
  qmemcpy(&v51, &layout->Param, 0x2Cu);
  v51.Bounds.x1 = x1;
  v51.Bounds.y1 = layout->Bounds.y1;
  v51.Bounds.x2 = layout->Bounds.x2;
  v51.Bounds.y2 = layout->Bounds.y2;
  v51.FontSize = 0.0;
  v51.NomWidth = 0.0;
  v51.NomHeight = 0.0;
  v51.TexHeight = 0.0;
  v12 = m->pHandle;
  v51.NewLineX = 0.0;
  v51.NewLineY = 0.0;
  v13 = 0;
  v51.GlyphBounds.x1 = 0.0;
  v51.pFont = 0;
  v51.GlyphBounds.y1 = 0.0;
  v51.pFontHandle = 0;
  v51.GlyphBounds.x2 = 0.0;
  v51.VectorSize = 0;
  v51.GlyphBounds.y2 = 0.0;
  v51.RasterSize = 0;
  v51.mColor = 0;
  v14 = (float *)(&v12->pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B74[5 * (v12->pHeader->Format & 0xF)]);
  v51.DirMtx.M[0][0] = *v14;
  v51.DirMtx.M[0][1] = v14[1];
  v51.DirMtx.M[0][2] = v14[2];
  v51.DirMtx.M[0][3] = v14[3];
  v51.DirMtx.M[1][0] = v14[4];
  v51.DirMtx.M[1][1] = v14[5];
  v51.DirMtx.M[1][2] = v14[6];
  v51.DirMtx.M[1][3] = v14[7];
  v45.M[0][0] = 1.0;
  v45.M[1][1] = 1.0;
  v45.M[0][1] = 0.0;
  v45.M[0][2] = 0.0;
  v45.M[0][3] = 0.0;
  v45.M[1][0] = 0.0;
  v45.M[1][2] = 0.0;
  v45.M[1][3] = 0.0;
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v45, &v51.DirMtx);
  v51.InvMtx.M[0][0] = v45.M[0][0];
  v51.InvMtx.M[0][1] = v45.M[0][1];
  v51.InvMtx.M[0][2] = v45.M[0][2];
  v51.InvMtx.M[0][3] = v45.M[0][3];
  v51.InvMtx.M[1][0] = v45.M[1][0];
  v51.InvMtx.M[1][1] = v45.M[1][1];
  v51.InvMtx.M[1][2] = v45.M[1][2];
  v51.InvMtx.M[1][3] = v45.M[1][3];
  v51.HeightRatio = Scaleform::Render::TextMeshProvider::calcHeightRatio(m, m4, vp);
  v51.HintedNomHeight = 0;
  this->HeightRatio = v51.HeightRatio;
  if ( (m->pHandle->pHeader->Format & 0x10) != 0 )
  {
    v51.Param.TextParam.Flags &= 0xFFFCu;
    v51.Param.ShadowParam.Flags &= 0xFFFCu;
  }
  this->Flags &= ~8u;
  v15 = layout;
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
  v41 = 1;
  do
  {
    v13 = (Scaleform::GFx::Resource *)Scaleform::Render::TextLayout::ReadNext(v15, (unsigned int)v13, &x);
    if ( !v13 )
      break;
    switch ( x.mChar.Tag )
    {
      case 0u:
        if ( (x.mChar.Flags & 1) != 0 )
          v41 = 1;
        else
          v41 = Scaleform::Render::TextMeshProvider::addGlyph(
                  this,
                  &v50,
                  &v51,
                  x.mChar.GlyphIndex,
                  (x.mChar.Flags & 2) != 0,
                  (x.mChar.Flags & 4) != 0,
                  v43,
                  meshGenFlags);
        v51.NewLineX = x.mChar.Advance + v51.NewLineX;
        break;
      case 1u:
        v51.mColor = x.mBackground.BackgroundColor;
        break;
      case 2u:
        Scaleform::Render::TextMeshProvider::addBackground(
          this,
          &v50,
          x.mBackground.BackgroundColor,
          x.mBackground.BorderColor,
          &v51.Bounds);
        break;
      case 3u:
        v51.NewLineX = x.mChar.Advance;
        v51.NewLineY = x.mLine.y;
        if ( v43 && (v51.pFont && (v51.pFont->Flags & 0x80) != 0 || (v51.Param.TextParam.Flags & 1) != 0) )
          v51.NewLineY = Scaleform::Render::TextMeshProvider::snapY(this, &v51);
        break;
      case 4u:
        pCache = this->pCache;
        BorderColor = x.mBackground.BorderColor;
        v51.pFont = x.mFont.pFont;
        v51.pFontHandle = Scaleform::Render::GlyphCache::RegisterFont(pCache, x.mFont.pFont);
        v51.FontSize = x.mChar.Advance;
        v51.TexHeight = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)BorderColor + 52))(BorderColor);
        if ( v43 && v51.pFont && (v51.pFont->Flags & 0x80) != 0 )
          v51.NewLineY = Scaleform::Render::TextMeshProvider::snapY(this, &v51);
        v15 = layout;
        break;
      case 5u:
        v45.M[0][0] = x.mLine.y;
        v45.M[0][1] = x.mSelection.y1;
        v45.M[0][2] = x.mSelection.x2;
        v45.M[0][3] = x.mSelection.y2;
        Scaleform::Render::TextMeshProvider::addSelection(
          this,
          &v50,
          x.mBackground.BackgroundColor,
          (const Scaleform::Render::Rect<float> *)&v45);
        break;
      case 6u:
        Scaleform::Render::TextMeshProvider::addUnderline(
          this,
          &v50,
          x.mUnderline.mColor,
          (Scaleform::Render::TextUnderlineStyle)x.mChar.GlyphIndex,
          x.mChar.Advance,
          x.mLine.y,
          x.mSelection.y1);
        this->Flags |= 0x80u;
        break;
      case 7u:
        rect.x1 = x.mLine.y;
        rect.y1 = x.mSelection.y1;
        rect.x2 = x.mSelection.x2;
        rect.y2 = x.mSelection.y2;
        Scaleform::Render::TextMeshProvider::addCursor(this, &v50, x.mBackground.BackgroundColor, &rect);
        break;
      case 8u:
        Scaleform::Render::TextMeshProvider::addImage(
          this,
          v13,
          (Scaleform::Render::ImageFillMode)v15,
          &v50,
          &v51,
          x.mImage.pImage,
          x.mLine.y,
          x.mSelection.y1,
          x.mSelection.x2,
          v43,
          v40);
        v51.NewLineX = x.mSelection.y2 + v51.NewLineX;
        break;
      default:
        break;
    }
  }
  while ( v41 );
  Flags = this->Flags;
  if ( (Flags & 8) != 0 && (Flags & 0xC0) != 0 )
  {
    Scaleform::Render::TextMeshProvider::addMask(this, &v50);
    v19 = 0.0;
    this->ClearBox.x1 = 0.0;
    v20 = 0;
    this->ClearBox.y1 = 0.0;
    v42 = 1;
    rect.x1 = 0.0 + 0.0;
    v21 = rect.x1;
    this->ClearBox.x2 = rect.x1;
    for ( this->ClearBox.y2 = v21; v20 < v50.Entries.Size; ++v20 )
    {
      v22 = v50.Entries.Pages[v20 >> 6];
      v45.M[0][0] = v19;
      v45.M[0][1] = v19;
      v45.M[0][2] = v19;
      v45.M[0][3] = v19;
      v23 = &v22[v20 & 0x3F];
      switch ( v23->LayerType )
      {
        case 4u:
        case 5u:
        case 7u:
          v45.M[0][0] = v23->EntryData.RasterData.Coord[0];
          v45.M[0][1] = v23->EntryData.RasterData.Coord[1];
          v45.M[0][2] = v23->EntryData.RasterData.Coord[2];
          v45.M[0][3] = v23->EntryData.RasterData.Coord[3];
          break;
        case 8u:
          pFont = v23->EntryData.VectorData.pFont;
          GetNominalGlyphHeight = pFont->GetNominalGlyphHeight;
          *(double *)&rect.x1 = v23->EntryData.RasterData.Coord[2];
          v26 = ((double (__thiscall *)(Scaleform::Render::Font *))GetNominalGlyphHeight)(pFont);
          v27 = v23->EntryData.VectorData.pFont;
          GetGlyphBounds = v27->GetGlyphBounds;
          x_4 = v23->EntryData.VectorData.GlyphIndex;
          rect.x1 = *(double *)&rect.x1 / v26;
          GetGlyphBounds(v27, x_4, (Scaleform::Render::Rect<float> *)&v45);
          v45.M[0][0] = rect.x1 * v45.M[0][0] + v23->EntryData.RasterData.Coord[3];
          v45.M[0][1] = rect.x1 * v45.M[0][1] + v23->EntryData.VectorData.y;
          v45.M[0][2] = rect.x1 * v45.M[0][2] + v23->EntryData.RasterData.Coord[3];
          v45.M[0][3] = rect.x1 * v45.M[0][3] + v23->EntryData.VectorData.y;
          v23->LayerType = 12;
          v19 = 0.0;
          break;
        default:
          break;
      }
      v29 = v45.M[0][2];
      if ( v45.M[0][2] > (double)v45.M[0][0] )
      {
        v30 = v45.M[0][1];
        if ( v45.M[0][3] > (double)v45.M[0][1] )
        {
          if ( v42 )
          {
            v31 = v45.M[0][3];
            v42 = 0;
            this->ClearBox.x1 = v45.M[0][0];
            this->ClearBox.y1 = v30;
            this->ClearBox.x2 = v29;
            this->ClearBox.y2 = v31;
          }
          else
          {
            Scaleform::Render::Rect<float>::Union(&this->ClearBox, v45.M[0][0], v45.M[0][1], v45.M[0][2], v45.M[0][3]);
            v19 = 0.0;
            v42 = 0;
          }
        }
      }
      if ( v23->LayerType == 9 )
        v23->LayerType = 13;
    }
    this->Flags |= 0x100u;
    rect.x1 = 1.0 / this->HeightRatio;
    v32 = rect.x1;
    this->ClearBox.x1 = this->ClearBox.x1 - rect.x1;
    this->ClearBox.y1 = this->ClearBox.y1 - v32;
    this->ClearBox.x2 = this->ClearBox.x2 + v32;
    this->ClearBox.y2 = v32 + this->ClearBox.y2;
  }
  Scaleform::Render::TextMeshProvider::UnpinSlots(this);
  this->Flags &= ~0x10u;
  Scaleform::Render::TextMeshProvider::sortEntries(this, &v50);
  v33 = 0;
  if ( this->Layers.Data.Size )
  {
    *(_DWORD *)v44 = 0;
    do
    {
      v34 = (Scaleform::Render::MatrixPoolImpl::HMatrix *)((char *)this->Layers.Data.Data + *(_DWORD *)v44);
      if ( v34->pHandle == (Scaleform::Render::MatrixPoolImpl::EntryHandle *)8
        || v34->pHandle == (Scaleform::Render::MatrixPoolImpl::EntryHandle *)12 )
      {
        Scaleform::Render::TextMeshProvider::createVectorGlyph(this, v33, ren, m, meshGenFlags);
        this->Flags |= 0x40u;
      }
      else
      {
        Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(v34 + 6, m);
        LODWORD(rect.x1) = 70;
        v35 = (Scaleform::Render::Mesh *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           176,
                                           &rect);
        if ( v35 )
        {
          Scaleform::Render::Mesh::Mesh(v35, ren, this, &v52, 0.0, v33, meshGenFlags);
          y1 = v36;
        }
        else
        {
          y1 = 0.0;
        }
        v37 = (Scaleform::RefCountVImpl *)v34[3].pHandle;
        if ( v37 )
          Scaleform::RefCountImpl::Release(v37);
        *(float *)&v34[3].pHandle = y1;
      }
      *(_DWORD *)v44 += 36;
      ++v33;
    }
    while ( v33 < this->Layers.Data.Size );
  }
  this->Flags |= 0x20u;
  Scaleform::Render::LinearHeap::ClearAndRelease(&v50.LHeap);
  return 1;
}

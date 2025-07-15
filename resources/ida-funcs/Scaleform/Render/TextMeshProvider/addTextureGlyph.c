void __userpurge Scaleform::Render::TextMeshProvider::addTextureGlyph(
        Scaleform::Render::TextMeshProvider *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::TmpTextStorage *storage,
        const Scaleform::Render::TextureGlyph *tgl,
        Scaleform::Render::GlyphRunData *data,
        unsigned int color,
        Scaleform::Render::PrimitiveFill *a7)
{
  double v10; // st7
  float v11; // edx
  double x1; // st7
  double v13; // st7
  Scaleform::Render::Font *pFont; // ecx
  double v15; // st6
  double v16; // st7
  unsigned int Flags; // eax
  Scaleform::Render::Image *pObject; // ecx
  double v19; // st6
  Scaleform::GFx::Resource *v20; // eax
  Scaleform::Render::PrimitiveFill *v21; // eax
  const Scaleform::Render::VertexFormat **p_pFormat; // edi
  int i; // ebx
  Scaleform::RefCountVImpl *v24; // ecx
  int v25; // eax
  Scaleform::Render::Image *v26; // ecx
  float v27; // esi
  unsigned int v28; // esi
  Scaleform::GFx::Resource *v29; // [esp-14h] [ebp-6Ch]
  Scaleform::GFx::Resource *v30; // [esp-14h] [ebp-6Ch]
  Scaleform::Render::TextureManager *pTexMan; // [esp-10h] [ebp-68h]
  Scaleform::Render::TextureManager *v32; // [esp-10h] [ebp-68h]
  Scaleform::GFx::Resource *v33; // [esp-Ch] [ebp-64h]
  Scaleform::GFx::Resource *v34; // [esp-Ch] [ebp-64h]
  float data_NewLineX; // [esp+Ch] [ebp-4Ch]
  float x2; // [esp+10h] [ebp-48h]
  float x2a; // [esp+10h] [ebp-48h]
  Scaleform::Render::Size<unsigned long> s; // [esp+14h] [ebp-44h] BYREF
  Scaleform::Render::PrimitiveFillData fillData; // [esp+1Ch] [ebp-3Ch] BYREF
  Scaleform::Render::TmpTextMeshEntry e; // [esp+34h] [ebp-24h] BYREF
  float scaleXa; // [esp+64h] [ebp+Ch]
  float scaleX; // [esp+64h] [ebp+Ch]
  float colora; // [esp+68h] [ebp+10h]
  float colorb; // [esp+68h] [ebp+10h]
  float colorc; // [esp+68h] [ebp+10h]
  float colord; // [esp+68h] [ebp+10h]

  data_NewLineX = data->NewLineX;
  ((void (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *, int))tgl->pImage.pObject->GetSize)(
    tgl->pImage.pObject,
    &s,
    a2);
  v10 = data->FontSize / data->TexHeight;
  colora = (double)s.Height * v10;
  v11 = tgl->UvBounds.x2;
  scaleXa = v10 * (double)(unsigned int)fillData.Type;
  x1 = tgl->UvBounds.x1;
  e.EntryIdx = 5;
  v13 = x1 - tgl->UvOrigin.x;
  pFont = data->pFont;
  e.pFill = a7;
  v15 = v13 * colora;
  v16 = colora;
  Flags = pFont->Flags;
  pObject = tgl->pImage.pObject;
  colorb = v15;
  *(float *)&e.mColor = v11;
  v19 = x2;
  x2a = colorb + x2;
  colorc = (tgl->UvBounds.y1 - tgl->UvOrigin.y) * scaleXa;
  scaleX = colorc + data->NewLineY;
  colord = v16 * (tgl->UvBounds.x2 - tgl->UvOrigin.x);
  *(float *)&s.Width = v19 + colord;
  if ( ((unsigned int)&_sbh_sizeHeaderList & Flags) != 0 )
  {
    v33 = (Scaleform::GFx::Resource *)pObject;
    LOBYTE(v33) = 3;
    pTexMan = this->pCache->pTexMan;
    v20 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *))pObject->GetTexture)(pObject);
    Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
      &fillData,
      PrimFill_UVTextureDFAlpha_VColor,
      &Scaleform::Render::RasterGlyphVertex::Format,
      v20,
      (Scaleform::Render::ImageFillMode)pTexMan,
      v33,
      0);
    v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &fillData);
    this->Flags |= 0x200u;
    e.pFill = v21;
    e.LayerType = 6;
    p_pFormat = &fillData.pFormat;
    for ( i = 1; i >= 0; --i )
    {
      v24 = (Scaleform::RefCountVImpl *)*--p_pFormat;
      if ( v24 )
        Scaleform::RefCountImpl::Release(v24);
    }
  }
  else
  {
    v25 = pObject->GetFormat(pObject);
    v26 = tgl->pImage.pObject;
    v34 = (Scaleform::GFx::Resource *)v26;
    LOBYTE(v34) = 3;
    v32 = this->pCache->pTexMan;
    if ( v25 == 9 )
    {
      v29 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *))v26->GetTexture)(v26);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &fillData,
        PrimFill_UVTextureAlpha_VColor,
        &Scaleform::Render::RasterGlyphVertex::Format,
        v29,
        (Scaleform::Render::ImageFillMode)v32,
        v34,
        0);
    }
    else
    {
      v30 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *))v26->GetTexture)(v26);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &fillData,
        PrimFill_UVTexture,
        &Scaleform::Render::ImageGlyphVertex::Format,
        v30,
        (Scaleform::Render::ImageFillMode)v32,
        v34,
        0);
    }
    e.pFill = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &fillData);
    Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&fillData);
  }
  e.EntryData.RasterData.Coord[0] = data_NewLineX;
  e.EntryData.BackgroundData.BorderColor = (unsigned int)tgl;
  v27 = tgl->UvBounds.x2;
  e.EntryData.RasterData.Coord[1] = *(float *)&tgl;
  v28 = LODWORD(v27) >> 6;
  e.EntryData.RasterData.Coord[2] = x2a;
  e.EntryData.RasterData.Coord[3] = scaleX;
  if ( v28 >= LODWORD(tgl->UvBounds.y2) )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *)&tgl->UvBounds.y1,
      v28);
  qmemcpy(
    (void *)(*(_DWORD *)(LODWORD(tgl->UvOrigin.y) + 4 * v28) + 36 * (LODWORD(tgl->UvBounds.x2)++ & 0x3F)),
    &e,
    0x24u);
}

void __userpurge Scaleform::Render::TextMeshProvider::addTextureGlyph(
        Scaleform::Render::TextMeshProvider *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::TmpTextStorage *storage,
        const Scaleform::Render::TextureGlyph *tgl,
        Scaleform::Render::GlyphRunData *data,
        unsigned int color,
        int a7)
{
  double v10; // st7
  float x2; // edx
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
  float NewLineX; // [esp+Ch] [ebp-4Ch]
  float v37; // [esp+10h] [ebp-48h]
  float v38; // [esp+10h] [ebp-48h]
  float v39[2]; // [esp+14h] [ebp-44h] BYREF
  Scaleform::Render::PrimitiveFillData initdata; // [esp+1Ch] [ebp-3Ch] BYREF
  _DWORD v41[9]; // [esp+34h] [ebp-24h] BYREF
  float v42; // [esp+64h] [ebp+Ch]
  float v43; // [esp+64h] [ebp+Ch]
  float v44; // [esp+68h] [ebp+10h]
  float v45; // [esp+68h] [ebp+10h]
  float v46; // [esp+68h] [ebp+10h]
  float v47; // [esp+68h] [ebp+10h]

  NewLineX = data->NewLineX;
  ((void (__thiscall *)(Scaleform::Render::Image *, float *, int))tgl->pImage.pObject->GetSize)(
    tgl->pImage.pObject,
    v39,
    a2);
  v10 = data->FontSize / data->TexHeight;
  v44 = (double)LODWORD(v39[1]) * v10;
  x2 = tgl->UvBounds.x2;
  v42 = v10 * (double)(unsigned int)initdata.Type;
  x1 = tgl->UvBounds.x1;
  v41[1] = 5;
  v13 = x1 - tgl->UvOrigin.x;
  pFont = data->pFont;
  v41[3] = a7;
  v15 = v13 * v44;
  v16 = v44;
  Flags = pFont->Flags;
  pObject = tgl->pImage.pObject;
  v45 = v15;
  *(float *)&v41[2] = x2;
  v19 = v37;
  v38 = v45 + v37;
  v46 = (tgl->UvBounds.y1 - tgl->UvOrigin.y) * v42;
  v43 = v46 + data->NewLineY;
  v47 = v16 * (tgl->UvBounds.x2 - tgl->UvOrigin.x);
  v39[0] = v19 + v47;
  if ( ((unsigned int)&_sbh_sizeHeaderList & Flags) != 0 )
  {
    v33 = (Scaleform::GFx::Resource *)pObject;
    LOBYTE(v33) = 3;
    pTexMan = this->pCache->pTexMan;
    v20 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *))pObject->GetTexture)(pObject);
    Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
      &initdata,
      PrimFill_UVTextureDFAlpha_VColor,
      &Scaleform::Render::RasterGlyphVertex::Format,
      v20,
      (Scaleform::Render::ImageFillMode)pTexMan,
      v33,
      0);
    v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &initdata);
    this->Flags |= 0x200u;
    v41[3] = v21;
    LOWORD(v41[0]) = 6;
    p_pFormat = &initdata.pFormat;
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
        &initdata,
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
        &initdata,
        PrimFill_UVTexture,
        &Scaleform::Render::ImageGlyphVertex::Format,
        v30,
        (Scaleform::Render::ImageFillMode)v32,
        v34,
        0);
    }
    v41[3] = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pCache->pFillMan, &initdata);
    Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&initdata);
  }
  *(float *)&v41[4] = NewLineX;
  v41[8] = tgl;
  v27 = tgl->UvBounds.x2;
  v41[5] = tgl;
  v28 = LODWORD(v27) >> 6;
  *(float *)&v41[6] = v38;
  *(float *)&v41[7] = v43;
  if ( v28 >= LODWORD(tgl->UvBounds.y2) )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4> *)&tgl->UvBounds.y1,
      v28);
  qmemcpy(
    (void *)(*(_DWORD *)(LODWORD(tgl->UvOrigin.y) + 4 * v28) + 36 * (LODWORD(tgl->UvBounds.x2)++ & 0x3F)),
    v41,
    0x24u);
}

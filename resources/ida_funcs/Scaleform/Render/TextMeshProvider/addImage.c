void __userpurge Scaleform::Render::TextMeshProvider::addImage(
        Scaleform::Render::TextMeshProvider *this@<ecx>,
        Scaleform::GFx::Resource *a2@<edi>,
        Scaleform::Render::ImageFillMode a3@<sil>,
        Scaleform::Render::TmpTextStorage *storage,
        const Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::Image *img,
        float scaleX,
        float scaleY,
        float baseLine,
        bool snap,
        float a11)
{
  unsigned int Size; // edx
  Scaleform::Render::TextureManager *pTexMan; // eax
  Scaleform::Render::Image_vtbl *v14; // edx
  Scaleform::GFx::Resource *v15; // eax
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *); // edx
  Scaleform::Render::Size<unsigned long> *(__thiscall *v17)(struct Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *); // edx
  unsigned int v18; // esi
  const Scaleform::Render::VertexFormat **p_pFormat; // esi
  int i; // edi
  Scaleform::RefCountVImpl *v21; // ecx
  char v23; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::Render::PrimitiveFillData fillData; // [esp+10h] [ebp-3Ch] BYREF
  Scaleform::Render::TmpTextMeshEntry e; // [esp+28h] [ebp-24h] BYREF
  float data_NewLineY; // [esp+64h] [ebp+18h]
  unsigned int snapa; // [esp+68h] [ebp+1Ch]
  unsigned int Width; // [esp+6Ch] [ebp+20h]

  data_NewLineY = data->NewLineY - scaleY * baseLine;
  if ( snap )
    Scaleform::Render::TextMeshProvider::snapX(this, data);
  Size = storage->Entries.Size;
  e.LayerType = 7;
  pTexMan = this->pCache->pTexMan;
  e.EntryIdx = Size;
  v14 = img->__vftable;
  e.TextureId = 0;
  v15 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::TextureManager *, int, _DWORD))v14->GetTexture)(
                                      img,
                                      pTexMan,
                                      3,
                                      0);
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
    (Scaleform::Render::PrimitiveFillData *)fillData.FillModes,
    PrimFill_UVTexture,
    &Scaleform::Render::ImageGlyphVertex::Format,
    v15,
    0,
    a2,
    a3);
  LODWORD(e.EntryData.RasterData.Coord[1]) = Scaleform::Render::PrimitiveFillManager::CreateFill(
                                               this->pCache->pFillMan,
                                               (const Scaleform::Render::PrimitiveFillData *)fillData.FillModes);
  e.EntryData.RasterData.Coord[2] = scaleX;
  GetSize = img->GetSize;
  e.EntryData.RasterData.Coord[3] = a11;
  Width = GetSize(img, (Scaleform::Render::Size<unsigned long> *)&fillData)->Width;
  v17 = img->GetSize;
  e.EntryData.RasterData.Coord[3] = (double)Width * scaleY + *(float *)&img;
  snapa = v17(img, (Scaleform::Render::Size<unsigned long> *)&v23)->Height;
  e.EntryData.BackgroundData.BorderColor = (unsigned int)img;
  v18 = storage->Entries.Size >> 6;
  e.EntryData.RasterData.Coord[3] = (double)snapa * scaleY + data_NewLineY;
  if ( v18 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v18);
  qmemcpy(
    &storage->Entries.Pages[v18][storage->Entries.Size++ & 0x3F],
    &e,
    sizeof(storage->Entries.Pages[v18][storage->Entries.Size++ & 0x3F]));
  p_pFormat = &fillData.pFormat;
  for ( i = 1; i >= 0; --i )
  {
    v21 = (Scaleform::RefCountVImpl *)*--p_pFormat;
    if ( v21 )
      Scaleform::RefCountImpl::Release(v21);
  }
}

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
        int a11)
{
  unsigned int Size; // edx
  Scaleform::Render::TextureManager *pTexMan; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *); // edx
  Scaleform::Render::Size<unsigned long> *(__thiscall *v16)(struct Scaleform::Render::Image *, Scaleform::Render::Size<unsigned long> *); // edx
  unsigned int v17; // esi
  Scaleform::Render::PrimitiveFillData *p_initdata_12; // esi
  int i; // edi
  Scaleform::RefCountVImpl *pFormat; // ecx
  char v22; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::Render::Size<unsigned long> v23; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE initdata[12]; // [esp+18h] [ebp-34h] BYREF
  Scaleform::Render::PrimitiveFillData initdata_12; // [esp+24h] [ebp-28h] BYREF
  _DWORD initdata_16[9]; // [esp+28h] [ebp-24h] BYREF
  float v27; // [esp+64h] [ebp+18h]
  unsigned int Height; // [esp+68h] [ebp+1Ch]
  unsigned int Width; // [esp+6Ch] [ebp+20h]

  v27 = data->NewLineY - scaleY * baseLine;
  if ( snap )
    Scaleform::Render::TextMeshProvider::snapX(this, data);
  Size = storage->Entries.Size;
  initdata_16[0] = 7;
  pTexMan = this->pCache->pTexMan;
  initdata_16[1] = Size;
  v14 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::TextureManager *, int, _DWORD))img->GetTexture)(
                                      img,
                                      pTexMan,
                                      3,
                                      0);
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
    (Scaleform::Render::PrimitiveFillData *)initdata,
    PrimFill_UVTexture,
    &Scaleform::Render::ImageGlyphVertex::Format,
    v14,
    0,
    a2,
    a3);
  initdata_16[5] = Scaleform::Render::PrimitiveFillManager::CreateFill(
                     this->pCache->pFillMan,
                     (const Scaleform::Render::PrimitiveFillData *)initdata);
  *(float *)&initdata_16[6] = scaleX;
  GetSize = img->GetSize;
  initdata_16[7] = a11;
  Width = GetSize(img, &v23)->Width;
  v16 = img->GetSize;
  *(float *)&initdata_16[7] = (double)Width * scaleY + *(float *)&img;
  Height = v16(img, (Scaleform::Render::Size<unsigned long> *)&v22)->Height;
  initdata_16[8] = img;
  v17 = storage->Entries.Size >> 6;
  *(float *)&initdata_16[7] = (double)Height * scaleY + v27;
  if ( v17 >= storage->Entries.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TmpTextMeshEntry,6,4>::allocPage(&storage->Entries, v17);
  qmemcpy(
    &storage->Entries.Pages[v17][storage->Entries.Size++ & 0x3F],
    initdata_16,
    sizeof(storage->Entries.Pages[v17][storage->Entries.Size++ & 0x3F]));
  p_initdata_12 = &initdata_12;
  for ( i = 1; i >= 0; --i )
  {
    pFormat = (Scaleform::RefCountVImpl *)p_initdata_12[-1].pFormat;
    p_initdata_12 = (Scaleform::Render::PrimitiveFillData *)((char *)p_initdata_12 - 4);
    if ( pFormat )
      Scaleform::RefCountImpl::Release(pFormat);
  }
}

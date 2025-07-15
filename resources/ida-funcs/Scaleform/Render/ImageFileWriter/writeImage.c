bool __cdecl Scaleform::Render::ImageFileWriter::writeImage(
        Scaleform::File *file,
        Scaleform::Render::ImageFileWriter *writer,
        Scaleform::Render::Image *image,
        const Scaleform::Render::ImageWriteArgs *args)
{
  Scaleform::Render::Image_vtbl *v5; // edx
  Scaleform::Render::ImageBase::ImageType (__thiscall *GetImageType)(struct Scaleform::Render::Image *); // eax
  Scaleform::Render::RawImage *v7; // edi
  int v8; // eax
  Scaleform::Render::Image_vtbl *v9; // edx
  Scaleform::Render::RawImage *v10; // eax
  Scaleform::Render::Palette *pObject; // esi
  char v13; // al
  Scaleform::Render::ImageFormat v14; // eax
  const Scaleform::Render::Size<unsigned long> *v15; // [esp-10h] [ebp-50h]
  int v16; // [esp+0h] [ebp-40h]
  char v17; // [esp+Fh] [ebp-31h]
  char v18; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::Render::ImageData v19; // [esp+18h] [ebp-28h] BYREF
  bool v20; // [esp+4Ch] [ebp+Ch]

  v5 = image->__vftable;
  v19.RawPlaneCount = 1;
  GetImageType = v5->GetImageType;
  v19.pPlanes = &v19.Plane0;
  v7 = 0;
  memset(&v19, 0, 10);
  memset(&v19.pPalette, 0, 24);
  v17 = 0;
  v8 = GetImageType(image);
  v9 = image->__vftable;
  if ( v8 == 2 )
  {
    v10 = (Scaleform::Render::RawImage *)v9->GetAsImage(image);
    Scaleform::Render::RawImage::GetImageData(v10, &v19);
    goto LABEL_3;
  }
  v13 = v9->GetUse(image);
  v16 = 0;
  if ( (v13 & 0x40) != 0 )
  {
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::Render::Image *, unsigned int *, _DWORD))image->Map)(
           image,
           &v19.Use,
           0) )
    {
      v17 = 1;
      goto LABEL_3;
    }
LABEL_13:
    Scaleform::Render::ImageData::~ImageData(&v19);
    return 0;
  }
  v15 = (const Scaleform::Render::Size<unsigned long> *)((int (__thiscall *)(Scaleform::Render::Image *))image->GetSize)(image);
  v14 = image->GetFormat(image);
  v7 = Scaleform::Render::RawImage::Create(v14, 1u, v15, (unsigned __int16)&v18, 0, 0);
  if ( !v7 )
    goto LABEL_13;
  Scaleform::Render::RawImage::GetImageData(v7, &v19);
  if ( !image->Decode(
          image,
          &v19,
          (void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *))Scaleform::Render::ImageBase::CopyScanlineDefault,
          0) )
  {
    Scaleform::Render::ImageData::~ImageData(&v19);
    ((void (__thiscall *)(Scaleform::Render::RawImage *, _DWORD))v7->Release)(v7, 0);
    return 0;
  }
LABEL_3:
  v20 = writer->Write(writer, file, &v19, args);
  if ( v17 )
    ((void (__thiscall *)(Scaleform::Render::Image *, int))image->Unmap)(image, v16);
  Scaleform::Render::ImageData::freePlanes(&v19);
  if ( v19.pPalette.pObject )
  {
    pObject = v19.pPalette.pObject;
    if ( InterlockedExchangeAdd(&v19.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
  if ( v7 )
    v7->Release(v7);
  return v20;
}

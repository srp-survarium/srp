char __thiscall Scaleform::Render::Texture::Update(Scaleform::Render::Texture *this)
{
  Scaleform::Render::ImageFormat v2; // ebp
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *pManager; // edi
  unsigned __int8 TextureFlags; // cl
  bool v6; // zf
  Scaleform::Render::ImageFormat v7; // eax
  void (__thiscall *computeUpdateConvertRescaleFlags)(Scaleform::Render::Texture *, bool, bool, Scaleform::Render::ImageFormat, Scaleform::Render::ResizeImageType *, Scaleform::Render::ImageFormat *, bool *); // edx
  _RTL_CRITICAL_SECTION *v9; // ebp
  Scaleform::Render::Image *v10; // eax
  Scaleform::Render::ImageData *p_Data; // ebp
  void (__stdcall *v13)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  Scaleform::Render::ImageData *v14; // ebp
  const Scaleform::Render::Size<unsigned long> *v15; // eax
  Scaleform::Render::RawImage *v16; // eax
  Scaleform::Render::ResizeImageType ImageFormatRescaleType; // eax
  unsigned int FormatPlaneCount; // ebp
  Scaleform::Render::ImageData *v19; // edi
  const Scaleform::Render::Size<unsigned long> *v20; // eax
  Scaleform::Render::RawImage *v21; // ebp
  void (__stdcall *v22)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  unsigned int i; // edi
  Scaleform::Render::Texture_vtbl *v24; // eax
  bool (__thiscall *Update)(Scaleform::Render::Texture *, const Scaleform::Render::Texture::UpdateDesc *, unsigned int, unsigned int); // edx
  unsigned int j; // edi
  bool v27; // cc
  unsigned int v28; // ebp
  unsigned int v29; // ebp
  Scaleform::Render::ImageFormat v30; // ebp
  void (__stdcall *v31)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  unsigned int v32; // ecx
  Scaleform::Render::Palette *v33; // esi
  Scaleform::Render::Palette *v34; // esi
  Scaleform::Render::Palette *v35; // [esp+26h] [ebp-FCh]
  int v36; // [esp+3Eh] [ebp-E4h] BYREF
  Scaleform::Render::ImageData *src; // [esp+42h] [ebp-E0h]
  unsigned int mipLevel; // [esp+46h] [ebp-DCh]
  unsigned int v39; // [esp+4Ah] [ebp-D8h]
  Scaleform::Render::RawImage *v40; // [esp+4Eh] [ebp-D4h]
  Scaleform::Render::ImageFormat format; // [esp+52h] [ebp-D0h]
  unsigned int MipLevels; // [esp+56h] [ebp-CCh]
  Scaleform::Render::RawImage *v43; // [esp+5Ah] [ebp-C8h]
  Scaleform::Render::ImageFormat v44; // [esp+5Eh] [ebp-C4h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+62h] [ebp-C0h]
  Scaleform::Render::ImagePlane pplane; // [esp+66h] [ebp-BCh] BYREF
  Scaleform::Render::ResizeImageType resizeType; // [esp+7Ah] [ebp-A8h] BYREF
  Scaleform::Render::ImagePlane splane; // [esp+7Eh] [ebp-A4h] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+92h] [ebp-90h] BYREF
  int v50; // [esp+A6h] [ebp-7Ch]
  int v51; // [esp+AAh] [ebp-78h]
  unsigned int Width; // [esp+AEh] [ebp-74h]
  unsigned int Height; // [esp+B2h] [ebp-70h]
  unsigned int v54; // [esp+B6h] [ebp-6Ch]
  BOOL v55; // [esp+BAh] [ebp-68h]
  Scaleform::Render::TextureManager *v56; // [esp+BEh] [ebp-64h]
  Scaleform::Render::ImageData v57; // [esp+C2h] [ebp-60h] BYREF
  Scaleform::Render::ImageData v58; // [esp+EAh] [ebp-38h] BYREF
  char v59[8]; // [esp+112h] [ebp-10h] BYREF
  char v60[8]; // [esp+11Ah] [ebp-8h] BYREF

  v2 = this->GetImageFormat(this);
  pObject = this->pManagerLocks.pObject;
  format = v2;
  if ( pObject )
    pManager = pObject->pManager;
  else
    pManager = 0;
  TextureFlags = this->TextureFlags;
  v6 = (this->Use & 2) == 0;
  LOBYTE(v55) = (TextureFlags & 2) != 0;
  LOBYTE(v39) = TextureFlags & 1;
  v57.RawPlaneCount = 1;
  v56 = pManager;
  HIBYTE(v36) = 0;
  mipLevel = 0;
  memset(&v57, 0, 10);
  v57.pPlanes = &v57.Plane0;
  memset(&v57.pPalette, 0, 24);
  memset(&v58, 0, 10);
  v58.RawPlaneCount = 1;
  v58.pPlanes = &v58.Plane0;
  memset(&v58.pPalette, 0, 24);
  v40 = 0;
  v43 = 0;
  if ( v6 )
    MipLevels = this->MipLevels;
  else
    MipLevels = 1;
  v7 = this->GetImageFormat(this);
  computeUpdateConvertRescaleFlags = this->computeUpdateConvertRescaleFlags;
  v44 = v7;
  resizeType = ResizeNone;
  computeUpdateConvertRescaleFlags(this, v39, v55, v2, &resizeType, &v44, (bool *)&v36 + 3);
  lpCriticalSection = &this->pManagerLocks.pObject->ImageLock.cs;
  v9 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  if ( this->pImage && (this->TextureFlags & 4) == 0 )
  {
    if ( this->pImage->GetImageType(this->pImage) == Type_RawImage )
    {
      if ( (_BYTE)v39 )
      {
        v10 = this->pImage->GetAsImage(this->pImage);
        Scaleform::Render::ImageData::operator=(&v57, (const Scaleform::Render::ImageData *)&v10[1]);
        src = &v57;
        goto LABEL_32;
      }
    }
    else if ( (_BYTE)v39 )
    {
      goto LABEL_17;
    }
    if ( !HIBYTE(v36) && pManager->isScanlineCompatible(pManager, this->pFormat) && pManager->mapTexture(pManager, this) )
    {
      p_Data = &this->pMap->Data;
LABEL_21:
      if ( HIBYTE(v36) )
        v13 = (void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *))Scaleform::Render::ImageBase::CopyScanlineDefault;
      else
        v13 = this->pFormat->GetScanlineCopyFn(this->pFormat);
      if ( !this->pImage->Decode(this->pImage, p_Data, v13, 0) )
      {
        if ( p_Data == &this->pMap->Data )
          pManager->unmapTexture(pManager, this, 0);
        LeaveCriticalSection(lpCriticalSection);
        goto LABEL_28;
      }
      src = p_Data;
      v9 = lpCriticalSection;
LABEL_32:
      if ( (_BYTE)v39 )
      {
        if ( !HIBYTE(v36)
          && pManager->isScanlineCompatible(pManager, this->pFormat)
          && pManager->mapTexture(pManager, this) )
        {
          v14 = &this->pMap->Data;
        }
        else
        {
          v15 = this->GetTextureSize(this, v60, 0);
          v16 = Scaleform::Render::RawImage::Create(v44, MipLevels, v15, 0, 0, 0);
          v43 = v16;
          if ( !v16 )
          {
            LeaveCriticalSection(v9);
LABEL_39:
            if ( v40 )
              v40->Release(v40);
            goto LABEL_19;
          }
          Scaleform::Render::ImageData::operator=(&v58, &v16->Data);
          v14 = &v58;
        }
        ImageFormatRescaleType = resizeType;
        mipLevel = (unsigned int)v14;
        if ( resizeType == ResizeNone )
        {
          ImageFormatRescaleType = Scaleform::Render::GetImageFormatRescaleType(format);
          resizeType = ImageFormatRescaleType;
        }
        Scaleform::Render::RescaleImageData(v14, src, ImageFormatRescaleType);
        src = v14;
      }
      FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(format);
      v39 = FormatPlaneCount;
      if ( !HIBYTE(v36) && pManager->isScanlineCompatible(pManager, this->pFormat) )
        goto LABEL_59;
      if ( !pManager->isScanlineCompatible(pManager, this->pFormat) )
      {
        for ( i = 0; i < FormatPlaneCount; ++i )
        {
          memset(&pplane, 0, sizeof(pplane));
          memset(&dplane, 0, sizeof(dplane));
          v50 = 0;
          v51 = 0;
          Width = 0;
          Height = 0;
          Scaleform::Render::ImageData::GetMipLevelPlane(src, 0, i, &pplane);
          dplane.Pitch = pplane.Pitch;
          dplane.Height = pplane.Height;
          dplane.DataSize = pplane.DataSize;
          Height = pplane.Height;
          dplane.Width = pplane.Width;
          Width = pplane.Width;
          v24 = this->__vftable;
          dplane.pData = pplane.pData;
          Update = v24->Update;
          v50 = 0;
          v51 = 0;
          v54 = i;
          Update(this, (const Scaleform::Render::Texture::UpdateDesc *)&dplane, 1u, 0);
        }
        goto LABEL_59;
      }
      if ( pManager->mapTexture(pManager, this) )
      {
        v19 = &this->pMap->Data;
LABEL_56:
        v22 = this->pFormat->GetScanlineCopyFn(this->pFormat);
        Scaleform::Render::ConvertImageData(v19, src, v22, 0);
LABEL_59:
        if ( v55 )
        {
          for ( j = 0; j < v39; ++j )
          {
            memset(&splane, 0, sizeof(splane));
            memset(&pplane, 0, sizeof(pplane));
            Scaleform::Render::ImageData::GetMipLevelPlane(src, 0, j, &splane);
            v27 = this->MipLevels <= 1u;
            mipLevel = 1;
            if ( !v27 )
            {
              v28 = splane.Width;
              do
              {
                Scaleform::Render::ImageData::GetMipLevelPlane(&this->pMap->Data, mipLevel, j, &pplane);
                if ( HIBYTE(v36) )
                {
                  dplane.Pitch = splane.Pitch;
                  v29 = v28 >> 1;
                  dplane.DataSize = splane.DataSize;
                  dplane.pData = splane.pData;
                  dplane.Width = 1;
                  if ( v29 )
                    dplane.Width = v29;
                  dplane.Height = 1;
                  if ( splane.Height >> 1 )
                    dplane.Height = splane.Height >> 1;
                  v30 = format;
                  Scaleform::Render::GenerateMipLevel(&dplane, &splane, format, j);
                  v35 = src->pPalette.pObject;
                  v31 = this->pFormat->GetScanlineCopyFn(this->pFormat);
                  Scaleform::Render::ConvertImagePlane(&pplane, &dplane, v30, j, v31, v35, 0);
                  v28 = dplane.Width;
                  splane.Height = dplane.Height;
                }
                else
                {
                  Scaleform::Render::GenerateMipLevel(&pplane, &splane, format, j);
                  v28 = pplane.Width;
                  splane.Height = pplane.Height;
                  splane.Pitch = pplane.Pitch;
                  splane.DataSize = pplane.DataSize;
                  splane.pData = pplane.pData;
                }
                v32 = this->MipLevels;
                splane.Width = v28;
                ++mipLevel;
              }
              while ( mipLevel < v32 );
            }
          }
        }
        if ( src == &this->pMap->Data )
          v56->unmapTexture(v56, this, 1);
        else
          this->uploadImage(this, src);
        LeaveCriticalSection(lpCriticalSection);
        if ( v43 )
          v43->Release(v43);
LABEL_28:
        if ( v40 )
          v40->Release(v40);
        Scaleform::Render::ImageData::~ImageData(&v58);
        Scaleform::Render::ImageData::~ImageData(&v57);
        return 1;
      }
      v19 = (Scaleform::Render::ImageData *)mipLevel;
      if ( mipLevel )
        goto LABEL_56;
      v20 = this->GetTextureSize(this, v59, 0);
      v21 = Scaleform::Render::RawImage::Create(v44, MipLevels, v20, 0, 0, 0);
      if ( v43 )
        v43->Release(v43);
      v43 = v21;
      if ( v21 )
      {
        Scaleform::Render::ImageData::operator=(&v58, &v21->Data);
        v19 = &v58;
        goto LABEL_56;
      }
      LeaveCriticalSection(lpCriticalSection);
      goto LABEL_39;
    }
LABEL_17:
    v40 = Scaleform::Render::RawImage::Create(v44, MipLevels, &this->ImgSize, 0, 0, 0);
    if ( !v40 )
    {
      LeaveCriticalSection(v9);
LABEL_19:
      Scaleform::Render::ImageData::~ImageData(&v58);
      Scaleform::Render::ImageData::~ImageData(&v57);
      return 0;
    }
    Scaleform::Render::ImageData::operator=(&v57, &v40->Data);
    v57.Format = (unsigned int)&loc_100000 | format;
    p_Data = &v57;
    goto LABEL_21;
  }
  LeaveCriticalSection(v9);
  if ( (v58.Flags & 2) != 0 )
  {
    v58.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v58.pPlanes);
  }
  v58.pPlanes = &v58.Plane0;
  if ( v58.pPalette.pObject )
  {
    v33 = v58.pPalette.pObject;
    if ( InterlockedExchangeAdd(&v58.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33);
  }
  if ( (v57.Flags & 2) != 0 )
  {
    v57.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v57.pPlanes);
  }
  v57.pPlanes = &v57.Plane0;
  if ( v57.pPalette.pObject )
  {
    v34 = v57.pPalette.pObject;
    if ( InterlockedExchangeAdd(&v57.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v34);
  }
  return 0;
}

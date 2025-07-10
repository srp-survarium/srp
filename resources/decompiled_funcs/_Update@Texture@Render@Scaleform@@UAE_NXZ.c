char __thiscall Scaleform::Render::Texture::Update(Scaleform::Render::Texture *this)
{
  Scaleform::Render::ImageFormat v2; // ebp
  Scaleform::Render::TextureManagerLocks *pObject; // eax
  Scaleform::Render::TextureManager *v4; // edi
  unsigned __int8 TextureFlags; // cl
  bool v6; // zf
  Scaleform::Render::ImageFormat v7; // eax
  void (__thiscall *computeUpdateConvertRescaleFlags)(Scaleform::Render::Texture *, bool, bool, Scaleform::Render::ImageFormat, Scaleform::Render::ResizeImageType *, Scaleform::Render::ImageFormat *, bool *); // edx
  Scaleform::Lock *pLock; // ebp
  Scaleform::Render::Image *v10; // eax
  Scaleform::Render::ImageData *p_Data; // ebp
  void (__stdcall *v13)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  Scaleform::Render::ImageData *p_imageData2; // ebp
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
  unsigned int MipLevels; // ecx
  Scaleform::Render::Palette *v33; // esi
  Scaleform::Render::Palette *v34; // esi
  Scaleform::Render::Palette *v35; // [esp+26h] [ebp-FCh]
  int v36; // [esp+3Eh] [ebp-E4h] BYREF
  Scaleform::Render::ImageData *psource; // [esp+42h] [ebp-E0h]
  unsigned int level; // [esp+46h] [ebp-DCh]
  unsigned int rescale; // [esp+4Ah] [ebp-D8h]
  Scaleform::Ptr<Scaleform::Render::RawImage> pimage1; // [esp+4Eh] [ebp-D4h]
  Scaleform::Render::ImageFormat format; // [esp+52h] [ebp-D0h]
  unsigned int sourceMipLevels; // [esp+56h] [ebp-CCh]
  Scaleform::Ptr<Scaleform::Render::RawImage> pimage2; // [esp+5Ah] [ebp-C8h]
  Scaleform::Render::ImageFormat rescaleBuffFromat; // [esp+5Eh] [ebp-C4h] BYREF
  Scaleform::Lock::Locker imageLock; // [esp+62h] [ebp-C0h]
  Scaleform::Render::ImagePlane tplane; // [esp+66h] [ebp-BCh] BYREF
  Scaleform::Render::ResizeImageType rescaleType; // [esp+7Ah] [ebp-A8h] BYREF
  Scaleform::Render::ImagePlane pplane; // [esp+7Eh] [ebp-A4h] BYREF
  Scaleform::Render::ImagePlane dplane; // [esp+92h] [ebp-90h] BYREF
  int v50; // [esp+A6h] [ebp-7Ch]
  int v51; // [esp+AAh] [ebp-78h]
  unsigned int Width; // [esp+AEh] [ebp-74h]
  unsigned int Height; // [esp+B2h] [ebp-70h]
  unsigned int v54; // [esp+B6h] [ebp-6Ch]
  BOOL swMipGen; // [esp+BAh] [ebp-68h]
  Scaleform::Render::TextureManager *pmanager; // [esp+BEh] [ebp-64h]
  Scaleform::Render::ImageData imageData1; // [esp+C2h] [ebp-60h] BYREF
  Scaleform::Render::ImageData imageData2; // [esp+EAh] [ebp-38h] BYREF
  _BYTE v59[8]; // [esp+112h] [ebp-10h] BYREF
  _BYTE v60[8]; // [esp+11Ah] [ebp-8h] BYREF

  v2 = this->GetImageFormat(this);
  pObject = this->pManagerLocks.pObject;
  format = v2;
  if ( pObject )
    v4 = pObject->pManager;
  else
    v4 = 0;
  TextureFlags = this->TextureFlags;
  v6 = (this->Use & 2) == 0;
  LOBYTE(swMipGen) = (TextureFlags & 2) != 0;
  LOBYTE(rescale) = TextureFlags & 1;
  imageData1.RawPlaneCount = 1;
  pmanager = v4;
  HIBYTE(v36) = 0;
  level = 0;
  memset(&imageData1, 0, 10);
  imageData1.pPlanes = &imageData1.Plane0;
  memset(&imageData1.pPalette, 0, 24);
  memset(&imageData2, 0, 10);
  imageData2.RawPlaneCount = 1;
  imageData2.pPlanes = &imageData2.Plane0;
  memset(&imageData2.pPalette, 0, 24);
  pimage1.pObject = 0;
  pimage2.pObject = 0;
  if ( v6 )
    sourceMipLevels = this->MipLevels;
  else
    sourceMipLevels = 1;
  v7 = this->GetImageFormat(this);
  computeUpdateConvertRescaleFlags = this->computeUpdateConvertRescaleFlags;
  rescaleBuffFromat = v7;
  rescaleType = ResizeNone;
  computeUpdateConvertRescaleFlags(this, rescale, swMipGen, v2, &rescaleType, &rescaleBuffFromat, (bool *)&v36 + 3);
  imageLock.pLock = &this->pManagerLocks.pObject->ImageLock;
  pLock = imageLock.pLock;
  EnterCriticalSection(&imageLock.pLock->cs);
  if ( this->pImage && (this->TextureFlags & 4) == 0 )
  {
    if ( this->pImage->GetImageType(this->pImage) == Type_RawImage )
    {
      if ( (_BYTE)rescale )
      {
        v10 = this->pImage->GetAsImage(this->pImage);
        Scaleform::Render::ImageData::operator=(&imageData1, (const Scaleform::Render::ImageData *)&v10[1]);
        psource = &imageData1;
        goto LABEL_32;
      }
    }
    else if ( (_BYTE)rescale )
    {
      goto LABEL_17;
    }
    if ( !HIBYTE(v36) && v4->isScanlineCompatible(v4, this->pFormat) && v4->mapTexture(v4, this) )
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
          v4->unmapTexture(v4, this, 0);
        LeaveCriticalSection(&imageLock.pLock->cs);
        goto LABEL_28;
      }
      psource = p_Data;
      pLock = imageLock.pLock;
LABEL_32:
      if ( (_BYTE)rescale )
      {
        if ( !HIBYTE(v36) && v4->isScanlineCompatible(v4, this->pFormat) && v4->mapTexture(v4, this) )
        {
          p_imageData2 = &this->pMap->Data;
        }
        else
        {
          v15 = this->GetTextureSize(this, v60, 0);
          v16 = Scaleform::Render::RawImage::Create(rescaleBuffFromat, sourceMipLevels, v15, 0, 0, 0);
          pimage2.pObject = v16;
          if ( !v16 )
          {
            LeaveCriticalSection(&pLock->cs);
LABEL_39:
            if ( pimage1.pObject )
              pimage1.pObject->Release(pimage1.pObject);
            goto LABEL_19;
          }
          Scaleform::Render::ImageData::operator=(&imageData2, &v16->Data);
          p_imageData2 = &imageData2;
        }
        ImageFormatRescaleType = rescaleType;
        level = (unsigned int)p_imageData2;
        if ( rescaleType == ResizeNone )
        {
          ImageFormatRescaleType = Scaleform::Render::GetImageFormatRescaleType(format);
          rescaleType = ImageFormatRescaleType;
        }
        Scaleform::Render::RescaleImageData(p_imageData2, psource, ImageFormatRescaleType);
        psource = p_imageData2;
      }
      FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(format);
      rescale = FormatPlaneCount;
      if ( !HIBYTE(v36) && v4->isScanlineCompatible(v4, this->pFormat) )
        goto LABEL_59;
      if ( !v4->isScanlineCompatible(v4, this->pFormat) )
      {
        for ( i = 0; i < FormatPlaneCount; ++i )
        {
          memset(&tplane, 0, sizeof(tplane));
          memset(&dplane, 0, sizeof(dplane));
          v50 = 0;
          v51 = 0;
          Width = 0;
          Height = 0;
          Scaleform::Render::ImageData::GetMipLevelPlane(psource, 0, i, &tplane);
          dplane.Pitch = tplane.Pitch;
          dplane.Height = tplane.Height;
          dplane.DataSize = tplane.DataSize;
          Height = tplane.Height;
          dplane.Width = tplane.Width;
          Width = tplane.Width;
          v24 = this->__vftable;
          dplane.pData = tplane.pData;
          Update = v24->Update;
          v50 = 0;
          v51 = 0;
          v54 = i;
          Update(this, (const Scaleform::Render::Texture::UpdateDesc *)&dplane, 1u, 0);
        }
        goto LABEL_59;
      }
      if ( v4->mapTexture(v4, this) )
      {
        v19 = &this->pMap->Data;
LABEL_56:
        v22 = this->pFormat->GetScanlineCopyFn(this->pFormat);
        Scaleform::Render::ConvertImageData(v19, psource, v22, 0);
LABEL_59:
        if ( swMipGen )
        {
          for ( j = 0; j < rescale; ++j )
          {
            memset(&pplane, 0, sizeof(pplane));
            memset(&tplane, 0, sizeof(tplane));
            Scaleform::Render::ImageData::GetMipLevelPlane(psource, 0, j, &pplane);
            v27 = this->MipLevels <= 1u;
            level = 1;
            if ( !v27 )
            {
              v28 = pplane.Width;
              do
              {
                Scaleform::Render::ImageData::GetMipLevelPlane(&this->pMap->Data, level, j, &tplane);
                if ( HIBYTE(v36) )
                {
                  dplane.Pitch = pplane.Pitch;
                  v29 = v28 >> 1;
                  dplane.DataSize = pplane.DataSize;
                  dplane.pData = pplane.pData;
                  dplane.Width = 1;
                  if ( v29 )
                    dplane.Width = v29;
                  dplane.Height = 1;
                  if ( pplane.Height >> 1 )
                    dplane.Height = pplane.Height >> 1;
                  v30 = format;
                  Scaleform::Render::GenerateMipLevel(&dplane, &pplane, format, j);
                  v35 = psource->pPalette.pObject;
                  v31 = this->pFormat->GetScanlineCopyFn(this->pFormat);
                  Scaleform::Render::ConvertImagePlane(&tplane, &dplane, v30, j, v31, v35, 0);
                  v28 = dplane.Width;
                  pplane.Height = dplane.Height;
                }
                else
                {
                  Scaleform::Render::GenerateMipLevel(&tplane, &pplane, format, j);
                  v28 = tplane.Width;
                  pplane.Height = tplane.Height;
                  pplane.Pitch = tplane.Pitch;
                  pplane.DataSize = tplane.DataSize;
                  pplane.pData = tplane.pData;
                }
                MipLevels = this->MipLevels;
                pplane.Width = v28;
                ++level;
              }
              while ( level < MipLevels );
            }
          }
        }
        if ( psource == &this->pMap->Data )
          pmanager->unmapTexture(pmanager, this, 1);
        else
          this->uploadImage(this, psource);
        LeaveCriticalSection(&imageLock.pLock->cs);
        if ( pimage2.pObject )
          pimage2.pObject->Release(pimage2.pObject);
LABEL_28:
        if ( pimage1.pObject )
          pimage1.pObject->Release(pimage1.pObject);
        Scaleform::Render::ImageData::~ImageData(&imageData2);
        Scaleform::Render::ImageData::~ImageData(&imageData1);
        return 1;
      }
      v19 = (Scaleform::Render::ImageData *)level;
      if ( level )
        goto LABEL_56;
      v20 = this->GetTextureSize(this, v59, 0);
      v21 = Scaleform::Render::RawImage::Create(rescaleBuffFromat, sourceMipLevels, v20, 0, 0, 0);
      if ( pimage2.pObject )
        pimage2.pObject->Release(pimage2.pObject);
      pimage2.pObject = v21;
      if ( v21 )
      {
        Scaleform::Render::ImageData::operator=(&imageData2, &v21->Data);
        v19 = &imageData2;
        goto LABEL_56;
      }
      LeaveCriticalSection(&imageLock.pLock->cs);
      goto LABEL_39;
    }
LABEL_17:
    pimage1.pObject = Scaleform::Render::RawImage::Create(rescaleBuffFromat, sourceMipLevels, &this->ImgSize, 0, 0, 0);
    if ( !pimage1.pObject )
    {
      LeaveCriticalSection(&pLock->cs);
LABEL_19:
      Scaleform::Render::ImageData::~ImageData(&imageData2);
      Scaleform::Render::ImageData::~ImageData(&imageData1);
      return 0;
    }
    Scaleform::Render::ImageData::operator=(&imageData1, &pimage1.pObject->Data);
    imageData1.Format = format | 0x100000;
    p_Data = &imageData1;
    goto LABEL_21;
  }
  LeaveCriticalSection(&pLock->cs);
  if ( (imageData2.Flags & 2) != 0 )
  {
    imageData2.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imageData2.pPlanes);
  }
  imageData2.pPlanes = &imageData2.Plane0;
  if ( imageData2.pPalette.pObject )
  {
    v33 = imageData2.pPalette.pObject;
    if ( InterlockedExchangeAdd(&imageData2.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33);
  }
  if ( (imageData1.Flags & 2) != 0 )
  {
    imageData1.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, imageData1.pPlanes);
  }
  imageData1.pPlanes = &imageData1.Plane0;
  if ( imageData1.pPalette.pObject )
  {
    v34 = imageData1.pPalette.pObject;
    if ( InterlockedExchangeAdd(&imageData1.pPalette.pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v34);
  }
  return 0;
}

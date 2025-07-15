char __thiscall Scaleform::Render::TGA::TGAFileImageSource::Decode(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int v8; // ebp
  Scaleform::Render::Palette *pObject; // eax
  Scaleform::Render::Palette *v10; // edi
  char v11; // [esp+Dh] [ebp-1029h]
  unsigned int ReadScanlineSize; // [esp+Eh] [ebp-1028h]
  Scaleform::Render::ImageScanlineBufferImpl v13; // [esp+12h] [ebp-1024h] BYREF
  unsigned __int8 tempBuffer[4096]; // [esp+36h] [ebp-1000h] BYREF

  if ( !Scaleform::Render::FileImageSource::seekFileToDecodeStart(this) )
    return 0;
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &v13,
    this->SourceFormat,
    this->Size.Width,
    this->Format,
    tempBuffer,
    0x1000u);
  if ( v13.ReadFormat == Image_None || !v13.Width || !v13.pReadScanline )
  {
    Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v13);
    return 0;
  }
  v11 = 1;
  if ( (this->ImageDesc & 0x20) != 0 )
  {
    v6 = 0;
    v7 = 1;
  }
  else
  {
    v6 = this->Size.Height - 1;
    v7 = -1;
  }
  v8 = 0;
  ReadScanlineSize = v13.ReadScanlineSize;
  if ( this->Size.Height )
  {
    while ( this->pFile.pObject->Read(this->pFile.pObject, v13.pReadScanline, ReadScanlineSize) == ReadScanlineSize )
    {
      Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        &v13,
        &pdest->pPlanes->pData[v6 * pdest->pPlanes->Pitch],
        this->pColorMap.pObject,
        copyScanline,
        arg);
      ++v8;
      v6 += v7;
      if ( v8 >= this->Size.Height )
        goto LABEL_15;
    }
    v11 = 0;
  }
LABEL_15:
  if ( this->Format == Image_P8 )
  {
    pObject = this->pColorMap.pObject;
    if ( pObject )
      InterlockedExchangeAdd(&pObject->RefCount.Value, 1);
    v10 = pdest->pPalette.pObject;
    if ( v10 )
    {
      if ( InterlockedExchangeAdd(&v10->RefCount.Value, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    }
    pdest->pPalette.pObject = this->pColorMap.pObject;
  }
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&v13);
  return v11;
}

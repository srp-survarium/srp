void __thiscall Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
        Scaleform::Render::ImageScanlineBufferImpl *this,
        Scaleform::Render::ImageFormat readFormat,
        unsigned int width,
        Scaleform::Render::ImageFormat convertSourceFormat,
        unsigned __int8 *tempBuffer,
        unsigned int tempBufferSize)
{
  Scaleform::Render::ImageFormat v7; // ecx
  Scaleform::Render::ImageFormat v8; // eax
  unsigned int FormatBitsPerPixel; // eax
  Scaleform::Render::ImageFormat v10; // ecx
  void (__stdcall *ImageConvertFunc)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax
  unsigned int v12; // edi
  unsigned int v13; // eax

  v7 = convertSourceFormat;
  this->ReadFormat = readFormat;
  if ( convertSourceFormat == Image_None )
    v7 = readFormat;
  this->ConvertSourceFormat = v7;
  this->Width = width;
  this->pReadScanline = 0;
  this->pConvertScanline = 0;
  this->ReadScanlineSize = (width * Scaleform::Render::ImageData::GetFormatBitsPerPixel(readFormat, 0)) >> 3;
  v8 = this->ConvertSourceFormat;
  this->ConvertScanlineSize = 0;
  this->pConvertFunc = 0;
  this->BuffersAllocated = 0;
  if ( this->ReadFormat == v8
    || (FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(v8, 0),
        v10 = this->ConvertSourceFormat,
        this->ConvertScanlineSize = (width * FormatBitsPerPixel) >> 3,
        ImageConvertFunc = (void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *))Scaleform::Render::GetImageConvertFunc(v10, this->ReadFormat),
        (this->pConvertFunc = ImageConvertFunc) != 0) )
  {
    v12 = (this->ReadScanlineSize + 8) & 0xFFFFFFF8;
    v13 = v12 + this->ConvertScanlineSize;
    if ( v13 > tempBufferSize )
    {
      this->pReadScanline = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 v13,
                                                 0);
      this->BuffersAllocated = 1;
    }
    else
    {
      this->pReadScanline = tempBuffer;
    }
    if ( this->pConvertFunc )
      this->pConvertScanline = &this->pReadScanline[v12];
  }
}

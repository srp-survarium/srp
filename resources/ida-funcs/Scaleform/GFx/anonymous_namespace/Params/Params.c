void __thiscall Scaleform::GFx::`anonymous namespace'::Params::Params(
        Scaleform::GFx::Params *this,
        Scaleform::Render::JPEG::Input *jin,
        unsigned int width,
        Scaleform::Render::ImageFormat format)
{
  unsigned int ReadScanlineSize; // edx
  unsigned __int8 *pReadScanline; // [esp-Ch] [ebp-1Ch]

  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->SourceScanline,
    Image_R8G8B8,
    width,
    Image_R8G8B8,
    this->SourceScanline.TempBuffer,
    0x800u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->AlphaScanline,
    Image_A8,
    width,
    Image_A8,
    this->AlphaScanline.TempBuffer,
    0x400u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha0,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha0.TempBuffer,
    0x800u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha1,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha1.TempBuffer,
    0x800u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->ScanlineWithAlpha2,
    Image_R8G8B8A8,
    width + 2,
    Image_R8G8B8A8,
    this->ScanlineWithAlpha2.TempBuffer,
    0x800u);
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    &this->FinalScanline,
    Image_R8G8B8A8,
    width,
    format,
    this->FinalScanline.TempBuffer,
    0x1000u);
  this->ZlibFile.pObject = 0;
  ReadScanlineSize = this->ScanlineWithAlpha0.ReadScanlineSize;
  this->ScanlineWithAlphas[1] = &this->ScanlineWithAlpha1;
  this->ScanlineWithAlphas[2] = &this->ScanlineWithAlpha2;
  pReadScanline = this->ScanlineWithAlpha0.pReadScanline;
  this->Jin = jin;
  this->Width = width;
  this->Success = 1;
  this->ScanlineWithAlphas[0] = &this->ScanlineWithAlpha0;
  memset((int)pReadScanline, 0, ReadScanlineSize);
}

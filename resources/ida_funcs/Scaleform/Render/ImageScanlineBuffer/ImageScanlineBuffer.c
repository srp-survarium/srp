void __thiscall Scaleform::Render::ImageScanlineBuffer<4096>::ImageScanlineBuffer<4096>(
        Scaleform::Render::ImageScanlineBuffer<4096> *this,
        Scaleform::Render::ImageFormat readFormat,
        unsigned int width,
        Scaleform::Render::ImageFormat convertSourceFormat)
{
  Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
    this,
    readFormat,
    width,
    convertSourceFormat,
    this->TempBuffer,
    0x1000u);
}

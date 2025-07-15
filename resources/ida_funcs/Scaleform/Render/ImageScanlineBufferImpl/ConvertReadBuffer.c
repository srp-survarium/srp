void __thiscall Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        Scaleform::Render::ImageScanlineBufferImpl *this,
        unsigned __int8 *dest,
        Scaleform::Render::Palette *pal,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *scanlineArg)
{
  void (__stdcall *pConvertFunc)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *); // eax

  pConvertFunc = this->pConvertFunc;
  if ( pConvertFunc )
  {
    pConvertFunc(this->pConvertScanline, this->pReadScanline, this->ReadScanlineSize, pal, 0);
    copyScanline(dest, this->pConvertScanline, this->ConvertScanlineSize, 0, scanlineArg);
  }
  else
  {
    copyScanline(dest, this->pReadScanline, this->ReadScanlineSize, pal, scanlineArg);
  }
}

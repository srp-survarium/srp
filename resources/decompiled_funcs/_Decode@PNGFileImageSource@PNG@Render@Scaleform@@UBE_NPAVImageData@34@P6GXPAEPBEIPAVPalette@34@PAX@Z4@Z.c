bool __thiscall Scaleform::Render::PNG::PNGFileImageSource::Decode(
        Scaleform::Render::PNG::PNGFileImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  return this->pOriginalInput
      && this->pOriginalInput->Decode(this->pOriginalInput, this->Format, pdest, copyScanline, arg);
}

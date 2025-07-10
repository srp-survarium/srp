char __thiscall Scaleform::Render::JPEG::ImageSource::Decode(
        Scaleform::Render::JPEG::ImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  Scaleform::Render::JPEG::Input *pOriginalInput; // eax

  pOriginalInput = this->pOriginalInput;
  if ( pOriginalInput )
  {
    this->pOriginalInput = 0;
  }
  else
  {
    if ( !Scaleform::Render::FileImageSource::seekFileToDecodeStart(this) )
      return 0;
    pOriginalInput = Scaleform::Render::JPEG::FileReader::CreateInput(
                       &Scaleform::Render::JPEG::FileReader::Instance,
                       (Scaleform::GFx::Resource *)this->pFile.pObject);
    if ( !pOriginalInput )
      return 0;
  }
  return Scaleform::Render::JPEG::DecodeHelper(pOriginalInput, this->Format, pdest, copyScanline, arg);
}

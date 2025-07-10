int __thiscall Scaleform::Render::WrapperImageSource::Decode(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *copyScanline)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *), void *))this->pDelegate.pObject->Decode)(
           this->pDelegate.pObject,
           pdest,
           copyScanline,
           arg);
}

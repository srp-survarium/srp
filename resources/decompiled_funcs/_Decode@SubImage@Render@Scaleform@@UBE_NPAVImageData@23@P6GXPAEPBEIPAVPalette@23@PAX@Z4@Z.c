int __thiscall Scaleform::Render::SubImage::Decode(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::ImageData *pdest,
        void (__stdcall *csf)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *),
        void *arg)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, void (__stdcall *)(unsigned __int8 *, const unsigned __int8 *, unsigned int, Scaleform::Render::Palette *, void *), void *))this->pImage.pObject->Decode)(
           this->pImage.pObject,
           pdest,
           csf,
           arg);
}

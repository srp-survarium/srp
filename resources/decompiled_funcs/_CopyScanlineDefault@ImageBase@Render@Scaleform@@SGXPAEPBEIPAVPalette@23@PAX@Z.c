void __stdcall Scaleform::Render::ImageBase::CopyScanlineDefault(
        unsigned __int8 *pd,
        unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  memcpy(pd, ps, size);
}

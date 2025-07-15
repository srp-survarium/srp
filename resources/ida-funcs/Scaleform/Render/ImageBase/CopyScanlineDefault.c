void __stdcall Scaleform::Render::ImageBase::CopyScanlineDefault(
        unsigned __int8 *pd,
        const __m128i *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  memcpy((int)pd, ps, size);
}

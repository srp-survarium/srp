void __stdcall Scaleform::Render::Image_CopyScanline_A_BGR(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  unsigned int i; // esi

  for ( i = size; i; --i )
  {
    *pd = *ps;
    pd[1] = *ps;
    pd[2] = *ps;
    pd += 3;
    ++ps;
  }
}

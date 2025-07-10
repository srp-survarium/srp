void __stdcall Scaleform::Render::Image_CopyScanline_A_BGRA(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  unsigned int i; // esi

  for ( i = size; i; --i )
  {
    *pd = -1;
    pd[1] = -1;
    pd[2] = -1;
    pd[3] = *ps;
    pd += 4;
    ++ps;
  }
}

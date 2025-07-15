void __stdcall Scaleform::Render::Image_CopyScanline_BGRA_A(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  unsigned __int8 *v6; // ecx
  unsigned int v7; // eax

  if ( size )
  {
    v6 = (unsigned __int8 *)(ps + 3);
    v7 = ((size - 1) >> 2) + 1;
    do
    {
      *pd++ = *v6;
      v6 += 4;
      --v7;
    }
    while ( v7 );
  }
}

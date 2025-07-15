void __stdcall Scaleform::Render::Image_CopyScanline_BGR_A_Avg(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *__formal,
        void *a5)
{
  unsigned int v7; // esi

  if ( size )
  {
    v7 = (size - 1) / 3 + 1;
    do
    {
      *pd++ = (*ps + ps[1] + (unsigned int)ps[2]) / 3;
      ps += 3;
      --v7;
    }
    while ( v7 );
  }
}

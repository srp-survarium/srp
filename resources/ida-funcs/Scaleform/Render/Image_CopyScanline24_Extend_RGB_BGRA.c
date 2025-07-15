void __stdcall Scaleform::Render::Image_CopyScanline24_Extend_RGB_BGRA(
        unsigned __int8 *pd,
        unsigned __int8 *ps,
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
      *pd = ps[2];
      pd[1] = ps[1];
      pd[2] = *ps;
      pd[3] = -1;
      pd += 4;
      ps += 3;
      --v7;
    }
    while ( v7 );
  }
}

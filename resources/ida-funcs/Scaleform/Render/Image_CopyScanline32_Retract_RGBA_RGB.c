void __stdcall Scaleform::Render::Image_CopyScanline32_Retract_RGBA_RGB(
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
      *pd = *ps;
      pd[1] = ps[1];
      pd[2] = ps[2];
      pd += 3;
      ps += 4;
      --v7;
    }
    while ( v7 );
  }
}

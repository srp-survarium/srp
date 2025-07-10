void __stdcall Scaleform::Render::Image_CopyScanline_P_A(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *colorMap,
        void *__formal)
{
  unsigned int v7; // ebp
  unsigned int Raw; // eax

  if ( size )
  {
    v7 = size;
    do
    {
      Raw = colorMap->Colors[*ps].Raw;
      if ( colorMap->HasAlphaFlag )
        *pd = HIBYTE(Raw);
      else
        *pd = ((unsigned __int8)Raw + BYTE1(Raw) + (unsigned int)BYTE2(Raw)) / 3;
      ++pd;
      ++ps;
      --v7;
    }
    while ( v7 );
  }
}

void __stdcall Scaleform::Render::Image_CopyScanline_P_RGBA(
        unsigned __int8 *pd,
        const unsigned __int8 *ps,
        unsigned int size,
        Scaleform::Render::Palette *colorMap,
        void *__formal)
{
  unsigned int i; // ebp
  unsigned int Raw; // eax

  for ( i = size; i; --i )
  {
    Raw = colorMap->Colors[*ps].Raw;
    *pd = BYTE2(Raw);
    pd[2] = Raw;
    pd[1] = BYTE1(Raw);
    pd[3] = HIBYTE(Raw);
    pd += 4;
    ++ps;
  }
}

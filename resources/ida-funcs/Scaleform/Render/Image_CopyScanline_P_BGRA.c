void __stdcall Scaleform::Render::Image_CopyScanline_P_BGRA(
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
    *(_DWORD *)pd = Raw;
    pd += 4;
    ++ps;
  }
}

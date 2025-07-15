void __thiscall Scaleform::Render::ImageData::SetPixelInScanline(
        Scaleform::Render::ImageData *this,
        unsigned __int8 *pline,
        unsigned int x,
        unsigned int color)
{
  Scaleform::Render::ImageFormat Format; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx

  Format = this->Format;
  if ( this->Format > Image_A8 )
  {
    if ( Format == Image_PS3_A8R8G8B8 )
    {
      pline[4 * x] = HIBYTE(color);
      pline[4 * x + 1] = BYTE2(color);
      pline[4 * x + 2] = BYTE1(color);
      pline[4 * x + 3] = color;
    }
  }
  else if ( this->Format == Image_A8 )
  {
    pline[x] = HIBYTE(color);
  }
  else
  {
    switch ( Format )
    {
      case Image_R8G8B8A8:
        pline[4 * x] = BYTE2(color);
        pline[4 * x + 2] = color;
        pline[4 * x + 1] = BYTE1(color);
        pline[4 * x + 3] = HIBYTE(color);
        break;
      case Image_B8G8R8A8:
        *(_DWORD *)&pline[4 * x] = color;
        break;
      case Image_R8G8B8:
        v5 = &pline[2 * x + x];
        *v5 = BYTE2(color);
        v5[1] = BYTE1(color);
        v5[2] = color;
        break;
      case Image_B8G8R8:
        v6 = &pline[2 * x + x];
        *v6 = color;
        *(_WORD *)(v6 + 1) = *(_WORD *)((char *)&color + 1);
        break;
      default:
        return;
    }
  }
}

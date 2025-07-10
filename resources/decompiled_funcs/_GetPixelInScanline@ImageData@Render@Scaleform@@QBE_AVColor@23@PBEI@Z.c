Scaleform::Render::Color *__thiscall Scaleform::Render::ImageData::GetPixelInScanline(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::Color *result,
        const unsigned __int8 *pline,
        unsigned int x)
{
  Scaleform::Render::ImageFormat Format; // ecx
  Scaleform::Render::Color *v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // dl
  unsigned __int8 v10; // cl

  Format = this->Format;
  v5 = result;
  if ( Format > Image_A8 )
  {
    if ( Format == Image_PS3_A8R8G8B8 )
    {
      result->Channels.Red = pline[4 * x + 1];
      result->Channels.Green = pline[4 * x + 2];
      v10 = pline[4 * x];
      result->Channels.Blue = pline[4 * x + 3];
      result->Channels.Alpha = v10;
    }
  }
  else if ( Format == Image_A8 )
  {
LABEL_8:
    v9 = pline[4 * x];
    result->Channels.Red = -1;
    result->Channels.Green = -1;
    result->Channels.Blue = -1;
    result->Channels.Alpha = v9;
  }
  else
  {
    switch ( Format )
    {
      case Image_R8G8B8A8:
        result->Channels.Red = pline[4 * x];
        result->Channels.Green = pline[4 * x + 1];
        v7 = pline[4 * x + 3];
        result->Channels.Blue = pline[4 * x + 2];
        result->Channels.Alpha = v7;
        break;
      case Image_B8G8R8A8:
        result->Channels.Red = pline[4 * x + 2];
        result->Channels.Green = pline[4 * x + 1];
        v6 = pline[4 * x + 3];
        result->Channels.Blue = pline[4 * x];
        result->Channels.Alpha = v6;
        break;
      case Image_R8G8B8:
        result->Channels.Red = pline[4 * x];
        v8 = pline[4 * x + 2];
        result->Channels.Green = pline[4 * x + 1];
        result->Channels.Blue = v8;
        result->Channels.Alpha = -1;
        break;
      case Image_B8G8R8:
        result->Channels.Red = pline[4 * x + 2];
        result->Channels.Green = pline[4 * x + 1];
        result->Channels.Blue = pline[4 * x];
        result->Channels.Alpha = -1;
        goto LABEL_8;
      default:
        return v5;
    }
  }
  return v5;
}

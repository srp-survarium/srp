int __thiscall Scaleform::Render::Text::ParagraphFormat::HashFunctor::operator()(
        Scaleform::Render::Text::ParagraphFormat::HashFunctor *this,
        const Scaleform::Render::Text::ParagraphFormat *data)
{
  unsigned __int16 PresentMask; // bx
  int v3; // esi
  unsigned int *pTabStops; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // esi
  bool v8; // dl

  PresentMask = data->PresentMask;
  v3 = 0;
  if ( (PresentMask & 0x40) != 0 && data->pTabStops )
  {
    pTabStops = data->pTabStops;
    v5 = 4 * *pTabStops + 4;
    v6 = 5381;
    if ( 4 * *pTabStops != -4 )
    {
      do
      {
        v7 = *((unsigned __int8 *)pTabStops + --v5);
        v6 = v7 + 65599 * v6;
      }
      while ( v5 );
    }
    v3 = v6;
  }
  if ( (PresentMask & 2) != 0 )
    v3 ^= data->BlockIndent;
  if ( (PresentMask & 4) != 0 )
    v3 ^= data->Indent << 8;
  if ( (PresentMask & 8) != 0 )
    v3 ^= data->Leading << 12;
  if ( (PresentMask & 0x10) != 0 )
    v3 ^= data->LeftMargin << 16;
  if ( (PresentMask & 0x20) != 0 )
    v3 ^= data->RightMargin << 18;
  v8 = (PresentMask & 0x80u) != 0 && (data->PresentMask & 0x8000) != 0;
  return v3 ^ (data->PresentMask >> 1) & 0xC00 ^ (v8 | (data->PresentMask << 9) | HIBYTE(data->PresentMask) & 6);
}

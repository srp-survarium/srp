char __thiscall Scaleform::GFx::FontCompactor::GlyphsEqual(
        Scaleform::GFx::FontCompactor *this,
        unsigned int pos,
        Scaleform::GFx::FontCompactor *cmpFont,
        unsigned int cmpPos)
{
  unsigned int v4; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  unsigned __int8 **Pages; // [esp+18h] [ebp+8h]

  v4 = pos;
  v6 = cmpPos;
  v7 = Scaleform::GFx::FontCompactor::navigateToEndGlyph(this, pos);
  if ( v7 - pos != Scaleform::GFx::FontCompactor::navigateToEndGlyph(cmpFont, cmpPos) - cmpPos )
    return 0;
  if ( pos < v7 )
  {
    Pages = cmpFont->Decoder.Data->Pages;
    while ( this->Decoder.Data->Pages[v4 >> 12][v4 & 0xFFF] == Pages[v6 >> 12][v6 & 0xFFF] )
    {
      ++v4;
      ++v6;
      if ( v4 >= v7 )
        return 1;
    }
    return 0;
  }
  return 1;
}

int __thiscall Scaleform::GFx::FontCompactor::ComputeGlyphHash(Scaleform::GFx::FontCompactor *this, unsigned int pos)
{
  unsigned int v2; // esi
  int v4; // edi
  unsigned int v5; // eax
  int v6; // edx

  v2 = pos;
  v4 = 0;
  v5 = Scaleform::GFx::FontCompactor::navigateToEndGlyph(this, pos);
  if ( pos < v5 )
  {
    do
    {
      v6 = (33 * v4) ^ this->Decoder.Data->Pages[v2 >> 12][v2 & 0xFFF];
      ++v2;
      v4 = v6;
    }
    while ( v2 < v5 );
  }
  return v4;
}

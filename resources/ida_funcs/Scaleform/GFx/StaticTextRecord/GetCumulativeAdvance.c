double __thiscall Scaleform::GFx::StaticTextRecord::GetCumulativeAdvance(Scaleform::GFx::StaticTextRecord *this)
{
  signed int Size; // esi
  unsigned int v2; // edi
  float *p_GlyphAdvance; // eax
  unsigned int v4; // edx
  double v5; // st7
  float *v6; // eax
  unsigned int v7; // esi
  double v8; // st7
  float advance; // [esp+4h] [ebp-4h]
  float advancea; // [esp+4h] [ebp-4h]
  float advanceb; // [esp+4h] [ebp-4h]
  float advancec; // [esp+4h] [ebp-4h]

  Size = this->Glyphs.Data.Size;
  advance = 0.0;
  v2 = 0;
  if ( Size >= 4 )
  {
    p_GlyphAdvance = &this->Glyphs.Data.Data[1].GlyphAdvance;
    v4 = ((unsigned int)(Size - 4) >> 2) + 1;
    v2 = 4 * v4;
    do
    {
      v5 = *(p_GlyphAdvance - 2);
      p_GlyphAdvance += 8;
      --v4;
      advancea = v5 + advance;
      advanceb = advancea + *(p_GlyphAdvance - 8);
      advancec = advanceb + *(p_GlyphAdvance - 6);
      advance = advancec + *(p_GlyphAdvance - 4);
    }
    while ( v4 );
  }
  if ( v2 < Size )
  {
    v6 = &this->Glyphs.Data.Data[v2].GlyphAdvance;
    v7 = Size - v2;
    do
    {
      v8 = *v6;
      v6 += 2;
      --v7;
      advance = v8 + advance;
    }
    while ( v7 );
  }
  return advance;
}

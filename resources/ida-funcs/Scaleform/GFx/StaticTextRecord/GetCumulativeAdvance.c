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
  float v10; // [esp+4h] [ebp-4h]
  float v11; // [esp+4h] [ebp-4h]
  float v12; // [esp+4h] [ebp-4h]
  float v13; // [esp+4h] [ebp-4h]

  Size = this->Glyphs.Data.Size;
  v10 = 0.0;
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
      v11 = v5 + v10;
      v12 = v11 + *(p_GlyphAdvance - 8);
      v13 = v12 + *(p_GlyphAdvance - 6);
      v10 = v13 + *(p_GlyphAdvance - 4);
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
      v10 = v8 + v10;
    }
    while ( v7 );
  }
  return v10;
}

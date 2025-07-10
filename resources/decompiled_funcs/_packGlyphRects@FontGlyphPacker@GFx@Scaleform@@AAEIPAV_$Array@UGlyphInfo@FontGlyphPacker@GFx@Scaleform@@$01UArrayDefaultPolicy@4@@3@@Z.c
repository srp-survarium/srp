unsigned int __thiscall Scaleform::GFx::FontGlyphPacker::packGlyphRects(
        Scaleform::GFx::FontGlyphPacker *this,
        Scaleform::Array<Scaleform::GFx::FontGlyphPacker::GlyphInfo,2,Scaleform::ArrayDefaultPolicy> *glyphs)
{
  unsigned int v3; // eax
  unsigned int v5; // edi
  unsigned int v6; // ecx
  int v7; // edx
  int glyphsa; // [esp+8h] [ebp+4h]

  v3 = 0;
  if ( !this->pFontPackParams->SeparateTextures )
    return Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, 0, glyphs->Data.Size, 0);
  v5 = 1;
  v6 = 0;
  if ( glyphs->Data.Size > 1 )
  {
    v7 = 48;
    glyphsa = 48;
    do
    {
      if ( *(Scaleform::GFx::FontResource **)((char *)&glyphs->Data.Data[-1].pFont + v7) != *(Scaleform::GFx::FontResource **)((char *)&glyphs->Data.Data->pFont + v7) )
      {
        v3 = Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, v6, v5, v3);
        v6 = v5;
      }
      ++v5;
      v7 = glyphsa + 48;
      glyphsa += 48;
    }
    while ( v5 < glyphs->Data.Size );
  }
  return Scaleform::GFx::FontGlyphPacker::packGlyphRects(this, glyphs, v6, glyphs->Data.Size, v3);
}

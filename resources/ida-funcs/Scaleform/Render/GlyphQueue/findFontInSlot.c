const Scaleform::Render::GlyphNode *__cdecl Scaleform::Render::GlyphQueue::findFontInSlot(
        Scaleform::Render::GlyphNode *glyph,
        const Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::GlyphNode *v2; // esi
  const Scaleform::Render::GlyphNode *result; // eax

  v2 = glyph;
  if ( !glyph )
    return 0;
  while ( v2->Param.pFont != font )
  {
    result = Scaleform::Render::GlyphQueue::findFontInSlot(v2->pNext, font);
    if ( result )
      return result;
    v2 = v2->pNex2;
    if ( !v2 )
      return 0;
  }
  return v2;
}

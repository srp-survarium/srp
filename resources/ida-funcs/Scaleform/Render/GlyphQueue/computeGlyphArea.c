void __thiscall Scaleform::Render::GlyphQueue::computeGlyphArea(
        Scaleform::Render::GlyphQueue *this,
        const Scaleform::Render::GlyphNode *glyph,
        unsigned int *used)
{
  const Scaleform::Render::GlyphNode *i; // esi

  for ( i = glyph; i; i = i->pNex2 )
  {
    if ( i->Param.pFont )
      *used += i->mRect.w * i->mRect.h;
    Scaleform::Render::GlyphQueue::computeGlyphArea(this, i->pNext, used);
  }
}

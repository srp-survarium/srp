Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::findSpaceInSlots(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphQueue *pNextActive; // eax
  Scaleform::Render::GlyphQueue *NumBandsInTexture; // esi
  Scaleform::Render::GlyphNode *result; // eax

  pNextActive = (Scaleform::Render::GlyphQueue *)this->ActiveSlots.Root.pNextActive;
  if ( pNextActive == (Scaleform::Render::GlyphQueue *)&this->ActiveSlots )
    return 0;
  while ( 1 )
  {
    NumBandsInTexture = (Scaleform::Render::GlyphQueue *)pNextActive->NumBandsInTexture;
    result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, (Scaleform::Render::GlyphSlot *)pNextActive);
    if ( result )
      break;
    pNextActive = NumBandsInTexture;
    if ( NumBandsInTexture == (Scaleform::Render::GlyphQueue *)&this->ActiveSlots )
      return 0;
  }
  return result;
}

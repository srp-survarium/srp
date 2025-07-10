Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::packGlyph(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphNode *pRoot; // eax
  unsigned int v5; // ebp
  unsigned int v6; // edi
  unsigned __int16 x; // ax
  unsigned __int16 v8; // cx
  Scaleform::Render::GlyphNode *result; // eax
  unsigned __int16 Failures; // cx

  pRoot = slot->pRoot;
  if ( !pRoot->Param.pFont )
  {
    v5 = slot->w;
    if ( v5 > 2 * w )
    {
      if ( pRoot->pNext )
      {
        if ( !pRoot->pNex2 && pRoot->mRect.h == slot->pBand->h )
        {
          v6 = pRoot->mRect.w;
          if ( v6 > w )
          {
            x = pRoot->mRect.x;
            v8 = slot->x;
            if ( (x == v8) != (v6 + x == v5 + v8) )
              Scaleform::Render::GlyphQueue::splitGlyph(this, slot, x == v8, w);
          }
        }
      }
      else if ( !pRoot->pNex2 )
      {
        Scaleform::Render::GlyphQueue::splitSlot(this, slot, w);
      }
    }
  }
  result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, slot->pRoot);
  if ( !result )
    ++slot->Failures;
  Failures = slot->Failures;
  if ( Failures <= 0x10u )
  {
    if ( Failures )
    {
      if ( result )
        slot->Failures = Failures - 1;
    }
  }
  else
  {
    slot->pPrevActive->pNextActive = slot->pNextActive;
    slot->pNextActive->pPrevActive = slot->pPrevActive;
    slot->TextureId |= 0x8000u;
  }
  return result;
}

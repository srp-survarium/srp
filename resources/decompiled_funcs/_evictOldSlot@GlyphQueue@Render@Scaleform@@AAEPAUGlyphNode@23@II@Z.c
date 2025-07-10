Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphQueue::evictOldSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphNode *result; // eax

  this->pEvictNotifier->ApplyInUseList(this->pEvictNotifier);
  result = Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 0);
  if ( !result )
  {
    this->pEvictNotifier->UpdatePinList(this->pEvictNotifier);
    return Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 1u);
  }
  return result;
}

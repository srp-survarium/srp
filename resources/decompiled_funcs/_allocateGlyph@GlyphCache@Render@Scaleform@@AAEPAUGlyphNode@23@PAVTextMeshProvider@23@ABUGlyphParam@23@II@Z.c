Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphCache::allocateGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphQueue *p_Queue; // edi
  Scaleform::Render::GlyphNode *result; // eax
  Scaleform::Render::GlyphNode *v7; // esi
  Scaleform::Render::TextNotifier *Notifier; // eax

  p_Queue = &this->Queue;
  result = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, w, h);
  v7 = result;
  if ( result )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(p_Queue, result, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
    return v7;
  }
  return result;
}

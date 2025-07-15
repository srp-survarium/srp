Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphCache::FindGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp)
{
  Scaleform::Render::GlyphQueue *p_Queue; // edi
  Scaleform::Render::GlyphNode *result; // eax
  Scaleform::Render::GlyphNode *v5; // esi
  Scaleform::Render::TextNotifier *Notifier; // eax

  p_Queue = &this->Queue;
  result = Scaleform::Render::GlyphQueue::FindGlyph(&this->Queue, gp);
  v5 = result;
  if ( result )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(p_Queue, result, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
    return v5;
  }
  return result;
}

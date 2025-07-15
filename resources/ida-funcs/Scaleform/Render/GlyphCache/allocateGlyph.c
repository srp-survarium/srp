Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphCache::allocateGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp,
        Scaleform::Render::GlyphNode *w,
        Scaleform::Render::GlyphNode *h)
{
  Scaleform::Render::GlyphQueue *p_Queue; // edi
  Scaleform::Render::GlyphNode *Glyph; // eax
  Scaleform::Render::GlyphNode *v7; // esi
  Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,79> >::PageType *Notifier; // eax
  Scaleform::AmpServer *Instance; // eax

  p_Queue = &this->Queue;
  Glyph = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, w, h);
  v7 = Glyph;
  if ( Glyph )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(p_Queue, Glyph, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)Notifier);
    return v7;
  }
  else
  {
    Instance = Scaleform::AmpServer::GetInstance();
    Instance->IncrementFontFailures(Instance);
    return 0;
  }
}

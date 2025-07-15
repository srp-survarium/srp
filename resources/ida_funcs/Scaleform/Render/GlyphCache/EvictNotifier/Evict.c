void __thiscall Scaleform::Render::GlyphCache::EvictNotifier::Evict(
        Scaleform::Render::GlyphCache::EvictNotifier *this,
        Scaleform::Render::TextMeshProvider *p)
{
  Scaleform::Render::TextMeshProvider::OnEvictSlots(p);
}

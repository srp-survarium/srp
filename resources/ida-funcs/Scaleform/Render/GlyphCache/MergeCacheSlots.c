void __thiscall Scaleform::Render::GlyphCache::MergeCacheSlots(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphQueue::MergeEmptySlots(&this->Queue);
}

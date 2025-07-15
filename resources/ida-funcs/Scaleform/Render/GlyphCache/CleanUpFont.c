void __thiscall Scaleform::Render::GlyphCache::CleanUpFont(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::FontCacheHandle *v3; // ebp
  Scaleform::Render::FontCacheHandle *i; // eax
  Scaleform::Render::GlyphCache::EvictNotifier *v5; // ecx
  Scaleform::Render::FontCacheHandle *pManager; // edi

  Scaleform::Render::GlyphCache::ApplyInUseList(this);
  Scaleform::Render::GlyphCache::UpdatePinList(this);
  v3 = font;
  Scaleform::Render::GlyphQueue::CleanUpFont(&this->Queue, font);
  for ( i = (Scaleform::Render::FontCacheHandle *)this->VectorGlyphShapeList.Root.pNext; ; i = pManager )
  {
    font = i;
    v5 = this == (Scaleform::Render::GlyphCache *)-2960 ? 0 : &this->Notifier;
    if ( i == (Scaleform::Render::FontCacheHandle *)v5 )
      break;
    pManager = (Scaleform::Render::FontCacheHandle *)i[1].pManager;
    if ( (Scaleform::Render::FontCacheHandle *)i[1].pFont == v3 )
    {
      i[1].pNext[1].pManager = (Scaleform::Render::FontCacheHandleManager *)pManager;
      i[1].pManager->FontLock.cs.OwningThread = i[1].pNext;
      Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
        &this->VectorGlyphCache,
        (Scaleform::Render::VectorGlyphShape **)&font);
    }
  }
}

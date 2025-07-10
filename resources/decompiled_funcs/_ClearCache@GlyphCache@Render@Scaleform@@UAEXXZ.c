void __thiscall Scaleform::Render::GlyphCache::ClearCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::FontCacheHandleManager *v2; // ecx

  Scaleform::Render::GlyphCache::UnpinAllSlots((Scaleform::Render::GlyphCache *)((char *)this - 12));
  Scaleform::Render::GlyphQueue::Clear((Scaleform::Render::GlyphQueue *)&this->Textures[31].pFill);
  v2 = 0;
  this->Method = TU_DirectMap;
  this->UpdatePacker.Width = 0;
  this->UpdatePacker.Height = 0;
  this->UpdatePacker.LastMaxHeight = 0;
  this->GlyphsToUpdate.MaxPages = 0;
  if ( this != (Scaleform::Render::GlyphCache *)-2948 )
    v2 = (Scaleform::Render::FontCacheHandleManager *)&this->TextInUse.Root.4;
  this->pFontHandleManager.pObject = v2;
  this->pRQCaches = (Scaleform::Render::RQCacheInterface *)v2;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&this->pLog);
}

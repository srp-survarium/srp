void __thiscall Scaleform::Render::GlyphCache::Destroy(Scaleform::Render::GlyphCache *this)
{
  unsigned int v2; // ecx
  Scaleform::Render::GlyphTextureMapper *Textures; // eax
  Scaleform::Render::VectorGlyphShape *p_Notifier; // ecx
  Scaleform::Render::FontCacheHandleManager *pObject; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::Render::RQCacheInterface *pRQCaches; // eax

  Scaleform::Render::GlyphCache::UnpinAllSlots(this);
  Scaleform::Render::GlyphQueue::Clear(&this->Queue);
  v2 = 0;
  if ( this->MaxNumTextures )
  {
    Textures = this->Textures;
    do
    {
      Textures->Valid = 0;
      Textures->NumGlyphsToUpdate = 0;
      ++v2;
      ++Textures;
    }
    while ( v2 < this->MaxNumTextures );
  }
  this->UpdatePacker.LastX = 0;
  this->UpdatePacker.LastY = 0;
  this->UpdatePacker.LastMaxHeight = 0;
  this->GlyphsToUpdate.Size = 0;
  this->RectsToUpdate.Size = 0;
  if ( this == (Scaleform::Render::GlyphCache *)-2960 )
    p_Notifier = 0;
  else
    p_Notifier = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
  this->VectorGlyphShapeList.Root.pPrev = p_Notifier;
  this->VectorGlyphShapeList.Root.pNext = p_Notifier;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>(&this->VectorGlyphCache);
  pObject = this->pFontHandleManager.pObject;
  if ( pObject )
  {
    Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(pObject);
    v6 = (Scaleform::RefCountVImpl *)this->pFontHandleManager.pObject;
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    this->pFontHandleManager.pObject = 0;
  }
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
  {
    pRQCaches->pCaches[1] = 0;
    this->pRQCaches = 0;
  }
}

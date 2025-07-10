void __thiscall Scaleform::Render::TextMeshProvider::AddToInUseList(Scaleform::Render::TextMeshProvider *this)
{
  unsigned int Flags; // eax
  Scaleform::Render::GlyphCache *pCache; // eax
  Scaleform::Render::TextMeshProvider *pPrev; // edx

  Flags = this->Flags;
  if ( (Flags & 6) == 0 )
  {
    this->Flags = Flags | 2;
    pCache = this->pCache;
    pPrev = pCache->TextInUse.Root.pPrev;
    pCache = (Scaleform::Render::GlyphCache *)((char *)pCache + 2924);
    this->pPrev = pPrev;
    this->pNext = (Scaleform::Render::TextMeshProvider *)&pCache[-1].RasterCacheWarning;
    pCache->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[2].~Scaleform::Render::GlyphCache = (void (__thiscall *)(struct Scaleform::Render::GlyphCache *))this;
    pCache->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::GlyphCache_vtbl *)this;
  }
}

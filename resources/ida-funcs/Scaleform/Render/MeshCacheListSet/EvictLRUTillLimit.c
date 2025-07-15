char __thiscall Scaleform::Render::MeshCacheListSet::EvictLRUTillLimit(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListSet::ListSlot *list,
        Scaleform::AllocAddr *a,
        unsigned int size,
        unsigned int limit)
{
  Scaleform::Render::MeshCacheItem *pPrev; // edx

  pPrev = list->Root.pPrev;
  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev != list )
  {
    while ( list->Size > limit )
    {
      ++this->pCache->Thrashing;
      if ( this->pCache->Evict(this->pCache, pPrev, a, 0) >= size )
        return 1;
      pPrev = list->Root.pPrev;
      if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
        return 0;
    }
  }
  return 0;
}

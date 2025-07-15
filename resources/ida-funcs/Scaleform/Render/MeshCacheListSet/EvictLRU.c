char __thiscall Scaleform::Render::MeshCacheListSet::EvictLRU(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListSet::ListSlot *list,
        Scaleform::AllocAddr *a,
        unsigned int size)
{
  Scaleform::Render::MeshCacheItem *pPrev; // edx

  pPrev = list->Root.pPrev;
  if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
    return 0;
  while ( 1 )
  {
    ++this->pCache->Thrashing;
    if ( this->pCache->Evict(this->pCache, pPrev, a, 0) >= size )
      break;
    pPrev = list->Root.pPrev;
    if ( (Scaleform::Render::MeshCacheListSet::ListSlot *)list->Root.pPrev == list )
      return 0;
  }
  return 1;
}

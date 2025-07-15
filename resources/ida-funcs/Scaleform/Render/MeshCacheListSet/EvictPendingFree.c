bool __thiscall Scaleform::Render::MeshCacheListSet::EvictPendingFree(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::AllocAddr *a)
{
  Scaleform::Render::MeshCacheItem *pNext; // eax
  Scaleform::Render::MeshCacheListSet::ListSlot *v4; // edi
  Scaleform::Render::MeshCacheItem *v5; // esi

  pNext = this->Slots[5].Root.pNext;
  v4 = &this->Slots[5];
  if ( pNext != (Scaleform::Render::MeshCacheItem *)&this->Slots[5] )
  {
    do
    {
      v5 = pNext->pNext;
      this->pCache->Evict(this->pCache, pNext, a, 0);
      pNext = v5;
    }
    while ( v5 != (Scaleform::Render::MeshCacheItem *)v4 );
  }
  return 0;
}

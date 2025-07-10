void __thiscall Scaleform::Render::MeshCacheListSet::PushListToFront(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListType to,
        Scaleform::Render::MeshCacheListType from)
{
  Scaleform::Render::MeshCacheItem *pNext; // edx
  Scaleform::Render::MeshCacheListSet::ListSlot *i; // eax
  char *v5; // esi
  Scaleform::Render::MeshCacheItem *v6; // edx
  Scaleform::Render::MeshCacheItem *pPrev; // edi

  pNext = this->Slots[from].Root.pNext;
  for ( i = &this->Slots[from]; pNext != (Scaleform::Render::MeshCacheItem *)i; pNext = pNext->pNext )
    pNext->ListType = to;
  v5 = (char *)this + 12 * to;
  v6 = this->Slots[from].Root.pNext;
  if ( v6 != (Scaleform::Render::MeshCacheItem *)i )
  {
    this->Slots[from].Root.pNext = (Scaleform::Render::MeshCacheItem *)&this->Slots[from];
    pPrev = i->Root.pPrev;
    i->Root.pPrev = (Scaleform::Render::MeshCacheItem *)i;
    pPrev->pNext = (Scaleform::Render::MeshCacheItem *)*((_DWORD *)v5 + 2);
    v6->pPrev = (Scaleform::Render::MeshCacheItem *)(v5 + 4);
    **((_DWORD **)v5 + 2) = pPrev;
    *((_DWORD *)v5 + 2) = v6;
  }
  *((_DWORD *)v5 + 3) += this->Slots[from].Size;
  this->Slots[from].Size = 0;
}

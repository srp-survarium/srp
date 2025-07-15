void __thiscall Scaleform::Render::MeshCache::MoveToCacheListFront(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheListType list,
        Scaleform::Render::MeshCacheItem *p)
{
  Scaleform::Render::MeshCacheListSet *pCacheList; // edx
  unsigned int *p_Size; // ecx
  Scaleform::Render::MeshCacheListSet *v5; // edx
  char *v6; // edx

  if ( p )
  {
    pCacheList = p->pCacheList;
    p->pPrev->pNext = p->pNext;
    p->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$91FE2188799D963DDDCE23AE0AD4A8E3::pPrev = p->pPrev;
    p_Size = &pCacheList->Slots[p->ListType].Size;
    *p_Size -= p->AllocSize;
    v5 = p->pCacheList;
    p->ListType = list;
    v6 = (char *)v5 + 12 * list;
    p->pNext = (Scaleform::Render::MeshCacheItem *)*((_DWORD *)v6 + 2);
    p->pPrev = (Scaleform::Render::MeshCacheItem *)(v6 + 4);
    **((_DWORD **)v6 + 2) = p;
    *((_DWORD *)v6 + 2) = p;
    *((_DWORD *)v6 + 3) += p->AllocSize;
  }
}

void __thiscall Scaleform::Render::MeshCacheListSet::PushFront(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListType type,
        Scaleform::Render::MeshCacheItem *p)
{
  char *v3; // edx

  p->ListType = type;
  v3 = (char *)this + 12 * type;
  p->pNext = (Scaleform::Render::MeshCacheItem *)*((_DWORD *)v3 + 2);
  p->pPrev = (Scaleform::Render::MeshCacheItem *)(v3 + 4);
  **((_DWORD **)v3 + 2) = p;
  *((_DWORD *)v3 + 2) = p;
  *((_DWORD *)v3 + 3) += p->AllocSize;
}

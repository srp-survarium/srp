BOOL __userpurge Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer@<eax>(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::MeshCacheListSet::ListSlot *plist,
        Scaleform::Render::MeshCacheItem *count,
        Scaleform::Render::D3D1x::MeshBuffer *pbuffer)
{
  Scaleform::Render::MeshCacheListSet::ListSlot *pNext; // esi
  unsigned int Size; // eax
  Scaleform::Render::MeshCacheItem *pPrev; // eax
  int plista; // [esp+10h] [ebp+4h]
  char evictionFailed; // [esp+14h] [ebp+8h]

  evictionFailed = 0;
  plista = 6;
  do
  {
    pNext = (Scaleform::Render::MeshCacheListSet::ListSlot *)plist->Root.pNext;
    while ( pNext != plist )
    {
      if ( (Scaleform::Render::MeshCacheItem *)pNext[4].Size == count || pNext[5].Root.pPrev == count )
      {
        if ( !(*(int (__thiscall **)(int, Scaleform::Render::MeshCacheListSet::ListSlot *, _DWORD, _DWORD))(*(_DWORD *)a2 + 32))(
                a2,
                pNext,
                0,
                0) )
        {
          Size = pNext[4].Size;
          evictionFailed = 1;
          if ( (Scaleform::Render::MeshCacheItem *)Size == count )
          {
            Scaleform::AllocAddr::Free(
              (Scaleform::AllocAddr *)(a2 + 304),
              ((unsigned int)pNext[5].Root.pNext >> 4) | (*(_DWORD *)(Size + 28) << 24),
              (pNext[5].Size + 15) >> 4);
            pNext[4].Size = 0;
          }
          pPrev = pNext[5].Root.pPrev;
          if ( pPrev == count )
          {
            Scaleform::AllocAddr::Free(
              (Scaleform::AllocAddr *)(a2 + 340),
              ((unsigned int)pNext[6].Root.pPrev >> 4) | (pPrev->HashKey << 24),
              ((unsigned int)&pNext[6].Root.pNext->ListType + 3) >> 4);
            pNext[5].Root.pPrev = 0;
          }
        }
        pNext = (Scaleform::Render::MeshCacheListSet::ListSlot *)plist->Root.pNext;
      }
      else
      {
        pNext = (Scaleform::Render::MeshCacheListSet::ListSlot *)pNext->Root.pNext;
      }
    }
    ++plist;
    --plista;
  }
  while ( plista );
  return evictionFailed == 0;
}

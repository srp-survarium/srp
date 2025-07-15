BOOL __userpurge Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer@<eax>(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::MeshCacheItem *plist,
        Scaleform::Render::D3D1x::MeshBuffer *count,
        Scaleform::Render::D3D1x::MeshBuffer *pbuffer)
{
  Scaleform::Render::MeshCacheItem *i; // esi
  Scaleform::Render::D3D1x::MeshBuffer *pPrev; // eax
  Scaleform::Render::D3D1x::MeshBuffer *pNext; // eax
  char v10; // [esp+Bh] [ebp-1h]
  int v11; // [esp+14h] [ebp+8h]

  v10 = 0;
  v11 = 6;
  do
  {
LABEL_10:
    for ( i = plist->pNext; i != plist; i = i->pNext )
    {
      if ( (Scaleform::Render::D3D1x::MeshBuffer *)i[1].pPrev == count
        || (Scaleform::Render::D3D1x::MeshBuffer *)i[1].pNext == count )
      {
        if ( !(*(int (__thiscall **)(int, Scaleform::Render::MeshCacheItem *, _DWORD, _DWORD))(*(_DWORD *)a2 + 32))(
                a2,
                i,
                0,
                0) )
        {
          pPrev = (Scaleform::Render::D3D1x::MeshBuffer *)i[1].pPrev;
          v10 = 1;
          if ( pPrev == count )
          {
            Scaleform::Render::D3D1x::MeshBufferSet::Free(
              pPrev,
              (unsigned int)i[1].pCacheList,
              (Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 296),
              i[1].ListType);
            i[1].pPrev = 0;
          }
          pNext = (Scaleform::Render::D3D1x::MeshBuffer *)i[1].pNext;
          if ( pNext == count )
          {
            Scaleform::Render::D3D1x::MeshBufferSet::Free(
              pNext,
              i[1].Type,
              (Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 332),
              (unsigned int)i[1].PrimitiveBatches.Root.pPrev);
            i[1].pNext = 0;
          }
        }
        goto LABEL_10;
      }
    }
    plist = (Scaleform::Render::MeshCacheItem *)((char *)plist + 12);
    --v11;
  }
  while ( v11 );
  return v10 == 0;
}

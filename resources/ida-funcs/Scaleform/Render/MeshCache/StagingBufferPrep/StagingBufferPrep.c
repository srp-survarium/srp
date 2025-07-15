void __thiscall Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
        Scaleform::Render::MeshCache::StagingBufferPrep *this,
        Scaleform::Render::MeshCache *cache,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        const Scaleform::Render::VertexFormat *format,
        Scaleform::Render::MeshCache::MeshResult canCopyData,
        Scaleform::Render::MeshCacheItem *skipBatch)
{
  unsigned int Size; // edi
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // edx
  unsigned int v11; // ebp
  int v12; // edi
  int v13; // eax
  Scaleform::Render::Mesh *v14; // edi
  int v15; // [esp+0h] [ebp-10h]
  int v16; // [esp+4h] [ebp-Ch]
  char v17; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+18h] [ebp+8h]

  this->pCache = cache;
  this->MC = mc;
  Size = mc->Meshes.Size;
  v8 = 0;
  for ( i = Size; v8 < Size; ++v8 )
  {
    v9 = *(int *)((char *)this->MC->Meshes.pData + v8 * this->MC->Meshes.StrideSize);
    v10 = *(_DWORD *)(v9 + 20);
    if ( v10 )
    {
      if ( !*(_DWORD *)(v9 + 32) )
        cache->StagingBuffer.TotalPinnedSize += v10;
      ++*(_DWORD *)(v9 + 32);
      this->PinnedFlagArray[v8] = 1;
    }
    else
    {
      this->PinnedFlagArray[v8] = 0;
    }
  }
  v11 = 0;
  if ( LOBYTE(canCopyData.Value) )
  {
    if ( Size )
    {
      do
      {
        v12 = *(int *)((char *)this->MC->Meshes.pData + v11 * this->MC->Meshes.StrideSize);
        if ( !this->PinnedFlagArray[v11] )
        {
          v13 = *(_DWORD *)(v12 + 112);
          if ( !v13 || v13 == 1 && *(Scaleform::Render::MeshCacheItem **)(v12 + 116) == skipBatch )
          {
            if ( !*(_DWORD *)(v12 + 20) )
              Scaleform::Render::MeshCache::GenerateMesh(
                this->pCache,
                &canCopyData,
                (Scaleform::Render::Mesh *)v12,
                format,
                0,
                0,
                0,
                v15,
                v16,
                v17);
            if ( !*(_DWORD *)(v12 + 32) )
              cache->StagingBuffer.TotalPinnedSize += *(_DWORD *)(v12 + 20);
            ++*(_DWORD *)(v12 + 32);
          }
        }
        ++v11;
      }
      while ( v11 < i );
    }
  }
  else if ( Size )
  {
    do
    {
      if ( !this->PinnedFlagArray[v11] )
      {
        v14 = *(Scaleform::Render::Mesh **)((char *)this->MC->Meshes.pData + v11 * this->MC->Meshes.StrideSize);
        if ( !v14->StagingBufferSize )
          Scaleform::Render::MeshCache::GenerateMesh(this->pCache, &canCopyData, v14, format, 0, 0, 0, v15, v16, v17);
        if ( !v14->PinCount )
          cache->StagingBuffer.TotalPinnedSize += v14->StagingBufferSize;
        ++v14->PinCount;
        Size = i;
      }
      ++v11;
    }
    while ( v11 < Size );
  }
}

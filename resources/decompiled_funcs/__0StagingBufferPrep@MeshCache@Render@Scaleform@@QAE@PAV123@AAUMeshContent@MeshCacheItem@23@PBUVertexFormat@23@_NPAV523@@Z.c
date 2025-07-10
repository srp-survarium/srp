void __thiscall Scaleform::Render::MeshCache::StagingBufferPrep::StagingBufferPrep(
        Scaleform::Render::MeshCache::StagingBufferPrep *this,
        Scaleform::Render::MeshCache *cache,
        Scaleform::Render::MeshCacheItem::MeshContent *mc,
        const Scaleform::Render::VertexFormat *format,
        bool canCopyData,
        Scaleform::Render::MeshCacheItem *skipBatch)
{
  unsigned int Size; // esi
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // edx
  unsigned int v11; // ebp
  int v12; // esi
  int v13; // eax
  Scaleform::Render::MeshCache *pCache; // edx
  int v15; // ecx
  _DWORD *v16; // esi
  Scaleform::Render::MeshCache *v17; // ecx
  int v18; // ecx
  int v19; // [esp-4h] [ebp-40h]
  int v20; // [esp-4h] [ebp-40h]
  void **v21; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::Render::MeshCache *v22; // [esp+14h] [ebp-28h]
  char v23; // [esp+18h] [ebp-24h]
  _DWORD *v24; // [esp+1Ch] [ebp-20h]
  const Scaleform::Render::VertexFormat *v25; // [esp+20h] [ebp-1Ch]
  int v26; // [esp+24h] [ebp-18h]
  int v27; // [esp+28h] [ebp-14h]
  int v28; // [esp+2Ch] [ebp-10h]
  int v29; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  unsigned int meshCount; // [esp+44h] [ebp+8h]

  this->pCache = cache;
  this->MC = mc;
  Size = mc->Meshes.Size;
  v8 = 0;
  for ( meshCount = Size; v8 < Size; ++v8 )
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
  if ( canCopyData )
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
            {
              pCache = this->pCache;
              v15 = *(_DWORD *)(v12 + 48);
              v25 = format;
              v19 = *(_DWORD *)(v12 + 104);
              v22 = pCache;
              v21 = &Scaleform::Render::MeshVertexOutput::`vftable';
              v23 = 0;
              v24 = (_DWORD *)v12;
              v26 = 0;
              v27 = 0;
              v28 = 6;
              v29 = 0;
              v30 = 0;
              (*(void (__thiscall **)(int, int, void ***, int))(*(_DWORD *)v15 + 12))(v15, v12, &v21, v19);
            }
            if ( !*(_DWORD *)(v12 + 32) )
              cache->StagingBuffer.TotalPinnedSize += *(_DWORD *)(v12 + 20);
            ++*(_DWORD *)(v12 + 32);
          }
        }
        ++v11;
      }
      while ( v11 < meshCount );
    }
  }
  else if ( Size )
  {
    do
    {
      if ( !this->PinnedFlagArray[v11] )
      {
        v16 = *(Scaleform::Render::MeshBase **)((char *)this->MC->Meshes.pData + v11 * this->MC->Meshes.StrideSize);
        if ( !v16[5] )
        {
          v17 = this->pCache;
          v25 = format;
          v20 = v16[26];
          v22 = v17;
          v18 = v16[12];
          v21 = &Scaleform::Render::MeshVertexOutput::`vftable';
          v23 = 0;
          v24 = v16;
          v26 = 0;
          v27 = 0;
          v28 = 6;
          v29 = 0;
          v30 = 0;
          (*(void (__thiscall **)(int, _DWORD *, void ***, int))(*(_DWORD *)v18 + 12))(v18, v16, &v21, v20);
        }
        if ( !v16[8] )
          cache->StagingBuffer.TotalPinnedSize += v16[5];
        ++v16[8];
        Size = meshCount;
      }
      ++v11;
    }
    while ( v11 < Size );
  }
}

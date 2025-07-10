Scaleform::Render::MeshCache::AllocResult __thiscall Scaleform::Render::D3D1x::MeshCache::AllocCacheItem(
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshCacheItem **pdata,
        unsigned __int8 **pvertexDataStart,
        unsigned __int16 **pindexDataStart,
        Scaleform::Render::MeshCacheItem::MeshType meshType,
        Scaleform::Render::MeshCacheItem::MeshBaseContent *mc,
        unsigned int vertexBufferSize,
        unsigned int vertexCount,
        unsigned int indexCount,
        bool waitForCache,
        const Scaleform::Render::VertexFormat *__formal)
{
  unsigned __int8 *v13; // ebp
  char v14; // al
  Scaleform::Render::D3D1x::VertexBuffer *v15; // esi
  Scaleform::Render::D3D1x::MeshCacheItem *v16; // eax
  unsigned int v17; // eax
  Scaleform::Render::D3D1x::MeshBuffer *pvb; // [esp+8h] [ebp-18h] BYREF
  unsigned int vbOffset; // [esp+Ch] [ebp-14h] BYREF
  unsigned int ibOffset; // [esp+10h] [ebp-10h] BYREF
  unsigned __int8 *pidata; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::Render::MeshCache::AllocResult failType; // [esp+18h] [ebp-8h]
  unsigned int indexAllocSize; // [esp+1Ch] [ebp-4h]
  unsigned __int8 *pvdata; // [esp+44h] [ebp+24h]

  if ( !this->AreBuffersLocked(this) && !this->LockBuffers(this) )
    return 4;
  v13 = 0;
  vbOffset = 0;
  ibOffset = 0;
  pvb = 0;
  pidata = 0;
  failType = Alloc_Fail;
  if ( Scaleform::Render::D3D1x::MeshCache::allocBuffer(
         (Scaleform::Render::D3D1x::MeshCache *)&this->VertexBuffers,
         (int)this,
         &vbOffset,
         &pvb,
         &this->VertexBuffers,
         vertexBufferSize,
         waitForCache) )
  {
    indexAllocSize = 2 * indexCount;
    v14 = Scaleform::Render::D3D1x::MeshCache::allocBuffer(
            (Scaleform::Render::D3D1x::MeshCache *)&this->IndexBuffers,
            (int)this,
            &ibOffset,
            (Scaleform::Render::D3D1x::MeshBuffer **)&pidata,
            &this->IndexBuffers,
            2 * indexCount,
            waitForCache);
    v15 = (Scaleform::Render::D3D1x::VertexBuffer *)pvb;
    if ( !v14 )
    {
      v13 = pidata;
      goto handle_alloc_fail;
    }
    if ( !pvb->pData )
    {
      if ( !pvb->DoLock(pvb, this->pDeviceContext.pObject) )
      {
        pvdata = 0;
        goto LABEL_11;
      }
      v15->pNextLock = this->LockedBuffers.pFirst;
      this->LockedBuffers.pFirst = v15;
    }
    pvdata = (unsigned __int8 *)v15->pData;
LABEL_11:
    v13 = pidata;
    if ( !*((_DWORD *)pidata + 6) )
    {
      if ( !(*(unsigned __int8 (__thiscall **)(unsigned __int8 *, ID3D11DeviceContext *))(*(_DWORD *)pidata + 8))(
              pidata,
              this->pDeviceContext.pObject) )
      {
        pidata = 0;
        goto LABEL_16;
      }
      *((_DWORD *)v13 + 8) = this->LockedBuffers.pFirst;
      this->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)v13;
    }
    pidata = (unsigned __int8 *)*((_DWORD *)v13 + 6);
LABEL_16:
    if ( !pvdata || !pidata )
      goto handle_alloc_fail;
    v16 = Scaleform::Render::D3D1x::MeshCacheItem::Create(
            vertexBufferSize,
            vertexCount,
            indexAllocSize,
            meshType,
            &this->CacheList,
            mc,
            v15,
            (Scaleform::Render::D3D1x::IndexBuffer *)v13,
            vbOffset,
            ibOffset,
            indexCount);
    *pdata = v16;
    if ( v16 )
    {
      v17 = ibOffset;
      *pvertexDataStart = &pvdata[vbOffset];
      *pindexDataStart = (unsigned __int16 *)&pidata[v17];
      return 3;
    }
    failType = Alloc_StateError;
  }
  v15 = (Scaleform::Render::D3D1x::VertexBuffer *)pvb;
handle_alloc_fail:
  if ( v15 )
    Scaleform::AllocAddr::Free(
      &this->VertexBuffers.Allocator,
      (vbOffset >> 4) | (v15->Index << 24),
      (vertexBufferSize + 15) >> 4);
  if ( v13 )
    Scaleform::AllocAddr::Free(
      &this->IndexBuffers.Allocator,
      (ibOffset >> 4) | (*((_DWORD *)v13 + 7) << 24),
      (2 * indexCount + 15) >> 4);
  return failType;
}

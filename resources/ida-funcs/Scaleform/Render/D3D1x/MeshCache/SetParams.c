char __thiscall Scaleform::Render::D3D1x::MeshCache::SetParams(
        Scaleform::Render::D3D1x::MeshCache *this,
        const Scaleform::Render::MeshCacheParams *argParams)
{
  Scaleform::Render::D3D1x::MeshCache *v3; // esi
  Scaleform::Render::D3D1x::MeshCache *v4; // ecx
  unsigned int MemGranularity; // ebx
  Scaleform::Render::RQCacheInterface *pRQCaches; // edi
  Scaleform::Render::MeshBuffer::AllocType v8; // [esp+0h] [ebp-38h]
  Scaleform::Render::MeshBuffer::AllocType v9; // [esp+0h] [ebp-38h]
  unsigned int v10; // [esp+4h] [ebp-34h]
  unsigned int v11; // [esp+4h] [ebp-34h]
  Scaleform::Render::MeshCacheParams p; // [esp+Ch] [ebp-2Ch] BYREF

  Scaleform::Render::MeshCacheParams::MeshCacheParams(&p, argParams);
  v3 = (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 4);
  Scaleform::Render::D3D1x::MeshCache::adjustMeshCacheParams(
    &p,
    (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 4));
  if ( this->Thrashing )
  {
    Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
    if ( this->Params.LRUTailSize != p.StagingBufferSize
      && !Scaleform::Render::MeshStagingBuffer::Initialize(
            (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
            (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::__vftable,
            p.StagingBufferSize) )
    {
      Scaleform::Render::MeshStagingBuffer::Initialize(
        (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
        (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::__vftable,
        this->Params.LRUTailSize);
      return 0;
    }
    MemGranularity = p.MemGranularity;
    if ( this->pRQCaches != (Scaleform::Render::RQCacheInterface *)p.MemReserve
      || this->Params.MemLimit != p.MemGranularity )
    {
      Scaleform::Render::D3D1x::MeshCache::destroyBuffers(v4, (int)v3, AT_None);
      if ( p.MemReserve
        && !Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
              p.MemReserve,
              (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 4),
              v8,
              v10) )
      {
        pRQCaches = this->pRQCaches;
        if ( pRQCaches )
          Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers((unsigned int)pRQCaches, v3, v9, v11);
        return 0;
      }
      this->VertexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)(16 * (5 * (MemGranularity >> 4) / 9));
      this->IndexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)((MemGranularity & 0xFFFFFFF0)
                                                                              - 16 * (5 * (MemGranularity >> 4) / 9));
    }
  }
  qmemcpy(&this->pRQCaches, &p, 0x2Cu);
  return 1;
}

char __thiscall Scaleform::Render::D3D1x::MeshCache::SetParams(
        Scaleform::Render::D3D1x::MeshCache *this,
        const Scaleform::Render::MeshCacheParams *argParams)
{
  unsigned int MemLimit; // edx
  unsigned int MemGranularity; // ecx
  unsigned int LRUTailSize; // edx
  unsigned int StagingBufferSize; // ecx
  unsigned int VBLockEvictSizeLimit; // edx
  unsigned int MaxBatchInstances; // ecx
  unsigned int InstancingThreshold; // edx
  unsigned int NoBatchVerticesSizeThreshold; // ecx
  unsigned int MaxVerticesSizeInBatch; // edx
  Scaleform::Render::D3D1x::MeshCache *v12; // ecx
  unsigned int MemReserve; // edi
  unsigned int v15; // ebp
  Scaleform::Render::D3D1x::MeshCache *v16; // ecx
  Scaleform::Ptr<ID3D11Buffer> *p_pMaskEraseBatchVertexBuffer; // edi
  Scaleform::Render::D3D1x::MeshCache *v18; // ecx
  Scaleform::Render::RQCacheInterface *pRQCaches; // ebx
  unsigned int v20; // ecx
  unsigned int MaxIndicesInBatch; // edx
  unsigned int v22; // [esp-4h] [ebp-40h]
  Scaleform::Render::MeshBuffer::AllocType v23; // [esp+0h] [ebp-3Ch]
  Scaleform::Render::MeshBuffer::AllocType v24; // [esp+0h] [ebp-3Ch]
  unsigned int v25; // [esp+4h] [ebp-38h]
  unsigned int v26; // [esp+4h] [ebp-38h]
  Scaleform::Render::MeshCacheParams params; // [esp+10h] [ebp-2Ch] BYREF

  MemLimit = argParams->MemLimit;
  params.MemReserve = argParams->MemReserve;
  MemGranularity = argParams->MemGranularity;
  params.MemLimit = MemLimit;
  LRUTailSize = argParams->LRUTailSize;
  params.MemGranularity = MemGranularity;
  StagingBufferSize = argParams->StagingBufferSize;
  params.LRUTailSize = LRUTailSize;
  VBLockEvictSizeLimit = argParams->VBLockEvictSizeLimit;
  params.StagingBufferSize = StagingBufferSize;
  MaxBatchInstances = argParams->MaxBatchInstances;
  params.VBLockEvictSizeLimit = VBLockEvictSizeLimit;
  InstancingThreshold = argParams->InstancingThreshold;
  params.MaxBatchInstances = MaxBatchInstances;
  NoBatchVerticesSizeThreshold = argParams->NoBatchVerticesSizeThreshold;
  params.InstancingThreshold = InstancingThreshold;
  MaxVerticesSizeInBatch = argParams->MaxVerticesSizeInBatch;
  params.MaxIndicesInBatch = argParams->MaxIndicesInBatch;
  params.NoBatchVerticesSizeThreshold = NoBatchVerticesSizeThreshold;
  params.MaxVerticesSizeInBatch = MaxVerticesSizeInBatch;
  Scaleform::Render::D3D1x::MeshCache::adjustMeshCacheParams(
    &params,
    (Scaleform::Render::D3D1x::MeshCache *)((char *)this - 4));
  if ( !this->BatchCacheItemHash.pTable )
    goto LABEL_13;
  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
  if ( this->Params.LRUTailSize != params.StagingBufferSize
    && !Scaleform::Render::MeshStagingBuffer::Initialize(
          (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
          (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::__vftable,
          params.StagingBufferSize) )
  {
    Scaleform::Render::MeshStagingBuffer::Initialize(
      (Scaleform::Render::MeshStagingBuffer *)&this->Params.MaxIndicesInBatch,
      (Scaleform::MemoryHeap *)this->Scaleform::Render::MeshCache::Scaleform::Render::MeshCacheConfig::__vftable,
      this->Params.LRUTailSize);
    return 0;
  }
  MemReserve = params.MemReserve;
  v15 = params.MemGranularity;
  if ( this->pRQCaches == (Scaleform::Render::RQCacheInterface *)params.MemReserve
    && this->Params.MemLimit == params.MemGranularity )
  {
    goto LABEL_13;
  }
  Scaleform::Render::D3D1x::MeshCache::destroyBuffers(v12, (int)&this[-1].pMaskEraseBatchVertexBuffer, AT_None);
  if ( !MemReserve
    || (v22 = MemReserve,
        p_pMaskEraseBatchVertexBuffer = &this[-1].pMaskEraseBatchVertexBuffer,
        Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
          v16,
          (int)&this[-1].pMaskEraseBatchVertexBuffer,
          v22,
          v23,
          v25)) )
  {
    v20 = 5 * (v15 >> 4);
    this->VertexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)(16 * (v20 / 9));
    this->IndexBuffers.Allocator.AddrTree.Root = (Scaleform::AllocAddrNode *)((v15 & 0xFFFFFFF0) - 16 * (v20 / 9));
LABEL_13:
    MaxIndicesInBatch = params.MaxIndicesInBatch;
    *(_QWORD *)&this->pRQCaches = *(_QWORD *)&params.MemReserve;
    *(_QWORD *)&this->Params.MemLimit = *(_QWORD *)&params.MemGranularity;
    *(_QWORD *)&this->Params.LRUTailSize = *(_QWORD *)&params.StagingBufferSize;
    *(_QWORD *)&this->Params.VBLockEvictSizeLimit = *(_QWORD *)&params.MaxBatchInstances;
    *(_QWORD *)&this->Params.InstancingThreshold = *(_QWORD *)&params.NoBatchVerticesSizeThreshold;
    this->Params.MaxVerticesSizeInBatch = MaxIndicesInBatch;
    return 1;
  }
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
    Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers(
      v18,
      (int)p_pMaskEraseBatchVertexBuffer,
      (unsigned int)pRQCaches,
      v24,
      v26);
  return 0;
}

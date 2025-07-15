void __thiscall Scaleform::Render::MeshCache::MeshCache(
        Scaleform::Render::MeshCache *this,
        Scaleform::MemoryHeap *pheap,
        const Scaleform::Render::MeshCacheParams *params)
{
  Scaleform::List<Scaleform::Render::MeshStagingNode,Scaleform::Render::MeshStagingNode> *p_MeshList; // ecx

  this->Scaleform::Render::MeshCacheConfig::__vftable = (Scaleform::Render::MeshCacheConfig_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
  this->pHeap = pheap;
  this->Scaleform::Render::CacheBase::__vftable = (Scaleform::Render::MeshCache_vtbl *)&Scaleform::Render::MeshCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->Scaleform::Render::MeshCacheConfig::__vftable = (Scaleform::Render::MeshCacheConfig_vtbl *)&Scaleform::Render::MeshCache::`vftable'{for `Scaleform::Render::MeshCacheConfig'};
  this->pRQCaches = 0;
  this->Params = *params;
  p_MeshList = &this->StagingBuffer.MeshList;
  this->StagingBuffer.pBuffer = 0;
  this->StagingBuffer.BufferSize = 0;
  this->StagingBuffer.TotalPinnedSize = 0;
  this->StagingBuffer.PinSizeLimit = 0;
  if ( this == (Scaleform::Render::MeshCache *)-76 )
  {
    p_MeshList->Root.pPrev = 0;
    p_MeshList->Root.pNext = 0;
    MEMORY[8] = 0;
    MEMORY[0xC] = 0;
  }
  else
  {
    this->StagingBuffer.MeshList.Root.pPrev = (Scaleform::Render::MeshStagingNode *)&this->StagingBuffer.PinSizeLimit;
    this->StagingBuffer.MeshList.Root.pNext = (Scaleform::Render::MeshStagingNode *)&this->StagingBuffer.PinSizeLimit;
    this->BatchCacheItemHash.pTable = 0;
    this->Thrashing = 0;
  }
}

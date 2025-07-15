void __usercall Scaleform::Render::D3D1x::MeshCache::EndFrame(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        Scaleform::Render::D3D1x::MeshBuffer *a2@<edi>)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  Scaleform::Render::D3D1x::MeshCache *v5; // ecx
  unsigned int Size; // ecx
  signed int v7; // eax
  Scaleform::List<Scaleform::Render::MeshBuffer,Scaleform::Render::MeshBuffer> *p_ChunkBuffers; // ecx
  Scaleform::Render::MeshBuffer *v9; // edx
  Scaleform::Render::D3D1x::MeshBuffer *pPrev; // esi
  bool v11; // zf
  Scaleform::Render::D3D1x::MeshCache *v12; // ecx
  Scaleform::Render::D3D1x::MeshBufferSet *p_VertexBuffers; // eax
  Scaleform::Render::D3D1x::MeshBuffer *v14; // [esp-4h] [ebp-28h]
  Scaleform::AmpFunctionTimer v15; // [esp+8h] [ebp-1Ch] BYREF
  signed int v16; // [esp+18h] [ebp-Ch]
  BOOL v17; // [esp+1Ch] [ebp-8h]
  Scaleform::Render::D3D1x::MeshBufferSet *v18; // [esp+20h] [ebp-4h]

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v15,
    v4,
    "Scaleform::Render::D3D1x::MeshCache::EndFrame",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  this->RSync.EndFrame(&this->RSync);
  Scaleform::Render::MeshCacheListSet::EndFrame(&this->CacheList);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->IndexBuffers.Allocator);
  Scaleform::Render::MeshCacheListSet::EvictPendingFree(&this->CacheList, &this->VertexBuffers.Allocator);
  Scaleform::Render::D3D1x::MeshCache::destroyPendingBuffers(v5, (int)this);
  Size = this->CacheList.Slots[4].Size;
  if ( Size >= this->Params.LRUTailSize )
    Size = this->Params.LRUTailSize;
  v7 = this->VertexBuffers.TotalSize
     + this->IndexBuffers.TotalSize
     - ((this->CacheList.Slots[3].Size + Size) >> 2)
     - (this->CacheList.Slots[3].Size
      + Size);
  if ( v7 > (signed int)this->Params.MemGranularity )
  {
    v14 = a2;
    while ( 1 )
    {
      p_ChunkBuffers = &this->ChunkBuffers;
      v9 = this == (Scaleform::Render::D3D1x::MeshCache *)-380
         ? 0
         : (Scaleform::Render::MeshBuffer *)&this->LockedBuffers;
      if ( this->ChunkBuffers.Root.pNext == v9 || v7 <= (signed int)this->Params.MemGranularity )
        break;
      pPrev = (Scaleform::Render::D3D1x::MeshBuffer *)p_ChunkBuffers->Root.pPrev;
      p_ChunkBuffers->Root.pPrev->pPrev->pNext = p_ChunkBuffers->Root.pPrev->pNext;
      pPrev->pNext->Scaleform::Render::MeshBuffer::pPrev = pPrev->pPrev;
      v16 = v7 - pPrev->Size;
      v11 = pPrev->GetBufferType(pPrev) == Buffer_Vertex;
      p_VertexBuffers = &this->VertexBuffers;
      if ( !v11 )
        p_VertexBuffers = &this->IndexBuffers;
      v18 = p_VertexBuffers;
      LOBYTE(v17) = Scaleform::Render::D3D1x::MeshCache::evictMeshesInBuffer(
                      v12,
                      (int)this,
                      (Scaleform::Render::MeshCacheItem *)this->CacheList.Slots,
                      pPrev,
                      v14);
      Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffer(v18, pPrev, v17);
      if ( !v17 )
      {
        pPrev->pPrev = this->PendingDestructionBuffers.Root.pPrev;
        pPrev->pNext = (Scaleform::Render::MeshBuffer *)&this->ChunkBuffers.Root.4;
        this->PendingDestructionBuffers.Root.pPrev->pNext = pPrev;
        this->PendingDestructionBuffers.Root.pPrev = pPrev;
      }
      v7 = v16;
    }
  }
  Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v15);
}

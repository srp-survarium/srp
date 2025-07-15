void __thiscall Scaleform::Render::D3D1x::MeshCache::ClearCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v2; // ecx
  Scaleform::Render::D3D1x::MeshBufferSet *v3; // ecx

  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)&this->pShaderManager);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v2, (int)(&this->RSync.pDeviceContext + 1), AT_Chunk);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v3, (int)&this->VertexBuffers.TotalSize, AT_Chunk);
  if ( this == (Scaleform::Render::D3D1x::MeshCache *)-368 )
  {
    MEMORY[4] = 0;
    MEMORY[0] = 0;
  }
  else
  {
    this->ChunkBuffers.Root.pPrev = (Scaleform::Render::MeshBuffer *)&this->VBSizeEvictedInLock;
    this->LockedBuffers.pFirst = (Scaleform::Render::D3D1x::MeshBuffer *)&this->VBSizeEvictedInLock;
  }
}

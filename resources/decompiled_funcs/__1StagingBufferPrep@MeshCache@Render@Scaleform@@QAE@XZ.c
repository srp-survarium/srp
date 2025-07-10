void __thiscall Scaleform::Render::MeshCache::StagingBufferPrep::~StagingBufferPrep(
        Scaleform::Render::MeshCache::StagingBufferPrep *this)
{
  Scaleform::Render::MeshCacheItem::MeshContent *MC; // eax
  unsigned int v2; // edx
  Scaleform::Render::MeshStagingBuffer *i; // esi
  int v4; // eax

  MC = this->MC;
  v2 = 0;
  for ( i = &this->pCache->StagingBuffer; v2 < MC->Meshes.Size; ++v2 )
  {
    if ( (*(Scaleform::Render::MeshBase **)((char *)MC->Meshes.pData + v2 * MC->Meshes.StrideSize))->StagingBufferSize )
    {
      v4 = *(int *)((char *)MC->Meshes.pData + v2 * MC->Meshes.StrideSize);
      if ( (*(_DWORD *)(v4 + 32))-- == 1 )
        i->TotalPinnedSize -= *(_DWORD *)(v4 + 20);
    }
    MC = this->MC;
  }
}

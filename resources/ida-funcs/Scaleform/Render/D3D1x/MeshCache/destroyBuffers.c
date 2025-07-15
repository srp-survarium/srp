void __userpurge Scaleform::Render::D3D1x::MeshCache::destroyBuffers(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::MeshBuffer::AllocType at)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v3; // ecx
  Scaleform::Render::D3D1x::MeshBufferSet *v4; // ecx

  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)(a2 + 100));
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v3, a2 + 288, at);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v4, a2 + 324, at);
  if ( a2 == -372 )
  {
    MEMORY[4] = 0;
    MEMORY[0] = 0;
  }
  else
  {
    *(_DWORD *)(a2 + 376) = a2 + 368;
    *(_DWORD *)(a2 + 372) = a2 + 368;
  }
}

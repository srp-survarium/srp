void __userpurge Scaleform::Render::D3D1x::MeshCache::destroyBuffers(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<esi>,
        Scaleform::Render::MeshBuffer::AllocType at)
{
  Scaleform::Render::D3D1x::MeshBufferSet *v3; // ecx
  Scaleform::Render::D3D1x::MeshBufferSet *v4; // ecx
  int v5; // ecx

  Scaleform::Render::MeshCacheListSet::EvictAll((Scaleform::Render::MeshCacheListSet *)(a2 + 104));
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v3, (Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 296), at);
  Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(v4, (Scaleform::Render::D3D1x::MeshBufferSet *)(a2 + 332), at);
  if ( a2 == -380 )
    v5 = 0;
  else
    v5 = a2 + 376;
  *(_DWORD *)(a2 + 380) = v5;
  *(_DWORD *)(a2 + 384) = v5;
}

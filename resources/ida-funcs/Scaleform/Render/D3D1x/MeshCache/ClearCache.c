void __thiscall Scaleform::Render::D3D1x::MeshCache::ClearCache(Scaleform::Render::D3D1x::MeshCache *this)
{
  Scaleform::Render::D3D1x::MeshCache::destroyBuffers(this, (int)&this[-1].pMaskEraseBatchVertexBuffer, AT_Chunk);
}

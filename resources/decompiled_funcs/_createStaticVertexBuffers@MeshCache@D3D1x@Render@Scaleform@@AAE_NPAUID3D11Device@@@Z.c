bool __usercall Scaleform::Render::D3D1x::MeshCache::createStaticVertexBuffers@<al>(
        Scaleform::Render::D3D1x::MeshCache *this@<eax>,
        ID3D11Device *pdevice@<edi>)
{
  return Scaleform::Render::D3D1x::MeshCache::createMaskEraseBatchVertexBuffer(pdevice, this);
}

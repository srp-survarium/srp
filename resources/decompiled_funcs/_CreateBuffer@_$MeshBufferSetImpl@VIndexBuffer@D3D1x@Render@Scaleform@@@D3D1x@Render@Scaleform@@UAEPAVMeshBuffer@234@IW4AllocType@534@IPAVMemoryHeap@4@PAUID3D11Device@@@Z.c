Scaleform::Render::D3D1x::IndexBuffer *__thiscall Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer>::CreateBuffer(
        Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::IndexBuffer> *this,
        unsigned int size,
        Scaleform::Render::MeshBuffer::AllocType type,
        unsigned int arena,
        Scaleform::MemoryHeap *pheap,
        ID3D11Device *pdevice)
{
  return Scaleform::Render::D3D1x::MeshBufferImpl<ID3D11Buffer,Scaleform::Render::D3D1x::IndexBuffer>::Create(
           size,
           type,
           arena,
           pheap,
           pdevice,
           this);
}

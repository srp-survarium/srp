char __userpurge Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers@<al>(
        unsigned int size@<eax>,
        Scaleform::Render::D3D1x::MeshCache *this,
        Scaleform::Render::MeshBuffer::AllocType type,
        unsigned int arena)
{
  unsigned int v6; // esi
  Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *p_VertexBuffers; // [esp+Ch] [ebp-4h]
  Scaleform::Render::D3D1x::MeshBuffer *v9; // [esp+18h] [ebp+8h]

  p_VertexBuffers = &this->VertexBuffers;
  v6 = 16 * (5 * (size >> 4) / 9);
  v9 = (Scaleform::Render::D3D1x::MeshBuffer *)((int (__stdcall *)(unsigned int, int, _DWORD, Scaleform::MemoryHeap *, ID3D11Device *))this->VertexBuffers.CreateBuffer)(
                                                 v6,
                                                 1,
                                                 0,
                                                 this->pHeap,
                                                 this->pDevice.pObject);
  if ( !v9 )
    return 0;
  if ( !this->IndexBuffers.CreateBuffer(
          &this->IndexBuffers,
          (size & 0xFFFFFFF0) - 16 * (v6 >> 4),
          1,
          0,
          this->pHeap,
          this->pDevice.pObject) )
  {
    Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffer(p_VertexBuffers, v9, 1);
    return 0;
  }
  return 1;
}

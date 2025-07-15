Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *__thiscall Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>::`vector deleting destructor'(
        Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer> *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::D3D1x::MeshBufferSetImpl<Scaleform::Render::D3D1x::VertexBuffer>_vtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr(&this->Allocator);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Buffers.Data.Data);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

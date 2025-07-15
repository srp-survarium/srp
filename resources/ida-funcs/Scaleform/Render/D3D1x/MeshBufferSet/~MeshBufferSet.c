void __thiscall Scaleform::Render::D3D1x::MeshBufferSet::~MeshBufferSet(Scaleform::Render::D3D1x::MeshBufferSet *this)
{
  this->__vftable = (Scaleform::Render::D3D1x::MeshBufferSet_vtbl *)&Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  Scaleform::AllocAddr::~AllocAddr(&this->Allocator);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Buffers.Data.Data);
}

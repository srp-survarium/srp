void __thiscall Scaleform::Render::TextMeshProvider::~TextMeshProvider(Scaleform::Render::TextMeshProvider *this)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax

  this->__vftable = (Scaleform::Render::TextMeshProvider_vtbl *)&Scaleform::Render::TextMeshProvider::`vftable';
  Scaleform::Render::TextMeshProvider::Clear(this);
  pHandle = this->ClearBounds.pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
  Scaleform::ConstructorMov<Scaleform::Render::TextMeshLayer>::DestructArray(
    this->Layers.Data.Data,
    this->Layers.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Layers.Data.Data);
  Scaleform::ConstructorMov<Scaleform::Render::TextMeshEntry>::DestructArray(
    this->Entries.Data.Data,
    this->Entries.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Notifiers.Data.Data);
  this->__vftable = (Scaleform::Render::TextMeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
}

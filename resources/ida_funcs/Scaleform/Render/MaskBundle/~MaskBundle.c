void __thiscall Scaleform::Render::MaskBundle::~MaskBundle(Scaleform::Render::MaskBundle *this)
{
  Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
    this->Prim.MaskAreas.Data.Data,
    this->Prim.MaskAreas.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Prim.MaskAreas.Data.Data);
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(&this->Prim);
  this->__vftable = (Scaleform::Render::MaskBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

Scaleform::Render::MaskPrimitive *__thiscall Scaleform::Render::MaskPrimitive::`scalar deleting destructor'(
        Scaleform::Render::MaskPrimitive *this,
        char a2)
{
  Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
    this->MaskAreas.Data.Data,
    this->MaskAreas.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->MaskAreas.Data.Data);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

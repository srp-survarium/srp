void __thiscall Scaleform::Render::ComplexPrimitiveBundle::~ComplexPrimitiveBundle(
        Scaleform::Render::ComplexPrimitiveBundle *this)
{
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::ComplexPrimitiveBundle_vtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable'{for `Scaleform::Render::Bundle'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::ComplexPrimitiveBundle::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  Scaleform::ConstructorMov<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry>::DestructArray(
    this->Instances.Data.Data,
    this->Instances.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Instances.Data.Data);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::ComplexPrimitiveBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

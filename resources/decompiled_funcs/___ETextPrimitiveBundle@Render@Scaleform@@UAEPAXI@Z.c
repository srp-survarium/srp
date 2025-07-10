Scaleform::Render::TextPrimitiveBundle *__thiscall Scaleform::Render::TextPrimitiveBundle::`vector deleting destructor'(
        Scaleform::Render::TextPrimitiveBundle *this,
        char a2)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::TextPrimitiveBundle_vtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::Bundle'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  pObject = (Scaleform::RefCountVImpl *)this->pMaskPrimitive.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::~ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>(&this->Layers);
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::TextPrimitiveBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

void __thiscall Scaleform::Render::TextPrimitiveBundle::TextPrimitiveBundle(
        Scaleform::Render::TextPrimitiveBundle *this)
{
  this->RefCount = 1;
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::TextPrimitiveBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Scaleform::Render::Bundle::Scaleform::RefCountBaseNTS<Scaleform::Render::Bundle,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,67>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::Render::TextPrimitiveBundle_vtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::Bundle'};
  this->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::TextPrimitiveBundle::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->Layers.Size = 0;
  this->pMaskPrimitive.pObject = 0;
}

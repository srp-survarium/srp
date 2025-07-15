void __thiscall Scaleform::Render::MaskBundle::MaskBundle(
        Scaleform::Render::MaskBundle *this,
        Scaleform::Render::HAL *hal,
        Scaleform::Render::MaskPrimitive::MaskAreaType maskType)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MaskBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->__vftable = (Scaleform::Render::MaskBundle_vtbl *)&Scaleform::Render::MaskBundle::`vftable';
  this->Prim.__vftable = (Scaleform::Render::MaskPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Prim.RefCount = 1;
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Prim.pHAL = hal;
  this->Prim.__vftable = (Scaleform::Render::MaskPrimitive_vtbl *)&Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,68>'};
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->Prim.Type = maskType;
  this->Prim.MaskAreas.Data.Data = 0;
  this->Prim.MaskAreas.Data.Size = 0;
  this->Prim.MaskAreas.Data.Policy.Capacity = 0;
}

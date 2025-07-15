void __thiscall Scaleform::Render::UserDataBundle::UserDataBundle(
        Scaleform::Render::UserDataBundle *this,
        Scaleform::Render::HAL *hal,
        Scaleform::GFx::Resource *data)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::UserDataBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->__vftable = (Scaleform::Render::UserDataBundle_vtbl *)&Scaleform::Render::UserDataBundle::`vftable';
  this->Prim.__vftable = (Scaleform::Render::UserDataPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Prim.RefCount = 1;
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->Prim.__vftable = (Scaleform::Render::UserDataPrimitive_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,68>'};
  this->Prim.__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->Prim.pHAL = hal;
  if ( data )
    Scaleform::RefCountImpl::AddRef(data);
  this->Prim.pUserData.pObject = (Scaleform::Render::UserDataState::Data *)data;
}

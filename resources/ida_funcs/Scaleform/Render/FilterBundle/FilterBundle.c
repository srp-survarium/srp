void __thiscall Scaleform::Render::FilterBundle::FilterBundle(
        Scaleform::Render::FilterBundle *this,
        Scaleform::Render::HAL *hal,
        Scaleform::GFx::Resource *filters,
        bool maskPresent)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::FilterBundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  this->Entries.Data.Data = 0;
  this->Entries.Data.Size = 0;
  this->Entries.Data.Policy.Capacity = 0;
  this->NeedUpdate = 1;
  this->FrameId = 0;
  Scaleform::Render::Bundle::UpdateChain(this, 0);
  this->NeedUpdate = 1;
  this->__vftable = (Scaleform::Render::FilterBundle_vtbl *)&Scaleform::Render::FilterBundle::`vftable';
  Scaleform::Render::FilterPrimitive::FilterPrimitive(&this->Prim, hal, filters, maskPresent);
}

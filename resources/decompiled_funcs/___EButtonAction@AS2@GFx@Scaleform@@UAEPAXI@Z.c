Scaleform::GFx::AS2::ButtonAction *__thiscall Scaleform::GFx::AS2::ButtonAction::`vector deleting destructor'(
        Scaleform::GFx::AS2::ButtonAction *this,
        char a2)
{
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258,Scaleform::ArrayDefaultPolicy> *p_Actions; // edi

  p_Actions = &this->Actions;
  this->__vftable = (Scaleform::GFx::AS2::ButtonAction_vtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Actions.Data,
    &this->Actions,
    0);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)p_Actions);
  this->__vftable = (Scaleform::GFx::AS2::ButtonAction_vtbl *)&Scaleform::GFx::ButtonActionBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}

void __thiscall Scaleform::GFx::ButtonDef::AddButtonAction(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::GFx::Resource *act)
{
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *p_ButtonActions; // esi
  _DWORD *p_pObject; // esi

  if ( act )
    Scaleform::RefCountImpl::AddRef(act);
  Size = this->ButtonActions.Data.Size;
  p_ButtonActions = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *)&this->ButtonActions;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_ButtonActions,
    p_ButtonActions,
    Size + 1);
  p_pObject = &p_ButtonActions->Data[p_ButtonActions->Size - 1].pObject;
  if ( p_pObject )
  {
    if ( act )
      Scaleform::RefCountImpl::AddRef(act);
    *p_pObject = act;
  }
  if ( act )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)act);
}

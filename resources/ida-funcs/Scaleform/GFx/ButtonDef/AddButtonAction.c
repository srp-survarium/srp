void __thiscall Scaleform::GFx::ButtonDef::AddButtonAction(
        Scaleform::GFx::ButtonDef *this,
        Scaleform::GFx::Resource *act)
{
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *p_ButtonActions; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *v5; // esi

  if ( act )
    Scaleform::RefCountImpl::AddRef(act);
  Size = this->ButtonActions.Data.Size;
  p_ButtonActions = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData>,258>,Scaleform::ArrayDefaultPolicy> *)&this->ButtonActions;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    p_ButtonActions,
    p_ButtonActions,
    Size + 1);
  v5 = &p_ButtonActions->Data[p_ButtonActions->Size - 1];
  if ( v5 )
  {
    if ( act )
      Scaleform::RefCountImpl::AddRef(act);
    v5->pObject = (Scaleform::GFx::AS2::ActionBufferData *)act;
  }
  if ( act )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)act);
}

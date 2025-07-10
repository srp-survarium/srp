void __thiscall Scaleform::GFx::AS3::AvmButton::SetHitStateObject(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // ebx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> > *v4; // ecx
  Scaleform::RefCountNTSImpl **v5; // esi

  pDispObj = this->pDispObj;
  v4 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> > *)&pDispObj[2].Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>;
  if ( ch )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      v4,
      1u);
    v5 = (Scaleform::RefCountNTSImpl **)pDispObj[2].Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    ++ch->RefCount;
    if ( *v5 )
      Scaleform::RefCountNTSImpl::Release(*v5);
    *v5 = ch;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      v4,
      0);
  }
  if ( Scaleform::GFx::Button::GetButtonState((Scaleform::GFx::ButtonRecord::MouseState)pDispObj[2].pParent) == Hit )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(this, Hit);
}

void __thiscall Scaleform::GFx::InteractiveObject::OnFocus(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject::FocusEventType event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 4))(
           (char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject::FocusEventType, Scaleform::GFx::InteractiveObject *, unsigned int, Scaleform::GFx::FocusMovedType))(*(_DWORD *)v6 + 68))(
      v6,
      event,
      oldOrNewFocusCh,
      controllerIdx,
      fmt);
  }
}

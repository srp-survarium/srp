char __thiscall Scaleform::GFx::AS3::MovieRoot::NotifyOnFocusChange(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Stage *curFocused,
        Scaleform::GFx::InteractiveObject *toBeFocused,
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent_vtbl *controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  Scaleform::GFx::AS3::Stage *pObject; // eax
  int v7; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v8; // ecx

  pObject = curFocused;
  if ( (curFocused || (pObject = this->pStage.pObject) != 0)
    && (v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 4))((int)pObject + 4 * pObject->AvmObjOffset)) != 0 )
  {
    v8 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v7 - 28);
  }
  else
  {
    v8 = 0;
  }
  return Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(
           v8,
           (Scaleform::GFx::AS3::Instances::fl_events::Event *)toBeFocused,
           controllerIdx,
           fmt,
           pfocusKeyInfo);
}

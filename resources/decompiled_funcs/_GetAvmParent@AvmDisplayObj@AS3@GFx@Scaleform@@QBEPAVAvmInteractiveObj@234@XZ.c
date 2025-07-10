Scaleform::GFx::AS3::AvmInteractiveObj *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(
        Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v2; // eax

  pParent = this->pDispObj->pParent;
  if ( pParent
    && (v2 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pParent->AvmObjOffset)
                                        + 4))((int)pParent + 4 * pParent->AvmObjOffset)) != 0 )
  {
    return (Scaleform::GFx::AS3::AvmInteractiveObj *)(v2 - 28);
  }
  else
  {
    return 0;
  }
}

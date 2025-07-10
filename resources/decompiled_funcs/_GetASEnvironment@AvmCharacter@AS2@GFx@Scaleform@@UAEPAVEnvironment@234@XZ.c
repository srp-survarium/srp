Scaleform::GFx::AS2::Environment *__thiscall Scaleform::GFx::AS2::AvmCharacter::GetASEnvironment(
        Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v3; // ecx

  pParent = this->pDispObj->pParent;
  if ( !pParent )
    return 0;
  while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    pParent = pParent->pParent;
    if ( !pParent )
      return 0;
  }
  v3 = &pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
     + pParent->AvmObjOffset;
  return (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v3)->SetRotation)(v3);
}

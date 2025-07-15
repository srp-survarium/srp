void __thiscall Scaleform::GFx::AS2::AvmButton::AvmButton(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::AS2::Environment *v4; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v5; // ecx
  Scaleform::GFx::AS2::Object *ActualPrototype; // eax
  Scaleform::GFx::AS2::Object *v7; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pUserDataHolder = 0;
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmButton_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pDispObj = pbutton;
  this->EventHandlers.mHash.pTable = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(pbutton, this);
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmButtonBase_vtbl *)&Scaleform::GFx::AvmButtonBase::`vftable';
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmButton_vtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmButtonBase_vtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable';
  this->ASButtonObj.pObject = 0;
  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
        goto LABEL_4;
    }
    v5 = &pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + pParent->AvmObjOffset;
    v4 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v5)->SetRotation)(v5);
  }
  else
  {
LABEL_4:
    v4 = 0;
  }
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].RefCount,
                      v4,
                      ASBuiltin_Button);
  v7 = ActualPrototype;
  if ( ActualPrototype )
    ActualPrototype->RefCount = (ActualPrototype->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = v7;
}

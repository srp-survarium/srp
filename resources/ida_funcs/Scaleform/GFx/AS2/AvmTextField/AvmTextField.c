void __thiscall Scaleform::GFx::AS2::AvmTextField::AvmTextField(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // edi
  Scaleform::StringLH *p_VariableName; // ebx
  Scaleform::GFx::ASStringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::AS2::Environment *v8; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v9; // ecx
  Scaleform::GFx::AS2::Object *ActualPrototype; // eax
  Scaleform::GFx::AS2::Object *v11; // ebx
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax
  int v14; // eax
  Scaleform::GFx::AS2::Environment *v15; // eax
  int v16; // [esp+0h] [ebp-10h]
  int v17; // [esp+4h] [ebp-Ch]

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pUserDataHolder = 0;
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmTextField_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pDispObj = ptf;
  this->EventHandlers.mHash.pTable = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(ptf, this);
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmTextFieldBase_vtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable';
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmTextField_vtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v3->__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmTextFieldBase_vtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable';
  p_VariableName = &ptf->pDef.pObject->VariableName;
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(ptf);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 StringManager,
                 (char *)((p_VariableName->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(p_VariableName->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  this->VariableName.pNode = StringNode;
  ++StringNode->RefCount;
  this->VariableVal.T.Type = 0;
  this->ASTextFieldObj.pObject = 0;
  if ( this->VariableName.pNode->Size )
    ptf->Flags |= 0x8000u;
  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
        goto LABEL_6;
    }
    v9 = &pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + pParent->AvmObjOffset;
    v8 = (Scaleform::GFx::AS2::Environment *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v9)->SetRotation)(v9);
  }
  else
  {
LABEL_6:
    v8 = 0;
  }
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].RefCount,
                      v8,
                      ASBuiltin_TextField);
  v11 = ActualPrototype;
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
  this->pProto.pObject = v11;
  v14 = (*(int (__thiscall **)(char *))(*((_DWORD *)&ptf->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + ptf->AvmObjOffset)
                                      + 124))(
          (char *)&ptf->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + 4 * ptf->AvmObjOffset);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)v3,
    (int)this,
    (Scaleform::GFx::AS2::ASStringContext *)(v14 + 116),
    v3,
    v16,
    v17);
  v15 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*((_DWORD *)&ptf->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                            + ptf->AvmObjOffset)
                                                                          + 124))(
                                              (char *)&ptf->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + 4 * ptf->AvmObjOffset);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(v15, v3, v3);
}

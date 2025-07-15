bool __thiscall Scaleform::GFx::AS2::AvmCharacter::IsTabable(Scaleform::GFx::AS2::AvmCharacter *this)
{
  bool result; // al
  Scaleform::GFx::AS2::Object *pObject; // ebx
  Scaleform::GFx::AS2::AvmCharacter_vtbl *v4; // edx
  const Scaleform::GFx::AS2::Environment *v5; // ebp
  bool v6; // bl
  Scaleform::GFx::ASStringNode *v7; // eax
  bool v8; // bl
  Scaleform::GFx::InteractiveObject *pDispObj; // eax
  unsigned __int8 AvmObjOffset; // cl
  int v11; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+10h] [ebp-10h] BYREF

  result = this->pDispObj->GetVisible(this->pDispObj);
  if ( !result )
    return result;
  if ( (this->pDispObj->Flags & 0x60) != 0 )
    return (this->pDispObj->Flags & 0x60) == 96;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    v4 = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
    v13.T.Type = 0;
    v5 = v4->GetASEnvironment(this);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)v5->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        "tabEnabled",
                        0xAu,
                        0);
    ++ConstStringNode->RefCount;
    v6 = pObject->GetMemberRaw(
           &pObject->Scaleform::GFx::AS2::ObjectInterface,
           &v5->StringContext,
           (const Scaleform::GFx::ASString *)&ConstStringNode,
           &v13);
    v7 = ConstStringNode;
    --ConstStringNode->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( v6 && v13.T.Type && v13.T.Type != 10 )
    {
      v8 = Scaleform::GFx::AS2::Value::ToBool(&v13, (int)this, v5);
      if ( v13.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v13);
      return v8;
    }
    if ( v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
  }
  pDispObj = this->pDispObj;
  AvmObjOffset = pDispObj->AvmObjOffset;
  result = AvmObjOffset
        && (v11 = (*(int (__thiscall **)(int))(*((_DWORD *)&pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                               + AvmObjOffset)
                                             + 4))((int)pDispObj + 4 * AvmObjOffset),
            (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 52))(v11))
        || this->pDispObj->TabIndex > 0;
  return result;
}

void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx::setImageSubstitutions(
        Scaleform::GFx::AS3::Classes::fl_gfx::TextFieldEx *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *textField,
        const Scaleform::GFx::AS3::Value *substInfo)
{
  Scaleform::GFx::AS3::VM *pVM; // ebp
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::TextField *pData; // ebx
  const Scaleform::GFx::AS3::Value *v8; // esi
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Value::V1U v10; // edi
  Scaleform::GFx::AS3::Impl::SparseArray *v11; // ebp
  unsigned int v12; // esi
  const Scaleform::GFx::AS3::Value *v13; // edi
  int v14; // eax
  Scaleform::GFx::AS3::AvmTextField *v15; // ecx
  int v16; // eax
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::StringDataPtr v18; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::VM *vm[2]; // [esp+10h] [ebp-8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  vm[0] = pVM;
  if ( !textField )
  {
    v18.pStr = "TextFieldEx::setImageSubstitutions";
    v18.Size = 34;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)vm,
      eNullArgumentError,
      this->pTraits.pObject->pVM,
      v18);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    v6 = (Scaleform::GFx::ASStringNode *)vm[1];
    goto LABEL_3;
  }
  pData = (Scaleform::GFx::TextField *)textField[2].pData;
  v8 = substInfo;
  v9 = substInfo->Flags & 0x1F;
  if ( v9 - 12 <= 3 && !substInfo->value.VS._1.VInt || !v9 )
  {
    Scaleform::GFx::TextField::ClearIdImageDescAssoc(pData);
    Scaleform::GFx::TextField::ClearImageSubstitutor(pData);
    pData->pDocument.pObject->RTFlags |= 2u;
    Scaleform::GFx::TextField::SetDirtyFlag(pData);
    return;
  }
  if ( v9 - 12 > 3 )
  {
    Name = Scaleform::GFx::DisplayObject::GetName(pData, (Scaleform::GFx::ASString *)&textField);
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
      &pData->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "%s.setImageSubstitutions() failed: parameter should be either 'null', object or array",
      Name->pNode->pData);
    v6 = textField;
LABEL_3:
    if ( !--v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    return;
  }
  v10 = substInfo->value.VS._1;
  if ( Scaleform::GFx::AS3::VM::IsOfType(pVM, substInfo, pVM->TraitsArray.pObject) )
  {
    v11 = (Scaleform::GFx::AS3::Impl::SparseArray *)(v10.VInt + 32);
    v12 = 0;
    textField = *(Scaleform::GFx::ASStringNode **)(v10.VInt + 32);
    if ( textField )
    {
      do
      {
        v13 = Scaleform::GFx::AS3::Impl::SparseArray::At(v11, v12);
        if ( (v13->Flags & 0x1F) - 12 <= 3 )
        {
          v14 = (*(int (__thiscall **)(int))(*((_DWORD *)&pData->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + pData->AvmObjOffset)
                                           + 4))((int)pData + 4 * pData->AvmObjOffset);
          if ( v14 )
            v15 = (Scaleform::GFx::AS3::AvmTextField *)(v14 - 28);
          else
            v15 = 0;
          Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(v15, vm[0], v12, v13);
        }
        ++v12;
      }
      while ( v12 < (unsigned int)textField );
    }
  }
  else if ( (v8->Flags & 0x1F) - 12 <= 3 )
  {
    v16 = (*(int (__thiscall **)(int))(*((_DWORD *)&pData->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + pData->AvmObjOffset)
                                     + 4))((int)pData + 4 * pData->AvmObjOffset);
    if ( v16 )
      Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(
        (Scaleform::GFx::AS3::AvmTextField *)(v16 - 28),
        pVM,
        0,
        v8);
    else
      Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(0, pVM, 0, v8);
  }
}

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
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::VM *vm; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+8h] [ebp-4h]

  pVM = this->pTraits.pObject->pVM;
  vm = pVM;
  if ( textField )
  {
    pData = (Scaleform::GFx::TextField *)textField[2].pData;
    v8 = substInfo;
    v9 = substInfo->Flags & 0x1F;
    if ( (v9 - 12 > 3 || substInfo->value.VS._1.VInt) && v9 )
    {
      if ( v9 - 12 > 3 )
      {
        Name = Scaleform::GFx::DisplayObject::GetName(pData, (Scaleform::GFx::ASString *)&textField);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &pData->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed: parameter should be either 'null', object or array",
          Name->pNode->pData);
        v18 = textField;
        --textField->RefCount;
        if ( !v18->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      else
      {
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
                Scaleform::GFx::AS3::AvmTextField::ProceedImageSubstitution(v15, vm, v12, v13);
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
    }
    else
    {
      Scaleform::GFx::TextField::ClearIdImageDescAssoc(pData);
      Scaleform::GFx::TextField::ClearImageSubstitutor(pData);
      pData->pDocument.pObject->RTFlags |= 2u;
      Scaleform::GFx::TextField::SetDirtyFlag(pData);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&vm, eNullArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
    v6 = v20;
    --v20->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

int __thiscall Scaleform::GFx::AS3::VM::OnException(
        Scaleform::GFx::AS3::VM *this,
        unsigned int offset,
        unsigned int cf)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v5; // ebp
  unsigned int exc_type_ind; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // ebp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v10; // esi
  Scaleform::GFx::AS3::Value *v11; // eax
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi
  Scaleform::GFx::AS3::WeakProxy *v13; // eax
  bool v14; // zf
  Scaleform::GFx::AS3::Value *v15; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  int result; // eax
  int position; // [esp+Ch] [ebp-Ch]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *ei; // [esp+10h] [ebp-8h]
  const Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *e; // [esp+14h] [ebp-4h]

  v3 = cf;
  v5 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)(*(_DWORD *)(*(_DWORD *)(cf + 20) + 112)
                                                             + 12 * *(_DWORD *)(cf + 24));
  position = -1;
  e = v5;
  cf = 0;
  if ( Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception::FindExceptionInfo(v5, offset, &cf) )
  {
    while ( 1 )
    {
      exc_type_ind = v5->info.Data.Data[cf].exc_type_ind;
      ei = &v5->info.Data.Data[cf];
      if ( !exc_type_ind )
        break;
      if ( (this->ExceptionObj.Flags & 0x1F) != 0 )
      {
        ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, &this->ExceptionObj);
        this->HandleException = 0;
        pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)ClassTraits;
        v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
               this,
               *(Scaleform::GFx::AS3::VMFile **)(v3 + 20),
               (Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 20) + 60) + 88)
                                                     + 16 * exc_type_ind));
        v10 = v9;
        this->HandleException = 1;
        if ( v9 )
        {
          if ( v9 == pObject )
            goto LABEL_22;
          if ( pObject )
          {
            while ( !pObject->ITraits.pObject->SupportsInterface(pObject->ITraits.pObject, v10->ITraits.pObject) )
            {
              pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pObject->pParent.pObject;
              if ( pObject == v10 )
                break;
              if ( !pObject )
                goto LABEL_10;
            }
LABEL_22:
            Scaleform::GFx::AS3::ValueStack::PopReserved(
              (Scaleform::GFx::AS3::ValueStack *)(*(_DWORD *)(*(_DWORD *)(v3 + 20) + 20) + 40),
              *(Scaleform::GFx::AS3::Value **)(v3 + 40));
            v15 = ++this->OpStack.pCurrent;
            p_ExceptionObj = &this->ExceptionObj;
            if ( v15 )
            {
              v15->Flags = p_ExceptionObj->Flags;
              v15->Bonus.pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
              v15->value.VS._1.VInt = this->ExceptionObj.value.VS._1.VInt;
              v15->value.VS._2.VObj = this->ExceptionObj.value.VS._2.VObj;
              if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
              {
                if ( (p_ExceptionObj->Flags & 0x200) != 0 )
                  ++this->ExceptionObj.Bonus.pWeakProxy->RefCount;
                else
                  Scaleform::GFx::AS3::Value::AddRefInternal(&this->ExceptionObj);
              }
            }
            if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
            {
              if ( (p_ExceptionObj->Flags & 0x200) != 0 )
              {
                pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
                v14 = pWeakProxy->RefCount-- == 1;
                if ( v14 )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
LABEL_31:
                p_ExceptionObj->Flags &= 0xFFFFFDE0;
                p_ExceptionObj->Bonus.pWeakProxy = 0;
                p_ExceptionObj->value.VS._1.VInt = 0;
                p_ExceptionObj->value.VS._2.VObj = 0;
                goto LABEL_33;
              }
LABEL_32:
              Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
              goto LABEL_33;
            }
            goto LABEL_33;
          }
        }
LABEL_10:
        v5 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *)e;
      }
      ++cf;
      if ( !Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception::FindExceptionInfo(v5, offset, &cf) )
        goto LABEL_34;
    }
    Scaleform::GFx::AS3::ValueStack::PopReserved(
      (Scaleform::GFx::AS3::ValueStack *)(*(_DWORD *)(*(_DWORD *)(v3 + 20) + 20) + 40),
      *(Scaleform::GFx::AS3::Value **)(v3 + 40));
    v11 = ++this->OpStack.pCurrent;
    p_ExceptionObj = &this->ExceptionObj;
    if ( v11 )
    {
      v11->Flags = p_ExceptionObj->Flags;
      v11->Bonus.pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
      v11->value.VS._1.VInt = this->ExceptionObj.value.VS._1.VInt;
      v11->value.VS._2.VObj = this->ExceptionObj.value.VS._2.VObj;
      if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
      {
        if ( (p_ExceptionObj->Flags & 0x200) != 0 )
          ++this->ExceptionObj.Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(&this->ExceptionObj);
      }
    }
    if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
    {
      if ( (p_ExceptionObj->Flags & 0x200) != 0 )
      {
        v13 = this->ExceptionObj.Bonus.pWeakProxy;
        v14 = v13->RefCount-- == 1;
        if ( v14 )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
          p_ExceptionObj->Flags &= 0xFFFFFDE0;
          this->ExceptionObj.Bonus.pWeakProxy = 0;
          this->ExceptionObj.value.VS._1.VInt = 0;
          this->ExceptionObj.value.VS._2.VObj = 0;
          goto LABEL_33;
        }
        goto LABEL_31;
      }
      goto LABEL_32;
    }
LABEL_33:
    p_ExceptionObj->Flags = 0;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      *(Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> **)(v3 + 36),
      *(_DWORD *)(v3 + 4));
    position = ei->target;
  }
LABEL_34:
  result = position;
  this->HandleException = position < 0;
  return result;
}

void __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::ArrayBase *arr,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v5; // esi
  void (__thiscall *GetValueUnsafe)(Scaleform::GFx::AS3::ArrayBase *, unsigned int, Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-29h] BYREF
  Scaleform::GFx::AS3::VM::Error v11; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+28h] [ebp-10h] BYREF
  unsigned int size; // [esp+3Ch] [ebp+4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = 0;
    size = arr->GetArraySize(arr);
    if ( size )
    {
      while ( 1 )
      {
        GetValueUnsafe = arr->GetValueUnsafe;
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        GetValueUnsafe(arr, v5, &v);
        if ( !tr->Coerce(tr, &v, &r) )
          break;
        this->PushBackValueUnsafe(this, &r);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= size )
          return;
      }
      VMRef = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v8);
      pNode = v11.Message.pNode;
      --v11.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}


void __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        const Scaleform::GFx::AS3::Instances::fl::Array *arr,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  unsigned int v5; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
  const Scaleform::GFx::AS3::Value *v7; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+7h] [ebp-15h] BYREF
  unsigned int size; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value r; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    p_SA = &arr->SA;
    v5 = 0;
    size = arr->SA.Length;
    if ( size )
    {
      v6 = tr;
      while ( 1 )
      {
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        v7 = Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, v5);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&arr, v6, v7, &r)->Result )
          break;
        this->PushBackValueUnsafe(this, &r);
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= size )
          return;
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}


bool __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        const Scaleform::GFx::AS3::Value *value,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // edi

  VMRef = this->VMRef;
  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(VMRef, value);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ClassTraits, VMRef->TraitsArray.pObject) )
  {
    Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
      this,
      (const Scaleform::GFx::AS3::Instances::fl::Array *)value->value.VS._1.VInt,
      tr);
    return !this->VMRef->HandleException;
  }
  else if ( (Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ClassTraits, VMRef->TraitsVector_int.pObject)
          || Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ClassTraits, VMRef->TraitsVector_uint.pObject)
          || Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ClassTraits, VMRef->TraitsVector_Number.pObject)
          || Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(ClassTraits, VMRef->TraitsVector_String.pObject)
          || ClassTraits->TraitsType == Traits_Vector_object && (ClassTraits->Flags & 0x20) != 0)
         && value->value.VS._1.VInt != -32 )
  {
    Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
      this,
      (Scaleform::GFx::AS3::ArrayBase *)(value->value.VS._1.VInt + 32),
      tr);
    return !VMRef->HandleException;
  }
  else
  {
    return 0;
  }
}

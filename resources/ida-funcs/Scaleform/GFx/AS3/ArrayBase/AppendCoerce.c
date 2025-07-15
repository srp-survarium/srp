void __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::ArrayBase *arr,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ArrayBase *v4; // edi
  unsigned int v5; // ebp
  void (__thiscall *GetValueUnsafe)(Scaleform::GFx::AS3::ArrayBase *, unsigned int, Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+8h] [ebp-28h] BYREF
  unsigned int size; // [esp+Ch] [ebp-24h]
  Scaleform::GFx::AS3::Value v; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+20h] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result[3])->Result )
  {
    v4 = arr;
    v5 = 0;
    size = arr->GetArraySize(arr);
    if ( size )
    {
      while ( 1 )
      {
        GetValueUnsafe = v4->GetValueUnsafe;
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        GetValueUnsafe(v4, v5, &v);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
                this,
                (Scaleform::GFx::AS3::CheckResult *)&arr,
                tr,
                &v,
                (Scaleform::GFx::ASStringNode *)&r)->Result )
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
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // ebp
  unsigned int v5; // edi
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // ebx
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
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
                this,
                (Scaleform::GFx::AS3::CheckResult *)&arr,
                v6,
                v7,
                (Scaleform::GFx::ASStringNode *)&r)->Result )
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
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // edi

  VMRef = this->VMRef;
  ClassTraits = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::VM::GetClassTraits(VMRef, value);
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

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

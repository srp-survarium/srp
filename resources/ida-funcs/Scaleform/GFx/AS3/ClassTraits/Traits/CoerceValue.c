char __thiscall Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // edx
  long double v; // st7
  const Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // eax
  const Scaleform::GFx::AS3::Value *v_4; // [esp+4h] [ebp-Ch]

  pVM = this->pVM;
  TraitsType = this->TraitsType;
  switch ( value->Flags & 0x1F )
  {
    case 0u:
      Scaleform::GFx::AS3::Value::SetNull(result);
      return 1;
    case 1u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_Boolean )
        return 0;
      goto LABEL_33;
    case 2u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_Number && TraitsType != Traits_SInt )
        return 0;
      v = (double)value->value.VS._1.VInt;
      goto LABEL_7;
    case 3u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_Number && TraitsType != Traits_UInt )
        return 0;
      v = (double)value->value.VS._1.VUInt;
LABEL_7:
      Scaleform::GFx::AS3::Value::SetNumber(result, v);
      return 1;
    case 4u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_Number )
        return 0;
      goto LABEL_33;
    case 5u:
    case 7u:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_Function )
        goto $LN19_50;
      return 0;
    case 0xAu:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_String )
        goto LABEL_33;
      return 0;
    case 0xBu:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_Namespace )
        goto LABEL_33;
      return 0;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      v_4 = value;
      if ( !value->value.VS._1.VInt )
        goto LABEL_16;
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(pVM, value);
LABEL_32:
      if ( !Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(this, ClassTraits) )
        return 0;
LABEL_33:
      Scaleform::GFx::AS3::Value::operator=(result, value);
      return 1;
    case 0xDu:
      ClassTraits = *(const Scaleform::GFx::AS3::ClassTraits::Traits **)(value->value.VS._1.VInt + 20);
      goto LABEL_32;
    case 0x10u:
    case 0x11u:
$LN19_50:
      v_4 = value;
LABEL_16:
      Scaleform::GFx::AS3::Value::Assign(result, v_4);
      return 1;
    default:
      return 1;
  }
}

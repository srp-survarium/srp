Scaleform::GFx::AS3::SlotInfo::BindingType __thiscall Scaleform::GFx::AS3::Traits::GetBindingType(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v4; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType result; // eax

  pVM = this->pVM;
  if ( mn->Kind == MN_QName && !mn->NameIndex && !mn->Ind )
    return 2;
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pVM, file, mn);
  if ( !v4 )
    return 2;
  switch ( v4->TraitsType )
  {
    case Traits_Boolean:
      result = BT_Boolean;
      break;
    case Traits_SInt:
      result = BT_Int;
      break;
    case Traits_UInt:
      result = BT_UInt;
      break;
    case Traits_Number:
      result = BT_Number;
      break;
    case Traits_String:
      result = BT_String;
      break;
    case Traits_Function:
      return 2;
    default:
      result = (v4 != (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pVM->TraitsObject.pObject) + 2;
      break;
  }
  return result;
}

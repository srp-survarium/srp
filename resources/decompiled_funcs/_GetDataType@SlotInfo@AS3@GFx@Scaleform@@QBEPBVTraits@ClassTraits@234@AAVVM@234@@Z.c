const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::SlotInfo::GetDataType(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits const > *p_CTraits; // ebx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // ebp
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // ecx
  int v6; // eax
  Scaleform::GFx::AS3::Abc::Multiname *TypeName; // esi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v8; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *result; // eax
  Scaleform::GFx::AS3::Multiname as3_nm; // [esp+8h] [ebp-18h] BYREF

  p_CTraits = &this->CTraits;
  if ( this->CTraits.pObject )
    return p_CTraits->pObject;
  pObject = this->File.pObject;
  if ( pObject && (TI = (Scaleform::GFx::AS3::Abc::TraitInfo *)this->TI) != 0 )
  {
    v6 = TI->kind & 0xF;
    if ( (TI->kind & 0xF) == 0 || v6 == 6 || v6 == 4 || v6 == 5 )
    {
      TypeName = (Scaleform::GFx::AS3::Abc::Multiname *)Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(
                                                          TI,
                                                          pObject->File.pObject);
      Scaleform::GFx::AS3::Multiname::Multiname(&as3_nm, pObject, TypeName);
      v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, this->File.pObject, TypeName);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v8);
      Scaleform::GFx::AS3::Multiname::~Multiname(&as3_nm);
      return p_CTraits->pObject;
    }
    else
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsFunction.pObject);
      return p_CTraits->pObject;
    }
  }
  else
  {
    switch ( (int)(*(_DWORD *)this << 22) >> 27 )
    {
      case 0:
      case 1:
      case 2:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsClassClass.pObject);
        result = p_CTraits->pObject;
        break;
      case 3:
      case 4:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsObject.pObject);
        result = p_CTraits->pObject;
        break;
      case 5:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsBoolean.pObject);
        result = p_CTraits->pObject;
        break;
      case 6:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsInt.pObject);
        result = p_CTraits->pObject;
        break;
      case 7:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsUint.pObject);
        result = p_CTraits->pObject;
        break;
      case 8:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsNumber.pObject);
        result = p_CTraits->pObject;
        break;
      case 9:
      case 10:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsString.pObject);
        result = p_CTraits->pObject;
        break;
      case 11:
      case 12:
      case 13:
      case 14:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)p_CTraits,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)vm->TraitsFunction.pObject);
        return p_CTraits->pObject;
      default:
        return p_CTraits->pObject;
    }
  }
  return result;
}

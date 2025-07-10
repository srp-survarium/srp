Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *obj)
{
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  const Scaleform::GFx::AS3::VM::Error *v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // edi
  Scaleform::GFx::ASStringNode *v17; // ecx
  Scaleform::GFx::AS3::Object_vtbl *VInt; // esi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::Value *v24; // eax
  const Scaleform::GFx::AS3::VM::Error *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  const Scaleform::GFx::AS3::VM::Error *v27; // eax
  Scaleform::GFx::AS3::VM::Error v28; // [esp+8h] [ebp-58h] BYREF
  Scaleform::GFx::AS3::VM::Error v29; // [esp+10h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v30; // [esp+18h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+20h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [esp+30h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value setter; // [esp+40h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v34; // [esp+50h] [ebp-10h] BYREF

  if ( (*(_BYTE *)this & 1) != 0 && vm->InInitializer <= 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, eConstWriteError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      vm,
      v6,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v28.Message.pNode;
    --v28.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v8 = result;
    result->Result = 0;
    return v8;
  }
  v9 = v->Flags & 0x1F;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( (_BYTE)v9 == 13 || (int)((*(_DWORD *)this & 0xFFFFFFE0) << 22) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&r, v);
  }
  else
  {
    DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
    if ( !DataType )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eClassNotFoundError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v11,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v12 = v28.Message.pNode;
LABEL_41:
      if ( !--v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_43:
      result->Result = 0;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    }
    if ( !DataType->Coerce(DataType, v, &r) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eCheckTypeFailedError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v13,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
      v12 = v28.Message.pNode;
      goto LABEL_41;
    }
  }
  v14 = *(_DWORD *)this;
  v15 = v14 << 22 >> 27;
  v16 = (32 * v14) >> 15;
  switch ( v15 )
  {
    case 1:
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::SetValueArray(
        obj,
        (Scaleform::GFx::AS3::AbsoluteIndex)v16,
        &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 2:
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)obj + v16), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 3:
      Scaleform::GFx::AS3::STPtr::SetValue((Scaleform::GFx::AS3::STPtr *)((char *)obj + v16), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 4:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)((char *)obj + v16),
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)r.value.VS._1.VInt);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 5:
      *((_BYTE *)&obj->__vftable + v16) = r.value.VS._1.VBool;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 6:
    case 7:
      *(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl **)((char *)&obj->__vftable + v16) = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)r.value.VS._1.VInt;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 8:
      *(double *)((char *)&obj->__vftable + v16) = r.value.VNumber;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 9:
      v17 = *(Scaleform::GFx::ASStringNode **)((char *)&obj->__vftable + v16);
      VInt = (Scaleform::GFx::AS3::Object_vtbl *)r.value.VS._1.VInt;
      if ( v17 )
      {
        if ( v17->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      }
      *(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl **)((char *)&obj->__vftable + v16) = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)VInt;
      if ( !VInt )
        goto LABEL_36;
      ++VInt->SetProperty;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      v8 = result;
      break;
    case 10:
    case 12:
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eConstWriteError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v20,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v21 = v28.Message.pNode;
      --v28.Message.pNode->RefCount;
      if ( v21->RefCount )
        goto LABEL_36;
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      v8 = result;
      break;
    case 11:
      Scaleform::GFx::AS3::VM::Error::Error(&v30, eCannotAssignToMethodError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v27,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v12 = v30.Message.pNode;
      goto LABEL_41;
    case 13:
    case 14:
      VT = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetValue(VT, &setter, (Scaleform::GFx::AS3::AbsoluteIndex)(v16 + 1));
      if ( Scaleform::GFx::AS3::Value::IsCallable(&setter) )
      {
        Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
        resulta = *Undefined;
        if ( (Undefined->Flags & 0x1F) > 9 )
        {
          if ( (Undefined->Flags & 0x200) != 0 )
            ++Undefined->Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
        }
        Scaleform::GFx::AS3::Value::Value(&v34, obj);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &setter, v24, &resulta, 1u, &r, 0);
        Scaleform::GFx::AS3::Value::~Value(&v34);
        if ( vm->HandleException )
        {
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
          Scaleform::GFx::AS3::Value::~Value(&r);
          v8 = result;
        }
        else
        {
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
LABEL_36:
          result->Result = 1;
          Scaleform::GFx::AS3::Value::~Value(&r);
          v8 = result;
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v29, eCallOfNonFunctionError, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          vm,
          v25,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v26 = v29.Message.pNode;
        --v29.Message.pNode->RefCount;
        if ( !v26->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&setter);
        Scaleform::GFx::AS3::Value::~Value(&r);
        v8 = result;
      }
      break;
    default:
      goto LABEL_43;
  }
  return v8;
}

Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::VTable *vt)
{
  Scaleform::GFx::ASStringNode *pObject; // edi
  unsigned int v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  unsigned int v12; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // eax
  const Scaleform::GFx::ASString *DataTypeName; // eax
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  const Scaleform::GFx::ASString *v18; // eax
  int v19; // ebp
  Scaleform::GFx::AS3::Value::V1U pLower; // esi
  Scaleform::GFx::ASStringNode *v21; // ecx
  Scaleform::GFx::AS3::Value::V1U v22; // edi
  Scaleform::GFx::AS3::Value::V1U *v23; // esi
  const char *pData; // edx
  const Scaleform::GFx::AS3::VM::Error *v26; // eax
  Scaleform::GFx::AS3::VTable *v27; // eax
  const Scaleform::GFx::AS3::Value *v28; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::VM::Error *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // ebp
  bool IsPrimitive; // al
  Scaleform::GFx::ASStringNode *v35; // edi
  const Scaleform::GFx::AS3::VM::Error *v36; // eax
  const Scaleform::GFx::AS3::VM::Error *v37; // eax
  Scaleform::StringDataPtr v38; // [esp-Ch] [ebp-68h] BYREF
  Scaleform::GFx::AS3::TypeInfo *v39; // [esp-4h] [ebp-60h]
  Scaleform::GFx::AS3::VM::Error v40; // [esp+Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v41; // [esp+14h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::VM::Error v42; // [esp+1Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::VM::Error v43; // [esp+24h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value setter; // [esp+4Ch] [ebp-10h] BYREF

  if ( (*(_BYTE *)this & 1) != 0 && (int)vm[1].pManager <= 0 )
  {
    pObject = this->Name.pObject;
    v39 = (Scaleform::GFx::AS3::TypeInfo *)_this;
    v38.pStr = pObject->pData;
    if ( v38.pStr )
      v8 = strlen(v38.pStr);
    else
      v8 = 0;
    v38.Size = v8;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v40,
      (Scaleform::GFx::AS3::VM_vtbl *)0x432,
      vm,
      v38,
      (Scaleform::GFx::AS3::Value *)v39);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)vm,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v40.Message.pNode;
    --v40.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v11 = result;
    result->Result = 0;
    return v11;
  }
  v12 = v->Flags & 0x1F;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( (_BYTE)v12 == 13 || (int)((*(_DWORD *)this & 0xFFFFFFE0) << 22) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&r, v);
  }
  else
  {
    DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, (Scaleform::GFx::AS3::VM *)vm);
    if ( !DataType )
    {
      DataTypeName = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(
                       this,
                       (Scaleform::GFx::ASString *)&_this,
                       (Scaleform::GFx::AS3::VM *)vm);
      Scaleform::GFx::AS3::Value::Value(&setter, DataTypeName);
      Scaleform::GFx::AS3::VM::Error::Error(&v40, (Scaleform::GFx::AS3::VM_vtbl *)0x3F6, vm, &setter);
      v39 = &Scaleform::GFx::AS3::fl::VerifyErrorTI;
      goto LABEL_13;
    }
    if ( !DataType->Coerce((Scaleform::GFx::AS3::ClassTraits::Traits *)DataType, v, &r) )
    {
      v18 = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(
              this,
              (Scaleform::GFx::ASString *)&_this,
              (Scaleform::GFx::AS3::VM *)vm);
      Scaleform::GFx::AS3::Value::Value(&setter, v18);
      Scaleform::GFx::AS3::VM::Error::Error(&v40, (Scaleform::GFx::AS3::VM_vtbl *)0x40A, vm, v, &setter);
      v39 = &Scaleform::GFx::AS3::fl::TypeErrorTI;
LABEL_13:
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        (Scaleform::GFx::AS3::VM *)vm,
        v15,
        (Scaleform::GFx::ASStringNode *)v39);
      v16 = v40.Message.pNode;
      --v40.Message.pNode->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      Scaleform::GFx::AS3::Value::~Value(&setter);
      v17 = _this;
LABEL_50:
      if ( !--v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
LABEL_52:
      result->Result = 0;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    }
  }
  v19 = (32 * *(_DWORD *)this) >> 15;
  switch ( (int)(*(_DWORD *)this << 22) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::SetValueArray(
        (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)_this->pLower,
        (Scaleform::GFx::AS3::AbsoluteIndex)v19,
        &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 2:
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)_this->pLower + v19), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 3:
      Scaleform::GFx::AS3::STPtr::SetValue((Scaleform::GFx::AS3::STPtr *)((char *)_this->pLower + v19), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 4:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)((char *)_this->pLower + v19),
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)r.value.VS._1.VInt);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 5:
      *((_BYTE *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v19) = r.value.VS._1.VBool;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 6:
    case 7:
      *(const char **)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v19) = (const char *)r.value.VS._1.VInt;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 8:
      *(double *)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v19) = r.value.VNumber;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 9:
      pLower = (Scaleform::GFx::AS3::Value::V1U)_this->pLower;
      v21 = *(Scaleform::GFx::ASStringNode **)(pLower.VInt + v19);
      v22 = r.value.VS._1;
      v23 = (Scaleform::GFx::AS3::Value::V1U *)(v19 + pLower.VInt);
      if ( v21 )
      {
        if ( v21->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      }
      *v23 = v22;
      if ( !v22.VInt )
        goto LABEL_43;
      ++*(_DWORD *)(v22.VInt + 12);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      v11 = result;
      break;
    case 10:
    case 12:
      pData = this->Name.pObject->pData;
      v39 = (Scaleform::GFx::AS3::TypeInfo *)_this;
      Scaleform::StringDataPtr::StringDataPtr(&v38, pData);
      Scaleform::GFx::AS3::VM::Error::Error(
        &v40,
        (Scaleform::GFx::AS3::VM_vtbl *)0x432,
        vm,
        v38,
        (Scaleform::GFx::AS3::Value *)v39);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        (Scaleform::GFx::AS3::VM *)vm,
        v26,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v17 = v40.Message.pNode;
      goto LABEL_50;
    case 11:
      v33 = _this;
      IsPrimitive = Scaleform::GFx::AS3::Value::IsPrimitive((Scaleform::GFx::AS3::Value *)_this);
      v35 = this->Name.pObject;
      v39 = (Scaleform::GFx::AS3::TypeInfo *)v33;
      if ( IsPrimitive )
      {
        Scaleform::StringDataPtr::StringDataPtr(&v38, v35->pData);
        Scaleform::GFx::AS3::VM::Error::Error(
          &v42,
          (Scaleform::GFx::AS3::VM_vtbl *)0x420,
          vm,
          v38,
          (Scaleform::GFx::AS3::Value *)v39);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          (Scaleform::GFx::AS3::VM *)vm,
          v36,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v17 = v42.Message.pNode;
      }
      else
      {
        Scaleform::StringDataPtr::StringDataPtr(&v38, v35->pData);
        Scaleform::GFx::AS3::VM::Error::Error(
          &v43,
          (Scaleform::GFx::AS3::VM_vtbl *)0x40D,
          vm,
          v38,
          (Scaleform::GFx::AS3::Value *)v39);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          (Scaleform::GFx::AS3::VM *)vm,
          v37,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v17 = v43.Message.pNode;
      }
      goto LABEL_50;
    case 13:
    case 14:
      v27 = vt;
      v28 = (const Scaleform::GFx::AS3::Value *)_this;
      if ( !vt )
      {
        ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(
                        (Scaleform::GFx::AS3::VM *)vm,
                        (const Scaleform::GFx::AS3::Value *)_this);
        v27 = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
      }
      Scaleform::GFx::AS3::VTable::GetValue(v27, &setter, (Scaleform::GFx::AS3::AbsoluteIndex)(v19 + 1));
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
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe((Scaleform::GFx::AS3::VM *)vm, &setter, v28, &resulta, 1u, &r, 0);
        if ( LOBYTE(vm[4].pData) )
        {
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
          Scaleform::GFx::AS3::Value::~Value(&r);
          v11 = result;
        }
        else
        {
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
LABEL_43:
          result->Result = 1;
          Scaleform::GFx::AS3::Value::~Value(&r);
          v11 = result;
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v41, (Scaleform::GFx::AS3::VM_vtbl *)0x3EE, vm, &setter);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          (Scaleform::GFx::AS3::VM *)vm,
          v31,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v32 = v41.Message.pNode;
        --v41.Message.pNode->RefCount;
        if ( !v32->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&setter);
        Scaleform::GFx::AS3::Value::~Value(&r);
        v11 = result;
      }
      break;
    default:
      goto LABEL_52;
  }
  return v11;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *obj)
{
  Scaleform::GFx::AS3::VM *v5; // esi
  const char *pData; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::CheckResult *v13; // eax
  Scaleform::GFx::AS3::Value *v14; // ebp
  unsigned int v15; // ecx
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // eax
  const Scaleform::GFx::ASString *DataTypeName; // eax
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  const Scaleform::GFx::ASString *v21; // eax
  int v22; // ebp
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v23; // edi
  Scaleform::GFx::ASStringNode *v24; // ecx
  Scaleform::GFx::AS3::Value::V1U v25; // esi
  Scaleform::GFx::ASString *v27; // eax
  Scaleform::GFx::ASStringNode *pObject; // edi
  const Scaleform::GFx::AS3::VM::Error *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS3::AbsoluteIndex v32; // edi
  Scaleform::GFx::AS3::Object *v33; // ebp
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  const Scaleform::GFx::AS3::Value *v36; // eax
  const Scaleform::GFx::AS3::VM::Error *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASString *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // edi
  const Scaleform::GFx::AS3::VM::Error *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::StringDataPtr v43; // [esp-10h] [ebp-74h] BYREF
  Scaleform::StringDataPtr v44[2]; // [esp-8h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v45; // [esp+Ch] [ebp-58h] BYREF
  Scaleform::GFx::AS3::VM::Error v46; // [esp+14h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v47; // [esp+1Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value setter; // [esp+44h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v51; // [esp+54h] [ebp-10h] BYREF

  v5 = vm;
  if ( (*(_BYTE *)this & 1) != 0 && vm->InInitializer <= 0 )
  {
    pData = obj->pTraits.pObject->GetName(obj->pTraits.pObject, &obj)->pNode->pData;
    v44[0].pStr = pData;
    if ( pData )
      v8 = strlen(pData);
    else
      v8 = 0;
    v44[0].Size = v8;
    v43.pStr = this->Name.pObject->pData;
    if ( v43.pStr )
      v9 = strlen(v43.pStr);
    else
      v9 = 0;
    v43.Size = v9;
    Scaleform::GFx::AS3::VM::Error::Error(&v45, eConstWriteError, (Scaleform::String)v5, v43, v44[0]);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v5,
      v10,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v45.Message.pNode;
    --v45.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = (Scaleform::GFx::ASStringNode *)obj;
    --obj->pPrev;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v13 = result;
    result->Result = 0;
    return v13;
  }
  v14 = v;
  v15 = v->Flags & 0x1F;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( (_BYTE)v15 == 13 || (int)((*(_DWORD *)this & 0xFFFFFFE0) << 22) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&r, v);
  }
  else
  {
    DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
    if ( !DataType )
    {
      DataTypeName = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(this, (Scaleform::GFx::ASString *)&obj, v5);
      Scaleform::GFx::AS3::Value::Value(&setter, DataTypeName);
      Scaleform::GFx::AS3::VM::Error::Error(
        &v45,
        (Scaleform::GFx::AS3::VM_vtbl *)0x3F6,
        (Scaleform::GFx::ASStringNode *)v5,
        &setter);
      v44[0].Size = (unsigned int)&Scaleform::GFx::AS3::fl::VerifyErrorTI;
      goto LABEL_18;
    }
    if ( !DataType->Coerce((Scaleform::GFx::AS3::ClassTraits::Traits *)DataType, v14, &r) )
    {
      v21 = Scaleform::GFx::AS3::SlotInfo::GetDataTypeName(this, (Scaleform::GFx::ASString *)&obj, v5);
      Scaleform::GFx::AS3::Value::Value(&setter, v21);
      Scaleform::GFx::AS3::VM::Error::Error(
        &v45,
        (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
        (Scaleform::GFx::ASStringNode *)v5,
        v14,
        &setter);
      v44[0].Size = (unsigned int)&Scaleform::GFx::AS3::fl::TypeErrorTI;
LABEL_18:
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v18, (Scaleform::GFx::ASStringNode *)v44[0].Size);
      v19 = v45.Message.pNode;
      --v45.Message.pNode->RefCount;
      if ( !v19->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      Scaleform::GFx::AS3::Value::~Value(&setter);
      v20 = (Scaleform::GFx::ASStringNode *)obj;
LABEL_56:
      if ( !--v20->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_58:
      result->Result = 0;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    }
  }
  v22 = (32 * *(_DWORD *)this) >> 15;
  switch ( (int)(*(_DWORD *)this << 22) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::SetValueArray(
        obj,
        (Scaleform::GFx::AS3::AbsoluteIndex)v22,
        &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 2:
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)obj + v22), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 3:
      Scaleform::GFx::AS3::STPtr::SetValue((Scaleform::GFx::AS3::STPtr *)((char *)obj + v22), &r);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 4:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)((char *)obj + v22),
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)r.value.VS._1.VInt);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 5:
      *((_BYTE *)&obj->__vftable + v22) = r.value.VS._1.VBool;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 6:
    case 7:
      *(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl **)((char *)&obj->__vftable + v22) = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP_vtbl *)r.value.VS._1.VInt;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 8:
      *(double *)((char *)&obj->__vftable + v22) = r.value.VNumber;
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      return result;
    case 9:
      v23 = obj;
      v24 = *(Scaleform::GFx::ASStringNode **)((char *)&obj->__vftable + v22);
      v25 = r.value.VS._1;
      if ( v24 )
      {
        if ( v24->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      }
      *(Scaleform::GFx::AS3::Value::V1U *)((char *)&v23->__vftable + v22) = v25;
      if ( !v25.VInt )
        goto LABEL_49;
      ++*(_DWORD *)(v25.VInt + 12);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      v13 = result;
      break;
    case 10:
    case 12:
      v27 = obj->pTraits.pObject->GetName(obj->pTraits.pObject, &obj);
      pObject = this->Name.pObject;
      Scaleform::StringDataPtr::StringDataPtr(v44, v27->pNode->pData);
      Scaleform::StringDataPtr::StringDataPtr(&v43, pObject->pData);
      Scaleform::GFx::AS3::VM::Error::Error(&v45, eConstWriteError, (Scaleform::String)v5, v43, v44[0]);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5,
        v29,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v30 = v45.Message.pNode;
      --v45.Message.pNode->RefCount;
      if ( !v30->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      v31 = (Scaleform::GFx::ASStringNode *)obj;
      --obj->pPrev;
      if ( v31->RefCount )
        goto LABEL_49;
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      result->Result = 1;
      Scaleform::GFx::AS3::Value::~Value(&r);
      v13 = result;
      break;
    case 11:
      v39 = obj->pTraits.pObject->GetName(obj->pTraits.pObject, &vm);
      v40 = this->Name.pObject;
      Scaleform::StringDataPtr::StringDataPtr(v44, v39->pNode->pData);
      Scaleform::StringDataPtr::StringDataPtr(&v43, v40->pData);
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eCannotAssignToMethodError, (Scaleform::String)v5, v43, v44[0]);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5,
        v41,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v42 = v47.Message.pNode;
      --v47.Message.pNode->RefCount;
      if ( !v42->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v42);
      v20 = (Scaleform::GFx::ASStringNode *)vm;
      goto LABEL_56;
    case 13:
    case 14:
      v32.Index = v22 + 1;
      v33 = obj;
      VT = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetValue(VT, &setter, v32);
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
        Scaleform::GFx::AS3::Value::Value(&v51, v33);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, &setter, v36, &resulta, 1u, &r, 0);
        Scaleform::GFx::AS3::Value::~Value(&v51);
        if ( v5->HandleException )
        {
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
          Scaleform::GFx::AS3::Value::~Value(&r);
          v13 = result;
        }
        else
        {
          Scaleform::GFx::AS3::Value::~Value(&resulta);
          Scaleform::GFx::AS3::Value::~Value(&setter);
LABEL_49:
          result->Result = 1;
          Scaleform::GFx::AS3::Value::~Value(&r);
          v13 = result;
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          &v46,
          (Scaleform::GFx::AS3::VM_vtbl *)0x3EE,
          (Scaleform::GFx::ASStringNode *)v5,
          &setter);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v5,
          v37,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v38 = v46.Message.pNode;
        --v46.Message.pNode->RefCount;
        if ( !v38->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&setter);
        Scaleform::GFx::AS3::Value::~Value(&r);
        v13 = result;
      }
      break;
    default:
      goto LABEL_58;
  }
  return v13;
}

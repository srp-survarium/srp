Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::ASStringNode *obj)
{
  int v5; // esi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  int v7; // eax
  char v8; // cl
  Scaleform::GFx::ASStringNode *v9; // edx
  Scaleform::GFx::AS3::Value::V1U v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::AS3::Value::V1U v12; // esi
  Scaleform::GFx::ASStringNode *v13; // edx
  unsigned int Flags; // ecx
  Scaleform::GFx::ASStringNode *v15; // edx
  Scaleform::GFx::ASStringNode *v16; // esi
  Scaleform::GFx::ASStringNode *v17; // edx
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::Object *v20; // edi
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Object *v22; // ebx
  Scaleform::GFx::AS3::VTable *v23; // eax
  _DWORD *v24; // esi
  Scaleform::GFx::AS3::VM *v25; // edi
  const Scaleform::GFx::AS3::Value *v26; // eax
  const char ***v27; // eax
  const Scaleform::GFx::AS3::VM::Error *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::AS3::Traits *Size; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const char ***v33; // eax
  Scaleform::GFx::ASStringNode *pObject; // edi
  const Scaleform::GFx::AS3::VM::Error *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::StringDataPtr v38; // [esp-10h] [ebp-58h] BYREF
  Scaleform::StringDataPtr v39[2]; // [esp-8h] [ebp-50h] BYREF
  Scaleform::GFx::ASStringNode *v40; // [esp+Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::ASStringNode *v41[2]; // [esp+10h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::VM::Error v42; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v43; // [esp+20h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value getter; // [esp+28h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v45; // [esp+38h] [ebp-10h] BYREF

  v5 = (32 * *(_DWORD *)this) >> 15;
  switch ( (int)(*(_DWORD *)this << 22) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)obj[5].pLower + v5);
      v6 = result;
      result->Result = 1;
      break;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)((char *)obj + v5));
      v6 = result;
      result->Result = 1;
      break;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe((Scaleform::GFx::AS3::STPtr *)((char *)obj + v5), value);
      v6 = result;
      result->Result = 1;
      break;
    case 4:
      if ( !(Scaleform::GFx::ASStringNode *)((char *)obj + v5) )
        goto LABEL_23;
      v7 = *(int *)((char *)&obj->pData + v5);
      if ( v7 && (*(_DWORD *)(*(_DWORD *)(v7 + 20) + 56) & 0x20) != 0 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, *(Scaleform::GFx::AS3::Class **)((char *)&obj->pData + v5));
        v6 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, *(Scaleform::GFx::AS3::Object **)((char *)&obj->pData + v5));
        v6 = result;
        result->Result = 1;
      }
      break;
    case 5:
      v8 = *((_BYTE *)&obj->pData + v5);
      value->Flags = value->Flags & 0xFFFFFFE0 | 1;
      v9 = v41[1];
      LOBYTE(v41[0]) = v8;
      value->value.VS._1.VStr = v41[0];
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v9;
      v6 = result;
      result->Result = 1;
      break;
    case 6:
      v10 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&obj->pData + v5);
      pNode = v43.Message.pNode;
      value->Flags = value->Flags & 0xFFFFFFE0 | 2;
      value->value.VS._1 = v10;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      v6 = result;
      result->Result = 1;
      break;
    case 7:
      v12 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&obj->pData + v5);
      v13 = v43.Message.pNode;
      value->Flags = value->Flags & 0xFFFFFFE0 | 3;
      value->value.VS._1 = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v13;
      v6 = result;
      result->Result = 1;
      break;
    case 8:
      Flags = value->Flags;
      *(double *)v41 = *(double *)((char *)&obj->pData + v5);
      v15 = v41[0];
      value->Flags = Flags & 0xFFFFFFE0 | 4;
      *(_QWORD *)&value->value.VNumber = __PAIR64__((unsigned int)v41[1], (unsigned int)v15);
      v6 = result;
      result->Result = 1;
      break;
    case 9:
      v16 = *(Scaleform::GFx::ASStringNode **)((char *)&obj->pData + v5);
      if ( v16 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v16);
      }
      else
      {
        v17 = v43.Message.pNode;
        value->Flags = value->Flags & 0xFFFFFFE0 | 0xC;
        value->value.VS._1.VInt = 0;
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v17;
      }
      v6 = result;
      result->Result = 1;
      break;
    case 10:
      ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                      *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> **)(*(_DWORD *)(obj->Size + 64) + 12),
                      (Scaleform::GFx::ASString *)&obj,
                      *(char **)((char *)&obj->pData + v5));
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, ConstString);
      v19 = obj;
      --obj->RefCount;
      if ( v19->RefCount )
        goto LABEL_23;
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      v6 = result;
      result->Result = 1;
      break;
    case 11:
      v20 = (Scaleform::GFx::AS3::Object *)obj;
      VT = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)obj->Size);
      Scaleform::GFx::AS3::VTable::GetMethod(VT, value, (Scaleform::GFx::AS3::AbsoluteIndex)v5, v20, 0);
      v6 = result;
      result->Result = 1;
      break;
    case 12:
    case 14:
      v22 = (Scaleform::GFx::AS3::Object *)obj;
      v23 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)obj->Size);
      Scaleform::GFx::AS3::VTable::GetValue(v23, &getter, (Scaleform::GFx::AS3::AbsoluteIndex)v5);
      v24 = &v22->pTraits.pObject->__vftable;
      v25 = (Scaleform::GFx::AS3::VM *)v24[16];
      if ( Scaleform::GFx::AS3::Value::IsCallable(&getter) )
      {
        Scaleform::GFx::AS3::Value::Value(&v45, v22);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v25, &getter, v26, value, 0, 0, 0);
        Scaleform::GFx::AS3::Value::~Value(&v45);
        Scaleform::GFx::AS3::Value::~Value(&getter);
LABEL_23:
        v6 = result;
        result->Result = 1;
      }
      else
      {
        v27 = (const char ***)(*(int (__thiscall **)(_DWORD *, Scaleform::GFx::ASStringNode **))(*v24 + 28))(v24, &v40);
        Scaleform::StringDataPtr::StringDataPtr(v39, **v27);
        Scaleform::GFx::AS3::VM::Error::Error(&v42, eCallOfNonFunctionError, (Scaleform::String)v25, v39[0]);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          v25,
          v28,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v29 = v42.Message.pNode;
        --v42.Message.pNode->RefCount;
        if ( !v29->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        v30 = v40;
        --v40->RefCount;
        if ( !v30->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&getter);
        v6 = result;
      }
      break;
    case 13:
      Size = (Scaleform::GFx::AS3::Traits *)obj->Size;
      pVM = Size->pVM;
      v33 = (const char ***)((int (__stdcall *)(Scaleform::GFx::ASStringNode **))Size->GetName)(v41);
      pObject = this->Name.pObject;
      Scaleform::StringDataPtr::StringDataPtr(v39, **v33);
      Scaleform::StringDataPtr::StringDataPtr(&v38, pObject->pData);
      Scaleform::GFx::AS3::VM::Error::Error(&v43, eWriteOnlyError, (Scaleform::String)pVM, v38, v39[0]);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        pVM,
        v35,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v36 = v43.Message.pNode;
      --v43.Message.pNode->RefCount;
      if ( !v36->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      v37 = v41[0];
      --v41[0]->RefCount;
      if ( !v37->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      goto LABEL_33;
    default:
LABEL_33:
      v6 = result;
      result->Result = 0;
      break;
  }
  return v6;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::ASStringNode *_this,
        Scaleform::GFx::AS3::VTable *vt,
        Scaleform::GFx::AS3::SlotInfo::ValTarget vtt)
{
  int v7; // esi
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  Scaleform::GFx::AS3::Class **v9; // eax
  Scaleform::GFx::AS3::Class *v10; // eax
  char v11; // cl
  Scaleform::GFx::AS3::Value::Extra v12; // edx
  Scaleform::GFx::AS3::Value::V1U v13; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::Value::V1U v15; // esi
  Scaleform::GFx::ASStringNode *v16; // edx
  unsigned int Flags; // edx
  unsigned int v18; // ecx
  Scaleform::GFx::AS3::Value::Extra v19; // edx
  Scaleform::GFx::ASStringNode *v20; // esi
  unsigned int v21; // edx
  Scaleform::GFx::ASStringNode *v22; // ecx
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::AS3::VTable *v25; // ecx
  const Scaleform::GFx::AS3::Value *v26; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const Scaleform::GFx::AS3::Value *v28; // eax
  Scaleform::GFx::AS3::VTable *v29; // eax
  const Scaleform::GFx::AS3::Value *v30; // ebx
  Scaleform::GFx::AS3::Traits *v31; // eax
  const Scaleform::GFx::AS3::VM::Error *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  const char *pData; // eax
  const Scaleform::GFx::AS3::VM::Error *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::StringDataPtr v37; // [esp-Ch] [ebp-48h] BYREF
  Scaleform::GFx::ASStringNode *v38; // [esp-4h] [ebp-40h]
  Scaleform::GFx::AS3::Value getter; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v40; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v41; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v42; // [esp+2Ch] [ebp-10h] BYREF

  v7 = (32 * *(_DWORD *)this) >> 15;
  switch ( (int)(*(_DWORD *)this << 22) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)_this->pLower[5].pLower + v7);
      v8 = result;
      result->Result = 1;
      break;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)((char *)_this->pLower + v7));
      v8 = result;
      result->Result = 1;
      break;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe((Scaleform::GFx::AS3::STPtr *)((char *)_this->pLower + v7), value);
      v8 = result;
      result->Result = 1;
      break;
    case 4:
      v9 = (Scaleform::GFx::AS3::Class **)((char *)_this->pLower + v7);
      if ( !v9 )
        goto LABEL_31;
      v10 = *v9;
      if ( v10 && (v10->pTraits.pObject->Flags & 0x20) != 0 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v10);
        v8 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v10);
        v8 = result;
        result->Result = 1;
      }
      break;
    case 5:
      v11 = *((_BYTE *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7);
      value->Flags = value->Flags & 0xFFFFFFE0 | 1;
      v12.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)getter.Bonus;
      LOBYTE(getter.Flags) = v11;
      value->value.VS._1.VInt = getter.Flags;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v12.pWeakProxy;
      v8 = result;
      result->Result = 1;
      break;
    case 6:
      v13 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7);
      pNode = v41.Message.pNode;
      value->Flags = value->Flags & 0xFFFFFFE0 | 2;
      value->value.VS._1 = v13;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      v8 = result;
      result->Result = 1;
      break;
    case 7:
      v15 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7);
      v16 = v41.Message.pNode;
      value->Flags = value->Flags & 0xFFFFFFE0 | 3;
      value->value.VS._1 = v15;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v16;
      v8 = result;
      result->Result = 1;
      break;
    case 8:
      Flags = value->Flags;
      *(double *)&getter.Flags = *(double *)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7);
      v18 = getter.Flags;
      value->Flags = Flags & 0xFFFFFFE0 | 4;
      v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)getter.Bonus;
      value->value.VS._1.VInt = v18;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v19.pWeakProxy;
      v8 = result;
      result->Result = 1;
      break;
    case 9:
      v20 = *(Scaleform::GFx::ASStringNode **)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7);
      if ( v20 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v20);
      }
      else
      {
        v21 = value->Flags & 0xFFFFFFE0 | 0xC;
        value->value.VS._1.VInt = 0;
        v22 = v41.Message.pNode;
        value->Flags = v21;
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v22;
      }
      v8 = result;
      result->Result = 1;
      break;
    case 10:
      ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                      vm->StringManagerRef,
                      (Scaleform::GFx::ASString *)&_this,
                      *(char **)((char *)&_this->pLower->$7DDA6D7E09E348E44B226E8441B9AFBF::pData + v7));
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, ConstString);
      v24 = _this;
      --_this->RefCount;
      if ( v24->RefCount )
        goto LABEL_31;
      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      v8 = result;
      result->Result = 1;
      break;
    case 11:
      v25 = vt;
      v26 = (const Scaleform::GFx::AS3::Value *)_this;
      LOBYTE(getter.Flags) = 0;
      if ( vt )
      {
        LOBYTE(getter.Flags) = 1;
      }
      else
      {
        ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, (const Scaleform::GFx::AS3::Value *)_this);
        v25 = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
      }
      if ( (v26->Flags & 0x1F) - 12 > 3 || vtt )
      {
        v28 = Scaleform::GFx::AS3::VTable::GetValue(v25, &v42, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v28);
        Scaleform::GFx::AS3::Value::~Value(&v42);
        v8 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VTable::GetMethod(
          v25,
          value,
          (Scaleform::GFx::AS3::AbsoluteIndex)v7,
          v26->value.VS._1.VObj,
          getter.Flags);
        v8 = result;
        result->Result = 1;
      }
      break;
    case 12:
    case 14:
      v29 = vt;
      v30 = (const Scaleform::GFx::AS3::Value *)_this;
      if ( !vt )
      {
        v31 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, (const Scaleform::GFx::AS3::Value *)_this);
        v29 = Scaleform::GFx::AS3::Traits::GetVT(v31);
      }
      Scaleform::GFx::AS3::VTable::GetValue(v29, &getter, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      if ( Scaleform::GFx::AS3::Value::IsCallable(&getter) )
      {
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &getter, v30, value, 0, 0, 0);
        Scaleform::GFx::AS3::Value::~Value(&getter);
LABEL_31:
        v8 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          &v40,
          (Scaleform::GFx::AS3::VM_vtbl *)0x3EE,
          (Scaleform::GFx::ASStringNode *)vm,
          &getter);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          vm,
          v32,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v33 = v40.Message.pNode;
        --v40.Message.pNode->RefCount;
        if ( !v33->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v33);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&getter);
        v8 = result;
      }
      break;
    case 13:
      pData = this->Name.pObject->pData;
      v38 = _this;
      Scaleform::StringDataPtr::StringDataPtr(&v37, pData);
      Scaleform::GFx::AS3::VM::Error::Error(
        &v41,
        (Scaleform::GFx::AS3::VM_vtbl *)0x435,
        (Scaleform::GFx::ASStringNode *)vm,
        v37,
        (Scaleform::GFx::AS3::Value *)v38);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v35,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v36 = v41.Message.pNode;
      --v41.Message.pNode->RefCount;
      if ( !v36->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      goto LABEL_37;
    default:
LABEL_37:
      v8 = result;
      result->Result = 0;
      break;
  }
  return v8;
}

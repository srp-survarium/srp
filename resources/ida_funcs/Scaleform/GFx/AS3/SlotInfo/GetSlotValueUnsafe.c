Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::ASStringNode *obj)
{
  int v4; // esi
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  int v6; // eax
  char v7; // cl
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::ASStringNode *v9; // edx
  unsigned int v10; // ecx
  Scaleform::GFx::ASStringNode *v11; // edx
  unsigned int v12; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::VM::ErrorID ID; // edx
  Scaleform::GFx::ASStringNode *v15; // esi
  Scaleform::GFx::ASStringNode *v16; // edx
  Scaleform::GFx::ASString *ConstString; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::Object *v19; // edi
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Object *v21; // edi
  Scaleform::GFx::AS3::VTable *v22; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::Value *v24; // eax
  const Scaleform::GFx::AS3::VM::Error *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::AS3::VM *v27; // esi
  const Scaleform::GFx::AS3::VM::Error *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::AS3::VM::Error v30; // [esp+8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v31; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value getter; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value v33; // [esp+28h] [ebp-10h] BYREF

  v4 = (32 * *(_DWORD *)this) >> 15;
  switch ( (int)(*(_DWORD *)this << 22) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)obj[5].pLower + v4);
      v5 = result;
      result->Result = 1;
      break;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (const Scaleform::GFx::AS3::Value *)((char *)obj + v4));
      v5 = result;
      result->Result = 1;
      break;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe((Scaleform::GFx::AS3::STPtr *)((char *)obj + v4), value);
      v5 = result;
      result->Result = 1;
      break;
    case 4:
      if ( !(Scaleform::GFx::ASStringNode *)((char *)obj + v4) )
        goto LABEL_23;
      v6 = *(int *)((char *)&obj->pData + v4);
      if ( v6 && (*(_DWORD *)(*(_DWORD *)(v6 + 20) + 56) & 0x20) != 0 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, *(Scaleform::GFx::AS3::Class **)((char *)&obj->pData + v4));
        v5 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, *(Scaleform::GFx::AS3::Object **)((char *)&obj->pData + v4));
        v5 = result;
        result->Result = 1;
      }
      break;
    case 5:
      v7 = *((_BYTE *)&obj->pData + v4);
      value->Flags = value->Flags & 0xFFFFFFE0 | 1;
      pNode = v30.Message.pNode;
      LOBYTE(v30.ID) = v7;
      value->value.VS._1.VInt = v30.ID;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      v5 = result;
      result->Result = 1;
      break;
    case 6:
      v9 = v31.Message.pNode;
      v10 = value->Flags & 0xFFFFFFE0 | 2;
      value->value.VS._1.VInt = *(int *)((char *)&obj->pData + v4);
      value->Flags = v10;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v9;
      v5 = result;
      result->Result = 1;
      break;
    case 7:
      v11 = v31.Message.pNode;
      v12 = value->Flags & 0xFFFFFFE0 | 3;
      value->value.VS._1.VInt = *(int *)((char *)&obj->pData + v4);
      value->Flags = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11;
      v5 = result;
      result->Result = 1;
      break;
    case 8:
      Flags = value->Flags;
      v30 = *(Scaleform::GFx::AS3::VM::Error *)((char *)&obj->pData + v4);
      ID = v30.ID;
      value->Flags = Flags & 0xFFFFFFE0 | 4;
      *(_QWORD *)&value->value.VNumber = __PAIR64__((unsigned int)v30.Message.pNode, ID);
      v5 = result;
      result->Result = 1;
      break;
    case 9:
      v15 = *(Scaleform::GFx::ASStringNode **)((char *)&obj->pData + v4);
      if ( v15 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v15);
      }
      else
      {
        v16 = v31.Message.pNode;
        value->Flags = value->Flags & 0xFFFFFFE0 | 0xC;
        value->value.VS._1.VInt = 0;
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v16;
      }
      v5 = result;
      result->Result = 1;
      break;
    case 10:
      ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                      *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> **)(*(_DWORD *)(obj->Size + 64) + 12),
                      (Scaleform::GFx::ASString *)&obj,
                      *(char **)((char *)&obj->pData + v4));
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, ConstString);
      v18 = obj;
      --obj->RefCount;
      if ( v18->RefCount )
        goto LABEL_23;
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v5 = result;
      result->Result = 1;
      break;
    case 11:
      v19 = (Scaleform::GFx::AS3::Object *)obj;
      VT = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)obj->Size);
      Scaleform::GFx::AS3::VTable::GetMethod(VT, value, (Scaleform::GFx::AS3::AbsoluteIndex)v4, v19, 0);
      v5 = result;
      result->Result = 1;
      break;
    case 12:
    case 14:
      v21 = (Scaleform::GFx::AS3::Object *)obj;
      v22 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)obj->Size);
      Scaleform::GFx::AS3::VTable::GetValue(v22, &getter, (Scaleform::GFx::AS3::AbsoluteIndex)v4);
      pVM = v21->pTraits.pObject->pVM;
      if ( Scaleform::GFx::AS3::Value::IsCallable(&getter) )
      {
        Scaleform::GFx::AS3::Value::Value(&v33, v21);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pVM, &getter, v24, value, 0, 0, 0);
        Scaleform::GFx::AS3::Value::~Value(&v33);
        Scaleform::GFx::AS3::Value::~Value(&getter);
LABEL_23:
        v5 = result;
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v30, eCallOfNonFunctionError, pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          pVM,
          v25,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v26 = v30.Message.pNode;
        --v30.Message.pNode->RefCount;
        if ( !v26->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&getter);
        v5 = result;
      }
      break;
    case 13:
      v27 = *(Scaleform::GFx::AS3::VM **)(obj->Size + 64);
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eWriteOnlyError, v27);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v27,
        v28,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v29 = v31.Message.pNode;
      --v31.Message.pNode->RefCount;
      if ( !v29->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      goto LABEL_29;
    default:
LABEL_29:
      v5 = result;
      result->Result = 0;
      break;
  }
  return v5;
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
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int v14; // edx
  Scaleform::GFx::ASStringNode *v15; // edx
  unsigned int v16; // ecx
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
  const Scaleform::GFx::AS3::VM::Error *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::AS3::Value getter; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v37; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v38; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v39; // [esp+2Ch] [ebp-10h] BYREF

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
      v11 = *((_BYTE *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7);
      value->Flags = value->Flags & 0xFFFFFFE0 | 1;
      v12.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)getter.Bonus;
      LOBYTE(getter.Flags) = v11;
      value->value.VS._1.VInt = getter.Flags;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v12.pWeakProxy;
      v8 = result;
      result->Result = 1;
      break;
    case 6:
      pNode = v38.Message.pNode;
      v14 = value->Flags & 0xFFFFFFE0 | 2;
      value->value.VS._1.VInt = *(int *)((char *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7);
      value->Flags = v14;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      v8 = result;
      result->Result = 1;
      break;
    case 7:
      v15 = v38.Message.pNode;
      v16 = value->Flags & 0xFFFFFFE0 | 3;
      value->value.VS._1.VInt = *(int *)((char *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7);
      value->Flags = v16;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15;
      v8 = result;
      result->Result = 1;
      break;
    case 8:
      Flags = value->Flags;
      *(double *)&getter.Flags = *(double *)((char *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7);
      v18 = getter.Flags;
      value->Flags = Flags & 0xFFFFFFE0 | 4;
      v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)getter.Bonus;
      value->value.VS._1.VInt = v18;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v19.pWeakProxy;
      v8 = result;
      result->Result = 1;
      break;
    case 9:
      v20 = *(Scaleform::GFx::ASStringNode **)((char *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7);
      if ( v20 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v20);
      }
      else
      {
        v21 = value->Flags & 0xFFFFFFE0 | 0xC;
        value->value.VS._1.VInt = 0;
        v22 = v38.Message.pNode;
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
                      *(char **)((char *)&_this->pLower->$F13D7A6F437FF8C99BCD83307E8BDE98::pData + v7));
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
        v28 = Scaleform::GFx::AS3::VTable::GetValue(v25, &v39, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v28);
        Scaleform::GFx::AS3::Value::~Value(&v39);
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
        Scaleform::GFx::AS3::VM::Error::Error(&v37, eCallOfNonFunctionError, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(
          vm,
          v32,
          (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
        v33 = v37.Message.pNode;
        --v37.Message.pNode->RefCount;
        if ( !v33->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v33);
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&getter);
        v8 = result;
      }
      break;
    case 13:
      Scaleform::GFx::AS3::VM::Error::Error(&v38, eWriteOnlyError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        vm,
        v34,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v35 = v38.Message.pNode;
      --v38.Message.pNode->RefCount;
      if ( !v35->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      goto LABEL_37;
    default:
LABEL_37:
      v8 = result;
      result->Result = 0;
      break;
  }
  return v8;
}

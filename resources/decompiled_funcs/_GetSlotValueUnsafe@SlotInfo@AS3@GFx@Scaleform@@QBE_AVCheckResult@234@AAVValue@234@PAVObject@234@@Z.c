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

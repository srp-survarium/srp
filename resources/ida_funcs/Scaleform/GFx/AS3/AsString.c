const char *__cdecl Scaleform::GFx::AS3::AsString(Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  const char *result; // eax

  switch ( kind )
  {
    case NS_Public:
      result = "public";
      break;
    case NS_Protected:
      result = "protected";
      break;
    case NS_StaticProtected:
      result = "static protected";
      break;
    case NS_Private:
      result = "private";
      break;
    case NS_Explicit:
      result = "explicit";
      break;
    case NS_PackageInternal:
      result = "package internal";
      break;
    default:
      result = "Invalid Namespace type";
      break;
  }
  return result;
}


Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS3::AsString(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASStringNode *value,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::AS3::Value *v3; // ecx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v6; // esi
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::String *v9; // eax
  Scaleform::String *v10; // eax
  Scaleform::GFx::AS3::Value::V1U v11; // ecx
  Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // ecx
  Scaleform::GFx::AS3::Value::V1U v17; // ecx
  Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASString *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // ecx
  Scaleform::GFx::AS3::Value::V1U pLower; // esi
  char *v24; // eax
  int v25; // eax
  Scaleform::GFx::ASStringNode *v26; // esi
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  const Scaleform::GFx::ASString *v29; // [esp-Ch] [ebp-34h]
  const Scaleform::GFx::ASString *v30; // [esp-Ch] [ebp-34h]
  Scaleform::GFx::ASString r; // [esp+4h] [ebp-24h] BYREF
  Scaleform::String v32; // [esp+8h] [ebp-20h] BYREF
  Scaleform::String v33; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString v34; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v35; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::ASStringNode *v36; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::ASString v37; // [esp+1Ch] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v38; // [esp+20h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v39; // [esp+24h] [ebp-4h] BYREF

  v3 = (Scaleform::GFx::AS3::Value *)value;
  switch ( (int)value->pData & 0x1F )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xA:
      pStringManager = sm->pStringManager;
      r.pNode = &pStringManager->EmptyStringNode;
      ++pStringManager->EmptyStringNode.RefCount;
      Scaleform::GFx::AS3::Value::Convert2String(v3, (Scaleform::GFx::AS3::CheckResult *)&value, &r);
      pNode = r.pNode;
      v6 = result;
      result->pNode = r.pNode;
      ++pNode->RefCount;
      v7 = r.pNode;
      goto LABEL_3;
    case 5:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        result,
        "thunk");
      return result;
    case 7:
      value = value->pLower;
      v9 = Scaleform::AsString<long>(&v33, (int *)&value);
      v10 = Scaleform::operator+(&v32, "VTable ind: ", v9);
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(sm, result, v10);
      Scaleform::String::~String(&v32);
      Scaleform::String::~String(&v33);
      return result;
    case 0xB:
      pLower = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      v24 = (char *)Scaleform::GFx::AS3::AsString((Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*(_DWORD *)(pLower.VInt + 20) << 28) >> 28));
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        (Scaleform::GFx::ASString *)&value,
        v24);
      v25 = *(_DWORD *)(pLower.VInt + 28);
      v26 = (Scaleform::GFx::ASStringNode *)(pLower.VInt + 28);
      if ( *(_DWORD *)(v25 + 20) )
      {
        Scaleform::GFx::ASString::operator+=((Scaleform::GFx::ASString *)&value, (char *)&stru_95AF78);
        Scaleform::GFx::ASString::Append((Scaleform::GFx::ASString *)&value, v26);
      }
      v27 = value;
      v6 = result;
      result->pNode = value;
      ++v27->RefCount;
      v7 = value;
      goto LABEL_3;
    case 0xC:
      v11 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      if ( !v11.VInt )
      {
        v16 = sm->Builtins[2].pNode;
        v8 = result;
        result->pNode = v16;
        ++v16->RefCount;
        return v8;
      }
      v6 = result;
      v29 = (const Scaleform::GFx::ASString *)(*(int (__thiscall **)(_DWORD, Scaleform::GFx::ASStringNode **))(**(_DWORD **)(v11.VInt + 20) + 16))(
                                                *(_DWORD *)(v11.VInt + 20),
                                                &v36);
      v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              sm,
              &v35,
              "[object ");
      v13 = Scaleform::GFx::ASString::operator+(v12, &v34, v29);
      Scaleform::GFx::ASString::operator+(v13, result, "]");
      v14 = v34.pNode;
      --v34.pNode->RefCount;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v15 = v35.pNode;
      --v35.pNode->RefCount;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v7 = v36;
      goto LABEL_3;
    case 0xD:
      v17 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      if ( v17.VInt )
      {
        v6 = result;
        v30 = (const Scaleform::GFx::ASString *)(*(int (__thiscall **)(_DWORD, Scaleform::GFx::ASStringNode **))(**(_DWORD **)(v17.VInt + 20) + 16))(
                                                  *(_DWORD *)(v17.VInt + 20),
                                                  &v39);
        v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                sm,
                &v38,
                "[class ");
        v19 = Scaleform::GFx::ASString::operator+(v18, &v37, v30);
        Scaleform::GFx::ASString::operator+(v19, result, "]");
        v20 = v37.pNode;
        --v37.pNode->RefCount;
        if ( !v20->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        v21 = v38.pNode;
        --v38.pNode->RefCount;
        if ( !v21->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v7 = v39;
LABEL_3:
        if ( !--v7->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        return v6;
      }
      else
      {
        v22 = sm->Builtins[2].pNode;
        v8 = result;
        result->pNode = v22;
        ++v22->RefCount;
      }
      return v8;
    case 0xE:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        result,
        "function Function() {}");
      return result;
    case 0xF:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        result,
        "thunk function");
      return result;
    case 0x10:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        result,
        "ThunkClosure");
      return result;
    case 0x11:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        sm,
        result,
        "VTableIndClosure");
      return result;
    default:
      p_EmptyStringNode = &sm->pStringManager->EmptyStringNode;
      v8 = result;
      result->pNode = p_EmptyStringNode;
      ++p_EmptyStringNode->RefCount;
      return v8;
  }
}

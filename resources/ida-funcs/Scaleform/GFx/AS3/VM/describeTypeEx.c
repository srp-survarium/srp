Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VM::describeTypeEx(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASStringNode *value)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  Scaleform::GFx::ASStringNode *v4; // esi
  Scaleform::GFx::ASStringNode *pNode; // ebp
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // ebp
  Scaleform::GFx::ASStringNode *v8; // ebp
  Scaleform::GFx::ASStringNode *v9; // ebp
  Scaleform::GFx::ASStringNode *pLower; // esi
  Scaleform::GFx::ASStringNode *v11; // ebp
  Scaleform::GFx::AS3::Value::V1U v12; // esi
  Scaleform::GFx::ASStringNode *v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // esi
  int v15; // edi
  Scaleform::String::DataDesc *VT; // eax
  Scaleform::GFx::ASStringNode *v17; // ebp
  Scaleform::String v18; // ecx
  int v19; // edi
  Scaleform::String::DataDesc *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ecx
  Scaleform::String v22; // ecx
  Scaleform::GFx::AS3::Value::V1U v23; // esi
  Scaleform::GFx::AS3::Traits_vtbl *OriginationTraits; // edi
  Scaleform::GFx::ASString *v25; // eax
  Scaleform::GFx::ASString *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::AS3::Value::V1U v30; // esi
  Scaleform::GFx::ASStringNode *v31; // ebp
  Scaleform::GFx::AS3::Value::V1U v32; // esi
  Scaleform::GFx::ASString *NameSkipVectorNS; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::AS3::Value::V1U v35; // esi
  char *v36; // eax
  int v37; // eax
  Scaleform::GFx::ASStringNode *v38; // esi
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // ecx
  Scaleform::GFx::ASStringNode *v43; // ebp
  Scaleform::GFx::ASString v44; // [esp-Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString v45; // [esp-8h] [ebp-28h] BYREF
  Scaleform::String v46; // [esp-4h] [ebp-24h]
  Scaleform::GFx::ASStringNode *v47; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASStringNode *v48; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v49; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v50; // [esp+1Ch] [ebp-4h] BYREF

  StringManagerRef = this->StringManagerRef;
  v4 = value;
  switch ( (int)value->pData & 0x1F )
  {
    case 0:
      pNode = StringManagerRef->Builtins[1].pNode;
      v6 = result;
      result->pNode = pNode;
      ++pNode->RefCount;
      break;
    case 1:
      v7 = StringManagerRef->Builtins[6].pNode;
      v6 = result;
      result->pNode = v7;
      ++v7->RefCount;
      break;
    case 2:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        StringManagerRef,
        result,
        "int");
      v6 = result;
      break;
    case 3:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        StringManagerRef,
        result,
        "uint");
      v6 = result;
      break;
    case 4:
      v8 = StringManagerRef->Builtins[7].pNode;
      v6 = result;
      result->pNode = v8;
      ++v8->RefCount;
      break;
    case 5:
      pLower = value->pLower;
      v11 = StringManagerRef->Builtins[0].pNode;
      v46.pData = 0;
      v45.pNode = pLower;
      v44.pNode = v11;
      ++v11->RefCount;
      Scaleform::GFx::AS3::GetThunkName(result, v44, (const Scaleform::GFx::AS3::ThunkInfo *)v45.pNode, v46);
      v6 = result;
      break;
    case 7:
      v15 = (int)value->pLower;
      VT = (Scaleform::String::DataDesc *)Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)value->RefCount);
      v17 = StringManagerRef->Builtins[0].pNode;
      v46.pData = VT;
      v45.pNode = v17;
      ++v17->RefCount;
      LOBYTE(v18.pData) = 0;
      Scaleform::GFx::AS3::GetVTableIndName(v15, v18, result, v45, (Scaleform::GFx::AS3::VTable *)v46.pData);
      v6 = result;
      break;
    case 0xA:
      v6 = result;
      if ( value->pLower )
        v9 = StringManagerRef->Builtins[8].pNode;
      else
        v9 = StringManagerRef->Builtins[2].pNode;
      result->pNode = v9;
      ++v9->RefCount;
      break;
    case 0xB:
      v35 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      v36 = (char *)Scaleform::GFx::AS3::AsString((Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*(_DWORD *)(v35.VInt + 20) << 28) >> 28));
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        StringManagerRef,
        (Scaleform::GFx::ASString *)&value,
        v36);
      v37 = *(_DWORD *)(v35.VInt + 28);
      v38 = (Scaleform::GFx::ASStringNode *)(v35.VInt + 28);
      if ( *(_DWORD *)(v37 + 20) )
      {
        Scaleform::GFx::ASString::operator+=((Scaleform::GFx::ASString *)&value, (const __m128i *)" ");
        Scaleform::GFx::ASString::Append((Scaleform::GFx::ASString *)&value, v38);
      }
      v39 = value;
      result->pNode = value;
      ++v39->RefCount;
      v40 = value;
      --value->RefCount;
      if ( !v40->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      v6 = result;
      break;
    case 0xC:
      v30 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      if ( !v30.VInt )
        goto LABEL_24;
      Scaleform::GFx::AS3::GetNameSkipVectorNS(*(Scaleform::GFx::AS3::Traits_vtbl **)(v30.VInt + 20), (int)result);
      v6 = result;
      break;
    case 0xD:
      v32 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      if ( v32.VInt )
      {
        NameSkipVectorNS = Scaleform::GFx::AS3::GetNameSkipVectorNS(
                             *(Scaleform::GFx::AS3::Traits_vtbl **)(v32.VInt + 20),
                             (int)&v50);
        Scaleform::GFx::ASString::AppendChar(NameSkipVectorNS, result, 0x24u);
        v34 = v50;
        --v50->RefCount;
        if ( !v34->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
        v6 = result;
      }
      else
      {
LABEL_24:
        v31 = StringManagerRef->Builtins[2].pNode;
        v6 = result;
        result->pNode = v31;
        ++v31->RefCount;
      }
      break;
    case 0xE:
      v23 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      OriginationTraits = (Scaleform::GFx::AS3::Traits_vtbl *)Scaleform::GFx::AS3::InstanceTraits::Function::GetOriginationTraits(*(Scaleform::GFx::AS3::InstanceTraits::Function **)(v23.VInt + 20));
      v46.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::AS3::Object::GetName(v23.VObj, &v49);
      v25 = Scaleform::GFx::AS3::GetNameSkipVectorNS(OriginationTraits, (int)&v48);
      v26 = Scaleform::GFx::ASString::operator+(v25, (Scaleform::GFx::ASString *)&v47, (const __m128i *)"::");
      Scaleform::GFx::ASString::operator+(v26, result, (const Scaleform::GFx::ASString *)v46.pData);
      v27 = v47;
      --v47->RefCount;
      if ( !v27->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      v28 = v48;
      --v48->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      v29 = v49.pNode;
      --v49.pNode->RefCount;
      if ( !v29->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      v6 = result;
      break;
    case 0xF:
      v12 = (Scaleform::GFx::AS3::Value::V1U)value->pLower;
      v13 = *(Scaleform::GFx::ASStringNode **)(v12.VInt + 40);
      v14 = *(Scaleform::GFx::ASStringNode **)(v12.VInt + 36);
      v46.pData = 0;
      v45.pNode = v14;
      v44.pNode = v13;
      Scaleform::GFx::AS3::GetNameSkipVectorNS((Scaleform::GFx::AS3::Traits_vtbl *)v13, (int)&v44);
      Scaleform::GFx::AS3::GetThunkName(result, v44, (const Scaleform::GFx::AS3::ThunkInfo *)v45.pNode, v46);
      v6 = result;
      break;
    case 0x10:
      v41 = value->pLower;
      v42 = *(Scaleform::GFx::ASStringNode **)(value->RefCount + 20);
      v46.pData = (Scaleform::String::DataDesc *)1;
      v45.pNode = v41;
      v44.pNode = v42;
      Scaleform::GFx::AS3::GetNameSkipVectorNS((Scaleform::GFx::AS3::Traits_vtbl *)v42, (int)&v44);
      Scaleform::GFx::AS3::GetThunkName(result, v44, (const Scaleform::GFx::AS3::ThunkInfo *)v45.pNode, v46);
      v6 = result;
      break;
    case 0x11:
      v19 = (int)value->pLower;
      v20 = (Scaleform::String::DataDesc *)Scaleform::GFx::AS3::Traits::GetVT(*(Scaleform::GFx::AS3::Traits **)(value->RefCount + 20));
      v21 = *(Scaleform::GFx::ASStringNode **)(v4->RefCount + 20);
      v46.pData = v20;
      v45.pNode = v21;
      Scaleform::GFx::AS3::GetNameSkipVectorNS((Scaleform::GFx::AS3::Traits_vtbl *)v21, (int)&v45);
      LOBYTE(v22.pData) = 1;
      Scaleform::GFx::AS3::GetVTableIndName(v19, v22, result, v45, (Scaleform::GFx::AS3::VTable *)v46.pData);
      v6 = result;
      break;
    default:
      v43 = StringManagerRef->Builtins[0].pNode;
      v6 = result;
      result->pNode = v43;
      ++v43->RefCount;
      break;
  }
  return v6;
}

Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::XMLSupportImpl::ToXMLString(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v4; // esi
  unsigned int v5; // eax
  bool v6; // al
  Scaleform::GFx::AS3::VM *v7; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS3::CheckResult *v10; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *pData; // eax
  Scaleform::GFx::AS3::Value *StringNode; // edi
  bool v15; // zf
  _DWORD *VInt; // edi
  int v17; // eax
  char *v18; // eax
  Scaleform::GFx::AS3::Value *v19; // edi
  Scaleform::GFx::ASStringNode *v20; // ecx
  const Scaleform::GFx::ASString *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  char *v24; // eax
  Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::AS3::VM::ErrorID ID; // eax
  Scaleform::GFx::ASString v27; // [esp+4h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString v28; // [esp+8h] [ebp-28h] BYREF
  Scaleform::GFx::ASString v29; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS3::VM::Error v30; // [esp+10h] [ebp-20h] BYREF
  Scaleform::StringBuffer buf; // [esp+18h] [ebp-18h] BYREF

  v30.ID = 0;
  v4 = v;
  v5 = v->Flags & 0x1F;
  if ( v5 && (v5 - 12 > 3 || v->value.VS._1.VInt) )
  {
    StringManagerRef = vm->StringManagerRef;
    if ( (v->Flags & 0x1F) != 0 )
    {
      if ( (v->Flags & 0x1F) <= 4 )
      {
        Scaleform::GFx::AS3::Value::ToStringValue(v, result, (Scaleform::GFx::ASStringNode *)StringManagerRef);
        return result;
      }
      if ( v5 == 10 )
      {
        Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
        v27.pNode = v4->value.VS._1.VStr;
        ++v27.pNode->RefCount;
        Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, &v27);
        pNode = v27.pNode;
        --v27.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        pData = buf.pData;
        if ( !buf.pData )
          pData = (char *)&::buf;
        StringNode = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                     StringManagerRef->pStringManager,
                                                     pData,
                                                     buf.Size);
        ++StringNode->value.VS._2.VObj;
        v = StringNode;
        Scaleform::GFx::AS3::Value::Assign(v4, (const Scaleform::GFx::ASString *)&v);
        v15 = StringNode->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
      }
    }
    if ( (v4->Flags & 0x1F) - 12 <= 3
      && (VInt = (_DWORD *)v4->value.VS._1.VInt) != 0
      && (v17 = VInt[5], *(_DWORD *)(v17 + 60) == 13)
      && (*(_DWORD *)(v17 + 56) & 0x20) == 0 )
    {
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      (*(void (__thiscall **)(_DWORD *, Scaleform::StringBuffer *, _DWORD, _DWORD, _DWORD))(*VInt + 88))(
        VInt,
        &buf,
        0,
        0,
        0);
      v18 = buf.pData;
      if ( !buf.pData )
        v18 = (char *)&::buf;
      v19 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                            StringManagerRef->pStringManager,
                                            v18,
                                            buf.Size);
      ++v19->value.VS._2.VObj;
      v = v19;
      Scaleform::GFx::AS3::Value::Assign(v4, (const Scaleform::GFx::ASString *)&v);
      v15 = v19->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1;
      if ( !v15 )
        goto LABEL_41;
      v20 = (Scaleform::GFx::ASStringNode *)v19;
    }
    else
    {
      if ( Scaleform::GFx::AS3::IsXMLListObject(v4) )
      {
        v21 = Scaleform::GFx::AS3::Instances::fl::XMLList::AS3toXMLString(
                (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->value.VS._1.VInt,
                &v29);
        Scaleform::GFx::AS3::Value::Assign(v4, v21);
        v22 = v29.pNode;
        --v29.pNode->RefCount;
        if ( !v22->RefCount )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          v10 = result;
          result->Result = 1;
          return v10;
        }
        goto LABEL_42;
      }
      if ( !Scaleform::GFx::AS3::Value::ToPrimitiveValue(v4, (Scaleform::GFx::AS3::CheckResult *)&vm)->Result
        || !Scaleform::GFx::AS3::Value::IsPrimitive(v4) )
      {
        v10 = result;
        result->Result = 0;
        return v10;
      }
      Scaleform::GFx::AS3::Value::ToStringValue(
        v4,
        (Scaleform::GFx::AS3::CheckResult *)&v,
        (Scaleform::GFx::ASStringNode *)StringManagerRef);
      Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
      v28.pNode = v4->value.VS._1.VStr;
      ++v28.pNode->RefCount;
      Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, &v28);
      v23 = v28.pNode;
      --v28.pNode->RefCount;
      if ( !v23->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      v24 = buf.pData;
      if ( !buf.pData )
        v24 = (char *)&::buf;
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                 StringManagerRef,
                 (Scaleform::GFx::ASString *)&v30,
                 v24,
                 buf.Size);
      Scaleform::GFx::AS3::Value::Assign(v4, String);
      ID = v30.ID;
      --*(_DWORD *)(v30.ID + 12);
      v20 = (Scaleform::GFx::ASStringNode *)ID;
      if ( *(_DWORD *)(ID + 12) )
      {
LABEL_41:
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
LABEL_42:
        v10 = result;
        result->Result = 1;
        return v10;
      }
    }
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    goto LABEL_41;
  }
  v6 = v5 - 12 <= 3 && v->value.VS._1.VInt == 0;
  v7 = vm;
  Scaleform::GFx::AS3::VM::Error::Error(&v30, (Scaleform::GFx::AS3::VM::ErrorID)(!v6 + 1009), vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v7,
    v8,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  v9 = v30.Message.pNode;
  --v30.Message.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v10 = result;
  result->Result = 0;
  return v10;
}

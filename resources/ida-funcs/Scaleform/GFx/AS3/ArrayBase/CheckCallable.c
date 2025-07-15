Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCallable(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *callback)
{
  unsigned int v3; // eax
  bool v4; // bl
  Scaleform::GFx::AS3::VM *VMRef; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v8; // eax
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::CheckResult *v12; // eax
  Scaleform::StringDataPtr v13; // [esp-10h] [ebp-24h]
  Scaleform::StringDataPtr v14; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v15; // [esp+Ch] [ebp-8h] BYREF

  v3 = callback->Flags & 0x1F;
  v4 = 1;
  if ( v3 <= 0xF && v3 != 14 && v3 != 5 && v3 != 15 && v3 != 6 && v3 != 7 && v3 != 12 && v3 != 13 )
  {
    VMRef = this->VMRef;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, callback);
    v14.pStr = "callable";
    v14.Size = 8;
    pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&callback)->pNode->pData;
    v13.pStr = pData;
    if ( pData )
      v8 = strlen(pData);
    else
      v8 = 0;
    v13.Size = v8;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eCheckTypeFailedError, (Scaleform::String)VMRef, v13, v14);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v9);
    pNode = v15.Message.pNode;
    --v15.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v11 = (Scaleform::GFx::ASStringNode *)callback;
    --callback->value.VS._2.VObj;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v4 = 0;
  }
  v12 = result;
  result->Result = v4;
  return v12;
}

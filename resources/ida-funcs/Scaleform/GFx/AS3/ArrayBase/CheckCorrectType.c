Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // edi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const char *pData; // eax
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::CheckResult *v13; // eax
  Scaleform::StringDataPtr v14; // [esp-10h] [ebp-24h]
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+Ch] [ebp-8h] BYREF

  v5 = tr;
  if ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(this, (Scaleform::GFx::AS3::CheckResult *)&tr, argc, argv, tr)->Result )
  {
    v13 = result;
    result->Result = 1;
  }
  else
  {
    VMRef = this->VMRef;
    pData = v5->GetName(v5, (Scaleform::GFx::ASString *)&tr)->pNode->pData;
    v15.pStr = pData;
    if ( pData )
      v9 = strlen(pData);
    else
      v9 = 0;
    v15.Size = v9;
    v14.pStr = "arguments";
    v14.Size = 9;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eCheckTypeFailedError, (Scaleform::String)VMRef, v14, v15);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v10);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = (Scaleform::GFx::ASStringNode *)tr;
    --tr->pPrev;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v13 = result;
    result->Result = 0;
  }
  return v13;
}

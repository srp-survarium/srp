Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::ASStringNode *coerced)
{
  const Scaleform::GFx::AS3::Value *v5; // ebp
  Scaleform::GFx::AS3::VM *VMRef; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // ebp
  const char *pData; // eax
  const char *v10; // eax
  unsigned int v11; // eax
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::AS3::CheckResult *v15; // eax
  Scaleform::StringDataPtr v16; // [esp-10h] [ebp-28h]
  Scaleform::StringDataPtr v17; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v18; // [esp+10h] [ebp-8h] BYREF

  v5 = v;
  if ( tr->Coerce(tr, v, (Scaleform::GFx::AS3::Value *)coerced) )
  {
    v15 = result;
    result->Result = 1;
  }
  else
  {
    VMRef = this->VMRef;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v5);
    pData = tr->GetName(tr, &coerced)->pNode->pData;
    v17.Size = (unsigned int)pData;
    if ( pData )
      strlen(pData);
    v17.pStr = (const char *)&v;
    v10 = **(const char ***)((int (__thiscall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->GetName)(ValueTraits);
    v16.pStr = v10;
    if ( v10 )
      v11 = strlen(v10);
    else
      v11 = 0;
    v16.Size = v11;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eCheckTypeFailedError, (Scaleform::String)VMRef, v16, v17);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v12);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !--tr->pPrev )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)tr);
    v14 = coerced;
    --coerced->RefCount;
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = result;
    result->Result = 0;
  }
  return v15;
}

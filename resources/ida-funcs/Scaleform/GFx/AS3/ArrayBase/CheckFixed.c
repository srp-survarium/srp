Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckFixed(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  bool v3; // zf
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  v3 = !this->Fixed;
  if ( this->Fixed )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eVectorFixedError, VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v5);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v3 = !this->Fixed;
  }
  v7 = result;
  result->Result = v3;
  return v7;
}

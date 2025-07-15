Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckFixed(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  bool v3; // zf
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::StringDataPtr v7; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v8; // [esp+4h] [ebp-8h] BYREF

  v3 = !this->Fixed;
  if ( this->Fixed )
  {
    v7.pStr = "Vector";
    v7.Size = 6;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eVectorFixedError, (Scaleform::String)this->VMRef, v7);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->VMRef, v4);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v3 = !this->Fixed;
  }
  v6 = result;
  result->Result = v3;
  return v6;
}

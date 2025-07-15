Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *const argv,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(this, (Scaleform::GFx::AS3::CheckResult *)&tr, argc, argv, tr)->Result )
  {
    v9 = result;
    result->Result = 1;
  }
  else
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eCheckTypeFailedError, VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v7);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v9 = result;
    result->Result = 0;
  }
  return v9;
}

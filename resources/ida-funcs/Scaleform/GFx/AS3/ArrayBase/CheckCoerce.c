Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::Value *coerced)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  if ( tr->Coerce(tr, v, coerced) )
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

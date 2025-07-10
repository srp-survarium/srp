Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::ArrayBase::CheckCallable(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Value *callback)
{
  unsigned int v3; // eax
  bool v4; // dl
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+0h] [ebp-8h] BYREF

  v3 = callback->Flags & 0x1F;
  v4 = 1;
  if ( v3 <= 0xF && v3 != 14 && v3 != 5 && v3 != 15 && v3 != 6 && v3 != 7 && v3 != 12 && v3 != 13 )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eCheckTypeFailedError, VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v6);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v4 = 0;
  }
  v8 = result;
  result->Result = v4;
  return v8;
}

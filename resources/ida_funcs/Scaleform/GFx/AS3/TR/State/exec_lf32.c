void __thiscall Scaleform::GFx::AS3::TR::State::exec_lf32(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v2; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v4; // [esp+4h] [ebp-8h] BYREF

  VMRef = this->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v4, eNotImplementedError, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    VMRef,
    v2,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v4.Message.pNode;
  --v4.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

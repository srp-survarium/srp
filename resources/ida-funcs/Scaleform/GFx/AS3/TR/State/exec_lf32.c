void __thiscall Scaleform::GFx::AS3::TR::State::exec_lf32(Scaleform::GFx::AS3::TR::State *this)
{
  const Scaleform::GFx::AS3::VM::Error *v2; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v4; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v5; // [esp+4h] [ebp-8h] BYREF

  v4.pStr = "exec_lf32";
  v4.Size = 9;
  Scaleform::GFx::AS3::VM::Error::Error(
    &v5,
    eNotImplementedError,
    (Scaleform::String)this->pTracer->CF->pFile->VMRef,
    v4);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTracer->CF->pFile->VMRef,
    v2,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v5.Message.pNode;
  --v5.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

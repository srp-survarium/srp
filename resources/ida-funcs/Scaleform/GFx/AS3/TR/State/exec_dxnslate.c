void __thiscall Scaleform::GFx::AS3::TR::State::exec_dxnslate(Scaleform::GFx::AS3::TR::State *this)
{
  const Scaleform::GFx::AS3::VM::Error *v2; // eax
  const Scaleform::GFx::AS3::VM::Error *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::StringDataPtr v5; // [esp-8h] [ebp-14h]
  Scaleform::StringDataPtr v6; // [esp-8h] [ebp-14h]
  Scaleform::GFx::AS3::VM::Error v7; // [esp+4h] [ebp-8h] BYREF

  if ( this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->OpStack.Data,
      this->OpStack.Data.Size - 1);
    if ( (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags
        & 0x40) != 0 )
      return;
    v6.pStr = "does not have the SETS_DXNS flag set";
    v6.Size = 36;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v7,
      eNotImplementedError,
      (Scaleform::String)this->pTracer->CF->pFile->VMRef,
      v6);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v3,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  else
  {
    v5.pStr = "dxnslate";
    v5.Size = 8;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v7,
      eNotImplementedError,
      (Scaleform::String)this->pTracer->CF->pFile->VMRef,
      v5);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v2,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  pNode = v7.Message.pNode;
  --v7.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

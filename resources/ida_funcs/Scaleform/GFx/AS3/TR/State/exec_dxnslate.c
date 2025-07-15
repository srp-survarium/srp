void __thiscall Scaleform::GFx::AS3::TR::State::exec_dxnslate(Scaleform::GFx::AS3::TR::State *this)
{
  const Scaleform::GFx::AS3::CallFrame *CF; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v6; // [esp+4h] [ebp-8h] BYREF

  if ( this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->OpStack.Data,
      this->OpStack.Data.Size - 1);
    if ( (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags
        & 0x40) != 0 )
      return;
    CF = this->pTracer->CF;
  }
  else
  {
    CF = this->pTracer->CF;
  }
  VMRef = CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v6, eNotImplementedError, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    VMRef,
    v4,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v6.Message.pNode;
  --v6.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

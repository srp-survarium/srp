void __thiscall Scaleform::GFx::AS3::VM::exec_getouterscope(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf,
        unsigned int scope_index)
{
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // ecx
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v7; // eax
  bool v8; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::VM::Error v10; // [esp+4h] [ebp-8h] BYREF

  pSavedScope = cf->pSavedScope;
  if ( scope_index < pSavedScope->Data.Size )
  {
    v7 = &pSavedScope->Data.Data[scope_index];
    v8 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
    pCurrent = this->OpStack.pCurrent;
    if ( !v8 )
    {
      pCurrent->Flags = v7->Flags;
      pCurrent->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
      pCurrent->value.VS._1.VInt = v7->value.VS._1.VInt;
      pCurrent->value.VS._2.VObj = v7->value.VS._2.VObj;
      if ( (v7->Flags & 0x1F) > 9 )
      {
        if ( (v7->Flags & 0x200) != 0 )
          ++v7->Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v7);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eParamRangeError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

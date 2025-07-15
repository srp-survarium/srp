void __thiscall Scaleform::GFx::AS3::VM::exec_pushscope(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  int v3; // eax
  bool v4; // al
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int Flags; // edx
  _DWORD *v10; // eax
  Scaleform::GFx::AS3::Value *v11; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::VM::Error v14; // [esp+Ch] [ebp-8h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3 = pCurrent->Flags & 0x1F;
  if ( !v3 || (unsigned int)(v3 - 12) <= 3 && !pCurrent->value.VS._1.VInt )
  {
    v4 = (unsigned int)(v3 - 12) <= 3 && pCurrent->value.VS._1.VInt == 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, (Scaleform::GFx::AS3::VM::ErrorID)(!v4 + 1009), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v5,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    --v14.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->ScopeStack.Data,
    &v);
  Size = this->ScopeStack.Data.Size;
  Data = this->ScopeStack.Data.Data;
  Flags = pCurrent->Flags;
  _mm_prefetch((const char *)pCurrent, 2);
  Size *= 16;
  *(unsigned int *)((char *)&Data[-1].Flags + Size) = Flags;
  v10 = (unsigned int *)((char *)&Data[-1].Flags + Size);
  v10[1] = pCurrent->Bonus.pWeakProxy;
  v10[2] = pCurrent->value.VS._1.VInt;
  v10[3] = pCurrent->value.VS._2.VObj;
  pCurrent->Flags = 0;
  v11 = this->OpStack.pCurrent;
  if ( (v11->Flags & 0x1F) <= 9 )
  {
LABEL_17:
    --this->OpStack.pCurrent;
    return;
  }
  if ( (v11->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    goto LABEL_17;
  }
  pWeakProxy = v11->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  v11->Flags &= 0xFFFFFDE0;
  v11->Bonus.pWeakProxy = 0;
  v11->value.VS._1.VInt = 0;
  v11->value.VS._2.VObj = 0;
  --this->OpStack.pCurrent;
}

void __thiscall Scaleform::GFx::AS3::VM::exec_returnvalue(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].DiscardResult )
  {
    Scaleform::GFx::AS3::VM::Coerce2ReturnType(this, this->OpStack.pCurrent, this->OpStack.pCurrent);
    return;
  }
  pCurrent = this->OpStack.pCurrent;
  if ( (pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_8:
    --this->OpStack.pCurrent;
    return;
  }
  if ( (pCurrent->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    goto LABEL_8;
  }
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  pCurrent->Flags &= 0xFFFFFDE0;
  pCurrent->Bonus.pWeakProxy = 0;
  pCurrent->value.VS._1.VInt = 0;
  pCurrent->value.VS._2.VObj = 0;
  --this->OpStack.pCurrent;
}

int __thiscall Scaleform::GFx::AS3::VM::exec_throw(
        Scaleform::GFx::AS3::VM *this,
        const unsigned int *cp,
        Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  const Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *OpCode; // eax

  p_ExceptionObj = &this->ExceptionObj;
  if ( (this->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (this->ExceptionObj.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_ExceptionObj->Flags &= 0xFFFFFDE0;
      p_ExceptionObj->Bonus.pWeakProxy = 0;
      p_ExceptionObj->value.VS._1.VInt = 0;
      p_ExceptionObj->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
    }
  }
  pCurrent = this->OpStack.pCurrent;
  p_ExceptionObj->Flags = pCurrent->Flags;
  p_ExceptionObj->Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
  p_ExceptionObj->value.VS._1.VInt = pCurrent->value.VS._1.VInt;
  p_ExceptionObj->value.VS._2.VObj = pCurrent->value.VS._2.VObj;
  --this->OpStack.pCurrent;
  OpCode = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(cf->pFile, cf->MBIIndex, cf);
  return Scaleform::GFx::AS3::VM::OnException(this, cp - OpCode->Data.Data, (unsigned int)cf);
}

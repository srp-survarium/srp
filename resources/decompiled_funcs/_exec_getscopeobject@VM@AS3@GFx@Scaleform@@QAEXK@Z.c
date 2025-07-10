void __thiscall Scaleform::GFx::AS3::VM::exec_getscopeobject(Scaleform::GFx::AS3::VM *this, unsigned int index)
{
  Scaleform::GFx::AS3::Value *v3; // ecx
  bool v4; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // eax

  v3 = &this->ScopeStack.Data.Data[index];
  v4 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
  pCurrent = this->OpStack.pCurrent;
  if ( v4 )
  {
    pCurrent->Flags &= ~0x100u;
  }
  else
  {
    pCurrent->Flags = v3->Flags;
    pCurrent->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    pCurrent->value.VS._1.VInt = v3->value.VS._1.VInt;
    pCurrent->value.VS._2.VObj = v3->value.VS._2.VObj;
    if ( (v3->Flags & 0x1F) <= 9 )
    {
LABEL_5:
      this->OpStack.pCurrent->Flags &= ~0x100u;
      return;
    }
    if ( (v3->Flags & 0x200) != 0 )
    {
      ++v3->Bonus.pWeakProxy->RefCount;
      goto LABEL_5;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(v3);
    this->OpStack.pCurrent->Flags &= ~0x100u;
  }
}

bool __thiscall Scaleform::GFx::AS3::Value::MakeStrongRef(Scaleform::GFx::AS3::Value *this)
{
  unsigned int Flags; // ecx
  bool result; // al
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  Flags = this->Flags;
  result = 0;
  if ( (Flags & 0x200) != 0 )
  {
    if ( this->Bonus.pWeakProxy->pObject )
    {
      Scaleform::GFx::AS3::Value::AddRefInternal(this);
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        this->Flags &= ~0x200u;
        this->Bonus.pWeakProxy = 0;
        return 1;
      }
    }
    else
    {
      this->value.VS._1.VInt = 0;
      this->value.VS._2.VObj = 0;
      this->Flags = Flags & 0xFFFFFFE0;
    }
    this->Flags &= ~0x200u;
    this->Bonus.pWeakProxy = 0;
    return 1;
  }
  return result;
}

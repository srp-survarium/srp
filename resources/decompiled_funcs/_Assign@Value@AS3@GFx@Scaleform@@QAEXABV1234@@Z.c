void __thiscall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  unsigned int Flags; // ecx

  if ( other != this )
  {
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
      {
        pWeakProxy = this->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        this->Flags &= 0xFFFFFDE0;
        this->Bonus.pWeakProxy = 0;
        this->value.VS._1.VInt = 0;
        this->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this);
      }
    }
    Flags = other->Flags;
    _mm_prefetch((const char *)other, 2);
    this->Flags = Flags;
    this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
    this->value.VNumber = other->value.VNumber;
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
        ++this->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(this);
    }
  }
}

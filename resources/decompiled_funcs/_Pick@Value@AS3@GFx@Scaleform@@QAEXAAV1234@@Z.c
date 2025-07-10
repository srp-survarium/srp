void __thiscall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  unsigned int Flags; // ecx

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
  this->value = *(Scaleform::GFx::AS3::Value::VU *)&other->value.VNumber;
  other->Flags = 0;
}

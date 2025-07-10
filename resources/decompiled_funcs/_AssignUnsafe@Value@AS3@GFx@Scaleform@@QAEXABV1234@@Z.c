void __thiscall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        const Scaleform::GFx::AS3::Value *other)
{
  unsigned int Flags; // edx

  if ( other != this )
  {
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

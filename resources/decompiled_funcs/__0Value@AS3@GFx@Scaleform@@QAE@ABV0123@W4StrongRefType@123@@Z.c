void __thiscall Scaleform::GFx::AS3::Value::Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Value *other,
        Scaleform::GFx::AS3::StrongRefType __formal)
{
  unsigned int Flags; // eax

  this->Bonus.pWeakProxy = 0;
  Flags = other->Flags;
  _mm_prefetch((const char *)other, 2);
  this->Flags = Flags;
  this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
  this->value = *(Scaleform::GFx::AS3::Value::VU *)&other->value.VNumber;
  if ( (other->Flags & 0x1F) > 9 )
  {
    if ( (other->Flags & 0x200) != 0 )
      ++other->Bonus.pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(other);
  }
  if ( (this->Flags & 0x200) != 0 )
    Scaleform::GFx::AS3::Value::MakeStrongRef(this);
}

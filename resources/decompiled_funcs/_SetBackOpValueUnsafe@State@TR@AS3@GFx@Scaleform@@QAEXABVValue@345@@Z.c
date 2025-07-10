void __thiscall Scaleform::GFx::AS3::TR::State::SetBackOpValueUnsafe(
        Scaleform::GFx::AS3::TR::State *this,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v2; // ecx
  unsigned int Flags; // edx

  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( v != v2 )
  {
    Flags = v->Flags;
    _mm_prefetch((const char *)v, 2);
    v2->Flags = Flags;
    v2->Bonus.pWeakProxy = v->Bonus.pWeakProxy;
    v2->value.VNumber = v->value.VNumber;
    if ( (v2->Flags & 0x1F) > 9 )
    {
      if ( (v2->Flags & 0x200) != 0 )
        ++v2->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v2);
    }
  }
}

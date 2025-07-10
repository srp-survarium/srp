void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value other; // [esp+4h] [ebp-10h] BYREF

  Flags = v->Flags;
  other.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  other.value.VNumber = v->value.VNumber;
  other.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::GFx::AS3::Value::Assign(&this->ValueA.Data.Data[ind], &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  }
}

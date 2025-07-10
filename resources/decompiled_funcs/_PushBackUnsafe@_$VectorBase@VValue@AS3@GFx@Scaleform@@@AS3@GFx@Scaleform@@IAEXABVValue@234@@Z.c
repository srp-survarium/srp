void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value val; // [esp+4h] [ebp-10h] BYREF

  Flags = v->Flags;
  val.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  val.value.VNumber = v->value.VNumber;
  val.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->ValueA.Data,
    &val);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
}

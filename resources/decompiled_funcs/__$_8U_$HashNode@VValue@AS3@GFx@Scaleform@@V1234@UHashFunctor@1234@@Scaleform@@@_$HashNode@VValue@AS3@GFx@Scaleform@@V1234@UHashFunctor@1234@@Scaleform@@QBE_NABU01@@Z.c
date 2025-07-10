bool __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::operator==<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *src)
{
  unsigned int Flags; // eax
  bool v4; // bl
  Scaleform::GFx::AS3::Value y; // [esp+8h] [ebp-10h] BYREF

  Flags = src->First.Flags;
  y.Bonus.pWeakProxy = src->First.Bonus.pWeakProxy;
  y.value.VNumber = src->First.value.VNumber;
  y.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&src->First);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&src->First);
  }
  v4 = Scaleform::GFx::AS3::StrictEqual(&this->First, &y);
  if ( (y.Flags & 0x1F) > 9 )
  {
    if ( (y.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&y);
      return v4;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&y);
  }
  return v4;
}

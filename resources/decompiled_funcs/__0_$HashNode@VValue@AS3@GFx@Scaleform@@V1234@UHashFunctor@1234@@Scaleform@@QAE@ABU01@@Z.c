void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *src)
{
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  this->First.Flags = src->First.Flags;
  this->First.Bonus.pWeakProxy = src->First.Bonus.pWeakProxy;
  this->First.value.VNumber = src->First.value.VNumber;
  if ( (src->First.Flags & 0x1F) > 9 )
  {
    if ( (src->First.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(&src->First);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(&src->First);
  }
  p_Second = &src->Second;
  this->Second = src->Second;
  if ( (src->Second.Flags & 0x1F) > 9 )
  {
    if ( (src->Second.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(p_Second);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Second);
  }
}

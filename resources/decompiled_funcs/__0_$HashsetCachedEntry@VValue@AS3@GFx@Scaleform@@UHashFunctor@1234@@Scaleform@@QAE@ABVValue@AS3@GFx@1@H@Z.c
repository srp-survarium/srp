void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        Scaleform::GFx::AS3::Value *key,
        int next)
{
  this->NextInChain = next;
  this->Value = *key;
  if ( (key->Flags & 0x1F) > 9 )
  {
    if ( (key->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(key);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(key);
  }
}

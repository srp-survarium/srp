void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *this,
        const Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *e)
{
  Scaleform::GFx::AS3::Value *p_Value; // ecx
  unsigned int Flags; // eax

  *this = *e;
  p_Value = &e->Value;
  Flags = e->Value.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(p_Value);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(p_Value);
  }
}

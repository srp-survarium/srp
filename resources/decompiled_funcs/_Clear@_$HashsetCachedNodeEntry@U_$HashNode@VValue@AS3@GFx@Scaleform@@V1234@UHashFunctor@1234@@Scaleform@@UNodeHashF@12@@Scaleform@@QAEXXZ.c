void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> *this)
{
  Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *p_Value; // esi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  p_Value = &this->Value;
  Flags = this->Value.Second.Flags;
  p_Second = &this->Value.Second;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Second);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
  }
  if ( (p_Value->First.Flags & 0x1F) > 9 )
  {
    if ( (p_Value->First.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&p_Value->First);
      this->NextInChain = -2;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&p_Value->First);
  }
  this->NextInChain = -2;
}

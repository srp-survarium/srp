void __thiscall Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>::Clear(
        Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> *this)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Second; // ecx

  Flags = this->Value.Second.Flags;
  p_Second = &this->Value.Second;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_Second);
      this->NextInChain = -2;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
  }
  this->NextInChain = -2;
}

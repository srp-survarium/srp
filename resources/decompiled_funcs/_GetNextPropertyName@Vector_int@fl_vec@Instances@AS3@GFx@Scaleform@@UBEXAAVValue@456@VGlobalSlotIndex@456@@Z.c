void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
  {
    Scaleform::GFx::AS3::Value::SetUInt32(name, ind.Index - 1);
  }
  else
  {
    if ( (name->Flags & 0x1F) > 9 )
    {
      if ( (name->Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(name);
        name->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(name);
    }
    name->Flags &= 0xFFFFFFE0;
  }
}

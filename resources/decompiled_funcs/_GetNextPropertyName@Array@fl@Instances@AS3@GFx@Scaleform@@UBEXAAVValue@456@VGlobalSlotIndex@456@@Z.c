void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int Length; // edx

  if ( ind.Index )
  {
    Length = this->SA.Length;
    if ( ind.Index > Length )
      Scaleform::GFx::AS3::Object::GetNextPropertyName(
        this,
        name,
        (Scaleform::GFx::AS3::GlobalSlotIndex)(ind.Index - Length));
    else
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

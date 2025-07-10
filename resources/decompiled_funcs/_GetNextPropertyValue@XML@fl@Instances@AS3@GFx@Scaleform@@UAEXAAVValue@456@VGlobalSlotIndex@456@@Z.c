void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
  {
    Scaleform::GFx::AS3::Value::Assign(value, this);
    return;
  }
  if ( (value->Flags & 0x1F) > 9 )
  {
    if ( (value->Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(value);
      value->Flags &= 0xFFFFFFE0;
      return;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(value);
  }
  value->Flags &= 0xFFFFFFE0;
}

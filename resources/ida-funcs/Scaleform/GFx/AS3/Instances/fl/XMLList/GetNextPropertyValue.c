void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index <= this->List.Data.Size )
  {
    Scaleform::GFx::AS3::Value::Assign(value, this->List.Data.Data[ind.Index - 1].pObject);
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

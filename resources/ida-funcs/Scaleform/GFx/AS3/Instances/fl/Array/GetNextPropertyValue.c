void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int Length; // edx
  const Scaleform::GFx::AS3::Value *v4; // eax

  if ( ind.Index )
  {
    Length = this->SA.Length;
    if ( ind.Index > Length )
    {
      Scaleform::GFx::AS3::Object::GetNextPropertyValue(
        this,
        value,
        (Scaleform::GFx::AS3::GlobalSlotIndex)(ind.Index - Length));
    }
    else
    {
      v4 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, ind.Index - 1);
      Scaleform::GFx::AS3::Value::Assign(value, v4);
    }
  }
  else
  {
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
}

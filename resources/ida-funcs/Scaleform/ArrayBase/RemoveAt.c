void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index)
{
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *v5; // ecx

  if ( this->Data.Size == 1 )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0);
  }
  else
  {
    Data = this->Data.Data;
    Flags = Data[index].Flags;
    v5 = &Data[index];
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v5);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v5);
    }
    memmove(
      (int)&this->Data.Data[index],
      (const __m128i *)&this->Data.Data[index + 1],
      16 * (this->Data.Size - index - 1));
    --this->Data.Size;
  }
}

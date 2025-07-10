void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *v5; // esi

  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size + 1);
  Size = this->Data.Size;
  if ( index < Size - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      16 * (Size - index - 1));
  v5 = &this->Data.Data[index];
  if ( v5 )
  {
    *v5 = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}

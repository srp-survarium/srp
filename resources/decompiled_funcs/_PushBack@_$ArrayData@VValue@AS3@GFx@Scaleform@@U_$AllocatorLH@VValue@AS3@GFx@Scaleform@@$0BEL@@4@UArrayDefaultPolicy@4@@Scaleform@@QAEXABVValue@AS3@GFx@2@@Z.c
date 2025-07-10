void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // ecx

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    this->Size + 1);
  Size = this->Size;
  if ( &this->Data[Size] != (Scaleform::GFx::AS3::Value *)16 )
  {
    this->Data[Size - 1] = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        ++val->Bonus.pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}

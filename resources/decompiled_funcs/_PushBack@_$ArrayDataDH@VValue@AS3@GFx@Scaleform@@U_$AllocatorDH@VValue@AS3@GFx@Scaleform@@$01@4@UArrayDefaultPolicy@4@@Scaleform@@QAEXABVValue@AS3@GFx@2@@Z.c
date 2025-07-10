void __thiscall Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int Size; // edx

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this->pHeap,
    this->Size + 1);
  Size = this->Size;
  if ( &this->Data[Size] != (Scaleform::GFx::AS3::Value *)16 )
  {
    this->Data[Size - 1] = *val;
    if ( (val->Flags & 0x1F) > 9 )
    {
      if ( (val->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(val);
    }
  }
}

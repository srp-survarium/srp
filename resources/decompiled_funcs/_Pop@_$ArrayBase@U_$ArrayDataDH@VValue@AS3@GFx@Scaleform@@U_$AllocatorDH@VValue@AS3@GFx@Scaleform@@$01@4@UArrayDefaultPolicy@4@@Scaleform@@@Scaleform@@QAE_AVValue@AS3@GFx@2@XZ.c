Scaleform::GFx::AS3::Value *__thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *Data; // ecx
  Scaleform::GFx::AS3::Value::V1U v5; // edx
  _DWORD *v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // ecx
  unsigned int Flags; // eax

  Size = this->Data.Size;
  Data = this->Data.Data;
  Size *= 16;
  v5 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)Data + Size - 8);
  v6 = *(_DWORD **)((char *)Data + Size - 12);
  v7 = (Scaleform::GFx::AS3::Value *)((char *)Data + Size - 16);
  Flags = v7->Flags;
  result->value.VS._1 = v5;
  result->value.VS._2.VObj = v7->value.VS._2.VObj;
  result->Flags = Flags;
  result->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v6;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++*v6;
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->Data,
        this->Data.Size - 1);
      return result;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(v7);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size - 1);
  return result;
}

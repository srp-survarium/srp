void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::clear(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        const Scaleform::GFx::AS3::Value *result)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Data; // esi

  p_Data = &this->Data;
  if ( this->Data.Data.Size )
  {
    if ( (this->Data.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      goto LABEL_5;
  }
  else if ( !this->Data.Data.Policy.Capacity )
  {
LABEL_5:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      &this->Data,
      0);
  }
  p_Data->Data.Size = 0;
  this->Length = 0;
  this->Position = 0;
}

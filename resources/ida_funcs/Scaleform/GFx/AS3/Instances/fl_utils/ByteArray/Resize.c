void __thiscall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Resize(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int size)
{
  unsigned int v3; // ebp
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_Data; // edi

  v3 = this->Data.Data.Size;
  if ( size > v3 )
  {
    p_Data = &this->Data;
    if ( size >= this->Data.Data.Size )
    {
      if ( size >= this->Data.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
          &this->Data,
          size + (size >> 2));
    }
    else if ( size < this->Data.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
        &this->Data,
        size);
    }
    this->Data.Data.Size = size;
    memset((int)&p_Data->Data.Data[v3], 0, size - v3);
  }
  this->Length = size;
  if ( this->Position > size )
    this->Position = size;
}

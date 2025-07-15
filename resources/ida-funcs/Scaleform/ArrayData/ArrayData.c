void __thiscall Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int size)
{
  this->Data = 0;
  this->Size = 0;
  this->Policy.Capacity = 0;
  if ( size >= this->Size )
  {
    if ( size >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        size + (size >> 2));
  }
  else if ( size < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      size);
    this->Size = size;
    return;
  }
  this->Size = size;
}


void __thiscall Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int size)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Value *v4; // eax
  unsigned int v5; // edi

  this->Size = 0;
  this->Data = 0;
  this->Policy.Capacity = 0;
  v3 = this->Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    size);
  if ( size > v3 )
  {
    v4 = &this->Data[v3];
    v5 = size - v3;
    if ( size != v3 )
    {
      do
      {
        if ( v4 )
        {
          v4->Flags = 0;
          v4->Bonus.pWeakProxy = 0;
        }
        ++v4;
        --v5;
      }
      while ( v5 );
    }
  }
}


void __thiscall Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned int size)
{
  this->Data = 0;
  this->Size = 0;
  this->Policy.Capacity = 0;
  if ( size >= this->Size )
  {
    if ( size >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        size + (size >> 2));
  }
  else if ( size < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      size);
    this->Size = size;
    return;
  }
  this->Size = size;
}

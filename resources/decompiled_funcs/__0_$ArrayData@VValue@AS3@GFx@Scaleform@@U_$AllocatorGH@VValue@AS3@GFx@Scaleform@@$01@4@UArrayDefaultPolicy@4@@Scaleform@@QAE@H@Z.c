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

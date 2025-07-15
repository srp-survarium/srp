void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        const Scaleform::RangeData<void *> *val)
{
  unsigned int Size; // eax
  Scaleform::RangeData<void *> *v5; // eax
  unsigned int Length; // edx

  Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size + 1);
  Size = this->Data.Size;
  if ( index < Size - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      12 * (Size - index - 1));
  v5 = &this->Data.Data[index];
  if ( v5 )
  {
    Length = val->Length;
    v5->Index = val->Index;
    v5->Length = Length;
    v5->Data = val->Data;
  }
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v5; // esi
  unsigned int *v6; // eax

  pHeap = this->Data.pHeap;
  v5 = this->Data.Size + 1;
  if ( v5 >= this->Data.Size )
  {
    if ( v5 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5);
  }
  this->Data.Size = v5;
  if ( index < v5 - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      4 * (v5 - index) - 4);
  v6 = &this->Data.Data[index];
  if ( v6 )
    *v6 = *val;
}


void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        const long double *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v5; // esi
  double *v6; // eax

  pHeap = this->Data.pHeap;
  v5 = this->Data.Size + 1;
  if ( v5 >= this->Data.Size )
  {
    if ( v5 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5);
  }
  this->Data.Size = v5;
  if ( index < v5 - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      8 * (v5 - index) - 8);
  v6 = &this->Data.Data[index];
  if ( v6 )
    *v6 = *(double *)val;
}


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

unsigned int __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned int,Scaleform::AllocatorDH_POD<unsigned int,328>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned int Size; // eax
  unsigned int v3; // ebx
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edi

  Size = this->Data.Size;
  v3 = this->Data.Data[Size - 1];
  pHeap = this->Data.pHeap;
  v5 = Size - 1;
  if ( Size )
  {
    if ( v5 < this->Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        Size - 1);
      this->Data.Size = v5;
      return v3;
    }
  }
  else if ( v5 >= this->Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State *,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State *,328>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5 + (v5 >> 2));
  }
  this->Data.Size = v5;
  return v3;
}


unsigned int __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned int Size; // eax
  unsigned int v3; // ebx
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edi

  Size = this->Data.Size;
  v3 = this->Data.Data[Size - 1];
  pHeap = this->Data.pHeap;
  v5 = Size - 1;
  if ( Size )
  {
    if ( v5 < this->Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        Size - 1);
      this->Data.Size = v5;
      return v3;
    }
  }
  else if ( v5 >= this->Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5 + (v5 >> 2));
  }
  this->Data.Size = v5;
  return v3;
}


long double __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned int Size; // eax
  long double result; // st7
  const Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edi

  Size = this->Data.Size;
  result = this->Data.Data[Size - 1];
  pHeap = this->Data.pHeap;
  v5 = Size - 1;
  if ( Size )
  {
    if ( v5 < this->Data.Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        Size - 1);
  }
  else if ( v5 >= this->Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5 + (v5 >> 2));
  }
  this->Data.Size = v5;
  return result;
}


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

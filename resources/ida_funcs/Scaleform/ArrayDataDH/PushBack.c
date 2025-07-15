void __thiscall Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayDataDH<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::Pair<double,unsigned long> *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  Scaleform::Pair<double,unsigned long> *Data; // eax
  Scaleform::Pair<double,unsigned long> *v6; // eax

  pHeap = this->pHeap;
  v4 = this->Size + 1;
  if ( v4 >= this->Size )
  {
    if ( v4 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      pHeap,
      v4);
  }
  Data = this->Data;
  this->Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}


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

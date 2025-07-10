void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int8 *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned __int8 *Data; // eax
  unsigned __int8 *v6; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->Data,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}

void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const unsigned __int8 *val)
{
  unsigned int v3; // esi
  unsigned __int8 *Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (unsigned __int8 *)1 )
    Data[v3 - 1] = *val;
}

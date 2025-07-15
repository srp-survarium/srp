unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx

  v2 = v;
  if ( v > 0x7F )
  {
    LOBYTE(v) = (2 * v) | 1;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (unsigned __int8 *)&v);
    Data = this->Data;
    LOBYTE(v) = v2 >> 7;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (unsigned __int8 *)&v);
    return 2;
  }
  else
  {
    v4 = this->Data;
    LOBYTE(v) = 2 * v;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v4,
      (unsigned __int8 *)&v);
    return 1;
  }
}


unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v5; // esi
  bool *v6; // edx
  char v8; // al
  bool *v9; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v10; // edi
  unsigned int v11; // esi
  unsigned int v12; // ebx
  bool *v13; // ecx
  char v14; // [esp+14h] [ebp+4h]

  Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v5 = this->Data->Data.Size + 1;
  if ( v <= 0x7F )
  {
    if ( v5 >= Data->Size )
    {
      if ( v5 >= Data->Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          Data,
          Data,
          v5 + (v5 >> 2));
    }
    else if ( v5 < Data->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        this->Data->Data.Size + 1);
    }
    v6 = Data->Data;
    Data->Size = v5;
    v6[v5 - 1] = 2 * v;
    return 1;
  }
  v8 = (2 * v) | 1;
  v14 = v8;
  if ( v5 >= Data->Size )
  {
    if ( v5 >= Data->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v5 + (v5 >> 2));
      goto LABEL_13;
    }
  }
  else if ( v5 < Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(Data, Data, v5);
LABEL_13:
    v8 = v14;
  }
  v9 = Data->Data;
  Data->Size = v5;
  v9[v5 - 1] = v8;
  v10 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v11 = this->Data->Data.Size + 1;
  v12 = v >> 7;
  if ( v11 >= this->Data->Data.Size )
  {
    if ( v11 >= v10->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v10,
        v10,
        v11 + (v11 >> 2));
  }
  else if ( v11 < v10->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v10,
      v10,
      this->Data->Data.Size + 1);
  }
  v13 = v10->Data;
  v10->Size = v11;
  v13[v11 - 1] = v12;
  return 2;
}

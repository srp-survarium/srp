unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v4; // edi
  unsigned int v5; // esi
  char v6; // bl
  bool *v7; // edx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v14; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // ecx

  v2 = v;
  if ( v > 0x3F )
  {
    if ( v > 0x3FFF )
    {
      Data = this->Data;
      if ( v > (unsigned int)&byte_3FFFFF )
      {
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (const unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (const unsigned __int8 *)&v);
        v14 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v14,
          (const unsigned __int8 *)&v);
        v15 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v15,
          (const unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (const unsigned __int8 *)&v);
        v12 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v12,
          (const unsigned __int8 *)&v);
        v13 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v13,
          (const unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      v9 = this->Data;
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v9,
        (const unsigned __int8 *)&v);
      v10 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v10,
        (const unsigned __int8 *)&v);
      return 2;
    }
  }
  else
  {
    v4 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
    v5 = this->Data->Data.Size + 1;
    v6 = 4 * v;
    if ( v5 >= this->Data->Data.Size )
    {
      if ( v5 >= v4->Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v4,
          v4,
          v5 + (v5 >> 2));
    }
    else if ( v5 < v4->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v4, v4, v5);
    }
    v7 = v4->Data;
    v4->Size = v5;
    v7[v5 - 1] = v6;
    return 1;
  }
}

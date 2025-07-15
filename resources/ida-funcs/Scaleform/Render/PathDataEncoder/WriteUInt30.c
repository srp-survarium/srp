unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v4; // edi
  unsigned int v5; // esi
  char v6; // bl
  char *v7; // eax
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v14; // ecx
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v15; // ecx

  v2 = v;
  if ( v > 0x3F )
  {
    if ( v > 0x3FFF )
    {
      Data = this->Data;
      if ( v > (unsigned int)&loc_3FFFFE + 1 )
      {
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v14 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v14,
          (unsigned __int8 *)&v);
        v15 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v15,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v12 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v12,
          (unsigned __int8 *)&v);
        v13 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v13,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      v9 = this->Data;
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v9,
        (unsigned __int8 *)&v);
      v10 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v10,
        (unsigned __int8 *)&v);
      return 2;
    }
  }
  else
  {
    v4 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
    v5 = this->Data->Data.Size + 1;
    v6 = 4 * v;
    if ( v5 >= this->Data->Data.Size )
    {
      if ( v5 >= v4->Policy.Capacity )
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v4,
          v4,
          v5 + (v5 >> 2));
    }
    else if ( v5 < v4->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v4,
        v4,
        v5);
    }
    v7 = &v4->Data[v5 - 1];
    v4->Size = v5;
    if ( v7 )
      *v7 = v6;
    return 1;
  }
}


unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx

  v2 = v;
  if ( v > 0x3F )
  {
    if ( v > 0x3FFF )
    {
      if ( v > (unsigned int)&loc_3FFFFE + 1 )
      {
        Data = this->Data;
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v10 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v10,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v11 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v11,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v7 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v7,
          (unsigned __int8 *)&v);
        v8 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v8,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        this->Data,
        (unsigned __int8 *)&v);
      v6 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v6,
        (unsigned __int8 *)&v);
      return 2;
    }
  }
  else
  {
    v4 = this->Data;
    LOBYTE(v) = 4 * v;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v4,
      (unsigned __int8 *)&v);
    return 1;
  }
}


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
      if ( v > 0x3FFFFF )
      {
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v14 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v14,
          (unsigned __int8 *)&v);
        v15 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v15,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v12 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v12,
          (unsigned __int8 *)&v);
        v13 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v13,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      v9 = this->Data;
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v9,
        (unsigned __int8 *)&v);
      v10 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v10,
        (unsigned __int8 *)&v);
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

unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int v)
{
  int v2; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // ecx

  v2 = v;
  if ( (unsigned int)(v + 32) > 0x3F )
  {
    if ( (unsigned int)(v + 0x2000) > 0x3FFF )
    {
      if ( v + 0x200000 > (unsigned int)&byte_3FFFFF )
      {
        Data = this->Data;
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v11 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v11,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v12 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v12,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v8 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v8,
          (unsigned __int8 *)&v);
        v9 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v9,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      v6 = this->Data;
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v6,
        (unsigned __int8 *)&v);
      v7 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v7,
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


unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int v)
{
  int v2; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v10; // edi
  char v11; // al
  unsigned int v12; // esi
  bool *v13; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v14; // edi
  int v15; // eax
  unsigned int v16; // esi
  bool *v17; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v18; // edi
  int v19; // eax
  unsigned int v20; // esi
  bool *v21; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v22; // edi
  unsigned int v23; // esi
  int v24; // ebx
  bool *v25; // ecx

  v2 = v;
  if ( (unsigned int)(v + 32) <= 0x3F )
  {
    Data = this->Data;
    LOBYTE(v) = 4 * v;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (const unsigned __int8 *)&v);
    return 1;
  }
  if ( (unsigned int)(v + 0x2000) <= 0x3FFF )
  {
    v6 = this->Data;
    LOBYTE(v) = (4 * v) | 1;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v6,
      (const unsigned __int8 *)&v);
    v7 = this->Data;
    LOBYTE(v) = v2 >> 6;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v7,
      (const unsigned __int8 *)&v);
    return 2;
  }
  if ( v + 0x200000 <= (unsigned int)&byte_3FFFFF )
  {
    LOBYTE(v) = (4 * v) | 2;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (const unsigned __int8 *)&v);
    v8 = this->Data;
    LOBYTE(v) = v2 >> 6;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v8,
      (const unsigned __int8 *)&v);
    v9 = this->Data;
    LOBYTE(v) = v2 >> 14;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v9,
      (const unsigned __int8 *)&v);
    return 3;
  }
  v10 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v11 = (4 * v) | 3;
  v12 = this->Data->Data.Size + 1;
  LOBYTE(v) = v11;
  if ( v12 >= v10->Size )
  {
    if ( v12 < v10->Policy.Capacity )
      goto LABEL_13;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v10,
      v10,
      v12 + (v12 >> 2));
  }
  else
  {
    if ( v12 >= v10->Policy.Capacity >> 1 )
      goto LABEL_13;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v10, v10, v12);
  }
  v11 = v;
LABEL_13:
  v13 = v10->Data;
  v10->Size = v12;
  v13[v12 - 1] = v11;
  v14 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v15 = v2 >> 6;
  v16 = this->Data->Data.Size + 1;
  LOBYTE(v) = v2 >> 6;
  if ( v16 >= v14->Size )
  {
    if ( v16 < v14->Policy.Capacity )
      goto LABEL_19;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v14,
      v14,
      v16 + (v16 >> 2));
  }
  else
  {
    if ( v16 >= v14->Policy.Capacity >> 1 )
      goto LABEL_19;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v14, v14, v16);
  }
  LOBYTE(v15) = v;
LABEL_19:
  v17 = v14->Data;
  v14->Size = v16;
  v17[v16 - 1] = v15;
  v18 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v19 = v2 >> 14;
  v20 = this->Data->Data.Size + 1;
  LOBYTE(v) = v2 >> 14;
  if ( v20 >= v18->Size )
  {
    if ( v20 >= v18->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v18,
        v18,
        v20 + (v20 >> 2));
      goto LABEL_24;
    }
  }
  else if ( v20 < v18->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v18, v18, v20);
LABEL_24:
    LOBYTE(v19) = v;
  }
  v21 = v18->Data;
  v18->Size = v20;
  v21[v20 - 1] = v19;
  v22 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v23 = this->Data->Data.Size + 1;
  v24 = v2 >> 22;
  if ( v23 >= this->Data->Data.Size )
  {
    if ( v23 >= v22->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v22,
        v22,
        v23 + (v23 >> 2));
  }
  else if ( v23 < v22->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v22,
      v22,
      this->Data->Data.Size + 1);
  }
  v25 = v22->Data;
  v22->Size = v23;
  v25[v23 - 1] = v24;
  return 4;
}

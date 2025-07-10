unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        int y)
{
  int v2; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v6; // edi
  char v7; // al
  unsigned int v8; // esi
  bool *v9; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v10; // edi
  int v11; // eax
  unsigned int v12; // esi
  bool *v13; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v14; // edi
  int v15; // eax
  unsigned int v16; // esi
  bool *v17; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v18; // edi
  unsigned int v19; // esi
  int v20; // ebx
  bool *v21; // ecx

  v2 = y;
  if ( (unsigned int)(y + 2048) <= 0xFFF )
  {
    LOBYTE(y) = (16 * y) | 2;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (const unsigned __int8 *)&y);
    Data = this->Data;
    LOBYTE(y) = v2 >> 4;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (const unsigned __int8 *)&y);
    return 2;
  }
  v6 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v7 = (16 * y) | 3;
  v8 = this->Data->Data.Size + 1;
  LOBYTE(y) = v7;
  if ( v8 >= v6->Size )
  {
    if ( v8 < v6->Policy.Capacity )
      goto LABEL_9;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      v8 + (v8 >> 2));
  }
  else
  {
    if ( v8 >= v6->Policy.Capacity >> 1 )
      goto LABEL_9;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v6, v6, v8);
  }
  v7 = y;
LABEL_9:
  v9 = v6->Data;
  v6->Size = v8;
  v9[v8 - 1] = v7;
  v10 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v11 = v2 >> 4;
  v12 = this->Data->Data.Size + 1;
  LOBYTE(y) = v2 >> 4;
  if ( v12 >= v10->Size )
  {
    if ( v12 < v10->Policy.Capacity )
      goto LABEL_15;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v10,
      v10,
      v12 + (v12 >> 2));
  }
  else
  {
    if ( v12 >= v10->Policy.Capacity >> 1 )
      goto LABEL_15;
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v10, v10, v12);
  }
  LOBYTE(v11) = y;
LABEL_15:
  v13 = v10->Data;
  v10->Size = v12;
  v13[v12 - 1] = v11;
  v14 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v15 = v2 >> 12;
  v16 = this->Data->Data.Size + 1;
  LOBYTE(y) = v2 >> 12;
  if ( v16 >= v14->Size )
  {
    if ( v16 >= v14->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v14,
        v14,
        v16 + (v16 >> 2));
      goto LABEL_20;
    }
  }
  else if ( v16 < v14->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v14, v14, v16);
LABEL_20:
    LOBYTE(v15) = y;
  }
  v17 = v14->Data;
  v14->Size = v16;
  v17[v16 - 1] = v15;
  v18 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v19 = this->Data->Data.Size + 1;
  v20 = v2 >> 20;
  if ( v19 >= this->Data->Data.Size )
  {
    if ( v19 >= v18->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v18,
        v18,
        v19 + (v19 >> 2));
  }
  else if ( v19 < v18->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v18,
      v18,
      this->Data->Data.Size + 1);
  }
  v21 = v18->Data;
  v18->Size = v19;
  v21[v19 - 1] = v20;
  return 3;
}

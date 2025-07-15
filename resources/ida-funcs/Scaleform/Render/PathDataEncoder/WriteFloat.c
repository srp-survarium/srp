void __thiscall Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
        Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float v)
{
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v4; // esi
  char *v5; // eax
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v6; // edi
  unsigned int v7; // esi
  char *v8; // eax
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v9; // edi
  unsigned int v10; // esi
  char *v11; // eax
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *v12; // edi
  unsigned int v13; // esi
  char *v14; // ecx

  Data = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v4 = this->Data->Data.Size + 1;
  if ( v4 >= this->Data->Data.Size )
  {
    if ( v4 >= Data->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v4 + (v4 >> 2));
  }
  else if ( v4 < Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      this->Data->Data.Size + 1);
  }
  v5 = &Data->Data[v4 - 1];
  Data->Size = v4;
  if ( v5 )
    *v5 = LOBYTE(v);
  v6 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v7 = this->Data->Data.Size + 1;
  if ( v7 >= this->Data->Data.Size )
  {
    if ( v7 >= v6->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v6,
        v6,
        v7 + (v7 >> 2));
  }
  else if ( v7 < v6->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      this->Data->Data.Size + 1);
  }
  v8 = &v6->Data[v7 - 1];
  v6->Size = v7;
  if ( v8 )
    *v8 = BYTE1(v);
  v9 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v10 = this->Data->Data.Size + 1;
  if ( v10 >= this->Data->Data.Size )
  {
    if ( v10 >= v9->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v9,
        v9,
        v10 + (v10 >> 2));
  }
  else if ( v10 < v9->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v9,
      v9,
      this->Data->Data.Size + 1);
  }
  v11 = &v9->Data[v10 - 1];
  v9->Size = v10;
  if ( v11 )
    *v11 = BYTE2(v);
  v12 = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v13 = this->Data->Data.Size + 1;
  if ( v13 >= this->Data->Data.Size )
  {
    if ( v13 >= v12->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v12,
        v12,
        v13 + (v13 >> 2));
  }
  else if ( v13 < v12->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v12,
      v12,
      this->Data->Data.Size + 1);
  }
  v14 = v12->Data;
  v12->Size = v13;
  if ( &v14[v13] != (char *)1 )
    v14[v13 - 1] = HIBYTE(v);
}


void __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float v)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v4; // esi
  bool *v5; // edx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v6; // edi
  unsigned int v7; // esi
  bool *v8; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v9; // edi
  unsigned int v10; // esi
  bool *v11; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v12; // edi
  unsigned int v13; // esi
  bool *v14; // edx

  Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v4 = this->Data->Data.Size + 1;
  if ( v4 >= this->Data->Data.Size )
  {
    if ( v4 >= Data->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v4 + (v4 >> 2));
  }
  else if ( v4 < Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      this->Data->Data.Size + 1);
  }
  v5 = Data->Data;
  Data->Size = v4;
  v5[v4 - 1] = LOBYTE(v);
  v6 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v7 = this->Data->Data.Size + 1;
  if ( v7 >= this->Data->Data.Size )
  {
    if ( v7 >= v6->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v6,
        v6,
        v7 + (v7 >> 2));
  }
  else if ( v7 < v6->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6,
      this->Data->Data.Size + 1);
  }
  v8 = v6->Data;
  v6->Size = v7;
  v8[v7 - 1] = BYTE1(v);
  v9 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v10 = this->Data->Data.Size + 1;
  if ( v10 >= this->Data->Data.Size )
  {
    if ( v10 >= v9->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v9,
        v9,
        v10 + (v10 >> 2));
  }
  else if ( v10 < v9->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v9,
      v9,
      this->Data->Data.Size + 1);
  }
  v11 = v9->Data;
  v9->Size = v10;
  v11[v10 - 1] = BYTE2(v);
  v12 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v13 = this->Data->Data.Size + 1;
  if ( v13 >= this->Data->Data.Size )
  {
    if ( v13 >= v12->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v12,
        v12,
        v13 + (v13 >> 2));
  }
  else if ( v13 < v12->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v12,
      v12,
      this->Data->Data.Size + 1);
  }
  v14 = v12->Data;
  v12->Size = v13;
  v14[v13 - 1] = HIBYTE(v);
}

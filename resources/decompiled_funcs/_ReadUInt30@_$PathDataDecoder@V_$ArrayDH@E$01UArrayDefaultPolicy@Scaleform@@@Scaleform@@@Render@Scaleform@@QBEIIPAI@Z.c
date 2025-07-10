unsigned int __thiscall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        unsigned int *v)
{
  unsigned __int8 *Data; // ecx
  unsigned int v4; // eax
  unsigned __int8 *v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // ecx

  Data = this->Data->Data.Data;
  v4 = Data[pos];
  v5 = &Data[pos];
  v6 = Data[pos] & 3;
  v7 = v4 >> 2;
  if ( v6 )
  {
    v8 = v6 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
      {
        *v = v7 | ((v5[1] | (v5[2] << 8)) << 6);
        return 3;
      }
      else
      {
        *v = v7 | ((v5[1] | ((v5[2] | (v5[3] << 8)) << 8)) << 6);
        return 4;
      }
    }
    else
    {
      *v = v7 | (v5[1] << 6);
      return 2;
    }
  }
  else
  {
    *v = v7;
    return 1;
  }
}

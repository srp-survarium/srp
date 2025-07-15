unsigned int __thiscall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        int *v)
{
  unsigned __int8 *Data; // ecx
  int v4; // eax
  unsigned __int8 *v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // ecx

  Data = this->Data->Data.Data;
  v4 = (char)Data[pos];
  v5 = &Data[pos];
  v6 = Data[pos] & 3;
  v7 = v4 >> 2;
  if ( v6 )
  {
    v8 = v7 & 0x3F;
    v9 = v6 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        *v = v8 | ((v5[1] | ((char)v5[2] << 8)) << 6);
        return 3;
      }
      else
      {
        *v = v8 | ((v5[1] | ((v5[2] | ((char)v5[3] << 8)) << 8)) << 6);
        return 4;
      }
    }
    else
    {
      *v = v8 | ((char)v5[1] << 6);
      return 2;
    }
  }
  else
  {
    *v = v7;
    return 1;
  }
}

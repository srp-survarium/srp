Scaleform::Render::ShapePathType __thiscall Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        float *coord,
        unsigned int *styles)
{
  unsigned __int8 *v6; // ecx
  unsigned int v7; // eax
  Scaleform::Render::ShapePathType result; // eax
  int v9; // ecx
  unsigned int SInt30; // eax
  int v11; // ebp
  int v12; // edx
  Scaleform::Render::ShapePathType flag; // [esp+Ch] [ebp+4h]

  v6 = &this->Decoder.Data->Data.Data[*(_DWORD *)pos];
  v7 = *v6;
  if ( (v7 & 1) != 0 )
  {
    flag = (v7 >> 1) | (v6[1] << 7);
    result = flag;
    v9 = 2;
  }
  else
  {
    result = v7 >> 1;
    flag = result;
    v9 = 1;
  }
  *(_DWORD *)pos += v9;
  if ( result )
  {
    *(_DWORD *)pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
                        &this->Decoder,
                        *(_DWORD *)pos,
                        styles);
    *(_DWORD *)pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
                        &this->Decoder,
                        *(_DWORD *)pos,
                        styles + 1);
    *(_DWORD *)pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
                        &this->Decoder,
                        *(_DWORD *)pos,
                        styles + 2);
    *(_DWORD *)pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
                        &this->Decoder,
                        *(_DWORD *)pos,
                        (int *)(pos + 4));
    SInt30 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadSInt30(
               &this->Decoder,
               *(_DWORD *)pos,
               (int *)(pos + 8));
    v11 = *(_DWORD *)(pos + 4);
    *(_DWORD *)pos += SInt30;
    v12 = *(_DWORD *)(pos + 8);
    *(_DWORD *)(pos + 12) = v11;
    *(_DWORD *)(pos + 16) = v12;
    *coord = (double)v11 * this->OneOverMultiplier;
    coord[1] = (double)*(int *)(pos + 8) * this->OneOverMultiplier;
    return flag;
  }
  return result;
}

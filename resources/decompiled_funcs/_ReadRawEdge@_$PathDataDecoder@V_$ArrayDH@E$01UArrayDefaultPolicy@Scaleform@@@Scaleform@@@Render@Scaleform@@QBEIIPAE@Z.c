unsigned int __thiscall Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadRawEdge(
        Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int pos,
        unsigned __int8 *data)
{
  unsigned __int8 v4; // cl
  int v5; // ecx
  int v6; // ebp
  int v7; // edx
  unsigned __int8 *v8; // eax
  int v9; // edi

  v4 = this->Data->Data.Data[pos];
  *data = v4;
  v5 = v4 & 0xF;
  v6 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v5];
  v7 = pos + 1;
  v8 = data + 1;
  if ( Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v5] )
  {
    v9 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::Sizes[v5];
    do
    {
      *v8++ = this->Data->Data.Data[v7++];
      --v9;
    }
    while ( v9 );
  }
  return v6 + 1;
}

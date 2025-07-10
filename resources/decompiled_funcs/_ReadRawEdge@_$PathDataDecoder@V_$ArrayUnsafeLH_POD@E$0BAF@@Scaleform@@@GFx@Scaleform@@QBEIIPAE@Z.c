unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadRawEdge(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int pos,
        unsigned __int8 *data)
{
  unsigned __int8 v4; // cl
  int v5; // ecx
  int v6; // ebp
  int v7; // edx
  unsigned __int8 *v8; // eax
  int v9; // edi

  v4 = this->Data->Data[pos];
  *data = v4;
  v5 = v4 & 0xF;
  v6 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v5];
  v7 = pos + 1;
  v8 = data + 1;
  if ( Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v5] )
  {
    v9 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v5];
    do
    {
      *v8++ = this->Data->Data[v7++];
      --v9;
    }
    while ( v9 );
  }
  return v6 + 1;
}

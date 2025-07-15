unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        unsigned __int8 *data)
{
  unsigned __int8 v4; // cl
  int v5; // edi
  unsigned int v6; // eax
  unsigned __int8 *v7; // edx
  int v9; // [esp+Ch] [ebp+4h]

  v4 = this->Data->Pages[pos >> 12][pos & 0xFFF];
  *data = v4;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v4 & 0xF];
  v6 = pos + 1;
  v7 = data + 1;
  v9 = v5;
  if ( !Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v4 & 0xF] )
    return 1;
  do
  {
    *v7++ = this->Data->Pages[v6 >> 12][v6 & 0xFFF];
    ++v6;
    --v5;
  }
  while ( v5 );
  return v9 + 1;
}


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

unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        unsigned __int8 *data)
{
  unsigned __int8 v4; // cl
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned __int8 *v7; // edx
  unsigned int nb; // [esp+Ch] [ebp+4h]

  v4 = this->Data->Pages[pos >> 12][pos & 0xFFF];
  *data = v4;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v4 & 0xF];
  v6 = pos + 1;
  v7 = data + 1;
  nb = v5;
  if ( !Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::Sizes[v4 & 0xF] )
    return 1;
  do
  {
    *v7++ = this->Data->Pages[v6 >> 12][v6 & 0xFFF];
    ++v6;
    --v5;
  }
  while ( v5 );
  return nb + 1;
}

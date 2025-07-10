int __thiscall Scaleform::GFx::FontCompactor::ComputePathHash(Scaleform::GFx::FontCompactor *this, unsigned int pos)
{
  unsigned int v2; // edi
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // ebp
  int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  unsigned int RawEdge; // eax
  unsigned int v8; // ecx
  int v9; // edx
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *v11; // [esp+10h] [ebp-10h]
  unsigned __int8 edge[12]; // [esp+14h] [ebp-Ch] BYREF

  v2 = pos;
  p_Decoder = &this->Decoder;
  v4 = 0;
  v11 = &this->Decoder;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
         &this->Decoder,
         pos,
         &pos)
     + v2;
  v6 = pos >> 1;
  while ( v6 )
  {
    --v6;
    RawEdge = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                p_Decoder,
                v5,
                edge);
    v5 += RawEdge;
    v8 = 0;
    if ( RawEdge )
    {
      do
      {
        v9 = (33 * v4) ^ edge[v8++];
        v4 = v9;
      }
      while ( v8 < RawEdge );
      p_Decoder = v11;
    }
  }
  return v4;
}

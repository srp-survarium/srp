char __thiscall Scaleform::GFx::FontCompactor::PathsEqual(
        Scaleform::GFx::FontCompactor *this,
        unsigned int pos,
        const Scaleform::GFx::FontCompactor *cmpPath,
        unsigned int cmpPos)
{
  unsigned int v4; // esi
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // edi
  unsigned int v6; // ebp
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *v7; // esi
  unsigned int UInt30; // ebx
  unsigned int v9; // ebx
  unsigned int RawEdge; // edi
  unsigned int v12; // ecx
  unsigned __int8 *v13; // edx
  unsigned __int8 *v14; // esi
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *v15; // [esp+10h] [ebp-20h]
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *v16; // [esp+14h] [ebp-1Ch]
  unsigned __int8 edge2[12]; // [esp+18h] [ebp-18h] BYREF
  unsigned __int8 edge1[12]; // [esp+24h] [ebp-Ch] BYREF

  v4 = pos;
  p_Decoder = &this->Decoder;
  v15 = &this->Decoder;
  v6 = v4
     + Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
         &this->Decoder,
         pos,
         &pos);
  v7 = &cmpPath->Decoder;
  v16 = &cmpPath->Decoder;
  UInt30 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
             &cmpPath->Decoder,
             cmpPos,
             (unsigned int *)&cmpPath);
  v9 = cmpPos + UInt30;
  if ( (const Scaleform::GFx::FontCompactor *)pos != cmpPath )
    return 0;
  pos >>= 1;
  if ( pos )
  {
    while ( 1 )
    {
      --pos;
      RawEdge = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                  p_Decoder,
                  v6,
                  edge1);
      cmpPos = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                 v7,
                 v9,
                 edge2);
      if ( RawEdge != cmpPos )
        return 0;
      v12 = RawEdge;
      v13 = edge2;
      v14 = edge1;
      if ( RawEdge >= 4 )
      {
        while ( *(_DWORD *)v14 == *(_DWORD *)v13 )
        {
          v12 -= 4;
          v13 += 4;
          v14 += 4;
          if ( v12 < 4 )
            goto LABEL_10;
        }
        return 0;
      }
LABEL_10:
      if ( v12 && (*v13 != *v14 || v12 > 1 && (v13[1] != v14[1] || v12 > 2 && v13[2] != v14[2])) )
        return 0;
      v9 += cmpPos;
      v6 += RawEdge;
      if ( !pos )
        return 1;
      p_Decoder = v15;
      v7 = v16;
    }
  }
  return 1;
}

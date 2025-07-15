unsigned int __thiscall Scaleform::GFx::FontCompactor::navigateToEndGlyph(
        Scaleform::GFx::FontCompactor *this,
        unsigned int pos)
{
  unsigned int v2; // esi
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // edi
  unsigned int v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // esi
  unsigned int v7; // esi
  unsigned int v8; // esi
  unsigned __int8 **Pages; // ebp
  unsigned int v10; // esi
  unsigned int v11; // esi
  unsigned int i; // ebx
  unsigned int v; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 data[12]; // [esp+Ch] [ebp-Ch] BYREF

  v2 = pos;
  p_Decoder = &this->Decoder;
  v4 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         &this->Decoder,
         pos,
         (int *)&pos)
     + v2;
  v5 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         p_Decoder,
         v4,
         (int *)&pos)
     + v4;
  v6 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         p_Decoder,
         v5,
         (int *)&pos)
     + v5;
  v7 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
         p_Decoder,
         v6,
         (int *)&pos)
     + v6;
  v8 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt15(
         p_Decoder,
         v7,
         &pos)
     + v7;
  if ( pos )
  {
    Pages = p_Decoder->Data->Pages;
    do
    {
      --pos;
      v10 = ((Pages[v8 >> 12][v8 & 0xFFF] & 1) != 0) + 1 + v8;
      v11 = ((Pages[v10 >> 12][v10 & 0xFFF] & 1) != 0) + 1 + v10;
      v8 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
             p_Decoder,
             v11,
             &v)
         + v11;
      if ( (v & 1) == 0 )
      {
        for ( i = v >> 1;
              i;
              v8 += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadRawEdge(
                      p_Decoder,
                      v8,
                      data) )
        {
          --i;
        }
        v = i - 1;
      }
    }
    while ( pos );
  }
  return v8;
}

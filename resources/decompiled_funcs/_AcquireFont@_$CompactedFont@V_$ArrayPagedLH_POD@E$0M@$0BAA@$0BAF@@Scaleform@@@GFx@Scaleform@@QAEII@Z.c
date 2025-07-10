unsigned int __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int startPos)
{
  const Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // eax
  Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // esi
  unsigned int UInt32fixlen; // ebp
  unsigned int v10; // esi
  unsigned int v11; // esi
  int v12; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]
  signed int ia; // [esp+Ch] [ebp-4h]
  signed int ib; // [esp+Ch] [ebp-4h]
  signed int ic; // [esp+Ch] [ebp-4h]

  Data = this->Decoder.Data;
  p_Decoder = (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder;
  if ( Data->Size < startPos + 15 )
    return 0;
  i = 0;
  if ( Data->Pages[startPos >> 12][startPos & 0xFFF] )
  {
    v6 = startPos;
    do
    {
      ++i;
      ++v6;
    }
    while ( p_Decoder->Data->Pages[v6 >> 12][v6 & 0xFFF] );
  }
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>>::Reserve(
    (Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2> > *)&this->Name,
    i + 1,
    0);
  v7 = 0;
  this->Name.Size = i + 1;
  if ( i != -1 )
  {
    do
    {
      this->Name.Data[v7] = p_Decoder->Data->Pages[(v7 + startPos) >> 12][(v7 + startPos) & 0xFFF];
      ++v7;
    }
    while ( v7 < this->Name.Size );
  }
  v8 = startPos + this->Name.Size;
  this->Flags = p_Decoder->Data->Pages[v8 >> 12][((_WORD)startPos + LOWORD(this->Name.Size)) & 0xFFF]
              | (p_Decoder->Data->Pages[(v8 + 1) >> 12][(v8 + 1) & 0xFFF] << 8);
  v8 += 2;
  this->NominalSize = p_Decoder->Data->Pages[v8 >> 12][v8 & 0xFFF]
                    | (p_Decoder->Data->Pages[(v8 + 1) >> 12][(v8 + 1) & 0xFFF] << 8);
  v8 += 2;
  ia = (__int16)(p_Decoder->Data->Pages[v8 >> 12][v8 & 0xFFF]
               | (p_Decoder->Data->Pages[(v8 + 1) >> 12][(v8 + 1) & 0xFFF] << 8));
  v8 += 2;
  this->Ascent = (float)ia;
  ib = (__int16)(p_Decoder->Data->Pages[v8 >> 12][v8 & 0xFFF]
               | (p_Decoder->Data->Pages[(v8 + 1) >> 12][(v8 + 1) & 0xFFF] << 8));
  v8 += 2;
  this->Descent = (float)ib;
  ic = (__int16)(p_Decoder->Data->Pages[v8 >> 12][v8 & 0xFFF]
               | (p_Decoder->Data->Pages[(v8 + 1) >> 12][(v8 + 1) & 0xFFF] << 8));
  v8 += 2;
  this->Leading = (float)ic;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   p_Decoder,
                   v8);
  this->NumGlyphs = UInt32fixlen;
  v10 = v8
      + 4
      + Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
          p_Decoder,
          v8 + 4)
      + 4;
  this->GlyphInfoTablePos = v10;
  v11 = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
          p_Decoder,
          v10 + 8 * UInt32fixlen,
          &this->KerningTableSize)
      + v10
      + 8 * UInt32fixlen;
  v12 = 6 * this->KerningTableSize - startPos;
  this->KerningTablePos = v11;
  return v11 + v12;
}

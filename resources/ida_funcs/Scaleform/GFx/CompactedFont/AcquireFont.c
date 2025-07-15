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


unsigned int __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::AcquireFont(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int startPos)
{
  const Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *Data; // eax
  Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_Decoder; // edi
  int v7; // ecx
  unsigned __int8 *v8; // eax
  unsigned int v9; // eax
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  int v14; // eax
  unsigned int startPosa; // [esp+10h] [ebp+4h]
  signed int startPosb; // [esp+10h] [ebp+4h]
  signed int startPosc; // [esp+10h] [ebp+4h]
  signed int startPosd; // [esp+10h] [ebp+4h]

  Data = this->Decoder.Data;
  p_Decoder = (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&this->Decoder;
  if ( Data->Size < startPos + 15 )
    return 0;
  v7 = 0;
  if ( Data->Data[startPos] )
  {
    v8 = &Data->Data[startPos];
    do
    {
      ++v8;
      ++v7;
    }
    while ( *v8 );
  }
  startPosa = v7 + 1;
  Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>>::Reserve(
    (Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2> > *)&this->Name,
    v7 + 1,
    0);
  v9 = 0;
  this->Name.Size = startPosa;
  if ( this->Name.Size )
  {
    do
    {
      this->Name.Data[v9] = p_Decoder->Data->Data.Data[v9 + startPos];
      ++v9;
    }
    while ( v9 < this->Name.Size );
  }
  v10 = startPos + this->Name.Size;
  this->Flags = *(unsigned __int16 *)&p_Decoder->Data->Data.Data[v10];
  v10 += 2;
  this->NominalSize = *(unsigned __int16 *)&p_Decoder->Data->Data.Data[v10];
  v10 += 2;
  startPosb = *(__int16 *)&p_Decoder->Data->Data.Data[v10];
  v10 += 2;
  this->Ascent = (float)startPosb;
  startPosc = *(__int16 *)&p_Decoder->Data->Data.Data[v10];
  v10 += 2;
  this->Descent = (float)startPosc;
  startPosd = *(__int16 *)&p_Decoder->Data->Data.Data[v10];
  v10 += 2;
  this->Leading = (float)startPosd;
  this->NumGlyphs = p_Decoder->Data->Data.Data[v10]
                  | ((p_Decoder->Data->Data.Data[v10 + 1]
                    | (*(unsigned __int16 *)&p_Decoder->Data->Data.Data[v10 + 2] << 8)) << 8);
  v10 += 4;
  v11 = v10
      + (p_Decoder->Data->Data.Data[v10]
       | ((p_Decoder->Data->Data.Data[v10 + 1]
         | ((p_Decoder->Data->Data.Data[v10 + 2] | (p_Decoder->Data->Data.Data[v10 + 3] << 8)) << 8)) << 8))
      + 4;
  v12 = v11 + 8 * this->NumGlyphs;
  this->GlyphInfoTablePos = v11;
  v13 = Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
          p_Decoder,
          v12,
          &this->KerningTableSize)
      + v12;
  v14 = 6 * this->KerningTableSize - startPos;
  this->KerningTablePos = v13;
  return v13 + v14;
}

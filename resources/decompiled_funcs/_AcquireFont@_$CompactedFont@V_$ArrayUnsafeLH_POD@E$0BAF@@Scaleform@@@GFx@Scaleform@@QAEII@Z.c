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

void __thiscall Scaleform::GFx::SwfShapeDecoder::SwfShapeDecoder(
        Scaleform::GFx::SwfShapeDecoder *this,
        Scaleform::Render::ShapePosInfo *pos,
        const unsigned __int8 *shapeData,
        float sfactor)
{
  unsigned int v5; // ecx
  unsigned int CurByteIndex; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned int v9; // edx
  Scaleform::Render::ShapePosInfo *v10; // edx
  int v11; // ecx
  Scaleform::Render::ShapePosInfo *v12; // edx
  int v13; // ecx
  Scaleform::Render::ShapePosInfo *v14; // edx
  int v15; // ecx
  Scaleform::Render::ShapePosInfo *v16; // edx
  int v17; // ecx
  unsigned int v18; // edx
  int v19; // ecx
  Scaleform::Render::ShapePosInfo *v20; // edx
  unsigned int v21; // edx
  const unsigned __int8 *v22; // esi
  unsigned __int8 v23; // cl
  int v24; // esi
  Scaleform::Render::ShapePosInfo *v25; // edx
  unsigned int v26; // edx
  const unsigned __int8 *v27; // esi
  unsigned __int8 v28; // cl
  int v29; // esi
  Scaleform::Render::ShapePosInfo *v30; // edx
  unsigned int v31; // edx
  const unsigned __int8 *v32; // esi
  unsigned __int8 v33; // cl
  int v34; // esi
  Scaleform::Render::ShapePosInfo *v35; // edx

  this->Stream.pData = shapeData;
  this->Stream.DataSize = -1;
  this->Stream.CurByteIndex = 0;
  this->Stream.CurBitIndex = 0;
  this->Pos = pos;
  if ( pos->Initialized )
  {
    this->Stream.CurByteIndex = pos->Pos >> 11;
    this->Stream.CurBitIndex = pos->Pos & 7;
  }
  else
  {
    pos->Sfactor = sfactor;
    this->Pos->StrokeBase = 0;
    this->Pos->FillBase = 0;
    if ( pos->Pos )
    {
      this->Pos->NumFillBits = (pos->Pos >> 7) & 0xF;
      this->Pos->NumStrokeBits = (pos->Pos >> 3) & 0xF;
      this->Stream.CurByteIndex = pos->Pos >> 11;
      this->Stream.CurBitIndex = pos->Pos & 7;
    }
    else
    {
      switch ( this->Stream.CurBitIndex )
      {
        case 0u:
          v5 = this->Stream.pData[this->Stream.CurByteIndex] >> 4;
          this->Stream.CurBitIndex = 4;
          break;
        case 1u:
          v5 = (this->Stream.pData[this->Stream.CurByteIndex] >> 3) & 0xF;
          this->Stream.CurBitIndex = 5;
          break;
        case 2u:
          v5 = (this->Stream.pData[this->Stream.CurByteIndex] >> 2) & 0xF;
          this->Stream.CurBitIndex = 6;
          break;
        case 3u:
          v5 = (this->Stream.pData[this->Stream.CurByteIndex] >> 1) & 0xF;
          this->Stream.CurBitIndex = 7;
          break;
        case 4u:
          CurByteIndex = this->Stream.CurByteIndex;
          v5 = this->Stream.pData[CurByteIndex] & 0xF;
          this->Stream.CurBitIndex = 0;
          this->Stream.CurByteIndex = CurByteIndex + 1;
          break;
        case 5u:
          v7 = this->Stream.CurByteIndex;
          v5 = (this->Stream.pData[v7 + 1] >> 7) | (2 * (this->Stream.pData[v7] & 7));
          this->Stream.CurBitIndex = 1;
          this->Stream.CurByteIndex = v7 + 1;
          break;
        case 6u:
          v8 = this->Stream.CurByteIndex;
          v5 = (this->Stream.pData[v8 + 1] >> 6) | (4 * (this->Stream.pData[v8] & 3));
          this->Stream.CurBitIndex = 2;
          this->Stream.CurByteIndex = v8 + 1;
          break;
        case 7u:
          v9 = this->Stream.CurByteIndex;
          v5 = (this->Stream.pData[v9 + 1] >> 5) | (8 * (this->Stream.pData[v9] & 1));
          this->Stream.CurBitIndex = 3;
          this->Stream.CurByteIndex = v9 + 1;
          break;
        default:
          v5 = 0;
          break;
      }
      this->Pos->NumFillBits = v5;
      switch ( this->Stream.CurBitIndex )
      {
        case 0u:
          v10 = this->Pos;
          v11 = this->Stream.pData[this->Stream.CurByteIndex] >> 4;
          this->Stream.CurBitIndex = 4;
          v10->NumStrokeBits = v11;
          break;
        case 1u:
          v12 = this->Pos;
          v13 = (this->Stream.pData[this->Stream.CurByteIndex] >> 3) & 0xF;
          this->Stream.CurBitIndex = 5;
          v12->NumStrokeBits = v13;
          break;
        case 2u:
          v14 = this->Pos;
          v15 = (this->Stream.pData[this->Stream.CurByteIndex] >> 2) & 0xF;
          this->Stream.CurBitIndex = 6;
          v14->NumStrokeBits = v15;
          break;
        case 3u:
          v16 = this->Pos;
          v17 = (this->Stream.pData[this->Stream.CurByteIndex] >> 1) & 0xF;
          this->Stream.CurBitIndex = 7;
          v16->NumStrokeBits = v17;
          break;
        case 4u:
          v18 = this->Stream.CurByteIndex;
          v19 = this->Stream.pData[v18] & 0xF;
          this->Stream.CurByteIndex = v18 + 1;
          v20 = this->Pos;
          this->Stream.CurBitIndex = 0;
          v20->NumStrokeBits = v19;
          break;
        case 5u:
          v21 = this->Stream.CurByteIndex;
          v22 = &this->Stream.pData[v21];
          v23 = *v22;
          v24 = v22[1] >> 7;
          this->Stream.CurByteIndex = v21 + 1;
          v25 = this->Pos;
          this->Stream.CurBitIndex = 1;
          v25->NumStrokeBits = v24 | (2 * (v23 & 7));
          break;
        case 6u:
          v26 = this->Stream.CurByteIndex;
          v27 = &this->Stream.pData[v26];
          v28 = *v27;
          v29 = v27[1] >> 6;
          this->Stream.CurByteIndex = v26 + 1;
          v30 = this->Pos;
          this->Stream.CurBitIndex = 2;
          v30->NumStrokeBits = v29 | (4 * (v28 & 3));
          break;
        case 7u:
          v31 = this->Stream.CurByteIndex;
          v32 = &this->Stream.pData[v31];
          v33 = *v32;
          v34 = v32[1] >> 5;
          this->Stream.CurByteIndex = v31 + 1;
          v35 = this->Pos;
          this->Stream.CurBitIndex = 3;
          v35->NumStrokeBits = v34 | (8 * (v33 & 1));
          break;
        default:
          this->Pos->NumStrokeBits = 0;
          break;
      }
    }
    this->Pos->LastY = 0;
    this->Pos->LastX = 0;
    this->Pos->Stroke = 0;
    this->Pos->Fill1 = 0;
    this->Pos->Fill0 = 0;
    this->Pos->Initialized = 1;
  }
}

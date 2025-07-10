int __thiscall Scaleform::GFx::SwfShapeDecoder::ReadEdge(
        Scaleform::GFx::SwfShapeDecoder *this,
        Scaleform::GFx::SwfShapeDecoder::Edge *edge)
{
  unsigned int CurBitIndex; // edi
  unsigned int CurByteIndex; // ebx
  const unsigned __int8 *pData; // edx
  int v6; // eax
  bool v7; // zf
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // edi
  int v15; // ebp
  unsigned int UInt; // ebx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  unsigned int v26; // ebp
  unsigned int v27; // ebx
  int v28; // edx
  unsigned int v29; // edi
  int v30; // eax
  unsigned int v31; // ebp
  unsigned int v32; // eax
  int v33; // ebx
  unsigned int v34; // eax
  unsigned int v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  int dy; // [esp+10h] [ebp-8h]
  int dya; // [esp+10h] [ebp-8h]
  int v43; // [esp+14h] [ebp-4h]

  if ( ++this->Stream.CurBitIndex >= 8 )
  {
    ++this->Stream.CurByteIndex;
    this->Stream.CurBitIndex = 0;
  }
  CurBitIndex = this->Stream.CurBitIndex;
  CurByteIndex = this->Stream.CurByteIndex;
  pData = this->Stream.pData;
  v6 = (unsigned __int8)this->Stream.pData[CurByteIndex] & (1 << (7 - CurBitIndex));
  this->Stream.CurBitIndex = CurBitIndex + 1;
  if ( CurBitIndex + 1 >= 8 )
  {
    this->Stream.CurBitIndex = 0;
    this->Stream.CurByteIndex = CurByteIndex + 1;
  }
  v7 = v6 == 0;
  v8 = this->Stream.CurBitIndex;
  if ( v7 )
  {
    switch ( v8 )
    {
      case 0u:
        v9 = pData[this->Stream.CurByteIndex] >> 4;
        this->Stream.CurBitIndex = 4;
        break;
      case 1u:
        v9 = (pData[this->Stream.CurByteIndex] >> 3) & 0xF;
        this->Stream.CurBitIndex = 5;
        break;
      case 2u:
        v9 = (pData[this->Stream.CurByteIndex] >> 2) & 0xF;
        this->Stream.CurBitIndex = 6;
        break;
      case 3u:
        v9 = (pData[this->Stream.CurByteIndex] >> 1) & 0xF;
        this->Stream.CurBitIndex = 7;
        break;
      case 4u:
        v10 = this->Stream.CurByteIndex;
        v9 = pData[v10] & 0xF;
        this->Stream.CurBitIndex = 0;
        this->Stream.CurByteIndex = v10 + 1;
        break;
      case 5u:
        v11 = this->Stream.CurByteIndex;
        v9 = (2 * (pData[v11] & 7)) | (pData[v11 + 1] >> 7);
        this->Stream.CurBitIndex = 1;
        this->Stream.CurByteIndex = v11 + 1;
        break;
      case 6u:
        v12 = this->Stream.CurByteIndex;
        v9 = (4 * (pData[v12] & 3)) | (pData[v12 + 1] >> 6);
        this->Stream.CurBitIndex = 2;
        this->Stream.CurByteIndex = v12 + 1;
        break;
      case 7u:
        v13 = this->Stream.CurByteIndex;
        v9 = (8 * (pData[v13] & 1)) | (pData[v13 + 1] >> 5);
        this->Stream.CurBitIndex = 3;
        this->Stream.CurByteIndex = v13 + 1;
        break;
      default:
        v9 = 0;
        break;
    }
    v14 = v9 + 2;
    v15 = 1 << (v9 + 1);
    UInt = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v9 + 2);
    if ( (v15 & UInt) != 0 )
      UInt |= -1 << v14;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v14);
    dy = v17;
    if ( (v15 & v17) != 0 )
      dy = (-1 << v14) | v17;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v14);
    v43 = v18;
    if ( (v15 & v18) != 0 )
      v43 = (-1 << v14) | v18;
    v19 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v14);
    if ( (v15 & v19) != 0 )
      v19 |= -1 << v14;
    edge->Cx = UInt + this->Pos->LastX;
    edge->Cy = dy + this->Pos->LastY;
    this->Pos->LastX += UInt + v43;
    this->Pos->LastY += dy + v19;
    edge->Ax = this->Pos->LastX;
    edge->Ay = this->Pos->LastY;
    edge->Curve = 1;
    return 2;
  }
  else
  {
    switch ( v8 )
    {
      case 0u:
        v21 = pData[this->Stream.CurByteIndex] >> 4;
        this->Stream.CurBitIndex = 4;
        break;
      case 1u:
        v21 = (pData[this->Stream.CurByteIndex] >> 3) & 0xF;
        this->Stream.CurBitIndex = 5;
        break;
      case 2u:
        v21 = (pData[this->Stream.CurByteIndex] >> 2) & 0xF;
        this->Stream.CurBitIndex = 6;
        break;
      case 3u:
        v21 = (pData[this->Stream.CurByteIndex] >> 1) & 0xF;
        this->Stream.CurBitIndex = 7;
        break;
      case 4u:
        v22 = this->Stream.CurByteIndex;
        v21 = pData[v22] & 0xF;
        this->Stream.CurBitIndex = 0;
        this->Stream.CurByteIndex = v22 + 1;
        break;
      case 5u:
        v23 = this->Stream.CurByteIndex;
        v21 = (2 * (pData[v23] & 7)) | (pData[v23 + 1] >> 7);
        this->Stream.CurBitIndex = 1;
        this->Stream.CurByteIndex = v23 + 1;
        break;
      case 6u:
        v24 = this->Stream.CurByteIndex;
        v21 = (4 * (pData[v24] & 3)) | (pData[v24 + 1] >> 6);
        this->Stream.CurBitIndex = 2;
        this->Stream.CurByteIndex = v24 + 1;
        break;
      case 7u:
        v25 = this->Stream.CurByteIndex;
        v21 = (8 * (pData[v25] & 1)) | (pData[v25 + 1] >> 5);
        this->Stream.CurBitIndex = 3;
        this->Stream.CurByteIndex = v25 + 1;
        break;
      default:
        v21 = 0;
        break;
    }
    v26 = this->Stream.CurBitIndex;
    v27 = this->Stream.CurByteIndex;
    v28 = pData[v27];
    v29 = v21 + 2;
    this->Stream.CurBitIndex = v26 + 1;
    v30 = v28 & (1 << (7 - v26));
    if ( v26 + 1 >= 8 )
    {
      this->Stream.CurBitIndex = 0;
      this->Stream.CurByteIndex = v27 + 1;
    }
    v31 = 0;
    edge->Curve = 0;
    dya = 0;
    if ( v30 )
    {
      v32 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v29);
      v33 = 1 << (v29 - 1);
      if ( (v33 & v32) != 0 )
        v32 |= -1 << v29;
      v31 = v32;
      v34 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v29);
      if ( (v33 & v34) != 0 )
        v34 |= -1 << v29;
      v35 = v34;
    }
    else
    {
      v36 = this->Stream.CurBitIndex;
      v37 = this->Stream.CurByteIndex;
      v38 = (unsigned __int8)this->Stream.pData[v37] & (1 << (7 - v36));
      this->Stream.CurBitIndex = v36 + 1;
      if ( v36 + 1 >= 8 )
      {
        this->Stream.CurBitIndex = 0;
        this->Stream.CurByteIndex = v37 + 1;
      }
      if ( v38 )
      {
        v40 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v29);
        if ( ((1 << (v29 - 1)) & v40) != 0 )
          v40 |= -1 << v29;
        dya = v40;
      }
      else
      {
        v39 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v29);
        if ( ((1 << (v29 - 1)) & v39) != 0 )
          v39 |= -1 << v29;
        v31 = v39;
      }
      v35 = dya;
    }
    edge->Ax = v31 + this->Pos->LastX;
    edge->Ay = v35 + this->Pos->LastY;
    this->Pos->LastX += v31;
    this->Pos->LastY += v35;
    return 1;
  }
}

Scaleform::Render::ShapePathType __thiscall Scaleform::GFx::SwfShapeDecoder::ReadNonEdgeRec(
        Scaleform::GFx::SwfShapeDecoder *this,
        Scaleform::Render::ShapePathType retVal)
{
  const unsigned __int8 *pData; // eax
  int v4; // ebx
  unsigned int CurByteIndex; // ecx
  int v6; // ebx
  int v7; // edi
  Scaleform::Render::ShapePathType result; // eax
  unsigned int v9; // edi
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  int UInt; // eax
  int v16; // ebp
  int v17; // eax
  Scaleform::Render::ShapePosInfo *Pos; // edx
  unsigned int v19; // eax
  signed int v20; // eax
  signed int v21; // eax
  unsigned int v22; // edx
  const unsigned __int8 *v23; // ecx
  unsigned __int8 v24; // al
  unsigned int v25; // edi
  unsigned int v26; // edx
  unsigned __int8 v27; // bl
  unsigned int v28; // edx
  int v29; // edi
  unsigned __int8 v30; // bl
  int v31; // eax
  unsigned __int8 v32; // bl
  unsigned int v33; // ebx
  unsigned int v34; // edx
  unsigned int v35; // ebx
  unsigned __int8 v36; // dl
  unsigned int v37; // ebp
  unsigned __int8 v38; // bl
  int v39; // eax
  unsigned int v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  Scaleform::Render::ShapePosInfo *v46; // eax
  unsigned int v47; // ecx
  Scaleform::Render::ShapePosInfo *v48; // eax
  unsigned int v49; // ecx
  Scaleform::Render::ShapePosInfo *v50; // eax
  unsigned int v51; // ecx
  Scaleform::Render::ShapePosInfo *v52; // eax
  unsigned int v53; // eax
  int v54; // ecx
  Scaleform::Render::ShapePosInfo *v55; // eax
  unsigned int v56; // eax
  int v57; // ecx
  Scaleform::Render::ShapePosInfo *v58; // eax
  unsigned int v59; // eax
  const unsigned __int8 *v60; // edx
  unsigned int v61; // ecx
  int v62; // edx
  Scaleform::Render::ShapePosInfo *v63; // eax
  unsigned int v64; // eax
  const unsigned __int8 *v65; // edx
  unsigned int v66; // ecx
  int v67; // edx
  Scaleform::Render::ShapePosInfo *v68; // eax

  if ( ++this->Stream.CurBitIndex >= 8 )
  {
    ++this->Stream.CurByteIndex;
    this->Stream.CurBitIndex = 0;
  }
  switch ( this->Stream.CurBitIndex )
  {
    case 0u:
      pData = this->Stream.pData;
      v4 = this->Stream.pData[this->Stream.CurByteIndex] >> 3;
      this->Stream.CurBitIndex = 5;
      goto LABEL_14;
    case 1u:
      pData = this->Stream.pData;
      v4 = (this->Stream.pData[this->Stream.CurByteIndex] >> 2) & 0x1F;
      this->Stream.CurBitIndex = 6;
      goto LABEL_14;
    case 2u:
      pData = this->Stream.pData;
      v4 = (this->Stream.pData[this->Stream.CurByteIndex] >> 1) & 0x1F;
      this->Stream.CurBitIndex = 7;
      goto LABEL_14;
    case 3u:
      CurByteIndex = this->Stream.CurByteIndex;
      pData = this->Stream.pData;
      v4 = this->Stream.pData[CurByteIndex] & 0x1F;
      this->Stream.CurBitIndex = 0;
      goto LABEL_13;
    case 4u:
      CurByteIndex = this->Stream.CurByteIndex;
      pData = this->Stream.pData;
      v6 = this->Stream.pData[CurByteIndex + 1] >> 7;
      v7 = 2 * (this->Stream.pData[CurByteIndex] & 0xF);
      this->Stream.CurBitIndex = 1;
      goto LABEL_12;
    case 5u:
      CurByteIndex = this->Stream.CurByteIndex;
      pData = this->Stream.pData;
      v6 = this->Stream.pData[CurByteIndex + 1] >> 6;
      v7 = 4 * (this->Stream.pData[CurByteIndex] & 7);
      this->Stream.CurBitIndex = 2;
      goto LABEL_12;
    case 6u:
      CurByteIndex = this->Stream.CurByteIndex;
      pData = this->Stream.pData;
      v6 = this->Stream.pData[CurByteIndex + 1] >> 5;
      v7 = 8 * (this->Stream.pData[CurByteIndex] & 3);
      this->Stream.CurBitIndex = 3;
      goto LABEL_12;
    case 7u:
      CurByteIndex = this->Stream.CurByteIndex;
      pData = this->Stream.pData;
      v6 = this->Stream.pData[CurByteIndex + 1] >> 4;
      v7 = 16 * (this->Stream.pData[CurByteIndex] & 1);
      this->Stream.CurBitIndex = 4;
LABEL_12:
      v4 = v7 | v6;
LABEL_13:
      this->Stream.CurByteIndex = CurByteIndex + 1;
LABEL_14:
      if ( !v4 )
        goto LABEL_15;
      if ( (v4 & 1) != 0 )
      {
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v9 = pData[this->Stream.CurByteIndex] >> 3;
            this->Stream.CurBitIndex = 5;
            break;
          case 1u:
            v9 = (pData[this->Stream.CurByteIndex] >> 2) & 0x1F;
            this->Stream.CurBitIndex = 6;
            break;
          case 2u:
            v9 = (pData[this->Stream.CurByteIndex] >> 1) & 0x1F;
            this->Stream.CurBitIndex = 7;
            break;
          case 3u:
            v10 = this->Stream.CurByteIndex;
            v9 = pData[v10] & 0x1F;
            this->Stream.CurBitIndex = 0;
            this->Stream.CurByteIndex = v10 + 1;
            break;
          case 4u:
            v11 = this->Stream.CurByteIndex;
            v9 = (2 * (pData[v11] & 0xF)) | (pData[v11 + 1] >> 7);
            this->Stream.CurBitIndex = 1;
            this->Stream.CurByteIndex = v11 + 1;
            break;
          case 5u:
            v12 = this->Stream.CurByteIndex;
            v9 = (4 * (pData[v12] & 7)) | (pData[v12 + 1] >> 6);
            this->Stream.CurBitIndex = 2;
            this->Stream.CurByteIndex = v12 + 1;
            break;
          case 6u:
            v13 = this->Stream.CurByteIndex;
            v9 = (8 * (pData[v13] & 3)) | (pData[v13 + 1] >> 5);
            this->Stream.CurBitIndex = 3;
            this->Stream.CurByteIndex = v13 + 1;
            break;
          case 7u:
            v14 = this->Stream.CurByteIndex;
            v9 = (16 * (pData[v14] & 1)) | (pData[v14 + 1] >> 4);
            this->Stream.CurBitIndex = 4;
            this->Stream.CurByteIndex = v14 + 1;
            break;
          default:
            v9 = 0;
            break;
        }
        UInt = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v9);
        v16 = 1 << (v9 - 1);
        if ( (v16 & UInt) != 0 )
          UInt |= -1 << v9;
        this->Pos->LastX = UInt;
        v17 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, v9);
        if ( (v16 & v17) != 0 )
          v17 |= -1 << v9;
        this->Pos->LastY = v17;
      }
      if ( (v4 & 2) != 0 )
      {
        Pos = this->Pos;
        if ( Pos->NumFillBits )
        {
          v19 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, Pos->NumFillBits);
          if ( v19 )
            v19 += this->Pos->FillBase;
          this->Pos->Fill0 = v19;
        }
      }
      if ( (v4 & 4) != 0 && this->Pos->NumFillBits )
      {
        v20 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, this->Pos->NumFillBits);
        if ( v20 > 0 )
          v20 += this->Pos->FillBase;
        this->Pos->Fill1 = v20;
      }
      if ( (v4 & 8) != 0 && this->Pos->NumStrokeBits )
      {
        v21 = Scaleform::GFx::StreamContext::ReadUInt(&this->Stream, this->Pos->NumStrokeBits);
        if ( v21 > 0 )
          v21 += this->Pos->StrokeBase;
        this->Pos->Stroke = v21;
      }
      if ( (v4 & 0x10) != 0 )
      {
        this->Pos->Stroke = 0;
        this->Pos->Fill1 = 0;
        this->Pos->Fill0 = 0;
        if ( this->Stream.CurBitIndex )
          ++this->Stream.CurByteIndex;
        v22 = this->Stream.CurByteIndex;
        v23 = this->Stream.pData;
        this->Stream.CurBitIndex = 0;
        v24 = v23[v22];
        v25 = v24;
        v26 = v22 + 1;
        this->Stream.CurByteIndex = v26;
        if ( v24 )
        {
          this->Stream.CurBitIndex = 0;
          v27 = v23[v26];
          v28 = v26 + 1;
          this->Stream.CurByteIndex = v28;
          v29 = v27;
          this->Stream.CurBitIndex = 0;
          v30 = v23[v28];
          this->Stream.CurByteIndex = ++v28;
          v31 = v30;
          this->Stream.CurBitIndex = 0;
          v32 = v23[v28];
          this->Stream.CurByteIndex = v28 + 1;
          v25 = v32 | (v31 << 8) | (v29 << 16);
        }
        v33 = this->Stream.CurByteIndex;
        this->Stream.CurBitIndex = 0;
        v34 = v23[v33];
        v35 = v33 + 1;
        this->Stream.CurByteIndex = v35;
        if ( v34 == 255 )
        {
          this->Stream.CurBitIndex = 0;
          v36 = v23[v35];
          v37 = v35 + 1;
          this->Stream.CurByteIndex = v35 + 1;
          this->Stream.CurBitIndex = 0;
          v38 = v23[v35 + 1];
          this->Stream.CurByteIndex = ++v37;
          this->Stream.CurBitIndex = 0;
          v39 = v23[v37];
          this->Stream.CurByteIndex = v37 + 1;
          v34 = v39 | (v38 << 8) | (v36 << 16);
        }
        this->Pos->FillBase = v25;
        this->Pos->StrokeBase = v34;
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v40 = this->Stream.pData[this->Stream.CurByteIndex] >> 4;
            this->Stream.CurBitIndex = 4;
            break;
          case 1u:
            v40 = (this->Stream.pData[this->Stream.CurByteIndex] >> 3) & 0xF;
            this->Stream.CurBitIndex = 5;
            break;
          case 2u:
            v40 = (this->Stream.pData[this->Stream.CurByteIndex] >> 2) & 0xF;
            this->Stream.CurBitIndex = 6;
            break;
          case 3u:
            v40 = (this->Stream.pData[this->Stream.CurByteIndex] >> 1) & 0xF;
            this->Stream.CurBitIndex = 7;
            break;
          case 4u:
            v41 = this->Stream.CurByteIndex;
            v40 = this->Stream.pData[v41] & 0xF;
            this->Stream.CurBitIndex = 0;
            this->Stream.CurByteIndex = v41 + 1;
            break;
          case 5u:
            v42 = this->Stream.CurByteIndex;
            v40 = (2 * (this->Stream.pData[v42] & 7)) | (this->Stream.pData[v42 + 1] >> 7);
            this->Stream.CurBitIndex = 1;
            this->Stream.CurByteIndex = v42 + 1;
            break;
          case 6u:
            v43 = this->Stream.CurByteIndex;
            v40 = (4 * (this->Stream.pData[v43] & 3)) | (this->Stream.pData[v43 + 1] >> 6);
            this->Stream.CurBitIndex = 2;
            this->Stream.CurByteIndex = v43 + 1;
            break;
          case 7u:
            v44 = this->Stream.CurByteIndex;
            v40 = (8 * (this->Stream.pData[v44] & 1)) | (this->Stream.pData[v44 + 1] >> 5);
            this->Stream.CurBitIndex = 3;
            this->Stream.CurByteIndex = v44 + 1;
            break;
          default:
            v40 = 0;
            break;
        }
        this->Pos->NumFillBits = v40;
        switch ( this->Stream.CurBitIndex )
        {
          case 0u:
            v45 = this->Stream.pData[this->Stream.CurByteIndex];
            v46 = this->Pos;
            this->Stream.CurBitIndex = 4;
            v46->NumStrokeBits = v45 >> 4;
            result = Shape_NewLayer;
            break;
          case 1u:
            v47 = this->Stream.pData[this->Stream.CurByteIndex];
            v48 = this->Pos;
            this->Stream.CurBitIndex = 5;
            v48->NumStrokeBits = (v47 >> 3) & 0xF;
            result = Shape_NewLayer;
            break;
          case 2u:
            v49 = this->Stream.pData[this->Stream.CurByteIndex];
            v50 = this->Pos;
            this->Stream.CurBitIndex = 6;
            v50->NumStrokeBits = (v49 >> 2) & 0xF;
            result = Shape_NewLayer;
            break;
          case 3u:
            v51 = this->Stream.pData[this->Stream.CurByteIndex];
            v52 = this->Pos;
            this->Stream.CurBitIndex = 7;
            v52->NumStrokeBits = (v51 >> 1) & 0xF;
            result = Shape_NewLayer;
            break;
          case 4u:
            v53 = this->Stream.CurByteIndex;
            v54 = this->Stream.pData[v53] & 0xF;
            this->Stream.CurByteIndex = v53 + 1;
            v55 = this->Pos;
            this->Stream.CurBitIndex = 0;
            v55->NumStrokeBits = v54;
            result = Shape_NewLayer;
            break;
          case 5u:
            v56 = this->Stream.CurByteIndex;
            v57 = (2 * (this->Stream.pData[v56] & 7)) | (this->Stream.pData[v56 + 1] >> 7);
            this->Stream.CurByteIndex = v56 + 1;
            v58 = this->Pos;
            this->Stream.CurBitIndex = 1;
            v58->NumStrokeBits = v57;
            result = Shape_NewLayer;
            break;
          case 6u:
            v59 = this->Stream.CurByteIndex;
            v60 = &this->Stream.pData[v59];
            v61 = v60[1];
            v62 = 4 * (*v60 & 3);
            this->Stream.CurByteIndex = v59 + 1;
            v63 = this->Pos;
            this->Stream.CurBitIndex = 2;
            v63->NumStrokeBits = v62 | (v61 >> 6);
            result = Shape_NewLayer;
            break;
          case 7u:
            v64 = this->Stream.CurByteIndex;
            v65 = &this->Stream.pData[v64];
            v66 = v65[1];
            v67 = 8 * (*v65 & 1);
            this->Stream.CurByteIndex = v64 + 1;
            v68 = this->Pos;
            this->Stream.CurBitIndex = 3;
            v68->NumStrokeBits = v67 | (v66 >> 5);
            result = Shape_NewLayer;
            break;
          default:
            this->Pos->NumStrokeBits = 0;
            result = Shape_NewLayer;
            break;
        }
      }
      else
      {
        result = retVal;
      }
      break;
    default:
LABEL_15:
      result = Shape_EndShape;
      break;
  }
  return result;
}

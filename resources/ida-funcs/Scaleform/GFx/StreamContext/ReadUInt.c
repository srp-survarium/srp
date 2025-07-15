unsigned int __thiscall Scaleform::GFx::StreamContext::ReadUInt(
        Scaleform::GFx::StreamContext *this,
        unsigned int bitcount)
{
  unsigned int CurBitIndex; // ebx
  int v4; // edi
  unsigned int v5; // ebx
  char v6; // di
  unsigned int result; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  unsigned int v10; // ecx
  unsigned int CurByteIndex; // esi
  const unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  const unsigned __int8 *pData; // ecx
  int v16; // esi
  unsigned int v17; // edi

  CurBitIndex = this->CurBitIndex;
  v4 = 1 << (8 - CurBitIndex);
  v5 = bitcount + CurBitIndex;
  v6 = v4 - 1;
  switch ( bitcount )
  {
    case 0u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
      return 0;
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
      if ( v5 > 8 )
        goto LABEL_8;
      result = (unsigned __int8)(v6 & this->pData[this->CurByteIndex]);
      v8 = 8;
      goto LABEL_5;
    case 9u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
      if ( v5 > 0x10 )
      {
        CurByteIndex = this->CurByteIndex;
        v12 = &this->pData[CurByteIndex];
        v13 = (v12[1] | ((unsigned __int8)(v6 & this->pData[CurByteIndex]) << 8)) << 8;
LABEL_10:
        result = v12[2] | v13;
        this->CurByteIndex = CurByteIndex + 2;
        v8 = 24;
      }
      else
      {
LABEL_8:
        v10 = this->CurByteIndex;
        result = (unsigned __int8)this->pData[v10 + 1] | ((unsigned __int8)(v6 & this->pData[v10]) << 8);
        this->CurByteIndex = v10 + 1;
        v8 = 16;
      }
      goto LABEL_5;
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
      CurByteIndex = this->CurByteIndex;
      v12 = &this->pData[CurByteIndex];
      v13 = (v12[1] | ((unsigned __int8)(v6 & *v12) << 8)) << 8;
      if ( v5 <= 0x18 )
        goto LABEL_10;
      goto LABEL_15;
    case 0x19u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Du:
    case 0x1Eu:
    case 0x1Fu:
    case 0x20u:
      if ( v5 > 0x20 )
      {
        v14 = this->CurByteIndex;
        pData = this->pData;
        v16 = (unsigned __int8)this->pData[v14 + 3]
            | (((unsigned __int8)this->pData[v14 + 2]
              | (((unsigned __int8)this->pData[v14 + 1] | ((unsigned __int8)(v6 & this->pData[v14]) << 8)) << 8)) << 8);
        this->CurByteIndex = v14 + 4;
        v17 = pData[v14 + 4];
        this->CurBitIndex = v5 - 32;
        return (v16 << (v5 - 32)) | (v17 >> (8 - (v5 - 32)));
      }
      else
      {
        CurByteIndex = this->CurByteIndex;
        v12 = &this->pData[CurByteIndex];
        v13 = (v12[1] | ((unsigned __int8)(v6 & *v12) << 8)) << 8;
LABEL_15:
        result = v12[3] | ((v12[2] | v13) << 8);
        this->CurByteIndex = CurByteIndex + 3;
        v8 = 32;
LABEL_5:
        v9 = v8 - v5;
        if ( v9 )
        {
          result >>= v9;
          this->CurBitIndex = 8 - v9;
        }
        else
        {
LABEL_18:
          ++this->CurByteIndex;
          this->CurBitIndex = 0;
        }
      }
      return result;
    default:
      result = 0;
      goto LABEL_18;
  }
}

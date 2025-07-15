void __thiscall Scaleform::GFx::StreamContext::ReadMatrix(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Matrix2x4<float> *pm)
{
  unsigned int CurBitIndex; // edx
  unsigned int CurByteIndex; // ebx
  int v6; // eax
  unsigned int UInt; // ebx
  unsigned int v8; // eax
  int v9; // ebp
  unsigned int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ebx
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  int v16; // ebp
  unsigned int v17; // eax
  signed int v18; // eax
  unsigned int v19; // ebx
  unsigned int v20; // eax
  int v21; // ebp
  unsigned int v22; // eax
  int v23; // [esp+14h] [ebp+4h]
  int v24; // [esp+14h] [ebp+4h]
  int v25; // [esp+14h] [ebp+4h]
  int v26; // [esp+14h] [ebp+4h]
  int v27; // [esp+14h] [ebp+4h]
  int v28; // [esp+14h] [ebp+4h]

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  this->CurBitIndex = 0;
  pm->M[0][0] = 1.0;
  pm->M[0][1] = 0.0;
  pm->M[0][2] = 0.0;
  pm->M[0][3] = 0.0;
  pm->M[1][0] = 0.0;
  pm->M[1][2] = 0.0;
  pm->M[1][3] = 0.0;
  pm->M[1][1] = 1.0;
  CurBitIndex = this->CurBitIndex;
  CurByteIndex = this->CurByteIndex;
  v6 = (unsigned __int8)this->pData[CurByteIndex] & (1 << (7 - CurBitIndex));
  this->CurBitIndex = CurBitIndex + 1;
  if ( CurBitIndex + 1 >= 8 )
  {
    this->CurBitIndex = 0;
    this->CurByteIndex = CurByteIndex + 1;
  }
  if ( v6 )
  {
    UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
    v8 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v9 = 1 << (UInt - 1);
    v23 = v8;
    if ( (v9 & v8) != 0 )
      v23 = (-1 << UInt) | v8;
    pm->M[0][0] = (double)v23 * 0.0000152587890625;
    v10 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v24 = v10;
    if ( (v9 & v10) != 0 )
      v24 = (-1 << UInt) | v10;
    pm->M[1][1] = (double)v24 * 0.0000152587890625;
  }
  v11 = this->CurBitIndex;
  v12 = this->CurByteIndex;
  v13 = (unsigned __int8)this->pData[v12] & (1 << (7 - v11));
  this->CurBitIndex = v11 + 1;
  if ( v11 + 1 >= 8 )
  {
    this->CurBitIndex = 0;
    this->CurByteIndex = v12 + 1;
  }
  if ( v13 )
  {
    v14 = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
    v15 = Scaleform::GFx::StreamContext::ReadUInt(this, v14);
    v16 = 1 << (v14 - 1);
    v25 = v15;
    if ( (v16 & v15) != 0 )
      v25 = (-1 << v14) | v15;
    pm->M[1][0] = (double)v25 * 0.0000152587890625;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(this, v14);
    v26 = v17;
    if ( (v16 & v17) != 0 )
      v26 = (-1 << v14) | v17;
    pm->M[0][1] = 0.0000152587890625 * (double)v26;
  }
  v18 = Scaleform::GFx::StreamContext::ReadUInt(this, 5u);
  v19 = v18;
  if ( v18 > 0 )
  {
    v20 = Scaleform::GFx::StreamContext::ReadUInt(this, v18);
    v21 = 1 << (v19 - 1);
    v27 = v20;
    if ( (v21 & v20) != 0 )
      v27 = (-1 << v19) | v20;
    pm->M[0][3] = (float)v27;
    v22 = Scaleform::GFx::StreamContext::ReadUInt(this, v19);
    v28 = v22;
    if ( (v21 & v22) != 0 )
      v28 = (-1 << v19) | v22;
    pm->M[1][3] = (float)v28;
  }
}

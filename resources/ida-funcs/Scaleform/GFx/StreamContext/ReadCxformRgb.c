void __thiscall Scaleform::GFx::StreamContext::ReadCxformRgb(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Cxform *pcxform)
{
  const unsigned __int8 *v3; // eax
  BOOL v4; // ecx
  int v5; // ebx
  unsigned int UInt; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  int v9; // ebx
  Scaleform::Render::Cxform *v10; // ebp
  unsigned int v11; // eax
  unsigned int v12; // eax
  double v13; // st7
  unsigned int v14; // eax
  int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // [esp+10h] [ebp-8h]
  BOOL v19; // [esp+14h] [ebp-4h]
  Scaleform::Render::Cxform *v20; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v21; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v22; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v23; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v24; // [esp+1Ch] [ebp+4h]

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  v3 = &this->pData[this->CurByteIndex];
  this->CurBitIndex = 0;
  v4 = (*v3 & 0x80) != 0;
  this->CurBitIndex = 1;
  v5 = *v3 & 0x40;
  v19 = v4;
  this->CurBitIndex = 2;
  UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v7 = UInt;
  if ( v5 )
  {
    v8 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v9 = 1 << (v7 - 1);
    v18 = v8;
    if ( (v9 & v8) != 0 )
      v18 = (-1 << v7) | v8;
    v10 = pcxform;
    pcxform->M[0][0] = (double)v18 * 0.00390625;
    v11 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v20 = (Scaleform::Render::Cxform *)v11;
    if ( (v9 & v11) != 0 )
      v20 = (Scaleform::Render::Cxform *)((-1 << v7) | v11);
    v10->M[0][1] = (double)(int)v20 * 0.00390625;
    v12 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v21 = (Scaleform::Render::Cxform *)v12;
    if ( (v9 & v12) != 0 )
      v21 = (Scaleform::Render::Cxform *)((-1 << v7) | v12);
    v10->M[0][2] = 0.00390625 * (double)(int)v21;
    v13 = 1.0;
  }
  else
  {
    v13 = 1.0;
    v10 = pcxform;
    pcxform->M[0][0] = 1.0;
    pcxform->M[0][1] = 1.0;
    pcxform->M[0][2] = 1.0;
  }
  v10->M[0][3] = v13;
  if ( v19 )
  {
    v14 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v15 = 1 << (v7 - 1);
    v22 = (Scaleform::Render::Cxform *)v14;
    if ( (v15 & v14) != 0 )
      v22 = (Scaleform::Render::Cxform *)((-1 << v7) | v14);
    v10->M[1][0] = (float)(int)v22;
    v16 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v23 = (Scaleform::Render::Cxform *)v16;
    if ( (v15 & v16) != 0 )
      v23 = (Scaleform::Render::Cxform *)((-1 << v7) | v16);
    v10->M[1][1] = (float)(int)v23;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v24 = (Scaleform::Render::Cxform *)v17;
    if ( (v15 & v17) != 0 )
      v24 = (Scaleform::Render::Cxform *)((-1 << v7) | v17);
    v10->M[1][2] = (float)(int)v24;
    v10->M[1][3] = v13;
    Scaleform::Render::Cxform::Normalize(v10);
  }
  else
  {
    v10->M[1][0] = 0.0;
    v10->M[1][1] = 0.0;
    v10->M[1][2] = 0.0;
    v10->M[1][3] = 0.0;
    Scaleform::Render::Cxform::Normalize(v10);
  }
}

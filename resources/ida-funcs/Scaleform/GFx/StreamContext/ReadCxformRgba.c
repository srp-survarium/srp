void __thiscall Scaleform::GFx::StreamContext::ReadCxformRgba(
        Scaleform::GFx::StreamContext *this,
        Scaleform::Render::Cxform *pcxform)
{
  const unsigned __int8 *v3; // eax
  BOOL v4; // ecx
  int v5; // ebx
  unsigned int UInt; // eax
  unsigned int v7; // edi
  unsigned int v8; // eax
  int v9; // ebp
  Scaleform::Render::Cxform *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  double v14; // st7
  unsigned int v15; // eax
  int v16; // ebp
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  int v20; // [esp+10h] [ebp-8h]
  BOOL v21; // [esp+14h] [ebp-4h]
  Scaleform::Render::Cxform *v22; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v23; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v24; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v25; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v26; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v27; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v28; // [esp+1Ch] [ebp+4h]

  if ( this->CurBitIndex )
    ++this->CurByteIndex;
  v3 = &this->pData[this->CurByteIndex];
  this->CurBitIndex = 0;
  v4 = (*v3 & 0x80) != 0;
  this->CurBitIndex = 1;
  v21 = v4;
  v5 = *v3 & 0x40;
  this->CurBitIndex = 2;
  UInt = Scaleform::GFx::StreamContext::ReadUInt(this, 4u);
  v7 = UInt;
  if ( v5 )
  {
    v8 = Scaleform::GFx::StreamContext::ReadUInt(this, UInt);
    v9 = 1 << (v7 - 1);
    v20 = v8;
    if ( (v9 & v8) != 0 )
      v20 = (-1 << v7) | v8;
    v10 = pcxform;
    pcxform->M[0][0] = (double)v20 * 0.00390625;
    v11 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v22 = (Scaleform::Render::Cxform *)v11;
    if ( (v9 & v11) != 0 )
      v22 = (Scaleform::Render::Cxform *)((-1 << v7) | v11);
    v10->M[0][1] = (double)(int)v22 * 0.00390625;
    v12 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v23 = (Scaleform::Render::Cxform *)v12;
    if ( (v9 & v12) != 0 )
      v23 = (Scaleform::Render::Cxform *)((-1 << v7) | v12);
    v10->M[0][2] = (double)(int)v23 * 0.00390625;
    v13 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v24 = (Scaleform::Render::Cxform *)v13;
    if ( (v9 & v13) != 0 )
      v24 = (Scaleform::Render::Cxform *)((-1 << v7) | v13);
    v14 = 0.00390625 * (double)(int)v24;
  }
  else
  {
    v14 = 1.0;
    v10 = pcxform;
    pcxform->M[0][0] = 1.0;
    pcxform->M[0][1] = 1.0;
    pcxform->M[0][2] = 1.0;
  }
  v10->M[0][3] = v14;
  if ( v21 )
  {
    v15 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v16 = 1 << (v7 - 1);
    v25 = (Scaleform::Render::Cxform *)v15;
    if ( (v16 & v15) != 0 )
      v25 = (Scaleform::Render::Cxform *)((-1 << v7) | v15);
    v10->M[1][0] = (float)(int)v25;
    v17 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v26 = (Scaleform::Render::Cxform *)v17;
    if ( (v16 & v17) != 0 )
      v26 = (Scaleform::Render::Cxform *)((-1 << v7) | v17);
    v10->M[1][1] = (float)(int)v26;
    v18 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v27 = (Scaleform::Render::Cxform *)v18;
    if ( (v16 & v18) != 0 )
      v27 = (Scaleform::Render::Cxform *)((-1 << v7) | v18);
    v10->M[1][2] = (float)(int)v27;
    v19 = Scaleform::GFx::StreamContext::ReadUInt(this, v7);
    v28 = (Scaleform::Render::Cxform *)v19;
    if ( (v16 & v19) != 0 )
      v28 = (Scaleform::Render::Cxform *)((-1 << v7) | v19);
    v10->M[1][3] = (float)(int)v28;
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

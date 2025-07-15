void __thiscall Scaleform::GFx::Stream::ReadMatrix(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Matrix2x4<float> *pm)
{
  int UInt; // ebx
  int v5; // eax
  int v6; // ebp
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // ebp
  int v11; // eax
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // ebp
  int v16; // eax
  int v17; // [esp+14h] [ebp+4h]
  int v18; // [esp+14h] [ebp+4h]
  int v19; // [esp+14h] [ebp+4h]
  int v20; // [esp+14h] [ebp+4h]
  int v21; // [esp+14h] [ebp+4h]
  int v22; // [esp+14h] [ebp+4h]

  this->UnusedBits = 0;
  pm->M[0][0] = 1.0;
  pm->M[0][1] = 0.0;
  pm->M[0][2] = 0.0;
  pm->M[0][3] = 0.0;
  pm->M[1][0] = 0.0;
  pm->M[1][2] = 0.0;
  pm->M[1][3] = 0.0;
  pm->M[1][1] = 1.0;
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    UInt = Scaleform::GFx::Stream::ReadUInt(this, 5);
    v5 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v6 = 1 << (UInt - 1);
    v17 = v5;
    if ( (v6 & v5) != 0 )
      v17 = (-1 << UInt) | v5;
    pm->M[0][0] = (double)v17 * 0.0000152587890625;
    v7 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v18 = v7;
    if ( (v6 & v7) != 0 )
      v18 = (-1 << UInt) | v7;
    pm->M[1][1] = (double)v18 * 0.0000152587890625;
  }
  if ( Scaleform::GFx::Stream::ReadUInt1(this) )
  {
    v8 = Scaleform::GFx::Stream::ReadUInt(this, 5);
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    v10 = 1 << (v8 - 1);
    v19 = v9;
    if ( (v10 & v9) != 0 )
      v19 = (-1 << v8) | v9;
    pm->M[1][0] = (double)v19 * 0.0000152587890625;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v8);
    v20 = v11;
    if ( (v10 & v11) != 0 )
      v20 = (-1 << v8) | v11;
    pm->M[0][1] = (double)v20 * 0.0000152587890625;
  }
  v12 = Scaleform::GFx::Stream::ReadUInt(this, 5);
  v13 = v12;
  if ( v12 > 0 )
  {
    v14 = Scaleform::GFx::Stream::ReadUInt(this, v12);
    v15 = 1 << (v13 - 1);
    v21 = v14;
    if ( (v15 & v14) != 0 )
      v21 = (-1 << v13) | v14;
    pm->M[0][3] = (float)v21;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v13);
    v22 = v16;
    if ( (v15 & v16) != 0 )
      v22 = (-1 << v13) | v16;
    pm->M[1][3] = (float)v22;
  }
}

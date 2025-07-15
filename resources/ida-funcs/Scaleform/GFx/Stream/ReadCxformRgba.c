void __thiscall Scaleform::GFx::Stream::ReadCxformRgba(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Cxform *pcxform)
{
  int v3; // ebx
  int UInt; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ebp
  Scaleform::Render::Cxform *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp+10h] [ebp-8h]
  int UInt1; // [esp+14h] [ebp-4h]
  Scaleform::Render::Cxform *v20; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v21; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v22; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v23; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v24; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v25; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v26; // [esp+1Ch] [ebp+4h]

  this->UnusedBits = 0;
  UInt1 = Scaleform::GFx::Stream::ReadUInt1(this);
  v3 = Scaleform::GFx::Stream::ReadUInt1(this);
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 4);
  v5 = UInt;
  if ( v3 )
  {
    v6 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v7 = 1 << (v5 - 1);
    v18 = v6;
    if ( (v7 & v6) != 0 )
      v18 = (-1 << v5) | v6;
    v8 = pcxform;
    pcxform->M[0][0] = (double)v18 * 0.00390625;
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v20 = (Scaleform::Render::Cxform *)v9;
    if ( (v7 & v9) != 0 )
      v20 = (Scaleform::Render::Cxform *)((-1 << v5) | v9);
    v8->M[0][1] = (double)(int)v20 * 0.00390625;
    v10 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v21 = (Scaleform::Render::Cxform *)v10;
    if ( (v7 & v10) != 0 )
      v21 = (Scaleform::Render::Cxform *)((-1 << v5) | v10);
    v8->M[0][2] = (double)(int)v21 * 0.00390625;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v22 = (Scaleform::Render::Cxform *)v11;
    if ( (v7 & v11) != 0 )
      v22 = (Scaleform::Render::Cxform *)((-1 << v5) | v11);
    v12 = (double)(int)v22 * 0.00390625;
  }
  else
  {
    v12 = 1.0;
    v8 = pcxform;
    pcxform->M[0][0] = 1.0;
    pcxform->M[0][1] = 1.0;
    pcxform->M[0][2] = 1.0;
  }
  v8->M[0][3] = v12;
  if ( UInt1 )
  {
    v13 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v14 = 1 << (v5 - 1);
    v23 = (Scaleform::Render::Cxform *)v13;
    if ( (v14 & v13) != 0 )
      v23 = (Scaleform::Render::Cxform *)((-1 << v5) | v13);
    v8->M[1][0] = (float)(int)v23;
    v15 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v24 = (Scaleform::Render::Cxform *)v15;
    if ( (v14 & v15) != 0 )
      v24 = (Scaleform::Render::Cxform *)((-1 << v5) | v15);
    v8->M[1][1] = (float)(int)v24;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v25 = (Scaleform::Render::Cxform *)v16;
    if ( (v14 & v16) != 0 )
      v25 = (Scaleform::Render::Cxform *)((-1 << v5) | v16);
    v8->M[1][2] = (float)(int)v25;
    v17 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v26 = (Scaleform::Render::Cxform *)v17;
    if ( (v14 & v17) != 0 )
      v26 = (Scaleform::Render::Cxform *)((-1 << v5) | v17);
    v8->M[1][3] = (float)(int)v26;
    Scaleform::Render::Cxform::Normalize(v8);
  }
  else
  {
    v8->M[1][0] = 0.0;
    v8->M[1][1] = 0.0;
    v8->M[1][2] = 0.0;
    v8->M[1][3] = 0.0;
    Scaleform::Render::Cxform::Normalize(v8);
  }
}

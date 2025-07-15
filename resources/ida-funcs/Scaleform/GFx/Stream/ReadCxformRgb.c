void __thiscall Scaleform::GFx::Stream::ReadCxformRgb(Scaleform::GFx::Stream *this, Scaleform::Render::Cxform *pcxform)
{
  int v3; // ebx
  int UInt; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  Scaleform::Render::Cxform *v8; // ebp
  int v9; // eax
  int v10; // eax
  double v11; // st7
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // [esp+10h] [ebp-8h]
  int UInt1; // [esp+14h] [ebp-4h]
  Scaleform::Render::Cxform *v18; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v19; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v20; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v21; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *v22; // [esp+1Ch] [ebp+4h]

  this->UnusedBits = 0;
  UInt1 = Scaleform::GFx::Stream::ReadUInt1(this);
  v3 = Scaleform::GFx::Stream::ReadUInt1(this);
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 4);
  v5 = UInt;
  if ( v3 )
  {
    v6 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v7 = 1 << (v5 - 1);
    v16 = v6;
    if ( (v7 & v6) != 0 )
      v16 = (-1 << v5) | v6;
    v8 = pcxform;
    pcxform->M[0][0] = (double)v16 * 0.00390625;
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v18 = (Scaleform::Render::Cxform *)v9;
    if ( (v7 & v9) != 0 )
      v18 = (Scaleform::Render::Cxform *)((-1 << v5) | v9);
    v8->M[0][1] = (double)(int)v18 * 0.00390625;
    v10 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v19 = (Scaleform::Render::Cxform *)v10;
    if ( (v7 & v10) != 0 )
      v19 = (Scaleform::Render::Cxform *)((-1 << v5) | v10);
    v8->M[0][2] = (double)(int)v19 * 0.00390625;
    v11 = 1.0;
  }
  else
  {
    v11 = 1.0;
    v8 = pcxform;
    pcxform->M[0][0] = 1.0;
    pcxform->M[0][1] = 1.0;
    pcxform->M[0][2] = 1.0;
  }
  v8->M[0][3] = v11;
  if ( UInt1 )
  {
    v12 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v13 = 1 << (v5 - 1);
    v20 = (Scaleform::Render::Cxform *)v12;
    if ( (v13 & v12) != 0 )
      v20 = (Scaleform::Render::Cxform *)((-1 << v5) | v12);
    v8->M[1][0] = (float)(int)v20;
    v14 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v21 = (Scaleform::Render::Cxform *)v14;
    if ( (v13 & v14) != 0 )
      v21 = (Scaleform::Render::Cxform *)((-1 << v5) | v14);
    v8->M[1][1] = (float)(int)v21;
    v15 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v22 = (Scaleform::Render::Cxform *)v15;
    if ( (v13 & v15) != 0 )
      v22 = (Scaleform::Render::Cxform *)((-1 << v5) | v15);
    v8->M[1][2] = (float)(int)v22;
    v8->M[1][3] = 1.0;
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

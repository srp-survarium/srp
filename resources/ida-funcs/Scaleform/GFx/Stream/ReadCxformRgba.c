void __thiscall Scaleform::GFx::Stream::ReadCxformRgba(
        Scaleform::GFx::Stream *this,
        Scaleform::Render::Cxform *pcxform)
{
  int UInt1; // ebx
  signed int UInt; // eax
  signed int v5; // esi
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
  unsigned int hasAdd; // [esp+14h] [ebp-4h]
  Scaleform::Render::Cxform *pcxforma; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxformb; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxformc; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxformd; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxforme; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxformf; // [esp+1Ch] [ebp+4h]
  Scaleform::Render::Cxform *pcxformg; // [esp+1Ch] [ebp+4h]

  this->UnusedBits = 0;
  hasAdd = Scaleform::GFx::Stream::ReadUInt1(this);
  UInt1 = Scaleform::GFx::Stream::ReadUInt1(this);
  UInt = Scaleform::GFx::Stream::ReadUInt(this, 4);
  v5 = UInt;
  if ( UInt1 )
  {
    v6 = Scaleform::GFx::Stream::ReadUInt(this, UInt);
    v7 = 1 << (v5 - 1);
    v18 = v6;
    if ( (v7 & v6) != 0 )
      v18 = (-1 << v5) | v6;
    v8 = pcxform;
    pcxform->M[0][0] = (double)v18 * 0.00390625;
    v9 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxforma = (Scaleform::Render::Cxform *)v9;
    if ( (v7 & v9) != 0 )
      pcxforma = (Scaleform::Render::Cxform *)((-1 << v5) | v9);
    v8->M[0][1] = (double)(int)pcxforma * 0.00390625;
    v10 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxformb = (Scaleform::Render::Cxform *)v10;
    if ( (v7 & v10) != 0 )
      pcxformb = (Scaleform::Render::Cxform *)((-1 << v5) | v10);
    v8->M[0][2] = (double)(int)pcxformb * 0.00390625;
    v11 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxformc = (Scaleform::Render::Cxform *)v11;
    if ( (v7 & v11) != 0 )
      pcxformc = (Scaleform::Render::Cxform *)((-1 << v5) | v11);
    v12 = (double)(int)pcxformc * 0.00390625;
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
  if ( hasAdd )
  {
    v13 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    v14 = 1 << (v5 - 1);
    pcxformd = (Scaleform::Render::Cxform *)v13;
    if ( (v14 & v13) != 0 )
      pcxformd = (Scaleform::Render::Cxform *)((-1 << v5) | v13);
    v8->M[1][0] = (float)(int)pcxformd;
    v15 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxforme = (Scaleform::Render::Cxform *)v15;
    if ( (v14 & v15) != 0 )
      pcxforme = (Scaleform::Render::Cxform *)((-1 << v5) | v15);
    v8->M[1][1] = (float)(int)pcxforme;
    v16 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxformf = (Scaleform::Render::Cxform *)v16;
    if ( (v14 & v16) != 0 )
      pcxformf = (Scaleform::Render::Cxform *)((-1 << v5) | v16);
    v8->M[1][2] = (float)(int)pcxformf;
    v17 = Scaleform::GFx::Stream::ReadUInt(this, v5);
    pcxformg = (Scaleform::Render::Cxform *)v17;
    if ( (v14 & v17) != 0 )
      pcxformg = (Scaleform::Render::Cxform *)((-1 << v5) | v17);
    v8->M[1][3] = (float)(int)pcxformg;
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

unsigned int __stdcall Scaleform::GFx::PlaceObject3Tag::ComputeDataSize(Scaleform::GFx::Stream *pin)
{
  unsigned int v1; // edi
  unsigned int v2; // ebx
  signed int v3; // eax
  unsigned int v4; // eax
  unsigned __int8 v5; // dl
  int v6; // ecx
  unsigned int v7; // eax
  unsigned __int8 v8; // bl
  int v9; // edi
  signed int v10; // eax
  unsigned int v11; // eax
  unsigned __int16 v12; // cx
  signed int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // edx
  signed int v16; // edx
  unsigned int v17; // eax
  signed int v18; // eax
  unsigned int v19; // eax
  unsigned __int16 v20; // dx
  signed int v21; // edx
  unsigned int v22; // ecx
  unsigned __int8 v23; // al
  signed int v24; // edx
  signed int v25; // eax
  signed int v26; // ecx
  unsigned int v27; // edx
  int v28; // eax
  char v29; // bl
  bool v30; // bl
  const char *v31; // eax
  char v33; // [esp+1Ah] [ebp-7Eh]
  char v34; // [esp+1Ah] [ebp-7Eh]
  char v35; // [esp+1Bh] [ebp-7Dh]
  char v36; // [esp+1Ch] [ebp-7Ch]
  char v37; // [esp+1Dh] [ebp-7Bh]
  char v38; // [esp+1Eh] [ebp-7Ah]
  char v39; // [esp+1Fh] [ebp-79h]
  char v40; // [esp+20h] [ebp-78h]
  char v41; // [esp+21h] [ebp-77h]
  char v42; // [esp+22h] [ebp-76h]
  char v43; // [esp+23h] [ebp-75h]
  char *v44; // [esp+24h] [ebp-74h]
  unsigned int v45; // [esp+28h] [ebp-70h]
  char *String; // [esp+2Ch] [ebp-6Ch]
  int pos; // [esp+30h] [ebp-68h]
  int v48; // [esp+34h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v49; // [esp+38h] [ebp-60h] BYREF

  v1 = pin->Pos + pin->FilePos - pin->DataSize;
  pos = v1;
  v2 = Scaleform::GFx::Stream::GetTagEndPosition(pin) - v1;
  v45 = v2;
  if ( !(unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(pin) )
    return v2;
  v3 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(pin);
  v4 = pin->Pos;
  v5 = pin->pBuffer[v4++];
  v6 = pin->DataSize - v4;
  v33 = v5;
  pin->Pos = v4;
  pin->UnusedBits = 0;
  if ( v6 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(pin);
  v7 = pin->Pos;
  v8 = pin->pBuffer[v7];
  v9 = 0;
  pin->Pos = v7 + 1;
  v44 = 0;
  String = 0;
  Scaleform::GFx::CharPosInfo::CharPosInfo(&v49);
  v10 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v10 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  v11 = pin->Pos;
  v12 = *(_WORD *)&pin->pBuffer[v11];
  pin->Pos = v11 + 2;
  v49.Depth = v12;
  v41 = v8 & 8;
  if ( (v8 & 8) != 0 )
  {
    v49.Flags.Flags |= 0x100u;
    String = Scaleform::GFx::Stream::ReadString(pin, pin->FileName.pHeap);
    v49.ClassName = String;
  }
  v39 = v33 & 2;
  if ( (v33 & 2) != 0 )
  {
    v13 = pin->DataSize - pin->Pos;
    v49.Flags.Flags |= 2u;
    pin->UnusedBits = 0;
    if ( v13 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v14 = pin->Pos;
    v15 = *(unsigned __int16 *)&pin->pBuffer[v14];
    pin->Pos = v14 + 2;
    v49.CharacterId.Id = v15;
  }
  v38 = v33 & 4;
  if ( (v33 & 4) != 0 )
  {
    v49.Flags.Flags |= 4u;
    Scaleform::GFx::Stream::ReadMatrix(pin, &v49.Matrix_1);
  }
  v43 = v33 & 8;
  if ( (v33 & 8) != 0 )
  {
    v49.Flags.Flags |= 8u;
    Scaleform::GFx::Stream::ReadCxformRgba(pin, &v49.ColorTransform);
  }
  v40 = v33 & 0x10;
  if ( (v33 & 0x10) != 0 )
  {
    v16 = pin->DataSize - pin->Pos;
    v49.Flags.Flags |= 0x10u;
    pin->UnusedBits = 0;
    if ( v16 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v17 = pin->Pos;
    v48 = *(unsigned __int16 *)&pin->pBuffer[v17];
    pin->Pos = v17 + 2;
    v49.Ratio = (double)v48 / 65535.0;
  }
  v42 = v33 & 0x20;
  if ( (v33 & 0x20) != 0 )
    v44 = Scaleform::GFx::Stream::ReadString(pin, pin->FileName.pHeap);
  v35 = v33 & 0x40;
  if ( (v33 & 0x40) != 0 )
  {
    v18 = pin->DataSize - pin->Pos;
    v49.Flags.Flags |= 0x40u;
    pin->UnusedBits = 0;
    if ( v18 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v19 = pin->Pos;
    v20 = *(_WORD *)&pin->pBuffer[v19];
    pin->Pos = v19 + 2;
    v49.ClipDepth = v20;
  }
  if ( (v8 & 1) != 0 )
  {
    v49.Flags.Flags |= 0x20u;
    Scaleform::GFx::LoadFilters<Scaleform::GFx::Stream>(pin, 0);
  }
  v36 = v8 & 2;
  if ( (v8 & 2) != 0 )
  {
    v21 = pin->DataSize - pin->Pos;
    pin->UnusedBits = 0;
    if ( v21 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(pin);
    v22 = pin->Pos;
    v23 = pin->pBuffer[v22];
    pin->Pos = v22 + 1;
    if ( !v23 || v23 > 0xEu )
      v23 = 1;
    v49.Flags.Flags |= 0x80u;
    v49.BlendMode = v23;
  }
  if ( (v8 & 4) != 0 )
  {
    v24 = pin->DataSize - pin->Pos;
    pin->UnusedBits = 0;
    if ( v24 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(pin);
    ++pin->Pos;
  }
  v37 = v33 & 0x80;
  if ( v33 < 0 )
  {
    v25 = pin->DataSize - pin->Pos;
    pin->UnusedBits = 0;
    if ( v25 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    pin->Pos += 2;
    v26 = pin->DataSize - pin->Pos;
    pin->UnusedBits = 0;
    if ( v26 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 4);
    v27 = pin->Pos;
    v28 = pin->pBuffer[v27] | ((pin->pBuffer[v27 + 1] | (*(unsigned __int16 *)&pin->pBuffer[v27 + 2] << 8)) << 8);
    pin->Pos = v27 + 4;
    v9 = v28;
  }
  Scaleform::GFx::Stream::SetPosition(pin, pos);
  v29 = v33;
  v34 = v33 & 1;
  v30 = (v29 & 2) != 0;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  depth = %d\n", v49.Depth);
  if ( v39 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  char id = %d\n", LOWORD(v49.CharacterId.Id));
  if ( v41 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  classname = %s\n", v49.ClassName);
  if ( v38 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  mat:\n");
    Scaleform::GFx::Stream::LogParseClass(pin, &v49.Matrix_1);
  }
  if ( v43 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  cxform:\n");
    Scaleform::GFx::Stream::LogParseClass(pin, &v49.ColorTransform);
  }
  if ( v40 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  ratio: %f\n", v49.Ratio);
  if ( v42 )
  {
    v31 = v44;
    if ( !v44 )
      v31 = "<null>";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  name = %s\n", v31);
  }
  if ( v35 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  ClipDepth = %d\n", v49.ClipDepth);
  if ( v36 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  blend mode = %d\n", v49.BlendMode);
  if ( v37 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  actions: flags = 0x%X\n", v9);
  if ( v30 )
  {
    if ( v34 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "    * (replace)\n");
  }
  else if ( v34 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "    * (move)\n");
  }
  if ( v44 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
  if ( String )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, String);
  Scaleform::GFx::Stream::SetPosition(pin, pos);
  if ( v49.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v49.pFilters.pObject);
  return v45;
}

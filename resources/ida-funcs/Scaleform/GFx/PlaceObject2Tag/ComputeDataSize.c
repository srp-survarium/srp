unsigned int __stdcall Scaleform::GFx::PlaceObject2Tag::ComputeDataSize(
        Scaleform::GFx::Stream *pin,
        unsigned int movieVersion)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  signed int v4; // eax
  unsigned int v5; // eax
  char v6; // bl
  char *String; // edi
  signed int v8; // edx
  unsigned int v9; // eax
  int v10; // edx
  unsigned int v11; // eax
  unsigned int DataSize; // ecx
  unsigned int v13; // eax
  unsigned int v14; // edx
  signed int v15; // edx
  unsigned int v16; // eax
  signed int v17; // eax
  unsigned int v18; // eax
  unsigned __int16 v19; // dx
  signed int v20; // edx
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // eax
  unsigned int v24; // eax
  int v25; // edx
  char v26; // bl
  const char *v27; // eax
  char v29; // [esp+1Ch] [ebp-7Ch]
  bool v30; // [esp+1Dh] [ebp-7Bh]
  char v31; // [esp+1Eh] [ebp-7Ah]
  char v32; // [esp+1Fh] [ebp-79h]
  char v33; // [esp+20h] [ebp-78h]
  char v34; // [esp+21h] [ebp-77h]
  char v35; // [esp+22h] [ebp-76h]
  char v36; // [esp+23h] [ebp-75h]
  int v37; // [esp+24h] [ebp-74h]
  unsigned int v38; // [esp+28h] [ebp-70h]
  char *v39; // [esp+2Ch] [ebp-6Ch]
  int pos; // [esp+30h] [ebp-68h]
  int v41; // [esp+34h] [ebp-64h]
  Scaleform::GFx::CharPosInfo v42; // [esp+38h] [ebp-60h] BYREF

  v2 = pin->Pos + pin->FilePos - pin->DataSize;
  pos = v2;
  v3 = Scaleform::GFx::Stream::GetTagEndPosition(pin) - v2;
  v38 = v3;
  if ( !(unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(pin) )
    return v3;
  v4 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v4 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(pin);
  v5 = pin->Pos;
  v6 = pin->pBuffer[v5];
  String = 0;
  pin->Pos = v5 + 1;
  v37 = 0;
  v39 = 0;
  Scaleform::GFx::CharPosInfo::CharPosInfo(&v42);
  v8 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v8 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  v9 = pin->Pos;
  v10 = *(unsigned __int16 *)&pin->pBuffer[v9];
  v11 = v9 + 2;
  pin->Pos = v11;
  v42.Depth = v10;
  v34 = v6 & 2;
  if ( (v6 & 2) != 0 )
  {
    DataSize = pin->DataSize;
    v42.Flags.Flags |= 2u;
    pin->UnusedBits = 0;
    if ( (int)(DataSize - v11) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v13 = pin->Pos;
    v14 = *(unsigned __int16 *)&pin->pBuffer[v13];
    pin->Pos = v13 + 2;
    v42.CharacterId.Id = v14;
  }
  v31 = v6 & 4;
  if ( (v6 & 4) != 0 )
  {
    v42.Flags.Flags |= 4u;
    Scaleform::GFx::Stream::ReadMatrix(pin, &v42.Matrix_1);
  }
  v36 = v6 & 8;
  if ( (v6 & 8) != 0 )
  {
    v42.Flags.Flags |= 8u;
    Scaleform::GFx::Stream::ReadCxformRgba(pin, &v42.ColorTransform);
  }
  v33 = v6 & 0x10;
  if ( (v6 & 0x10) != 0 )
  {
    v15 = pin->DataSize - pin->Pos;
    v42.Flags.Flags |= 0x10u;
    pin->UnusedBits = 0;
    if ( v15 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v16 = pin->Pos;
    v41 = *(unsigned __int16 *)&pin->pBuffer[v16];
    pin->Pos = v16 + 2;
    v42.Ratio = (double)v41 / 65535.0;
  }
  v35 = v6 & 0x20;
  if ( (v6 & 0x20) != 0 )
  {
    String = Scaleform::GFx::Stream::ReadString(pin, pin->FileName.pHeap);
    v39 = String;
  }
  v32 = v6 & 0x40;
  if ( (v6 & 0x40) != 0 )
  {
    v17 = pin->DataSize - pin->Pos;
    v42.Flags.Flags |= 0x40u;
    pin->UnusedBits = 0;
    if ( v17 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    v18 = pin->Pos;
    v19 = *(_WORD *)&pin->pBuffer[v18];
    pin->Pos = v18 + 2;
    v42.ClipDepth = v19;
  }
  v29 = v6 & 0x80;
  if ( v6 < 0 )
  {
    v20 = pin->DataSize - pin->Pos;
    pin->UnusedBits = 0;
    if ( v20 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
    pin->Pos += 2;
    v21 = pin->Pos;
    pin->UnusedBits = 0;
    if ( movieVersion < 6 )
    {
      if ( (int)(pin->DataSize - v21) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
      v24 = pin->Pos;
      v25 = *(unsigned __int16 *)&pin->pBuffer[v24];
      pin->Pos = v24 + 2;
      v37 = v25;
    }
    else
    {
      if ( (int)(pin->DataSize - v21) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(pin, 4);
      v22 = pin->Pos;
      String = v39;
      v23 = pin->pBuffer[v22] | ((pin->pBuffer[v22 + 1] | (*(unsigned __int16 *)&pin->pBuffer[v22 + 2] << 8)) << 8);
      pin->Pos = v22 + 4;
      v37 = v23;
    }
  }
  Scaleform::GFx::Stream::SetPosition(pin, pos);
  v30 = (v6 & 2) != 0;
  v26 = v6 & 1;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  depth = %d\n", v42.Depth);
  if ( v34 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  char id = %d\n", LOWORD(v42.CharacterId.Id));
  if ( v31 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  mat:\n");
    Scaleform::GFx::Stream::LogParseClass(pin, &v42.Matrix_1);
  }
  if ( v36 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  cxform:\n");
    Scaleform::GFx::Stream::LogParseClass(pin, &v42.ColorTransform);
  }
  if ( v33 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  ratio: %f\n", v42.Ratio);
  if ( v35 )
  {
    v27 = String;
    if ( !String )
      v27 = "<null>";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  name = %s\n", v27);
  }
  if ( v32 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  ClipDepth = %d\n", v42.ClipDepth);
  if ( v29 )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  actions: flags = 0x%X\n", v37);
  if ( v30 )
  {
    if ( v26 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "    * (replace)\n");
  }
  else if ( v26 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "    * (move)\n");
  }
  if ( String )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, String);
  Scaleform::GFx::Stream::SetPosition(pin, pos);
  if ( v42.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v42.pFilters.pObject);
  return v38;
}

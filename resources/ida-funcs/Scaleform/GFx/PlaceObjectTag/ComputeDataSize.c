int __stdcall Scaleform::GFx::PlaceObjectTag::ComputeDataSize(Scaleform::GFx::Stream *pin)
{
  int v1; // ebx
  int v2; // edi
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned int v5; // edx
  int v6; // ecx
  unsigned int v7; // eax
  int v8; // edx
  signed int v9; // edi
  int v11; // [esp+Ch] [ebp-64h]
  Scaleform::GFx::CharPosInfo v12; // [esp+10h] [ebp-60h] BYREF

  v1 = pin->FilePos + pin->Pos - pin->DataSize;
  v2 = Scaleform::GFx::Stream::GetTagEndPosition(pin) - v1;
  v11 = v2;
  if ( !(unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(pin) )
    return v2;
  Scaleform::GFx::CharPosInfo::CharPosInfo(&v12);
  v3 = pin->DataSize - pin->Pos;
  pin->UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  Pos = pin->Pos;
  v5 = *(unsigned __int16 *)&pin->pBuffer[Pos];
  Pos += 2;
  v6 = pin->DataSize - Pos;
  pin->Pos = Pos;
  v12.CharacterId.Id = v5;
  pin->UnusedBits = 0;
  if ( v6 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
  v7 = pin->Pos;
  v8 = *(unsigned __int16 *)&pin->pBuffer[v7];
  pin->Pos = v7 + 2;
  v12.Depth = v8;
  Scaleform::GFx::Stream::ReadMatrix(pin, &v12.Matrix_1);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    pin,
    "  CharId = %d\n  depth = %d\n  mat = \n",
    LOWORD(v12.CharacterId.Id),
    v12.Depth);
  Scaleform::GFx::Stream::LogParseClass(pin, &v12.Matrix_1);
  v9 = pin->FilePos + pin->Pos - pin->DataSize;
  if ( v9 < Scaleform::GFx::Stream::GetTagEndPosition(pin) )
  {
    Scaleform::GFx::Stream::ReadCxformRgb(pin, &v12.ColorTransform);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(pin, "  cxform:\n");
    Scaleform::GFx::Stream::LogParseClass(pin, &v12.ColorTransform);
  }
  Scaleform::GFx::Stream::SetPosition(pin, v1);
  if ( v12.pFilters.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12.pFilters.pObject);
  return v11;
}

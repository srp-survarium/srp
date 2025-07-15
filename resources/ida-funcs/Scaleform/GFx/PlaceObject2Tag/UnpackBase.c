void __thiscall Scaleform::GFx::PlaceObject2Tag::UnpackBase(
        Scaleform::GFx::PlaceObject2Tag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        int version)
{
  const unsigned __int8 *pData; // ecx
  unsigned __int8 v5; // bl
  int v6; // eax
  bool v7; // zf
  char v8; // dl
  unsigned int CurBitIndex; // edi
  int v11; // edx
  unsigned int CurByteIndex; // eax
  unsigned int v13; // edx
  unsigned __int8 v14; // dl
  unsigned __int16 v15; // di
  bool v16; // al
  char v17; // bl
  char v18; // [esp+Fh] [ebp-15h]
  Scaleform::GFx::StreamContext v19; // [esp+14h] [ebp-10h] BYREF
  Scaleform::Render::Cxform *pcxform; // [esp+28h] [ebp+4h]

  pData = this->pData;
  v19.CurByteIndex = 0;
  v19.CurBitIndex = 0;
  v19.pData = pData;
  v19.DataSize = -1;
  v5 = *pData;
  v6 = 1;
  v8 = *pData & 0x80;
  v7 = (*pData & 0x80u) == 0;
  v19.CurByteIndex = 1;
  v18 = v8;
  if ( !v7 )
  {
    v6 = 5;
    v19.CurByteIndex = 5;
  }
  CurBitIndex = 0;
  v19.CurBitIndex = 0;
  v11 = *(unsigned __int16 *)&pData[v6];
  CurByteIndex = v6 + 2;
  v19.CurByteIndex = CurByteIndex;
  data->Pos.Depth = v11;
  if ( (v5 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 2u;
    v19.CurBitIndex = 0;
    v13 = *(unsigned __int16 *)&pData[CurByteIndex];
    CurByteIndex += 2;
    v19.CurByteIndex = CurByteIndex;
    data->Pos.CharacterId.Id = v13;
  }
  if ( (v5 & 4) != 0 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&v19, &data->Pos.Matrix_1);
    CurBitIndex = v19.CurBitIndex;
    CurByteIndex = v19.CurByteIndex;
    pData = v19.pData;
  }
  if ( (v5 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&v19, &data->Pos.ColorTransform);
    CurBitIndex = v19.CurBitIndex;
    CurByteIndex = v19.CurByteIndex;
    pData = v19.pData;
  }
  if ( (v5 & 0x10) != 0 )
  {
    data->Pos.Flags.Flags |= 0x10u;
    if ( CurBitIndex )
      v19.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    v19.CurBitIndex = 0;
    pcxform = (Scaleform::Render::Cxform *)*(unsigned __int16 *)&pData[CurByteIndex];
    CurByteIndex += 2;
    v19.CurByteIndex = CurByteIndex;
    data->Pos.Ratio = (double)(int)pcxform / 65535.0;
  }
  if ( (v5 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      v19.CurByteIndex = ++CurByteIndex;
    data->Name = (const char *)&this->pData[CurByteIndex];
    do
    {
      CurBitIndex = 0;
      v19.CurBitIndex = 0;
      v14 = pData[CurByteIndex++];
      v19.CurByteIndex = CurByteIndex;
    }
    while ( v14 );
  }
  else
  {
    data->Name = 0;
  }
  if ( (v5 & 0x40) != 0 )
  {
    data->Pos.Flags.Flags |= 0x40u;
    if ( CurBitIndex )
      v19.CurByteIndex = ++CurByteIndex;
    v19.CurBitIndex = 0;
    v15 = *(_WORD *)&pData[CurByteIndex];
    v19.CurByteIndex = CurByteIndex + 2;
    data->Pos.ClipDepth = v15;
  }
  if ( v18 )
    this->ProcessEventHandlers(this, data, &v19, this->pData, version);
  else
    data->pEventHandlers = 0;
  v16 = (v5 & 2) != 0;
  v17 = v5 & 1;
  data->PlaceType = Place_Add;
  if ( v16 )
  {
    if ( v17 )
      data->PlaceType = Place_Replace;
  }
  else if ( v17 )
  {
    data->PlaceType = Place_Move;
  }
}

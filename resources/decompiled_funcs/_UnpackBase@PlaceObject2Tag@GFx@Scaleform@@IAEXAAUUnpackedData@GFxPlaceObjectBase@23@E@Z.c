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
  Scaleform::GFx::StreamContext sc; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *dataa; // [esp+28h] [ebp+4h]

  pData = this->pData;
  sc.CurByteIndex = 0;
  sc.CurBitIndex = 0;
  sc.pData = pData;
  sc.DataSize = -1;
  v5 = *pData;
  v6 = 1;
  v8 = *pData & 0x80;
  v7 = (*pData & 0x80u) == 0;
  sc.CurByteIndex = 1;
  v18 = v8;
  if ( !v7 )
  {
    v6 = 5;
    sc.CurByteIndex = 5;
  }
  CurBitIndex = 0;
  sc.CurBitIndex = 0;
  v11 = *(unsigned __int16 *)&pData[v6];
  CurByteIndex = v6 + 2;
  sc.CurByteIndex = CurByteIndex;
  data->Pos.Depth = v11;
  if ( (v5 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 2u;
    sc.CurBitIndex = 0;
    v13 = *(unsigned __int16 *)&pData[CurByteIndex];
    CurByteIndex += 2;
    sc.CurByteIndex = CurByteIndex;
    data->Pos.CharacterId.Id = v13;
  }
  if ( (v5 & 4) != 0 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&sc, &data->Pos.Matrix_1);
    CurBitIndex = sc.CurBitIndex;
    CurByteIndex = sc.CurByteIndex;
    pData = sc.pData;
  }
  if ( (v5 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&sc, &data->Pos.ColorTransform);
    CurBitIndex = sc.CurBitIndex;
    CurByteIndex = sc.CurByteIndex;
    pData = sc.pData;
  }
  if ( (v5 & 0x10) != 0 )
  {
    data->Pos.Flags.Flags |= 0x10u;
    if ( CurBitIndex )
      sc.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    sc.CurBitIndex = 0;
    dataa = (Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *)*(unsigned __int16 *)&pData[CurByteIndex];
    CurByteIndex += 2;
    sc.CurByteIndex = CurByteIndex;
    data->Pos.Ratio = (double)(int)dataa / 65535.0;
  }
  if ( (v5 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      sc.CurByteIndex = ++CurByteIndex;
    data->Name = (const char *)&this->pData[CurByteIndex];
    do
    {
      CurBitIndex = 0;
      sc.CurBitIndex = 0;
      v14 = pData[CurByteIndex++];
      sc.CurByteIndex = CurByteIndex;
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
      sc.CurByteIndex = ++CurByteIndex;
    sc.CurBitIndex = 0;
    v15 = *(_WORD *)&pData[CurByteIndex];
    sc.CurByteIndex = CurByteIndex + 2;
    data->Pos.ClipDepth = v15;
  }
  if ( v18 )
    this->ProcessEventHandlers(this, data, &sc, this->pData, version);
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

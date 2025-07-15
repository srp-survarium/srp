void __thiscall Scaleform::GFx::PlaceObjectTag::Unpack(
        Scaleform::GFx::PlaceObjectTag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  unsigned __int8 *pData; // eax
  unsigned __int16 v4; // cx
  int v5; // eax
  Scaleform::GFx::StreamContext sc; // [esp+10h] [ebp-10h] BYREF

  data->Name = 0;
  data->pEventHandlers = 0;
  data->PlaceType = Place_Add;
  pData = this->pData;
  sc.pData = this->pData;
  sc.CurByteIndex = 0;
  sc.CurBitIndex = 0;
  sc.DataSize = -1;
  data->Pos.Flags.Flags |= 2u;
  v4 = *(_WORD *)this->pData;
  sc.CurByteIndex = 2;
  data->Pos.CharacterId.Id = v4;
  data->Pos.Flags.Flags |= 1u;
  sc.CurBitIndex = 0;
  v5 = *((unsigned __int16 *)pData + 1);
  sc.CurByteIndex = 4;
  data->Pos.Depth = v5;
  data->Pos.Flags.Flags |= 4u;
  Scaleform::GFx::StreamContext::ReadMatrix(&sc, &data->Pos.Matrix_1);
  if ( this->HasCxForm )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgb(&sc, &data->Pos.ColorTransform);
  }
}

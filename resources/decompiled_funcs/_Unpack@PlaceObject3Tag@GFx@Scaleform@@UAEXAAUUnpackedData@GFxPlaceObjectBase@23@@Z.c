void __thiscall Scaleform::GFx::PlaceObject3Tag::Unpack(
        Scaleform::GFx::PlaceObject3Tag *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  const unsigned __int8 *pData; // ecx
  int v4; // eax
  unsigned int CurBitIndex; // edi
  int v7; // edx
  unsigned int CurByteIndex; // eax
  unsigned __int8 v9; // dl
  unsigned int v10; // edx
  unsigned __int8 v11; // dl
  unsigned __int16 v12; // dx
  Scaleform::Render::FilterSet *v13; // eax
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::GFx::Resource *v15; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned __int8 v17; // cl
  char v18; // cl
  char v19; // [esp+Dh] [ebp-17h]
  unsigned __int8 v20; // [esp+Eh] [ebp-16h]
  Scaleform::GFx::StreamContext sc; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *dataa; // [esp+28h] [ebp+4h]

  pData = this->pData;
  sc.CurByteIndex = 0;
  sc.pData = pData;
  sc.DataSize = -1;
  sc.CurBitIndex = 0;
  v19 = *pData;
  v4 = 1;
  sc.CurByteIndex = 1;
  if ( v19 < 0 )
  {
    v4 = 5;
    sc.CurByteIndex = 5;
  }
  sc.CurBitIndex = 0;
  v20 = pData[v4];
  sc.CurByteIndex = v4 + 1;
  CurBitIndex = 0;
  sc.CurBitIndex = 0;
  v7 = *(unsigned __int16 *)&pData[v4 + 1];
  CurByteIndex = v4 + 3;
  sc.CurByteIndex = CurByteIndex;
  data->Pos.Depth = v7;
  if ( (v20 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 0x100u;
    data->Pos.ClassName = (const char *)&this->pData[CurByteIndex];
    do
    {
      CurBitIndex = 0;
      sc.CurBitIndex = 0;
      v9 = pData[CurByteIndex++];
      sc.CurByteIndex = CurByteIndex;
    }
    while ( v9 );
  }
  if ( (v19 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 2u;
    CurBitIndex = 0;
    sc.CurBitIndex = 0;
    v10 = *(unsigned __int16 *)&pData[CurByteIndex];
    CurByteIndex += 2;
    sc.CurByteIndex = CurByteIndex;
    data->Pos.CharacterId.Id = v10;
  }
  if ( (v19 & 4) != 0 )
  {
    data->Pos.Flags.Flags |= 4u;
    Scaleform::GFx::StreamContext::ReadMatrix(&sc, &data->Pos.Matrix_1);
    CurBitIndex = sc.CurBitIndex;
    CurByteIndex = sc.CurByteIndex;
    pData = sc.pData;
  }
  if ( (v19 & 8) != 0 )
  {
    data->Pos.Flags.Flags |= 8u;
    Scaleform::GFx::StreamContext::ReadCxformRgba(&sc, &data->Pos.ColorTransform);
    CurBitIndex = sc.CurBitIndex;
    CurByteIndex = sc.CurByteIndex;
    pData = sc.pData;
  }
  if ( (v19 & 0x10) != 0 )
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
  if ( (v19 & 0x20) != 0 )
  {
    if ( CurBitIndex )
      sc.CurByteIndex = ++CurByteIndex;
    data->Name = (const char *)&this->pData[CurByteIndex];
    do
    {
      CurBitIndex = 0;
      sc.CurBitIndex = 0;
      v11 = pData[CurByteIndex++];
      sc.CurByteIndex = CurByteIndex;
    }
    while ( v11 );
  }
  else
  {
    data->Name = 0;
  }
  if ( (v19 & 0x40) != 0 )
  {
    if ( CurBitIndex )
      sc.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    sc.CurBitIndex = 0;
    v12 = *(_WORD *)&pData[CurByteIndex];
    CurByteIndex += 2;
    data->Pos.ClipDepth = v12;
    data->Pos.Flags.Flags |= 0x40u;
    sc.CurByteIndex = CurByteIndex;
  }
  if ( (v20 & 1) != 0 )
  {
    data->Pos.Flags.Flags |= 0x20u;
    v13 = (Scaleform::Render::FilterSet *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
    if ( v13 )
    {
      Scaleform::Render::FilterSet::FilterSet(v13, 0);
      v15 = v14;
    }
    else
    {
      v15 = 0;
    }
    if ( Scaleform::GFx::LoadFilters<Scaleform::GFx::StreamContext>(&sc, (Scaleform::Render::FilterSet *)v15) )
    {
      if ( v15 )
        Scaleform::RefCountImpl::AddRef(v15);
      pObject = (Scaleform::RefCountVImpl *)data->Pos.pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      data->Pos.pFilters.pObject = (Scaleform::Render::FilterSet *)v15;
    }
    if ( v15 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v15);
    pData = sc.pData;
    CurByteIndex = sc.CurByteIndex;
    CurBitIndex = sc.CurBitIndex;
  }
  if ( (v20 & 2) != 0 )
  {
    data->Pos.Flags.Flags |= 0x80u;
    if ( CurBitIndex )
      sc.CurByteIndex = ++CurByteIndex;
    CurBitIndex = 0;
    sc.CurBitIndex = 0;
    v17 = pData[CurByteIndex++];
    sc.CurByteIndex = CurByteIndex;
    if ( !v17 || v17 > 0xEu )
      v17 = 1;
    data->Pos.BlendMode = v17;
  }
  if ( (v20 & 4) != 0 )
  {
    if ( CurBitIndex )
      ++CurByteIndex;
    sc.CurBitIndex = 0;
    sc.CurByteIndex = CurByteIndex + 1;
  }
  if ( v19 < 0 )
    this->ProcessEventHandlers(this, data, &sc, this->pData);
  else
    data->pEventHandlers = 0;
  v18 = v19 & 1;
  data->PlaceType = Place_Add;
  if ( (v19 & 2) != 0 )
  {
    if ( v18 )
      data->PlaceType = Place_Replace;
  }
  else if ( v18 )
  {
    data->PlaceType = Place_Move;
  }
}

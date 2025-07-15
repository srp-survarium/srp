void __thiscall Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject2EH *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        unsigned __int8 *prawdata,
        unsigned __int8 version)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *EventHandlersPtr; // eax
  unsigned int CurByteIndex; // eax
  unsigned int v7; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v8; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v9; // ebp
  unsigned int v10; // edx
  int v11; // eax
  Scaleform::GFx::AS2::ActionBufferData *v12; // edi
  unsigned int v13; // eax
  Scaleform::GFx::AS2::ActionBufferData *v14; // ecx
  _DWORD *v15; // eax
  unsigned int v16; // edi
  unsigned __int8 **v17; // eax
  unsigned __int8 *pdata; // [esp+18h] [ebp+Ch]
  bool v20; // [esp+1Ch] [ebp+10h]

  EventHandlersPtr = Scaleform::GFx::PlaceObject2Tag::GetEventHandlersPtr(prawdata);
  if ( EventHandlersPtr )
  {
    data->pEventHandlers = EventHandlersPtr;
  }
  else
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurByteIndex += 2;
    CurByteIndex = sc->CurByteIndex;
    sc->CurBitIndex = 0;
    v20 = version >= 6u;
    sc->CurBitIndex = 0;
    if ( v20 )
      v7 = CurByteIndex + 4;
    else
      v7 = CurByteIndex + 2;
    sc->CurByteIndex = v7;
    v8 = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                                               Scaleform::Memory::pGlobalHeap,
                                                                                               12,
                                                                                               0);
    if ( v8 )
    {
      v8->Data.Data = 0;
      v8->Data.Size = 0;
      v8->Data.Policy.Capacity = 0;
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    while ( 1 )
    {
      if ( sc->CurBitIndex )
        ++sc->CurByteIndex;
      sc->CurBitIndex = 0;
      sc->CurBitIndex = 0;
      if ( v20 )
      {
        v10 = sc->CurByteIndex;
        v11 = (unsigned __int8)sc->pData[v10]
            | (((unsigned __int8)sc->pData[v10 + 1] | (*(unsigned __int16 *)&sc->pData[v10 + 2] << 8)) << 8);
        sc->CurByteIndex = v10 + 4;
        v12 = (Scaleform::GFx::AS2::ActionBufferData *)v11;
      }
      else
      {
        v13 = sc->CurByteIndex;
        v14 = (Scaleform::GFx::AS2::ActionBufferData *)*(unsigned __int16 *)&sc->pData[v13];
        sc->CurByteIndex = v13 + 2;
        v12 = v14;
      }
      if ( !v12 )
        break;
      v15 = Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
      if ( v15 )
      {
        *v15 = 0;
        v15[1] = 0;
        v15[2] = 0;
        *((_BYTE *)v15 + 12) = 0;
        *((_BYTE *)v15 + 16) = 0;
        *((_BYTE *)v15 + 18) = 0;
        *((_BYTE *)v15 + 19) = 0;
        *((_BYTE *)v15 + 17) = -1;
        v15[5] = 0;
        pdata = (unsigned __int8 *)v15;
      }
      else
      {
        pdata = 0;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read((Scaleform::GFx::AS2::AvmSwfEvent *)pdata, sc, v12);
      v16 = v9->Data.Size + 1;
      if ( v16 >= v9->Data.Size )
      {
        if ( v16 >= v9->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v9->Data,
            v9,
            v16 + (v16 >> 2));
      }
      else if ( v16 < v9->Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v9->Data,
          v9,
          v9->Data.Size + 1);
      }
      v17 = (unsigned __int8 **)&v9->Data.Data[v16 - 1];
      v9->Data.Size = v16;
      if ( v17 )
        *v17 = pdata;
    }
    Scaleform::GFx::PlaceObject2Tag::SetEventHandlersPtr(this->pData, v9);
    data->pEventHandlers = v9;
  }
}

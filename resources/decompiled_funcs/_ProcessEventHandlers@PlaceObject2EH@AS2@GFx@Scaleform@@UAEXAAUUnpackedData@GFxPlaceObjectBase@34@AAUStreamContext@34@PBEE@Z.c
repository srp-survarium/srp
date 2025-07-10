void __thiscall Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject2EH *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        Scaleform::GFx::SwfEvent *prawdata,
        unsigned __int8 version)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *EventHandlersPtr; // eax
  unsigned int CurByteIndex; // eax
  unsigned int v7; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v8; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v9; // ebp
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  Scaleform::GFx::SwfEvent *v15; // eax
  unsigned int v16; // edi
  Scaleform::GFx::SwfEvent **v17; // eax
  Scaleform::GFx::SwfEvent *ev; // [esp+18h] [ebp+Ch]
  bool u32Flags; // [esp+1Ch] [ebp+10h]

  EventHandlersPtr = Scaleform::GFx::PlaceObject2Tag::GetEventHandlersPtr((const unsigned __int8 *)prawdata);
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
    u32Flags = version >= 6u;
    sc->CurBitIndex = 0;
    if ( u32Flags )
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
      if ( u32Flags )
      {
        v10 = sc->CurByteIndex;
        v11 = (unsigned __int8)sc->pData[v10]
            | (((unsigned __int8)sc->pData[v10 + 1] | (*(unsigned __int16 *)&sc->pData[v10 + 2] << 8)) << 8);
        sc->CurByteIndex = v10 + 4;
        v12 = v11;
      }
      else
      {
        v13 = sc->CurByteIndex;
        v14 = *(unsigned __int16 *)&sc->pData[v13];
        sc->CurByteIndex = v13 + 2;
        v12 = v14;
      }
      if ( !v12 )
        break;
      v15 = (Scaleform::GFx::SwfEvent *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 24, 0);
      if ( v15 )
      {
        v15->Event.Id = 0;
        v15->Event.WcharCode = 0;
        v15->Event.KeyCode = 0;
        v15->Event.AsciiCode = 0;
        v15->Event.RollOverCnt = 0;
        v15->Event.KeysState.States = 0;
        v15->Event.MouseWheelDelta = 0;
        v15->Event.ControllerIndex = -1;
        v15->pActionOpData.pObject = 0;
        ev = v15;
      }
      else
      {
        ev = 0;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(ev, sc, v12);
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
      v17 = &v9->Data.Data[v16 - 1];
      v9->Data.Size = v16;
      if ( v17 )
        *v17 = ev;
    }
    Scaleform::GFx::PlaceObject2Tag::SetEventHandlersPtr(this->pData, v9);
    data->pEventHandlers = v9;
  }
}

void __thiscall Scaleform::GFx::AS2::PlaceObject3EH::ProcessEventHandlers(
        Scaleform::GFx::AS2::PlaceObject3EH *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data,
        Scaleform::GFx::StreamContext *sc,
        const unsigned __int8 *__formal)
{
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *EventHandlersPtr; // eax
  Scaleform::GFx::AS2::AvmSwfEvent *v5; // ebx
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v6; // eax
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v7; // ebp
  unsigned int CurByteIndex; // ecx
  const unsigned __int8 *v9; // eax
  unsigned int v10; // esi
  Scaleform::GFx::AS2::AvmSwfEvent *v11; // eax
  unsigned int v12; // esi
  Scaleform::GFx::AS2::AvmSwfEvent **v13; // eax
  unsigned __int8 *pdata; // [esp+8h] [ebp-4h]

  pdata = this->pData;
  EventHandlersPtr = Scaleform::GFx::PlaceObject2Tag::GetEventHandlersPtr(this->pData);
  v5 = 0;
  if ( EventHandlersPtr )
  {
    data->pEventHandlers = EventHandlersPtr;
  }
  else
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurByteIndex += 6;
    sc->CurBitIndex = 0;
    v6 = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                                               Scaleform::Memory::pGlobalHeap,
                                                                                               12,
                                                                                               0);
    if ( v6 )
    {
      v6->Data.Data = 0;
      v6->Data.Size = 0;
      v6->Data.Policy.Capacity = 0;
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    while ( 1 )
    {
      if ( sc->CurBitIndex )
        ++sc->CurByteIndex;
      CurByteIndex = sc->CurByteIndex;
      v9 = &sc->pData[CurByteIndex];
      sc->CurBitIndex = 0;
      v10 = *v9 | ((v9[1] | (*((unsigned __int16 *)v9 + 1) << 8)) << 8);
      sc->CurByteIndex = CurByteIndex + 4;
      if ( !v10 )
        break;
      v11 = (Scaleform::GFx::AS2::AvmSwfEvent *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  24,
                                                  0);
      if ( v11 )
      {
        v11->Event.Id = 0;
        v11->Event.WcharCode = 0;
        v11->Event.KeyCode = 0;
        v11->Event.AsciiCode = 0;
        v11->Event.RollOverCnt = 0;
        v11->Event.KeysState.States = 0;
        v11->Event.MouseWheelDelta = 0;
        v11->Event.ControllerIndex = -1;
        v11->pActionOpData.pObject = 0;
        v5 = v11;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(v5, sc, v10);
      v12 = v7->Data.Size + 1;
      if ( v12 >= v7->Data.Size )
      {
        if ( v12 >= v7->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v7->Data,
            v7,
            v12 + (v12 >> 2));
      }
      else if ( v12 < v7->Data.Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v7->Data,
          v7,
          v7->Data.Size + 1);
      }
      v13 = &v7->Data.Data[v12 - 1];
      v7->Data.Size = v12;
      if ( v13 )
        *v13 = v5;
      v5 = 0;
    }
    Scaleform::GFx::PlaceObject2Tag::SetEventHandlersPtr(pdata, v7);
    data->pEventHandlers = v7;
  }
}

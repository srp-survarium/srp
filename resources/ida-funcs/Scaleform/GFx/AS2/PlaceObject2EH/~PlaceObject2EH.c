void __thiscall Scaleform::GFx::AS2::PlaceObject2EH::~PlaceObject2EH(Scaleform::GFx::AS2::PlaceObject2EH *this)
{
  Scaleform::GFx::PlaceObject3Tag *v1; // esi
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *EventHandlersPtr; // eax
  void **p_Data; // ebx
  unsigned int Size; // ebp
  unsigned int v5; // edi
  _DWORD *v6; // esi
  Scaleform::RefCountVImpl *v7; // ecx

  v1 = (Scaleform::GFx::PlaceObject3Tag *)this;
  this->__vftable = (Scaleform::GFx::AS2::PlaceObject2EH_vtbl *)&Scaleform::GFx::AS2::PlaceObject2EH::`vftable';
  if ( (this->pData[0] & 0x80u) != 0 )
  {
    EventHandlersPtr = Scaleform::GFx::PlaceObject2Tag::GetEventHandlersPtr(this->pData);
    p_Data = (void **)&EventHandlersPtr->Data.Data;
    if ( EventHandlersPtr )
    {
      Size = EventHandlersPtr->Data.Size;
      v5 = 0;
      if ( Size )
      {
        do
        {
          v6 = (_DWORD *)*((_DWORD *)*p_Data + v5);
          if ( v6 )
          {
            v7 = (Scaleform::RefCountVImpl *)v6[5];
            if ( v7 )
              Scaleform::RefCountImpl::Release(v7);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
          }
          ++v5;
        }
        while ( v5 < Size );
        v1 = (Scaleform::GFx::PlaceObject3Tag *)this;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, p_Data);
    }
  }
  Scaleform::GFx::PlaceObject2Tag::~PlaceObject2Tag(v1);
}

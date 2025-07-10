void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::SwfEvent **v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::SwfEvent **)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          this->Data,
                                          16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 260;
      v5 = (Scaleform::GFx::SwfEvent **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          pheapAddr,
                                          4 * v4,
                                          &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}

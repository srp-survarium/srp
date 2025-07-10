void __thiscall Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Waitable::HandlerStruct *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 16 * ((newCapacity + 15) >> 4);
      if ( this->Data )
      {
        v5 = (Scaleform::Waitable::HandlerStruct *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this->Data,
                                                     (newCapacity + 15) >> 4 << 7);
      }
      else
      {
        newCapacity = 2;
        v5 = (Scaleform::Waitable::HandlerStruct *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     8 * v4,
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
}

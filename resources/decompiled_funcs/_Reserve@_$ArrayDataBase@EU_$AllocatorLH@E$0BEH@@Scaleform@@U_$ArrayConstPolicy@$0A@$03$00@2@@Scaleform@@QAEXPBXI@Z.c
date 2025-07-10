void __thiscall Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 4 * ((newCapacity + 3) >> 2);
      if ( this->Data )
      {
        v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, v4);
      }
      else
      {
        newCapacity = 327;
        v5 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  pheapAddr,
                                  v4,
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

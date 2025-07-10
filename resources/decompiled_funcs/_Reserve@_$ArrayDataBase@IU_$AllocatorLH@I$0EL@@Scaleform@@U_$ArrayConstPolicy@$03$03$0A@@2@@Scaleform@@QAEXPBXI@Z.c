void __thiscall Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0>>::Reserve(
        Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH<unsigned int,75>,Scaleform::ArrayConstPolicy<4,4,0> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v3; // eax
  unsigned int v5; // esi
  unsigned int *v6; // eax

  v3 = newCapacity;
  if ( newCapacity < 4 )
    v3 = 4;
  v5 = 4 * ((v3 + 3) >> 2);
  if ( this->Data )
  {
    v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Realloc(
                           Scaleform::Memory::pGlobalHeap,
                           this->Data,
                           16 * ((v3 + 3) >> 2));
  }
  else
  {
    newCapacity = 75;
    v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                           Scaleform::Memory::pGlobalHeap,
                           pheapAddr,
                           16 * ((v3 + 3) >> 2),
                           &newCapacity);
  }
  this->Policy.Capacity = v5;
  this->Data = v6;
}

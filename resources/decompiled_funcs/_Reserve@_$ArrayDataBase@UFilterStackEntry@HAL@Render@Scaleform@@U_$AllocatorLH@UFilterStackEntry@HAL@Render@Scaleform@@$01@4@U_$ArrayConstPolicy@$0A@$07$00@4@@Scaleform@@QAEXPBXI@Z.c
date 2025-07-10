void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::HAL::FilterStackEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::FilterStackEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::HAL::FilterStackEntry *v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = Scaleform::Memory::pGlobalHeap->__vftable;
      v5 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v6 = (Scaleform::Render::HAL::FilterStackEntry *)((int (__stdcall *)(Scaleform::Render::HAL::FilterStackEntry *, unsigned int))v4->Realloc)(
                                                           this->Data,
                                                           (newCapacity + 7) >> 3 << 6);
      }
      else
      {
        AllocAutoHeap = v4->AllocAutoHeap;
        newCapacity = 2;
        v6 = (Scaleform::Render::HAL::FilterStackEntry *)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                           pheapAddr,
                                                           8 * v5,
                                                           &newCapacity);
      }
      this->Policy.Capacity = v5;
      this->Data = v6;
    }
    else
    {
      if ( this->Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this->Data);
        this->Data = 0;
      }
      this->Policy.Capacity = 0;
    }
  }
}

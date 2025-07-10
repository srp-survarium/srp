void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::HAL::RenderTargetEntry *v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = Scaleform::Memory::pGlobalHeap->__vftable;
      v5 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v6 = (Scaleform::Render::HAL::RenderTargetEntry *)((int (__stdcall *)(Scaleform::Render::HAL::RenderTargetEntry *, unsigned int))v4->Realloc)(
                                                            this->Data,
                                                            6016 * ((newCapacity + 7) >> 3));
      }
      else
      {
        AllocAutoHeap = v4->AllocAutoHeap;
        newCapacity = 2;
        v6 = (Scaleform::Render::HAL::RenderTargetEntry *)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                            pheapAddr,
                                                            752 * v5,
                                                            &newCapacity);
      }
      this->Policy.Capacity = v5;
      this->Data = v6;
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

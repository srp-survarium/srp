void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::TextureFormat *,Scaleform::AllocatorLH<Scaleform::Render::TextureFormat *,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  Scaleform::MemoryHeap_vtbl *v4; // edx
  unsigned int v5; // esi
  Scaleform::Render::TextureFormat **v6; // eax
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // edx

  if ( newCapacity )
  {
    v4 = Scaleform::Memory::pGlobalHeap->__vftable;
    v5 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v6 = (Scaleform::Render::TextureFormat **)((int (__stdcall *)(Scaleform::Render::TextureFormat **, unsigned int))v4->Realloc)(
                                                  this->Data,
                                                  16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      AllocAutoHeap = v4->AllocAutoHeap;
      newCapacity = 2;
      v6 = (Scaleform::Render::TextureFormat **)((int (__stdcall *)(const void *, unsigned int, unsigned int *))AllocAutoHeap)(
                                                  pheapAddr,
                                                  4 * v5,
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

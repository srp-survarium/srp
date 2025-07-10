void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::UserDataState::Data const *,Scaleform::AllocatorLH<Scaleform::Render::UserDataState::Data const *,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  const Scaleform::Render::UserDataState::Data **v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v5 = (const Scaleform::Render::UserDataState::Data **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                this->Data,
                                                                32 * ((newCapacity + 7) >> 3));
      }
      else
      {
        newCapacity = 2;
        v5 = (const Scaleform::Render::UserDataState::Data **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
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
}

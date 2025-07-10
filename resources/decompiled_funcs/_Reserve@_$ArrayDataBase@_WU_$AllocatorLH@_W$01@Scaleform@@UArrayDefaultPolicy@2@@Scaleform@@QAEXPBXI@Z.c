void __thiscall Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  wchar_t *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (wchar_t *)Scaleform::Memory::pGlobalHeap->Realloc(
                        Scaleform::Memory::pGlobalHeap,
                        this->Data,
                        8 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (wchar_t *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                        Scaleform::Memory::pGlobalHeap,
                        pheapAddr,
                        2 * v4,
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

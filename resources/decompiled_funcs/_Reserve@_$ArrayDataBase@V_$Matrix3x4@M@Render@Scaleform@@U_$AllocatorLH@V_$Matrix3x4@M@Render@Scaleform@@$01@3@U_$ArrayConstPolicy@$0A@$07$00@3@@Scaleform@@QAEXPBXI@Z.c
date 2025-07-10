void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::Matrix3x4<float> *v5; // eax

  if ( newCapacity >= this->Policy.Capacity )
  {
    if ( newCapacity )
    {
      v4 = 8 * ((newCapacity + 7) >> 3);
      if ( this->Data )
      {
        v5 = (Scaleform::Render::Matrix3x4<float> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      384 * ((newCapacity + 7) >> 3));
      }
      else
      {
        newCapacity = 2;
        v5 = (Scaleform::Render::Matrix3x4<float> *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      pheapAddr,
                                                      48 * v4,
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

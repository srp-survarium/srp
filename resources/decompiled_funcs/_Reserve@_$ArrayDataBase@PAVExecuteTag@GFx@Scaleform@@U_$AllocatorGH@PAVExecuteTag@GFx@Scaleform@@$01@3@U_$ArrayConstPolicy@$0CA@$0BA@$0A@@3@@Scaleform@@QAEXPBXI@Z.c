void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v3; // eax
  unsigned int v5; // esi
  Scaleform::GFx::ExecuteTag **v6; // eax

  v3 = newCapacity;
  if ( newCapacity < 0x20 )
    v3 = 32;
  v5 = 16 * ((v3 + 15) >> 4);
  if ( this->Data )
  {
    v6 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          this->Data,
                                          (v3 + 15) >> 4 << 6);
  }
  else
  {
    newCapacity = 2;
    v6 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          (v3 + 15) >> 4 << 6,
                                          &newCapacity);
  }
  this->Policy.Capacity = v5;
  this->Data = v6;
}

void __thiscall Scaleform::ArrayUnsafeBase<int,Scaleform::AllocatorGH<int,2>>::Reserve(
        Scaleform::ArrayUnsafeBase<int,Scaleform::AllocatorGH<int,2> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    if ( this->Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 2;
      this->Data = (int *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4 * v5, &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}

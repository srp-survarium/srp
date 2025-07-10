void __thiscall Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261>>::Reserve(
        Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 261;
      this->Data = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                        Scaleform::Memory::pGlobalHeap,
                                        this,
                                        v5,
                                        &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}

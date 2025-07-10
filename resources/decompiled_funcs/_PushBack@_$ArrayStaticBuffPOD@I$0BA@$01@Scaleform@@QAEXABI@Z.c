void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned int,16,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned long,16,2> *this,
        const unsigned int *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned int *v6; // eax
  unsigned int Reserved; // ecx
  unsigned int *Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x10 )
  {
    if ( Size == 16 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 4 * v5;
      if ( pHeap )
        v6 = (unsigned int *)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, v9, 0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x40u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned int *)Scaleform::Memory::pGlobalHeap->Realloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       Data,
                                       8 * Reserved);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}

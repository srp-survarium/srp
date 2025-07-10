void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *this,
        const unsigned __int8 *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax
  unsigned int Reserved; // ecx
  unsigned __int8 *Data; // edx

  Size = this->Size;
  if ( Size >= 0x400 )
  {
    if ( Size == 1024 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      if ( pHeap )
        v6 = (unsigned __int8 *)pHeap->Alloc(pHeap, v5, 0);
      else
        v6 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                  Scaleform::Memory::pGlobalHeap,
                                  this,
                                  v5,
                                  0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x400u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          Data,
                                          2 * Reserved);
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

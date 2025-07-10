void __thiscall Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2> *this,
        const unsigned __int16 *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  unsigned __int16 *v6; // eax
  unsigned int Reserved; // ecx
  unsigned __int16 *Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x48 )
  {
    if ( Size == 72 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 2 * v5;
      if ( pHeap )
        v6 = (unsigned __int16 *)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (unsigned __int16 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   this,
                                   v9,
                                   0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x90u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (unsigned __int16 *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           Data,
                                           4 * Reserved);
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

void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this,
        Scaleform::RefCountImpl *const *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // eax
  Scaleform::RefCountImpl **v6; // eax
  unsigned int Reserved; // ecx
  Scaleform::RefCountImpl **Data; // edx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v9 = 4 * v5;
      if ( pHeap )
        v6 = (Scaleform::RefCountImpl **)pHeap->Alloc(pHeap, v9, 0);
      else
        v6 = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           v9,
                                           0);
      this->Data = v6;
      qmemcpy(v6, this->Static, 0x80u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->Realloc(
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

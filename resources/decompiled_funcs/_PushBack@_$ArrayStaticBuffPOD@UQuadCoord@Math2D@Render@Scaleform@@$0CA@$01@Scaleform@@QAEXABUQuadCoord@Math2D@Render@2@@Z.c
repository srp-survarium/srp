void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Math2D::QuadCoord,32,2> *this,
        const Scaleform::Render::Math2D::QuadCoord *val)
{
  unsigned int Size; // eax
  Scaleform::Render::Math2D::QuadCoord *v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // eax
  Scaleform::Render::Math2D::QuadCoord *v7; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::Math2D::QuadCoord *Data; // edx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      v10 = 16 * v6;
      if ( pHeap )
        v7 = (Scaleform::Render::Math2D::QuadCoord *)pHeap->Alloc(pHeap, v10, 0);
      else
        v7 = (Scaleform::Render::Math2D::QuadCoord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       v10,
                                                       0);
      this->Data = v7;
      qmemcpy(v7, this->Static, 0x200u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::Render::Math2D::QuadCoord *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               Data,
                                                               32 * Reserved);
      }
    }
    v4 = &this->Data[this->Size];
  }
  else
  {
    v4 = &this->Static[Size];
  }
  *v4 = *val;
  ++this->Size;
}

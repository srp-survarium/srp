void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *this,
        const Scaleform::Render::Scale9GridTess::TmpVertexType *val)
{
  unsigned int Size; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *v4; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v6; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *v7; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // edx
  unsigned int v10; // [esp-Ch] [ebp-10h]

  Size = this->Size;
  if ( Size >= 0x48 )
  {
    if ( Size == 72 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      v10 = 12 * v6;
      if ( pHeap )
        v7 = (Scaleform::Render::Scale9GridTess::TmpVertexType *)pHeap->Alloc(pHeap, v10, 0);
      else
        v7 = (Scaleform::Render::Scale9GridTess::TmpVertexType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   v10,
                                                                   0);
      this->Data = v7;
      qmemcpy(v7, this->Static, 0x360u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        this->Reserved = 2 * Reserved;
        this->Data = (Scaleform::Render::Scale9GridTess::TmpVertexType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                           Scaleform::Memory::pGlobalHeap,
                                                                           Data,
                                                                           24 * Reserved);
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

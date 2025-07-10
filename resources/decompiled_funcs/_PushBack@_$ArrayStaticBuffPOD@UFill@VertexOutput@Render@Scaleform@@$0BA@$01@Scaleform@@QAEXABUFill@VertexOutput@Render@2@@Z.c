void __thiscall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::VertexOutput::Fill,16,2> *this,
        const Scaleform::Render::VertexOutput::Fill *val)
{
  unsigned int Size; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  unsigned int v5; // edx
  Scaleform::Render::VertexOutput::Fill *v6; // eax
  unsigned int Reserved; // ecx
  Scaleform::Render::VertexOutput::Fill *Data; // edx
  unsigned int v9; // ecx

  Size = this->Size;
  if ( Size >= 0x10 )
  {
    if ( Size == 16 )
    {
      pHeap = this->pHeap;
      v5 = 56 * this->Reserved;
      this->Reserved *= 2;
      if ( pHeap )
        v6 = (Scaleform::Render::VertexOutput::Fill *)pHeap->Alloc(pHeap, v5, 0);
      else
        v6 = (Scaleform::Render::VertexOutput::Fill *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        v5,
                                                        0);
      this->Data = v6;
      qmemcpy((void *)v6, this->Static, 0x1C0u);
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        v9 = 2 * Reserved;
        this->Reserved = v9;
        this->Data = (Scaleform::Render::VertexOutput::Fill *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                Data,
                                                                28 * v9);
      }
    }
    qmemcpy((void *)&this->Data[this->Size++], val, sizeof(this->Data[this->Size++]));
  }
  else
  {
    qmemcpy((void *)&this->Static[Size], val, sizeof(this->Static[Size]));
    ++this->Size;
  }
}

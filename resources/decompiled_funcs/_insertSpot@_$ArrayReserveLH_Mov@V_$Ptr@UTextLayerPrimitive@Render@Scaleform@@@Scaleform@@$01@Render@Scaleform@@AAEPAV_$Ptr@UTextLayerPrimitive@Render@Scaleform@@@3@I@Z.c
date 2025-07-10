Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned int index)
{
  unsigned int Size; // eax
  $445CB3699B64BB30984BADDF1BBAFC2D *v5; // edi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // eax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *pData; // ecx
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v8; // eax
  unsigned int v9; // edi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v10; // ebx

  Size = this->Size;
  if ( this->Size < 2 )
  {
    if ( index < Size )
      memmove(&this->Raw[4 * index + 4], &this->Raw[4 * index], 4 * (Size - index));
    ++this->Size;
    return (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&this->4 + index;
  }
  if ( this->Size == 2 )
  {
    v5 = &this->4;
    inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::allocInsertCopy(
                 this,
                 index,
                 (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&this->4,
                 2u,
                 4u);
    if ( inserted )
    {
      ++this->Size;
      v5->AD.pData = inserted;
      this->AD.Reserve = 4;
      return &inserted[index];
    }
    return 0;
  }
  pData = this->AD.pData;
  if ( Size >= this->AD.Reserve )
  {
    v9 = (Size + 4) & 0xFFFFFFFC;
    v10 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::allocInsertCopy(
            this,
            index,
            pData,
            Size,
            v9);
    if ( v10 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->AD.pData);
      ++this->Size;
      this->AD.Reserve = v9;
      this->AD.pData = v10;
      return &v10[index];
    }
    return 0;
  }
  if ( index < Size )
    memmove((unsigned __int8 *)&pData[index + 1], (unsigned __int8 *)&pData[index], 4 * (Size - index));
  v8 = this->AD.pData;
  ++this->Size;
  return &v8[index];
}

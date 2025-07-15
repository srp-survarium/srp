void __thiscall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned int index)
{
  $037AF80D9AEBE352D643A8853E25724C *v3; // ebx
  $037AF80D9AEBE352D643A8853E25724C *pData; // eax
  Scaleform::RefCountVImpl *v5; // ecx
  int v6; // edi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v7; // eax

  v3 = &this->4;
  if ( this->Size <= 2 )
    pData = &this->4;
  else
    pData = ($037AF80D9AEBE352D643A8853E25724C *)v3->AD.pData;
  v5 = (Scaleform::RefCountVImpl *)(&pData->AD.pData)[index];
  v6 = (int)pData + 4 * index;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  memmove(v6, (const __m128i *)(v6 + 4), 4 * (this->Size - index) - 4);
  if ( --this->Size == 2 )
  {
    v7 = v3->AD.pData;
    v3->AD.pData = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)v3->AD.pData->pObject;
    *(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&v3->Raw[4] = v7[1];
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
}
